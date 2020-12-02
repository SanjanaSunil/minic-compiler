# MiniC Compiler

## Description

MiniC is a C-style language that supports basic operations, assignment, loops, conditional statements, I/O operations etc. More details about microsyntax and macrosyntax can be seen in `MiniC/MiniC_Language_Manual.pdf`. 

A basic compiler that supports the following has been created:
* Parsing
* AST generation
* Semantic analysis
* LLVM IR generation

Sample programs for this language can be seen in `MiniC/sample_programs`. 

## Installation

### Java:
You can refer to Installation guide [here](https://www3.ntu.edu.sg/home/ehchua/programming/howto/JDK_Howto.html).

To check if Java is installed:

```bash
$ java -version
$ javac -version
```


### Antlr:
Refer to the [antlr](https://www.antlr.org/) main website.You can find how to install on Linux, OS X, Windows.

*PS: Make sure you put following lines in your source file(.bashrc, .zshrc etc.,)*

```bash
export CLASSPATH=".:/usr/local/lib/antlr-4.8-complete.jar:$CLASSPATH"
alias antlr4='java -jar /usr/local/lib/antlr-4.8-complete.jar'
alias grun='java org.antlr.v4.gui.TestRig'
```
```bash
$ source ~/.bashrc
```

## Usage

### Visualize parse tree

First run the following:
```bash
$ cd antlr
$ make 
```

General command:
```bash
$ grun <name_of_grammar> <root_node/Start Symbol> <path_to_test_file> <option>
```

Command here to visualize parse tree:
```bash
$ grun Expr prog ../tests/<test_file> -gui
```

### IR generation

First run the following:
```bash
$ cd llvm_ir
$ make 
```

To generate the IR, run the following. Here test file could include the sample programs.
```bash
$ ./expr <test-file>
```

A `tmp.bc` file will be generated in the current directory. Semantic analysis is also done here. Run `lli tmp.bc` to run the program.