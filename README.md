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

# Installation
You will need:
 * A modern C/C++ compiler (preferably clang/clang++)
 * CMake 3.1+ installed (on a Mac, run `brew install cmake`)
 * 

```bash
git clone https://github.com/Iainmon/extended-lambda-calculus-language.git
cd extended-lambda-calculus-language
mkdir build
cd build
cmake ..
make -j4
./lcalc std.la --interactive
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
-   Add string literal [heres how](https://stackoverflow.com/questions/24557953/handling-string-literals-which-end-in-an-escaped-quote-in-antlr4)
-   Add comments to language grammar
-   Do a search for `[flag todo]`
-   α-renaming

### Note:
`std::bad_cast` comes from `source/InterpreterListener.cc` returning something other than `ast::node_reference`. All instances of `ASTNode` must be upcasted to `ast::node_reference`, or else a runtime error will occur.