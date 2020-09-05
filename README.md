### Note:
`std::bad_cast` comes from `source/InterpreterListener.cc` returning something other than `ast::node_reference`. All instances of `ASTNode` must be upcasted to `ast::node_reference`, or else a runtime error will occur.

# Roadmap
-   [x] Create language grammar rules
-   [x] Construct Abstract Syntax Tree using the ANTLR visitor archetecture
-   [x] Implement Untyped λ Calculus semantic rules
-   [x] Make interactive REPL mode
-   [x] Implement the rest of the grammar rules: conditionals, imports, operations, etc.
-   [ ] Remove operations, print, and maybe imports from the language grammar. Symbols should parse as identifiers, and have native abstraction implementations (as well as print and import).
-   [ ] Add string literals to language grammar
-   [ ] Make a nice file interpreter with a good CLI
-   [ ] Test everything before moving on to types
-   [ ] Implement type grammar
-   [ ] Implement type checking
-   [ ] Implement stacks and module system (blocks, modules, exposures)


# Third Party Dependencies
-   Antlr4 (a copy of the JAR and entire project as zip)
-   Antlr4-cpp-runtime
-   Switch - 
-   Argh! - https://github.com/adishavit/argh