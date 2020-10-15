//#include "ast.h"
#include <iostream>
using namespace std;

void error(string message) {
    cerr << message;
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
        for(auto var : node.varList)
            var->accept(*this);

    }

    virtual void visit(ASTVariableDeclType &node)
    {
        if(node.var) (node.var)->accept(*this);
        if(node.var_assign) (node.var_assign)->accept(*this);
    }

};