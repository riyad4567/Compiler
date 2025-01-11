#include <iostream>
using namespace std;

class SymbolInfo
{
private:
    string name;
    string type;

public:
    SymbolInfo *pointer;
    SymbolInfo(string name, string type)
    {
        this->name = name;
        this->type = type;
        this->pointer=nullptr;
    }
    string nameGetter()
    {
        return this->name;
    }
    string typeGetter()
    {
        return type;
    }
    void nameSetter(string name)
    {
        this->name = name;
    }
    void typeSetter(string type)
    {
        this->type = type;
    }
};

