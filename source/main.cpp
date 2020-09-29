#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <readline/readline.h>
#include <readline/history.h>

// GDB init command mac: set startup-with-shell off

#include "antlr4-runtime.h"
#include "frontend/frontend.h"
#include "ast/ast.h"
#include "language/language.h"
#include "backend/backend.h"
#include "backend/interpreter/native_library/native_library.h"
#include "tools/format.h"

#include "argh.h"

void print(const std::string &input) { std::cout << input << std::endl; }

int compile(const std::string &source, const std::string &out_file_name) {
    backend::codegen::CodeGenerationVisitor code_gen;

    ast::node_reference ast = language::construct_syntax_tree(source);
    ast->accept(&code_gen);
    const std::string generated_source = code_gen.source.str();

    std::ofstream out_file;
    out_file.open(out_file_name);
    out_file << generated_source;
    out_file.close();

    std::cout << green << "Output file written to " << Bgreen << out_file_name << green << "." << reset<< std::endl;

    return 0;
}

void format_file(const std::string &file_name) {
    std::ifstream input_stream;
    std::ofstream output_stream;
    std::stringstream contents;

    input_stream.open(file_name);
    contents << input_stream.rdbuf() << std::endl;
    input_stream.close();

    output_stream.open(file_name);
    output_stream << tools::format_lambda_symbols(contents.str());
    output_stream.close();
}

int main(int argc, const char *argv[]) {

    argh::parser cmdl(argv);

    std::string file_name;
    cmdl(1) >> file_name;

    if (file_name.empty())
        std::cout << "No input file was provided." << std::endl;

    std::ifstream file_stream;
    file_stream.open(file_name);

    std::stringstream source;
    if (file_stream)
        source << file_stream.rdbuf() << std::endl;

    const bool run_interactive_mode = !!cmdl[{"-i", "--interactive", "--repl"}];
    const bool verbose_print = !!cmdl[{"--verbose"}];
    const bool show_assoc = !!cmdl[{"--show-association"}];
    const bool format_document = !!cmdl[{"--format"}];

    std::string out_file_name;
    if (cmdl({"-o", "--out"}) >> out_file_name) {
        return compile(source.str(), out_file_name);
    }

    if (format_document) {
        format_file(file_name);
    }

    bool main_file_done = false;

    // ast::scope_reference global_scope = std::make_shared<ast::Scope>();
    // ast::node_reference exit_abstraction = std::make_shared<backend::interpreter::native_library::Exit>();
    // ast::node_reference truthy_abstraction = std::make_shared<backend::interpreter::native_library::Truthy>();
    // ast::node_reference typeof_abstraction = std::make_shared<backend::interpreter::native_library::Typeof>();
    // global_scope->set("exit", exit_abstraction);
    // global_scope->set("truthy", truthy_abstraction);
    // global_scope->set("typeof", typeof_abstraction);


    ast::scope_reference global_scope = std::make_shared<ast::Scope>();

    std::shared_ptr<ast::NativeAbstraction> exit_abstraction = std::make_shared<backend::interpreter::native_library::Exit>();
    ast::node_reference native_exit = std::make_shared<backend::interpreter::Curried>(exit_abstraction, 1);
    std::shared_ptr<ast::NativeAbstraction> truthy_abstraction = std::make_shared<backend::interpreter::native_library::Truthy>();
    ast::node_reference native_truthy = std::make_shared<backend::interpreter::Curried>(truthy_abstraction, 1);
    std::shared_ptr<ast::NativeAbstraction> typeof_abstraction = std::make_shared<backend::interpreter::native_library::Typeof>();
    ast::node_reference native_typeof = std::make_shared<backend::interpreter::Curried>(typeof_abstraction, 1);
    global_scope->set("exit", native_exit);
    // global_scope->set("truthy", native_truthy);
    global_scope->set("typeof", native_typeof);

    int last_group_count = 0;



    do {

        ast::node_reference ast = language::construct_syntax_tree(source.str());

        if (verbose_print)
            print(ast->to_string());

        std::unique_ptr<backend::interpreter::InterpreterVisitor> interpreter = std::make_unique<backend::interpreter::InterpreterVisitor>(global_scope);
        ast::node_reference evaluated_ast = ast->accept(interpreter.get());
        // ast::node_reference evaluated_ast = backend::interpreter::interpret_syntax_tree(ast, global_scope);

        if (verbose_print)
            print(evaluated_ast->to_string());
            
        if (typeid(*evaluated_ast) == typeid(ast::Grouping)) {
            std::shared_ptr<ast::Grouping> grouping = std::static_pointer_cast<ast::Grouping>(evaluated_ast);
            if (!grouping->nodes.empty() && last_group_count != grouping->nodes.size()) {
                ast::node_reference last_node = grouping->nodes.back();
                ast::node_reference print_instruction = std::make_shared<ast::PrintInstruction>(last_node);
                language::evaluate(print_instruction->accept(interpreter.get()), global_scope);
                // print_instruction->accept(interpreter.get());
                // print(grouping->nodes.back()->to_string());
                last_group_count = grouping->nodes.size();
            }
        }
        
        if (!run_interactive_mode)
            return 0;

        if (!main_file_done)
            main_file_done = true;

        std::cout << yellow << "λ" << blue << " ] " << reset;
        std::string input_line;
        getline(std::cin, input_line);
        if (input_line.compare(":q\n") == 0)
            return 0;
        if (input_line.compare(":write\n") == 0) {
            std::ofstream write_out_file;
            write_out_file.open(file_name);
            write_out_file << source.str();
            write_out_file.close();
        }
        source << input_line << std::endl;
        // std::string myGraphJson = "{\"kind\":{\"graph\":true},"
        // "\"nodes\":[{\"id\":\"1\"},{\"id\":\"2\"}],"
        // "\"edges\":[{\"from\":\"1\",\"to\":\"2\"}]}";
        // std::cout << myGraphJson;

    } while (run_interactive_mode);

    return 0;
}