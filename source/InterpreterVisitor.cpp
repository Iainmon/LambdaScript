#include "frontend/frontend.h"
#include <iostream>
#include <memory>
#include <switch>

#include "ast/ast.h"

using namespace std;

class InterpreterVisitor : public lambdaBaseVisitor {
  private:
  public:
    map<string, ast::node_reference> assigned;

    antlrcpp::Any visitAbstraction(lambdaParser::AbstractionContext *ctx) override {
        const string argument = ctx->Identifier()->getText();
        ast::node_reference body = ctx->expression()->accept(this);
        ast::scope_reference scope = make_shared<ast::Scope>();
        shared_ptr<ast::Abstraction> abstraction = make_shared<ast::Abstraction>(argument, body, scope);
        return (ast::node_reference)abstraction;
    }

    antlrcpp::Any visitApplication(lambdaParser::ApplicationContext *ctx) override {
        
        // std::bad_cast happens when node_reference is returned without being bound to variable
        ast::node_reference lhs = ctx->expression(0)->accept(this);
        ast::node_reference rhs = ctx->expression(1)->accept(this);
        // Check if lhs is an abstraction. If not, return ast::Grouping instead of ast::Application
        // if (lhs->type == ast::ASTNodeType::ABSTRACTION) {
            // cout << "Application" << endl;
            ast::node_reference application = make_shared<ast::Application>(lhs, rhs);
            return application;
        // } else {
        //     cout << "Grouping" << endl;
        //     shared_ptr<ast::Grouping> grouping = make_shared<ast::Grouping>();
        //     grouping->nodes.push_back(lhs);
        //     grouping->nodes.push_back(rhs);
            
        //     return (ast::node_reference)grouping;
        // }

    }

    antlrcpp::Any visitVariable(lambdaParser::VariableContext *ctx) override {
        // cout << "VariableRefference " << ctx->Identifier()->getText() << endl;
        const string name = ctx->Identifier()->getText();
        // SWITCH(name)
        // CASE("tru") FALL CASE("true") ast::node_reference boolean = make_shared<ast::Literal>(true); return boolean;
        // BREAK
        // CASE("fls") FALL CASE("false") ast::node_reference boolean = make_shared<ast::Literal>(false); return boolean;
        // END

        ast::node_reference identifier = make_shared<ast::Variable>(name);
        return identifier;
    }

    antlrcpp::Any visitInstructionLine(lambdaParser::InstructionLineContext *ctx) override {
        // cout << "InstructionLiteral" << endl;
        if (ctx->expression().size() == 1) {
            return ctx->expression(0)->accept(this);
        }
        shared_ptr<ast::Grouping> grouping = make_shared<ast::Grouping>();
        for (lambdaParser::ExpressionContext* &line_expression : ctx->expression()) {
            ast::node_reference expression = line_expression->accept(this);
            grouping->nodes.push_back(expression);
        }
        return (ast::node_reference)grouping;
    }

    antlrcpp::Any visitLiteral(lambdaParser::LiteralContext *ctx) override {
        // cout << "Literal" << endl;

        if (ctx->Int() != nullptr) {
            const int value = stoi(ctx->Int()->getText());
            ast::node_reference integer = make_shared<ast::Literal>(value);
            return integer;
        }
        if (ctx->Bool() != nullptr) {
            const string boolean = ctx->Bool()->getText();
            SWITCH(boolean)
            CASE("tru") FALL CASE("true") ast::node_reference boolean = make_shared<ast::Literal>(true); return boolean;
            BREAK
            CASE("fls") FALL CASE("false") ast::node_reference boolean = make_shared<ast::Literal>(false); return boolean;
            END
        }

        cout << "HELLO " << ctx->getText() << endl;

        ast::node_reference nilLiteral = make_shared<ast::Literal>();
        return nilLiteral;
    }

    antlrcpp::Any visitAssign(lambdaParser::AssignContext *ctx) override {
        // cout << "Assignment" << endl;

        const string name = ctx->Identifier()->getText();
        ast::node_reference value = ctx->expression()->accept(this);
        assigned[name] = value;

        ast::node_reference assignment = make_shared<ast::Assignment>(name, value);
        return assignment;
        // return value; // Returns value of assignment instead of Assignment node.
    }

    antlrcpp::Any visitBinaryExpression(lambdaParser::BinaryExpressionContext *ctx) override {
        // cout << "BinaryExpression" << endl;
        ast::node_reference lhs = ctx->expression(0)->accept(this);
        ast::node_reference rhs = ctx->expression(1)->accept(this);
        ast::OperationType opType = ast::Operation::matchOperationType(ctx->Operator()->getText());
        ast::node_reference operationNode = make_shared<ast::Operation>(opType, lhs, rhs);
        return operationNode;
    }

    // Atom
    antlrcpp::Any visitBrackets(lambdaParser::BracketsContext *ctx) override {
        // cout << "Brackets" << endl;
        return ctx->expression()->accept(this);
    }

    antlrcpp::Any visitPrintInstruction(lambdaParser::PrintInstructionContext *ctx) override {
        // cout << "PrintInstruction" << endl;
        cout << ctx->expression()->getText() << endl;
        ast::node_reference valueToPrint = ctx->expression()->accept(this);
        ast::node_reference printInstr = make_shared<ast::PrintInstruction>(valueToPrint);
        return printInstr;
    }

    // Print should be a listnener
    // antlrcpp::Any visitPrint(lambdaParser::PrintInstructionContext *ctx) override {
    //   cout << dye::aqua() << endl;
    // }

    // visitImport(*ctx) {
    //     filename = ...
    //     parsed = parse(lex(pipe(filename)))
    //     return visit(parsed);
    // }
};