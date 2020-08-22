
// Generated from language/lambda.g4 by ANTLR 4.8


#include "lambdaListener.h"

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

std::vector<lambdaParser::StatementContext *> lambdaParser::ProgramContext::statement() {
  return getRuleContexts<lambdaParser::StatementContext>();
}

lambdaParser::StatementContext* lambdaParser::ProgramContext::statement(size_t i) {
  return getRuleContext<lambdaParser::StatementContext>(i);
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

lambdaParser::ProgramContext* lambdaParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, lambdaParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(9); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(8);
      statement();
      setState(11); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == lambdaParser::T__1

    || _la == lambdaParser::VAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

lambdaParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lambdaParser::LetContext* lambdaParser::StatementContext::let() {
  return getRuleContext<lambdaParser::LetContext>(0);
}

lambdaParser::ShowContext* lambdaParser::StatementContext::show() {
  return getRuleContext<lambdaParser::ShowContext>(0);
}


size_t lambdaParser::StatementContext::getRuleIndex() const {
  return lambdaParser::RuleStatement;
}

void lambdaParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void lambdaParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

lambdaParser::StatementContext* lambdaParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, lambdaParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(15);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case lambdaParser::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(13);
        let();
        break;
      }

      case lambdaParser::T__1: {
        enterOuterAlt(_localctx, 2);
        setState(14);
        show();
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

//----------------- LetContext ------------------------------------------------------------------

lambdaParser::LetContext::LetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lambdaParser::LetContext::VAR() {
  return getToken(lambdaParser::VAR, 0);
}

tree::TerminalNode* lambdaParser::LetContext::INT() {
  return getToken(lambdaParser::INT, 0);
}


size_t lambdaParser::LetContext::getRuleIndex() const {
  return lambdaParser::RuleLet;
}

void lambdaParser::LetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLet(this);
}

void lambdaParser::LetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLet(this);
}

lambdaParser::LetContext* lambdaParser::let() {
  LetContext *_localctx = _tracker.createInstance<LetContext>(_ctx, getState());
  enterRule(_localctx, 4, lambdaParser::RuleLet);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(17);
    match(lambdaParser::VAR);
    setState(18);
    match(lambdaParser::T__0);
    setState(19);
    match(lambdaParser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShowContext ------------------------------------------------------------------

lambdaParser::ShowContext::ShowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lambdaParser::ShowContext::INT() {
  return getToken(lambdaParser::INT, 0);
}

tree::TerminalNode* lambdaParser::ShowContext::VAR() {
  return getToken(lambdaParser::VAR, 0);
}


size_t lambdaParser::ShowContext::getRuleIndex() const {
  return lambdaParser::RuleShow;
}

void lambdaParser::ShowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShow(this);
}

void lambdaParser::ShowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<lambdaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShow(this);
}

lambdaParser::ShowContext* lambdaParser::show() {
  ShowContext *_localctx = _tracker.createInstance<ShowContext>(_ctx, getState());
  enterRule(_localctx, 6, lambdaParser::RuleShow);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(21);
    match(lambdaParser::T__1);
    setState(22);
    _la = _input->LA(1);
    if (!(_la == lambdaParser::VAR

    || _la == lambdaParser::INT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> lambdaParser::_decisionToDFA;
atn::PredictionContextCache lambdaParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN lambdaParser::_atn;
std::vector<uint16_t> lambdaParser::_serializedATN;

std::vector<std::string> lambdaParser::_ruleNames = {
  "program", "statement", "let", "show"
};

std::vector<std::string> lambdaParser::_literalNames = {
  "", "'<-'", "'show'"
};

std::vector<std::string> lambdaParser::_symbolicNames = {
  "", "", "", "VAR", "INT", "WS"
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
    0x3, 0x7, 0x1b, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x3, 0x2, 0x6, 0x2, 0xc, 0xa, 0x2, 0xd, 0x2, 
    0xe, 0x2, 0xd, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x12, 0xa, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x2, 0x2, 0x6, 0x2, 0x4, 0x6, 0x8, 0x2, 0x3, 0x3, 0x2, 0x5, 0x6, 0x2, 
    0x18, 0x2, 0xb, 0x3, 0x2, 0x2, 0x2, 0x4, 0x11, 0x3, 0x2, 0x2, 0x2, 0x6, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0x8, 0x17, 0x3, 0x2, 0x2, 0x2, 0xa, 0xc, 0x5, 
    0x4, 0x3, 0x2, 0xb, 0xa, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0xd, 0xb, 0x3, 0x2, 0x2, 0x2, 0xd, 0xe, 0x3, 0x2, 0x2, 0x2, 0xe, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0xf, 0x12, 0x5, 0x6, 0x4, 0x2, 0x10, 0x12, 
    0x5, 0x8, 0x5, 0x2, 0x11, 0xf, 0x3, 0x2, 0x2, 0x2, 0x11, 0x10, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x5, 0x3, 0x2, 0x2, 0x2, 0x13, 0x14, 0x7, 0x5, 
    0x2, 0x2, 0x14, 0x15, 0x7, 0x3, 0x2, 0x2, 0x15, 0x16, 0x7, 0x6, 0x2, 
    0x2, 0x16, 0x7, 0x3, 0x2, 0x2, 0x2, 0x17, 0x18, 0x7, 0x4, 0x2, 0x2, 
    0x18, 0x19, 0x9, 0x2, 0x2, 0x2, 0x19, 0x9, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0xd, 0x11, 
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
