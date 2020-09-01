
// Generated from lambda.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "lambdaVisitor.h"


/**
 * This class provides an empty implementation of lambdaVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  lambdaBaseVisitor : public lambdaVisitor {
public:

  virtual antlrcpp::Any visitInstructionLine(lambdaParser::InstructionLineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryExpression(lambdaParser::BinaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImportInstruction(lambdaParser::ImportInstructionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConditional(lambdaParser::ConditionalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitApplication(lambdaParser::ApplicationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAbstraction(lambdaParser::AbstractionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(lambdaParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrintInstruction(lambdaParser::PrintInstructionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(lambdaParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssign(lambdaParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBrackets(lambdaParser::BracketsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBody(lambdaParser::BodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondition(lambdaParser::ConditionContext *ctx) override {
    return visitChildren(ctx);
  }


};

