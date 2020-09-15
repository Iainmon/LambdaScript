
#include "language.h"
#include <iostream>
#include <string>

using namespace antlr4;

ast::node_reference language::construct_syntax_tree(const std::string &source) {

    ANTLRInputStream input(source);
    LanguageLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    LanguageParser parser(&tokens);

    tree::ParseTree *tree = parser.program();

    language::ConstructorVisitor visitor;
    ast::node_reference ast = visitor.visit(tree);

    return ast;
}

ast::node_reference language::construct_syntax_tree(std::ifstream &source) {

    ANTLRInputStream input(source);
    LanguageLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    LanguageParser parser(&tokens);

    tree::ParseTree *tree = parser.program();

    language::ConstructorVisitor visitor;
    ast::node_reference ast = visitor.visit(tree);

    return ast;
}