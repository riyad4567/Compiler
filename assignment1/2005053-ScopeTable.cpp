#include <iostream>
#include "2005053-SymbolInfo.cpp"
using namespace std;

class ScopeTable
{
private:
    int buckets;
    string id;
    int count;
    SymbolInfo **arr;
    ScopeTable *parentScope;
    int *chainLength;

public:
    ScopeTable(int buckets)
    {
        this->buckets = buckets;
        this->id = "";
        this->parentScope = nullptr;
        this->count = 0;
        this->arr = new SymbolInfo *[buckets];
        this->chainLength = new int[buckets];
        for (int i = 0; i < buckets; i++)
        {

            // if(arr[i]!=nullptr)
            //  cout<<"aye"<<endl;
            arr[i] = nullptr;
            chainLength[i] = 0;
        }
    }
    ~ScopeTable()
    {
        for (int i = 0; i < buckets; i++)
        {
            if (arr[i] != nullptr)
            {
                delete arr[i];
                //arr[i] = nullptr;
            }
        }
        delete[] arr;
        delete[] chainLength;
    }
    void SetParent(ScopeTable *ob)
    {
        this->parentScope = ob;
    }
    int *GetChainLength()
    {
        return this->chainLength;
    }
    int getCount()
    {
        return this->count;
    }
    void setCount(int count)
    {
        this->count = count;
    }
    ScopeTable *getParent()
    {
        return this->parentScope;
    }
    void setId(string id)
    {
        this->id = id;
    }
    string getId()
    {
        return this->id;
    }
    int HashFunction(string str)
    {
        unsigned long long int hash = 0, i = 0;
        unsigned long long int len = str.length();

        for (i = 0; i < len; i++)
        {
            hash = (str[i]) + (hash << 6) + (hash << 16) - hash;
        }
        return (hash % buckets);
    }

    bool Insert(string name, string type)
    {
        SymbolInfo *obj = new SymbolInfo(name, type);
        int index = HashFunction(name);
        int size = 0;
        // cout<<"Hello"<<endl;
        SymbolInfo *temp = arr[index];
        SymbolInfo *prev = temp;
        SymbolInfo *head=temp;
        while (temp != nullptr)
        {   
            if ((temp->nameGetter()).compare(name) == 0)
            {
                return false;
            }
            size++;
            prev = temp;
            temp = temp->pointer;
             //cout<<"Hello"<<endl;
        }
        if (head == nullptr)
        {
            arr[index] = obj;
            chainLength[index] = 1;
        }
        else
        {
            prev->pointer = obj;
            chainLength[index] = size + 1;
        }
        return true;
    }
    SymbolInfo *LookUp(string name)
    {
        int index = HashFunction(name);
        SymbolInfo *temp = arr[index];
        while (temp != nullptr)
        {

            if ((temp->nameGetter()).compare(name) == 0)
            {
                return temp;
            }
            temp = temp->pointer;
        }

        return nullptr;
    }
    int GetPosition(SymbolInfo *temp)
    {   
        int count=0;
        while(temp != nullptr)
        {
            temp = temp->pointer;
            count++;
        }
        return count;
    }
    bool Delete(string name)
    {
        int index = HashFunction(name);
        SymbolInfo *temp = arr[index];
        SymbolInfo *prev = temp;
        SymbolInfo *head = temp;

        bool flag = false;
        while (temp != nullptr)
        {

            if ((temp->nameGetter()).compare(name) == 0)
            {
                flag = true;
                break;
            }
            prev = temp;
            temp = temp->pointer;
        }
        if (flag)
        {
            if (prev == head)
            {
                arr[index] = head->pointer;
                delete temp;
                //delete head;
            }
            else if (temp->pointer == nullptr)
            {
                prev->pointer = nullptr;
                delete temp;
            }
            else
            {
                prev->pointer = temp->pointer;
                delete temp;
            }
            chainLength[index] -= 1;
            return true;
        }
        else
        {
            return false;
        }
    }
    void Print()
    {
        cout << "\tScopeTable# " << id << endl;
        for (int i = 0; i < buckets; i++)
        {
            cout << "\t" << i + 1;
            if (arr[i] != nullptr)
            {
                // cout<<"aye"<<endl;
                SymbolInfo *temp = arr[i];
                while (temp != nullptr)
                {
                    cout << " --> (" << temp->nameGetter() << "," << temp->typeGetter() << ")";
                    temp = temp->pointer;
                }
            }
            cout<<endl;
        }
    }
};