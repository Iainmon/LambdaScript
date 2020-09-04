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

// class TreeShapeListener : public lambdaBaseListener {
//   private:
//     HashMap scope;

//   public:
//     void exitShow(lambdaParser::ShowContext *ctx) override {
//         if (ctx->INT() != nullptr) {
//             const std::string value = ctx->INT()->getText();
//             print(value);
//         } else if (ctx->VAR() != nullptr) {
//             const string name = ctx->VAR()->getText();
//             const string value = scope[name];
//             print(value);
//         }
//     }
//     void exitLet(lambdaParser::LetContext *ctx) override {
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
        // lambdaLexer lexer(&input);
        // CommonTokenStream tokens(&lexer);
        // lambdaParser parser(&tokens);

        // // Parsing
        // tree::ParseTree *tree = parser.program();

        // // AST Construction
        // language::InterpreterVisitor visitor;
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

    int last_group_count = 0;

    do {

        ast::node_reference ast = language::construct_syntax_tree(source.str());

        if (verbose_print)
            print(ast->to_string());

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
                    std::shared_ptr<ast::PrintInstruction> print_instruction = std::make_shared<ast::PrintInstruction>(last_node);
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

    } while (run_interactive_mode);

    return 0;
}