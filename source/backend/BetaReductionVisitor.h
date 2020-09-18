// This class will replace the evaluate function.
#ifndef BETA_REDUCTION_VISITOR_H
#define BETA_REDUCTION_VISITOR_H

#include "../ast/ast.h"
#include <stack>

namespace backend {
    // AKA EvaluationVisitor
    class BetaReductionVisitor : public NodeVisitor {
        private:
        public:
        ast::scope_reference replacement_table;

        BetaReductionVisitor(ast::scope_reference _replacement_table);
        BetaReductionVisitor();

        ast::node_reference visitVariable(std::shared_ptr<ast::Variable>) override;
        ast::node_reference visitApplication(std::shared_ptr<ast::Application>) override;
        ast::node_reference visitAbstraction(std::shared_ptr<ast::Abstraction>) override;
        ast::node_reference visitAssignment(std::shared_ptr<ast::Assignment>) override;

    };

}

#endif