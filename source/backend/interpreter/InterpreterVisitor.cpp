#include "InterpreterVisitor.h"
#include "BetaReductionVisitor.h"
#include "logic/arithmetical_evaluator.h"

backend::interpreter::InterpreterVisitor::InterpreterVisitor() {
    ast::scope_reference scope = std::make_shared<ast::Scope>();
    stack.push(scope);
}
backend::interpreter::InterpreterVisitor::InterpreterVisitor(ast::scope_reference scope) {
    stack.push(scope);
}

ast::node_reference backend::interpreter::InterpreterVisitor::visitLiteral(std::shared_ptr<ast::Literal> literal) {
    // std::cout << "[lit] " << literal->pretty_print() << std::endl;
    return literal;
}
ast::node_reference backend::interpreter::InterpreterVisitor::visitVariable(std::shared_ptr<ast::Variable> variable) {
    // Lazy evaluation. Returns the node without that was referenced, without evaluating it.
    // return stack.top()->get(variable->identifier);
    // Other?
    // std::cout << "[var] " << variable->pretty_print() << std::endl;
    
    // Coppies the value referenced.
    return stack.top()->get(variable->identifier);// ->accept(&copy_visitor);
}
ast::node_reference backend::interpreter::InterpreterVisitor::visitAssignment(std::shared_ptr<ast::Assignment> assignment) {
    ast::node_reference value = assignment->value->accept(this);
    if (!stack.top()->has(assignment->identifier)) {
        stack.top()->set(assignment->identifier, value);
    }
    // Walrus operator like
    return value;

    // Whatever I am doing. This is bad because it allows for functions to declare variables.
    // return (ast::node_reference)assignment;
}
ast::node_reference backend::interpreter::InterpreterVisitor::visitApplication(std::shared_ptr<ast::Application> application) {
    // std::cout << "[app] " << application->pretty_print() << std::endl;
    ast::node_reference reduced_lhs = application->lhs->accept(this);
    // std::cout << "Is this code even being called? " << typeid(*reduced_lhs).name() << std::endl;
    if (typeid(*reduced_lhs) == typeid(backend::interpreter::Curried)) {
        std::shared_ptr<backend::interpreter::Curried> curried = std::static_pointer_cast<backend::interpreter::Curried>(reduced_lhs);
        ast::node_reference reduced_rhs = application->rhs->accept(this);
        if (typeid(*reduced_rhs) == typeid(ast::Variable)) {
            return application;
        }
        return curried->apply_argument(reduced_rhs)->accept(this);
    }
    if (!(typeid(*reduced_lhs) == typeid(ast::Abstraction))) {
        if (typeid(*reduced_lhs) == typeid(ast::Literal) || typeid(*reduced_lhs) == typeid(ast::Grouping)) {
            std::shared_ptr<ast::Grouping> grouping = std::make_shared<ast::Grouping>();
            grouping->nodes.push_back(reduced_lhs);
            grouping->nodes.push_back(application->rhs->accept(this));
            return (ast::node_reference)grouping;
        }
        std::cout << typeid(*reduced_lhs).name() << std::endl; 
        ast::node_reference preserved_application = std::make_shared<ast::Application>(application->lhs->accept(this), application->rhs->accept(this));
        return preserved_application;
    }

    std::shared_ptr<ast::Abstraction> lhs = std::static_pointer_cast<ast::Abstraction>(reduced_lhs);
    ast::node_reference rhs = application->rhs->accept(this);

    // Pushes a new stack frame
    ast::scope_reference scope = std::make_shared<ast::Scope>(*(stack.top()));
    scope->set(lhs->argument, rhs);
    stack.push(scope);
    // Applies the argument, β-reduction
    backend::interpreter::BetaReductionVisitor beta_reducer(scope);
    ast::node_reference normal_expression = lhs->body->accept(&beta_reducer)->accept(this);
    // Pops the stack frame
    stack.pop();

    // Returns normal, non-reducible expression
    return normal_expression;
}
ast::node_reference backend::interpreter::InterpreterVisitor::visitAbstraction(std::shared_ptr<ast::Abstraction> abstraction) {
    // std::cout << "[abs] " << abstraction->pretty_print() << std::endl;
    return abstraction;
}
ast::node_reference backend::interpreter::InterpreterVisitor::visitArithmeticalOperation(std::shared_ptr<ast::Operation> operation) {
    // The Operation ASTNode should be converted to a NativeAbstraction
    std::shared_ptr<ast::Operation> op = std::make_shared<ast::Operation>(operation->opType, operation->lhs->accept(this), operation->rhs->accept(this));
    op->operation_character = operation->operation_character;
    ast::node_reference operation_result = backend::evaluate_arithmetical_operation(op);
    return operation_result;
}
ast::node_reference backend::interpreter::InterpreterVisitor::visitCondition(std::shared_ptr<ast::Condition> condition) {
    ast::node_reference con = condition->condition->accept(this);
    bool truthy;
    if (typeid(*con) == typeid(ast::Literal)) {
        std::shared_ptr<ast::Literal> literal = std::static_pointer_cast<ast::Literal>(con);
        if (literal->valueType == ast::LiteralType::Int) {
            truthy = literal->getInt() > 0;
        } else if (literal->valueType == ast::LiteralType::Bool) {
            truthy = literal->getBool();
        } else if (literal->valueType == ast::LiteralType::Nil) {
            truthy = false;
        } else {
            truthy = false;
        }
    } else {
        truthy = false;
    }
    return truthy ? condition->consequent->accept(this) : condition->alternative->accept(this);
}
ast::node_reference backend::interpreter::InterpreterVisitor::visitNativeAbstraction(std::shared_ptr<ast::NativeAbstraction> native_abstraction) {
    // Will call the native_abstractions .apply() method, where it will construct an AST tree
    // Sometimes the use of a new Curryable object will be used to keep track of previously provided arguments, until all are met, and the expression can be executed internally.
    // For example, the add function (+) will need to do this. Exit will not. Print will not.
    // std::cout << "[nab] " << native_abstraction->pretty_print() << std::endl;
    return native_abstraction;
}
ast::node_reference backend::interpreter::InterpreterVisitor::visitCurried(std::shared_ptr<backend::interpreter::Curried> curried) {
    // std::cout << "[cur] " << curried->pretty_print() << std::endl;
    return curried;
}
ast::node_reference backend::interpreter::InterpreterVisitor::visitImportInstruction(std::shared_ptr<ast::ImportInstruction> import_instruction) {
    return import_instruction;
}
ast::node_reference backend::interpreter::InterpreterVisitor::visitPrintInstruction(std::shared_ptr<ast::PrintInstruction> print_instruction) {
    ast::node_reference value = print_instruction->value->accept(this);
    std::cout << magenta << "λ -> " << reset << value->pretty_print() << std::endl;
    return value;
}
ast::node_reference backend::interpreter::InterpreterVisitor::visitGrouping(std::shared_ptr<ast::Grouping> grouping) {
    std::shared_ptr<ast::Grouping> evaluated_grouping = std::make_shared<ast::Grouping>();
    for (ast::node_reference &node : grouping->nodes) {
        ast::node_reference evaluated_node = node->accept(this);
        // evaluated_grouping->nodes.push_back(evaluated_node);
        node = evaluated_node;
    }
    // return (ast::node_reference)evaluated_grouping;
    return grouping;
}

ast::node_reference backend::interpreter::InterpreterVisitor::visitGenericASTNode(std::shared_ptr<ast::ASTNode> ast_node) {
    std::cout << "GENERIC" << ast_node->pretty_print() << std::endl;
    return ast_node;
}

void backend::interpreter::InterpreterVisitor::push_stack_frame() {
    ast::scope_reference scope = std::make_shared<ast::Scope>(*(stack.top()));
    stack.push(scope);
}
void backend::interpreter::InterpreterVisitor::pop_stack_frame() {
    stack.pop();
}