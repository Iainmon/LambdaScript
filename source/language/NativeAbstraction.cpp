#include "language.h"
#include "../ast/ast.h"

#include <iostream>
#include <string>
#include <sstream>

language::native_functions::Exit::Exit() {
    type = ast::ASTNodeType::NATIVE_ABSTRACTION;
}
ast::node_reference language::native_functions::Exit::apply(ast::node_reference argument, ast::scope_reference scope) {
    throw 0;
    return argument;
}
std::string language::native_functions::Exit::to_string() {
    std::stringstream ss;
    ss << "( native exit )";
    return ss.str();
}
std::string language::native_functions::Exit::pretty_print() {
    std::stringstream ss;
    ss << "( native exit )";
    return ss.str();
}


language::native_functions::Truthy::Truthy() {
    type = ast::ASTNodeType::NATIVE_ABSTRACTION;
}
ast::node_reference language::native_functions::Truthy::apply(ast::node_reference argument, ast::scope_reference scope) {
    bool truthy;

    if (argument->type == ast::ASTNodeType::LITERAL) {
        std::shared_ptr<ast::Literal> literal = std::static_pointer_cast<ast::Literal>(argument);
        if (literal->valueType == ast::LiteralType::Int) {
            truthy = literal->getInt() > 0;
        } else if (literal->valueType == ast::LiteralType::Bool) {
            truthy = literal->getBool();
        } else if (literal->valueType == ast::LiteralType::Nil) {
            truthy = false;
        } else {
            truthy = false;
        }
    } else {
        truthy = false;
    }
    ast::node_reference boolean_literal = std::make_shared<ast::Literal>(truthy);
    return boolean_literal;
}
std::string language::native_functions::Truthy::to_string() {
    std::stringstream ss;
    ss << "( native truthy )";
    return ss.str();
}
std::string language::native_functions::Truthy::pretty_print() {
    std::stringstream ss;
    ss << "( native truthy )";
    return ss.str();
}