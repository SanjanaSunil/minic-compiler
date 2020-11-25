
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
    setState(29);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::T__7

    || _la == ExprParser::TYPE) {
      setState(26);
      progStatement();
      setState(31);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(32);
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
    setState(36);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::TYPE: {
        setState(34);
        varDecl();
        break;
      }

      case ExprParser::T__7: {
        setState(35);
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
    setState(38);
    match(ExprParser::T__0);
    setState(42);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::T__0)
      | (1ULL << ExprParser::T__27)
      | (1ULL << ExprParser::T__28)
      | (1ULL << ExprParser::T__29)
      | (1ULL << ExprParser::T__30)
      | (1ULL << ExprParser::T__31)
      | (1ULL << ExprParser::T__34)
      | (1ULL << ExprParser::TYPE)
      | (1ULL << ExprParser::ID))) != 0)) {
      setState(39);
      statement();
      setState(44);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(45);
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
    setState(61);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VariableContext *>(_tracker.createInstance<ExprParser::VarIdContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(47);
      match(ExprParser::ID);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VariableContext *>(_tracker.createInstance<ExprParser::VarArrOneDContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(48);
      match(ExprParser::ID);
      setState(49);
      match(ExprParser::T__2);
      setState(50);
      expr(0);
      setState(51);
      match(ExprParser::T__3);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<VariableContext *>(_tracker.createInstance<ExprParser::VarArrTwoDContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(53);
      match(ExprParser::ID);
      setState(54);
      match(ExprParser::T__2);
      setState(55);
      expr(0);
      setState(56);
      match(ExprParser::T__3);
      setState(57);
      match(ExprParser::T__2);
      setState(58);
      expr(0);
      setState(59);
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
    setState(63);
    match(ExprParser::ID);
    setState(64);
    match(ExprParser::T__4);
    setState(65);
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

ExprParser::VarDeclTypeAContext* ExprParser::VariableDeclContext::varDeclTypeA() {
  return getRuleContext<ExprParser::VarDeclTypeAContext>(0);
}

std::vector<ExprParser::VarDeclTypeBContext *> ExprParser::VariableDeclContext::varDeclTypeB() {
  return getRuleContexts<ExprParser::VarDeclTypeBContext>();
}

ExprParser::VarDeclTypeBContext* ExprParser::VariableDeclContext::varDeclTypeB(size_t i) {
  return getRuleContext<ExprParser::VarDeclTypeBContext>(i);
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
    setState(67);
    match(ExprParser::TYPE);
    setState(68);
    varDeclTypeA();
    setState(72);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::T__6) {
      setState(69);
      varDeclTypeB();
      setState(74);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(75);
    match(ExprParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclTypeAContext ------------------------------------------------------------------

ExprParser::VarDeclTypeAContext::VarDeclTypeAContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::VarDeclTypeAContext::getRuleIndex() const {
  return ExprParser::RuleVarDeclTypeA;
}

void ExprParser::VarDeclTypeAContext::copyFrom(VarDeclTypeAContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VariableDeclTypeAContext ------------------------------------------------------------------

ExprParser::VariableContext* ExprParser::VariableDeclTypeAContext::variable() {
  return getRuleContext<ExprParser::VariableContext>(0);
}

ExprParser::VarAssignContext* ExprParser::VariableDeclTypeAContext::varAssign() {
  return getRuleContext<ExprParser::VarAssignContext>(0);
}

ExprParser::VariableDeclTypeAContext::VariableDeclTypeAContext(VarDeclTypeAContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::VariableDeclTypeAContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVariableDeclTypeA(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::VarDeclTypeAContext* ExprParser::varDeclTypeA() {
  VarDeclTypeAContext *_localctx = _tracker.createInstance<VarDeclTypeAContext>(_ctx, getState());
  enterRule(_localctx, 12, ExprParser::RuleVarDeclTypeA);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<VarDeclTypeAContext *>(_tracker.createInstance<ExprParser::VariableDeclTypeAContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(79);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(77);
      variable();
      break;
    }

    case 2: {
      setState(78);
      varAssign();
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

//----------------- VarDeclTypeBContext ------------------------------------------------------------------

ExprParser::VarDeclTypeBContext::VarDeclTypeBContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::VarDeclTypeBContext::getRuleIndex() const {
  return ExprParser::RuleVarDeclTypeB;
}

void ExprParser::VarDeclTypeBContext::copyFrom(VarDeclTypeBContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VariableDeclTypeBContext ------------------------------------------------------------------

ExprParser::VariableContext* ExprParser::VariableDeclTypeBContext::variable() {
  return getRuleContext<ExprParser::VariableContext>(0);
}

ExprParser::VarAssignContext* ExprParser::VariableDeclTypeBContext::varAssign() {
  return getRuleContext<ExprParser::VarAssignContext>(0);
}

ExprParser::VariableDeclTypeBContext::VariableDeclTypeBContext(VarDeclTypeBContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::VariableDeclTypeBContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVariableDeclTypeB(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::VarDeclTypeBContext* ExprParser::varDeclTypeB() {
  VarDeclTypeBContext *_localctx = _tracker.createInstance<VarDeclTypeBContext>(_ctx, getState());
  enterRule(_localctx, 14, ExprParser::RuleVarDeclTypeB);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<VarDeclTypeBContext *>(_tracker.createInstance<ExprParser::VariableDeclTypeBContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(85);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(81);
      match(ExprParser::T__6);
      setState(82);
      variable();
      break;
    }

    case 2: {
      setState(83);
      match(ExprParser::T__6);
      setState(84);
      varAssign();
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
  enterRule(_localctx, 16, ExprParser::RuleFunctionArgument);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(99);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<FunctionArgumentContext *>(_tracker.createInstance<ExprParser::FuncArgContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(87);
      match(ExprParser::TYPE);
      setState(88);
      match(ExprParser::ID);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<FunctionArgumentContext *>(_tracker.createInstance<ExprParser::FuncArgArrOneDContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(89);
      match(ExprParser::TYPE);
      setState(90);
      match(ExprParser::ID);
      setState(91);
      match(ExprParser::T__2);
      setState(92);
      match(ExprParser::T__3);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<FunctionArgumentContext *>(_tracker.createInstance<ExprParser::FuncArgArrTwoDContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(93);
      match(ExprParser::TYPE);
      setState(94);
      match(ExprParser::ID);
      setState(95);
      match(ExprParser::T__2);
      setState(96);
      match(ExprParser::T__3);
      setState(97);
      match(ExprParser::T__2);
      setState(98);
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
  enterRule(_localctx, 18, ExprParser::RuleFunctionDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<FunctionDeclContext *>(_tracker.createInstance<ExprParser::FuncDeclContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(101);
    match(ExprParser::T__7);
    setState(102);
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
    setState(103);
    match(ExprParser::ID);
    setState(104);
    match(ExprParser::T__9);
    setState(106);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::TYPE) {
      setState(105);
      functionArgument();
    }
    setState(112);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::T__6) {
      setState(108);
      match(ExprParser::T__6);
      setState(109);
      functionArgument();
      setState(114);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(115);
    match(ExprParser::T__10);
    setState(116);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

ExprParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::FunctionCallContext::getRuleIndex() const {
  return ExprParser::RuleFunctionCall;
}

void ExprParser::FunctionCallContext::copyFrom(FunctionCallContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FuncCallContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::FuncCallContext::ID() {
  return getToken(ExprParser::ID, 0);
}

std::vector<ExprParser::ExprContext *> ExprParser::FuncCallContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::FuncCallContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::FuncCallContext::FuncCallContext(FunctionCallContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::FuncCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFuncCall(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::FunctionCallContext* ExprParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 20, ExprParser::RuleFunctionCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<FunctionCallContext *>(_tracker.createInstance<ExprParser::FuncCallContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(118);
    match(ExprParser::ID);
    setState(119);
    match(ExprParser::T__9);
    setState(121);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::T__9)
      | (1ULL << ExprParser::T__11)
      | (1ULL << ExprParser::T__12)
      | (1ULL << ExprParser::INT)
      | (1ULL << ExprParser::FLOAT)
      | (1ULL << ExprParser::BOOL)
      | (1ULL << ExprParser::CHAR)
      | (1ULL << ExprParser::STRING)
      | (1ULL << ExprParser::ID))) != 0)) {
      setState(120);
      expr(0);
    }
    setState(127);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::T__6) {
      setState(123);
      match(ExprParser::T__6);
      setState(124);
      expr(0);
      setState(129);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(130);
    match(ExprParser::T__10);
   
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
//----------------- ExprFuncCallContext ------------------------------------------------------------------

ExprParser::FunctionCallContext* ExprParser::ExprFuncCallContext::functionCall() {
  return getRuleContext<ExprParser::FunctionCallContext>(0);
}

ExprParser::ExprFuncCallContext::ExprFuncCallContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExprFuncCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExprFuncCall(this);
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
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, ExprParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(148);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ExprUnaryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(133);
      dynamic_cast<ExprUnaryContext *>(_localctx)->op = match(ExprParser::T__11);
      setState(134);
      expr(17);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ExprNotContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(135);
      dynamic_cast<ExprNotContext *>(_localctx)->op = match(ExprParser::T__12);
      setState(136);
      expr(16);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ExprIntContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(137);
      match(ExprParser::INT);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ExprFloatContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(138);
      match(ExprParser::FLOAT);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ExprCharContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(139);
      match(ExprParser::CHAR);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ExprBoolContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(140);
      match(ExprParser::BOOL);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ExprStringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(141);
      match(ExprParser::STRING);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ExprParenthesisContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(142);
      match(ExprParser::T__9);
      setState(143);
      expr(0);
      setState(144);
      match(ExprParser::T__10);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<ExprVarContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(146);
      variable();
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<ExprFuncCallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(147);
      functionCall();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(176);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(174);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprDivMulModContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(150);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(151);
          dynamic_cast<ExprDivMulModContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << ExprParser::T__13)
            | (1ULL << ExprParser::T__14)
            | (1ULL << ExprParser::T__15))) != 0))) {
            dynamic_cast<ExprDivMulModContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(152);
          expr(16);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprAddSubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(153);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(154);
          dynamic_cast<ExprAddSubContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ExprParser::T__11

          || _la == ExprParser::T__16)) {
            dynamic_cast<ExprAddSubContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(155);
          expr(15);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ExprCompContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(156);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(157);
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
          setState(158);
          expr(14);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ExprEqContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(159);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(160);
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
          setState(161);
          expr(13);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<ExprAndContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(162);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(163);
          dynamic_cast<ExprAndContext *>(_localctx)->op = match(ExprParser::T__23);
          setState(164);
          expr(12);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<ExprOrContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(165);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(166);
          dynamic_cast<ExprOrContext *>(_localctx)->op = match(ExprParser::T__24);
          setState(167);
          expr(11);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<ExprTernaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(168);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(169);
          match(ExprParser::T__25);
          setState(170);
          expr(0);
          setState(171);
          match(ExprParser::T__26);
          setState(172);
          expr(10);
          break;
        }

        } 
      }
      setState(178);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
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
//----------------- StatFuncCallContext ------------------------------------------------------------------

ExprParser::FunctionCallContext* ExprParser::StatFuncCallContext::functionCall() {
  return getRuleContext<ExprParser::FunctionCallContext>(0);
}

ExprParser::StatFuncCallContext::StatFuncCallContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::StatFuncCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatFuncCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatWhileContext ------------------------------------------------------------------

ExprParser::ExprContext* ExprParser::StatWhileContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::BlockContext* ExprParser::StatWhileContext::block() {
  return getRuleContext<ExprParser::BlockContext>(0);
}

ExprParser::StatWhileContext::StatWhileContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::StatWhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatWhile(this);
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
//----------------- StatBreakContext ------------------------------------------------------------------

ExprParser::StatBreakContext::StatBreakContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::StatBreakContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatBreak(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatContinueContext ------------------------------------------------------------------

ExprParser::StatContinueContext::StatContinueContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::StatContinueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatContinue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatReturnContext ------------------------------------------------------------------

ExprParser::ExprContext* ExprParser::StatReturnContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::StatReturnContext::StatReturnContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::StatReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatReturn(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatIfContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::StatIfContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::StatIfContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

std::vector<ExprParser::BlockContext *> ExprParser::StatIfContext::block() {
  return getRuleContexts<ExprParser::BlockContext>();
}

ExprParser::BlockContext* ExprParser::StatIfContext::block(size_t i) {
  return getRuleContext<ExprParser::BlockContext>(i);
}

ExprParser::StatIfContext::StatIfContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::StatIfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatIf(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatForContext ------------------------------------------------------------------

ExprParser::BlockContext* ExprParser::StatForContext::block() {
  return getRuleContext<ExprParser::BlockContext>(0);
}

ExprParser::VarDeclContext* ExprParser::StatForContext::varDecl() {
  return getRuleContext<ExprParser::VarDeclContext>(0);
}

std::vector<ExprParser::VariableContext *> ExprParser::StatForContext::variable() {
  return getRuleContexts<ExprParser::VariableContext>();
}

ExprParser::VariableContext* ExprParser::StatForContext::variable(size_t i) {
  return getRuleContext<ExprParser::VariableContext>(i);
}

std::vector<ExprParser::ExprContext *> ExprParser::StatForContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::StatForContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::StatForContext::StatForContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::StatForContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatFor(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::StatementContext* ExprParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 24, ExprParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(246);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatVarDeclContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(179);
      varDecl();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatVarAssignContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(180);
      variable();
      setState(181);
      match(ExprParser::T__4);
      setState(182);
      expr(0);
      setState(183);
      match(ExprParser::T__5);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatBlockContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(185);
      block();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatFuncCallContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(186);
      functionCall();
      setState(187);
      match(ExprParser::T__5);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatReturnContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(189);
      match(ExprParser::T__27);
      setState(191);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << ExprParser::T__9)
        | (1ULL << ExprParser::T__11)
        | (1ULL << ExprParser::T__12)
        | (1ULL << ExprParser::INT)
        | (1ULL << ExprParser::FLOAT)
        | (1ULL << ExprParser::BOOL)
        | (1ULL << ExprParser::CHAR)
        | (1ULL << ExprParser::STRING)
        | (1ULL << ExprParser::ID))) != 0)) {
        setState(190);
        expr(0);
      }
      setState(193);
      match(ExprParser::T__5);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatBreakContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(194);
      match(ExprParser::T__28);
      setState(195);
      match(ExprParser::T__5);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatContinueContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(196);
      match(ExprParser::T__29);
      setState(197);
      match(ExprParser::T__5);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatWhileContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(198);
      match(ExprParser::T__30);
      setState(199);
      match(ExprParser::T__9);
      setState(200);
      expr(0);
      setState(201);
      match(ExprParser::T__10);
      setState(202);
      block();
      break;
    }

    case 9: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatIfContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(204);
      match(ExprParser::T__31);
      setState(205);
      match(ExprParser::T__9);
      setState(206);
      expr(0);
      setState(207);
      match(ExprParser::T__10);
      setState(208);
      block();
      setState(217);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ExprParser::T__32) {
        setState(209);
        match(ExprParser::T__32);
        setState(210);
        match(ExprParser::T__9);
        setState(211);
        expr(0);
        setState(212);
        match(ExprParser::T__10);
        setState(213);
        block();
        setState(219);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(222);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == ExprParser::T__33) {
        setState(220);
        match(ExprParser::T__33);
        setState(221);
        block();
      }
      break;
    }

    case 10: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<ExprParser::StatForContext>(_localctx));
      enterOuterAlt(_localctx, 10);
      setState(224);
      match(ExprParser::T__34);
      setState(225);
      match(ExprParser::T__9);
      setState(232);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
      case 1: {
        setState(226);
        varDecl();
        break;
      }

      case 2: {
        setState(227);
        dynamic_cast<StatForContext *>(_localctx)->initvar = variable();
        setState(228);
        match(ExprParser::T__4);
        setState(229);
        dynamic_cast<StatForContext *>(_localctx)->initexpr = expr(0);
        setState(230);
        match(ExprParser::T__5);
        break;
      }

      }
      setState(235);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << ExprParser::T__9)
        | (1ULL << ExprParser::T__11)
        | (1ULL << ExprParser::T__12)
        | (1ULL << ExprParser::INT)
        | (1ULL << ExprParser::FLOAT)
        | (1ULL << ExprParser::BOOL)
        | (1ULL << ExprParser::CHAR)
        | (1ULL << ExprParser::STRING)
        | (1ULL << ExprParser::ID))) != 0)) {
        setState(234);
        dynamic_cast<StatForContext *>(_localctx)->condexpr = expr(0);
      }
      setState(237);
      match(ExprParser::T__5);
      setState(242);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == ExprParser::ID) {
        setState(238);
        dynamic_cast<StatForContext *>(_localctx)->loopvar = variable();
        setState(239);
        match(ExprParser::T__4);
        setState(240);
        dynamic_cast<StatForContext *>(_localctx)->loopexpr = expr(0);
      }
      setState(244);
      match(ExprParser::T__10);
      setState(245);
      block();
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

