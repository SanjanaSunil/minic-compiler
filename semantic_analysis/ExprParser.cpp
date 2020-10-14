
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

std::vector<ExprParser::ExprContext *> ExprParser::ProgContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::ProgContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
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
    setState(5); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(4);
      expr(0);
      setState(7); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::T__0)
      | (1ULL << ExprParser::T__1)
      | (1ULL << ExprParser::T__2)
      | (1ULL << ExprParser::T__14)
      | (1ULL << ExprParser::INT)
      | (1ULL << ExprParser::FLOAT)
      | (1ULL << ExprParser::BOOL)
      | (1ULL << ExprParser::CHAR)
      | (1ULL << ExprParser::STRING))) != 0));
    setState(9);
    match(ExprParser::EOF);
   
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
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, ExprParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(25);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::T__0:
      case ExprParser::T__1: {
        _localctx = _tracker.createInstance<ExprUnaryContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(12);
        dynamic_cast<ExprUnaryContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == ExprParser::T__0

        || _la == ExprParser::T__1)) {
          dynamic_cast<ExprUnaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(13);
        expr(14);
        break;
      }

      case ExprParser::T__2: {
        _localctx = _tracker.createInstance<ExprNotContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(14);
        dynamic_cast<ExprNotContext *>(_localctx)->op = match(ExprParser::T__2);
        setState(15);
        expr(13);
        break;
      }

      case ExprParser::INT: {
        _localctx = _tracker.createInstance<ExprIntContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(16);
        match(ExprParser::INT);
        break;
      }

      case ExprParser::FLOAT: {
        _localctx = _tracker.createInstance<ExprFloatContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(17);
        match(ExprParser::FLOAT);
        break;
      }

      case ExprParser::CHAR: {
        _localctx = _tracker.createInstance<ExprCharContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(18);
        match(ExprParser::CHAR);
        break;
      }

      case ExprParser::BOOL: {
        _localctx = _tracker.createInstance<ExprBoolContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(19);
        match(ExprParser::BOOL);
        break;
      }

      case ExprParser::STRING: {
        _localctx = _tracker.createInstance<ExprStringContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(20);
        match(ExprParser::STRING);
        break;
      }

      case ExprParser::T__14: {
        _localctx = _tracker.createInstance<ExprParenthesisContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(21);
        match(ExprParser::T__14);
        setState(22);
        expr(0);
        setState(23);
        match(ExprParser::T__15);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(47);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(45);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprDivMulModContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(27);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(28);
          dynamic_cast<ExprDivMulModContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << ExprParser::T__3)
            | (1ULL << ExprParser::T__4)
            | (1ULL << ExprParser::T__5))) != 0))) {
            dynamic_cast<ExprDivMulModContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(29);
          expr(13);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprAddSubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(30);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(31);
          dynamic_cast<ExprAddSubContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ExprParser::T__0

          || _la == ExprParser::T__1)) {
            dynamic_cast<ExprAddSubContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(32);
          expr(12);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ExprCompContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(33);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(34);
          dynamic_cast<ExprCompContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << ExprParser::T__6)
            | (1ULL << ExprParser::T__7)
            | (1ULL << ExprParser::T__8)
            | (1ULL << ExprParser::T__9))) != 0))) {
            dynamic_cast<ExprCompContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(35);
          expr(11);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ExprEqContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(36);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(37);
          dynamic_cast<ExprEqContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ExprParser::T__10

          || _la == ExprParser::T__11)) {
            dynamic_cast<ExprEqContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(38);
          expr(10);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<ExprAndContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(39);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(40);
          dynamic_cast<ExprAndContext *>(_localctx)->op = match(ExprParser::T__12);
          setState(41);
          expr(9);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<ExprOrContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(42);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(43);
          dynamic_cast<ExprOrContext *>(_localctx)->op = match(ExprParser::T__13);
          setState(44);
          expr(8);
          break;
        }

        } 
      }
      setState(49);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
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
    case 1: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ExprParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 12);
    case 1: return precpred(_ctx, 11);
    case 2: return precpred(_ctx, 10);
    case 3: return precpred(_ctx, 9);
    case 4: return precpred(_ctx, 8);
    case 5: return precpred(_ctx, 7);

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
  "prog", "expr"
};

