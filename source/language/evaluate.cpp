#include "language.h"
#include "../ast/consolecolors.h"

using namespace std;

// ast::node_reference apply_beta_reduction(shared_ptr<ast::Application> application) {
//     shared_ptr<ast::Abstraction> lhs = static_pointer_cast<ast::Abstraction>(application->lhs);
//     ast::node_reference rhs = application->rhs;
//     lhs->scope->set(lhs->argument, rhs);
//     return language::evaluate(lhs->body, lhs->scope);
// }

int apply_arithmatic_operation(ast::OperationType op_type, int lhs, int rhs) {
    switch (op_type) {
        case ast::OperationType::ADD:
            return lhs + rhs;
            break;
        case ast::OperationType::SUBTRACT:
            return lhs - rhs;
            break;
        case ast::OperationType::MULTIPLY:
            return lhs * rhs;
            break;
        case ast::OperationType::DIVIDE:
            return lhs / rhs;
            break;
        case ast::OperationType::NO_OP:
            cout << "NO OPERATION" << endl;
            return 0;
    }
    return 0;
}

bool apply_logic_operation(ast::OperationType op_type, int lhs, int rhs) {
    switch (op_type) {
        case ast::OperationType::EQUALS:
            return lhs == rhs;
            break;
        case ast::OperationType::LESS_THAN:
            return lhs < rhs;
            break;
        case ast::OperationType::LESS_THAT_EQUAL:
            return lhs <= rhs;
            break;
        case ast::OperationType::GREATER_THAN:
            return lhs > rhs;
            break;
        case ast::OperationType::GREATER_THAN_EQUAL:
            return lhs >= rhs;
            break;
        case ast::OperationType::NO_OP:
            cout << "NO OPERATION" << endl;
            return false;
    }
    return false;
}
bool apply_logic_operation(ast::OperationType op_type, bool lhs, bool rhs) {
    switch (op_type) {
        case ast::OperationType::EQUALS:
            return lhs == rhs;
            break;
        case ast::OperationType::NO_OP:
            cout << "NO OPERATION" << endl;
            return false;
    }
    return false;
}

bool apply_operation(ast::OperationType op_type, bool lhs, bool rhs) {
    switch (op_type) {
        case ast::OperationType::EQUALS:
            return lhs == rhs;
            break;
        case ast::OperationType::NO_OP:
            cout << "NO OPERATION" << endl;
            return false;
    }
    return false;
}

