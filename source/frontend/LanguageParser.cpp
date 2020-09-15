
// Generated from Language.g4 by ANTLR 4.8


#include "LanguageListener.h"
#include "LanguageVisitor.h"

#include "LanguageParser.h"


using namespace antlrcpp;
using namespace antlr4;

LanguageParser::LanguageParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

LanguageParser::~LanguageParser() {
  delete _interpreter;
}

std::string LanguageParser::getGrammarFileName() const {
  return "Language.g4";
}

const std::vector<std::string>& LanguageParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& LanguageParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

LanguageParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LanguageParser::ProgramContext::getRuleIndex() const {
  return LanguageParser::RuleProgram;
}

void LanguageParser::ProgramContext::copyFrom(ProgramContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- InstructionLineContext ------------------------------------------------------------------

std::vector<LanguageParser::ExpressionContext *> LanguageParser::InstructionLineContext::expression() {
  return getRuleContexts<LanguageParser::ExpressionContext>();
}

LanguageParser::ExpressionContext* LanguageParser::InstructionLineContext::expression(size_t i) {
  return getRuleContext<LanguageParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> LanguageParser::InstructionLineContext::EOF() {
  return getTokens(LanguageParser::EOF);
}

tree::TerminalNode* LanguageParser::InstructionLineContext::EOF(size_t i) {
  return getToken(LanguageParser::EOF, i);
}

std::vector<tree::TerminalNode *> LanguageParser::InstructionLineContext::NL() {
  return getTokens(LanguageParser::NL);
}

tree::TerminalNode* LanguageParser::InstructionLineContext::NL(size_t i) {
  return getToken(LanguageParser::NL, i);
}

LanguageParser::InstructionLineContext::InstructionLineContext(ProgramContext *ctx) { copyFrom(ctx); }

void LanguageParser::InstructionLineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInstructionLine(this);
}
void LanguageParser::InstructionLineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInstructionLine(this);
}

antlrcpp::Any LanguageParser::InstructionLineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitInstructionLine(this);
  else
    return visitor->visitChildren(this);
}
LanguageParser::ProgramContext* LanguageParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, LanguageParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<ProgramContext *>(_tracker.createInstance<LanguageParser::InstructionLineContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(17);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LanguageParser::T__2)
      | (1ULL << LanguageParser::T__3)
      | (1ULL << LanguageParser::T__4)
      | (1ULL << LanguageParser::T__6)
      | (1ULL << LanguageParser::Lambda)
      | (1ULL << LanguageParser::Bool)
      | (1ULL << LanguageParser::Int)
      | (1ULL << LanguageParser::Identifier)
      | (1ULL << LanguageParser::Operator))) != 0)) {
      setState(12);
      expression(0);
      setState(13);
      _la = _input->LA(1);
      if (!(_la == LanguageParser::EOF

      || _la == LanguageParser::NL)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(19);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(21);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(20);
      match(LanguageParser::EOF);
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

//----------------- ExpressionContext ------------------------------------------------------------------

LanguageParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LanguageParser::ExpressionContext::getRuleIndex() const {
  return LanguageParser::RuleExpression;
}

void LanguageParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BinaryExpressionContext ------------------------------------------------------------------

tree::TerminalNode* LanguageParser::BinaryExpressionContext::Operator() {
  return getToken(LanguageParser::Operator, 0);
}

std::vector<LanguageParser::ExpressionContext *> LanguageParser::BinaryExpressionContext::expression() {
  return getRuleContexts<LanguageParser::ExpressionContext>();
}

LanguageParser::ExpressionContext* LanguageParser::BinaryExpressionContext::expression(size_t i) {
  return getRuleContext<LanguageParser::ExpressionContext>(i);
}

LanguageParser::BinaryExpressionContext::BinaryExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void LanguageParser::BinaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryExpression(this);
}
void LanguageParser::BinaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryExpression(this);
}

antlrcpp::Any LanguageParser::BinaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitBinaryExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ImportInstructionContext ------------------------------------------------------------------

tree::TerminalNode* LanguageParser::ImportInstructionContext::Identifier() {
  return getToken(LanguageParser::Identifier, 0);
}

