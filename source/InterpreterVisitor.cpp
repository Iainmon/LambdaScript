#include "frontend/frontend.h"
#include "color.hpp"

struct Value {
  string value;
  string name;
  *Type type;
}

map<string, Value> assigned;

class InterpreterVisitor : public lambdaBaseVisitor {
  public:
    antlrcpp::Any visitApplication(lambdaParser::ApplicationContext *ctx) override {}
    antlrcpp::Any visitPrint(...) {
      cout << dye::aqua(...) << endl;
    }
};