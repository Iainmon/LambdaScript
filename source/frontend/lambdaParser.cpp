
// Generated from lambda.g4 by ANTLR 4.8


#include "lambdaListener.h"
#include "lambdaVisitor.h"

#include "lambdaParser.h"


using namespace antlrcpp;
using namespace antlr4;

lambdaParser::lambdaParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

lambdaParser::~lambdaParser() {
  delete _interpreter;
}

std::string lambdaParser::getGrammarFileName() const {
  return "lambda.g4";
}

const std::vector<std::string>& lambdaParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& lambdaParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

lambdaParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lambdaParser::ExpressionContext* lambdaParser::ProgramContext::expression() {
  return getRuleContext<lambdaParser::ExpressionContext>(0);
}


size_t lambdaParser::ProgramContext::getRuleIndex() const {
  return lambdaParser::RuleProgram;
}

void lambdaParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void lambdaParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any lambdaParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lambdaVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

lambdaParser::ProgramContext* lambdaParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, lambdaParser::RuleProgram);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(10);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case lambdaParser::T__2:
      case lambdaParser::T__3:
      case lambdaParser::T__5:
      case lambdaParser::Lambda:
      case lambdaParser::Identifier:
      case lambdaParser::Operator:
      case lambdaParser::Bool:
      case lambdaParser::Int: {
        enterOuterAlt(_localctx, 1);
        setState(8);
        expression(0);
        break;
      }

      case lambdaParser::EOF: {
        enterOuterAlt(_localctx, 2);

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

//----------------- ExpressionContext ------------------------------------------------------------------

lambdaParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t lambdaParser::ExpressionContext::getRuleIndex() const {
  return lambdaParser::RuleExpression;
}

void lambdaParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BinaryExpressionContext ------------------------------------------------------------------

tree::TerminalNode* lambdaParser::BinaryExpressionContext::Operator() {
  return getToken(lambdaParser::Operator, 0);
}

std::vector<lambdaParser::ExpressionContext *> lambdaParser::BinaryExpressionContext::expression() {
  return getRuleContexts<lambdaParser::ExpressionContext>();
}

lambdaParser::ExpressionContext* lambdaParser::BinaryExpressionContext::expression(size_t i) {
  return getRuleContext<lambdaParser::ExpressionContext>(i);
}

lambdaParser::BinaryExpressionContext::BinaryExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void lambdaParser::BinaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryExpression(this);
}
void lambdaParser::BinaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryExpression(this);
}

antlrcpp::Any lambdaParser::BinaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lambdaVisitor*>(visitor))
    return parserVisitor->visitBinaryExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConditionalContext ------------------------------------------------------------------

lambdaParser::ConditionContext* lambdaParser::ConditionalContext::condition() {
  return getRuleContext<lambdaParser::ConditionContext>(0);
}

lambdaParser::ConditionalContext::ConditionalContext(ExpressionContext *ctx) { copyFrom(ctx); }

void lambdaParser::ConditionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditional(this);
}
void lambdaParser::ConditionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditional(this);
}

antlrcpp::Any lambdaParser::ConditionalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lambdaVisitor*>(visitor))
    return parserVisitor->visitConditional(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ApplicationContext ------------------------------------------------------------------

std::vector<lambdaParser::ExpressionContext *> lambdaParser::ApplicationContext::expression() {
  return getRuleContexts<lambdaParser::ExpressionContext>();
}

lambdaParser::ExpressionContext* lambdaParser::ApplicationContext::expression(size_t i) {
  return getRuleContext<lambdaParser::ExpressionContext>(i);
}

lambdaParser::ApplicationContext::ApplicationContext(ExpressionContext *ctx) { copyFrom(ctx); }

void lambdaParser::ApplicationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterApplication(this);
}
void lambdaParser::ApplicationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitApplication(this);
}

antlrcpp::Any lambdaParser::ApplicationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lambdaVisitor*>(visitor))
    return parserVisitor->visitApplication(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AbstractionContext ------------------------------------------------------------------

tree::TerminalNode* lambdaParser::AbstractionContext::Lambda() {
  return getToken(lambdaParser::Lambda, 0);
}

tree::TerminalNode* lambdaParser::AbstractionContext::Identifier() {
  return getToken(lambdaParser::Identifier, 0);
}

lambdaParser::ExpressionContext* lambdaParser::AbstractionContext::expression() {
  return getRuleContext<lambdaParser::ExpressionContext>(0);
}

lambdaParser::AbstractionContext::AbstractionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void lambdaParser::AbstractionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAbstraction(this);
}
void lambdaParser::AbstractionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAbstraction(this);
}