LanguageParser::ImportInstructionContext::ImportInstructionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void LanguageParser::ImportInstructionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportInstruction(this);
}
void LanguageParser::ImportInstructionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportInstruction(this);
}

antlrcpp::Any LanguageParser::ImportInstructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitImportInstruction(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConditionalContext ------------------------------------------------------------------

LanguageParser::ConditionContext* LanguageParser::ConditionalContext::condition() {
  return getRuleContext<LanguageParser::ConditionContext>(0);
}

LanguageParser::ConditionalContext::ConditionalContext(ExpressionContext *ctx) { copyFrom(ctx); }

void LanguageParser::ConditionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditional(this);
}
void LanguageParser::ConditionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditional(this);
}

antlrcpp::Any LanguageParser::ConditionalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitConditional(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ApplicationContext ------------------------------------------------------------------

std::vector<LanguageParser::ExpressionContext *> LanguageParser::ApplicationContext::expression() {
  return getRuleContexts<LanguageParser::ExpressionContext>();
}

LanguageParser::ExpressionContext* LanguageParser::ApplicationContext::expression(size_t i) {
  return getRuleContext<LanguageParser::ExpressionContext>(i);
}

LanguageParser::ApplicationContext::ApplicationContext(ExpressionContext *ctx) { copyFrom(ctx); }

void LanguageParser::ApplicationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterApplication(this);
}
void LanguageParser::ApplicationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitApplication(this);
}

antlrcpp::Any LanguageParser::ApplicationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitApplication(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AbstractionContext ------------------------------------------------------------------

tree::TerminalNode* LanguageParser::AbstractionContext::Lambda() {
  return getToken(LanguageParser::Lambda, 0);
}

tree::TerminalNode* LanguageParser::AbstractionContext::Identifier() {
  return getToken(LanguageParser::Identifier, 0);
}

LanguageParser::ExpressionContext* LanguageParser::AbstractionContext::expression() {
  return getRuleContext<LanguageParser::ExpressionContext>(0);
}

LanguageParser::TypeBindingContext* LanguageParser::AbstractionContext::typeBinding() {
  return getRuleContext<LanguageParser::TypeBindingContext>(0);
}

LanguageParser::AbstractionContext::AbstractionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void LanguageParser::AbstractionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAbstraction(this);
}
void LanguageParser::AbstractionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAbstraction(this);
}

antlrcpp::Any LanguageParser::AbstractionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitAbstraction(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableContext ------------------------------------------------------------------

tree::TerminalNode* LanguageParser::VariableContext::Identifier() {
  return getToken(LanguageParser::Identifier, 0);
}

LanguageParser::TypeBindingContext* LanguageParser::VariableContext::typeBinding() {
  return getRuleContext<LanguageParser::TypeBindingContext>(0);
}

LanguageParser::VariableContext::VariableContext(ExpressionContext *ctx) { copyFrom(ctx); }

void LanguageParser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}
void LanguageParser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

antlrcpp::Any LanguageParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrintInstructionContext ------------------------------------------------------------------

LanguageParser::ExpressionContext* LanguageParser::PrintInstructionContext::expression() {
  return getRuleContext<LanguageParser::ExpressionContext>(0);
}

LanguageParser::PrintInstructionContext::PrintInstructionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void LanguageParser::PrintInstructionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrintInstruction(this);
}
void LanguageParser::PrintInstructionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrintInstruction(this);
}

antlrcpp::Any LanguageParser::PrintInstructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitPrintInstruction(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiteralContext ------------------------------------------------------------------

tree::TerminalNode* LanguageParser::LiteralContext::Int() {
  return getToken(LanguageParser::Int, 0);
}

tree::TerminalNode* LanguageParser::LiteralContext::Bool() {
  return getToken(LanguageParser::Bool, 0);
}

LanguageParser::LiteralContext::LiteralContext(ExpressionContext *ctx) { copyFrom(ctx); }

void LanguageParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}
void LanguageParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}

antlrcpp::Any LanguageParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignContext ------------------------------------------------------------------

tree::TerminalNode* LanguageParser::AssignContext::Identifier() {
  return getToken(LanguageParser::Identifier, 0);
}

LanguageParser::ExpressionContext* LanguageParser::AssignContext::expression() {
  return getRuleContext<LanguageParser::ExpressionContext>(0);
}

