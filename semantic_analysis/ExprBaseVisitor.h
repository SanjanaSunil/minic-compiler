
// Generated from Expr.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "ExprVisitor.h"


/**
 * This class provides an empty implementation of ExprVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ExprBaseVisitor : public ExprVisitor {
public:

  virtual antlrcpp::Any visitProg(ExprParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprInt(ExprParser::ExprIntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprComp(ExprParser::ExprCompContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprNot(ExprParser::ExprNotContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprAddSub(ExprParser::ExprAddSubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprEq(ExprParser::ExprEqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprUnary(ExprParser::ExprUnaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprChar(ExprParser::ExprCharContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprDivMulMod(ExprParser::ExprDivMulModContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprOr(ExprParser::ExprOrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprString(ExprParser::ExprStringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprBool(ExprParser::ExprBoolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprAnd(ExprParser::ExprAndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprFloat(ExprParser::ExprFloatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprParenthesis(ExprParser::ExprParenthesisContext *ctx) override {
    return visitChildren(ctx);
  }


};

