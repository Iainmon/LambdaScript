#pragma once

#include "../frontend/frontend.h"
#include "../ast/ast.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <memory>
#include <chrono>

namespace language {
class ConstructorVisitor : public LanguageBaseVisitor {
  public:

    antlrcpp::Any visitAbstraction(LanguageParser::AbstractionContext *ctx) override;

    antlrcpp::Any visitApplication(LanguageParser::ApplicationContext *ctx) override;

    antlrcpp::Any visitVariable(LanguageParser::VariableContext *ctx) override;

    antlrcpp::Any visitInstructionLine(LanguageParser::InstructionLineContext *ctx) override;

    antlrcpp::Any visitLiteral(LanguageParser::LiteralContext *ctx) override;

    antlrcpp::Any visitAssign(LanguageParser::AssignContext *ctx) override;

    antlrcpp::Any visitBinaryExpression(LanguageParser::BinaryExpressionContext *ctx) override;

    antlrcpp::Any visitBrackets(LanguageParser::BracketsContext *ctx) override;

    antlrcpp::Any visitPrintInstruction(LanguageParser::PrintInstructionContext *ctx) override;

    antlrcpp::Any visitImportInstruction(LanguageParser::ImportInstructionContext *ctx) override;

    antlrcpp::Any visitConditional(LanguageParser::ConditionalContext *ctx) override;

    antlrcpp::Any visitBody(LanguageParser::BodyContext *ctx) override;

    antlrcpp::Any visitCondition(LanguageParser::ConditionContext *ctx) override;

    antlrcpp::Any visitTypeBinding(LanguageParser::TypeBindingContext *ctx) override;

    antlrcpp::Any visitTypeBrackets(LanguageParser::TypeBracketsContext *ctx) override;

    antlrcpp::Any visitLeafType(LanguageParser::LeafTypeContext *ctx) override;

    antlrcpp::Any visitNodeType(LanguageParser::NodeTypeContext *ctx) override;

};

ast::node_reference construct_syntax_tree(const std::string& source);
ast::node_reference construct_syntax_tree(std::ifstream& source);

ast::node_reference evaluate(ast::node_reference ast, ast::scope_reference scope);
ast::node_reference import_file(const std::string& source_file, ast::scope_reference scope);
}