antlrcpp::Any lambdaParser::AbstractionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lambdaVisitor*>(visitor))
    return parserVisitor->visitAbstraction(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableContext ------------------------------------------------------------------

tree::TerminalNode* lambdaParser::VariableContext::Identifier() {
  return getToken(lambdaParser::Identifier, 0);
}

lambdaParser::VariableContext::VariableContext(ExpressionContext *ctx) { copyFrom(ctx); }

void lambdaParser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}
void lambdaParser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

antlrcpp::Any lambdaParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lambdaVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrintInstructionContext ------------------------------------------------------------------

lambdaParser::ExpressionContext* lambdaParser::PrintInstructionContext::expression() {
  return getRuleContext<lambdaParser::ExpressionContext>(0);
}

lambdaParser::PrintInstructionContext::PrintInstructionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void lambdaParser::PrintInstructionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrintInstruction(this);
}
void lambdaParser::PrintInstructionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrintInstruction(this);
}

antlrcpp::Any lambdaParser::PrintInstructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lambdaVisitor*>(visitor))
    return parserVisitor->visitPrintInstruction(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralContext ------------------------------------------------------------------

tree::TerminalNode* lambdaParser::LiteralContext::Int() {
  return getToken(lambdaParser::Int, 0);
}

tree::TerminalNode* lambdaParser::LiteralContext::Bool() {
  return getToken(lambdaParser::Bool, 0);
}

lambdaParser::LiteralContext::LiteralContext(ExpressionContext *ctx) { copyFrom(ctx); }

void lambdaParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}
void lambdaParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}

antlrcpp::Any lambdaParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lambdaVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignContext ------------------------------------------------------------------

tree::TerminalNode* lambdaParser::AssignContext::Identifier() {
  return getToken(lambdaParser::Identifier, 0);
}

lambdaParser::ExpressionContext* lambdaParser::AssignContext::expression() {
  return getRuleContext<lambdaParser::ExpressionContext>(0);
}

lambdaParser::AssignContext::AssignContext(ExpressionContext *ctx) { copyFrom(ctx); }

void lambdaParser::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}
void lambdaParser::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}

antlrcpp::Any lambdaParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lambdaVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BracketsContext ------------------------------------------------------------------

lambdaParser::ExpressionContext* lambdaParser::BracketsContext::expression() {
  return getRuleContext<lambdaParser::ExpressionContext>(0);
}

lambdaParser::BracketsContext::BracketsContext(ExpressionContext *ctx) { copyFrom(ctx); }

void lambdaParser::BracketsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBrackets(this);
}
void lambdaParser::BracketsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBrackets(this);
}

antlrcpp::Any lambdaParser::BracketsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lambdaVisitor*>(visitor))
    return parserVisitor->visitBrackets(this);
  else
    return visitor->visitChildren(this);
}

lambdaParser::ExpressionContext* lambdaParser::expression() {
   return expression(0);
}

lambdaParser::ExpressionContext* lambdaParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  lambdaParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  lambdaParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, lambdaParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(33);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<LiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(13);
      _la = _input->LA(1);
      if (!(_la == lambdaParser::Bool

      || _la == lambdaParser::Int)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<VariableContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(14);
      match(lambdaParser::Identifier);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<AbstractionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(15);
      match(lambdaParser::Lambda);
      setState(16);
      match(lambdaParser::Identifier);
      setState(17);
      match(lambdaParser::T__0);
      setState(18);
      expression(6);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<AssignContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(19);
      match(lambdaParser::Identifier);
      setState(20);
      match(lambdaParser::T__1);
      setState(21);
      expression(5);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ConditionalContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(22);
      condition();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<BinaryExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(23);
      match(lambdaParser::Operator);
      setState(24);
      expression(0);
      setState(25);
      expression(3);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<PrintInstructionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(27);
      match(lambdaParser::T__2);
      setState(28);
      expression(2);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<BracketsContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(29);
      match(lambdaParser::T__3);
      setState(30);
      expression(0);
      setState(31);
      match(lambdaParser::T__4);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(39);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<ApplicationContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleExpression);
        setState(35);

        if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
        setState(36);
        expression(8); 
      }
      setState(41);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BodyContext ------------------------------------------------------------------

