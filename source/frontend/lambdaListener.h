
// Generated from language/lambda.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "lambdaParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by lambdaParser.
 */
class  lambdaListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(lambdaParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(lambdaParser::ProgramContext *ctx) = 0;

  virtual void enterStatement(lambdaParser::StatementContext *ctx) = 0;
  virtual void exitStatement(lambdaParser::StatementContext *ctx) = 0;

  virtual void enterLet(lambdaParser::LetContext *ctx) = 0;
  virtual void exitLet(lambdaParser::LetContext *ctx) = 0;

  virtual void enterShow(lambdaParser::ShowContext *ctx) = 0;
  virtual void exitShow(lambdaParser::ShowContext *ctx) = 0;


};

