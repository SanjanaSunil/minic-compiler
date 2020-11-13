//#include "ast.h"
#include <iostream>
#include "SymbolTable.h"

using namespace std;

class SemanticVisitor : public ASTvisitor
{
    int func_arg_dims;
    bool return_found;
    bool is_function_call;
    SymbolTable *symbol_table;

    unique_ptr<llvm::LLVMContext> Context;
    unique_ptr<llvm::IRBuilder<>> Builder;

public:
    unique_ptr<llvm::Module> TheModule;

    SemanticVisitor() {
        symbol_table = new SymbolTable();
        return_found = false;
        is_function_call = false;
        func_arg_dims = 0;

        Context = make_unique<llvm::LLVMContext>();
        TheModule = make_unique<llvm::Module>("MiniC", *Context);
        Builder = make_unique<llvm::IRBuilder<>>(*Context);
    }

    virtual llvm::Value* visit(ASTProg &node)
    {
        symbol_table->addBlockScope();
        for (auto progStat : node.progStatList)
            progStat->accept(*this);
        
        symbol_table->removeScope();

        return nullptr;
    }

    // Add to symbol table
    // Change None type
    virtual llvm::Value* visit(ASTProgStat &node)
    {
        if(node.var_decl) (node.var_decl)->accept(*this);
        if(node.func_decl) (node.func_decl)->accept(*this);

        return nullptr;
    }

    // Add new scope
    virtual llvm::Value* visit(ASTBlockStat &node)
    {
        for(auto stat : node.statementList)
            stat->accept(*this);

        return nullptr;
    }

    // Check if exists in symbol table and get type and whether it is array
    // However this can be part of declaration as well, so don't check here?
    // Check if param1 and param2 is positive int if it is not null
    virtual llvm::Value* visit(ASTVariable &node)
    {
        if(node.param1) 
        {
            (node.param1)->accept(*this);
            if((node.param1)->node_type != INT) error("Invalid array indexing");
        }
        if(node.param2) 
        {
            (node.param2)->accept(*this);
            if(node.param2->node_type != INT) error("Invalid array indexing");
        }

        node.node_type = symbol_table->getType(node.id);

        return nullptr;
    }

    virtual llvm::Value* visit(ASTVariableAssign &node)
    {
        (node.exp)->accept(*this);
        node.node_type = (node.exp)->node_type;

        return nullptr;
    }

    // Check if each in vector is either of type none or specified type
    // Add to symbol table
    virtual llvm::Value* visit(ASTVariableDecl &node)
    {
        node.node_type = getNodeType(node.lit_type);
        for(auto varDecl : node.varList)
        {
            varDecl->accept(*this);
            if(varDecl->var_assign && node.node_type != varDecl->var_assign->node_type)
                error("Invalid assignment");
            
            if(symbol_table->existsInCurrentScope(node.lit_type))
                error("Variable already defined");

            int dims = 0;
            if(varDecl->var) dims = varDecl->var->getDimensions();
            symbol_table->addVariableToCurrentScope(varDecl->getId(), node.lit_type, dims);
        }

        return nullptr;
    }

    virtual llvm::Value* visit(ASTVariableDeclType &node)
    {
        if(node.var) (node.var)->accept(*this);
        if(node.var_assign) 
        {
            (node.var_assign)->accept(*this);
            node.node_type = (node.var_assign)->node_type;
        }

        return nullptr;
    }

    // Add to symbol table along with dimension
    virtual llvm::Value* visit(ASTFuncArg &node)
    {
        symbol_table->addVariableToCurrentScope(node.id, node.lit_type, node.dimension);
        node.node_type = getNodeType(node.lit_type);

        return nullptr;
    }

    // Add to symbol table
    virtual llvm::Value* visit(ASTFuncDecl &node)
    {
        return_found = false;

        vector<string> args;
        vector<int> dims;
        for(auto funcArg : node.funcArgList)
        {
            args.push_back(funcArg->lit_type);
            dims.push_back(funcArg->dimension);
        }
        symbol_table->addFunctionToCurrentScope(node.id, node.lit_type, args, dims);
        symbol_table->addFunctionScope(node.lit_type);

        node.node_type = getNodeType(node.lit_type);

        // check main
        if(node.id == "main")
        {
            if(int(args.size()) > 0) error("Invalid main function");
            if(node.node_type != INT) error("Invalid main function type");
        }

        for(auto funcArg : node.funcArgList) funcArg->accept(*this);
        (node.block)->accept(*this);

        if(!return_found && node.node_type != NONE)
            error("Return statement not found");

        symbol_table->removeScope();
        return nullptr;
    }

