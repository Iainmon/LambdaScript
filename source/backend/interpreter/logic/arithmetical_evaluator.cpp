#include "arithmetical_evaluator.h"

int backend::integrated_arithmetical_expression_evaluation::apply_arithmatic_operation(ast::OperationType op_type, int lhs, int rhs) {
    switch (op_type) {
        case ast::OperationType::ADD:
            return lhs + rhs;
            break;
        case ast::OperationType::SUBTRACT:
            return lhs - rhs;
            break;
        case ast::OperationType::MULTIPLY:
            return lhs * rhs;
            break;
        case ast::OperationType::DIVIDE:
            return lhs / rhs;
            break;
        case ast::OperationType::NO_OP:
            std::cout << "NO OPERATION" << std::endl;
            return 0;
    }
    return 0;
}

bool backend::integrated_arithmetical_expression_evaluation::apply_logic_operation(ast::OperationType op_type, int lhs, int rhs) {
    switch (op_type) {
        case ast::OperationType::EQUALS:
            return lhs == rhs;
            break;
        case ast::OperationType::LESS_THAN:
            return lhs < rhs;
            break;
        case ast::OperationType::LESS_THAT_EQUAL:
            return lhs <= rhs;
            break;
        case ast::OperationType::GREATER_THAN:
            return lhs > rhs;
            break;
        case ast::OperationType::GREATER_THAN_EQUAL:
            return lhs >= rhs;
            break;
        case ast::OperationType::NO_OP:
            std::cout << "NO OPERATION" << std::endl;
            return false;
    }
    return false;
}
bool backend::integrated_arithmetical_expression_evaluation::apply_logic_operation(ast::OperationType op_type, bool lhs, bool rhs) {
    switch (op_type) {
        case ast::OperationType::EQUALS:
            return lhs == rhs;
            break;
        case ast::OperationType::NO_OP:
            std::cout << "NO OPERATION" << std::endl;
            return false;
    }
    return false;
}

ast::node_reference backend::evaluate_arithmetical_operation(std::shared_ptr<ast::Operation> operation) {
    if (typeid(*(operation->lhs)) == typeid(ast::Literal) && typeid(*(operation->rhs)) == typeid(ast::Literal)) {
        std::shared_ptr<ast::Literal> lhs = std::static_pointer_cast<ast::Literal>(operation->lhs);
        std::shared_ptr<ast::Literal> rhs = std::static_pointer_cast<ast::Literal>(operation->rhs);
        if (lhs->valueType == rhs->valueType) {
            if (operation->arithmatic_op) {
                const int calculation_result = backend::integrated_arithmetical_expression_evaluation::apply_arithmatic_operation(operation->opType, lhs->getInt(), rhs->getInt());
                ast::node_reference result = std::make_shared<ast::Literal>(calculation_result);
                return result;
            } else {
                bool calculation_result;
                if (lhs->valueType == ast::LiteralType::Bool) {
                    calculation_result = backend::integrated_arithmetical_expression_evaluation::apply_logic_operation(operation->opType, lhs->getBool(), rhs->getBool());
                } else {
                    calculation_result = backend::integrated_arithmetical_expression_evaluation::apply_logic_operation(operation->opType, lhs->getInt(), rhs->getInt());
                }
                ast::node_reference result = std::make_shared<ast::Literal>(calculation_result);
                return result;
            }
        }
    }
    return (ast::node_reference)operation;
}