#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "../frontend/frontend.h"
#include "../ast/ast.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <memory>

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

    antlrcpp::Any visitImportInstruction(lambdaParser::ImportInstructionContext *ctx) override;

    antlrcpp::Any visitConditional(lambdaParser::ConditionalContext *ctx) override;

    antlrcpp::Any visitBody(lambdaParser::BodyContext *ctx) override;

    antlrcpp::Any visitCondition(lambdaParser::ConditionContext *ctx) override;

    antlrcpp::Any visitTypeBinding(lambdaParser::TypeBindingContext *ctx) override;

    antlrcpp::Any visitTypeBrackets(lambdaParser::TypeBracketsContext *ctx) override;

    antlrcpp::Any visitLeafType(lambdaParser::LeafTypeContext *ctx) override;

    antlrcpp::Any visitNodeType(lambdaParser::NodeTypeContext *ctx) override;

};

ast::node_reference construct_syntax_tree(const std::string& source);
ast::node_reference construct_syntax_tree(std::ifstream& source);

ast::node_reference evaluate(ast::node_reference ast, ast::scope_reference scope);
ast::node_reference import_file(const std::string& source_file, ast::scope_reference scope);

namespace native_functions {

class Exit : public ast::NativeAbstraction {
    public:
    Exit();
    ast::node_reference apply(ast::node_reference argument, ast::scope_reference scope) override;
    string to_string() override;
    string pretty_print() override;
};

class Truthy : public ast::NativeAbstraction {
    public:
    Truthy();
    ast::node_reference apply(ast::node_reference argument, ast::scope_reference scope) override;
    string to_string() override;
    string pretty_print() override;
};

class Sum : public ast::NativeAbstraction, public std::enable_shared_from_this<Sum> {
    int accumulator;
    public:
    Sum();
    ast::node_reference apply(ast::node_reference argument, ast::scope_reference scope) override;
    ast::node_reference reduce();
    string to_string() override;
    string pretty_print() override;
};

class Reduce : public ast::NativeAbstraction {
    public:
    Reduce();
    ast::node_reference apply(ast::node_reference argument, ast::scope_reference scope) override;
    string to_string() override;
    string pretty_print() override;
};

class Typeof : public ast::NativeAbstraction {
    public:
    Typeof();
    ast::node_reference apply(ast::node_reference argument, ast::scope_reference scope) override;
    string to_string() override;
    string pretty_print() override;
};

}

}

#endif