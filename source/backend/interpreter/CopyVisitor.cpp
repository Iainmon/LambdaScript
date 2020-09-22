#include "CopyVisitor.h"

ast::node_reference backend::interpreter::CopyVisitor::visitLiteral(std::shared_ptr<ast::Literal> literal) {
    std::shared_ptr<ast::Literal> lit = std::make_shared<ast::Literal>();
    lit->valueType = literal->valueType;
    lit->value = literal->value;
    return lit;
}
ast::node_reference backend::interpreter::CopyVisitor::visitVariable(std::shared_ptr<ast::Variable> variable) {
    std::shared_ptr<ast::Variable> var = std::make_shared<ast::Variable>(variable->identifier);
    return var;
}
ast::node_reference backend::interpreter::CopyVisitor::visitTypeNode(std::shared_ptr<ast::typesystem::TypeNode> type_node) {
    if (typeid(*type_node) == typeid(ast::typesystem::FunctionType)) {
        std::shared_ptr<ast::typesystem::FunctionType> function_type_node = std::static_pointer_cast<ast::typesystem::FunctionType>(type_node);
        ast::typesystem::type_reference lhs = std::static_pointer_cast<ast::typesystem::TypeNode>(function_type_node->lhs->accept(this));
        ast::typesystem::type_reference rhs = std::static_pointer_cast<ast::typesystem::TypeNode>(function_type_node->rhs->accept(this));
        std::shared_ptr<ast::typesystem::FunctionType> node = std::make_shared<ast::typesystem::FunctionType>(lhs, rhs);
        return node;
    } else {
        std::shared_ptr<ast::typesystem::Type> leaf_type_node = std::static_pointer_cast<ast::typesystem::Type>(type_node); 
        std::shared_ptr<ast::typesystem::Type> node = std::make_shared<ast::typesystem::Type>(leaf_type_node->name);
        return node;
    }
}