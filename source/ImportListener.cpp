#include "frontend/frontend.h"
#include <iostream>
#include <map>

class ImportVisitor : public lambdaBaseVisitor {
  public:
    // antlrcpp::Any visitApplication(lambdaParser::ApplicationContext *ctx) override {}
    // antlrcpp::Any visitPrint() {
    //   cout << dye::aqua(...) << endl;
    // }
    antlrcpp::Any visitImport(lambdaParser::ImportContext *ctx) override {
        if (ctx->Identifier() != nullptr) {
            const std::string filename = ctx->Identifier()->getText();
            std::ifstream stream;
            stream.open(filename);
            ANTLRInputStream input(stream);
            lambdaLexer lexer(&input);
            CommonTokenStream tokens(&lexer);
            lambdaParser parser(&tokens);
        }
    }
};