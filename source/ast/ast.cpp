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
string ASTNode::pretty_print() {
    stringstream ss;
    ss << "( * )";
    return ss.str();
}
node_reference ASTNode::accept(backend::NodeVisitor *visitor) {
    shared_ptr<ASTNode> self = static_pointer_cast<ASTNode>(shared_from_this());
    return visitor->visitGenericASTNode(self);
}

shared_ptr<Scope> Scope::copy(const unordered_map<string, node_reference> &_scope) {
    shared_ptr<Scope> duplicate = make_shared<Scope>(_scope);
    return duplicate;
}
Scope::Scope() { }
Scope::Scope(const unordered_map<string, node_reference> &_scope) { scope = _scope; }
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
    // cout << "Variable \'" << name << "\' does not exist! Returning Nil Literal." << endl; // TODO temporary, and only for interactive mode.
    // node_reference base_literal = make_shared<Literal>('l');
    // return base_literal;
    node_reference nil_literal = make_shared<Literal>();
    return nil_literal;
    // return nullptr;
}
bool Scope::has(const string &name) { return !(scope.find(name) == scope.end()); }

string Scope::enumerated_identifier() {
    identifier_counter++;
    return "v" + to_string(identifier_counter);
}


Abstraction::Abstraction(const string &_argument, node_reference _body/*, scope_reference _scope*/) {
    type = ABSTRACTION;
    argument = _argument;
    body = _body;
    closure = make_shared<Scope>();
}
Abstraction::Abstraction(const string &_argument, node_reference _body, scope_reference _closure) {
    type = ABSTRACTION;
    argument = _argument;
    body = _body;
    closure = make_shared<Scope>(*_closure);
}
void Abstraction::capture(scope_reference scope) {
    closure = make_shared<Scope>(*scope);
}
string Abstraction::to_string() {
    stringstream ss;
    ss << "Abstraction (" << Bmagenta << "λ" << cyan << argument << reset << ". " << body->to_string() << " )";
    return ss.str();
}
string Abstraction::pretty_print() {
    stringstream ss;
    ss << "(" << magenta << "λ" << cyan << argument << reset << "." << body->pretty_print() << ")";
    return ss.str();
}
node_reference Abstraction::accept(backend::NodeVisitor *visitor) {
    shared_ptr<Abstraction> self = static_pointer_cast<Abstraction>(shared_from_this());
    return visitor->visitAbstraction(self);
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
string Application::pretty_print() {
    // cout << "ApplicationPrint" << endl;
    stringstream ss;
    ss << "(" << lhs->pretty_print() << " " << rhs->pretty_print() << ")";
    return ss.str();
}
node_reference Application::accept(backend::NodeVisitor *visitor) {
    shared_ptr<Application> self = static_pointer_cast<Application>(shared_from_this());
    return visitor->visitApplication(self);
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
Literal::Literal(char let) {
    type = LITERAL;
    value = "*";
    valueType = Base;
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
string Literal::pretty_print() {
    stringstream ss;
    ss << yellow << value << reset;
    return ss.str();
}
node_reference Literal::accept(backend::NodeVisitor *visitor) {
    shared_ptr<Literal> self = static_pointer_cast<Literal>(shared_from_this());
    return visitor->visitLiteral(self);
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
string Variable::pretty_print() {
    stringstream ss;
    ss << cyan << identifier << reset;
    return ss.str();
}
node_reference Variable::accept(backend::NodeVisitor *visitor) {
    shared_ptr<Variable> self = static_pointer_cast<Variable>(shared_from_this());
    return visitor->visitVariable(self);
}

Operation::Operation(OperationType _opType, node_reference _lhs, node_reference _rhs) {
    type = OPERATION;
    opType = _opType;
    lhs = _lhs;
    rhs = _rhs;
    if (opType == OperationType::ADD || opType == OperationType::SUBTRACT || opType == OperationType::MULTIPLY || opType == OperationType::DIVIDE) {
        arithmatic_op = true;
    } else {
        arithmatic_op = false;
    }
}
string Operation::to_string() {
    // cout << "OperationPrint" << endl;
    stringstream ss;
    ss << "OPPERATION ( " << lhs->to_string() << " ) ( " << rhs->to_string() << " )";
    return ss.str();
}
string Operation::pretty_print() {
    stringstream ss;
    ss << "(" << lhs->pretty_print() << " " << operation_character << " " << rhs->pretty_print() << ")";
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
node_reference Operation::accept(backend::NodeVisitor *visitor) {
    shared_ptr<Operation> self = static_pointer_cast<Operation>(shared_from_this());
    return visitor->visitArithmeticalOperation(self);
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
string PrintInstruction::pretty_print() {
    // cout << "PrintPrint" << endl;
    stringstream ss;
    ss << "print " << value->pretty_print();
    return ss.str();
}
node_reference PrintInstruction::accept(backend::NodeVisitor *visitor) {
    shared_ptr<PrintInstruction> self = static_pointer_cast<PrintInstruction>(shared_from_this());
    return visitor->visitPrintInstruction(self);
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
string Grouping::pretty_print() {
    stringstream ss;
    if (nodes.empty()) {
        ss << "( ";
    } else {
        ss << "( " << endl;
    }
    for (node_reference& node : nodes) {
        ss << "\t" << "( " << node->pretty_print() << " ) " << endl;
    }
    ss << ")";
    return ss.str();
}
node_reference Grouping::accept(backend::NodeVisitor *visitor) {
    shared_ptr<Grouping> self = static_pointer_cast<Grouping>(shared_from_this());
    return visitor->visitGrouping(self);
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
string Assignment::pretty_print() {
    stringstream ss;
    ss << "(" << cyan << identifier << blue << " = " << reset << value->pretty_print() << ")";
    return ss.str();
}
node_reference Assignment::accept(backend::NodeVisitor *visitor) {
    shared_ptr<Assignment> self = static_pointer_cast<Assignment>(shared_from_this());
    return visitor->visitAssignment(self);
}

ImportInstruction::ImportInstruction(const string &_file_name) {
    type = IMPORT;
    file_name = _file_name;
}

string ImportInstruction::to_string() {
    stringstream ss;
    ss << "Import ( " << file_name << " )";
    return ss.str();
}
string ImportInstruction::pretty_print() {
    stringstream ss;
    ss << "(" << green << "import " << blue << file_name << reset << ")";
    return ss.str();
}

node_reference ImportInstruction::accept(backend::NodeVisitor *visitor) {
    shared_ptr<ImportInstruction> self = static_pointer_cast<ImportInstruction>(shared_from_this());
    return visitor->visitImportInstruction(self);
}

node_reference NativeAbstraction::apply(node_reference argument, scope_reference scope) {
    return argument;
}

void NativeAbstraction::pre_apply_hook(node_reference argument, scope_reference scope) { }

node_reference NativeAbstraction::accept(backend::NodeVisitor *visitor) {
    shared_ptr<NativeAbstraction> self = static_pointer_cast<NativeAbstraction>(shared_from_this());
    return visitor->visitNativeAbstraction(self);
}