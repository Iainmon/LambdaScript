#include "language.h"



language::native_functions::Exit::Exit() { type = ast::ASTNodeType::NATIVE_ABSTRACTION; }
ast::node_reference language::native_functions::Exit::apply(ast::node_reference argument, ast::scope_reference scope) {
    if (argument->type == ast::ASTNodeType::LITERAL) {
        std::shared_ptr<ast::Literal> literal = std::static_pointer_cast<ast::Literal>(argument);
        if (literal->valueType == ast::LiteralType::Int) {
            exit(literal->getInt());
        } else if (literal->valueType == ast::LiteralType::Bool) {
            exit(literal->getBool() ? 1 : 0);
        }
    }
    exit(0);
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

language::native_functions::Truthy::Truthy() { type = ast::ASTNodeType::NATIVE_ABSTRACTION; }
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



language::native_functions::Sum::Sum() {
    type = ast::ASTNodeType::NATIVE_ABSTRACTION;
    accumulator = 0;
}
ast::node_reference language::native_functions::Sum::apply(ast::node_reference argument, ast::scope_reference scope) {

    if (argument->type == ast::ASTNodeType::LITERAL) {
        std::shared_ptr<ast::Literal> literal = std::static_pointer_cast<ast::Literal>(argument);
        if (literal->valueType == ast::LiteralType::Int) {
            accumulator += literal->getInt();
        } else if (literal->valueType == ast::LiteralType::Bool) {
            accumulator += literal->getBool() ? 1 : 0;
        }
    }
    ast::node_reference self = shared_from_this();
    return self;
}
std::string language::native_functions::Sum::to_string() {
    std::stringstream ss;
    ss << "( native sum )";
    return ss.str();
}
std::string language::native_functions::Sum::pretty_print() {
    std::stringstream ss;
    ss << "( native sum )";
    return ss.str();
}
ast::node_reference language::native_functions::Sum::reduce() {
    ast::node_reference sum = make_shared<ast::Literal>(accumulator);
    return sum;
}



language::native_functions::Reduce::Reduce() {
    type = ast::ASTNodeType::NATIVE_ABSTRACTION;
}
ast::node_reference language::native_functions::Reduce::apply(ast::node_reference argument, ast::scope_reference scope) {

    std::shared_ptr<language::native_functions::Sum> sum = std::static_pointer_cast<language::native_functions::Sum>(argument);
    if (sum == nullptr)
        return argument;

    return sum->reduce();
}
std::string language::native_functions::Reduce::to_string() {
    std::stringstream ss;
    ss << "( native reduce )";
    return ss.str();
}
std::string language::native_functions::Reduce::pretty_print() {
    std::stringstream ss;
    ss << "( native reduce )";
    return ss.str();
}
