#include "Curried.h"

backend::interpreter::Curried::Curried(std::shared_ptr<ast::NativeAbstraction> _target_native_abstraction, const int &_argument_count) {
    type = ast::ASTNodeType::ABSTRACTION;
    target_native_abstraction = _target_native_abstraction;
    argument_count = argument_count;
}
std::shared_ptr<backend::interpreter::Curried> backend::interpreter::Curried::apply_argument(ast::node_reference argument) {
    arguments.push(argument);
    std::shared_ptr<backend::interpreter::Curried> self = std::static_pointer_cast<backend::interpreter::Curried>(shared_from_this());
    return self;
}
ast::node_reference backend::interpreter::Curried::accept(backend::NodeVisitor* visitor) {
    if (arguments.size() > argument_count) {
        return target_native_abstraction->execute_with_argument_queue(arguments)->accept(visitor);
    } else {
        
        ast::node_reference generic_self = shared_from_this();

        if (typeid(*visitor) == typeid(backend::interpreter::InterpreterVisitor)) {
            std::shared_ptr<backend::interpreter::Curried> self = std::static_pointer_cast<backend::interpreter::Curried>(generic_self);
            backend::interpreter::InterpreterVisitor* interpreter_visitor = static_cast<backend::interpreter::InterpreterVisitor*>(visitor);
            return interpreter_visitor->visitCurried(self);
        } else {
            // return visitor->visitGenericASTNode(generic_self);
            // return generic_self;
            return target_native_abstraction->accept(visitor);
        }
    }
}
std::string backend::interpreter::Curried::pretty_print() {
    return target_native_abstraction->pretty_print();
}