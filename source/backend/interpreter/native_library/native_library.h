#pragma once

#include "../../../ast/ast.h"
#include <chrono>
#include <memory>

namespace backend {
namespace interpreter {
namespace native_library {

class Exit : public ast::NativeAbstraction {
  public:
    Exit();
    ast::node_reference apply(ast::node_reference argument, ast::scope_reference scope) override;
    ast::node_reference execute_with_argument_queue(std::queue<ast::node_reference> arguments) override;
    std::string to_string() override;
    std::string pretty_print() override;
};

class Truthy : public ast::NativeAbstraction {
  public:
    Truthy();
    ast::node_reference apply(ast::node_reference argument, ast::scope_reference scope) override;
    ast::node_reference execute_with_argument_queue(std::queue<ast::node_reference> arguments) override;
    std::string to_string() override;
    std::string pretty_print() override;
};

class Typeof : public ast::NativeAbstraction {
  public:
    Typeof();
    ast::node_reference apply(ast::node_reference argument, ast::scope_reference scope) override;
    ast::node_reference execute_with_argument_queue(std::queue<ast::node_reference> arguments) override;
    std::string to_string() override;
    std::string pretty_print() override;
};

} // namespace native_library
} // namespace interpreter
} // namespace backend