    // Check symbol table, check if arguments are correct in number and type
    virtual llvm::Value* visit(ASTFuncCall &node)
    {
        vector<NodeType> args;
        vector<int> dims;
        for(auto exp : node.funcArgList)
        {
            is_function_call = true;
            func_arg_dims = 0;

            exp->accept(*this);
            args.push_back(exp->node_type);
            dims.push_back(func_arg_dims);

            if(node.id == "input" && exp->node_type == NONE) error("Invalid input function");
            if(node.id == "print" && exp->node_type == NONE) error("Invalid print function");
        }

        if(node.id == "input" || node.id == "print")
        {
            node.node_type = NONE;
            return nullptr;
        }

        if(!symbol_table->isValidFunctionCall(node.id, args, dims))
            error("Invalid function call");
        
        node.node_type = symbol_table->getType(node.id);
        is_function_call = false;

        return nullptr;
    }

    // Assign type to whatever type the variable is
    virtual llvm::Value* visit(ASTExpr &node)
    {
        return nullptr;
    }

    virtual llvm::Value* visit(ASTExprInt &node)
    {
        return llvm::ConstantInt::get(llvm::Type::getInt64Ty(*Context), node.intlit, true);
    }

    virtual llvm::Value* visit(ASTExprFloat &node)
    {
        return llvm::ConstantFP::get(llvm::Type::getFloatTy(*Context), node.floatlit);
    }

    virtual llvm::Value* visit(ASTExprChar &node)
    {
        return llvm::ConstantInt::get(llvm::Type::getInt32Ty(*Context), node.charlit);
    }

    virtual llvm::Value* visit(ASTExprBool &node)
    {
        return llvm::ConstantInt::get(llvm::Type::getInt1Ty(*Context), node.boollit);
    }

    virtual llvm::Value* visit(ASTExprString &node)
    {
        return Builder->CreateGlobalStringPtr(node.stringlit);
    }

    virtual llvm::Value* visit(ASTExprUnary &node)
    {
        llvm::Value *operand = (node.exp)->accept(*this);
        if(node.unary_op == "+" || node.unary_op == "-")
        {
            node.node_type = (node.exp)->node_type;
            if((node.exp)->node_type != INT && (node.exp)->node_type != FLOAT)
                error("Invalid unary operation");
        }
        else if(node.unary_op == "!")
        {
            node.node_type = BOOL;
            if((node.exp)->node_type != BOOL)
                error("Invalid unary operation");
        }

        if(node.unary_op == "+") return Builder->CreateAdd(operand, llvm::ConstantInt::get(llvm::Type::getInt32Ty(*Context), 0), "positive");
        if(node.unary_op == "-") return Builder->CreateNeg(operand, "negate");
        if(node.unary_op == "!") return Builder->CreateNot(operand, "not");

        return nullptr;
    }

    virtual llvm::Value* visit(ASTExprBinary &node)
    {
        llvm::Value *l = (node.left)->accept(*this);
        llvm::Value *r = (node.right)->accept(*this);

        // l->print(llvm::errs(), true);

        string bin_op = node.bin_operator;
        NodeType left_type = (node.left)->node_type;
        NodeType right_type = (node.right)->node_type;

        if(left_type != right_type || left_type == CHAR || left_type == STRING || left_type == NONE)
            error("Invalid binary operation");

        if(bin_op == "&&" || bin_op == "||")
        {
            if(left_type != BOOL) error("Invalid binary operation");
            node.node_type = BOOL;
        }
        else if(bin_op == "==" || bin_op == "!=") node.node_type = BOOL;
        else
        {
            if(left_type != INT && left_type != FLOAT) error("Invalid binary operation");
            node.node_type = left_type;
            if(bin_op == "<" || bin_op == ">" || bin_op == "<=" || bin_op == ">=")
                node.node_type = BOOL;
        }  

        if(bin_op == "+") return Builder->CreateAdd(l, r, "addition");
        if(bin_op == "-") return Builder->CreateSub(l, r, "subtraction");
        if(bin_op == "*") return Builder->CreateMul(l, r, "multiplication");
        if(bin_op == "/") return Builder->CreateSDiv(l, r, "division");
        if(bin_op == "%") return Builder->CreateSRem(l, r, "mod");
        
        if(bin_op == "<") return Builder->CreateICmpSLT(l, r, "lt");
        if(bin_op == "<=") return Builder->CreateICmpSLE(l, r, "le");
        if(bin_op == ">") return Builder->CreateICmpSGT(l, r, "gt");
        if(bin_op == ">=") return Builder->CreateICmpSGE(l, r, "ge");
        if(bin_op == "==") return Builder->CreateICmpEQ(l, r, "equal");
        if(bin_op == "!=") return Builder->CreateICmpNE(l, r, "unequal");
        
        if(bin_op == "&&") return Builder->CreateAnd(l, r, "and");
        if(bin_op == "||") return Builder->CreateOr(l, r, "or");

        return nullptr;      
    }

    virtual llvm::Value* visit(ASTExprTernary &node)
    {
        (node.first)->accept(*this);
        (node.second)->accept(*this);
        (node.third)->accept(*this);

        if((node.first)->node_type != BOOL) 
            error("Invalid ternary condition");
        
        if((node.second)->node_type != (node.third)->node_type)
            error("Incompatible ternary returns");

        node.node_type = (node.second)->node_type;

        return nullptr;
    }

