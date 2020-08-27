
#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <string>

#include <switch>

#ifndef AST_H
#define AST_H

std::string int_to_string(int &in);

using namespace std;

namespace ast {

string bool_as_text(const bool &b);
bool text_as_bool(const string &b);

enum ASTNodeType { MAIN, ABSTRACTION, APPLICATION, CONDITION, PRINT, VARIABLE, OPERATION, LITERAL };
class ASTNode {
    public:
    ASTNodeType type;
    virtual string to_string();
};

class Scope;

using node_reference = shared_ptr<ASTNode>;
using scope_reference = shared_ptr<Scope>;

class Scope {
    private:
    map<string, ASTNode> scope;
    shared_ptr<Scope> copy(const map<string, ASTNode> &_scope);
    public:
    Scope();
    Scope(const map<string, ASTNode> &_scope);
    shared_ptr<Scope> copy();
    shared_ptr<Scope> set(const string &name, node_reference node);
    shared_ptr<ASTNode> get(const string &name);
    bool has(const string &name);
};

class Abstraction : public ASTNode {
    public:
    string argument;
    node_reference body;
    scope_reference scope;
    Abstraction(const string &_argument, node_reference _body, scope_reference _scope);
    string to_string() override;
};

class Application : public ASTNode {
    public:
    node_reference lhs;
    node_reference rhs;
    Application(node_reference _lhs, node_reference _rhs);
    string to_string() override;
};

const string NILVAL = "nil";
#define nil NILVAL

enum LiteralType { Bool, Int, Nil };
class Literal : public ASTNode {
    public:
    string value;
    LiteralType valueType;
    Literal(bool val);
    Literal(int val);
    Literal();
    bool getBool();
    int getInt();
    string getNil();
    string to_string() override;
};

class Variable : public ASTNode {
    public:
    string identifier;
    Variable(const string &name);
    string to_string() override;
};

enum OperationType { NO_OP, ADD, SUBTRACT, MULTIPLY, DIVIDE, GREATER_THAN, LESS_THAN, GREATER_THAN_EQUAL, LESS_THAT_EQUAL, EQUALS };
class Operation : public ASTNode {
    public:
    OperationType opType;
    node_reference lhs;
    node_reference rhs;
    Operation(OperationType _opType, node_reference _lhs, node_reference _rhs);
    static OperationType matchOperationType(const string &op);
    string to_string() override;
};

class Main : public ASTNode {
    public:
    node_reference entry;
    Main(node_reference main);
    string to_string() override;
};

class PrintInstruction : public ASTNode {
    public:
    node_reference value;
    PrintInstruction(node_reference valueToPrint);
    string to_string() override;
};

node_reference evaluate(node_reference ast);

} // namespace ast

#endif