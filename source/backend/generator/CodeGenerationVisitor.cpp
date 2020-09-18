#include "CodeGenerationVisitor.h"

backend::codegen::CodeGenerationVisitor::CodeGenerationVisitor() {
    source << "// Transpiled from LambdaScript. " << std::endl << std::endl << std::endl;
    source << "const nil = null;const print = input => console.log(input);" << std::endl << std::endl;
}


ast::node_reference backend::codegen::CodeGenerationVisitor::visitLiteral(std::shared_ptr<ast::Literal> literal) {
    source << literal->value;

    return (ast::node_reference)literal;
}
ast::node_reference backend::codegen::CodeGenerationVisitor::visitVariable(std::shared_ptr<ast::Variable> variable) {
    source << variable->identifier;

    return (ast::node_reference)variable;
}
ast::node_reference backend::codegen::CodeGenerationVisitor::visitAssignment(std::shared_ptr<ast::Assignment> assignment) {
    source << assignment->identifier << " = ";
    assignment->value->accept(this);
    source << std::endl;

    return (ast::node_reference)assignment;
}
ast::node_reference backend::codegen::CodeGenerationVisitor::visitApplication(std::shared_ptr<ast::Application> application) {
    source << "(";
    application->lhs->accept(this);
    source << ")" << "(";
    application->rhs->accept(this);
    source << ")";

    return (ast::node_reference)application;
}
ast::node_reference backend::codegen::CodeGenerationVisitor::visitAbstraction(std::shared_ptr<ast::Abstraction> abstraction) {
    source << "(" << abstraction->argument << " => ";
    abstraction->body->accept(this);
    source << ")";

    return (ast::node_reference)abstraction;
}
ast::node_reference backend::codegen::CodeGenerationVisitor::visitNativeAbstraction(std::shared_ptr<ast::NativeAbstraction> native_abstraction) {

    return (ast::node_reference)native_abstraction;
}
ast::node_reference backend::codegen::CodeGenerationVisitor::visitArithmeticalOperation(std::shared_ptr<ast::Operation> operation) {
    source << "(";
    operation->lhs->accept(this);
    source << " " << operation->operation_character << " ";
    operation->rhs->accept(this);
    source << ")";
    
    return (ast::node_reference)operation;
}
ast::node_reference backend::codegen::CodeGenerationVisitor::visitPrintInstruction(std::shared_ptr<ast::PrintInstruction> print_instruction) {
    source << "print(";
    print_instruction->value->accept(this);
    source << ")" << std::endl;
    
    return (ast::node_reference)print_instruction;
}
ast::node_reference backend::codegen::CodeGenerationVisitor::visitGrouping(std::shared_ptr<ast::Grouping> grouping) {
    source << std::endl;
    for (ast::node_reference &node : grouping->nodes) {
        node->accept(this);
        // source << std::endl;
    }
    return (ast::node_reference)grouping;
}