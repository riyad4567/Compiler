#ifndef SYMBOLINFO_H_
#define SYMBOLINFO_H_

#include <iostream>
#include <vector>
using namespace std;

class SymbolInfo
{
private:
    string name;
    string type;
    string retType;
    string varType;
    string expr;
    bool checkArray;
    bool checkFunction;
    int startline;
    int endline;

public:
    SymbolInfo *pointer;
    vector<SymbolInfo *> listOfParameter;
    vector<SymbolInfo*>childArr;   
    SymbolInfo()
    {   
        this->name ="";
        this->type ="";
        this->pointer = nullptr;
        this->listOfParameter = {};
        this->checkArray = false;
        this->checkFunction = false;
        this->childArr={};
    }
    SymbolInfo(string name, string type)
    {
        this->name = name;
        this->type = type;
        this->pointer = nullptr;
        this->listOfParameter = {};
        this->checkArray = false;
        this->childArr={};
        this->checkFunction = false;
    }
    void startlineSetter(int n)
    {
        startline=n;
    }
    void endlineSetter(int n)
    {
        endline=n;
    }
    void addChild(vector<SymbolInfo*>listofChild)
    {
         for(SymbolInfo *child:listofChild)
         {
            childArr.push_back(child);
         }
    }
    void checkArraySetter(bool b)
    {
        checkArray=b;
    }
    void exprSetter(string s)
    {
        expr=s;
    }
    string exprGetter()
    {
        return expr;
    }
    void checkFunctionSetter(bool b)
    {
        checkFunction=b;
    }  
    void retTypeSetter(string s)
    {
        this->retType = s;
    }
    void varTypeSetter(string s)
    {
        this->varType = s;
    }
    void nameSetter(string name)
    {
        this->name = name;
    }
    void typeSetter(string type)
    {
        this->type = type;
    }
    bool checkArrayGetter()
    {
        return checkArray;
    }
    bool checkFunctionGetter()
    {
        return checkFunction;
    }
    int startlineGetter()
    {
        return startline;
    }
    int endlineGetter()
    {
        return endline;
    }
    string nameGetter()
    {
        return this->name;
    }
    string typeGetter()
    {
        return type;
    }
    string varTypeGetter()
    {
        return varType;
    }
    string retTypeGetter()
    {
        return retType;
    }
};

#endif