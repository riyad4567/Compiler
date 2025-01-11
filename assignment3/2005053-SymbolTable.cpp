#include <iostream>
#include "2005053-ScopeTable.cpp"
using namespace std;

class SymbolTable
{
private:
   ScopeTable *current;
   int bucket;
   int count;

public:
   SymbolTable(int n)
   {
      ScopeTable *obj = new ScopeTable(n);
      current = obj;
      this->count = 1;
      current->setId(1);
      bucket = n;
   }
   ~SymbolTable()
   {  
      //cout<<"DESTROYED"<<endl;
      while (current!= nullptr)
      {
         //cout << "\tScopeTable# " <<current->getId() << " deleted" << endl;
         ExitScope();
      }
   }
   ScopeTable *GetCurrent()
   {
      return this->current;
   }
   void SetCurrent(ScopeTable *obj)
   {
      this->current = obj;
   }
   void EnterScope()
   {
      ScopeTable *obj = new ScopeTable(bucket);
      obj->SetParent(current);
      //current->setCount(current->getCount() + 1);
      //string formate = current->getId() + "." + to_string(current->getCount());
      obj->setId(++count);
      current = obj;
   }
   void ExitScope()
   {
      ScopeTable *temp = current->getParent();
      delete current;
      current = temp;
   }
   bool Insert(string name, string type)
   {
      return current->Insert(name, type);
   }
   SymbolInfo *LookUp(string name)
   { 
      ScopeTable *temp=current;
      while (current != nullptr)
      {
         SymbolInfo *obj = current->LookUp(name);
         if (obj != nullptr)
         { 
            current=temp;
            return obj;
         }
         // cout<<"Unable to find symbol "<<endl;
         current = current->getParent();
         // cout<<current<<endl;
      }
      // cout<<"G"<<endl;
      current=temp;
      return nullptr;
   }
   bool Remove(string name)
   {
      return current->Delete(name);
   }
   void PrintCurrentScope(FILE *logout)
   {
      current->Print(logout);
   }
   void PrintAllScope(FILE *logout)
   {
      ScopeTable *temp = current;
      while (temp != nullptr)
      {
         temp->Print(logout);
         temp = temp->getParent();
      }
   }
};
