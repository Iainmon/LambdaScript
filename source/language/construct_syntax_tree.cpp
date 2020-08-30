
#include "language.h"
#include <iostream>
#include <string>

using namespace antlr4;

ast::node_reference language::construct_syntax_tree(const std::string &source) {

    ANTLRInputStream input(source);
    lambdaLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    lambdaParser parser(&tokens);

    tree::ParseTree *tree = parser.program();

    language::InterpreterVisitor visitor;
    ast::node_reference ast = visitor.visit(tree);

    return ast;
}