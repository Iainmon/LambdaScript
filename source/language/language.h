#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "../frontend/frontend.h"
#include "../ast/ast.h"
#include <string>

namespace language {
class InterpreterVisitor : public lambdaBaseVisitor {
  public:

    antlrcpp::Any visitAbstraction(lambdaParser::AbstractionContext *ctx) override;

    antlrcpp::Any visitApplication(lambdaParser::ApplicationContext *ctx) override;

    antlrcpp::Any visitVariable(lambdaParser::VariableContext *ctx) override;

    antlrcpp::Any visitInstructionLine(lambdaParser::InstructionLineContext *ctx) override;

    antlrcpp::Any visitLiteral(lambdaParser::LiteralContext *ctx) override;

    antlrcpp::Any visitAssign(lambdaParser::AssignContext *ctx) override;

    antlrcpp::Any visitBinaryExpression(lambdaParser::BinaryExpressionContext *ctx) override;

    antlrcpp::Any visitBrackets(lambdaParser::BracketsContext *ctx) override;

    antlrcpp::Any visitPrintInstruction(lambdaParser::PrintInstructionContext *ctx) override;
};

ast::node_reference construct_syntax_tree(const std::string& source);
ast::node_reference construct_syntax_tree(const std::istream& source);

ast::node_reference evaluate(ast::node_reference ast, ast::scope_reference scope);
ast::node_reference import_file(const std::string& source_file, ast::scope_reference scope);
}

#endif