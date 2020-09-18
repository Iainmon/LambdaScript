// This class will replace the evaluate function.
#pragma once

#include "../NodeVisitor.h"
#include <sstream>
#include <string>

namespace backend {
    namespace codegen {
        class CodeGenerationVisitor : public NodeVisitor {
            private:
            public:
            std::stringstream source;

            CodeGenerationVisitor();

            ast::node_reference visitLiteral(std::shared_ptr<ast::Literal>) override;
            ast::node_reference visitVariable(std::shared_ptr<ast::Variable>) override;
            ast::node_reference visitApplication(std::shared_ptr<ast::Application>) override;
            ast::node_reference visitAbstraction(std::shared_ptr<ast::Abstraction>) override;
            ast::node_reference visitAssignment(std::shared_ptr<ast::Assignment>) override;
            ast::node_reference visitArithmeticalOperation(std::shared_ptr<ast::Operation>) override;
            ast::node_reference visitGrouping(std::shared_ptr<ast::Grouping>) override;
            ast::node_reference visitNativeAbstraction(std::shared_ptr<ast::NativeAbstraction>) override;
            // ast::node_reference visitImportInstruction(std::shared_ptr<ast::ImportInstruction>) override;
            ast::node_reference visitPrintInstruction(std::shared_ptr<ast::PrintInstruction>) override;
            // ast::node_reference visitGenericASTNode(std::shared_ptr<ast::ASTNode>) override;

        };
    }
}