LanguageParser::TypeBindingContext* LanguageParser::AssignContext::typeBinding() {
  return getRuleContext<LanguageParser::TypeBindingContext>(0);
}

LanguageParser::AssignContext::AssignContext(ExpressionContext *ctx) { copyFrom(ctx); }

void LanguageParser::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}
void LanguageParser::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}

antlrcpp::Any LanguageParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BracketsContext ------------------------------------------------------------------

LanguageParser::ExpressionContext* LanguageParser::BracketsContext::expression() {
  return getRuleContext<LanguageParser::ExpressionContext>(0);
}

LanguageParser::BracketsContext::BracketsContext(ExpressionContext *ctx) { copyFrom(ctx); }

void LanguageParser::BracketsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBrackets(this);
}
void LanguageParser::BracketsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBrackets(this);
}

antlrcpp::Any LanguageParser::BracketsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitBrackets(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::ExpressionContext* LanguageParser::expression() {
   return expression(0);
}

LanguageParser::ExpressionContext* LanguageParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  LanguageParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  LanguageParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, LanguageParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(55);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<LiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(24);
      _la = _input->LA(1);
      if (!(_la == LanguageParser::Bool

      || _la == LanguageParser::Int)) {
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
      setState(25);
      match(LanguageParser::Identifier);
      setState(27);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
      case 1: {
        setState(26);
        typeBinding();
        break;
      }

      }
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<AbstractionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(29);
      match(LanguageParser::Lambda);
      setState(30);
      match(LanguageParser::Identifier);
      setState(32);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LanguageParser::T__11) {
        setState(31);
        typeBinding();
      }
      setState(34);
      match(LanguageParser::T__0);
      setState(35);
      expression(7);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<AssignContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(36);
      match(LanguageParser::Identifier);
      setState(38);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == LanguageParser::T__11) {
        setState(37);
        typeBinding();
      }
      setState(40);
      match(LanguageParser::T__1);
      setState(41);
      expression(6);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ConditionalContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(42);
      condition();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<BinaryExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(43);
      match(LanguageParser::Operator);
      setState(44);
      expression(0);
      setState(45);
      expression(4);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<PrintInstructionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(47);
      match(LanguageParser::T__2);
      setState(48);
      expression(3);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ImportInstructionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(49);
      match(LanguageParser::T__3);
      setState(50);
      match(LanguageParser::Identifier);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<BracketsContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(51);
      match(LanguageParser::T__4);
      setState(52);
      expression(0);
      setState(53);
      match(LanguageParser::T__5);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(61);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<ApplicationContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleExpression);
        setState(57);

        if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
        setState(58);
        expression(9); 
      }
      setState(63);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
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

LanguageParser::BodyContext::BodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LanguageParser::ExpressionContext* LanguageParser::BodyContext::expression() {
  return getRuleContext<LanguageParser::ExpressionContext>(0);
}


size_t LanguageParser::BodyContext::getRuleIndex() const {
  return LanguageParser::RuleBody;
}

void LanguageParser::BodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBody(this);
}

void LanguageParser::BodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBody(this);
}


