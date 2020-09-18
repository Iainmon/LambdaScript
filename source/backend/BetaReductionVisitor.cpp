#include "BetaReductionVisitor.h"

backend::BetaReductionVisitor::BetaReductionVisitor() {
    // Nothing to replace
    ast::scope_reference scope = std::make_shared<ast::Scope>();
    replacement_table = scope;
}
backend::BetaReductionVisitor::BetaReductionVisitor(ast::scope_reference _replacement_table) {
    replacement_table = _replacement_table;
}



ast::node_reference backend::BetaReductionVisitor::visitVariable(std::shared_ptr<ast::Variable> variable) {
    if (replacement_table->has(variable->identifier)) {
        return replacement_table->get(variable->identifier);
    } else {
        return (ast::node_reference)variable;
    }
}
ast::node_reference backend::BetaReductionVisitor::visitAssignment(std::shared_ptr<ast::Assignment> assignment) {
    return (ast::node_reference)assignment;
}
ast::node_reference backend::BetaReductionVisitor::visitApplication(std::shared_ptr<ast::Application> application) {
    ast::node_reference app = std::make_shared<ast::Application>(application->lhs->accept(this), application->rhs->accept(this));
    return app;
}
ast::node_reference backend::BetaReductionVisitor::visitAbstraction(std::shared_ptr<ast::Abstraction> abstraction) {
    ast::node_reference abs = std::make_shared<ast::Abstraction>(abstraction->argument, abstraction->body->accept(this));
    return (ast::node_reference)abs;
}