lambdaParser::BodyContext::BodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lambdaParser::ExpressionContext* lambdaParser::BodyContext::expression() {
  return getRuleContext<lambdaParser::ExpressionContext>(0);
}


size_t lambdaParser::BodyContext::getRuleIndex() const {
  return lambdaParser::RuleBody;
}

void lambdaParser::BodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBody(this);
}

void lambdaParser::BodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBody(this);
}


antlrcpp::Any lambdaParser::BodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lambdaVisitor*>(visitor))
    return parserVisitor->visitBody(this);
  else
    return visitor->visitChildren(this);
}

lambdaParser::BodyContext* lambdaParser::body() {
  BodyContext *_localctx = _tracker.createInstance<BodyContext>(_ctx, getState());
  enterRule(_localctx, 4, lambdaParser::RuleBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(42);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionContext ------------------------------------------------------------------

lambdaParser::ConditionContext::ConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lambdaParser::ExpressionContext* lambdaParser::ConditionContext::expression() {
  return getRuleContext<lambdaParser::ExpressionContext>(0);
}

std::vector<lambdaParser::BodyContext *> lambdaParser::ConditionContext::body() {
  return getRuleContexts<lambdaParser::BodyContext>();
}

lambdaParser::BodyContext* lambdaParser::ConditionContext::body(size_t i) {
  return getRuleContext<lambdaParser::BodyContext>(i);
}


size_t lambdaParser::ConditionContext::getRuleIndex() const {
  return lambdaParser::RuleCondition;
}

void lambdaParser::ConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCondition(this);
}

void lambdaParser::ConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCondition(this);
}


antlrcpp::Any lambdaParser::ConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lambdaVisitor*>(visitor))
    return parserVisitor->visitCondition(this);
  else
    return visitor->visitChildren(this);
}