bool ExprParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 11: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ExprParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 15);
    case 1: return precpred(_ctx, 14);
    case 2: return precpred(_ctx, 13);
    case 3: return precpred(_ctx, 12);
    case 4: return precpred(_ctx, 11);
    case 5: return precpred(_ctx, 10);
    case 6: return precpred(_ctx, 9);

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
  "varDeclTypeA", "varDeclTypeB", "functionArgument", "functionDecl", "functionCall", 
  "expr", "statement"
};

std::vector<std::string> ExprParser::_literalNames = {
  "", "'{'", "'}'", "'['", "']'", "'='", "';'", "','", "'func'", "'void'", 
  "'('", "')'", "'-'", "'!'", "'/'", "'*'", "'%'", "'+'", "'<'", "'<='", 
  "'>'", "'>='", "'=='", "'!='", "'&&'", "'||'", "'?'", "':'", "'return'", 
  "'break'", "'continue'", "'while'", "'if'", "'elif'", "'else'", "'for'"
};

std::vector<std::string> ExprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "TYPE", "INT", "FLOAT", "BOOL", "CHAR", "STRING", "ID", "COMMENT", "NS"
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
    0x3, 0x2e, 0xfb, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x3, 
    0x2, 0x7, 0x2, 0x1e, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x21, 0xb, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x27, 0xa, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x7, 0x4, 0x2b, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x2e, 0xb, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x40, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x49, 0xa, 0x7, 
    0xc, 0x7, 0xe, 0x7, 0x4c, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x5, 0x8, 0x52, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x5, 0x9, 0x58, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x5, 0xa, 0x66, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x5, 0xb, 0x6d, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x71, 
    0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x74, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x7c, 0xa, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x7, 0xc, 0x80, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x83, 0xb, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x97, 0xa, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xb1, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 
    0xb4, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 
    0xe, 0xc2, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0xda, 0xa, 0xe, 0xc, 0xe, 0xe, 
    0xe, 0xdd, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xe1, 0xa, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x5, 0xe, 0xeb, 0xa, 0xe, 0x3, 0xe, 0x5, 0xe, 0xee, 0xa, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xf5, 0xa, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xf9, 0xa, 0xe, 0x3, 0xe, 0x2, 0x3, 0x18, 
    0xf, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x2, 0x7, 0x4, 0x2, 0xb, 0xb, 0x26, 0x26, 0x3, 0x2, 0x10, 0x12, 
    0x4, 0x2, 0xe, 0xe, 0x13, 0x13, 0x3, 0x2, 0x14, 0x17, 0x3, 0x2, 0x18, 
    0x19, 0x2, 0x11b, 0x2, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x4, 0x26, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x28, 0x3, 0x2, 0x2, 0x2, 0x8, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x41, 0x3, 0x2, 0x2, 0x2, 0xc, 0x45, 0x3, 0x2, 0x2, 0x2, 0xe, 0x51, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x57, 0x3, 0x2, 0x2, 0x2, 0x12, 0x65, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x67, 0x3, 0x2, 0x2, 0x2, 0x16, 0x78, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x96, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xf8, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x1e, 0x5, 0x4, 0x3, 0x2, 0x1d, 0x1c, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x21, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1f, 
    0x20, 0x3, 0x2, 0x2, 0x2, 0x20, 0x22, 0x3, 0x2, 0x2, 0x2, 0x21, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x7, 0x2, 0x2, 0x3, 0x23, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x27, 0x5, 0xc, 0x7, 0x2, 0x25, 0x27, 0x5, 0x14, 
    0xb, 0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 0x2, 0x26, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0x27, 0x5, 0x3, 0x2, 0x2, 0x2, 0x28, 0x2c, 0x7, 0x3, 0x2, 0x2, 
    0x29, 0x2b, 0x5, 0x1a, 0xe, 0x2, 0x2a, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2b, 
    0x2e, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 
    0x3, 0x2, 0x2, 0x2, 0x2d, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2c, 0x3, 
    0x2, 0x2, 0x2, 0x2f, 0x30, 0x7, 0x4, 0x2, 0x2, 0x30, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x31, 0x40, 0x7, 0x2c, 0x2, 0x2, 0x32, 0x33, 0x7, 0x2c, 0x2, 
    0x2, 0x33, 0x34, 0x7, 0x5, 0x2, 0x2, 0x34, 0x35, 0x5, 0x18, 0xd, 0x2, 
    0x35, 0x36, 0x7, 0x6, 0x2, 0x2, 0x36, 0x40, 0x3, 0x2, 0x2, 0x2, 0x37, 
    0x38, 0x7, 0x2c, 0x2, 0x2, 0x38, 0x39, 0x7, 0x5, 0x2, 0x2, 0x39, 0x3a, 
    0x5, 0x18, 0xd, 0x2, 0x3a, 0x3b, 0x7, 0x6, 0x2, 0x2, 0x3b, 0x3c, 0x7, 
    0x5, 0x2, 0x2, 0x3c, 0x3d, 0x5, 0x18, 0xd, 0x2, 0x3d, 0x3e, 0x7, 0x6, 
    0x2, 0x2, 0x3e, 0x40, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x3f, 0x32, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x37, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x9, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x7, 0x2c, 0x2, 0x2, 0x42, 
    0x43, 0x7, 0x7, 0x2, 0x2, 0x43, 0x44, 0x5, 0x18, 0xd, 0x2, 0x44, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 0x7, 0x26, 0x2, 0x2, 0x46, 0x4a, 0x5, 
    0xe, 0x8, 0x2, 0x47, 0x49, 0x5, 0x10, 0x9, 0x2, 0x48, 0x47, 0x3, 0x2, 
    0x2, 0x2, 0x49, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 
    0x2, 0x4a, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4d, 0x3, 0x2, 0x2, 0x2, 
    0x4c, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x8, 0x2, 0x2, 0x4e, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x52, 0x5, 0x8, 0x5, 0x2, 0x50, 0x52, 
    0x5, 0xa, 0x6, 0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x50, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0xf, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 0x9, 
    0x2, 0x2, 0x54, 0x58, 0x5, 0x8, 0x5, 0x2, 0x55, 0x56, 0x7, 0x9, 0x2, 
    0x2, 0x56, 0x58, 0x5, 0xa, 0x6, 0x2, 0x57, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x58, 0x11, 0x3, 0x2, 0x2, 0x2, 0x59, 
    0x5a, 0x7, 0x26, 0x2, 0x2, 0x5a, 0x66, 0x7, 0x2c, 0x2, 0x2, 0x5b, 0x5c, 
    0x7, 0x26, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x2c, 0x2, 0x2, 0x5d, 0x5e, 0x7, 
    0x5, 0x2, 0x2, 0x5e, 0x66, 0x7, 0x6, 0x2, 0x2, 0x5f, 0x60, 0x7, 0x26, 
    0x2, 0x2, 0x60, 0x61, 0x7, 0x2c, 0x2, 0x2, 0x61, 0x62, 0x7, 0x5, 0x2, 
    0x2, 0x62, 0x63, 0x7, 0x6, 0x2, 0x2, 0x63, 0x64, 0x7, 0x5, 0x2, 0x2, 
    0x64, 0x66, 0x7, 0x6, 0x2, 0x2, 0x65, 0x59, 0x3, 0x2, 0x2, 0x2, 0x65, 
    0x5b, 0x3, 0x2, 0x2, 0x2, 0x65, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x66, 0x13, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x7, 0xa, 0x2, 0x2, 0x68, 0x69, 0x9, 
    0x2, 0x2, 0x2, 0x69, 0x6a, 0x7, 0x2c, 0x2, 0x2, 0x6a, 0x6c, 0x7, 0xc, 
    0x2, 0x2, 0x6b, 0x6d, 0x5, 0x12, 0xa, 0x2, 0x6c, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x72, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x6f, 0x7, 0x9, 0x2, 0x2, 0x6f, 0x71, 0x5, 0x12, 0xa, 0x2, 0x70, 
    0x6e, 0x3, 0x2, 0x2, 0x2, 0x71, 0x74, 0x3, 0x2, 0x2, 0x2, 0x72, 0x70, 
    0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x3, 0x2, 0x2, 0x2, 0x73, 0x75, 0x3, 
    0x2, 0x2, 0x2, 0x74, 0x72, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x7, 0xd, 
    0x2, 0x2, 0x76, 0x77, 0x5, 0x6, 0x4, 0x2, 0x77, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x78, 0x79, 0x7, 0x2c, 0x2, 0x2, 0x79, 0x7b, 0x7, 0xc, 0x2, 0x2, 
    0x7a, 0x7c, 0x5, 0x18, 0xd, 0x2, 0x7b, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7b, 
    0x7c, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x81, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 
    0x7, 0x9, 0x2, 0x2, 0x7e, 0x80, 0x5, 0x18, 0xd, 0x2, 0x7f, 0x7d, 0x3, 
    0x2, 0x2, 0x2, 0x80, 0x83, 0x3, 0x2, 0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 
    0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 0x2, 0x2, 0x82, 0x84, 0x3, 0x2, 0x2, 
    0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x7, 0xd, 0x2, 0x2, 
    0x85, 0x17, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x8, 0xd, 0x1, 0x2, 0x87, 
    0x88, 0x7, 0xe, 0x2, 0x2, 0x88, 0x97, 0x5, 0x18, 0xd, 0x13, 0x89, 0x8a, 
    0x7, 0xf, 0x2, 0x2, 0x8a, 0x97, 0x5, 0x18, 0xd, 0x12, 0x8b, 0x97, 0x7, 
    0x27, 0x2, 0x2, 0x8c, 0x97, 0x7, 0x28, 0x2, 0x2, 0x8d, 0x97, 0x7, 0x2a, 
    0x2, 0x2, 0x8e, 0x97, 0x7, 0x29, 0x2, 0x2, 0x8f, 0x97, 0x7, 0x2b, 0x2, 
    0x2, 0x90, 0x91, 0x7, 0xc, 0x2, 0x2, 0x91, 0x92, 0x5, 0x18, 0xd, 0x2, 
    0x92, 0x93, 0x7, 0xd, 0x2, 0x2, 0x93, 0x97, 0x3, 0x2, 0x2, 0x2, 0x94, 
    0x97, 0x5, 0x8, 0x5, 0x2, 0x95, 0x97, 0x5, 0x16, 0xc, 0x2, 0x96, 0x86, 
    0x3, 0x2, 0x2, 0x2, 0x96, 0x89, 0x3, 0x2, 0x2, 0x2, 0x96, 0x8b, 0x3, 
    0x2, 0x2, 0x2, 0x96, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x96, 0x8d, 0x3, 0x2, 
    0x2, 0x2, 0x96, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x96, 0x8f, 0x3, 0x2, 0x2, 
    0x2, 0x96, 0x90, 0x3, 0x2, 0x2, 0x2, 0x96, 0x94, 0x3, 0x2, 0x2, 0x2, 
    0x96, 0x95, 0x3, 0x2, 0x2, 0x2, 0x97, 0xb2, 0x3, 0x2, 0x2, 0x2, 0x98, 
    0x99, 0xc, 0x11, 0x2, 0x2, 0x99, 0x9a, 0x9, 0x3, 0x2, 0x2, 0x9a, 0xb1, 
    0x5, 0x18, 0xd, 0x12, 0x9b, 0x9c, 0xc, 0x10, 0x2, 0x2, 0x9c, 0x9d, 0x9, 
    0x4, 0x2, 0x2, 0x9d, 0xb1, 0x5, 0x18, 0xd, 0x11, 0x9e, 0x9f, 0xc, 0xf, 
    0x2, 0x2, 0x9f, 0xa0, 0x9, 0x5, 0x2, 0x2, 0xa0, 0xb1, 0x5, 0x18, 0xd, 
    0x10, 0xa1, 0xa2, 0xc, 0xe, 0x2, 0x2, 0xa2, 0xa3, 0x9, 0x6, 0x2, 0x2, 
    0xa3, 0xb1, 0x5, 0x18, 0xd, 0xf, 0xa4, 0xa5, 0xc, 0xd, 0x2, 0x2, 0xa5, 
    0xa6, 0x7, 0x1a, 0x2, 0x2, 0xa6, 0xb1, 0x5, 0x18, 0xd, 0xe, 0xa7, 0xa8, 
    0xc, 0xc, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0x1b, 0x2, 0x2, 0xa9, 0xb1, 0x5, 
    0x18, 0xd, 0xd, 0xaa, 0xab, 0xc, 0xb, 0x2, 0x2, 0xab, 0xac, 0x7, 0x1c, 
    0x2, 0x2, 0xac, 0xad, 0x5, 0x18, 0xd, 0x2, 0xad, 0xae, 0x7, 0x1d, 0x2, 
    0x2, 0xae, 0xaf, 0x5, 0x18, 0xd, 0xc, 0xaf, 0xb1, 0x3, 0x2, 0x2, 0x2, 
    0xb0, 0x98, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x9b, 0x3, 0x2, 0x2, 0x2, 0xb0, 
    0x9e, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xa4, 
    0x3, 0x2, 0x2, 0x2, 0xb0, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xaa, 0x3, 
    0x2, 0x2, 0x2, 0xb1, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb0, 0x3, 0x2, 
    0x2, 0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0xb4, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xf9, 0x5, 0xc, 0x7, 0x2, 
    0xb6, 0xb7, 0x5, 0x8, 0x5, 0x2, 0xb7, 0xb8, 0x7, 0x7, 0x2, 0x2, 0xb8, 
    0xb9, 0x5, 0x18, 0xd, 0x2, 0xb9, 0xba, 0x7, 0x8, 0x2, 0x2, 0xba, 0xf9, 
    0x3, 0x2, 0x2, 0x2, 0xbb, 0xf9, 0x5, 0x6, 0x4, 0x2, 0xbc, 0xbd, 0x5, 
    0x16, 0xc, 0x2, 0xbd, 0xbe, 0x7, 0x8, 0x2, 0x2, 0xbe, 0xf9, 0x3, 0x2, 
    0x2, 0x2, 0xbf, 0xc1, 0x7, 0x1e, 0x2, 0x2, 0xc0, 0xc2, 0x5, 0x18, 0xd, 
    0x2, 0xc1, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x3, 0x2, 0x2, 0x2, 
    0xc2, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xf9, 0x7, 0x8, 0x2, 0x2, 0xc4, 
    0xc5, 0x7, 0x1f, 0x2, 0x2, 0xc5, 0xf9, 0x7, 0x8, 0x2, 0x2, 0xc6, 0xc7, 
    0x7, 0x20, 0x2, 0x2, 0xc7, 0xf9, 0x7, 0x8, 0x2, 0x2, 0xc8, 0xc9, 0x7, 
    0x21, 0x2, 0x2, 0xc9, 0xca, 0x7, 0xc, 0x2, 0x2, 0xca, 0xcb, 0x5, 0x18, 
    0xd, 0x2, 0xcb, 0xcc, 0x7, 0xd, 0x2, 0x2, 0xcc, 0xcd, 0x5, 0x6, 0x4, 
    0x2, 0xcd, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x7, 0x22, 0x2, 0x2, 
    0xcf, 0xd0, 0x7, 0xc, 0x2, 0x2, 0xd0, 0xd1, 0x5, 0x18, 0xd, 0x2, 0xd1, 
    0xd2, 0x7, 0xd, 0x2, 0x2, 0xd2, 0xdb, 0x5, 0x6, 0x4, 0x2, 0xd3, 0xd4, 
    0x7, 0x23, 0x2, 0x2, 0xd4, 0xd5, 0x7, 0xc, 0x2, 0x2, 0xd5, 0xd6, 0x5, 
    0x18, 0xd, 0x2, 0xd6, 0xd7, 0x7, 0xd, 0x2, 0x2, 0xd7, 0xd8, 0x5, 0x6, 
    0x4, 0x2, 0xd8, 0xda, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd3, 0x3, 0x2, 0x2, 
    0x2, 0xda, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 
    0xdb, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xdd, 
    0xdb, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x7, 0x24, 0x2, 0x2, 0xdf, 0xe1, 
    0x5, 0x6, 0x4, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x3, 
    0x2, 0x2, 0x2, 0xe1, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x7, 0x25, 
    0x2, 0x2, 0xe3, 0xea, 0x7, 0xc, 0x2, 0x2, 0xe4, 0xeb, 0x5, 0xc, 0x7, 
    0x2, 0xe5, 0xe6, 0x5, 0x8, 0x5, 0x2, 0xe6, 0xe7, 0x7, 0x7, 0x2, 0x2, 
    0xe7, 0xe8, 0x5, 0x18, 0xd, 0x2, 0xe8, 0xe9, 0x7, 0x8, 0x2, 0x2, 0xe9, 
    0xeb, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe5, 
    0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xed, 0x3, 
    0x2, 0x2, 0x2, 0xec, 0xee, 0x5, 0x18, 0xd, 0x2, 0xed, 0xec, 0x3, 0x2, 
    0x2, 0x2, 0xed, 0xee, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x3, 0x2, 0x2, 
    0x2, 0xef, 0xf4, 0x7, 0x8, 0x2, 0x2, 0xf0, 0xf1, 0x5, 0x8, 0x5, 0x2, 
    0xf1, 0xf2, 0x7, 0x7, 0x2, 0x2, 0xf2, 0xf3, 0x5, 0x18, 0xd, 0x2, 0xf3, 
    0xf5, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 
    0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x7, 
    0xd, 0x2, 0x2, 0xf7, 0xf9, 0x5, 0x6, 0x4, 0x2, 0xf8, 0xb5, 0x3, 0x2, 
    0x2, 0x2, 0xf8, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xbb, 0x3, 0x2, 0x2, 
    0x2, 0xf8, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xbf, 0x3, 0x2, 0x2, 0x2, 
    0xf8, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xf8, 
    0xc8, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xce, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xe2, 
    0x3, 0x2, 0x2, 0x2, 0xf9, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x18, 0x1f, 0x26, 
    0x2c, 0x3f, 0x4a, 0x51, 0x57, 0x65, 0x6c, 0x72, 0x7b, 0x81, 0x96, 0xb0, 
    0xb2, 0xc1, 0xdb, 0xe0, 0xea, 0xed, 0xf4, 0xf8, 
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
