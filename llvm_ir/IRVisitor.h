//#include "ast.h"
#include <iostream>
// #include "SymbolTable.h"
using namespace std;

class IRVisitor : public ASTvisitor
{
    SymbolTable *symbol_table;
    unique_ptr<llvm::LLVMContext> Context;
    unique_ptr<llvm::IRBuilder<>> Builder;

    llvm::Value *ret_ir;

public:
    unique_ptr<llvm::Module> Module;

    IRVisitor() {
        symbol_table = new SymbolTable();
        ret_ir = nullptr;

        Context = make_unique<llvm::LLVMContext>();
        Module = make_unique<llvm::Module>("MiniC", *Context);
        Builder = make_unique<llvm::IRBuilder<>>(*Context);
    }

    /* CHANGE - remove function scope */
    virtual void visit(ASTProg &node)
    {
        symbol_table->addBlockScope();

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
            symbol_table->addVariableToCurrentScope(varDecl->getId(), node.lit_type, dims);

            // Change this to reflect all types, not just int. Take care of arrays as well.
            if(symbol_table->isGlobal())
            {
                auto ir_val = new llvm::GlobalVariable(*Module, 
                                                        llvm::Type::getInt32Ty(*Context), 
                                                        false,
                                                        llvm::GlobalValue::CommonLinkage, 
                                                        NULL, 
                                                        varDecl->getId());
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
        symbol_table->addVariableToCurrentScope(node.id, node.lit_type, node.dimension);
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
        symbol_table->addFunctionToCurrentScope(node.id, node.lit_type, args, dims);
        symbol_table->addFunctionScope(node.lit_type);

        // CHANGE
        vector<llvm::Type*> param_types;
        for(auto funcArg : node.funcArgList) 
        {
            funcArg->accept(*this);
            param_types.push_back(llvm::Type::getInt32Ty(*Context));
        }

        // CHANGE
        llvm::FunctionType *ft = llvm::FunctionType::get(llvm::Type::getVoidTy(*Context), param_types, false);
        llvm::Function *func = llvm::Function::Create(ft, 
                                                      llvm::GlobalValue::LinkageTypes::CommonLinkage, 
                                                      node.id, 
                                                      *Module);
        
        llvm::BasicBlock *bb = llvm::BasicBlock::Create(*Context, "entry", func);
        Builder->SetInsertPoint(bb);

        (node.block)->accept(*this);

        symbol_table->removeScope();

        // CHANGE
        Builder->CreateRetVoid();
        
    }

    virtual void visit(ASTFuncCall &node)
    {

    }

    virtual void visit(ASTExpr &node)
    {

    }

    virtual void visit(ASTExprInt &node)
    {
    }

    virtual void visit(ASTExprFloat &node)
    {
    }

    virtual void visit(ASTExprChar &node)
    {
    }

    virtual void visit(ASTExprBool &node)
    {
    }

    virtual void visit(ASTExprString &node)
    {
    }

    virtual void visit(ASTExprUnary &node)
    {

    }

    virtual void visit(ASTExprBinary &node)
    {

     
    }

    virtual void visit(ASTExprTernary &node)
    {
    }

    virtual void visit(ASTExprVar &node)
    {
    }

    virtual void visit(ASTExprFuncCall &node)
    {

    }

    virtual void visit(ASTStatVarAssign &node)
    {

    }

    virtual void visit(ASTStatVarDecl &node)
    {

    }

    virtual void visit(ASTStatBlock &node)
    {

    }

    virtual void visit(ASTStatFuncCall &node)
    {

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