std::vector<std::string> ExprParser::_literalNames = {
  "", "'+'", "'-'", "'!'", "'/'", "'*'", "'%'", "'<'", "'<='", "'>'", "'>='", 
  "'=='", "'!='", "'&&'", "'||'", "'('", "')'"
};

std::vector<std::string> ExprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "TYPE", 
  "INT", "FLOAT", "BOOL", "CHAR", "STRING", "ID", "COMMENT", "NS"
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
    0x3, 0x1b, 0x35, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x3, 0x2, 0x6, 
    0x2, 0x8, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x9, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0x1c, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 
    0x30, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x33, 0xb, 0x3, 0x3, 0x3, 0x2, 0x3, 
    0x4, 0x4, 0x2, 0x4, 0x2, 0x6, 0x3, 0x2, 0x3, 0x4, 0x3, 0x2, 0x6, 0x8, 
    0x3, 0x2, 0x9, 0xc, 0x3, 0x2, 0xd, 0xe, 0x2, 0x40, 0x2, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x6, 0x8, 0x5, 0x4, 0x3, 0x2, 
    0x7, 0x6, 0x3, 0x2, 0x2, 0x2, 0x8, 0x9, 0x3, 0x2, 0x2, 0x2, 0x9, 0x7, 
    0x3, 0x2, 0x2, 0x2, 0x9, 0xa, 0x3, 0x2, 0x2, 0x2, 0xa, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0xb, 0xc, 0x7, 0x2, 0x2, 0x3, 0xc, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0xd, 0xe, 0x8, 0x3, 0x1, 0x2, 0xe, 0xf, 0x9, 0x2, 0x2, 0x2, 0xf, 0x1c, 
    0x5, 0x4, 0x3, 0x10, 0x10, 0x11, 0x7, 0x5, 0x2, 0x2, 0x11, 0x1c, 0x5, 
    0x4, 0x3, 0xf, 0x12, 0x1c, 0x7, 0x14, 0x2, 0x2, 0x13, 0x1c, 0x7, 0x15, 
    0x2, 0x2, 0x14, 0x1c, 0x7, 0x17, 0x2, 0x2, 0x15, 0x1c, 0x7, 0x16, 0x2, 
    0x2, 0x16, 0x1c, 0x7, 0x18, 0x2, 0x2, 0x17, 0x18, 0x7, 0x11, 0x2, 0x2, 
    0x18, 0x19, 0x5, 0x4, 0x3, 0x2, 0x19, 0x1a, 0x7, 0x12, 0x2, 0x2, 0x1a, 
    0x1c, 0x3, 0x2, 0x2, 0x2, 0x1b, 0xd, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x10, 
    0x3, 0x2, 0x2, 0x2, 0x1b, 0x12, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0x1b, 0x14, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0x1b, 0x16, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x31, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0xc, 0xe, 0x2, 0x2, 
    0x1e, 0x1f, 0x9, 0x3, 0x2, 0x2, 0x1f, 0x30, 0x5, 0x4, 0x3, 0xf, 0x20, 
    0x21, 0xc, 0xd, 0x2, 0x2, 0x21, 0x22, 0x9, 0x2, 0x2, 0x2, 0x22, 0x30, 
    0x5, 0x4, 0x3, 0xe, 0x23, 0x24, 0xc, 0xc, 0x2, 0x2, 0x24, 0x25, 0x9, 
    0x4, 0x2, 0x2, 0x25, 0x30, 0x5, 0x4, 0x3, 0xd, 0x26, 0x27, 0xc, 0xb, 
    0x2, 0x2, 0x27, 0x28, 0x9, 0x5, 0x2, 0x2, 0x28, 0x30, 0x5, 0x4, 0x3, 
    0xc, 0x29, 0x2a, 0xc, 0xa, 0x2, 0x2, 0x2a, 0x2b, 0x7, 0xf, 0x2, 0x2, 
    0x2b, 0x30, 0x5, 0x4, 0x3, 0xb, 0x2c, 0x2d, 0xc, 0x9, 0x2, 0x2, 0x2d, 
    0x2e, 0x7, 0x10, 0x2, 0x2, 0x2e, 0x30, 0x5, 0x4, 0x3, 0xa, 0x2f, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0x2f, 0x20, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0x2f, 0x26, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x29, 0x3, 0x2, 
    0x2, 0x2, 0x2f, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x30, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x31, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 0x2, 0x2, 
    0x32, 0x5, 0x3, 0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x6, 
    0x9, 0x1b, 0x2f, 0x31, 
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
