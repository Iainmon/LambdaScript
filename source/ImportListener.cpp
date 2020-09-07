// #include "frontend/frontend.h"
// #include "ast/ast.h"
// #include <iostream>
// #include <map>

// class ImportListener : public LanguageBaseListener {
//   private:
//     HashMap imports;

//   public:
//     void exitShow(LanguageParser::ImportContext *ctx) override {
//         if (ctx->INT() != nullptr) {
//             const std::string value = ctx->INT()->getText();
//             print(value);
//         } else if (ctx->VAR() != nullptr) {
//             const string name = ctx->VAR()->getText();
//             const string value = scope[name];
//             print(value);
//         }

//         if (ctx->Identifier)
//     }
// };