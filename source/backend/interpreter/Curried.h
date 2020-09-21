#pragma once

#include "../../ast/ast.h"
#include "InterpreterVisitor.h"
#include <queue>
#include <memory>

namespace backend {
    namespace interpreter {
        // What will this do? How will this work?
        //  This will allow arguments to be provided and stored until the required amount is met, and the native abstraction can be executed.
        //  1) Each object will store a reference to the native abstraction to be executed. It will also store an empty list of size n, where n is the parameter count of the native abstraction args.
        //      It will also implement a function that will create an AST tree, providing the native abstraction, and the provided args. Example: (\b.(truthy t) b) where t is a free term.
        class Curried : public ast::ASTNode {
            int argument_count;
            std::shared_ptr<ast::NativeAbstraction> target_native_abstraction;
            std::queue<ast::node_reference> arguments;
            
            public:
            Curried(std::shared_ptr<ast::NativeAbstraction> _target_native_abstraction, const int &_argument_count);
            std::shared_ptr<backend::interpreter::Curried> apply_argument(ast::node_reference);
            ast::node_reference accept(backend::NodeVisitor*) override;
            std::string pretty_print() override;
        };
    }
}