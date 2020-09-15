#include "InterpreterVisitor.h"

backend::InterpreterVisitor::InterpreterVisitor() {
    ast::scope_reference scope = std::make_shared<ast::Scope>();
    stack.push(scope);
}
backend::InterpreterVisitor::InterpreterVisitor(ast::scope_reference scope) {
    stack.push(scope);
}

ast::node_reference backend::InterpreterVisitor::visitLiteral(std::shared_ptr<ast::Literal> literal) {
    return (ast::node_reference)literal;
}
ast::node_reference backend::InterpreterVisitor::visitVariable(std::shared_ptr<ast::Variable> variable) {
    // Lazy evaluation. Returns the node without that was referenced, without evaluating it.
    return stack.top()->get(variable->identifier);
    // Other?
    return stack.top()->get(variable->identifier)->accept(this);
}
ast::node_reference backend::InterpreterVisitor::visitAssignment(std::shared_ptr<ast::Assignment> assignment) {
    // Lazy
    // ast::node_reference value = assignment->value;
    
    // Whatever I am doing
    ast::node_reference value = assignment->value->accept(this);

    stack.top()->set(assignment->identifier, value);
    
    // Walrus operator like
    return value;

    // Whatever I am doing. This is bad because it allows for functions to declare variables.
    // return (ast::node_reference)assignment;
}
ast::node_reference backend::InterpreterVisitor::visitApplication(std::shared_ptr<ast::Application> application) {
    // Do this later skater.
}
ast::node_reference backend::InterpreterVisitor::visitAbstraction(std::shared_ptr<ast::Abstraction> abstraction) {
    return (ast::node_reference)abstraction;
}
ast::node_reference backend::InterpreterVisitor::visitArithmeticalOperation(std::shared_ptr<ast::Operation> operation) {
    return (ast::node_reference)operation;
}
ast::node_reference backend::InterpreterVisitor::visitNativeAbstraction(std::shared_ptr<ast::NativeAbstraction> native_abstraction) {
    return (ast::node_reference)native_abstraction;
}
ast::node_reference backend::InterpreterVisitor::visitImportInstruction(std::shared_ptr<ast::ImportInstruction> import_instruction) {
    return (ast::node_reference)import_instruction;
}
ast::node_reference backend::InterpreterVisitor::visitGrouping(std::shared_ptr<ast::Grouping> grouping) {
    std::shared_ptr<ast::Grouping> evaluated_grouping = std::make_shared<ast::Grouping>();
    for (ast::node_reference &node : grouping->nodes) {
        ast::node_reference evaluated_node = node->accept(this);
        // evaluated_grouping->nodes.push_back(evaluated_node);
        node = evaluated_node;
    }
    // return (ast::node_reference)evaluated_grouping;
    return (ast::node_reference)grouping;
}

ast::node_reference backend::InterpreterVisitor::visitGenericASTNode(std::shared_ptr<ast::ASTNode> ast_node) {
    std::cout << ast_node->pretty_print() << std::endl;
    return ast_node;
}