
// Generated from Language.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "LanguageVisitor.h"


/**
 * This class provides an empty implementation of LanguageVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  LanguageBaseVisitor : public LanguageVisitor {
public:

  virtual antlrcpp::Any visitInstructionLine(LanguageParser::InstructionLineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryExpression(LanguageParser::BinaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImportInstruction(LanguageParser::ImportInstructionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConditional(LanguageParser::ConditionalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitApplication(LanguageParser::ApplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAbstraction(LanguageParser::AbstractionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(LanguageParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrintInstruction(LanguageParser::PrintInstructionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(LanguageParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssign(LanguageParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBrackets(LanguageParser::BracketsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBody(LanguageParser::BodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondition(LanguageParser::ConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeBinding(LanguageParser::TypeBindingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLeafType(LanguageParser::LeafTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNodeType(LanguageParser::NodeTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeBrackets(LanguageParser::TypeBracketsContext *ctx) override {
    return visitChildren(ctx);
  }


};