antlrcpp::Any LanguageParser::BodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitBody(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::BodyContext* LanguageParser::body() {
  BodyContext *_localctx = _tracker.createInstance<BodyContext>(_ctx, getState());
  enterRule(_localctx, 4, LanguageParser::RuleBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
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

LanguageParser::ConditionContext::ConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LanguageParser::ExpressionContext* LanguageParser::ConditionContext::expression() {
  return getRuleContext<LanguageParser::ExpressionContext>(0);
}

std::vector<LanguageParser::BodyContext *> LanguageParser::ConditionContext::body() {
  return getRuleContexts<LanguageParser::BodyContext>();
}

LanguageParser::BodyContext* LanguageParser::ConditionContext::body(size_t i) {
  return getRuleContext<LanguageParser::BodyContext>(i);
}


size_t LanguageParser::ConditionContext::getRuleIndex() const {
  return LanguageParser::RuleCondition;
}

void LanguageParser::ConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCondition(this);
}

void LanguageParser::ConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCondition(this);
}


antlrcpp::Any LanguageParser::ConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitCondition(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::ConditionContext* LanguageParser::condition() {
  ConditionContext *_localctx = _tracker.createInstance<ConditionContext>(_ctx, getState());
  enterRule(_localctx, 6, LanguageParser::RuleCondition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(81);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LanguageParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(66);
        match(LanguageParser::T__6);
        setState(67);
        expression(0);
        setState(68);
        match(LanguageParser::T__7);
        setState(69);
        body();
        setState(70);
        match(LanguageParser::T__8);
        setState(71);
        body();
        break;
      }

      case LanguageParser::T__4: {
        enterOuterAlt(_localctx, 2);
        setState(73);
        match(LanguageParser::T__4);
        setState(74);
        expression(0);
        setState(75);
        match(LanguageParser::T__9);
        setState(76);
        body();
        setState(77);
        match(LanguageParser::T__10);
        setState(78);
        body();
        setState(79);
        match(LanguageParser::T__5);
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

//----------------- TypeBindingContext ------------------------------------------------------------------

LanguageParser::TypeBindingContext::TypeBindingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LanguageParser::TypeContext* LanguageParser::TypeBindingContext::type() {
  return getRuleContext<LanguageParser::TypeContext>(0);
}


size_t LanguageParser::TypeBindingContext::getRuleIndex() const {
  return LanguageParser::RuleTypeBinding;
}

void LanguageParser::TypeBindingContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeBinding(this);
}

void LanguageParser::TypeBindingContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeBinding(this);
}


antlrcpp::Any LanguageParser::TypeBindingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitTypeBinding(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::TypeBindingContext* LanguageParser::typeBinding() {
  TypeBindingContext *_localctx = _tracker.createInstance<TypeBindingContext>(_ctx, getState());
  enterRule(_localctx, 8, LanguageParser::RuleTypeBinding);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    match(LanguageParser::T__11);
    setState(84);
    type(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

LanguageParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t LanguageParser::TypeContext::getRuleIndex() const {
  return LanguageParser::RuleType;
}

void LanguageParser::TypeContext::copyFrom(TypeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LeafTypeContext ------------------------------------------------------------------

tree::TerminalNode* LanguageParser::LeafTypeContext::TypeIdentifier() {
  return getToken(LanguageParser::TypeIdentifier, 0);
}

LanguageParser::LeafTypeContext::LeafTypeContext(TypeContext *ctx) { copyFrom(ctx); }

void LanguageParser::LeafTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLeafType(this);
}
void LanguageParser::LeafTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLeafType(this);
}

antlrcpp::Any LanguageParser::LeafTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitLeafType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NodeTypeContext ------------------------------------------------------------------

std::vector<LanguageParser::TypeContext *> LanguageParser::NodeTypeContext::type() {
  return getRuleContexts<LanguageParser::TypeContext>();
}

LanguageParser::TypeContext* LanguageParser::NodeTypeContext::type(size_t i) {
  return getRuleContext<LanguageParser::TypeContext>(i);
}

LanguageParser::NodeTypeContext::NodeTypeContext(TypeContext *ctx) { copyFrom(ctx); }

void LanguageParser::NodeTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNodeType(this);
}
void LanguageParser::NodeTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNodeType(this);
}

antlrcpp::Any LanguageParser::NodeTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitNodeType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeBracketsContext ------------------------------------------------------------------

LanguageParser::TypeContext* LanguageParser::TypeBracketsContext::type() {
  return getRuleContext<LanguageParser::TypeContext>(0);
}

LanguageParser::TypeBracketsContext::TypeBracketsContext(TypeContext *ctx) { copyFrom(ctx); }

void LanguageParser::TypeBracketsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeBrackets(this);
}
void LanguageParser::TypeBracketsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LanguageListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeBrackets(this);
}

antlrcpp::Any LanguageParser::TypeBracketsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LanguageVisitor*>(visitor))
    return parserVisitor->visitTypeBrackets(this);
  else
    return visitor->visitChildren(this);
}

LanguageParser::TypeContext* LanguageParser::type() {
   return type(0);
}

