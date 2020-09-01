#include "language.h"
#include <iostream>

// ast::node_reference language::import_file(const std::string &source_file, ast::scope_reference scope) {
//     std::ifstream source_stream;
//     source_stream.open(source_file);
//     ast::node_reference ast = language::construct_syntax_tree(source_stream);
//     ast::node_reference evaluated_ast = language::evaluate(ast, scope);
//     return evaluated_ast;
// }