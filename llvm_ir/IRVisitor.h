#include <iostream>

using namespace std;

class IRVisitor : public ASTvisitor
{
    IRTable *symbol_table;
    unique_ptr<llvm::LLVMContext> Context;
    unique_ptr<llvm::IRBuilder<>> Builder;

    llvm::Value *ir_ret;
    llvm::Value *first_array_param;

public:
    unique_ptr<llvm::Module> Module;

    IRVisitor() {
        symbol_table = new IRTable();
        ir_ret = nullptr;
        first_array_param = nullptr;

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
            case CHAR: return Builder->getInt8Ty();
            case STRING: return Builder->getInt8PtrTy();
            default: return Builder->getInt32Ty();
        } 
    }

    // MAKE SURE ir_ret is being appropriately returned!!
    virtual void visit(ASTProg &node)
    {   
        //printf and scanf
        // CHANGE - add support for float
        vector<llvm::Type*> runTimeFuncArgs = { getLLVMType(STRING) };
        llvm::FunctionType *runTimeFuncType = llvm::FunctionType::get(getLLVMType(INT), runTimeFuncArgs, true);
        llvm::Function::Create(runTimeFuncType, llvm::Function::ExternalLinkage, "printf", Module.get());
        llvm::Function::Create(runTimeFuncType, llvm::Function::ExternalLinkage, "scanf", Module.get());

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

    virtual void visit(ASTVariable &node)
    {
        if(node.param1) (node.param1)->accept(*this);
        if(node.param2) 
        {
            first_array_param = ir_ret;
            (node.param2)->accept(*this);
        }
    }

    virtual void visit(ASTVariableAssign &node)
    {
        (node.exp)->accept(*this);
    }

    virtual void visit(ASTVariableDecl &node)
    {
        for(auto varDecl : node.varList)
        {
            varDecl->accept(*this);

            int dims = 0;
            if(varDecl->var) dims = varDecl->var->getDimensions();

            if(symbol_table->isGlobal())
            {
                if(dims > 0)
                {
                    ASTExprInt* int_node = dynamic_cast<ASTExprInt*>(varDecl->var->param1);
                    int global_array_sz = int_node->intlit;

                    int cols = 0;
                    if(dims == 2)
                    {
                        ASTExprInt* int_node2 = dynamic_cast<ASTExprInt*>(varDecl->var->param2);
                        cols = int_node2->intlit;
                        global_array_sz *= cols;
                    }

                    auto var_type = llvm::ArrayType::get(getLLVMType(node.node_type), global_array_sz);
                    auto ir_val = new llvm::GlobalVariable(*Module, 
                                                            var_type, 
                                                            false,
                                                            llvm::GlobalValue::PrivateLinkage, 
                                                            NULL, 
                                                            varDecl->getId());

                    vector<llvm::Constant*> global_arr_vals;
                    for(int i=0; i<global_array_sz; ++i)
                    {
                        if(node.node_type == INT) global_arr_vals.push_back(llvm::ConstantInt::get(getLLVMType(INT), 0, true));
                        else if(node.node_type == FLOAT) global_arr_vals.push_back(llvm::ConstantFP::get(getLLVMType(FLOAT), 0.0));
                        else if(node.node_type == CHAR) global_arr_vals.push_back(llvm::ConstantInt::get(getLLVMType(CHAR), '$'));
                        else if(node.node_type == BOOL) global_arr_vals.push_back(llvm::ConstantInt::get(getLLVMType(BOOL), false));
                    }

                    ir_val->setInitializer(llvm::ConstantArray::get(var_type, global_arr_vals));

                    if(dims == 2) symbol_table->addVariableToCurrentScope(varDecl->getId(), ir_val, llvm::ConstantInt::get(getLLVMType(INT), cols));
                    else symbol_table->addVariableToCurrentScope(varDecl->getId(), ir_val);
                }
                else
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
                    else if(node.node_type == CHAR) ir_val->setInitializer(llvm::ConstantInt::get(getLLVMType(CHAR), '$'));
                    else if(node.node_type == BOOL) ir_val->setInitializer(llvm::ConstantInt::get(getLLVMType(BOOL), false));

                    if(varDecl->var_assign)
                    {
                        llvm::Value* lhs_val = symbol_table->getVal(varDecl->getId());
                        ir_val->setInitializer((llvm::Constant*) ir_ret);
                    }
                }
            }
            else
            {
                llvm::Value *array_size = nullptr;
                if(dims > 0) array_size = ir_ret;
                if(dims == 2) array_size = Builder->CreateMul(ir_ret, first_array_param, "mul_tmp");

                llvm::Function *parent = Builder->GetInsertBlock()->getParent();
                llvm::AllocaInst *alloca_inst = Builder->CreateAlloca(getLLVMType(node.node_type), array_size, varDecl->getId());

                if(dims == 2) symbol_table->addVariableToCurrentScope(varDecl->getId(), alloca_inst, ir_ret); 
                else symbol_table->addVariableToCurrentScope(varDecl->getId(), alloca_inst);

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

    // CHANGE - allow array argument
    virtual void visit(ASTFuncDecl &node)
    {   
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
        symbol_table->addScope();

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

        if(!Builder->GetInsertBlock()->getTerminator())
        {
            if(node.node_type == NONE) Builder->CreateRetVoid();
            else if(node.node_type == INT) Builder->CreateRet(llvm::ConstantInt::get(getLLVMType(INT), 0, true));
            else if(node.node_type == FLOAT) Builder->CreateRet(llvm::ConstantFP::get(getLLVMType(FLOAT), 0.0));
            else if(node.node_type == CHAR) Builder->CreateRet(llvm::ConstantInt::get(getLLVMType(CHAR), '$'));
            else if(node.node_type == BOOL) Builder->CreateRet(llvm::ConstantInt::get(getLLVMType(BOOL), false));
        }        

        symbol_table->removeScope();
    }

    // CHANGE - check array as parameter
    virtual void visit(ASTFuncCall &node)
    {
        llvm::Function *CalleeF = Module->getFunction(node.id);
        vector<llvm::Value*> ArgsV;

        for (unsigned i = 0, e = node.funcArgList.size(); i != e; ++i)
        {   
            if(node.id == "scanf" && i != 0) 
            {
                ASTExprVar* variable = dynamic_cast<ASTExprVar*>(node.funcArgList[i]);

                (variable->var)->accept(*this);
                if((variable->var)->getDimensions() > 0)
                {
                    vector<llvm::Value*> idxs;
                    if(symbol_table->isGlobalVariable((variable->var)->id)) 
                        idxs.push_back(llvm::ConstantInt::get(getLLVMType(INT), 0));
                    if((variable->var)->getDimensions() == 2) 
                    {
                        llvm::Value* idx = Builder->CreateMul(symbol_table->getArrayParam((variable->var)->id), first_array_param, "mul_tmp");
                        ir_ret = Builder->CreateAdd(ir_ret, idx, "add_tmp");
                    }
                    idxs.push_back(ir_ret);

                    llvm::Value* array_val = symbol_table->getVal((variable->var)->id);
                    ir_ret = Builder->CreateInBoundsGEP(array_val, idxs, (variable->var)->id + "$");
                }
                else ir_ret = symbol_table->getVal(variable->var->id);

                ArgsV.push_back(ir_ret);
            }
            else 
            {
                node.funcArgList[i]->accept(*this);

                // Take care of printing float 
                if(node.id == "printf" && node.funcArgList[i]->node_type == FLOAT) 
                    ir_ret = Builder->CreateFPExt(ir_ret, Builder->getDoubleTy());
 
                ArgsV.push_back(ir_ret);
            }
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

    // CHANGE - FOR FLOAT etc
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

    virtual void visit(ASTExprVar &node)
    {
        (node.var)->accept(*this);

        if((node.var)->getDimensions() > 0)
        {
            vector<llvm::Value*> idxs;
            if(symbol_table->isGlobalVariable((node.var)->id)) 
                idxs.push_back(llvm::ConstantInt::get(getLLVMType(INT), 0));

            if((node.var)->getDimensions() == 2) 
            {
                llvm::Value* idx = Builder->CreateMul(symbol_table->getArrayParam((node.var)->id), first_array_param, "mul_tmp");
                ir_ret = Builder->CreateAdd(ir_ret, idx, "add_tmp");
            }
            idxs.push_back(ir_ret);

            llvm::Value* array_val = symbol_table->getVal((node.var)->id);
            ir_ret = Builder->CreateInBoundsGEP(array_val, idxs, (node.var)->id + "$");
        }
        else ir_ret = symbol_table->getVal((node.var)->id);

        ir_ret = Builder->CreateLoad(ir_ret);
    }

    virtual void visit(ASTExprFuncCall &node)
    {
        (node.func_call)->accept(*this);
    }

    virtual void visit(ASTStatVarAssign &node)
    {
        (node.exp)->accept(*this);

        if((node.var)->getDimensions() > 0)
        {
            llvm::Value* exp_val = ir_ret;

            (node.var)->accept(*this);
            
            vector<llvm::Value*> idxs;
            if(symbol_table->isGlobalVariable((node.var)->id)) 
                idxs.push_back(llvm::ConstantInt::get(getLLVMType(INT), 0));

            if((node.var)->getDimensions() == 2) 
            {
                llvm::Value* idx = Builder->CreateMul(symbol_table->getArrayParam((node.var)->id), first_array_param, "mul_tmp");
                ir_ret = Builder->CreateAdd(ir_ret, idx, "add_tmp");
            }
            idxs.push_back(ir_ret);

            llvm::Value* array_val = symbol_table->getVal((node.var)->id);
            auto idx_ptr = Builder->CreateInBoundsGEP(array_val, idxs, (node.var)->id + "$");

            Builder->CreateStore(exp_val, idx_ptr);
            return;
        }

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
        if(node.return_expr) 
        {
            (node.return_expr)->accept(*this);
            Builder->CreateRet(ir_ret);
        }
        else Builder->CreateRetVoid();
    }

    virtual void visit(ASTStatLoopControl &node)
    {

    }

    virtual void visit(ASTStatWhile &node)
    {
        symbol_table->addScope();

        llvm::Function *TheFunction = Builder->GetInsertBlock()->getParent();
        llvm::BasicBlock *LoopCondBB = llvm::BasicBlock::Create(*Context, "loopcond", TheFunction);
        llvm::BasicBlock *LoopBodyBB = llvm::BasicBlock::Create(*Context, "loopbody");
        llvm::BasicBlock *OuterBB = llvm::BasicBlock::Create(*Context, "outer");

        Builder->CreateBr(LoopCondBB);
        Builder->SetInsertPoint(LoopCondBB);

        llvm::Value* CondV = llvm::ConstantInt::get(getLLVMType(BOOL), 1);
        (node.exp)->accept(*this);
        CondV = ir_ret;
        Builder->CreateCondBr(CondV, LoopBodyBB, OuterBB);

        // Loop Body
        TheFunction->getBasicBlockList().push_back(LoopBodyBB);
        Builder->SetInsertPoint(LoopBodyBB);
        (node.block)->accept(*this);
        Builder->CreateBr(LoopCondBB);

        // Outer block
        TheFunction->getBasicBlockList().push_back(OuterBB);
        Builder->SetInsertPoint(OuterBB);

        symbol_table->removeScope();
    }

    virtual void visit(ASTStatIf &node)
    {   
        (node.exprList[0])->accept(*this);
        llvm::Value* CondV = ir_ret;
        llvm::Function *TheFunction = Builder->GetInsertBlock()->getParent();

        llvm::BasicBlock *ThenBB = llvm::BasicBlock::Create(*Context, "then", TheFunction);
        llvm::BasicBlock *ElseBB = llvm::BasicBlock::Create(*Context, "else");
        llvm::BasicBlock *MergeBB = llvm::BasicBlock::Create(*Context, "ifcont");

        if(node.blockList.size() == 1) ElseBB = MergeBB;

        Builder->CreateCondBr(CondV, ThenBB, ElseBB);

        Builder->SetInsertPoint(ThenBB);

        symbol_table->addScope();
        (node.blockList[0])->accept(*this);
        llvm::Value *ThenV = ir_ret;
        symbol_table->removeScope();

        ThenBB = Builder->GetInsertBlock();
        if(!ThenBB->getTerminator()) Builder->CreateBr(MergeBB);

        llvm::Value *ElseV = nullptr;
        if(node.blockList.size() > 1)
        {
            TheFunction->getBasicBlockList().push_back(ElseBB);
            Builder->SetInsertPoint(ElseBB);

            symbol_table->addScope();
            (node.blockList[1])->accept(*this);
            ElseV = ir_ret;
            symbol_table->removeScope();

            ElseBB = Builder->GetInsertBlock();
            if(!ElseBB->getTerminator()) Builder->CreateBr(MergeBB);
        }

        TheFunction->getBasicBlockList().push_back(MergeBB);
        Builder->SetInsertPoint(MergeBB);

        // llvm::PHINode *PN;
        // if(node.blockList.size() > 1)
        // {
        //     PN = Builder->CreatePHI(ThenV->getType(), 2, "iftmp");

        //     PN->addIncoming(ThenV, ThenBB);
        //     PN->addIncoming(ElseV, ElseBB);
        // }
        // else
        // {
        //     PN = Builder->CreatePHI(ThenV->getType(), 1, "iftmp");
        //     PN->addIncoming(ThenV, ThenBB);
        // }
        // ir_ret = PN;
    }

    // CHANGE allow for optional conditions
    /*
    Basic block for initializing
    Leads to another block with loop condition. If true, go to loop body, else outer
    Body has end expr. End expr goes to loop condition
    */
    virtual void visit(ASTStatFor &node) {
        symbol_table->addScope();

        llvm::Function *TheFunction = Builder->GetInsertBlock()->getParent();
        // llvm::BasicBlock *BeforeLoopBB = Builder->GetInsertBlock();

        // Initializing
        if(node.var_decl) (node.var_decl)->accept(*this);
        if(node.init_var && node.init_expr) 
        {
            (node.init_expr)->accept(*this);

            if((node.init_var)->getDimensions() > 0)
            {
                llvm::Value* exp_val = ir_ret;

                (node.init_var)->accept(*this);
                vector<llvm::Value*> idxs;
                if(symbol_table->isGlobalVariable((node.init_var)->id)) 
                    idxs.push_back(llvm::ConstantInt::get(getLLVMType(INT), 0));

                if((node.init_var)->getDimensions() == 2) 
                {
                    llvm::Value* idx = Builder->CreateMul(symbol_table->getArrayParam((node.init_var)->id), first_array_param, "mul_tmp");
                    ir_ret = Builder->CreateAdd(ir_ret, idx, "add_tmp");
                }
                idxs.push_back(ir_ret);

                llvm::Value* array_val = symbol_table->getVal((node.init_var)->id);
                auto idx_ptr = Builder->CreateInBoundsGEP(array_val, idxs, (node.init_var)->id + "$");

                Builder->CreateStore(exp_val, idx_ptr);
            }
            else
            {
                llvm::Value* lhs_val = symbol_table->getVal((node.init_var)->id);
                Builder->CreateStore(ir_ret, lhs_val);
            }
        }

        llvm::BasicBlock *LoopCondBB = llvm::BasicBlock::Create(*Context, "loopcond", TheFunction);
        llvm::BasicBlock *LoopBodyBB = llvm::BasicBlock::Create(*Context, "loopbody");
        llvm::BasicBlock *OuterBB = llvm::BasicBlock::Create(*Context, "outer");

        // Loop Condition
        Builder->CreateBr(LoopCondBB);
        Builder->SetInsertPoint(LoopCondBB);
        llvm::Value* CondV = llvm::ConstantInt::get(getLLVMType(BOOL), 1);
        if(node.cond_expr) 
        {
            (node.cond_expr)->accept(*this);
            CondV = ir_ret;
        }
        Builder->CreateCondBr(CondV, LoopBodyBB, OuterBB);
        /*
        for allocValue in all symbol tables:
            Builder->CreatePHI(allocValue->getType(), 1, "iftmp");
            PN->addIncoming(acclocValue, BeforeLoopBB);
        (Same thing for LoopBodyBB)
        */

        // Loop Body
        TheFunction->getBasicBlockList().push_back(LoopBodyBB);
        Builder->SetInsertPoint(LoopBodyBB);
        (node.block)->accept(*this);

        if(node.loop_var && node.loop_expr) 
        {
            (node.loop_expr)->accept(*this);

            if((node.loop_var)->getDimensions() > 0)
            {
                llvm::Value* exp_val = ir_ret;

                (node.loop_var)->accept(*this);
                vector<llvm::Value*> idxs;
                if(symbol_table->isGlobalVariable((node.loop_var)->id)) 
                    idxs.push_back(llvm::ConstantInt::get(getLLVMType(INT), 0));
                if((node.loop_var)->getDimensions() == 2) 
                {
                    llvm::Value* idx = Builder->CreateMul(symbol_table->getArrayParam((node.loop_var)->id), first_array_param, "mul_tmp");
                    ir_ret = Builder->CreateAdd(ir_ret, idx, "add_tmp");
                }
                idxs.push_back(ir_ret);

                llvm::Value* array_val = symbol_table->getVal((node.loop_var)->id);
                auto idx_ptr = Builder->CreateInBoundsGEP(array_val, idxs, (node.loop_var)->id + "$");

                Builder->CreateStore(exp_val, idx_ptr);
            }
            else
            {
                llvm::Value* lhs_val = symbol_table->getVal((node.loop_var)->id);
                Builder->CreateStore(ir_ret, lhs_val);
            }
        }
        Builder->CreateBr(LoopCondBB);

        // Outer block
        TheFunction->getBasicBlockList().push_back(OuterBB);
        Builder->SetInsertPoint(OuterBB);

        symbol_table->removeScope();
    }
};