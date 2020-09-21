#include "ast.h"


ast::node_reference ast::typesystem::TypeNode::accept(backend::NodeVisitor *visitor) {
    std::shared_ptr<ast::typesystem::TypeNode> self = std::static_pointer_cast<ast::typesystem::TypeNode>(shared_from_this());
    return visitor->visitTypeNode(self);
}

bool ast::typesystem::TypeNode::operator==(const ast::typesystem::TypeNode &ref) {
    if (this->type == ref.type) {
        return *this == ref;
    } else {
        return false;
    }
}

bool ast::typesystem::Type::operator==(const ast::typesystem::TypeNode &ref) {
    if (typeid(ref) == typeid(ast::typesystem::Type)) {
        // Compares the string identifiers
        return name == static_cast<const ast::typesystem::Type&>(ref).name;
    } else {
        // Always false. Cannot compare leaf type to node type
        return false;
    }
}
bool ast::typesystem::FunctionType::operator==(const ast::typesystem::TypeNode &ref) {
    if (typeid(ref) == typeid(ast::typesystem::FunctionType)) {
        const ast::typesystem::FunctionType& reference = static_cast<const ast::typesystem::FunctionType&>(ref);
        return ((this->lhs == reference.lhs) && (this->rhs == reference.rhs));
    } else {
        return false;
    }
}

std::string ast::typesystem::TypeNode::pretty_print() {
    std::stringstream ss;
    ss << blue << ":: *" << reset;
    return ss.str();
}


ast::typesystem::Type::Type(const std::string &_name) {
    type = ast::ASTNodeType::LITERAL;
    name = _name;
}

std::string ast::typesystem::Type::pretty_print() {
    std::stringstream ss;
    ss << Bblue << name << reset;
    return ss.str();
}

ast::typesystem::FunctionType::FunctionType(ast::typesystem::type_reference _lhs, ast::typesystem::type_reference _rhs) {
    type = ast::ASTNodeType::LITERAL;
    lhs = _lhs;
    rhs = _rhs;
}

std::string ast::typesystem::FunctionType::pretty_print() {
    std::stringstream ss;
    ss << "(" << lhs->pretty_print() << " -> " << rhs->pretty_print() << ")";
    return ss.str();
}

ast::typesystem::type_reference ast::typesystem::type_from_name(const std::string &name) {
    // This is just a basic type annotation, and does not actually implement any of the required type properties.
    // This is temporary.
    ast::typesystem::type_reference type_from_name = std::make_shared<ast::typesystem::Type>(name);
    return type_from_name;

    // SWITCH(name)
    // CASE("Num") FALL CASE("Int")
    // ast::typesystem::type_reference number_type = std::make_shared<ast::typesystem::Num>();
    // return number_type;
    // BREAK
    // CASE("Bool")
    // ast::typesystem::type_reference boolean_type = std::make_shared<ast::typesystem::Bool>();
    // return boolean_type;
    // BREAK
    // END
}

