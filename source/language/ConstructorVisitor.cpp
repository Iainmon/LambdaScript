#include "language.h"
#include "../ast/ast.h"
#include "../backend/interpreter/native_library/native_library.h"
#include "../backend/backend.h"
using namespace std;
using namespace language;

antlrcpp::Any ConstructorVisitor::visitAbstraction(LanguageParser::AbstractionContext *ctx) {
    const string argument = ctx->Identifier()->getText();
    ast::node_reference body = ctx->expression()->accept(this);
    // ast::scope_reference scope = make_shared<ast::Scope>();
    shared_ptr<ast::Abstraction> abstraction = make_shared<ast::Abstraction>(argument, body);

    // [flag TODO]
    if (ctx->typeBinding() != nullptr) {
        // This is where the body type should be resolved, and a function type should be constructed and assigned to the abstraction here.
        ast::typesystem::type_reference argument_type = ctx->typeBinding()->accept(this);
        if (body->data_type != nullptr) {
            ast::typesystem::type_reference body_type = abstraction->body->data_type;
            ast::typesystem::type_reference abstraction_type = make_shared<ast::typesystem::FunctionType>(argument_type, body_type);
        } else {
            ast::typesystem::type_reference ambiguous_type = ast::typesystem::type_from_name("Ambiguous");
            ast::typesystem::type_reference abstraction_type = make_shared<ast::typesystem::FunctionType>(argument_type, ambiguous_type);
            abstraction->data_type = abstraction_type;
        }
    }
    return (ast::node_reference)abstraction;
}
antlrcpp::Any ConstructorVisitor::visitApplication(LanguageParser::ApplicationContext *ctx)  {

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
antlrcpp::Any ConstructorVisitor::visitVariable(LanguageParser::VariableContext *ctx)  {
    // cout << "VariableRefference " << ctx->Identifier()->getText() << endl;
    const string name = ctx->Identifier()->getText();
    // SWITCH(name)
    // CASE("tru") FALL CASE("true") ast::node_reference boolean = make_shared<ast::Literal>(true); return boolean;
    // BREAK
    // CASE("fls") FALL CASE("false") ast::node_reference boolean = make_shared<ast::Literal>(false); return boolean;
    // END

    ast::node_reference identifier = make_shared<ast::Variable>(name);

    if (ctx->typeBinding() != nullptr) {
        ast::typesystem::type_reference type = ctx->typeBinding()->accept(this);
        identifier->data_type = type;
    }

    return identifier;
}
antlrcpp::Any ConstructorVisitor::visitInstructionLine(LanguageParser::InstructionLineContext *ctx)  {
    // cout << "InstructionLiteral" << endl;
    if (ctx->expression().size() == 1) {
        return ctx->expression(0)->accept(this);
    }
    shared_ptr<ast::Grouping> grouping = make_shared<ast::Grouping>();
    for (LanguageParser::ExpressionContext *&line_expression : ctx->expression()) {
        ast::node_reference expression = line_expression->accept(this);
        grouping->nodes.push_back(expression);
    }
    return (ast::node_reference)grouping;
}
antlrcpp::Any ConstructorVisitor::visitLiteral(LanguageParser::LiteralContext *ctx)  {
    // cout << "Literal" << endl;

    if (ctx->Int() != nullptr) {
        const int value = stoi(ctx->Int()->getText());
        ast::node_reference integer = make_shared<ast::Literal>(value);
        integer->data_type = ast::typesystem::type_from_name("Num");
        return integer;
    }
    if (ctx->Bool() != nullptr) {
        const string boolean = ctx->Bool()->getText();
        SWITCH(boolean)
        CASE("tru") FALL CASE("true") ast::node_reference boolean = make_shared<ast::Literal>(true);
        boolean->data_type = ast::typesystem::type_from_name("Bool");
        return boolean;
        BREAK
        CASE("fls") FALL CASE("false") ast::node_reference boolean = make_shared<ast::Literal>(false);
        boolean->data_type = ast::typesystem::type_from_name("Bool");
        return boolean;
        END
    }

    cout << "HELLO " << ctx->getText() << endl;

    ast::node_reference base_literal = make_shared<ast::Literal>('l');
    return base_literal;
}
antlrcpp::Any ConstructorVisitor::visitAssign(LanguageParser::AssignContext *ctx)  {
    // cout << "Assignment" << endl;

    const string name = ctx->Identifier()->getText();
    ast::node_reference value = ctx->expression()->accept(this);
    if (ctx->typeBinding() != nullptr) {
        ast::typesystem::type_reference type = ctx->typeBinding()->accept(this);
        value->data_type = type;
    }

    ast::node_reference assignment = make_shared<ast::Assignment>(name, value);
    return assignment;
    // return value; // Returns value of assignment instead of Assignment node.
}
antlrcpp::Any ConstructorVisitor::visitBinaryExpression(LanguageParser::BinaryExpressionContext *ctx)  {
    // cout << "BinaryExpression" << endl;
    ast::node_reference lhs = ctx->expression(0)->accept(this);
    ast::node_reference rhs = ctx->expression(1)->accept(this);
    ast::OperationType opType = ast::Operation::matchOperationType(ctx->Operator()->getText());
    ast::node_reference operation_node = make_shared<ast::Operation>(opType, lhs, rhs);

    // Sets the operation symbol as a string.
    shared_ptr<ast::Operation> op_node = static_pointer_cast<ast::Operation>(operation_node);
    op_node->operation_character = ctx->Operator()->getText();

    return operation_node;
}
antlrcpp::Any ConstructorVisitor::visitBrackets(LanguageParser::BracketsContext *ctx)  {
    // cout << "Brackets" << endl;
    return ctx->expression()->accept(this);
}
antlrcpp::Any ConstructorVisitor::visitPrintInstruction(LanguageParser::PrintInstructionContext *ctx)  {
    // cout << "PrintInstruction" << endl;
    ast::node_reference valueToPrint = ctx->expression()->accept(this);
    ast::node_reference printInstr = make_shared<ast::PrintInstruction>(valueToPrint);
    return printInstr;
}
antlrcpp::Any ConstructorVisitor::visitImportInstruction(LanguageParser::ImportInstructionContext *ctx) {
    // return ctx->imports()->accept(this);
    string file_name = ctx->Identifier()->getText();
    ast::node_reference importInstr = make_shared<ast::ImportInstruction>(file_name);
    return importInstr;
}

antlrcpp::Any ConstructorVisitor::visitConditional(LanguageParser::ConditionalContext *ctx) {
    return ctx->condition()->accept(this);
}
antlrcpp::Any ConstructorVisitor::visitBody(LanguageParser::BodyContext *ctx) {
    return ctx->expression()->accept(this);
}

antlrcpp::Any ConstructorVisitor::visitCondition(LanguageParser::ConditionContext *ctx) {
    
    ast::node_reference condition = ctx->expression()->accept(this);
    ast::node_reference tru_expression = ctx->body(0)->accept(this);
    ast::node_reference fls_expression = ctx->body(1)->accept(this);

    // [flag TODO]
    // This is not the way to go. Conditionals should exist as an AST node, instead of being encoded as truthy applications.

    ast::node_reference native_truthy = std::make_shared<backend::interpreter::Curried>(std::make_shared<backend::interpreter::native_library::Truthy>(), 1);

    ast::node_reference application_0 = make_shared<ast::Application>(native_truthy, condition);
    ast::node_reference application_1 = make_shared<ast::Application>(application_0, tru_expression);
    ast::node_reference application_2 = make_shared<ast::Application>(application_1, fls_expression);
    return application_2;
}

antlrcpp::Any ConstructorVisitor::visitTypeBinding(LanguageParser::TypeBindingContext *ctx) {
    return ctx->type()->accept(this);
}
antlrcpp::Any ConstructorVisitor::visitTypeBrackets(LanguageParser::TypeBracketsContext *ctx) {
    return ctx->type()->accept(this);
}

antlrcpp::Any ConstructorVisitor::visitLeafType(LanguageParser::LeafTypeContext *ctx) {
    const string type_name = ctx->TypeIdentifier()->getText();
    ast::typesystem::type_reference type = ast::typesystem::type_from_name(type_name);
    return type;
}
antlrcpp::Any ConstructorVisitor::visitNodeType(LanguageParser::NodeTypeContext *ctx) {
    ast::typesystem::type_reference lhs = ctx->type(0)->accept(this);
    ast::typesystem::type_reference rhs = ctx->type(1)->accept(this);
    ast::typesystem::type_reference node_type = make_shared<ast::typesystem::FunctionType>(lhs, rhs);
    return node_type;
}