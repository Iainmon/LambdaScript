// #include <iostream>
// #include <map>
// #include <sstream>
// #include <string>
// #include <readline/readline.h>
// #include <readline/history.h>

// // GDB init command mac: set startup-with-shell off

// #include "antlr4-runtime.h"
// #include "frontend/frontend.h"
// #include "ast/ast.h"
// #include "language/language.h"
// #include "backend/backend.h"

// #include "argh.h"

// void print(const std::string &input) { std::cout << input << std::endl; }

// int main(int argc, const char *argv[]) {

//     argh::parser cmdl(argv);

//     std::string file_name;
//     cmdl(1, "program.la") >> file_name;

//     std::ifstream file_stream;
//     file_stream.open(file_name);

//     std::stringstream source;
//     if (file_stream)
//         source << file_stream.rdbuf() << std::endl;

//     const bool run_interactive_mode = !!cmdl[{"-i", "--interactive", "--repl"}];
//     const bool verbose_print = !!cmdl[{"--verbose"}];
//     const bool show_assoc = !!cmdl[{"--show-association"}];

//     bool main_file_done = false;

//     ast::scope_reference global_scope = std::make_shared<ast::Scope>();
//     ast::node_reference exit_abstraction = std::make_shared<language::native_functions::Exit>();
//     ast::node_reference truthy_abstraction = std::make_shared<language::native_functions::Truthy>();
//     ast::node_reference sum_abstraction = std::make_shared<language::native_functions::Sum>();
//     ast::node_reference reduce_abstraction = std::make_shared<language::native_functions::Reduce>();
//     ast::node_reference typeof_abstraction = std::make_shared<language::native_functions::Typeof>();
//     ast::node_reference time_abstraction = std::make_shared<language::native_functions::Time>();
//     global_scope->set("exit", exit_abstraction);
//     global_scope->set("truthy", truthy_abstraction);
//     global_scope->set("sum", sum_abstraction);
//     global_scope->set("reduce", reduce_abstraction);
//     global_scope->set("typeof", typeof_abstraction);
//     global_scope->set("time", time_abstraction);

//     int last_group_count = 0;

//     do {

//         ast::node_reference ast = language::construct_syntax_tree(source.str());

//         if (verbose_print)
//             print(ast->to_string());
//         // ast::scope_reference program_scope = std::make_shared<ast::Scope>(*global_scope);
//         std::unique_ptr<backend::InterpreterVisitor> interpreter = std::make_unique<backend::InterpreterVisitor>(global_scope);
//         ast::node_reference evaluated_ast = ast->accept(interpreter.get());

//         if (verbose_print)
//             print(evaluated_ast->to_string());
            
//         if (evaluated_ast->type == ast::ASTNodeType::GROUPING) {
//             std::shared_ptr<ast::Grouping> grouping = std::static_pointer_cast<ast::Grouping>(evaluated_ast);
//             if (!grouping->nodes.empty()) {
//                 if (last_group_count != grouping->nodes.size()) {
//                     ast::node_reference last_node = grouping->nodes.back();
//                     ast::node_reference print_instruction = std::make_shared<ast::PrintInstruction>(last_node);
//                     language::evaluate(print_instruction, global_scope);
//                     // print(grouping->nodes.back()->to_string());
//                     last_group_count = grouping->nodes.size();
//                 }
//             }
//         }
        
//         if (!run_interactive_mode)
//             return 0;

//         if (!main_file_done)
//             main_file_done = true;

//         std::string input_line;
//         getline(std::cin, input_line);
//         if (input_line.compare(":q\n") == 0)
//             return 0;
//         source << input_line << std::endl;
//         // std::string myGraphJson = "{\"kind\":{\"graph\":true},"
//         // "\"nodes\":[{\"id\":\"1\"},{\"id\":\"2\"}],"
//         // "\"edges\":[{\"from\":\"1\",\"to\":\"2\"}]}";
//         // std::cout << myGraphJson;

//     } while (run_interactive_mode);

//     return 0;
// }