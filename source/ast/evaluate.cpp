#include "ast.h"
#include "consolecolors.h"

using namespace std;

// ast::node_reference apply_beta_reduction(shared_ptr<ast::Application> application) {
//     shared_ptr<ast::Abstraction> lhs = static_pointer_cast<ast::Abstraction>(application->lhs);
//     ast::node_reference rhs = application->rhs;
//     lhs->scope->set(lhs->argument, rhs);
//     return ast::evaluate(lhs->body, lhs->scope);
// }

ast::node_reference ast::evaluate(node_reference ast, scope_reference scope) {
    // while (true) {
        if (ast->type == ast::ASTNodeType::APPLICATION) {
            // Reduce both sides, then apply beta reduction.
            shared_ptr<ast::Application> application = static_pointer_cast<ast::Application>(ast);

            shared_ptr<ast::Abstraction> lhs;
            if (application->lhs->type != ast::ASTNodeType::ABSTRACTION) {
                lhs = static_pointer_cast<ast::Abstraction>(ast::evaluate(application->lhs, scope));
            } else {
                lhs = static_pointer_cast<ast::Abstraction>(application->lhs);
            }
            ast::node_reference rhs = ast::evaluate(application->rhs, scope);
            // ast::node_reference rhs = application->rhs;

            ast::scope_reference child_scope = make_shared<ast::Scope>(*scope);
            child_scope->set(lhs->argument, rhs);
            return ast::evaluate(lhs->body, child_scope);

            // return apply_beta_reduction(application);
            // return ast;
        } 
        else if (ast->type == ast::ASTNodeType::ABSTRACTION) {
            shared_ptr<ast::Abstraction> abstraction = static_pointer_cast<ast::Abstraction>(ast);
            // abstraction->scope->set(abstraction->argument, abstraction->body);
            // abstraction->scope = scope;

            return (ast::node_reference)abstraction;
        } 
        else if (ast->type == ast::ASTNodeType::GROUPING) {
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
            cout << magenta << "λ -> " << reset;
            shared_ptr<ast::PrintInstruction> print_instruction = static_pointer_cast<ast::PrintInstruction>(ast);
            ast::node_reference value_to_print = ast::evaluate(print_instruction->value, scope);
            if (value_to_print->type == ast::ASTNodeType::LITERAL) {
                shared_ptr<ast::Literal> literal_to_print = static_pointer_cast<ast::Literal>(value_to_print);
                cout << yellow << literal_to_print->value << reset << endl;
            } else if (value_to_print->type == ast::ASTNodeType::ABSTRACTION) {
                cout << magenta << "[ " << Bmagenta << "λ" << magenta << " function ]" << reset << endl;
                cout << value_to_print->to_string() << endl;
            } else {
                cout << yellow << "[meta] " << reset << value_to_print->to_string() << endl;
            }
            // ast::node_reference base_literal = make_shared<ast::Literal>('l');
            // return base_literal;
            ast::node_reference nil_literal = make_shared<ast::Literal>('l');
            return nil_literal;
        }
        // cout << "No evaluation rule defined." << ast->to_string() << endl;
        return ast;
    // }
}