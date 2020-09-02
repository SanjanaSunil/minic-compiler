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

### To Compile:

```bash
$ cd antlr
$ make 
```
### To Run

General command:
```bash
$ grun <name_of_grammar> <root_node/Start Symbol> <path_to_test_file> <option>
```

Command here:
```bash
$ grun Expr prog ../tests/<test_file> -gui
```
