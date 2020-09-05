#include "language.h"
#include "../ast/ast.h"

using namespace std;
using namespace language;

antlrcpp::Any InterpreterVisitor::visitAbstraction(lambdaParser::AbstractionContext *ctx) {
    const string argument = ctx->Identifier()->getText();
    ast::node_reference body = ctx->expression()->accept(this);
    // ast::scope_reference scope = make_shared<ast::Scope>();
    shared_ptr<ast::Abstraction> abstraction = make_shared<ast::Abstraction>(argument, body);
    return (ast::node_reference)abstraction;
}
antlrcpp::Any InterpreterVisitor::visitApplication(lambdaParser::ApplicationContext *ctx)  {

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
antlrcpp::Any InterpreterVisitor::visitVariable(lambdaParser::VariableContext *ctx)  {
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
antlrcpp::Any InterpreterVisitor::visitInstructionLine(lambdaParser::InstructionLineContext *ctx)  {
    // cout << "InstructionLiteral" << endl;
    if (ctx->expression().size() == 1) {
        return ctx->expression(0)->accept(this);
    }
    shared_ptr<ast::Grouping> grouping = make_shared<ast::Grouping>();
    for (lambdaParser::ExpressionContext *&line_expression : ctx->expression()) {
        ast::node_reference expression = line_expression->accept(this);
        grouping->nodes.push_back(expression);
    }
    return (ast::node_reference)grouping;
}
antlrcpp::Any InterpreterVisitor::visitLiteral(lambdaParser::LiteralContext *ctx)  {
    // cout << "Literal" << endl;

    if (ctx->Int() != nullptr) {
        const int value = stoi(ctx->Int()->getText());
        ast::node_reference integer = make_shared<ast::Literal>(value);
        return integer;
    }
    if (ctx->Bool() != nullptr) {
        const string boolean = ctx->Bool()->getText();
        SWITCH(boolean)
        CASE("tru") FALL CASE("true") ast::node_reference boolean = make_shared<ast::Literal>(true);
        return boolean;
        BREAK
        CASE("fls") FALL CASE("false") ast::node_reference boolean = make_shared<ast::Literal>(false);
        return boolean;
        END
    }

    cout << "HELLO " << ctx->getText() << endl;

    ast::node_reference base_literal = make_shared<ast::Literal>('l');
    return base_literal;
}
antlrcpp::Any InterpreterVisitor::visitAssign(lambdaParser::AssignContext *ctx)  {
    // cout << "Assignment" << endl;

    const string name = ctx->Identifier()->getText();
    ast::node_reference value = ctx->expression()->accept(this);
    // assigned[name] = value;

    ast::node_reference assignment = make_shared<ast::Assignment>(name, value);
    return assignment;
    // return value; // Returns value of assignment instead of Assignment node.
}
antlrcpp::Any InterpreterVisitor::visitBinaryExpression(lambdaParser::BinaryExpressionContext *ctx)  {
    // cout << "BinaryExpression" << endl;
    ast::node_reference lhs = ctx->expression(0)->accept(this);
    ast::node_reference rhs = ctx->expression(1)->accept(this);
    ast::OperationType opType = ast::Operation::matchOperationType(ctx->Operator()->getText());
    ast::node_reference operationNode = make_shared<ast::Operation>(opType, lhs, rhs);
    return operationNode;
}
antlrcpp::Any InterpreterVisitor::visitBrackets(lambdaParser::BracketsContext *ctx)  {
    // cout << "Brackets" << endl;
    return ctx->expression()->accept(this);
}
antlrcpp::Any InterpreterVisitor::visitPrintInstruction(lambdaParser::PrintInstructionContext *ctx)  {
    // cout << "PrintInstruction" << endl;
    ast::node_reference valueToPrint = ctx->expression()->accept(this);
    ast::node_reference printInstr = make_shared<ast::PrintInstruction>(valueToPrint);
    return printInstr;
}
antlrcpp::Any InterpreterVisitor::visitImportInstruction(lambdaParser::ImportInstructionContext *ctx) {
    // return ctx->imports()->accept(this);
    string file_name = ctx->Identifier()->getText();
    ast::node_reference importInstr = make_shared<ast::ImportInstruction>(file_name);
    return importInstr;
}

antlrcpp::Any InterpreterVisitor::visitConditional(lambdaParser::ConditionalContext *ctx) {
    return ctx->condition()->accept(this);
}
antlrcpp::Any InterpreterVisitor::visitBody(lambdaParser::BodyContext *ctx) {
    return ctx->expression()->accept(this);
}

antlrcpp::Any InterpreterVisitor::visitCondition(lambdaParser::ConditionContext *ctx) {
    
    ast::node_reference condition = ctx->expression()->accept(this);
    ast::node_reference tru_expression = ctx->body(0)->accept(this);
    ast::node_reference fls_expression = ctx->body(1)->accept(this);
    
    // This is not the way to go. Conditionals should exist as an AST node, instead of being encoded as truthy applications.

    ast::node_reference truthy = make_shared<native_functions::Truthy>();
    ast::node_reference application_0 = make_shared<ast::Application>(truthy, condition);
    ast::node_reference application_1 = make_shared<ast::Application>(application_0, tru_expression);
    ast::node_reference application_2 = make_shared<ast::Application>(application_1, fls_expression);
    return application_2;
}
