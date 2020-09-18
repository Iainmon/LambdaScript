#include "NodeVisitor.h"

backend::NodeVisitor::NodeVisitor() {}

ast::node_reference backend::NodeVisitor::visitLiteral(std::shared_ptr<ast::Literal> literal) {
    return (ast::node_reference)literal;
}
ast::node_reference backend::NodeVisitor::visitVariable(std::shared_ptr<ast::Variable> variable) {
    return (ast::node_reference)variable;
}
ast::node_reference backend::NodeVisitor::visitAssignment(std::shared_ptr<ast::Assignment> assignment) {
    ast::node_reference ass = std::make_shared<ast::Assignment>(assignment->identifier, assignment->value->accept(this));
    return (ast::node_reference)assignment;
}
ast::node_reference backend::NodeVisitor::visitApplication(std::shared_ptr<ast::Application> application) {
    ast::node_reference app = std::make_shared<ast::Application>(application->lhs->accept(this), application->rhs->accept(this));
    return app;
}
ast::node_reference backend::NodeVisitor::visitAbstraction(std::shared_ptr<ast::Abstraction> abstraction) {
    ast::node_reference abs = std::make_shared<ast::Abstraction>(abstraction->argument, abstraction->body->accept(this));
    return (ast::node_reference)abs;
}
ast::node_reference backend::NodeVisitor::visitArithmeticalOperation(std::shared_ptr<ast::Operation> operation) {
    // The Operation ASTNode should be converted to a NativeAbstraction
    ast::node_reference op = std::make_shared<ast::Operation>(operation->opType, operation->lhs->accept(this), operation->rhs->accept(this));
    return (ast::node_reference)op;
}
ast::node_reference backend::NodeVisitor::visitNativeAbstraction(std::shared_ptr<ast::NativeAbstraction> native_abstraction) {
    // Will call the native_abstractions .apply() method, where it will construct an AST tree
    // Sometimes the use of a new Curryable object will be used to keep track of previously provided arguments, until all are met, and the expression can be executed internally.
    // For example, the add function (+) will need to do this. Exit will not. Print will not.
    return (ast::node_reference)native_abstraction;
}
ast::node_reference backend::NodeVisitor::visitImportInstruction(std::shared_ptr<ast::ImportInstruction> import_instruction) {
    return (ast::node_reference)import_instruction;
}
ast::node_reference backend::NodeVisitor::visitPrintInstruction(std::shared_ptr<ast::PrintInstruction> print_instruction) {
    ast::node_reference print = std::make_shared<ast::PrintInstruction>(print_instruction->value->accept(this));
    return print;
}
ast::node_reference backend::NodeVisitor::visitGrouping(std::shared_ptr<ast::Grouping> grouping) {
    std::shared_ptr<ast::Grouping> evaluated_grouping = std::make_shared<ast::Grouping>();
    for (ast::node_reference &node : grouping->nodes) {
        ast::node_reference evaluated_node = node->accept(this);
        evaluated_grouping->nodes.push_back(evaluated_node);
    }
    return (ast::node_reference)evaluated_grouping;
}

ast::node_reference backend::NodeVisitor::visitGenericASTNode(std::shared_ptr<ast::ASTNode> ast_node) {
    return ast_node;
}
