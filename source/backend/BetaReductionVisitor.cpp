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
    if (replacement_table->has(abstraction->argument)) {
        // Creates variable node with renamed identifier
        const std::string& collided_argument = abstraction->argument;
        const std::string renamed_argument = enumerate_name(abstraction->argument);
        std::shared_ptr<ast::Variable> renamed_variable = std::make_shared<ast::Variable>(renamed_argument);

        // Renames all occurances inside of the abstraction body
        ast::scope_reference rename_table = std::make_shared<ast::Scope>();
        rename_table->set(collided_argument, renamed_variable);
        backend::AlphaRenamingVisitor alpha_renamer(rename_table);
        ast::node_reference renamed_body = abstraction->body->accept(&alpha_renamer);

        // Constructs new abstraction node
        ast::node_reference abs = std::make_shared<ast::Abstraction>(renamed_argument, renamed_body);
        return (ast::node_reference)abs;
    } else {
        ast::node_reference abs = std::make_shared<ast::Abstraction>(abstraction->argument, abstraction->body->accept(this));
        return (ast::node_reference)abs;
    }
}

std::string backend::BetaReductionVisitor::enumerate_name(const std::string &name) {
    int suffix = 0;
    std::string renamed;
    do {
        renamed = name + std::to_string(suffix);
        suffix++;
    } while (replacement_table->has(renamed));
    return renamed;
}