LanguageParser::TypeContext* LanguageParser::type(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  LanguageParser::TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, parentState);
  LanguageParser::TypeContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, LanguageParser::RuleType, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(92);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LanguageParser::TypeIdentifier: {
        _localctx = _tracker.createInstance<LeafTypeContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(87);
        match(LanguageParser::TypeIdentifier);
        break;
      }

      case LanguageParser::T__4: {
        _localctx = _tracker.createInstance<TypeBracketsContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(88);
        match(LanguageParser::T__4);
        setState(89);
        type(0);
        setState(90);
        match(LanguageParser::T__5);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(99);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<NodeTypeContext>(_tracker.createInstance<TypeContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleType);
        setState(94);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(95);
        match(LanguageParser::T__9);
        setState(96);
        type(3); 
      }
      setState(101);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool LanguageParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);
    case 5: return typeSempred(dynamic_cast<TypeContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool LanguageParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 8);

  default:
    break;
  }
  return true;
}

bool LanguageParser::typeSempred(TypeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> LanguageParser::_decisionToDFA;
atn::PredictionContextCache LanguageParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN LanguageParser::_atn;
std::vector<uint16_t> LanguageParser::_serializedATN;

std::vector<std::string> LanguageParser::_ruleNames = {
  "program", "expression", "body", "condition", "typeBinding", "type"
};

std::vector<std::string> LanguageParser::_literalNames = {
  "", "'.'", "'='", "'print'", "'import'", "'('", "')'", "'if'", "'then'", 
  "'else'", "'->'", "'|'", "':'"
};

std::vector<std::string> LanguageParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "Lambda", "Bool", 
  "Int", "Identifier", "TypeIdentifier", "Operator", "WS", "NL"
};

dfa::Vocabulary LanguageParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> LanguageParser::_tokenNames;

