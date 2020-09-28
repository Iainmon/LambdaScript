#include "native_library.h"
using namespace std;

backend::interpreter::native_library::Exit::Exit() { type = ast::ASTNodeType::NATIVE_ABSTRACTION; }
ast::node_reference backend::interpreter::native_library::Exit::apply(ast::node_reference argument, ast::scope_reference scope) {
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
ast::node_reference backend::interpreter::native_library::Exit::execute_with_argument_queue(std::queue<ast::node_reference> arguments) {
    ast::node_reference argument = arguments.back();
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
std::string backend::interpreter::native_library::Exit::to_string() {
    std::stringstream ss;
    ss << "( native exit )";
    return ss.str();
}
std::string backend::interpreter::native_library::Exit::pretty_print() {
    std::stringstream ss;
    ss << "( native exit )";
    return ss.str();
}

backend::interpreter::native_library::Truthy::Truthy() { type = ast::ASTNodeType::NATIVE_ABSTRACTION; }
ast::node_reference backend::interpreter::native_library::Truthy::apply(ast::node_reference argument, ast::scope_reference scope) {
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
ast::node_reference backend::interpreter::native_library::Truthy::execute_with_argument_queue(std::queue<ast::node_reference> arguments) {
    ast::node_reference argument = arguments.back();

    bool truthy;

    std::shared_ptr<ast::Abstraction> tru_body = std::make_shared<ast::Abstraction>("b", std::make_shared<ast::Variable>("a"));
    std::shared_ptr<ast::Abstraction> fls_body = std::make_shared<ast::Abstraction>("b", std::make_shared<ast::Variable>("b"));
    std::shared_ptr<ast::Abstraction> tru_encoding = std::make_shared<ast::Abstraction>("a", tru_body);
    std::shared_ptr<ast::Abstraction> fls_encoding = std::make_shared<ast::Abstraction>("a", fls_body);

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
    return truthy ? tru_encoding : fls_encoding;
}
std::string backend::interpreter::native_library::Truthy::to_string() {
    std::stringstream ss;
    ss << "( native truthy )";
    return ss.str();
}
std::string backend::interpreter::native_library::Truthy::pretty_print() {
    std::stringstream ss;
    ss << "( native truthy )";
    return ss.str();
}


backend::interpreter::native_library::Typeof::Typeof() {
    type = ast::ASTNodeType::NATIVE_ABSTRACTION;
}
ast::node_reference backend::interpreter::native_library::Typeof::apply(ast::node_reference argument, ast::scope_reference scope) {
    // For this to work the way it is supposed to, Types have to have an specific AST node
    if (argument->data_type != nullptr) {
        cout << blue << ":: " << reset << argument->data_type->pretty_print() << endl;
    }
    return argument;
}
ast::node_reference backend::interpreter::native_library::Typeof::execute_with_argument_queue(std::queue<ast::node_reference> arguments) {
    ast::node_reference argument = arguments.back();
    // if (argument->data_type != nullptr) {
    //     cout << blue << ":: " << reset << argument->data_type->pretty_print() << endl;
    // }
    if (argument->data_type != nullptr) {
        return argument->data_type;
    } else {
        return argument;
    }
}
std::string backend::interpreter::native_library::Typeof::to_string() {
    std::stringstream ss;
    ss << "( native typeof )";
    return ss.str();
}
std::string backend::interpreter::native_library::Typeof::pretty_print() {
    std::stringstream ss;
    ss << "( native typeof )";
    return ss.str();
}