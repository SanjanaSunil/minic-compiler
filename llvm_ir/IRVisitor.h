#include <iostream>

using namespace std;

class IRVisitor : public ASTvisitor
{
    IRTable *symbol_table;
    unique_ptr<llvm::LLVMContext> Context;
    unique_ptr<llvm::IRBuilder<>> Builder;

    llvm::Value *ir_ret;

public:
    unique_ptr<llvm::Module> Module;

    IRVisitor() {
        symbol_table = new IRTable();
        ir_ret = nullptr;

        Context = make_unique<llvm::LLVMContext>();
        Module = make_unique<llvm::Module>("MiniC", *Context);
        Builder = make_unique<llvm::IRBuilder<>>(*Context);
    }

    llvm::Type *getLLVMType(NodeType ty) { 
        switch (ty) {
            case NONE: return Builder->getVoidTy();
            case INT: return Builder->getInt32Ty();
            case FLOAT: return Builder->getFloatTy();
            case BOOL: return Builder->getInt1Ty();
            case CHAR: return Builder->getInt8PtrTy();
            default: return Builder->getInt32Ty();
        } 
    }

    virtual void visit(ASTProg &node)
    {
        symbol_table->addScope();

        for (auto progStat : node.progStatList)
            progStat->accept(*this);

        symbol_table->removeScope();
    }

    virtual void visit(ASTProgStat &node)
    {
        if(node.var_decl) (node.var_decl)->accept(*this);
        if(node.func_decl) (node.func_decl)->accept(*this);
    }

    virtual void visit(ASTBlockStat &node)
    {
        for(auto stat : node.statementList)
            stat->accept(*this);
    }

    // CHANGE - take care of array?
    virtual void visit(ASTVariable &node)
    {
        if(node.param1) (node.param1)->accept(*this);
        if(node.param2) (node.param2)->accept(*this);
    }

    virtual void visit(ASTVariableAssign &node)
    {
        (node.exp)->accept(*this);
    }

    /* CHANGE! */
    virtual void visit(ASTVariableDecl &node)
    {
        for(auto varDecl : node.varList)
        {
            varDecl->accept(*this);

            int dims = 0;
            if(varDecl->var) dims = varDecl->var->getDimensions();

            // Change this to reflect all types, not just int. Take care of arrays as well.
            // Change to include assignment 
            if(symbol_table->isGlobal())
            {
                auto ir_val = new llvm::GlobalVariable(*Module, 
                                                        getLLVMType(node.node_type), 
                                                        false,
                                                        llvm::GlobalValue::PrivateLinkage, 
                                                        NULL, 
                                                        varDecl->getId());

                symbol_table->addVariableToCurrentScope(varDecl->getId(), ir_val);

                if(node.node_type == INT) ir_val->setInitializer(llvm::ConstantInt::get(getLLVMType(INT), 0, true));
                else if(node.node_type == FLOAT) ir_val->setInitializer(llvm::ConstantFP::get(getLLVMType(FLOAT), 0.0));
                else if(node.node_type == CHAR) ir_val->setInitializer(llvm::ConstantInt::get(getLLVMType(CHAR), 'a'));
                else if(node.node_type == BOOL) ir_val->setInitializer(llvm::ConstantInt::get(getLLVMType(BOOL), false));

                if(varDecl->var_assign)
                {
                    llvm::Value* lhs_val = symbol_table->getVal(varDecl->getId());
                    ir_val->setInitializer((llvm::Constant*) ir_ret);
                }
            }
            else
            {
                llvm::Function *parent = Builder->GetInsertBlock()->getParent();
                llvm::AllocaInst *alloca_inst = Builder->CreateAlloca(getLLVMType(node.node_type), 
                                                                      nullptr, 
                                                                      varDecl->getId());

                symbol_table->addVariableToCurrentScope(varDecl->getId(), alloca_inst);

                if(varDecl->var_assign)
                {
                    llvm::Value* lhs_val = symbol_table->getVal(varDecl->getId());
                    Builder->CreateStore(ir_ret, lhs_val);
                }
            }

        }
    }

    virtual void visit(ASTVariableDeclType &node)
    {
        if(node.var) (node.var)->accept(*this);
        if(node.var_assign) (node.var_assign)->accept(*this);
    }

    virtual void visit(ASTFuncArg &node)
    {

    }

    // CHANGE - change function return types, check last line, check arguments
    virtual void visit(ASTFuncDecl &node)
    {   
        vector<string> args;
        vector<int> dims;
        for(auto funcArg : node.funcArgList)
        {
            args.push_back(funcArg->lit_type);
            dims.push_back(funcArg->dimension);
        }
        // symbol_table->addFunctionToCurrentScope(node.id, node.lit_type, args, dims);
        symbol_table->addScope();

        // CHANGE
        vector<llvm::Type*> param_types;
        for(auto funcArg : node.funcArgList) 
        {
            funcArg->accept(*this);
            param_types.push_back(getLLVMType(funcArg->node_type));
        }

        // CHANGE
        llvm::FunctionType *ft = llvm::FunctionType::get(getLLVMType(node.node_type), param_types, false);
        llvm::Function *func = llvm::Function::Create(ft, 
                                                      llvm::GlobalValue::LinkageTypes::ExternalLinkage, 
                                                      node.id, 
                                                      *Module);
        
        llvm::BasicBlock *bb = llvm::BasicBlock::Create(*Context, "entry", func);
        Builder->SetInsertPoint(bb);

        // CHANGE to allocate arrays as welll
        int i = 0;
        llvm::Function::arg_iterator AI = func->arg_begin();
        for(AI = func->arg_begin(); AI != func->arg_end(); ++AI)
        {
            string name = (node.funcArgList[i])->id;
            NodeType ty = (node.funcArgList[i])->node_type;
            
            AI->setName(name);
            llvm::AllocaInst *Alloca = Builder->CreateAlloca(getLLVMType(ty), nullptr, name.c_str());
            Builder->CreateStore(static_cast<llvm::Value *>(&*AI), Alloca);

            symbol_table->addVariableToCurrentScope(name, Alloca);
            i++;
        }

        (node.block)->accept(*this);

        symbol_table->removeScope();

        // CHANGE
        Builder->CreateRetVoid();
        
    }

