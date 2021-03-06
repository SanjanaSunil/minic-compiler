#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

enum ScopeType{Function, Block, Loop};

struct VariableDetails
{
    NodeType var_type;
    int dimensions; // -1 if it's a function
    vector<NodeType> argument_types; // Only for functions
    vector<int> argument_dims;
};

class Scope
{
public:
    ScopeType scope_type;
    NodeType return_type;
    unordered_map<string, VariableDetails> var_map; 

    Scope(ScopeType scope_type, NodeType return_type) 
        : scope_type(scope_type), return_type(return_type) {}
    
    bool existsInScope(string id) {
        if(var_map.find(id) != var_map.end()) return true;
        return false;
    }

    void redefineError(string id) {
        error(id + " has already been defined");
    }

    void addFunction(string id, NodeType ret_type, vector<NodeType> args, vector<int> dims) {
        if(existsInScope(id)) redefineError(id);
        var_map[id] = {ret_type, -1, args, dims};
    }

    void addVariable(string id, NodeType var_type, int dims) {
        if(existsInScope(id)) redefineError(id);
        var_map[id] = {var_type, dims, {}, {}};
    }

    VariableDetails getDetails(string id) {
        return var_map[id];
    }

    NodeType getType(string id) {
        return var_map[id].var_type;
    }

    int getDimensions(string id) {
        return var_map[id].dimensions;
    }

    vector<NodeType> getArgs(string id) {
        return var_map[id].argument_types;
    }

    vector<int> getDims(string id) {
        return var_map[id].argument_dims;
    }

    bool isFunction(string id) {
        if(var_map[id].dimensions == -1) return true;
        return false;
    }

    bool isValidFunctionCall(string id, vector<NodeType>& args, vector<int>& dims) {
        if(!existsInScope(id)) return false;
        if(!isFunction(id)) return false;

        vector<NodeType> func_args = getArgs(id);
        vector<int> func_dims = getDims(id);
        if(args.size() != func_args.size()) return false;
        for(int i=0; i<int(args.size()); ++i)
        {
            if(func_args[i] != args[i] || func_dims[i] != dims[i])
                return false;
        }

        return true;
    }

    bool isValidVariable(string id, int dimensions) {
        if(!existsInScope(id)) return false;
        if(dimensions != getDimensions(id)) return false;

        return true;
    }
};

class SymbolTable
{
public:
    vector<Scope*> scopes;

    void addBlockScope() {
        Scope *block_scope = new Scope(Block, NONE);
        scopes.push_back(block_scope);
    }

    void addLoopScope() {
        Scope *loop_scope = new Scope(Loop, NONE);
        scopes.push_back(loop_scope);
    }

    void addFunctionScope(string return_type) {
        NodeType ret_type = getNodeType(return_type);
        Scope *func_scope = new Scope(Function, ret_type);
        scopes.push_back(func_scope);
    }

    void addFunctionToCurrentScope(string id, string return_type, vector<string>& arguments, vector<int>& dims) {
        NodeType ret_type = getNodeType(return_type);

        vector<NodeType> args;
        for(string argument : arguments) args.push_back(getNodeType(argument));

        Scope *recent_scope = scopes.back();
        recent_scope->addFunction(id, ret_type, args, dims);
    }

    void addVariableToCurrentScope(string id, string variable_type, int dims) {
        NodeType var_type = getNodeType(variable_type);
        Scope *recent_scope = scopes.back();
        recent_scope->addVariable(id, var_type, dims);
    }

    VariableDetails getDetails(string id) {
        int n = scopes.size();
        for(int i=n-1; i>=0; --i)
        {
            if(scopes[i]->existsInScope(id))
                return scopes[i]->getDetails(id);
        }

        error("Invalid reference");
    }

    NodeType getType(string id) {
        int n = scopes.size();
        for(int i=n-1; i>=0; --i)
        {
            if(scopes[i]->existsInScope(id))
                return scopes[i]->getType(id);
        }

        return NONE;
        // error("Invalid reference");
    }

    int getDimensions(string id) {
        int n = scopes.size();
        for(int i=n-1; i>=0; --i)
        {
            if(scopes[i]->existsInScope(id))
                return scopes[i]->getDimensions(id);
        }

        error("Invalid reference");
    }

    vector<NodeType> getArgs(string id) {
        int n = scopes.size();
        for(int i=n-1; i>=0; --i)
        {
            if(scopes[i]->existsInScope(id))
                return scopes[i]->getArgs(id);
        }

        error("Invalid reference");
    }

    vector<int> getDims(string id) {
        int n = scopes.size();
        for(int i=n-1; i>=0; --i)
        {
            if(scopes[i]->existsInScope(id))
                return scopes[i]->getDims(id);
        }

        error("Invalid reference");
    }

    bool existsInCurrentScope(string id) {
        return (scopes.back())->existsInScope(id);
    }

    bool isValidFunctionCall(string id, vector<NodeType> args, vector<int> dims) {
        int n = scopes.size();
        for(int i=n-1; i>=0; --i)
        {
            if(scopes[i]->isValidFunctionCall(id, args, dims))
                return true;
        }
        return false;
    }

    bool isValidVariable(string id, int dimensions) {
        int n = scopes.size();
        for(int i=n-1; i>=0; --i)
        {
            if(scopes[i]->isValidVariable(id, dimensions))
                return true;
        }
        return false;
    }

    NodeType getCurrentReturnType() {
        for(int i=0; i<int(scopes.size()); ++i)
        {
            if(scopes[i]->scope_type == Function)
                return scopes[i]->return_type;
        }
        return NONE;
    }

    bool scopeTypeExists(ScopeType scope_type) {
        for(int i=0; i<int(scopes.size()); ++i)
        {
            if(scopes[i]->scope_type == scope_type)
                return true;
        }
        return false;
    }

    void removeScope() {
        Scope* recent_scope = scopes.back();
        scopes.pop_back();
        delete recent_scope;
    }

    bool isGlobal() {
        return (scopes.size() == 1);
    }
};