ast::node_reference language::evaluate(ast::node_reference ast, ast::scope_reference scope) {
    // while (true) {
        if (ast->type == ast::ASTNodeType::APPLICATION) {
            // Reduce both sides, then apply beta reduction.
            shared_ptr<ast::Application> application = static_pointer_cast<ast::Application>(ast);
            
            // cout << application->to_string() << endl;
            // if (application->lhs == nullptr)
            //     cout << "LHS is nullptr" << endl;

            ast::node_reference evaluated_lhs = language::evaluate(application->lhs, scope);

            if (evaluated_lhs->type == ast::ASTNodeType::NATIVE_ABSTRACTION) {
                shared_ptr<ast::NativeAbstraction> native_abstraction = static_pointer_cast<ast::NativeAbstraction>(evaluated_lhs);
                native_abstraction->pre_apply_hook(application->rhs, scope);
                return native_abstraction->apply(language::evaluate(application->rhs, scope), scope);
            }

            if (evaluated_lhs->type == ast::ASTNodeType::LITERAL || evaluated_lhs->type == ast::ASTNodeType::GROUPING) {
                if (evaluated_lhs->type == ast::ASTNodeType::LITERAL) {
                    shared_ptr<ast::Literal> literal = static_pointer_cast<ast::Literal>(evaluated_lhs);
                    if (literal->valueType == ast::LiteralType::Bool && (scope->has("trbool") && scope->has("flbool"))) {
                        bool truthy = literal->getBool();
                        ast::node_reference truthy_reff = scope->get(truthy ? "trbool" : "flbool");
                        shared_ptr<ast::Abstraction> boolean_lambda = static_pointer_cast<ast::Abstraction>(truthy_reff);
                        ast::node_reference casted_truthy_application = make_shared<ast::Application>(boolean_lambda, application->rhs);
                        return language::evaluate(casted_truthy_application, scope);
                    }
                }
                shared_ptr<ast::Grouping> grouping = make_shared<ast::Grouping>();
                grouping->nodes.push_back(application->lhs);
                grouping->nodes.push_back(application->rhs);
                return (ast::node_reference)grouping;
            }

            ast::node_reference rhs = language::evaluate(application->rhs, scope);

 /* start */if (application->lhs->type != ast::ASTNodeType::ABSTRACTION) {
  /* dont */    shared_ptr<ast::Abstraction> lhs = static_pointer_cast<ast::Abstraction>(language::evaluate(application->lhs, scope));
                
                scope->set(lhs->argument, rhs);
  /* edit */    return language::evaluate(lhs->body, scope);

                // ast::scope_reference child_scope = make_shared<ast::Scope>(*scope);
                // child_scope->set(lhs->argument, rhs);
   /* this */   // return language::evaluate(lhs->body, child_scope);
            } else {
                shared_ptr<ast::Abstraction> lhs = static_pointer_cast<ast::Abstraction>(application->lhs);
                
                scope->set(lhs->argument, rhs);
  /* code */    return language::evaluate(lhs->body, scope);

                // ast::scope_reference child_scope = make_shared<ast::Scope>(*scope);
                // child_scope->set(lhs->argument, rhs);
                // return language::evaluate(lhs->body, child_scope);
  /* end */ }
            // ast::node_reference rhs = application->rhs;

            // ast::scope_reference child_scope = make_shared<ast::Scope>(*scope);
            // child_scope->set(lhs->argument, rhs);
            // return language::evaluate(lhs->body, child_scope);



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
                ast::node_reference evaluated_node = language::evaluate(node, scope);
                // evaluated_grouping->nodes.push_back(evaluated_node);
                node = evaluated_node;
            }
            // return (ast::node_reference)evaluated_grouping;
            return (ast::node_reference)grouping;
        } else if (ast->type == ast::ASTNodeType::ASSIGNMENT) {
            // cout << "ASSIGNMENT" << endl;
            shared_ptr<ast::Assignment> assignment = static_pointer_cast<ast::Assignment>(ast);
            ast::node_reference value = language::evaluate(assignment->value, scope);
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
            ast::node_reference value_to_print = language::evaluate(print_instruction->value, scope);
            if (value_to_print->type == ast::ASTNodeType::LITERAL) {
                shared_ptr<ast::Literal> literal_to_print = static_pointer_cast<ast::Literal>(value_to_print);
                if (literal_to_print->valueType == ast::LiteralType::Bool)
                    cout << yellow << (literal_to_print->getBool() ? "tru" : "fls" ) << reset << endl;
                else
                    cout << yellow << literal_to_print->value << reset << endl;
                
            } else if (value_to_print->type == ast::ASTNodeType::ABSTRACTION) {
                cout << yellow << "[ " << Bmagenta << "λ" << yellow << " function ]" << reset << " ";
                cout << value_to_print->pretty_print() << endl;
            } 
            else if (value_to_print->type == ast::ASTNodeType::GROUPING) {
                cout << yellow << "[ " << Bblue << "β" << yellow << " grouping ]" << reset << " ";
                cout << value_to_print->pretty_print() << endl;
            }
            else {
                cout << yellow << "[meta] " << reset << value_to_print->pretty_print() << endl;
            }
            // ast::node_reference base_literal = make_shared<ast::Literal>('l');
            // return base_literal;
            ast::node_reference nil_literal = make_shared<ast::Literal>('l');
            return nil_literal;
        } else if (ast->type == ast::ASTNodeType::OPERATION) {
            shared_ptr<ast::Operation> operation = static_pointer_cast<ast::Operation>(ast);
            ast::node_reference lhs = language::evaluate(operation->lhs, scope);
            ast::node_reference rhs = language::evaluate(operation->rhs, scope);
            if (lhs->type == ast::ASTNodeType::LITERAL && rhs->type == ast::ASTNodeType::LITERAL) {
                shared_ptr<ast::Literal> lhs_literal = static_pointer_cast<ast::Literal>(lhs);
                shared_ptr<ast::Literal> rhs_literal = static_pointer_cast<ast::Literal>(rhs);
                if (lhs_literal->valueType == rhs_literal->valueType) {
                    ast::LiteralType type = lhs_literal->valueType;
                    if (operation->arithmatic_op) {
                        if (type == ast::LiteralType::Int) {
                            int result = apply_arithmatic_operation(operation->opType, lhs_literal->getInt(), rhs_literal->getInt());
                            ast::node_reference result_literal = make_shared<ast::Literal>(result);
                            return result_literal;
                        } else {
                            return (ast::node_reference)operation;
                            cout << "No arithmetic defined for " << lhs_literal->to_string() << " and " << rhs_literal->to_string() << "." << endl;
                        }
                    } else {
                        if (type == ast::LiteralType::Int) {
                            bool result = apply_logic_operation(operation->opType, lhs_literal->getInt(), rhs_literal->getInt());
                            ast::node_reference result_literal = make_shared<ast::Literal>(result);
                            return result_literal;
                        } else if (type == ast::LiteralType::Bool) {
                            bool result = apply_logic_operation(operation->opType, lhs_literal->getBool(), rhs_literal->getBool());
                            ast::node_reference result_literal = make_shared<ast::Literal>(result);
                            return result_literal;
                        } else {
                            return (ast::node_reference)operation;
                            cout << "No arithmetic defined for " << lhs_literal->to_string() << " and " << rhs_literal->to_string() << "." << endl;
                        }
                    }
                } else { 
                    return (ast::node_reference)operation;
                    cout << "Arithmetic cannot be applied becauese LHS and RHS are not the same type!" << endl;
                    
                }
            } else {
                cout << "LHS or RHS is not a literal!" << endl;
                return (ast::node_reference)operation;
            }
        } else if (ast->type == ast::ASTNodeType::IMPORT) {
            shared_ptr<ast::ImportInstruction> import = static_pointer_cast<ast::ImportInstruction>(ast);
            ast::node_reference imported_ast = language::import_file(import->file_name, scope);
            return imported_ast;
        }
        // cout << "No evaluation rule defined." << ast->to_string() << endl;
        return ast;
    // }
}