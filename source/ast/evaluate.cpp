#include "ast.h"
#include "consolecolors.h"

using namespace std;

ast::node_reference ast::evaluate(node_reference ast, scope_reference scope) {
    // while (true) {
        if (ast->type == ast::ASTNodeType::APPLICATION) {
            // Reduce both sides, then apply beta reduction.
            return ast;
        } else if (ast->type == ast::ASTNodeType::GROUPING) {
            // cout << "GROUPING" << endl;
            shared_ptr<ast::Grouping> grouping = static_pointer_cast<ast::Grouping>(ast);
            shared_ptr<ast::Grouping> evaluated_grouping = make_shared<ast::Grouping>();
            for (ast::node_reference &node : grouping->nodes) {
                ast::node_reference evaluated_node = ast::evaluate(node, scope);
                // evaluated_grouping->nodes.push_back(evaluated_node);
                node = evaluated_node;
            }
            // return (ast::node_reference)evaluated_grouping;
            return (ast::node_reference)grouping;
        } else if (ast->type == ast::ASTNodeType::ASSIGNMENT) {
            // cout << "ASSIGNMENT" << endl;
            shared_ptr<ast::Assignment> assignment = static_pointer_cast<ast::Assignment>(ast);
            ast::node_reference value = ast::evaluate(assignment->value, scope);
            scope->set(assignment->identifier, value);
            return (ast::node_reference)assignment;
        } else if (ast->type == ast::ASTNodeType::VARIABLE) {
            // cout << "IDENTIFIER" << endl;
            shared_ptr<ast::Variable> variable = static_pointer_cast<ast::Variable>(ast);
            ast::node_reference variable_reference = scope->get(variable->identifier);
            if (variable_reference == nullptr) {
                cout << yellow << "Reference to undefined " << red << "[ " << reset << variable->to_string() << red << " ]" << reset << endl;
                throw "Reference to undefined value.";
            }
            ast::node_reference value = static_pointer_cast<ast::Literal>(variable_reference);
            return value;

        } else if (ast->type == ast::ASTNodeType::LITERAL) {
            // cout << "LITERAL" << endl;

            ast::node_reference literal = static_pointer_cast<ast::Literal>(ast);
            return (ast::node_reference)literal;
        } else if (ast->type == ast::ASTNodeType::PRINT) {
            // cout << "PRINT" << endl;

            shared_ptr<ast::PrintInstruction> print_instruction = static_pointer_cast<ast::PrintInstruction>(ast);
            ast::node_reference value_to_print = ast::evaluate(print_instruction->value, scope);
            if (value_to_print->type == ast::ASTNodeType::LITERAL) {
                shared_ptr<ast::Literal> literal_to_print = static_pointer_cast<ast::Literal>(value_to_print);
                cout << literal_to_print->value << endl;
            } else {
                cout << value_to_print->to_string() << endl;
            }
            ast::node_reference nil = make_shared<ast::Literal>();
            return nil;
        }
    // }
}