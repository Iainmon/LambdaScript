
// Generated from Language.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "LanguageParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by LanguageParser.
 */
class  LanguageVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by LanguageParser.
   */
    virtual antlrcpp::Any visitInstructionLine(LanguageParser::InstructionLineContext *context) = 0;

    virtual antlrcpp::Any visitBinaryExpression(LanguageParser::BinaryExpressionContext *context) = 0;

    virtual antlrcpp::Any visitImportInstruction(LanguageParser::ImportInstructionContext *context) = 0;

    virtual antlrcpp::Any visitConditional(LanguageParser::ConditionalContext *context) = 0;

    virtual antlrcpp::Any visitApplication(LanguageParser::ApplicationContext *context) = 0;

    virtual antlrcpp::Any visitAbstraction(LanguageParser::AbstractionContext *context) = 0;

    virtual antlrcpp::Any visitVariable(LanguageParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitPrintInstruction(LanguageParser::PrintInstructionContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(LanguageParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitAssign(LanguageParser::AssignContext *context) = 0;

    virtual antlrcpp::Any visitBrackets(LanguageParser::BracketsContext *context) = 0;

    virtual antlrcpp::Any visitBody(LanguageParser::BodyContext *context) = 0;

    virtual antlrcpp::Any visitCondition(LanguageParser::ConditionContext *context) = 0;

    virtual antlrcpp::Any visitTypeBinding(LanguageParser::TypeBindingContext *context) = 0;

    virtual antlrcpp::Any visitLeafType(LanguageParser::LeafTypeContext *context) = 0;

    virtual antlrcpp::Any visitNodeType(LanguageParser::NodeTypeContext *context) = 0;

    virtual antlrcpp::Any visitTypeBrackets(LanguageParser::TypeBracketsContext *context) = 0;


};

