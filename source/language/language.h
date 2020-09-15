#ifndef LANGUAGE_H
#define LANGUAGE_H

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

class Time : public ast::NativeAbstraction {
    private:
    std::chrono::time_point<std::chrono::high_resolution_clock> t1;
    public:
    Time();
    ast::node_reference apply(ast::node_reference argument, ast::scope_reference scope) override;
    void pre_apply_hook(ast::node_reference argument, ast::scope_reference scope) override;
    string to_string() override;
    string pretty_print() override;
};

}

}

#endif