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
    int arraySize;
    int Offset;
    int argumentNumber;
    bool isGlobal;
    int scope;
    string nextlabel;
    string truelabel;
    string falselabel;

public:
    SymbolInfo *pointer;
    vector<SymbolInfo *> listOfParameter;
    vector<SymbolInfo *> childArr;
    vector<SymbolInfo *> varList;
    SymbolInfo()
    {
        this->name = "";
        this->type = "";
        this->arraySize = 0;
        this->Offset = -1;
        this->argumentNumber = 0;
        this->pointer = nullptr;
        this->listOfParameter = {};
        this->checkArray = false;
        this->checkFunction = false;
        this->childArr = {};
        this->varList = {};
        this->isGlobal = false;
        this->scope = 1;
        this->nextlabel="";
        this->truelabel="";
        this->falselabel="";
    }
    SymbolInfo(string name, string type)
    {
        this->name = name;
        this->arraySize = 0;
        this->Offset = -1;
        this->argumentNumber = 0;
        this->type = type;
        this->pointer = nullptr;
        this->listOfParameter = {};
        this->checkArray = false;
        this->childArr = {};
        this->varList = {};
        this->checkFunction = false;
        this->isGlobal = false;
        this->scope = 1;
        this->nextlabel="";
        this->truelabel="";
        this->falselabel="";
    }
    void startlineSetter(int n)
    {
        startline = n;
    }
    void endlineSetter(int n)
    {
        endline = n;
    }
    void addChild(vector<SymbolInfo *> listofChild)
    {
        for (SymbolInfo *child : listofChild)
        {
            childArr.push_back(child);
        }
    }
    void checkArraySetter(bool b)
    {
        checkArray = b;
    }
    void setScope(int n)
    {
        scope = n;
    }
    int getScope()
    {
        return scope;
    }
    void exprSetter(string s)
    {
        expr = s;
    }
    void isGlobalSetter(bool a)
    {
        isGlobal = a;
    }
    bool isGlobalGetter()
    {
        return isGlobal;
    }
    string exprGetter()
    {
        return expr;
    }
    void offsetSetter(int a)
    {
        Offset = a;
    }
    void argNumberSetter(int n)
    {
        argumentNumber = n;
    }
    void sizeSetter(int n)
    {
        arraySize = n;
    }
    void checkFunctionSetter(bool b)
    {
        checkFunction = b;
    }
    void retTypeSetter(string s)
    {
        this->retType = s;
    }
    void varTypeSetter(string s)
    {
        this->varType = s;
    }
    void setNextLabel(string str)
    {
        this->nextlabel=str;
    }
    void setTrueLabel(string str)
    {
        this->truelabel=str;
    }
    void setFalseLabel(string str)
    {
        this->falselabel=str;
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
    int argNumberGetter()
    {
        return argumentNumber;
    }
    int offsetGetter()
    {
        return Offset;
    }
    int sizeGetter()
    {
        return arraySize;
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
    string getNextLabel()
    {
        return nextlabel;
    }
    string getTrueLabel()
    {
        return truelabel;
    }
    string getFalseLabel()
    {
        return falselabel;
    }
};

#endif