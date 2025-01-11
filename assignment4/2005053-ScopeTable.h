#ifndef SCOPETABLE_H_
#define SCOPETABLE_H_

#include <iostream>
#include "2005053-SymbolInfo.h"
using namespace std;

class ScopeTable
{
private:
    int buckets;
    int id;

   
    ScopeTable *parentScope;
    int *chainLength;

public:
     SymbolInfo **arr;
    ScopeTable(int buckets)
    {
        this->buckets = buckets;
        this->id = 0;
        this->parentScope = nullptr;
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
                // arr[i] = nullptr;
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
    ScopeTable *getParent()
    {
        return this->parentScope;
    }
    void setId(int id)
    {
        this->id = id;
    }
    int getId()
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
        SymbolInfo *head = temp;
        while (temp != nullptr)
        {
            if ((temp->nameGetter()).compare(name) == 0)
            {
                return false;
            }
            size++;
            prev = temp;
            temp = temp->pointer;
            // cout<<"Hello"<<endl;
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
        int count = 0;
        while (temp != nullptr)
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
                // delete head;
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

    void Print(FILE *logout)
    {
        // // cout << "\tScopeTable# " << id << endl;
        // string ID = to_string(id);
        // fprintf(logout, "\tScopeTable# %s\n", ID.c_str());
        // for (int i = 0; i < buckets; i++)
        // {
        //     // cout << "\t" << i + 1;

        //     if (arr[i] != nullptr)
        //     {
        //         // cout<<"aye"<<endl;
        //         fprintf(logout, "\t%d", i + 1);
        //         SymbolInfo *temp = arr[i];
        //         bool flag = false;
        //         while (temp != nullptr)
        //         {
        //             // cout << " --> (" << temp->nameGetter() << "," << temp->typeGetter() << ")";
        //             // const char* str = s.c_str();
        //             // fprintf(logout," --> (%s,%s)" ,temp->nameGetter().c_str(),temp->typeGetter().c_str());
        //             if (temp->checkFunctionGetter())
        //             {
        //                 if (flag)
        //                 {
        //                     fprintf(logout, " <%s, FUNCTION, Width: %d, Offset: %d, IsParam: %d,Scope: %d,RetType: %s>", temp->nameGetter().c_str(),temp->widthGetter(),temp->offsetGetter(),temp->paramGetter(),id,temp->retTypeGetter().c_str());
        //                 }
        //                 else
        //                 {
        //                     fprintf(logout, " --> <%s, FUNCTION, Width: %d, Offset: %d, IsParam: %d,Scope: %d,RetType: %s>", temp->nameGetter().c_str(),temp->widthGetter(),temp->offsetGetter(),temp->paramGetter(),id,temp->retTypeGetter().c_str());
        //                 }
        //             }
        //             else if (temp->checkArrayGetter())
        //             {
        //                 if (flag)
        //                 {
        //                     fprintf(logout, " <%s, ARRAY, Width: %d, Offset: %d, IsParam: %d,Scope: %d>", temp->nameGetter().c_str(),temp->widthGetter(),temp->offsetGetter(),temp->paramGetter(),id);
        //                 }
        //                 else
        //                 {
        //                     fprintf(logout, " --> <%s, ARRAY, Width: %d, Offset: %d, IsParam: %d,Scope: %d>", temp->nameGetter().c_str(),temp->widthGetter(),temp->offsetGetter(),temp->paramGetter(),id);
        //                 }
        //             }
        //             else if (temp->typeGetter().compare("ID") == 0)
        //             {
        //                 if (flag)
        //                 {
        //                     fprintf(logout, " <%s, %s, Width: %d, Offset: %d, IsParam: %d,Scope: %d>", temp->nameGetter().c_str(), temp->varTypeGetter().c_str(),temp->widthGetter(),temp->offsetGetter(),temp->paramGetter(),id);
        //                 }
        //                 else
        //                 {
        //                     fprintf(logout, " --> <%s, %s, Width: %d, Offset: %d, IsParam: %d,Scope: %d>", temp->nameGetter().c_str(), temp->varTypeGetter().c_str(),temp->widthGetter(),temp->offsetGetter(),temp->paramGetter(),id);
        //                 }
        //             }
        //             else
        //             {
        //                 if (flag)
        //                 {
        //                     fprintf(logout, " <%s, %s, Width: %d, Offset: %d, IsParam: %d,Scope: %d>", temp->nameGetter().c_str(), temp->typeGetter().c_str(),temp->widthGetter(),temp->offsetGetter(),temp->paramGetter(),id);
        //                 }
        //                 else
        //                 {
        //                     fprintf(logout, " --> <%s, %s, Width: %d, Offset: %d, IsParam: %d,Scope: %d>", temp->nameGetter().c_str(), temp->typeGetter().c_str(),temp->widthGetter(),temp->offsetGetter(),temp->paramGetter(),id);
        //                 }
        //             }
        //             temp = temp->pointer;
        //             flag = true;
        //         }
        //         //fprintf(logout, "\n");
        //     }
        //      fprintf(logout,"\n");
        //     // cout<<endl;
        // }
        
    }
};


#endif