#include "frontend/frontend.h"
#include <iostream>
#include <memory>

using namespace std;

class Scope;

class Value {
    string name;
    string value;
};

class Abstraction : public Value {
  public:
    string argumentName;
    lambdaParser::ExpressionContext *body;
    shared_ptr<Scope> scope; // Also known as closure

    Abstraction(const string &_argumentName, lambdaParser::ExpressionContext *_body, shared_ptr<Scope> _scope) {
        argumentName = _argumentName;
        body = _body;
        scope = _scope;
    }
};

class Application : public Value {
  public:
    shared_ptr<Abstraction> lhs;
    shared_ptr<Value> rhs;

    Application(shared_ptr<Abstraction> leftHandSide, shared_ptr<Value> rightHandSide) {
        lhs = leftHandSide;
        rhs = rightHandSide;
    }
};

enum LiteralType {
    BOOL, INTEGER
};

class Literal : public Value {
    private:
    public:
    bool bval;
    int ival;
    LiteralType type;
    Literal(bool val) {
        bval = val;
        type = BOOL;
    }
    Literal(int val) {
        ival = val;
        type = INTEGER;
    }
};

class Scope {
  private:
    map<string, Value> scope;
    Scope(const &map<string, Value> _scope) { scope = _scope; }

  public:
    Scope();
    shared_ptr<Scope> copy() {
        shared_ptr<Scope> duplicate = make_shared<Scope>(scope);
        return duplicate;
    }
    shared_ptr<Scope> set(const string name, const &Value value) {
        map<string, Value> scopes = scope;
        scopes[name] = value;
        return copy(scopes);
    }
    shared_ptr<Value> get(const &string name) {
        shared_ptr<Value> value(scope[name]);
        return value;
    }
    bool has(const &string name) { return !(scope.find(name) == scope.end()); }
};

class InterpreterVisitor : public lambdaBaseVisitor {
  private:
  public:
    map<string, Value> assigned;

    antlrcpp::Any visitApplication(lambdaParser::ApplicationContext *ctx) override {
        // Apply β-reduction
        // shared_ptr<InterpreterVisitor> visitor;
        // return callee.getBody().accept(visitor.get());

        shared_ptr<Abstraction> lhs(ctx->expression(0)->accept(this));
        shared_ptr<Value> rhs(ctx->expression(1)->accept(this));
        shared_ptr<Application> application(lhs, rhs);
        return application;
    }

    antlrcpp::Any visitVariable(lambdaParser::VariableContext *ctx) override {
        const string name = ctx->Identifier()->getText();
        return assigned[name];
    }

    antlrcpp::Any visitLiteral(lambdaParser::LiteralContext *ctx) override {
        if (ctx->Int() != nullptr) {
            const int value = stoi(ctx->Int()->getText());
            return shared_ptr<Literal>(value);
        }

        string booleanLiteral = string(ctx->Bool()->getText());
        switch (booleanLiteral) {
        case "tru":
        case "true":
            return shared_ptr<Literal>(true);
        case "fls":
        case "false":
            return shared_ptr<Literal>(false);
        }
        return nullptr;
    }

    antlrcpp::Any visitAssign(lambdaParser::AssignContext *ctx) override {
        const string name = ctx->Identifier()->getText();
        const Value value = ctx->expression()->accept(this);
        assigned[name] = value;
    }

    antlrcpp::Any visitBinaryExpression(lambdaParser::BinaryExpressionContext *ctx) override {
        const int left = ctx->expression(0)->accept(this);
        const int right = ctx->expression(1)->accept(this);
        const string operator = ctx->Operator()->getText();

        switch (operator) {
        case "+":
            return left + right;
        case "-":
            return left - right;
        case "*":
            return left * right;
        case "/":
            return left / right;
        case "<":
            return left < right;
        case ">":
            return left > right;
        case "<=":
            return left <= right;
        case ">=":
            return left >= right;
        case "==":
            return left == right;
        default:
            return nullptr;
        }
    }

    // Atom
    antlrcpp::Any visitBrackets(lambdaParser::BracketsContext *ctx) override { return ctx->expression()->accept(this); }

    // Print should be a listnener
    // antlrcpp::Any visitPrint(lambdaParser::PrintInstructionContext *ctx) override {
    //   cout << dye::aqua() << endl;
    // }

    // visitImport(*ctx) {
    //     filename = ...
    //     parsed = parse(lex(pipe(filename)))
    //     return visit(parsed);
    // }
};