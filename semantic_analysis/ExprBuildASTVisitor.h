#include <iostream>
#include "ast.h"
#include <vector>
#include "ExprVisitor.h"

using namespace std;

class ExprBuildASTVisitor : public ExprVisitor
{
public:
    /**
   * Visit parse trees produced by ExprParser.
   */
    virtual antlrcpp::Any visitProg(ExprParser::ProgContext *context)
    {
        cout << "In visitProg" << endl;
        ASTProg *node = new ASTProg();
        ASTExpr *statementNode;

        for (auto statement : context->expr())
        {
            statementNode = visit(statement);
            if (statementNode != nullptr)
            {
                node->statementList.push_back(statementNode);
            }
        }
        return (ASTProg *) node;
    }

    virtual antlrcpp::Any visitExprUnary(ExprParser::ExprUnaryContext *context)
    {
        cout << "In visitExprUnary" << endl;
        string op = context->op->getText();
        ASTExpr *exp = visit(context->expr());

        ASTExprUnary *node = new ASTExprUnary(op, exp);
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprNot(ExprParser::ExprNotContext *context)
    {
        cout << "In visitExprNot" << endl;
        ASTExpr *exp = visit(context->expr());
        ASTExprNot *node = new ASTExprNot(exp);
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprDivMulMod(ExprParser::ExprDivMulModContext *context)
    {
        cout << "In visitExprDivMulMod" << endl;

        string op = context->op->getText();
        ASTExpr *left = visit(context->expr(0));
        ASTExpr *right = visit(context->expr(1));

        ASTExprBinary *node = new ASTExprBinary(op, left, right);
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprInt(ExprParser::ExprIntContext *context)
    {
        cout << "In visitExprInt" << endl;
        ASTExprInt *node = new ASTExprInt(stoi(context->INT()->getText()));
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprFloat(ExprParser::ExprFloatContext *context)
    {
        cout << "In visitExprFloat" << endl;
        ASTExprFloat *node = new ASTExprFloat(stof(context->FLOAT()->getText()));
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprChar(ExprParser::ExprCharContext *context)
    {
        cout << "In visitExprChar" << endl;
        ASTExprChar *node = new ASTExprChar((context->CHAR()->getText())[0]);
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprBool(ExprParser::ExprBoolContext *context)
    {
        cout << "In visitExprBool" << endl;
        string bool_type = context->BOOL()->getText();

        ASTExprBool *node;
        if(bool_type == "true") node = new ASTExprBool(true);
        else node = new ASTExprBool(false);

        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprString(ExprParser::ExprStringContext *context)
    {
        cout << "In visitExprString" << endl;
        ASTExprString *node = new ASTExprString(context->STRING()->getText());
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprParenthesis(ExprParser::ExprParenthesisContext *context)
    {
        cout << "In visitExprParenthesis" << endl;
        return visit(context->expr());
    }
};