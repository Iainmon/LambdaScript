
// Generated from Language.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "LanguageListener.h"


/**
 * This class provides an empty implementation of LanguageListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  LanguageBaseListener : public LanguageListener {
public:

  virtual void enterInstructionLine(LanguageParser::InstructionLineContext * /*ctx*/) override { }
  virtual void exitInstructionLine(LanguageParser::InstructionLineContext * /*ctx*/) override { }

  virtual void enterBinaryExpression(LanguageParser::BinaryExpressionContext * /*ctx*/) override { }
  virtual void exitBinaryExpression(LanguageParser::BinaryExpressionContext * /*ctx*/) override { }

  virtual void enterImportInstruction(LanguageParser::ImportInstructionContext * /*ctx*/) override { }
  virtual void exitImportInstruction(LanguageParser::ImportInstructionContext * /*ctx*/) override { }

  virtual void enterConditional(LanguageParser::ConditionalContext * /*ctx*/) override { }
  virtual void exitConditional(LanguageParser::ConditionalContext * /*ctx*/) override { }

  virtual void enterApplication(LanguageParser::ApplicationContext * /*ctx*/) override { }
  virtual void exitApplication(LanguageParser::ApplicationContext * /*ctx*/) override { }

  virtual void enterAbstraction(LanguageParser::AbstractionContext * /*ctx*/) override { }
  virtual void exitAbstraction(LanguageParser::AbstractionContext * /*ctx*/) override { }

  virtual void enterVariable(LanguageParser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(LanguageParser::VariableContext * /*ctx*/) override { }

  virtual void enterPrintInstruction(LanguageParser::PrintInstructionContext * /*ctx*/) override { }
  virtual void exitPrintInstruction(LanguageParser::PrintInstructionContext * /*ctx*/) override { }

  virtual void enterLiteral(LanguageParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(LanguageParser::LiteralContext * /*ctx*/) override { }

  virtual void enterAssign(LanguageParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(LanguageParser::AssignContext * /*ctx*/) override { }

  virtual void enterBrackets(LanguageParser::BracketsContext * /*ctx*/) override { }
  virtual void exitBrackets(LanguageParser::BracketsContext * /*ctx*/) override { }

  virtual void enterBody(LanguageParser::BodyContext * /*ctx*/) override { }
  virtual void exitBody(LanguageParser::BodyContext * /*ctx*/) override { }

  virtual void enterCondition(LanguageParser::ConditionContext * /*ctx*/) override { }
  virtual void exitCondition(LanguageParser::ConditionContext * /*ctx*/) override { }

  virtual void enterTypeBinding(LanguageParser::TypeBindingContext * /*ctx*/) override { }
  virtual void exitTypeBinding(LanguageParser::TypeBindingContext * /*ctx*/) override { }

  virtual void enterLeafType(LanguageParser::LeafTypeContext * /*ctx*/) override { }
  virtual void exitLeafType(LanguageParser::LeafTypeContext * /*ctx*/) override { }

  virtual void enterNodeType(LanguageParser::NodeTypeContext * /*ctx*/) override { }
  virtual void exitNodeType(LanguageParser::NodeTypeContext * /*ctx*/) override { }

  virtual void enterTypeBrackets(LanguageParser::TypeBracketsContext * /*ctx*/) override { }
  virtual void exitTypeBrackets(LanguageParser::TypeBracketsContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

