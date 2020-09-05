
// Generated from lambda.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "lambdaParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by lambdaParser.
 */
class  lambdaListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterInstructionLine(lambdaParser::InstructionLineContext *ctx) = 0;
  virtual void exitInstructionLine(lambdaParser::InstructionLineContext *ctx) = 0;

  virtual void enterBinaryExpression(lambdaParser::BinaryExpressionContext *ctx) = 0;
  virtual void exitBinaryExpression(lambdaParser::BinaryExpressionContext *ctx) = 0;

  virtual void enterImportInstruction(lambdaParser::ImportInstructionContext *ctx) = 0;
  virtual void exitImportInstruction(lambdaParser::ImportInstructionContext *ctx) = 0;

  virtual void enterConditional(lambdaParser::ConditionalContext *ctx) = 0;
  virtual void exitConditional(lambdaParser::ConditionalContext *ctx) = 0;

  virtual void enterApplication(lambdaParser::ApplicationContext *ctx) = 0;
  virtual void exitApplication(lambdaParser::ApplicationContext *ctx) = 0;

  virtual void enterAbstraction(lambdaParser::AbstractionContext *ctx) = 0;
  virtual void exitAbstraction(lambdaParser::AbstractionContext *ctx) = 0;

  virtual void enterVariable(lambdaParser::VariableContext *ctx) = 0;
  virtual void exitVariable(lambdaParser::VariableContext *ctx) = 0;

  virtual void enterPrintInstruction(lambdaParser::PrintInstructionContext *ctx) = 0;
  virtual void exitPrintInstruction(lambdaParser::PrintInstructionContext *ctx) = 0;

  virtual void enterLiteral(lambdaParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(lambdaParser::LiteralContext *ctx) = 0;

  virtual void enterAssign(lambdaParser::AssignContext *ctx) = 0;
  virtual void exitAssign(lambdaParser::AssignContext *ctx) = 0;

  virtual void enterBrackets(lambdaParser::BracketsContext *ctx) = 0;
  virtual void exitBrackets(lambdaParser::BracketsContext *ctx) = 0;

  virtual void enterBody(lambdaParser::BodyContext *ctx) = 0;
  virtual void exitBody(lambdaParser::BodyContext *ctx) = 0;

  virtual void enterCondition(lambdaParser::ConditionContext *ctx) = 0;
  virtual void exitCondition(lambdaParser::ConditionContext *ctx) = 0;

  virtual void enterTypeBinding(lambdaParser::TypeBindingContext *ctx) = 0;
  virtual void exitTypeBinding(lambdaParser::TypeBindingContext *ctx) = 0;

  virtual void enterLeafType(lambdaParser::LeafTypeContext *ctx) = 0;
  virtual void exitLeafType(lambdaParser::LeafTypeContext *ctx) = 0;

  virtual void enterNodeType(lambdaParser::NodeTypeContext *ctx) = 0;
  virtual void exitNodeType(lambdaParser::NodeTypeContext *ctx) = 0;

  virtual void enterTypeBrackets(lambdaParser::TypeBracketsContext *ctx) = 0;
  virtual void exitTypeBrackets(lambdaParser::TypeBracketsContext *ctx) = 0;


};

