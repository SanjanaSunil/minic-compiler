
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

    virtual antlrcpp::Any visitProgStat(ExprParser::ProgStatContext *context) = 0;

    virtual antlrcpp::Any visitBlockStat(ExprParser::BlockStatContext *context) = 0;

    virtual antlrcpp::Any visitVarId(ExprParser::VarIdContext *context) = 0;

    virtual antlrcpp::Any visitVarArrOneD(ExprParser::VarArrOneDContext *context) = 0;

    virtual antlrcpp::Any visitVarArrTwoD(ExprParser::VarArrTwoDContext *context) = 0;

    virtual antlrcpp::Any visitVariableAssign(ExprParser::VariableAssignContext *context) = 0;

    virtual antlrcpp::Any visitVariableDecl(ExprParser::VariableDeclContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclTypeA(ExprParser::VariableDeclTypeAContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclTypeB(ExprParser::VariableDeclTypeBContext *context) = 0;

    virtual antlrcpp::Any visitFuncArg(ExprParser::FuncArgContext *context) = 0;

    virtual antlrcpp::Any visitFuncArgArrOneD(ExprParser::FuncArgArrOneDContext *context) = 0;

    virtual antlrcpp::Any visitFuncArgArrTwoD(ExprParser::FuncArgArrTwoDContext *context) = 0;

    virtual antlrcpp::Any visitFuncDecl(ExprParser::FuncDeclContext *context) = 0;

    virtual antlrcpp::Any visitFuncCall(ExprParser::FuncCallContext *context) = 0;

    virtual antlrcpp::Any visitExprInt(ExprParser::ExprIntContext *context) = 0;

    virtual antlrcpp::Any visitExprComp(ExprParser::ExprCompContext *context) = 0;

    virtual antlrcpp::Any visitExprNot(ExprParser::ExprNotContext *context) = 0;

    virtual antlrcpp::Any visitExprAddSub(ExprParser::ExprAddSubContext *context) = 0;

    virtual antlrcpp::Any visitExprVar(ExprParser::ExprVarContext *context) = 0;

    virtual antlrcpp::Any visitExprEq(ExprParser::ExprEqContext *context) = 0;

    virtual antlrcpp::Any visitExprUnary(ExprParser::ExprUnaryContext *context) = 0;

    virtual antlrcpp::Any visitExprChar(ExprParser::ExprCharContext *context) = 0;

    virtual antlrcpp::Any visitExprFuncCall(ExprParser::ExprFuncCallContext *context) = 0;

    virtual antlrcpp::Any visitExprDivMulMod(ExprParser::ExprDivMulModContext *context) = 0;

    virtual antlrcpp::Any visitExprOr(ExprParser::ExprOrContext *context) = 0;

    virtual antlrcpp::Any visitExprString(ExprParser::ExprStringContext *context) = 0;

    virtual antlrcpp::Any visitExprBool(ExprParser::ExprBoolContext *context) = 0;

    virtual antlrcpp::Any visitExprAnd(ExprParser::ExprAndContext *context) = 0;

    virtual antlrcpp::Any visitExprTernary(ExprParser::ExprTernaryContext *context) = 0;

    virtual antlrcpp::Any visitExprFloat(ExprParser::ExprFloatContext *context) = 0;

    virtual antlrcpp::Any visitExprParenthesis(ExprParser::ExprParenthesisContext *context) = 0;

    virtual antlrcpp::Any visitStatVarDecl(ExprParser::StatVarDeclContext *context) = 0;

    virtual antlrcpp::Any visitStatVarAssign(ExprParser::StatVarAssignContext *context) = 0;

    virtual antlrcpp::Any visitStatBlock(ExprParser::StatBlockContext *context) = 0;

    virtual antlrcpp::Any visitStatFuncCall(ExprParser::StatFuncCallContext *context) = 0;

    virtual antlrcpp::Any visitStatReturn(ExprParser::StatReturnContext *context) = 0;

    virtual antlrcpp::Any visitStatBreak(ExprParser::StatBreakContext *context) = 0;

    virtual antlrcpp::Any visitStatContinue(ExprParser::StatContinueContext *context) = 0;

    virtual antlrcpp::Any visitStatWhile(ExprParser::StatWhileContext *context) = 0;

    virtual antlrcpp::Any visitStatIf(ExprParser::StatIfContext *context) = 0;

    virtual antlrcpp::Any visitStatFor(ExprParser::StatForContext *context) = 0;


};

