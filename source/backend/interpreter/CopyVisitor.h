#pragma once

#include "../NodeVisitor.h"

namespace backend {
    namespace interpreter {
        class CopyVisitor : public NodeVisitor {
            public:
            ast::node_reference visitLiteral(std::shared_ptr<ast::Literal>) override;
            ast::node_reference visitVariable(std::shared_ptr<ast::Variable>) override;
            ast::node_reference visitTypeNode(std::shared_ptr<ast::typesystem::TypeNode>) override;
        };
    }
}