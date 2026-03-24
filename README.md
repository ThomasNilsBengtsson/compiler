# Mini-Java Compiler

A complete compiler for a subset of Java (Mini-Java), built incrementally across three assignments. The compiler takes `.java` source files through the full pipeline — lexing, parsing, semantic analysis, IR generation, bytecode compilation, and execution — all implemented from scratch in C++.

## Overview

The compiler targets a Mini-Java language: a simplified subset of Java supporting classes, methods, basic types (`int`, `boolean`), arithmetic, control flow (`if`/`else`, `while`), method calls, and object instantiation.

**Pipeline:**

```
Source (.java)
    │
    ▼
Lexical Analysis      (Flex)           → token stream
    │
    ▼
Syntax Analysis       (Bison, LALR(1)) → AST
    │
    ▼
Symbol Table                           → scoped symbol table
    │
    ▼
Semantic Analysis                      → type/scope/duplicate checks
    │
    ▼
IR Generation                          → Three-Address Code (TAC) + CFG
    │
    ▼
Bytecode Generation                    → program.bc
    │
    ▼
Interpreter                            → stdout output
```

## Project Structure

```
.
├── assignment1/        # Lexer + parser (Flex + Bison)
├── assignment2/        # + Semantic analysis and symbol table
└── assignment3/        # + IR generation, bytecode, interpreter (complete compiler)
    ├── lexer.flex          # Lexical rules
    ├── parser.yy           # Grammar (LALR(1))
    ├── Node.h              # AST node definition
    ├── symbol_table.cc/h   # Scoped symbol table
    ├── semantic_analyzer.cc/hh  # Duplicate and type checking
    ├── ir.cc/hh            # TAC instruction set and CFG structures
    ├── ir_generator.cc/hh  # AST → IR (visitor pattern)
    ├── bytecode.cc/h       # IR → stack-based bytecode
    ├── interpreter.cc/h    # Bytecode virtual machine
    ├── main.cc             # Compiler entry point
    ├── Makefile
    └── test_files/
        ├── assignment3_valid/   # 10 valid Mini-Java programs
        ├── semantic_errors/     # Programs with expected semantic errors
        ├── syntax_errors/       # Programs with expected syntax errors
        └── lexical_errors/      # Programs with expected lexical errors
```

## Dependencies

- **g++** with C++14 support
- **Bison** (>= 3.0)
- **Flex**
- **Graphviz** (`dot`) — optional, for visualising AST and CFG

## Building

```bash
cd assignment3
make
```

This runs Bison and Flex to generate the parser and lexer, then compiles everything into a single `./compiler` binary.

```bash
# Clean generated files
make clean
```

## Usage

```bash
./compiler <source.java>
```

The compiler runs the full pipeline and prints the program output to stdout.

**Exit codes:**

| Code | Meaning |
|------|---------|
| `0`  | Success |
| `1`  | Lexical error |
| `2`  | Syntax error |
| `3`  | AST error |
| `4`  | Semantic error |

**Generated artifacts** (written to the working directory):

| File | Description |
|------|-------------|
| `cfg.dot` | Control flow graph (Graphviz) |
| `program.bc` | Compiled bytecode |

## Example

Given `Sum.java`:

```java
public class Sum {
    public static void main(String[] a) {
        int sum;
        int i;
        sum = 0;
        i = 1;
        while (i < 11) {
            sum = sum + i;
            i = i + 1;
        }
        System.out.println(sum);
    }
}
```

```bash
./compiler test_files/assignment3_valid/Sum.java
# Output: 55
```

**Visualise the control flow graph:**

```bash
make cfg        # produces cfg.pdf
make tree       # produces tree.pdf (AST)
```

## Language Features

| Feature | Supported |
|---------|-----------|
| Classes and methods | Yes |
| `int`, `boolean` types | Yes |
| Arithmetic (`+`, `-`, `*`) | Yes |
| Comparison (`<`, `>`, `==`) | Yes |
| Logic (`&&`, `\|\|`, `!`) | Yes |
| `if`/`else`, `while` | Yes |
| `System.out.println` | Yes |
| Object instantiation (`new`) | Yes |
| Method calls, `this` | Yes |
| Arrays | No |
| Inheritance | No |

## Intermediate Representation

The IR uses Three-Address Code with an explicit Control Flow Graph per method. Temporary variables are named `_t0`, `_t1`, …, and basic blocks are `block_0`, `block_1`, …

Example IR for `1 + 2`:

```
Test.main:
block_0:
    _t0 = 1
    _t1 = 2
    _t2 = _t0 + _t1
    print _t2
    stop
```

## Bytecode

The bytecode targets a simple stack-based virtual machine. Instructions include:

| Instruction | Description |
|-------------|-------------|
| `iconst N` | Push integer constant |
| `iload idx` | Push local variable |
| `istore idx` | Pop into local variable |
| `iadd`, `isub`, `imul` | Arithmetic |
| `ilt`, `igt`, `ieq` | Comparison |
| `iand`, `ior` | Logical |
| `iffalse label` | Conditional branch |
| `goto label` | Unconditional branch |
| `call method N` | Call method with N arguments |
| `return` | Return from method |
| `print` | Print top of stack |
| `stop` | Halt execution |

## Testing

```bash
# Run all tests (requires Python 3)
python3 testScript.py
```

The test script compiles each file in `test_files/`, compares compiler output against expected errors annotated in source comments (`// @error - message`), and reports pass/fail with coloured output.

## Semantic Checks

The semantic analyser reports errors in the format `@error at line N. <message>` and detects:

- Duplicate class names
- Duplicate method names within a class
- Duplicate variable/parameter names
- Invalid type definitions
- Return type mismatches
