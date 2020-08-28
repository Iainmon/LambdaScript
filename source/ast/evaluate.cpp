#include "ast.h"

using namespace std;

ast::node_reference ast::evaluate(node_reference ast, scope_reference scope) {
    while (true) {
        if (ast->type == ast::ASTNodeType::APPLICATION) {
            // Reduce both sides, then apply beta reduction.
        } else if (ast->type == ast::ASTNodeType::GROUPING) {
            shared_ptr<ast::Grouping> grouping = static_pointer_cast<ast::Grouping>(ast);
            for (ast::node_reference &node : grouping->nodes) {

            }
        } else {
            return ast;
        }
    }
}