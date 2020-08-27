#include "ast.h"

using namespace std;

ast::node_reference ast::evaluate(node_reference ast) {
    while (true) {
        if (ast->type == ast::ASTNodeType::APPLICATION) {
            // Reduce both sides, then apply beta reduction.
        } else {
            return ast;
        }
    }
}