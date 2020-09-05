# Extended Lambda Calculus (ELC)
Examples:
```haskell
-- interactive mode
id = (λx.x)
λ -> [ λ function ] (λx.x)

id 103
λ -> 103

add 2 3
λ -> 5

inc = add 1
λ -> [meta] (inc = (add 1))

inc 6
λ -> 7

not tru 
λ -> fls
```

```haskell
-- program.la
(condition = tru)
(if condition then print 1010 else print 2020)
(not condition -> print 3030 | print 4040)

-- output
1010
4040
```

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
-   [x] Implement type grammar
-   [x] Implement type annotations
-   [x] Implement type resolution
-   [ ] Implement type checking
-   [ ] Implement stacks and module system (blocks, modules, exposures)
-   [ ] Make LLVM IR code generator

# Third Party Dependencies
-   Antlr4 (a copy of the JAR and entire project as zip)
-   Antlr4-cpp-runtime
-   Switch - 
-   Argh! - https://github.com/adishavit/argh

### ToDo
-   Fix issue with imports needing to have an extra newline to avoid NL EOF warning.
-   Do a search for `[flag todo]`

### Note:
`std::bad_cast` comes from `source/InterpreterListener.cc` returning something other than `ast::node_reference`. All instances of `ASTNode` must be upcasted to `ast::node_reference`, or else a runtime error will occur.