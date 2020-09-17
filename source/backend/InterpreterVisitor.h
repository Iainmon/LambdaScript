// This class will replace the evaluate function.
#ifndef INTERPRETER_VISITOR_H
#define INTERPRETER_VISITOR_H

#include "../ast/ast.h"
#include <stack>

namespace backend {
    // AKA EvaluationVisitor
    class InterpreterVisitor {
        private:
        void push_stack_frame();
        void pop_stack_frame();

        public:
        std::stack<ast::scope_reference> stack;

        InterpreterVisitor(ast::scope_reference scope);
        InterpreterVisitor();

        ast::node_reference visitLiteral(std::shared_ptr<ast::Literal>);
        ast::node_reference visitVariable(std::shared_ptr<ast::Variable>);
        ast::node_reference visitApplication(std::shared_ptr<ast::Application>);
        ast::node_reference visitAbstraction(std::shared_ptr<ast::Abstraction>);
        ast::node_reference visitAssignment(std::shared_ptr<ast::Assignment>);
        ast::node_reference visitArithmeticalOperation(std::shared_ptr<ast::Operation>);
        ast::node_reference visitGrouping(std::shared_ptr<ast::Grouping>);
        ast::node_reference visitNativeAbstraction(std::shared_ptr<ast::NativeAbstraction>);
        ast::node_reference visitImportInstruction(std::shared_ptr<ast::ImportInstruction>);
        ast::node_reference visitPrintInstruction(std::shared_ptr<ast::PrintInstruction>);
        ast::node_reference visitGenericASTNode(std::shared_ptr<ast::ASTNode>);

    };

}

#endif