LanguageParser::Initializer::Initializer() {
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
    0x3, 0x16, 0x69, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x12, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
    0x15, 0xb, 0x2, 0x3, 0x2, 0x5, 0x2, 0x18, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x1e, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x23, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0x29, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x3a, 0xa, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x7, 0x3, 0x3e, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x41, 0xb, 0x3, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x54, 0xa, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x5, 0x7, 0x5f, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 
    0x64, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x67, 0xb, 0x7, 0x3, 0x7, 0x2, 0x4, 
    0x4, 0xc, 0x8, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0x2, 0x4, 0x3, 0x3, 0x16, 
    0x16, 0x3, 0x2, 0x10, 0x11, 0x2, 0x73, 0x2, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x39, 0x3, 0x2, 0x2, 0x2, 0x6, 0x42, 0x3, 0x2, 0x2, 0x2, 0x8, 0x53, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x55, 0x3, 0x2, 0x2, 0x2, 0xc, 0x5e, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0xf, 0x5, 0x4, 0x3, 0x2, 0xf, 0x10, 0x9, 0x2, 0x2, 0x2, 
    0x10, 0x12, 0x3, 0x2, 0x2, 0x2, 0x11, 0xe, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x13, 0x11, 0x3, 0x2, 0x2, 0x2, 0x13, 0x14, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x17, 0x3, 0x2, 0x2, 0x2, 0x15, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0x18, 0x7, 0x2, 0x2, 0x3, 0x17, 0x16, 0x3, 0x2, 
    0x2, 0x2, 0x17, 0x18, 0x3, 0x2, 0x2, 0x2, 0x18, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x19, 0x1a, 0x8, 0x3, 0x1, 0x2, 0x1a, 0x3a, 0x9, 0x3, 0x2, 0x2, 
    0x1b, 0x1d, 0x7, 0x12, 0x2, 0x2, 0x1c, 0x1e, 0x5, 0xa, 0x6, 0x2, 0x1d, 
    0x1c, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x3a, 
    0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0x7, 0xf, 0x2, 0x2, 0x20, 0x22, 0x7, 
    0x12, 0x2, 0x2, 0x21, 0x23, 0x5, 0xa, 0x6, 0x2, 0x22, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0x23, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0x25, 0x7, 0x3, 0x2, 0x2, 0x25, 0x3a, 0x5, 0x4, 0x3, 0x9, 
    0x26, 0x28, 0x7, 0x12, 0x2, 0x2, 0x27, 0x29, 0x5, 0xa, 0x6, 0x2, 0x28, 
    0x27, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x7, 0x4, 0x2, 0x2, 0x2b, 0x3a, 0x5, 
    0x4, 0x3, 0x8, 0x2c, 0x3a, 0x5, 0x8, 0x5, 0x2, 0x2d, 0x2e, 0x7, 0x14, 
    0x2, 0x2, 0x2e, 0x2f, 0x5, 0x4, 0x3, 0x2, 0x2f, 0x30, 0x5, 0x4, 0x3, 
    0x6, 0x30, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x7, 0x5, 0x2, 0x2, 
    0x32, 0x3a, 0x5, 0x4, 0x3, 0x5, 0x33, 0x34, 0x7, 0x6, 0x2, 0x2, 0x34, 
    0x3a, 0x7, 0x12, 0x2, 0x2, 0x35, 0x36, 0x7, 0x7, 0x2, 0x2, 0x36, 0x37, 
    0x5, 0x4, 0x3, 0x2, 0x37, 0x38, 0x7, 0x8, 0x2, 0x2, 0x38, 0x3a, 0x3, 
    0x2, 0x2, 0x2, 0x39, 0x19, 0x3, 0x2, 0x2, 0x2, 0x39, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0x39, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x39, 0x26, 0x3, 0x2, 0x2, 
    0x2, 0x39, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x39, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0x39, 0x31, 0x3, 0x2, 0x2, 0x2, 0x39, 0x33, 0x3, 0x2, 0x2, 0x2, 0x39, 
    0x35, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 
    0xc, 0xa, 0x2, 0x2, 0x3c, 0x3e, 0x5, 0x4, 0x3, 0xb, 0x3d, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x41, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x3d, 0x3, 0x2, 
    0x2, 0x2, 0x3f, 0x40, 0x3, 0x2, 0x2, 0x2, 0x40, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x5, 0x4, 0x3, 0x2, 
    0x43, 0x7, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 0x9, 0x2, 0x2, 0x45, 
    0x46, 0x5, 0x4, 0x3, 0x2, 0x46, 0x47, 0x7, 0xa, 0x2, 0x2, 0x47, 0x48, 
    0x5, 0x6, 0x4, 0x2, 0x48, 0x49, 0x7, 0xb, 0x2, 0x2, 0x49, 0x4a, 0x5, 
    0x6, 0x4, 0x2, 0x4a, 0x54, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0x7, 
    0x2, 0x2, 0x4c, 0x4d, 0x5, 0x4, 0x3, 0x2, 0x4d, 0x4e, 0x7, 0xc, 0x2, 
    0x2, 0x4e, 0x4f, 0x5, 0x6, 0x4, 0x2, 0x4f, 0x50, 0x7, 0xd, 0x2, 0x2, 
    0x50, 0x51, 0x5, 0x6, 0x4, 0x2, 0x51, 0x52, 0x7, 0x8, 0x2, 0x2, 0x52, 
    0x54, 0x3, 0x2, 0x2, 0x2, 0x53, 0x44, 0x3, 0x2, 0x2, 0x2, 0x53, 0x4b, 
    0x3, 0x2, 0x2, 0x2, 0x54, 0x9, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x7, 
    0xe, 0x2, 0x2, 0x56, 0x57, 0x5, 0xc, 0x7, 0x2, 0x57, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x58, 0x59, 0x8, 0x7, 0x1, 0x2, 0x59, 0x5f, 0x7, 0x13, 0x2, 
    0x2, 0x5a, 0x5b, 0x7, 0x7, 0x2, 0x2, 0x5b, 0x5c, 0x5, 0xc, 0x7, 0x2, 
    0x5c, 0x5d, 0x7, 0x8, 0x2, 0x2, 0x5d, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5e, 
    0x58, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x65, 
    0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0xc, 0x4, 0x2, 0x2, 0x61, 0x62, 0x7, 
    0xc, 0x2, 0x2, 0x62, 0x64, 0x5, 0xc, 0x7, 0x5, 0x63, 0x60, 0x3, 0x2, 
    0x2, 0x2, 0x64, 0x67, 0x3, 0x2, 0x2, 0x2, 0x65, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x65, 0x66, 0x3, 0x2, 0x2, 0x2, 0x66, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0xc, 0x13, 0x17, 0x1d, 0x22, 0x28, 0x39, 
    0x3f, 0x53, 0x5e, 0x65, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

LanguageParser::Initializer LanguageParser::_init;
