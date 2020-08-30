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
    // cout << "ASTNodePrint" << endl;
    stringstream ss;
    ss << "( ASTNode )";
    return ss.str();
}

shared_ptr<Scope> Scope::copy(const map<string, node_reference> &_scope) {
    shared_ptr<Scope> duplicate = make_shared<Scope>(_scope);
    return duplicate;
}
Scope::Scope() { }
Scope::Scope(const map<string, node_reference> &_scope) { scope = _scope; }
shared_ptr<Scope> Scope::copy() {
    shared_ptr<Scope> duplicate = make_shared<Scope>(scope);
    return duplicate;
}
void Scope::set(const string &name, node_reference node) {
    scope[name] = node;
}
node_reference Scope::unsafe_get(const string &name) {
    return scope[name];
}
node_reference Scope::get(const string &name) {
    if (has(name)) {
        return unsafe_get(name);
    }
    cout << "Variable \'" << name << "\' does not exist! Returning Nil Literal." << endl;
    node_reference nil_literal = make_shared<Literal>();
    return nil_literal;
    // return nullptr;
}
bool Scope::has(const string &name) { return !(scope.find(name) == scope.end()); }


Abstraction::Abstraction(const string &_argument, node_reference _body/*, scope_reference _scope*/) {
    type = ABSTRACTION;
    argument = _argument;
    body = _body;
    // scope = _scope;
}
string Abstraction::to_string() {
    // cout << "AbstractionPrint" << endl;
    stringstream ss;
    ss << "Abstraction (" << Bmagenta << "λ" << cyan << argument << reset << ". " << body->to_string() << " )";
    return ss.str();
}

Application::Application(node_reference _lhs, node_reference _rhs) {
    type = APPLICATION;
    lhs = _lhs;
    rhs = _rhs;
}
string Application::to_string() {
    // cout << "ApplicationPrint" << endl;
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
    // cout << "LiteralPrint" << endl;
    stringstream ss;
    ss << "Literal ( " << yellow << value << reset << " )";
    return ss.str();
}

Variable::Variable(const string &name) {
    type = VARIABLE;
    identifier = name;
}
string Variable::to_string() {
    // cout << "VariablePrint" << endl;
    stringstream ss;
    ss << "Identifier ( " << cyan << "\"" << identifier << "\"" << reset << " )";
    return ss.str();
}

Operation::Operation(OperationType _opType, node_reference _lhs, node_reference _rhs) {
    type = OPERATION;
    opType = _opType;
    lhs = _lhs;
    rhs = _rhs;
}
string Operation::to_string() {
    // cout << "OperationPrint" << endl;
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
    cout << "MainPrint" << endl;
    stringstream ss;
    ss << "( main = " << entry->to_string() << " )";
    return ss.str();
}

PrintInstruction::PrintInstruction(node_reference valueToPrint) {
    type = PRINT;
    value = valueToPrint;
}

string PrintInstruction::to_string() {
    // cout << "PrintPrint" << endl;
    stringstream ss;
    ss << "print ( " << value->to_string() << " )";
    return ss.str();
}

Grouping::Grouping() {
    type = GROUPING;
}
string Grouping::to_string() {
    // cout << "GroupPrint" << endl;
    stringstream ss;
    if (nodes.empty()) {
        ss << "Grouping ( ";
    } else {
        ss << "Grouping ( " << endl;
    }
    for (node_reference& node : nodes) {
        ss << "\t" << "( " << node->to_string() << " ) " << endl;
    }
    ss << ")";
    return ss.str();
}

Assignment::Assignment(const string &_identifier, node_reference _value) {
    type = ASSIGNMENT;
    identifier = _identifier;
    value = _value;
}
string Assignment::to_string() {
    // cout << "AssignmentPrint" << endl;
    stringstream ss;
    ss << "Assignment ( " << Bcyan << identifier << blue << " = " << reset << "( " << value->to_string() << " ) )";
    return ss.str();
}