    // Set node type acc to symbol table
    virtual llvm::Value* visit(ASTExprVar &node)
    {
        (node.var)->accept(*this);
        node.node_type = (node.var)->node_type;

        if(node.node_type == NONE) error("Variable does not exist");

        int dimensions = (node.var)->getDimensions();
        if(is_function_call)
        {
            dimensions = symbol_table->getDimensions((node.var)->id);
            if((node.var)->getDimensions() > dimensions)
                error("Invalid array indexing");
        }

        if(!symbol_table->isValidVariable((node.var)->id, dimensions))
            error("Invalid reference");
    
        if(is_function_call) 
        {
            int call_dimension = (node.var)->getDimensions();
            int actual_dimension = dimensions;
            func_arg_dims = actual_dimension - call_dimension;
        }

        return nullptr;
    }

    // Set node type acc to symbol table
    virtual llvm::Value* visit(ASTExprFuncCall &node)
    {
        (node.func_call)->accept(*this);
        node.node_type = (node.func_call)->node_type;

        return nullptr;
    }

    // Check if can be assigned properly
    virtual llvm::Value* visit(ASTStatVarAssign &node)
    {
        (node.exp)->accept(*this);
        node.node_type = (node.exp)->node_type;

        if(!symbol_table->isValidVariable((node.var)->id, (node.var)->getDimensions()))
            error("Invalid reference");

        if(symbol_table->getType((node.var)->id) != node.node_type)
            error("Invalid assignment");

        return nullptr;
    }

    virtual llvm::Value* visit(ASTStatVarDecl &node)
    {
        (node.var_decl)->accept(*this);
        node.node_type = (node.var_decl)->node_type;

        return nullptr;
    }

    // Create new scope
    virtual llvm::Value* visit(ASTStatBlock &node)
    {
        symbol_table->addBlockScope();
        (node.block)->accept(*this);
        symbol_table->removeScope();

        return nullptr;
    }

    // Nothing to do here since it will already check
    virtual llvm::Value* visit(ASTStatFuncCall &node)
    {
        (node.func_call)->accept(*this);
        node.node_type = (node.func_call)->node_type;

        return nullptr;
    }

    // Check if currect return type, if in function
    virtual llvm::Value* visit(ASTStatReturn &node)
    {
        return_found = true;

        if(node.return_expr) 
        {
            (node.return_expr)->accept(*this);
            node.node_type = (node.return_expr)->node_type;
        }
        else node.node_type = NONE;

        if(!symbol_table->scopeTypeExists(Function))
            error("Incorrect return statement");
        
        if(node.node_type != symbol_table->getCurrentReturnType())
            error("Invalid return type");

        return nullptr;
    }

    // Check if in loop or function
    virtual llvm::Value* visit(ASTStatLoopControl &node)
    {
        if(!symbol_table->scopeTypeExists(Loop))
            error("Invalid " + node.control_stat + " statement");

        return nullptr;
    }

    virtual llvm::Value* visit(ASTStatWhile &node)
    {
        (node.exp)->accept(*this);
        if((node.exp)->node_type != INT && (node.exp)->node_type != BOOL)
            error("Invalid loop condition");

        symbol_table->addLoopScope();
        (node.block)->accept(*this);
        symbol_table->removeScope();

        return nullptr;
    }

    virtual llvm::Value* visit(ASTStatIf &node)
    {
        for(auto exp : node.exprList)
        {
            exp->accept(*this);
            if(exp->node_type != INT && exp->node_type != BOOL)
                error("Invalid if condition");
        }

        for(auto block : node.blockList) 
        {
            symbol_table->addBlockScope();
            block->accept(*this);
            symbol_table->removeScope();
        }

        return nullptr;
    }

    virtual llvm::Value* visit(ASTStatFor &node) {
        symbol_table->addBlockScope();

        if(node.var_decl) (node.var_decl)->accept(*this);
        if(node.init_var && node.init_expr) 
        {
            (node.init_var)->accept(*this);
            (node.init_expr)->accept(*this);

            node.node_type = (node.init_expr)->node_type;

            if(!symbol_table->isValidVariable((node.init_var)->id, (node.init_var)->getDimensions()))
                error("Invalid reference");

            if(symbol_table->getType((node.init_var)->id) != node.node_type)
                error("Invalid assignment");
        }

        if(node.cond_expr) (node.cond_expr)->accept(*this);
        if((node.cond_expr)->node_type != BOOL && (node.cond_expr)->node_type != INT)
            error("Invalid for loop");

        if(node.loop_var && node.loop_expr) 
        {
            (node.loop_var)->accept(*this);
            (node.loop_expr)->accept(*this);

            node.node_type = (node.loop_expr)->node_type;

            if(!symbol_table->isValidVariable((node.loop_var)->id, (node.loop_var)->getDimensions()))
                error("Invalid reference");

            if(symbol_table->getType((node.loop_var)->id) != node.node_type)
                error("Invalid assignment");
        }

        (node.block)->accept(*this);
        symbol_table->removeScope();

        return nullptr;
    }
    
};