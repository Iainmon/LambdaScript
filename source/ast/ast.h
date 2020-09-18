#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <switch>

#include "consolecolors.h"

namespace ast {
class Scope;
class ASTNode;
class Application;
class Abstraction;
class Grouping;
class Literal;
class Variable;
class PrintInstruction;
class ImportInstruction;
class Operation;
class Assignment;
class NativeAbstraction;

using node_reference = std::shared_ptr<ASTNode>;
using scope_reference = std::shared_ptr<Scope>;
}

#include "../backend/NodeVisitor.h"

namespace backend {
    class NodeVisitor;
}

std::string int_to_string(int &in);

namespace ast {

namespace typesystem {
class TypeNode;
using type_reference = std::shared_ptr<TypeNode>;
}

std::string bool_as_text(const bool &b);
bool text_as_bool(const std::string &b);




enum ASTNodeType { MAIN, ABSTRACTION, APPLICATION, CONDITION, PRINT, VARIABLE, OPERATION, LITERAL, GROUPING, ASSIGNMENT, IMPORT, NATIVE_ABSTRACTION };
class ASTNode : public std::enable_shared_from_this<ASTNode> {
    public:
    typesystem::type_reference data_type;
    ASTNodeType type;
    virtual std::string to_string();
    virtual std::string pretty_print();
    virtual node_reference accept(backend::NodeVisitor *visitor);
};

// enum TypeNodeType = { TYPE, FUNCTION };
// class TypeNode {
//     public:
//     TypeNodeType type;
// };
// using type_reference = std::shared_ptr<TypeNode>;

// class Type : public TypeNode {
//     public:
//     std::string name;
//     Type(const std::string &name);
// };

// class Function : public TypeNode {
//     public:
//     type_reference lhs;
//     type_reference rhs;
//     Function(type_reference _lhs, type_reference _rhs);
// };

// These will extend the Type class.
// class Bool;
// class Number;


class Scope {
    private:
    std::map<std::string, node_reference> scope;
    int identifier_counter = 0;
    std::shared_ptr<Scope> copy(const std::map<std::string, node_reference> &_scope);
    node_reference unsafe_get(const std::string &name);
    public:
    Scope();
    Scope(const std::map<std::string, node_reference> &_scope);
    std::shared_ptr<Scope> copy();
    void set(const std::string &name, node_reference node);
    node_reference get(const std::string &name);
    bool has(const std::string &name);
    std::string enumerated_identifier();
};

class Abstraction : public ASTNode {
    public:
    std::string argument;
    node_reference body;
    scope_reference closure;
    Abstraction(const std::string &_argument, node_reference _body);
    Abstraction(const std::string &_argument, node_reference _body, scope_reference _closure);
    void capture(scope_reference scope);
    std::string to_string() override;
    std::string pretty_print() override;
    node_reference accept(backend::NodeVisitor *visitor) override;
};

class Application : public ASTNode {
    public:
    node_reference lhs;
    node_reference rhs;
    Application(node_reference _lhs, node_reference _rhs);
    std::string to_string() override;
    std::string pretty_print() override;
    node_reference accept(backend::NodeVisitor *visitor) override;
};

const std::string NILVAL = "nil";
#define nil NILVAL

enum LiteralType { Bool, Int, Nil, Base };
class Literal : public ASTNode {
    public:
    std::string value;
    LiteralType valueType;
    Literal(bool val);
    Literal(int val);
    Literal(char let);
    Literal();
    bool getBool();
    int getInt();
    std::string getNil();
    std::string to_string() override;
    std::string pretty_print() override;
    node_reference accept(backend::NodeVisitor *visitor) override;
};

class Variable : public ASTNode {
    public:
    std::string identifier;
    Variable(const std::string &name);
    std::string to_string() override;
    std::string pretty_print() override;
    node_reference accept(backend::NodeVisitor *visitor) override;
};

enum OperationType { NO_OP, ADD, SUBTRACT, MULTIPLY, DIVIDE, GREATER_THAN, LESS_THAN, GREATER_THAN_EQUAL, LESS_THAT_EQUAL, EQUALS };
class Operation : public ASTNode {
    public:
    bool arithmatic_op;
    OperationType opType;
    node_reference lhs;
    node_reference rhs;
    Operation(OperationType _opType, node_reference _lhs, node_reference _rhs);
    static OperationType matchOperationType(const std::string &op);
    std::string to_string() override;
    std::string pretty_print() override;
    node_reference accept(backend::NodeVisitor *visitor) override;
};

class PrintInstruction : public ASTNode {
    public:
    node_reference value;
    PrintInstruction(node_reference valueToPrint);
    std::string to_string() override;
    std::string pretty_print() override;
    node_reference accept(backend::NodeVisitor *visitor) override;
};

class Grouping : public ASTNode {
    public:
    std::vector<node_reference> nodes;
    Grouping();
    std::string to_string() override;
    std::string pretty_print() override;
    node_reference accept(backend::NodeVisitor *visitor) override;
};

class Assignment : public ASTNode {
    public:
    std::string identifier;
    node_reference value;
    Assignment(const std::string &_identifier, node_reference _value);
    std::string to_string() override;
    std::string pretty_print() override;
    node_reference accept(backend::NodeVisitor *visitor) override;
};


class ImportInstruction : public ASTNode {
    public:
    std::string file_name;
    ImportInstruction(const std::string &_file_name);
    std::string to_string() override;
    std::string pretty_print() override;
    node_reference accept(backend::NodeVisitor *visitor) override;
};

class NativeAbstraction : public ASTNode {
    public:
    // ASTNodeType type;
    // virtual std::string to_string();
    // virtual std::string pretty_print();
    virtual node_reference apply(node_reference argument, scope_reference scope);
    virtual void pre_apply_hook(node_reference argument, scope_reference scope);
    node_reference accept(backend::NodeVisitor *visitor) override;
};

namespace typesystem {

enum TypeNodeType { TYPE, FUNCTION };
class TypeNode {
    public:
    TypeNodeType type;
    virtual std::string pretty_print();
    virtual bool operator==(const TypeNode &ref);
};



type_reference type_from_name(const std::string &name);

class Type : public TypeNode {
    public:
    std::string name;
    Type(const std::string &_name);
    std::string pretty_print() override;
    bool operator==(const TypeNode &ref) override;
};

class FunctionType : public TypeNode {
    public:
    type_reference lhs;
    type_reference rhs;
    FunctionType(type_reference _lhs, type_reference _rhs);
    std::string pretty_print() override;
    bool operator==(const TypeNode &ref) override;
};

// These will extend the Type class.
// class Bool;
// class Number;

}
} // namespace ast
