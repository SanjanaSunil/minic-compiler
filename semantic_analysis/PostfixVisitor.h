//#include "ast.h"
#include <iostream>
using namespace std;

class PostFixVisitor : public ASTvisitor
{
public:
    virtual void visit(ASTProg &node)
    {
        cout << "PostFixVisit traversal invoked" << endl;
        int i = 1;
        for (auto statement : node.statementList)
        {
            cout << "line " << i << " : ";
            statement->accept(*this);
            cout << endl;
            i = i + 1;
        }
    }

    virtual void visit(ASTStatExpr &node)
    {
        node.expr->accept(*this);
    }

    virtual void visit(ASTStatAssignExpr &node)
    {
        cout << node.id;
        node.expr->accept(*this);
        cout << " =";
    }

    virtual void visit(ASTExpr &node)
    {
        cout << "ASTExpr visit function" << endl;
    }

    virtual void visit(ASTExprBinary &node)
    {
        ASTExpr *left = node.getLeft();
        ASTExpr *right = node.getRight();

        left->accept(*this);
        right->accept(*this);
        cout << " " + node.getBin_operator();
    }

    virtual void visit(ASTExprTernary &node)
    {
        ASTExpr *first = node.getFirst();
        ASTExpr *second = node.getSecond();
        ASTExpr *third = node.getThird();

        first->accept(*this);
        second->accept(*this);
        third->accept(*this);

        // visit(node.getFirst());
        // visit(node.getSecond());
        // visit(node.getThird());
        cout << " ?:";
    }

    virtual void visit(ASTExprID &node)
    {
        cout << " " << node.getID();
    }

    virtual void visit(ASTExprINT &node)
    {
        cout << " " << node.getIntLit();
    }
};