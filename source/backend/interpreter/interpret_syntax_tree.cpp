#include "interpret_syntax_tree.h"
#include "InterpreterVisitor.h"

ast::node_reference backend::interpreter::interpret_syntax_tree(ast::node_reference root, ast::scope_reference scope) {
    InterpreterVisitor interpreter_visitor(scope);
    return root->accept(&interpreter_visitor);
}