
// Generated from language/lambda.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "lambdaListener.h"


/**
 * This class provides an empty implementation of lambdaListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  lambdaBaseListener : public lambdaListener {
public:

  virtual void enterProgram(lambdaParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(lambdaParser::ProgramContext * /*ctx*/) override { }

  virtual void enterStatement(lambdaParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(lambdaParser::StatementContext * /*ctx*/) override { }

  virtual void enterLet(lambdaParser::LetContext * /*ctx*/) override { }
  virtual void exitLet(lambdaParser::LetContext * /*ctx*/) override { }

  virtual void enterShow(lambdaParser::ShowContext * /*ctx*/) override { }
  virtual void exitShow(lambdaParser::ShowContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

