#include <iostream>
#include <map>
#include <sstream>
#include <string>

// GDB init command mac: set startup-with-shell off

#include "antlr4-runtime.h"
#include "frontend/frontend.h"
#include "InterpreterVisitor.cpp"
#include "ast/ast.h"


#include "argh.h"

using namespace antlr4;

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

void run_loop() {
    std::stringstream ss;
    while (true) {
        std::string input_line;
        getline(std::cin, input_line);
        ss << input_line << std::endl;
        // ANTLRInputStream input(input_line);
        ANTLRInputStream input(ss.str());
        lambdaLexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        lambdaParser parser(&tokens);

        // Parsing
        tree::ParseTree *tree = parser.program();

        // AST Construction
        InterpreterVisitor visitor;
        ast::node_reference ast = visitor.visit(tree);
        // ast::node_reference ast = ast::construct_syntax_tree(ss.str());
        print("-- Constructed AST --");
        print(ast->to_string());
        
        // Evaluation
        ast::scope_reference global_scope = make_shared<ast::Scope>();
        ast::node_reference evaluated_ast = ast::evaluate(ast, global_scope);
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
    std::ifstream stream;
    stream.open(argv[1]);
    ANTLRInputStream input(stream);
    print("Lexing...");
    lambdaLexer lexer(&input);
    print("Parsing...");
    CommonTokenStream tokens(&lexer);
    lambdaParser parser(&tokens);

    tree::ParseTree *tree = parser.program();
    std::wstring s = antlrcpp::s2ws(tree->toStringTree(&parser)) + L"\n";
    std::wcout << "Parse Tree: " << s << std::endl;

    print("Interpreting...");
    InterpreterVisitor visitor;
    ast::node_reference ast = visitor.visit(tree);
    print("-- Abstract Syntax Tree --");
    print(ast->to_string());

    run_loop();

    // std::string treeString = tree->toStringTree();
    // std::cout << treeString << std::endl;

    // tree::ParseTree *tree = parser.program();
    // TreeShapeListener listener;
    // tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

    return 0;
}