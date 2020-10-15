//#include "ast.h"
#include <iostream>
using namespace std;

void error(string message) {
    cerr << "ERROR: " << message << endl;
    exit(1);
}

class SemanticVisitor : public ASTvisitor
{
public:
    virtual void visit(ASTProg &node)
    {
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
    }

    virtual void visit(ASTVariableAssign &node)
    {
        (node.exp)->accept(*this);
    }

    // Check if each in vector is either of type none or specified type
    // Add to symbol table
    virtual void visit(ASTVariableDecl &node)
    {
        for(auto varDecl : node.varList)
        {
            varDecl->accept(*this);
            if(varDecl->var_assign && node.node_type != varDecl->var_assign->node_type)
                error("Invalid assignment");
        }
    }

    virtual void visit(ASTVariableDeclType &node)
    {
        if(node.var) (node.var)->accept(*this);
        if(node.var_assign) (node.var_assign)->accept(*this);
    }

    // Add to symbol table along with dimension
    virtual void visit(ASTFuncArg &node)
    {
        return;
    }

    // Add to symbol table
    virtual void visit(ASTFuncDecl &node)
    {
        (node.block)->accept(*this);
    }

    // Check symbol table, check if arguments are correct in number and type
    virtual void visit(ASTFuncCall &node)
    {
        for(auto exp : node.funcArgList)
        {
            exp->accept(*this);
        }
    }

    virtual void visit(ASTExpr &node)
    {
        return;
    }

    virtual void visit(ASTExprUnary &node)
    {
        (node.exp)->accept(*this);
        if(node.unary_op == "+" || node.unary_op == "-")
        {
            if((node.exp)->node_type != INT)
                error("Invalid unary operation");
        }
        else if(node.unary_op == "!")
        {
            if((node.exp)->node_type != BOOL)
                error("Invalid unary operation");
        }
    }

    virtual void visit(ASTExprBinary &node)
    {
        (node.left)->accept(*this);
        (node.right)->accept(*this);

        string bin_op = node.bin_operator;
        if(bin_op == "+" || bin_op == "-" || bin_op == "/" || bin_op == "*" || bin_op == "%")
        {
            if((node.left)->node_type != INT || (node.right)->node_type != INT)
                error("Invalid binary operation");
        }
        else 
        {
            if((node.left)->node_type != BOOL || (node.right)->node_type != BOOL)
                error("Invalid binary operation");
        }
    }
};