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

#include "argh.h"


void print(const std::string &input) { std::cout << input << std::endl; }

// class TreeShapeListener : public LanguageBaseListener {
//   private:
//     HashMap scope;

//   public:
//     void exitShow(LanguageParser::ShowContext *ctx) override {
//         if (ctx->INT() != nullptr) {
//             const std::string value = ctx->INT()->getText();
//             print(value);
//         } else if (ctx->VAR() != nullptr) {
//             const string name = ctx->VAR()->getText();
//             const string value = scope[name];
//             print(value);
//         }
//     }
//     void exitLet(LanguageParser::LetContext *ctx) override {
//         const string name = ctx->VAR()->getText();
//         const string value = ctx->INT()->getText();
//         scope[name] = value;
//     }
// };

void run_loop(const std::string &pre_load = "") {
    std::stringstream ss;
    while (true) {
        std::string input_line;
        getline(std::cin, input_line);
        ss << input_line << std::endl;
        // // ANTLRInputStream input(input_line);
        // ANTLRInputStream input(ss.str());
        // LanguageLexer lexer(&input);
        // CommonTokenStream tokens(&lexer);
        // LanguageParser parser(&tokens);

        // // Parsing
        // tree::ParseTree *tree = parser.program();

        // // AST Construction
        // language::ConstructorVisitor visitor;
        // ast::node_reference ast = visitor.visit(tree);
        ast::node_reference ast = language::construct_syntax_tree(ss.str());
        print("-- Constructed AST --");
        print(ast->to_string());
        
        // Evaluation
        ast::scope_reference global_scope = make_shared<ast::Scope>();
        ast::node_reference evaluated_ast = language::evaluate(ast, global_scope);
        // if (evaluated_ast->type == ast::ASTNodeType::GROUPING) {
        //     shared_ptr<ast::Grouping> grouping = make_shared<ast::Grouping>();
        //     if (!grouping->nodes.empty()) {
        //         print(grouping->nodes.front()->to_string());
        //     } // else {
        //         print(grouping->to_string());
        //     // }
        // } else {
            print("-- Evaluated AST --");
            print(evaluated_ast->to_string());
        // }
    }
}

int main(int argc, const char *argv[]) {

    argh::parser cmdl(argv);

    std::string file_name;
    cmdl(1, "program.la") >> file_name;

    std::ifstream file_stream;
    file_stream.open(file_name);

    std::stringstream source;
    if (file_stream)
        source << file_stream.rdbuf() << std::endl;

    const bool run_interactive_mode = !!cmdl[{"-i", "--interactive", "--repl"}];
    const bool verbose_print = !!cmdl[{"--verbose"}];
    const bool show_assoc = !!cmdl[{"--show-association"}];

    bool main_file_done = false;

    ast::scope_reference global_scope = make_shared<ast::Scope>();
    ast::node_reference exit_abstraction = make_shared<language::native_functions::Exit>();
    ast::node_reference truthy_abstraction = make_shared<language::native_functions::Truthy>();
    ast::node_reference sum_abstraction = make_shared<language::native_functions::Sum>();
    ast::node_reference reduce_abstraction = make_shared<language::native_functions::Reduce>();
    ast::node_reference typeof_abstraction = make_shared<language::native_functions::Typeof>();
    ast::node_reference time_abstraction = make_shared<language::native_functions::Time>();
    global_scope->set("exit", exit_abstraction);
    global_scope->set("truthy", truthy_abstraction);
    global_scope->set("sum", sum_abstraction);
    global_scope->set("reduce", reduce_abstraction);
    global_scope->set("typeof", typeof_abstraction);
    global_scope->set("time", time_abstraction);

    int last_group_count = 0;

    do {

        ast::node_reference ast = language::construct_syntax_tree(source.str());

        if (verbose_print)
            print(ast->to_string());
        // ast::scope_reference program_scope = std::make_shared<ast::Scope>(*global_scope);
        ast::node_reference evaluated_ast = language::evaluate(ast, global_scope);

        if (verbose_print)
            print(evaluated_ast->to_string());
        
        if (!run_interactive_mode)
            return 0;

        if (!main_file_done)
            main_file_done = true;

        if (evaluated_ast->type == ast::ASTNodeType::GROUPING) {
            std::shared_ptr<ast::Grouping> grouping = std::static_pointer_cast<ast::Grouping>(evaluated_ast);
            if (!grouping->nodes.empty()) {
                if (last_group_count != grouping->nodes.size()) {
                    ast::node_reference last_node = grouping->nodes.back();
                    ast::node_reference print_instruction = std::make_shared<ast::PrintInstruction>(last_node);
                    language::evaluate(print_instruction, global_scope);
                    // print(grouping->nodes.back()->to_string());
                    last_group_count = grouping->nodes.size();
                }
            }
        }

        std::string input_line;
        getline(std::cin, input_line);
        if (input_line.compare(":q\n") == 0)
            return 0;
        source << input_line << std::endl;
        // std::string myGraphJson = "{\"kind\":{\"graph\":true},"
        // "\"nodes\":[{\"id\":\"1\"},{\"id\":\"2\"}],"
        // "\"edges\":[{\"from\":\"1\",\"to\":\"2\"}]}";
        // std::cout << myGraphJson;

    } while (run_interactive_mode);

    return 0;
}