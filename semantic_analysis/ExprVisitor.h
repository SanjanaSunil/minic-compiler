
// Generated from Expr.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "ExprParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ExprParser.
 */
class  ExprVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ExprParser.
   */
    virtual antlrcpp::Any visitProg(ExprParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitExprInt(ExprParser::ExprIntContext *context) = 0;

    virtual antlrcpp::Any visitExprComp(ExprParser::ExprCompContext *context) = 0;

    virtual antlrcpp::Any visitExprNot(ExprParser::ExprNotContext *context) = 0;

    virtual antlrcpp::Any visitExprAddSub(ExprParser::ExprAddSubContext *context) = 0;

    virtual antlrcpp::Any visitExprEq(ExprParser::ExprEqContext *context) = 0;

    virtual antlrcpp::Any visitExprUnary(ExprParser::ExprUnaryContext *context) = 0;

    virtual antlrcpp::Any visitExprChar(ExprParser::ExprCharContext *context) = 0;

    virtual antlrcpp::Any visitExprDivMulMod(ExprParser::ExprDivMulModContext *context) = 0;

    virtual antlrcpp::Any visitExprOr(ExprParser::ExprOrContext *context) = 0;

    virtual antlrcpp::Any visitExprString(ExprParser::ExprStringContext *context) = 0;

    virtual antlrcpp::Any visitExprBool(ExprParser::ExprBoolContext *context) = 0;

    virtual antlrcpp::Any visitExprAnd(ExprParser::ExprAndContext *context) = 0;

    virtual antlrcpp::Any visitExprFloat(ExprParser::ExprFloatContext *context) = 0;

    virtual antlrcpp::Any visitExprParenthesis(ExprParser::ExprParenthesisContext *context) = 0;


};