    virtual void visit(ASTFuncCall &node)
    {
        llvm::Function *CalleeF = Module->getFunction(node.id);
        vector<llvm::Value*> ArgsV;
        for (unsigned i = 0, e = node.funcArgList.size(); i != e; ++i) {
            node.funcArgList[i]->accept(*this);
            ArgsV.push_back(ir_ret);
        }

        if(CalleeF->getReturnType()->isVoidTy()) ir_ret = Builder->CreateCall(CalleeF, ArgsV);
        else ir_ret = Builder->CreateCall(CalleeF, ArgsV, node.id);
    }

    virtual void visit(ASTExpr &node)
    {

    }

    // Change for long and unsigned
    virtual void visit(ASTExprInt &node)
    {
        ir_ret = llvm::ConstantInt::get(getLLVMType(INT), node.intlit, true);
    }

    virtual void visit(ASTExprFloat &node)
    {
        ir_ret = llvm::ConstantFP::get(getLLVMType(FLOAT), node.floatlit);
    }

    virtual void visit(ASTExprChar &node)
    {
        ir_ret = llvm::ConstantInt::get(getLLVMType(CHAR), node.charlit);
    }

    virtual void visit(ASTExprBool &node)
    {
        ir_ret = llvm::ConstantInt::get(getLLVMType(BOOL), node.boollit);
    }

    virtual void visit(ASTExprString &node)
    {
        ir_ret = Builder->CreateGlobalStringPtr(node.stringlit);
    }

    // CHANGE - FOR FLOAT etc
    virtual void visit(ASTExprUnary &node)
    {
        (node.exp)->accept(*this);
        llvm::Value *operand = ir_ret;

        if(node.unary_op == "-") ir_ret = Builder->CreateNeg(operand, "negate");
        if(node.unary_op == "!") ir_ret = Builder->CreateNot(operand, "not");
    }

    virtual void visit(ASTExprBinary &node)
    {
        llvm::Value *l;
        (node.left)->accept(*this);
        l = ir_ret;

        llvm::Value *r;
        (node.right)->accept(*this);
        r = ir_ret;
     
        string bin_op = node.bin_operator;

        if(bin_op == "+") ir_ret =  Builder->CreateAdd(l, r, "add");
        if(bin_op == "-") ir_ret = Builder->CreateSub(l, r, "sub");
        if(bin_op == "*") ir_ret = Builder->CreateMul(l, r, "mul");
        if(bin_op == "/") ir_ret = Builder->CreateSDiv(l, r, "div");
        if(bin_op == "%") ir_ret = Builder->CreateSRem(l, r, "mod");
        
        if(bin_op == "<") ir_ret = Builder->CreateICmpSLT(l, r, "lt");
        if(bin_op == "<=") ir_ret = Builder->CreateICmpSLE(l, r, "le");
        if(bin_op == ">") ir_ret = Builder->CreateICmpSGT(l, r, "gt");
        if(bin_op == ">=") ir_ret = Builder->CreateICmpSGE(l, r, "ge");
        if(bin_op == "==") ir_ret = Builder->CreateICmpEQ(l, r, "eq");
        if(bin_op == "!=") ir_ret = Builder->CreateICmpNE(l, r, "uneq");
        
        if(bin_op == "&&") ir_ret = Builder->CreateAnd(l, r, "and");
        if(bin_op == "||") ir_ret = Builder->CreateOr(l, r, "or");
    }

    virtual void visit(ASTExprTernary &node)
    {
    }

    // CHANGE to check for array
    virtual void visit(ASTExprVar &node)
    {
        (node.var)->accept(*this);
        ir_ret = symbol_table->getVal((node.var)->id);
        ir_ret = Builder->CreateLoad(ir_ret);
    }

    virtual void visit(ASTExprFuncCall &node)
    {
        (node.func_call)->accept(*this);
    }

    // CHANGE - change type?
    virtual void visit(ASTStatVarAssign &node)
    {
        (node.exp)->accept(*this);
        llvm::Value* lhs_val = symbol_table->getVal((node.var)->id);
        Builder->CreateStore(ir_ret, lhs_val);
    }

    virtual void visit(ASTStatVarDecl &node)
    {
        (node.var_decl)->accept(*this);
    }

    virtual void visit(ASTStatBlock &node)
    {
        symbol_table->addScope();
        (node.block)->accept(*this);
        symbol_table->removeScope();
    }

    virtual void visit(ASTStatFuncCall &node)
    {
        (node.func_call)->accept(*this);
    }

    virtual void visit(ASTStatReturn &node)
    {

    }

    virtual void visit(ASTStatLoopControl &node)
    {

    }

    virtual void visit(ASTStatWhile &node)
    {

    }

    virtual void visit(ASTStatIf &node)
    {

    }

    virtual void visit(ASTStatFor &node) {

    }
};