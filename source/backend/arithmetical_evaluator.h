#pragma once

#include "../ast/ast.h"

namespace backend {
    namespace integrated_arithmetical_expression_evaluation {
        int apply_arithmatic_operation(ast::OperationType, int, int);
        bool apply_logic_operation(ast::OperationType, int, int);
        bool apply_logic_operation(ast::OperationType, bool, bool);
    }
    ast::node_reference evaluate_arithmetical_operation(std::shared_ptr<ast::Operation> operation);
}