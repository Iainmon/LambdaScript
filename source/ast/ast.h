#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <switch>

#include "consolecolors.h"

#ifndef AST_H
#define AST_H

std::string int_to_string(int &in);

using namespace std;

namespace ast {


string bool_as_text(const bool &b);
bool text_as_bool(const string &b);

enum ASTNodeType { MAIN, ABSTRACTION, APPLICATION, CONDITION, PRINT, VARIABLE, OPERATION, LITERAL, GROUPING, ASSIGNMENT, IMPORT };
class ASTNode {
    public:
    ASTNodeType type;
    virtual string to_string();
    virtual string pretty_print();
};

class Scope;

using node_reference = shared_ptr<ASTNode>;
using scope_reference = shared_ptr<Scope>;

class Scope {
    private:
    map<string, node_reference> scope;
    int identifier_counter = 0;
    shared_ptr<Scope> copy(const map<string, node_reference> &_scope);
    node_reference unsafe_get(const string &name);
    public:
    Scope();
    Scope(const map<string, node_reference> &_scope);
    shared_ptr<Scope> copy();
    void set(const string &name, node_reference node);
    node_reference get(const string &name);
    bool has(const string &name);
    string enumerated_identifier();
};

class Abstraction : public ASTNode {
    public:
    string argument;
    node_reference body;
    // scope_reference scope = nullptr;
    Abstraction(const string &_argument, node_reference _body/*, scope_reference _scope*/);
    string to_string() override;
    string pretty_print() override;
};

class Application : public ASTNode {
    public:
    node_reference lhs;
    node_reference rhs;
    Application(node_reference _lhs, node_reference _rhs);
    string to_string() override;
    string pretty_print() override;
};

const string NILVAL = "nil";
#define nil NILVAL

enum LiteralType { Bool, Int, Nil, Base };
class Literal : public ASTNode {
    public:
    string value;
    LiteralType valueType;
    Literal(bool val);
    Literal(int val);
    Literal(char let);
    Literal();
    bool getBool();
    int getInt();
    string getNil();
    string to_string() override;
    string pretty_print() override;
};

class Variable : public ASTNode {
    public:
    string identifier;
    Variable(const string &name);
    string to_string() override;
    string pretty_print() override;
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
    string pretty_print() override;
};

class Main : public ASTNode {
    public:
    node_reference entry;
    Main(node_reference main);
    string to_string() override;
    string pretty_print() override;
};

class PrintInstruction : public ASTNode {
    public:
    node_reference value;
    PrintInstruction(node_reference valueToPrint);
    string to_string() override;
    string pretty_print() override;
};

class Grouping : public ASTNode {
    public:
    vector<node_reference> nodes;
    Grouping();
    string to_string() override;
    string pretty_print() override;
};

class Assignment : public ASTNode {
    public:
    string identifier;
    node_reference value;
    Assignment(const string &_identifier, node_reference _value);
    string to_string() override;
    string pretty_print() override;
};


class ImportInstruction : public ASTNode {
    public:
    string file_name;
    ImportInstruction(const string &_file_name);
    string to_string() override;
    string pretty_print() override;
};

// class NativeAbstraction : public ASTNode {
//     public:
//     NativeAbstraction();
//     virtual node_reference apply(node_reference argument, scope_reference scope) = 0;
// };


} // namespace ast

#endif