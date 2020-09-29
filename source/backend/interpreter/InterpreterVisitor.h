// This class will replace the evaluate function.
#pragma once

#include "../NodeVisitor.h"
#include "CopyVisitor.h"
#include "Curried.h"
#include <stack>

namespace backend {
// AKA EvaluationVisitor
namespace interpreter {
class Curried;
class InterpreterVisitor : public NodeVisitor {
  private:
    CopyVisitor copy_visitor;
    void push_stack_frame();
    void pop_stack_frame();

  public:
    std::stack<ast::scope_reference> stack;

    InterpreterVisitor(ast::scope_reference scope);
    InterpreterVisitor();

    ast::node_reference visitLiteral(std::shared_ptr<ast::Literal>) override;
    ast::node_reference visitVariable(std::shared_ptr<ast::Variable>) override;
    ast::node_reference visitApplication(std::shared_ptr<ast::Application>) override;
    ast::node_reference visitAbstraction(std::shared_ptr<ast::Abstraction>) override;
    ast::node_reference visitAssignment(std::shared_ptr<ast::Assignment>) override;
    ast::node_reference visitArithmeticalOperation(std::shared_ptr<ast::Operation>) override;
    ast::node_reference visitGrouping(std::shared_ptr<ast::Grouping>) override;
    ast::node_reference visitNativeAbstraction(std::shared_ptr<ast::NativeAbstraction>) override;
    ast::node_reference visitCondition(std::shared_ptr<ast::Condition>) override;
    ast::node_reference visitImportInstruction(std::shared_ptr<ast::ImportInstruction>) override;
    ast::node_reference visitPrintInstruction(std::shared_ptr<ast::PrintInstruction>) override;
    ast::node_reference visitGenericASTNode(std::shared_ptr<ast::ASTNode>) override;
    ast::node_reference visitCurried(std::shared_ptr<backend::interpreter::Curried>);
};
} // namespace interpreter
} // namespace backend