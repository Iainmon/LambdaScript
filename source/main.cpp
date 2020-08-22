#include <iostream>
#include <map>

#include "antlr4-runtime.h"
#include "frontend/frontend.h"

using namespace antlr4;

struct Variable;

using HashMap = std::map<std::string, std::string>;
using string = std::string;

struct Object {

};

struct Variable {
    std::string name;
    int value;
};

void print(const std::string &input) {
    std::cout << input << std::endl;
}

class TreeShapeListener : public lambdaBaseListener {
  private:
    HashMap scope;
  public:
    void enterShow(lambdaParser::ShowContext *ctx) override {
        if (ctx->INT() != nullptr) {
            const std::string value = ctx->INT()->getText();
            print(value);
        } else if (ctx->VAR() != nullptr) {
            const string value = scope[value];
            print(value);
        }
    }
};

int main(int argc, const char *argv[]) {
    std::ifstream stream;
    stream.open(argv[1]);
    ANTLRInputStream input(stream);
    lambdaLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    lambdaParser parser(&tokens);

    tree::ParseTree *tree = parser.program();
    TreeShapeListener listener;
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

    return 0;
}