#include <iostream>
#include <string>

using namespace std;

enum NodeType{NONE, INT, FLOAT, CHAR, BOOL, STRING};

NodeType getNodeType(string lit_type) {
    if(lit_type == "int" || lit_type == "uint" || lit_type == "long") return INT;
    else if(lit_type == "float") return FLOAT;
    else if(lit_type == "char") return CHAR;
    else if(lit_type == "bool") return BOOL;
    else if(lit_type == "string") return STRING;
    return NONE;
}

void error(string message) {
    cerr << "ERROR: " << message << endl;
    exit(1);
}