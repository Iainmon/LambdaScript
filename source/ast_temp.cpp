#include <iostream>
#include <map>
#include <memory>
#include <string>

#include <switch>

using namespace std;

namespace ast {
string bool_as_text(const bool &b) {
    return b ? "true" : "false";
}
bool text_as_bool(const string &b) {
    if (b.compare("true") == 0) {
        return true;
    }
    return false;
}

enum ASTNodeType { MAIN, ABSTRACTION, APPLICATION, CONDITION, PRINT, VARIABLE, OPERATION, LITERAL };
class ASTNode {
  public:
    ASTNodeType type;
};
class Scope;
using node_reference = shared_ptr<ASTNode>;
using scope_reference = shared_ptr<Scope>;

class Scope {
  private:
    map<string, ASTNode> scope;
    shared_ptr<Scope> copy(const map<string, ASTNode> &_scope) {
        shared_ptr<Scope> duplicate = make_shared<Scope>(_scope);
        return duplicate;
    }

  public:
    Scope();
    Scope(const map<string, ASTNode> &_scope) { scope = _scope; }
    shared_ptr<Scope> copy() {
        shared_ptr<Scope> duplicate = make_shared<Scope>(scope);
        return duplicate;
    }
    shared_ptr<Scope> set(const string &name, node_reference node) {
        map<string, ASTNode> scopes = scope;
        scopes[name] = *node;
        return copy(scopes);
    }
    shared_ptr<ASTNode> get(const string &name) {
        shared_ptr<ASTNode> value = make_shared<ASTNode>(scope[name]);
        return value;
    }
    bool has(const string &name) { return !(scope.find(name) == scope.end()); }
};

class Abstraction : public ASTNode {
  public:
    string argument;
    node_reference body;
    scope_reference scope;
    Abstraction(const string &_argument, node_reference _body, scope_reference _scope) {
        type = ABSTRACTION;
        argument = _argument;
        body = _body;
        scope = _scope;
    }
};

class Application : public ASTNode {
  public:
    node_reference lhs;
    node_reference rhs;
    Application(node_reference _lhs, node_reference _rhs) {
        type = APPLICATION;
        lhs = _lhs;
        rhs = _rhs;
    }
};

const string NILVAL = "nil";

#define nil NILVAL

enum LiteralType { Bool, Int, Nil };
class Literal : public ASTNode {
  public:
    string value;
    LiteralType valueType;
    Literal(bool val) {
        type = LITERAL;
        value = bool_as_text(val);
        valueType = Bool;
    }
    Literal(int val) {
        type = LITERAL;
        value = to_string(val);
        valueType = Int;
    }
    Literal() {
        type = LITERAL;
        value = nil;
        valueType = Nil;
    }
    bool getBool() { return text_as_bool(value); }
    int getInt() { return stoi(value); }
    string getNil() { return nil; }
};

class Variable : public ASTNode {
  public:
    string identifier;
    Variable(const string &name) {
        type = VARIABLE;
        identifier = name;
    }
};

enum OperationType { NO_OP, ADD, SUBTRACT, MULTIPLY, DIVIDE, GREATER_THAN, LESS_THAN, GREATER_THAN_EQUAL, LESS_THAT_EQUAL, EQUALS };
class Operation : public ASTNode {
  public:
    OperationType opType;
    node_reference lhs;
    node_reference rhs;
    Operation(OperationType _opType, node_reference _lhs, node_reference _rhs) {
        type = OPERATION;
        opType = _opType;
        lhs = _lhs;
        rhs = _rhs;
    }

    static OperationType matchOperationType(const string &op);
};

// TODO - Change this to a map lookup.
OperationType Operation::matchOperationType(const string &op) {
    OperationType opType;
    SWITCH(op)
        CASE("+") opType = ADD;
        BREAK
        CASE("-") opType = SUBTRACT;
        BREAK
        CASE("*") opType = MULTIPLY;
        BREAK
        CASE("/") opType = DIVIDE;
        BREAK
        CASE("<") opType = LESS_THAN;
        BREAK
        CASE(">") opType = GREATER_THAN;
        BREAK
        CASE("<=") opType = LESS_THAT_EQUAL;
        BREAK
        CASE(">=") opType = GREATER_THAN_EQUAL;
        BREAK
        CASE("==") opType = EQUALS;
        BREAK
        DEFAULT opType = NO_OP;
    END
    return opType;
}

class Main : public ASTNode {
    public:
    node_reference entry;
    Main(node_reference main) {
        type = MAIN;
        entry = main;
    }
};

class PrintInstruction : public ASTNode {
    public:
    node_reference value;
    PrintInstruction(node_reference valueToPrint) {
        type = PRINT;
        value = valueToPrint;
    }
};

} // namespace ast