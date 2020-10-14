
// Generated from Expr.g4 by ANTLR 4.8


#include "ExprVisitor.h"

#include "ExprParser.h"


using namespace antlrcpp;
using namespace antlr4;

ExprParser::ExprParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ExprParser::~ExprParser() {
  delete _interpreter;
}

std::string ExprParser::getGrammarFileName() const {
  return "Expr.g4";
}

const std::vector<std::string>& ExprParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ExprParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

ExprParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::ProgContext::EOF() {
  return getToken(ExprParser::EOF, 0);
}

std::vector<ExprParser::ProgStatementContext *> ExprParser::ProgContext::progStatement() {
  return getRuleContexts<ExprParser::ProgStatementContext>();
}

ExprParser::ProgStatementContext* ExprParser::ProgContext::progStatement(size_t i) {
  return getRuleContext<ExprParser::ProgStatementContext>(i);
}


size_t ExprParser::ProgContext::getRuleIndex() const {
  return ExprParser::RuleProg;
}


antlrcpp::Any ExprParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ProgContext* ExprParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, ExprParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(23);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::T__7

    || _la == ExprParser::TYPE) {
      setState(20);
      progStatement();
      setState(25);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(26);
    match(ExprParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgStatementContext ------------------------------------------------------------------

ExprParser::ProgStatementContext::ProgStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::ProgStatementContext::getRuleIndex() const {
  return ExprParser::RuleProgStatement;
}

void ExprParser::ProgStatementContext::copyFrom(ProgStatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ProgStatContext ------------------------------------------------------------------

ExprParser::VarDeclContext* ExprParser::ProgStatContext::varDecl() {
  return getRuleContext<ExprParser::VarDeclContext>(0);
}

ExprParser::FunctionDeclContext* ExprParser::ProgStatContext::functionDecl() {
  return getRuleContext<ExprParser::FunctionDeclContext>(0);
}

ExprParser::ProgStatContext::ProgStatContext(ProgStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ProgStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitProgStat(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::ProgStatementContext* ExprParser::progStatement() {
  ProgStatementContext *_localctx = _tracker.createInstance<ProgStatementContext>(_ctx, getState());
  enterRule(_localctx, 2, ExprParser::RuleProgStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<ProgStatementContext *>(_tracker.createInstance<ExprParser::ProgStatContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(30);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::TYPE: {
        setState(28);
        varDecl();
        break;
      }

      case ExprParser::T__7: {
        setState(29);
        functionDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

ExprParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::BlockContext::getRuleIndex() const {
  return ExprParser::RuleBlock;
}

void ExprParser::BlockContext::copyFrom(BlockContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BlockStatContext ------------------------------------------------------------------

std::vector<ExprParser::StatementContext *> ExprParser::BlockStatContext::statement() {
  return getRuleContexts<ExprParser::StatementContext>();
}

ExprParser::StatementContext* ExprParser::BlockStatContext::statement(size_t i) {
  return getRuleContext<ExprParser::StatementContext>(i);
}

ExprParser::BlockStatContext::BlockStatContext(BlockContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::BlockStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitBlockStat(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::BlockContext* ExprParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 4, ExprParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<BlockContext *>(_tracker.createInstance<ExprParser::BlockStatContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(32);
    match(ExprParser::T__0);
    setState(36);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::T__0)
      | (1ULL << ExprParser::TYPE)
      | (1ULL << ExprParser::ID))) != 0)) {
      setState(33);
      statement();
      setState(38);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(39);
    match(ExprParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

ExprParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::VariableContext::getRuleIndex() const {
  return ExprParser::RuleVariable;
}

void ExprParser::VariableContext::copyFrom(VariableContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VarArrTwoDContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::VarArrTwoDContext::ID() {
  return getToken(ExprParser::ID, 0);
}

std::vector<ExprParser::ExprContext *> ExprParser::VarArrTwoDContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::VarArrTwoDContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::VarArrTwoDContext::VarArrTwoDContext(VariableContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::VarArrTwoDContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVarArrTwoD(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarIdContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::VarIdContext::ID() {
  return getToken(ExprParser::ID, 0);
}

ExprParser::VarIdContext::VarIdContext(VariableContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::VarIdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVarId(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarArrOneDContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::VarArrOneDContext::ID() {
  return getToken(ExprParser::ID, 0);
}

ExprParser::ExprContext* ExprParser::VarArrOneDContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::VarArrOneDContext::VarArrOneDContext(VariableContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::VarArrOneDContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVarArrOneD(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::VariableContext* ExprParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 6, ExprParser::RuleVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(55);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VariableContext *>(_tracker.createInstance<ExprParser::VarIdContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(41);
      match(ExprParser::ID);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VariableContext *>(_tracker.createInstance<ExprParser::VarArrOneDContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(42);
      match(ExprParser::ID);
      setState(43);
      match(ExprParser::T__2);
      setState(44);
      expr(0);
      setState(45);
      match(ExprParser::T__3);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<VariableContext *>(_tracker.createInstance<ExprParser::VarArrTwoDContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(47);
      match(ExprParser::ID);
      setState(48);
      match(ExprParser::T__2);
      setState(49);
      expr(0);
      setState(50);
      match(ExprParser::T__3);
      setState(51);
      match(ExprParser::T__2);
      setState(52);
      expr(0);
      setState(53);
      match(ExprParser::T__3);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarAssignContext ------------------------------------------------------------------

ExprParser::VarAssignContext::VarAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::VarAssignContext::getRuleIndex() const {
  return ExprParser::RuleVarAssign;
}

void ExprParser::VarAssignContext::copyFrom(VarAssignContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VariableAssignContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::VariableAssignContext::ID() {
  return getToken(ExprParser::ID, 0);
}

ExprParser::ExprContext* ExprParser::VariableAssignContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::VariableAssignContext::VariableAssignContext(VarAssignContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::VariableAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVariableAssign(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::VarAssignContext* ExprParser::varAssign() {
  VarAssignContext *_localctx = _tracker.createInstance<VarAssignContext>(_ctx, getState());
  enterRule(_localctx, 8, ExprParser::RuleVarAssign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<VarAssignContext *>(_tracker.createInstance<ExprParser::VariableAssignContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(57);
    match(ExprParser::ID);
    setState(58);
    match(ExprParser::T__4);
    setState(59);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

ExprParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::VarDeclContext::getRuleIndex() const {
  return ExprParser::RuleVarDecl;
}

void ExprParser::VarDeclContext::copyFrom(VarDeclContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VariableDeclContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::VariableDeclContext::TYPE() {
  return getToken(ExprParser::TYPE, 0);
}

std::vector<ExprParser::VariableContext *> ExprParser::VariableDeclContext::variable() {
  return getRuleContexts<ExprParser::VariableContext>();
}

ExprParser::VariableContext* ExprParser::VariableDeclContext::variable(size_t i) {
  return getRuleContext<ExprParser::VariableContext>(i);
}

std::vector<ExprParser::VarAssignContext *> ExprParser::VariableDeclContext::varAssign() {
  return getRuleContexts<ExprParser::VarAssignContext>();
}

ExprParser::VarAssignContext* ExprParser::VariableDeclContext::varAssign(size_t i) {
  return getRuleContext<ExprParser::VarAssignContext>(i);
}

ExprParser::VariableDeclContext::VariableDeclContext(VarDeclContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::VariableDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVariableDecl(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::VarDeclContext* ExprParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 10, ExprParser::RuleVarDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<VarDeclContext *>(_tracker.createInstance<ExprParser::VariableDeclContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(61);
    match(ExprParser::TYPE);
    setState(64);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(62);
      variable();
      break;
    }

    case 2: {
      setState(63);
      varAssign();
      break;
    }

    }
    setState(72);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::T__5) {
      setState(70);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
      case 1: {
        setState(66);
        match(ExprParser::T__5);
        setState(67);
        variable();
        break;
      }

      case 2: {
        setState(68);
        match(ExprParser::T__5);
        setState(69);
        varAssign();
        break;
      }

      }
      setState(74);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(75);
    match(ExprParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionArgumentContext ------------------------------------------------------------------

ExprParser::FunctionArgumentContext::FunctionArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::FunctionArgumentContext::getRuleIndex() const {
  return ExprParser::RuleFunctionArgument;
}

void ExprParser::FunctionArgumentContext::copyFrom(FunctionArgumentContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FuncArgArrOneDContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::FuncArgArrOneDContext::TYPE() {
  return getToken(ExprParser::TYPE, 0);
}

tree::TerminalNode* ExprParser::FuncArgArrOneDContext::ID() {
  return getToken(ExprParser::ID, 0);
}

ExprParser::FuncArgArrOneDContext::FuncArgArrOneDContext(FunctionArgumentContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::FuncArgArrOneDContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFuncArgArrOneD(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncArgContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::FuncArgContext::TYPE() {
  return getToken(ExprParser::TYPE, 0);
}

tree::TerminalNode* ExprParser::FuncArgContext::ID() {
  return getToken(ExprParser::ID, 0);
}

ExprParser::FuncArgContext::FuncArgContext(FunctionArgumentContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::FuncArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFuncArg(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncArgArrTwoDContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::FuncArgArrTwoDContext::TYPE() {
  return getToken(ExprParser::TYPE, 0);
}

tree::TerminalNode* ExprParser::FuncArgArrTwoDContext::ID() {
  return getToken(ExprParser::ID, 0);
}

ExprParser::FuncArgArrTwoDContext::FuncArgArrTwoDContext(FunctionArgumentContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::FuncArgArrTwoDContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFuncArgArrTwoD(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::FunctionArgumentContext* ExprParser::functionArgument() {
  FunctionArgumentContext *_localctx = _tracker.createInstance<FunctionArgumentContext>(_ctx, getState());
  enterRule(_localctx, 12, ExprParser::RuleFunctionArgument);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(89);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<FunctionArgumentContext *>(_tracker.createInstance<ExprParser::FuncArgContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(77);
      match(ExprParser::TYPE);
      setState(78);
      match(ExprParser::ID);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<FunctionArgumentContext *>(_tracker.createInstance<ExprParser::FuncArgArrOneDContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(79);
      match(ExprParser::TYPE);
      setState(80);
      match(ExprParser::ID);
      setState(81);
      match(ExprParser::T__2);
      setState(82);
      match(ExprParser::T__3);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<FunctionArgumentContext *>(_tracker.createInstance<ExprParser::FuncArgArrTwoDContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(83);
      match(ExprParser::TYPE);
      setState(84);
      match(ExprParser::ID);
      setState(85);
      match(ExprParser::T__2);
      setState(86);
      match(ExprParser::T__3);
      setState(87);
      match(ExprParser::T__2);
      setState(88);
      match(ExprParser::T__3);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclContext ------------------------------------------------------------------

ExprParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::FunctionDeclContext::getRuleIndex() const {
  return ExprParser::RuleFunctionDecl;
}

void ExprParser::FunctionDeclContext::copyFrom(FunctionDeclContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FuncDeclContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::FuncDeclContext::ID() {
  return getToken(ExprParser::ID, 0);
}

ExprParser::BlockContext* ExprParser::FuncDeclContext::block() {
  return getRuleContext<ExprParser::BlockContext>(0);
}

tree::TerminalNode* ExprParser::FuncDeclContext::TYPE() {
  return getToken(ExprParser::TYPE, 0);
}

std::vector<ExprParser::FunctionArgumentContext *> ExprParser::FuncDeclContext::functionArgument() {
  return getRuleContexts<ExprParser::FunctionArgumentContext>();
}

ExprParser::FunctionArgumentContext* ExprParser::FuncDeclContext::functionArgument(size_t i) {
  return getRuleContext<ExprParser::FunctionArgumentContext>(i);
}

ExprParser::FuncDeclContext::FuncDeclContext(FunctionDeclContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::FuncDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFuncDecl(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::FunctionDeclContext* ExprParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 14, ExprParser::RuleFunctionDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<FunctionDeclContext *>(_tracker.createInstance<ExprParser::FuncDeclContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(91);
    match(ExprParser::T__7);
    setState(92);
    dynamic_cast<FuncDeclContext *>(_localctx)->functype = _input->LT(1);
    _la = _input->LA(1);
    if (!(_la == ExprParser::T__8

    || _la == ExprParser::TYPE)) {
      dynamic_cast<FuncDeclContext *>(_localctx)->functype = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(93);
    match(ExprParser::ID);
    setState(94);
    match(ExprParser::T__9);
    setState(96);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::TYPE) {
      setState(95);
      functionArgument();
    }
    setState(102);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::T__5) {
      setState(98);
      match(ExprParser::T__5);
      setState(99);
      functionArgument();
      setState(104);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(105);
    match(ExprParser::T__10);
    setState(106);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ExprParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::ExprContext::getRuleIndex() const {
  return ExprParser::RuleExpr;
}

void ExprParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprIntContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::ExprIntContext::INT() {
  return getToken(ExprParser::INT, 0);
}

ExprParser::ExprIntContext::ExprIntContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprIntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprInt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprCompContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::ExprCompContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ExprCompContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::ExprCompContext::ExprCompContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprCompContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprComp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprNotContext ------------------------------------------------------------------

ExprParser::ExprContext* ExprParser::ExprNotContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::ExprNotContext::ExprNotContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprNotContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprNot(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprAddSubContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::ExprAddSubContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ExprAddSubContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::ExprAddSubContext::ExprAddSubContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprAddSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprAddSub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprVarContext ------------------------------------------------------------------

ExprParser::VariableContext* ExprParser::ExprVarContext::variable() {
  return getRuleContext<ExprParser::VariableContext>(0);
}

ExprParser::ExprVarContext::ExprVarContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprEqContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::ExprEqContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ExprEqContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::ExprEqContext::ExprEqContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprEqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprEq(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprUnaryContext ------------------------------------------------------------------

ExprParser::ExprContext* ExprParser::ExprUnaryContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::ExprUnaryContext::ExprUnaryContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprUnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprUnary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprCharContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::ExprCharContext::CHAR() {
  return getToken(ExprParser::CHAR, 0);
}

ExprParser::ExprCharContext::ExprCharContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprCharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprChar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprDivMulModContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::ExprDivMulModContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ExprDivMulModContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::ExprDivMulModContext::ExprDivMulModContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprDivMulModContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprDivMulMod(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprOrContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::ExprOrContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ExprOrContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::ExprOrContext::ExprOrContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprOrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprOr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprStringContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::ExprStringContext::STRING() {
  return getToken(ExprParser::STRING, 0);
}

ExprParser::ExprStringContext::ExprStringContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprStringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprString(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprBoolContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::ExprBoolContext::BOOL() {
  return getToken(ExprParser::BOOL, 0);
}

ExprParser::ExprBoolContext::ExprBoolContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprBoolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprBool(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprAndContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::ExprAndContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ExprAndContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::ExprAndContext::ExprAndContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprAndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprAnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprTernaryContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::ExprTernaryContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ExprTernaryContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::ExprTernaryContext::ExprTernaryContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprTernaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprTernary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprFloatContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::ExprFloatContext::FLOAT() {
  return getToken(ExprParser::FLOAT, 0);
}

ExprParser::ExprFloatContext::ExprFloatContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprFloatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprFloat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprParenthesisContext ------------------------------------------------------------------

ExprParser::ExprContext* ExprParser::ExprParenthesisContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::ExprParenthesisContext::ExprParenthesisContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprParenthesis(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ExprContext* ExprParser::expr() {
   return expr(0);
}

ExprParser::ExprContext* ExprParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ExprParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  ExprParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 16;
  enterRecursionRule(_localctx, 16, ExprParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(123);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::T__11:
      case ExprParser::T__12: {
        _localctx = _tracker.createInstance<ExprUnaryContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(109);
        dynamic_cast<ExprUnaryContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == ExprParser::T__11

        || _la == ExprParser::T__12)) {
          dynamic_cast<ExprUnaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(110);
        expr(16);
        break;
      }

      case ExprParser::T__13: {
        _localctx = _tracker.createInstance<ExprNotContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(111);
        dynamic_cast<ExprNotContext *>(_localctx)->op = match(ExprParser::T__13);
        setState(112);
        expr(15);
        break;
      }

      case ExprParser::INT: {
        _localctx = _tracker.createInstance<ExprIntContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(113);
        match(ExprParser::INT);
        break;
      }

      case ExprParser::FLOAT: {
        _localctx = _tracker.createInstance<ExprFloatContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(114);
        match(ExprParser::FLOAT);
        break;
      }

      case ExprParser::CHAR: {
        _localctx = _tracker.createInstance<ExprCharContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(115);
        match(ExprParser::CHAR);
        break;
      }

      case ExprParser::BOOL: {
        _localctx = _tracker.createInstance<ExprBoolContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(116);
        match(ExprParser::BOOL);
        break;
      }

      case ExprParser::STRING: {
        _localctx = _tracker.createInstance<ExprStringContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(117);
        match(ExprParser::STRING);
        break;
      }

      case ExprParser::T__9: {
        _localctx = _tracker.createInstance<ExprParenthesisContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(118);
        match(ExprParser::T__9);
        setState(119);
        expr(0);
        setState(120);
        match(ExprParser::T__10);
        break;
      }

      case ExprParser::ID: {
        _localctx = _tracker.createInstance<ExprVarContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(122);
        variable();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(151);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(149);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprDivMulModContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(125);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(126);
          dynamic_cast<ExprDivMulModContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << ExprParser::T__14)
            | (1ULL << ExprParser::T__15)
            | (1ULL << ExprParser::T__16))) != 0))) {
            dynamic_cast<ExprDivMulModContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(127);
          expr(15);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprAddSubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(128);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(129);
          dynamic_cast<ExprAddSubContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ExprParser::T__11

          || _la == ExprParser::T__12)) {
            dynamic_cast<ExprAddSubContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(130);
          expr(14);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ExprCompContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(131);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(132);
          dynamic_cast<ExprCompContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << ExprParser::T__17)
            | (1ULL << ExprParser::T__18)
            | (1ULL << ExprParser::T__19)
            | (1ULL << ExprParser::T__20))) != 0))) {
            dynamic_cast<ExprCompContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(133);
          expr(13);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ExprEqContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(134);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(135);
          dynamic_cast<ExprEqContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ExprParser::T__21

          || _la == ExprParser::T__22)) {
            dynamic_cast<ExprEqContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(136);
          expr(12);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<ExprAndContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(137);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(138);
          dynamic_cast<ExprAndContext *>(_localctx)->op = match(ExprParser::T__23);
          setState(139);
          expr(11);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<ExprOrContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(140);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(141);
          dynamic_cast<ExprOrContext *>(_localctx)->op = match(ExprParser::T__24);
          setState(142);
          expr(10);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<ExprTernaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(143);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(144);
          match(ExprParser::T__25);
          setState(145);
          expr(0);
          setState(146);
          match(ExprParser::T__26);
          setState(147);
          expr(9);
          break;
        }

        } 
      }
      setState(153);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

ExprParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::StatementContext::getRuleIndex() const {
  return ExprParser::RuleStatement;
}

void ExprParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StatBlockContext ------------------------------------------------------------------

ExprParser::BlockContext* ExprParser::StatBlockContext::block() {
  return getRuleContext<ExprParser::BlockContext>(0);
}

ExprParser::StatBlockContext::StatBlockContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::StatBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatBlock(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatVarDeclContext ------------------------------------------------------------------

ExprParser::VarDeclContext* ExprParser::StatVarDeclContext::varDecl() {
  return getRuleContext<ExprParser::VarDeclContext>(0);
}

ExprParser::StatVarDeclContext::StatVarDeclContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::StatVarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatVarDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatVarAssignContext ------------------------------------------------------------------

ExprParser::VariableContext* ExprParser::StatVarAssignContext::variable() {
  return getRuleContext<ExprParser::VariableContext>(0);
}

ExprParser::ExprContext* ExprParser::StatVarAssignContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::StatVarAssignContext::StatVarAssignContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::StatVarAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatVarAssign(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::StatementContext* ExprParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 18, ExprParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(161);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::TYPE: {
        _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatVarDeclContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(154);
        varDecl();
        break;
      }

      case ExprParser::ID: {
        _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatVarAssignContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(155);
        variable();
        setState(156);
        match(ExprParser::T__4);
        setState(157);
        expr(0);
        setState(158);
        match(ExprParser::T__6);
        break;
      }

      case ExprParser::T__0: {
        _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatBlockContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(160);
        block();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool ExprParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 8: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ExprParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 14);
    case 1: return precpred(_ctx, 13);
    case 2: return precpred(_ctx, 12);
    case 3: return precpred(_ctx, 11);
    case 4: return precpred(_ctx, 10);
    case 5: return precpred(_ctx, 9);
    case 6: return precpred(_ctx, 8);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ExprParser::_decisionToDFA;
atn::PredictionContextCache ExprParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ExprParser::_atn;
std::vector<uint16_t> ExprParser::_serializedATN;

std::vector<std::string> ExprParser::_ruleNames = {
  "prog", "progStatement", "block", "variable", "varAssign", "varDecl", 
  "functionArgument", "functionDecl", "expr", "statement"
};

std::vector<std::string> ExprParser::_literalNames = {
  "", "'{'", "'}'", "'['", "']'", "'='", "','", "';'", "'func'", "'void'", 
  "'('", "')'", "'+'", "'-'", "'!'", "'/'", "'*'", "'%'", "'<'", "'<='", 
  "'>'", "'>='", "'=='", "'!='", "'&&'", "'||'", "'?'", "':'"
};

std::vector<std::string> ExprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "TYPE", "INT", "FLOAT", "BOOL", 
  "CHAR", "STRING", "ID", "COMMENT", "NS"
};

dfa::Vocabulary ExprParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ExprParser::_tokenNames;

ExprParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x26, 0xa6, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x3, 0x2, 0x7, 0x2, 0x18, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x1b, 0xb, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x21, 0xa, 0x3, 
    0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x25, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x28, 
    0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x3a, 0xa, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x43, 
    0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x49, 0xa, 
    0x7, 0xc, 0x7, 0xe, 0x7, 0x4c, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x5c, 0xa, 0x8, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x63, 0xa, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x67, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x6a, 
    0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x7e, 0xa, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x98, 0xa, 0xa, 0xc, 0xa, 
    0xe, 0xa, 0x9b, 0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xa4, 0xa, 0xb, 0x3, 0xb, 0x2, 0x3, 
    0x12, 0xc, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x2, 
    0x7, 0x4, 0x2, 0xb, 0xb, 0x1e, 0x1e, 0x3, 0x2, 0xe, 0xf, 0x3, 0x2, 0x11, 
    0x13, 0x3, 0x2, 0x14, 0x17, 0x3, 0x2, 0x18, 0x19, 0x2, 0xb8, 0x2, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x20, 0x3, 0x2, 0x2, 0x2, 0x6, 0x22, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0x39, 0x3, 0x2, 0x2, 0x2, 0xa, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x3f, 0x3, 0x2, 0x2, 0x2, 0xe, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x5d, 0x3, 0x2, 0x2, 0x2, 0x12, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x14, 0xa3, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x18, 0x5, 0x4, 0x3, 0x2, 0x17, 0x16, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x19, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0x19, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1c, 0x3, 0x2, 0x2, 
    0x2, 0x1b, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x7, 0x2, 0x2, 0x3, 
    0x1d, 0x3, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x21, 0x5, 0xc, 0x7, 0x2, 0x1f, 
    0x21, 0x5, 0x10, 0x9, 0x2, 0x20, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x20, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0x21, 0x5, 0x3, 0x2, 0x2, 0x2, 0x22, 0x26, 0x7, 
    0x3, 0x2, 0x2, 0x23, 0x25, 0x5, 0x14, 0xb, 0x2, 0x24, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0x25, 0x28, 0x3, 0x2, 0x2, 0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x27, 0x3, 0x2, 0x2, 0x2, 0x27, 0x29, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0x26, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 0x7, 0x4, 0x2, 0x2, 0x2a, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x3a, 0x7, 0x24, 0x2, 0x2, 0x2c, 0x2d, 
    0x7, 0x24, 0x2, 0x2, 0x2d, 0x2e, 0x7, 0x5, 0x2, 0x2, 0x2e, 0x2f, 0x5, 
    0x12, 0xa, 0x2, 0x2f, 0x30, 0x7, 0x6, 0x2, 0x2, 0x30, 0x3a, 0x3, 0x2, 
    0x2, 0x2, 0x31, 0x32, 0x7, 0x24, 0x2, 0x2, 0x32, 0x33, 0x7, 0x5, 0x2, 
    0x2, 0x33, 0x34, 0x5, 0x12, 0xa, 0x2, 0x34, 0x35, 0x7, 0x6, 0x2, 0x2, 
    0x35, 0x36, 0x7, 0x5, 0x2, 0x2, 0x36, 0x37, 0x5, 0x12, 0xa, 0x2, 0x37, 
    0x38, 0x7, 0x6, 0x2, 0x2, 0x38, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x39, 0x2b, 
    0x3, 0x2, 0x2, 0x2, 0x39, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x39, 0x31, 0x3, 
    0x2, 0x2, 0x2, 0x3a, 0x9, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x24, 
    0x2, 0x2, 0x3c, 0x3d, 0x7, 0x7, 0x2, 0x2, 0x3d, 0x3e, 0x5, 0x12, 0xa, 
    0x2, 0x3e, 0xb, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x42, 0x7, 0x1e, 0x2, 0x2, 
    0x40, 0x43, 0x5, 0x8, 0x5, 0x2, 0x41, 0x43, 0x5, 0xa, 0x6, 0x2, 0x42, 
    0x40, 0x3, 0x2, 0x2, 0x2, 0x42, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 0x4a, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 0x8, 0x2, 0x2, 0x45, 0x49, 0x5, 
    0x8, 0x5, 0x2, 0x46, 0x47, 0x7, 0x8, 0x2, 0x2, 0x47, 0x49, 0x5, 0xa, 
    0x6, 0x2, 0x48, 0x44, 0x3, 0x2, 0x2, 0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 
    0x2, 0x49, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4c, 
    0x4a, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x9, 0x2, 0x2, 0x4e, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x1e, 0x2, 0x2, 0x50, 0x5c, 0x7, 
    0x24, 0x2, 0x2, 0x51, 0x52, 0x7, 0x1e, 0x2, 0x2, 0x52, 0x53, 0x7, 0x24, 
    0x2, 0x2, 0x53, 0x54, 0x7, 0x5, 0x2, 0x2, 0x54, 0x5c, 0x7, 0x6, 0x2, 
    0x2, 0x55, 0x56, 0x7, 0x1e, 0x2, 0x2, 0x56, 0x57, 0x7, 0x24, 0x2, 0x2, 
    0x57, 0x58, 0x7, 0x5, 0x2, 0x2, 0x58, 0x59, 0x7, 0x6, 0x2, 0x2, 0x59, 
    0x5a, 0x7, 0x5, 0x2, 0x2, 0x5a, 0x5c, 0x7, 0x6, 0x2, 0x2, 0x5b, 0x4f, 
    0x3, 0x2, 0x2, 0x2, 0x5b, 0x51, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x55, 0x3, 
    0x2, 0x2, 0x2, 0x5c, 0xf, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0xa, 
    0x2, 0x2, 0x5e, 0x5f, 0x9, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x7, 0x24, 0x2, 
    0x2, 0x60, 0x62, 0x7, 0xc, 0x2, 0x2, 0x61, 0x63, 0x5, 0xe, 0x8, 0x2, 
    0x62, 0x61, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x3, 0x2, 0x2, 0x2, 0x63, 
    0x68, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x7, 0x8, 0x2, 0x2, 0x65, 0x67, 
    0x5, 0xe, 0x8, 0x2, 0x66, 0x64, 0x3, 0x2, 0x2, 0x2, 0x67, 0x6a, 0x3, 
    0x2, 0x2, 0x2, 0x68, 0x66, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x3, 0x2, 
    0x2, 0x2, 0x69, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x68, 0x3, 0x2, 0x2, 
    0x2, 0x6b, 0x6c, 0x7, 0xd, 0x2, 0x2, 0x6c, 0x6d, 0x5, 0x6, 0x4, 0x2, 
    0x6d, 0x11, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x8, 0xa, 0x1, 0x2, 0x6f, 
    0x70, 0x9, 0x3, 0x2, 0x2, 0x70, 0x7e, 0x5, 0x12, 0xa, 0x12, 0x71, 0x72, 
    0x7, 0x10, 0x2, 0x2, 0x72, 0x7e, 0x5, 0x12, 0xa, 0x11, 0x73, 0x7e, 0x7, 
    0x1f, 0x2, 0x2, 0x74, 0x7e, 0x7, 0x20, 0x2, 0x2, 0x75, 0x7e, 0x7, 0x22, 
    0x2, 0x2, 0x76, 0x7e, 0x7, 0x21, 0x2, 0x2, 0x77, 0x7e, 0x7, 0x23, 0x2, 
    0x2, 0x78, 0x79, 0x7, 0xc, 0x2, 0x2, 0x79, 0x7a, 0x5, 0x12, 0xa, 0x2, 
    0x7a, 0x7b, 0x7, 0xd, 0x2, 0x2, 0x7b, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7c, 
    0x7e, 0x5, 0x8, 0x5, 0x2, 0x7d, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x71, 
    0x3, 0x2, 0x2, 0x2, 0x7d, 0x73, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x74, 0x3, 
    0x2, 0x2, 0x2, 0x7d, 0x75, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x76, 0x3, 0x2, 
    0x2, 0x2, 0x7d, 0x77, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x78, 0x3, 0x2, 0x2, 
    0x2, 0x7d, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x99, 0x3, 0x2, 0x2, 0x2, 
    0x7f, 0x80, 0xc, 0x10, 0x2, 0x2, 0x80, 0x81, 0x9, 0x4, 0x2, 0x2, 0x81, 
    0x98, 0x5, 0x12, 0xa, 0x11, 0x82, 0x83, 0xc, 0xf, 0x2, 0x2, 0x83, 0x84, 
    0x9, 0x3, 0x2, 0x2, 0x84, 0x98, 0x5, 0x12, 0xa, 0x10, 0x85, 0x86, 0xc, 
    0xe, 0x2, 0x2, 0x86, 0x87, 0x9, 0x5, 0x2, 0x2, 0x87, 0x98, 0x5, 0x12, 
    0xa, 0xf, 0x88, 0x89, 0xc, 0xd, 0x2, 0x2, 0x89, 0x8a, 0x9, 0x6, 0x2, 
    0x2, 0x8a, 0x98, 0x5, 0x12, 0xa, 0xe, 0x8b, 0x8c, 0xc, 0xc, 0x2, 0x2, 
    0x8c, 0x8d, 0x7, 0x1a, 0x2, 0x2, 0x8d, 0x98, 0x5, 0x12, 0xa, 0xd, 0x8e, 
    0x8f, 0xc, 0xb, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x1b, 0x2, 0x2, 0x90, 0x98, 
    0x5, 0x12, 0xa, 0xc, 0x91, 0x92, 0xc, 0xa, 0x2, 0x2, 0x92, 0x93, 0x7, 
    0x1c, 0x2, 0x2, 0x93, 0x94, 0x5, 0x12, 0xa, 0x2, 0x94, 0x95, 0x7, 0x1d, 
    0x2, 0x2, 0x95, 0x96, 0x5, 0x12, 0xa, 0xb, 0x96, 0x98, 0x3, 0x2, 0x2, 
    0x2, 0x97, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x97, 0x82, 0x3, 0x2, 0x2, 0x2, 
    0x97, 0x85, 0x3, 0x2, 0x2, 0x2, 0x97, 0x88, 0x3, 0x2, 0x2, 0x2, 0x97, 
    0x8b, 0x3, 0x2, 0x2, 0x2, 0x97, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x97, 0x91, 
    0x3, 0x2, 0x2, 0x2, 0x98, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x99, 0x97, 0x3, 
    0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0x9b, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9c, 0xa4, 0x5, 0xc, 0x7, 
    0x2, 0x9d, 0x9e, 0x5, 0x8, 0x5, 0x2, 0x9e, 0x9f, 0x7, 0x7, 0x2, 0x2, 
    0x9f, 0xa0, 0x5, 0x12, 0xa, 0x2, 0xa0, 0xa1, 0x7, 0x9, 0x2, 0x2, 0xa1, 
    0xa4, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa4, 0x5, 0x6, 0x4, 0x2, 0xa3, 0x9c, 
    0x3, 0x2, 0x2, 0x2, 0xa3, 0x9d, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa2, 0x3, 
    0x2, 0x2, 0x2, 0xa4, 0x15, 0x3, 0x2, 0x2, 0x2, 0x10, 0x19, 0x20, 0x26, 
    0x39, 0x42, 0x48, 0x4a, 0x5b, 0x62, 0x68, 0x7d, 0x97, 0x99, 0xa3, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ExprParser::Initializer ExprParser::_init;
