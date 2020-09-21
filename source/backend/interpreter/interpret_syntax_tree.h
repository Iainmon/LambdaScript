#pragma once

#include "../../ast/ast.h"

namespace backend {
    namespace interpreter {
        ast::node_reference interpret_syntax_tree(ast::node_reference, ast::scope_reference);
    }
}