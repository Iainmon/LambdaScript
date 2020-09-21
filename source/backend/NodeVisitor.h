#pragma once

#include "../ast/ast.h"
#include <memory>

namespace backend {
    class NodeVisitor : public std::enable_shared_from_this<NodeVisitor> {
        public:

        NodeVisitor();

        virtual ast::node_reference visitLiteral(std::shared_ptr<ast::Literal>);
        virtual ast::node_reference visitVariable(std::shared_ptr<ast::Variable>);
        virtual ast::node_reference visitApplication(std::shared_ptr<ast::Application>);
        virtual ast::node_reference visitAbstraction(std::shared_ptr<ast::Abstraction>);
        virtual ast::node_reference visitAssignment(std::shared_ptr<ast::Assignment>);
        virtual ast::node_reference visitArithmeticalOperation(std::shared_ptr<ast::Operation>);
        virtual ast::node_reference visitGrouping(std::shared_ptr<ast::Grouping>);
        virtual ast::node_reference visitNativeAbstraction(std::shared_ptr<ast::NativeAbstraction>);
        virtual ast::node_reference visitImportInstruction(std::shared_ptr<ast::ImportInstruction>);
        virtual ast::node_reference visitPrintInstruction(std::shared_ptr<ast::PrintInstruction>);
        virtual ast::node_reference visitGenericASTNode(std::shared_ptr<ast::ASTNode>);
        virtual ast::node_reference visitTypeNode(std::shared_ptr<ast::typesystem::TypeNode>);

    };

}