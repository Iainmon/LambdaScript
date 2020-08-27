#include "ast.h"


std::string int_to_string(int &in) {
    return std::to_string(in);
}

using namespace std;

string ast::bool_as_text(const bool &b) { return b ? "true" : "false"; }

bool ast::text_as_bool(const string &b) {
    if (b.compare("true") == 0) {
        return true;
    }
    return false;
}


using namespace ast;

string ASTNode::to_string() {
    stringstream ss;
    ss << "( ASTNode )";
    return ss.str();
}

shared_ptr<Scope> Scope::copy(const map<string, ASTNode> &_scope) {
    shared_ptr<Scope> duplicate = make_shared<Scope>(_scope);
    return duplicate;
}

Scope::Scope(const map<string, ASTNode> &_scope) { scope = _scope; }
shared_ptr<Scope> Scope::copy() {
    shared_ptr<Scope> duplicate = make_shared<Scope>(scope);
    return duplicate;
}
shared_ptr<Scope> Scope::set(const string &name, node_reference node) {
    map<string, ASTNode> scopes = scope;
    scopes[name] = *node;
    return copy(scopes);
}
shared_ptr<ASTNode> Scope::get(const string &name) {
    shared_ptr<ASTNode> value = make_shared<ASTNode>(scope[name]);
    return value;
}
bool Scope::has(const string &name) { return !(scope.find(name) == scope.end()); }


Abstraction::Abstraction(const string &_argument, node_reference _body, scope_reference _scope) {
    type = ABSTRACTION;
    argument = _argument;
    body = _body;
    scope = _scope;
}
string Abstraction::to_string() {
    stringstream ss;
    ss << "Abstraction (λ" << argument << ". " << body->to_string() << " )";
    return ss.str();
}

Application::Application(node_reference _lhs, node_reference _rhs) {
    type = APPLICATION;
    lhs = _lhs;
    rhs = _rhs;
}
string Application::to_string() {
    stringstream ss;
    ss << "Application ( " << lhs->to_string() << " ) ( " << rhs->to_string() << " )";
    return ss.str();
}

Literal::Literal(bool val) {
    type = LITERAL;
    value = bool_as_text(val);
    valueType = Bool;
}
Literal::Literal(int val) {
    type = LITERAL;
    value = int_to_string(val);
    valueType = Int;
}
Literal::Literal() {
    type = LITERAL;
    value = nil;
    valueType = Nil;
}
bool Literal::getBool() { return text_as_bool(value); }
int Literal::getInt() { return stoi(value); }
string Literal::getNil() { return nil; }
string Literal::to_string() {
    stringstream ss;
    ss << "Literal ( " << value << " )";
    return ss.str();
}

Variable::Variable(const string &name) {
    type = VARIABLE;
    identifier = name;
}
string Variable::to_string() {
    stringstream ss;
    ss << "Identifier ( \"" << identifier << "\" )";
    return ss.str();
}

Operation::Operation(OperationType _opType, node_reference _lhs, node_reference _rhs) {
    type = OPERATION;
    opType = _opType;
    lhs = _lhs;
    rhs = _rhs;
}
string Operation::to_string() {
    stringstream ss;
    ss << "OPPERATION ( " << lhs->to_string() << " ) ( " << rhs->to_string() << " )";
    return ss.str();
}
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

Main::Main(node_reference main) {
    type = MAIN;
    entry = main;
}
string Main::to_string() {
    stringstream ss;
    ss << "( main = " << entry->to_string() << " )";
    return ss.str();
}

PrintInstruction::PrintInstruction(node_reference valueToPrint) {
    type = PRINT;
    value = valueToPrint;
}

string PrintInstruction::to_string() {
    stringstream ss;
    ss << "print ( " << value->to_string() << " )";
    return ss.str();
}