lambdaParser::ConditionContext* lambdaParser::condition() {
  ConditionContext *_localctx = _tracker.createInstance<ConditionContext>(_ctx, getState());
  enterRule(_localctx, 6, lambdaParser::RuleCondition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(58);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case lambdaParser::T__5: {
        enterOuterAlt(_localctx, 1);
        setState(44);
        match(lambdaParser::T__5);
        setState(45);
        expression(0);
        setState(46);
        match(lambdaParser::T__6);
        setState(47);
        body();
        setState(48);
        match(lambdaParser::T__7);
        setState(49);
        body();
        break;
      }

      case lambdaParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(51);
        match(lambdaParser::T__3);
        setState(52);
        expression(0);
        setState(53);
        match(lambdaParser::T__8);
        setState(54);
        body();
        setState(55);
        match(lambdaParser::T__9);
        setState(56);
        body();
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

bool lambdaParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool lambdaParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> lambdaParser::_decisionToDFA;
atn::PredictionContextCache lambdaParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN lambdaParser::_atn;
std::vector<uint16_t> lambdaParser::_serializedATN;

std::vector<std::string> lambdaParser::_ruleNames = {
  "program", "expression", "body", "condition"
};

std::vector<std::string> lambdaParser::_literalNames = {
  "", "'.'", "'='", "'print'", "'('", "')'", "'if'", "'then'", "'else'", 
  "'->'", "'|'"
};

std::vector<std::string> lambdaParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "Lambda", "Identifier", "Operator", 
  "Bool", "Int", "WS"
};

dfa::Vocabulary lambdaParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> lambdaParser::_tokenNames;

lambdaParser::Initializer::Initializer() {
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
    0x3, 0x12, 0x3f, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0xd, 0xa, 0x2, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0x24, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x28, 0xa, 0x3, 
    0xc, 0x3, 0xe, 0x3, 0x2b, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x3d, 
    0xa, 0x5, 0x3, 0x5, 0x2, 0x3, 0x4, 0x6, 0x2, 0x4, 0x6, 0x8, 0x2, 0x3, 
    0x3, 0x2, 0x10, 0x11, 0x2, 0x44, 0x2, 0xc, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0x6, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x8, 0x3c, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0xd, 0x5, 0x4, 0x3, 0x2, 0xb, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0xa, 0x3, 0x2, 0x2, 0x2, 0xc, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0xd, 0x3, 0x3, 0x2, 0x2, 0x2, 0xe, 0xf, 0x8, 0x3, 0x1, 0x2, 0xf, 0x24, 
    0x9, 0x2, 0x2, 0x2, 0x10, 0x24, 0x7, 0xe, 0x2, 0x2, 0x11, 0x12, 0x7, 
    0xd, 0x2, 0x2, 0x12, 0x13, 0x7, 0xe, 0x2, 0x2, 0x13, 0x14, 0x7, 0x3, 
    0x2, 0x2, 0x14, 0x24, 0x5, 0x4, 0x3, 0x8, 0x15, 0x16, 0x7, 0xe, 0x2, 
    0x2, 0x16, 0x17, 0x7, 0x4, 0x2, 0x2, 0x17, 0x24, 0x5, 0x4, 0x3, 0x7, 
    0x18, 0x24, 0x5, 0x8, 0x5, 0x2, 0x19, 0x1a, 0x7, 0xf, 0x2, 0x2, 0x1a, 
    0x1b, 0x5, 0x4, 0x3, 0x2, 0x1b, 0x1c, 0x5, 0x4, 0x3, 0x5, 0x1c, 0x24, 
    0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x7, 0x5, 0x2, 0x2, 0x1e, 0x24, 0x5, 
    0x4, 0x3, 0x4, 0x1f, 0x20, 0x7, 0x6, 0x2, 0x2, 0x20, 0x21, 0x5, 0x4, 
    0x3, 0x2, 0x21, 0x22, 0x7, 0x7, 0x2, 0x2, 0x22, 0x24, 0x3, 0x2, 0x2, 
    0x2, 0x23, 0xe, 0x3, 0x2, 0x2, 0x2, 0x23, 0x10, 0x3, 0x2, 0x2, 0x2, 
    0x23, 0x11, 0x3, 0x2, 0x2, 0x2, 0x23, 0x15, 0x3, 0x2, 0x2, 0x2, 0x23, 
    0x18, 0x3, 0x2, 0x2, 0x2, 0x23, 0x19, 0x3, 0x2, 0x2, 0x2, 0x23, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0x23, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x24, 0x29, 0x3, 
    0x2, 0x2, 0x2, 0x25, 0x26, 0xc, 0x9, 0x2, 0x2, 0x26, 0x28, 0x5, 0x4, 
    0x3, 0xa, 0x27, 0x25, 0x3, 0x2, 0x2, 0x2, 0x28, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0x29, 0x27, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2c, 
    0x2d, 0x5, 0x4, 0x3, 0x2, 0x2d, 0x7, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 
    0x7, 0x8, 0x2, 0x2, 0x2f, 0x30, 0x5, 0x4, 0x3, 0x2, 0x30, 0x31, 0x7, 
    0x9, 0x2, 0x2, 0x31, 0x32, 0x5, 0x6, 0x4, 0x2, 0x32, 0x33, 0x7, 0xa, 
    0x2, 0x2, 0x33, 0x34, 0x5, 0x6, 0x4, 0x2, 0x34, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x35, 0x36, 0x7, 0x6, 0x2, 0x2, 0x36, 0x37, 0x5, 0x4, 0x3, 0x2, 
    0x37, 0x38, 0x7, 0xb, 0x2, 0x2, 0x38, 0x39, 0x5, 0x6, 0x4, 0x2, 0x39, 
    0x3a, 0x7, 0xc, 0x2, 0x2, 0x3a, 0x3b, 0x5, 0x6, 0x4, 0x2, 0x3b, 0x3d, 
    0x3, 0x2, 0x2, 0x2, 0x3c, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x35, 0x3, 
    0x2, 0x2, 0x2, 0x3d, 0x9, 0x3, 0x2, 0x2, 0x2, 0x6, 0xc, 0x23, 0x29, 
    0x3c, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

lambdaParser::Initializer lambdaParser::_init;
