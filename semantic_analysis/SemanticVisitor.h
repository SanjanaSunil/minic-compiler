//#include "ast.h"
#include <iostream>
#include "SymbolTable.h"
using namespace std;

/*
    * Check not only if it exists but also if it is of same dimensions
*/

class SemanticVisitor : public ASTvisitor
{
    SymbolTable *symbol_table;

public:
    SemanticVisitor() {
        symbol_table = new SymbolTable();
    }

    virtual void visit(ASTProg &node)
    {
        symbol_table->addBlockScope();
        for (auto progStat : node.progStatList)
            progStat->accept(*this);
    }

    // Add to symbol table
    // Change None type
    virtual void visit(ASTProgStat &node)
    {
        if(node.var_decl) (node.var_decl)->accept(*this);
        if(node.func_decl) (node.func_decl)->accept(*this);
    }

    // Add new scope
    virtual void visit(ASTBlockStat &node)
    {
        for(auto stat : node.statementList)
            stat->accept(*this);
    }

    // Check if exists in symbol table and get type and whether it is array
    // However this can be part of declaration as well, so don't check here?
    // Check if param1 and param2 is positive int if it is not null
    virtual void visit(ASTVariable &node)
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
    }

    virtual void visit(ASTVariableAssign &node)
    {
        (node.exp)->accept(*this);
        node.node_type = (node.exp)->node_type;
    }

    // Check if each in vector is either of type none or specified type
    // Add to symbol table
    virtual void visit(ASTVariableDecl &node)
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
    }

    virtual void visit(ASTVariableDeclType &node)
    {
        if(node.var) (node.var)->accept(*this);
        if(node.var_assign) 
        {
            (node.var_assign)->accept(*this);
            node.node_type = (node.var_assign)->node_type;
        }
    }

    // Add to symbol table along with dimension
    virtual void visit(ASTFuncArg &node)
    {
        symbol_table->addVariableToCurrentScope(node.id, node.lit_type, node.dimension);
        node.node_type = getNodeType(node.lit_type);
    }

    // Add to symbol table
    virtual void visit(ASTFuncDecl &node)
    {
        vector<string> args;
        for(auto funcArg : node.funcArgList) args.push_back(funcArg->lit_type);
        symbol_table->addFunctionToCurrentScope(node.id, node.lit_type, args);
        symbol_table->addFunctionScope(node.lit_type);

        node.node_type = getNodeType(node.lit_type);

        for(auto funcArg : node.funcArgList) funcArg->accept(*this);
        (node.block)->accept(*this);
    }

    // Check symbol table, check if arguments are correct in number and type
    virtual void visit(ASTFuncCall &node)
    {
        vector<NodeType> args;
        for(auto exp : node.funcArgList)
        {
            exp->accept(*this);
            args.push_back(exp->node_type);
        }

        if(!symbol_table->isValidFunctionCall(node.id, args))
            error("Invalid function call");
        
        node.node_type = symbol_table->getType(node.id);
    }

    // Assign type to whatever type the variable is
    virtual void visit(ASTExpr &node)
    {
        return;
    }

    virtual void visit(ASTExprUnary &node)
    {
        (node.exp)->accept(*this);
        if(node.unary_op == "+" || node.unary_op == "-")
        {
            node.node_type = INT;
            if((node.exp)->node_type == CHAR || (node.exp)->node_type == STRING)
                error("Invalid unary operation");
        }
        else if(node.unary_op == "!")
        {
            node.node_type = BOOL;
            if((node.exp)->node_type != BOOL && (node.exp)->node_type != INT)
                error("Invalid unary operation");
        }
    }

    virtual void visit(ASTExprBinary &node)
    {
        (node.left)->accept(*this);
        (node.right)->accept(*this);

        string bin_op = node.bin_operator;
        NodeType left_type = (node.left)->node_type;
        NodeType right_type = (node.right)->node_type;

        if(left_type == CHAR || left_type == STRING || right_type == CHAR || right_type == STRING)
            error("Invalid binary operation");

        if(bin_op == "+" || bin_op == "-" || bin_op == "/" || bin_op == "*" || bin_op == "/")
            node.node_type = INT;
        else
            node.node_type = BOOL;
    }

    virtual void visit(ASTExprTernary &node)
    {
        (node.first)->accept(*this);
        (node.second)->accept(*this);
        (node.third)->accept(*this);

        if((node.first)->node_type != BOOL && (node.first)->node_type != INT) 
            error("Invalid ternary condition");
        
        if((node.second)->node_type != (node.third)->node_type)
            error("Incompatible ternary returns");

        node.node_type = (node.second)->node_type;
    }

    // Set node type acc to symbol table
    virtual void visit(ASTExprVar &node)
    {
        (node.var)->accept(*this);
        node.node_type = (node.var)->node_type;

        if(node.node_type == NONE) error("Variable does not exist");
        if(!symbol_table->isValidVariable((node.var)->id, (node.var)->getDimensions()))
            error("Invalid reference");
    }

    // Set node type acc to symbol table
    virtual void visit(ASTExprFuncCall &node)
    {
        (node.func_call)->accept(*this);
        node.node_type = (node.func_call)->node_type;
    }

    // Check if can be assigned properly
    virtual void visit(ASTStatVarAssign &node)
    {
        (node.exp)->accept(*this);
        node.node_type = (node.exp)->node_type;
    }

    virtual void visit(ASTStatVarDecl &node)
    {
        (node.var_decl)->accept(*this);
        node.node_type = (node.var_decl)->node_type;
    }

    // Create new scope
    virtual void visit(ASTStatBlock &node)
    {
        (node.block)->accept(*this);
    }

    // Nothing to do here since it will already check
    virtual void visit(ASTStatFuncCall &node)
    {
        (node.func_call)->accept(*this);
    }

    // Check if currect return type, if in function
    virtual void visit(ASTStatReturn &node)
    {
        if(node.return_expr) 
        {
            (node.return_expr)->accept(*this);
            node.node_type = (node.return_expr)->node_type;
        }
    }

    // Check if in loop or function
    virtual void visit(ASTStatLoopControl &node)
    {
        return;
    }

    virtual void visit(ASTStatWhile &node)
    {
        (node.exp)->accept(*this);
        if((node.exp)->node_type != INT && (node.exp)->node_type != BOOL)
            error("Invalid loop condition");

        (node.block)->accept(*this);
    }

    virtual void visit(ASTStatIf &node)
    {
        for(auto exp : node.exprList)
        {
            exp->accept(*this);
            if(exp->node_type != INT && exp->node_type != BOOL)
                error("Invalid if condition");
        }

        for(auto block : node.blockList) block->accept(*this);
    }

    virtual void visit(ASTStatFor &node) {
        if(node.var_decl) (node.var_decl)->accept(*this);
        if(node.init_var) (node.init_var)->accept(*this);
        if(node.init_expr) (node.init_expr)->accept(*this);

        if(node.cond_expr) (node.cond_expr)->accept(*this);
        if((node.cond_expr)->node_type != BOOL && (node.cond_expr)->node_type != INT)
            error("Invalid for loop");

        if(node.loop_var) (node.loop_var)->accept(*this);
        if(node.loop_expr) (node.loop_expr)->accept(*this);
        
        if(node.block) (node.block)->accept(*this);
    }
    
};