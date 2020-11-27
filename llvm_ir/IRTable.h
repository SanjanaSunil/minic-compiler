#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class IRScope
{
public:
    llvm::BasicBlock* block;
    unordered_map<string, llvm::Value*> var_map; 

    IRScope(llvm::BasicBlock* block) {
        this->block = block;
    }
    
    bool existsInScope(string id) {
        if(var_map.find(id) != var_map.end()) return true;
        return false;
    }

    void addVariable(string id, llvm::Value* val) {
        var_map[id] = val;
    }

    llvm::Value* getVal(string id) {
        return var_map[id];
    }
};

class IRTable
{
public:
    vector<IRScope*> scopes;

    void addScope(llvm::BasicBlock* block=nullptr) {
        IRScope *scope = new IRScope(block);
        scopes.push_back(scope);
    }

    llvm::BasicBlock* getRecentBlock() {
        if(scopes.size() > 0)
        {
            IRScope *recent_scope = scopes.back();
            return recent_scope->block;
        }
        return nullptr;
    }

    void addVariableToCurrentScope(string id, llvm::Value* val) {
        IRScope *recent_scope = scopes.back();
        recent_scope->addVariable(id, val);
    }

    llvm::Value* getVal(string id) {
        int n = scopes.size();
        for(int i=n-1; i>=0; --i)
        {
            if(scopes[i]->existsInScope(id))
                return scopes[i]->getVal(id);
        }

        return nullptr;
    }

    bool existsInCurrentScope(string id) {
        return (scopes.back())->existsInScope(id);
    }

    void removeScope() {
        IRScope* recent_scope = scopes.back();
        scopes.pop_back();
        delete recent_scope;
    }

    bool isGlobal() {
        return (scopes.size() == 1);
    }
};