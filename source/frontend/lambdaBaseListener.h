
// Generated from lambda.g4 by ANTLR 4.8

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

  virtual void enterBinaryExpression(lambdaParser::BinaryExpressionContext * /*ctx*/) override { }
  virtual void exitBinaryExpression(lambdaParser::BinaryExpressionContext * /*ctx*/) override { }

  virtual void enterConditional(lambdaParser::ConditionalContext * /*ctx*/) override { }
  virtual void exitConditional(lambdaParser::ConditionalContext * /*ctx*/) override { }

  virtual void enterApplication(lambdaParser::ApplicationContext * /*ctx*/) override { }
  virtual void exitApplication(lambdaParser::ApplicationContext * /*ctx*/) override { }

  virtual void enterAbstraction(lambdaParser::AbstractionContext * /*ctx*/) override { }
  virtual void exitAbstraction(lambdaParser::AbstractionContext * /*ctx*/) override { }

  virtual void enterVariable(lambdaParser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(lambdaParser::VariableContext * /*ctx*/) override { }

  virtual void enterPrintInstruction(lambdaParser::PrintInstructionContext * /*ctx*/) override { }
  virtual void exitPrintInstruction(lambdaParser::PrintInstructionContext * /*ctx*/) override { }

  virtual void enterLiteral(lambdaParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(lambdaParser::LiteralContext * /*ctx*/) override { }

  virtual void enterAssign(lambdaParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(lambdaParser::AssignContext * /*ctx*/) override { }

  virtual void enterBrackets(lambdaParser::BracketsContext * /*ctx*/) override { }
  virtual void exitBrackets(lambdaParser::BracketsContext * /*ctx*/) override { }

  virtual void enterBody(lambdaParser::BodyContext * /*ctx*/) override { }
  virtual void exitBody(lambdaParser::BodyContext * /*ctx*/) override { }

  virtual void enterCondition(lambdaParser::ConditionContext * /*ctx*/) override { }
  virtual void exitCondition(lambdaParser::ConditionContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

