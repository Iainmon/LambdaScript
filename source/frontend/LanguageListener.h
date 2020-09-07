
// Generated from Language.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "LanguageParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by LanguageParser.
 */
class  LanguageListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterInstructionLine(LanguageParser::InstructionLineContext *ctx) = 0;
  virtual void exitInstructionLine(LanguageParser::InstructionLineContext *ctx) = 0;

  virtual void enterBinaryExpression(LanguageParser::BinaryExpressionContext *ctx) = 0;
  virtual void exitBinaryExpression(LanguageParser::BinaryExpressionContext *ctx) = 0;

  virtual void enterImportInstruction(LanguageParser::ImportInstructionContext *ctx) = 0;
  virtual void exitImportInstruction(LanguageParser::ImportInstructionContext *ctx) = 0;

  virtual void enterConditional(LanguageParser::ConditionalContext *ctx) = 0;
  virtual void exitConditional(LanguageParser::ConditionalContext *ctx) = 0;

  virtual void enterApplication(LanguageParser::ApplicationContext *ctx) = 0;
  virtual void exitApplication(LanguageParser::ApplicationContext *ctx) = 0;

  virtual void enterAbstraction(LanguageParser::AbstractionContext *ctx) = 0;
  virtual void exitAbstraction(LanguageParser::AbstractionContext *ctx) = 0;

  virtual void enterVariable(LanguageParser::VariableContext *ctx) = 0;
  virtual void exitVariable(LanguageParser::VariableContext *ctx) = 0;

  virtual void enterPrintInstruction(LanguageParser::PrintInstructionContext *ctx) = 0;
  virtual void exitPrintInstruction(LanguageParser::PrintInstructionContext *ctx) = 0;

  virtual void enterLiteral(LanguageParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(LanguageParser::LiteralContext *ctx) = 0;

  virtual void enterAssign(LanguageParser::AssignContext *ctx) = 0;
  virtual void exitAssign(LanguageParser::AssignContext *ctx) = 0;

  virtual void enterBrackets(LanguageParser::BracketsContext *ctx) = 0;
  virtual void exitBrackets(LanguageParser::BracketsContext *ctx) = 0;

  virtual void enterBody(LanguageParser::BodyContext *ctx) = 0;
  virtual void exitBody(LanguageParser::BodyContext *ctx) = 0;

  virtual void enterCondition(LanguageParser::ConditionContext *ctx) = 0;
  virtual void exitCondition(LanguageParser::ConditionContext *ctx) = 0;

  virtual void enterTypeBinding(LanguageParser::TypeBindingContext *ctx) = 0;
  virtual void exitTypeBinding(LanguageParser::TypeBindingContext *ctx) = 0;

  virtual void enterLeafType(LanguageParser::LeafTypeContext *ctx) = 0;
  virtual void exitLeafType(LanguageParser::LeafTypeContext *ctx) = 0;

  virtual void enterNodeType(LanguageParser::NodeTypeContext *ctx) = 0;
  virtual void exitNodeType(LanguageParser::NodeTypeContext *ctx) = 0;

  virtual void enterTypeBrackets(LanguageParser::TypeBracketsContext *ctx) = 0;
  virtual void exitTypeBrackets(LanguageParser::TypeBracketsContext *ctx) = 0;


};

