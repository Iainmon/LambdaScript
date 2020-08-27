#include <iostream>
#include <map>

#include "antlr4-runtime.h"
#include "frontend/frontend.h"
#include "InterpreterVisitor.cpp"
#include "ast/ast.h"

using namespace antlr4;

struct Variable;

using HashMap = std::map<std::string, std::string>;
using string = std::string;

struct Object {};

struct Variable {
    std::string name;
    int value;
};

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
    print(ast->to_string());

    // std::string treeString = tree->toStringTree();
    // std::cout << treeString << std::endl;

    // tree::ParseTree *tree = parser.program();
    // TreeShapeListener listener;
    // tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

    return 0;
}