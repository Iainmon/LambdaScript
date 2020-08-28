
// Generated from lambda.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "lambdaParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by lambdaParser.
 */
class  lambdaVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by lambdaParser.
   */
    virtual antlrcpp::Any visitInstructionLine(lambdaParser::InstructionLineContext *context) = 0;

    virtual antlrcpp::Any visitBinaryExpression(lambdaParser::BinaryExpressionContext *context) = 0;

    virtual antlrcpp::Any visitConditional(lambdaParser::ConditionalContext *context) = 0;

    virtual antlrcpp::Any visitApplication(lambdaParser::ApplicationContext *context) = 0;

    virtual antlrcpp::Any visitAbstraction(lambdaParser::AbstractionContext *context) = 0;

    virtual antlrcpp::Any visitVariable(lambdaParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitPrintInstruction(lambdaParser::PrintInstructionContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(lambdaParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitAssign(lambdaParser::AssignContext *context) = 0;

    virtual antlrcpp::Any visitBrackets(lambdaParser::BracketsContext *context) = 0;

    virtual antlrcpp::Any visitBody(lambdaParser::BodyContext *context) = 0;

    virtual antlrcpp::Any visitCondition(lambdaParser::ConditionContext *context) = 0;


};

