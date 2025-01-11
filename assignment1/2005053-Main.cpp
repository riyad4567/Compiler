#include <bits/stdc++.h>
#include "2005053-SymbolTable.cpp"
using namespace std;

int main()
{

    string str, name, type, first;
    char operation;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // fout.clear();
    int k = 0, n, index, position,flag=0;
    getline(cin, first);
    istringstream num(first);
    num >> n;
    bool check;
    SymbolTable *obj = new SymbolTable(n);
    cout << "\tScopeTable# 1 created" << endl;
    while (getline(cin, str))
    {
        k++;
        istringstream input(str);
        input >> operation;
        cout << "Cmd " << k << ": " << str << endl;
        switch (operation)
        {
        case 'I':
        {
            if (!(input >> name >> type) || (input >> ws).peek() != EOF)
            {
                cout << "\tWrong number of arguments for the command I" << endl;
            }
            else
            {
                // cout<<name<<type<<endl;
                check = obj->Insert(name, type);
                if (check)
                {
                    index = obj->GetCurrent()->HashFunction(name);
                    // cout<<index<<endl;
                    position = obj->GetCurrent()->GetChainLength()[index];
                    cout << "\tInserted  at position <" << index + 1 << ", " << position << "> of ScopeTable# " << obj->GetCurrent()->getId() << endl;
                }
                else
                {
                    cout << "\t'" << name << "' already exists in the current ScopeTable# " << obj->GetCurrent()->getId() << endl;
                }
            }
            // obj->Print();
            break;
        }
        case 'D':
        {
            if (!(input >> name) || (input >> ws).peek() != EOF)
            {
                cout << "\tWrong number of arguments for the command D" << endl;
            }
            else
            {
                // ScopeTable *temp=obj->GetCurrent();
                SymbolInfo *sym = obj->GetCurrent()->LookUp(name);
                int pos = obj->GetCurrent()->GetPosition(sym);
                // cout<<pos<<" "<<endl;
                check = obj->Remove(name);
                if (check)
                {
                    index = obj->GetCurrent()->HashFunction(name);
                    // cout<<index<<endl;
                    // cout<<obj->GetCurrent()->GetChainLength()[index]<<endl;
                    position = obj->GetCurrent()->GetChainLength()[index] - pos + 2;
                    cout << "\tDeleted '" << name << "' from position <" << index + 1 << ", " << position << "> of ScopeTable# " << obj->GetCurrent()->getId() << endl;
                }
                else
                {
                    cout << "\tNot found in the current ScopeTable# " << obj->GetCurrent()->getId() << endl;
                }
            }
            // obj->Print();
            break;
        }
        case 'L':
        {
            if (!(input >> name) || (input >> ws).peek() != EOF)
            {
                cout << "\tWrong number of arguments for the command L" << endl;
            }
            else
            {
                ScopeTable *temp = obj->GetCurrent();
                // cout<<"Before"<<endl;
                SymbolInfo *sym = obj->LookUp(name);
                // cout<<sym<<endl;
                if (sym == nullptr)
                {
                    cout << "\t'" << name << "' not found in any of the ScopeTables" << endl;
                }
                else
                {
                    index = obj->GetCurrent()->HashFunction(name);
                    // cout<<index<<endl;
                    position = obj->GetCurrent()->GetChainLength()[index] - obj->GetCurrent()->GetPosition(sym) + 1;
                    cout << "\t'" << name << "' found at position <" << index + 1 << ", " << position << "> of ScopeTable# " << obj->GetCurrent()->getId() << endl;
                }
                obj->SetCurrent(temp);
            }
            // obj->Print();
            break;
        }
        case 'P':
        {
            char var;
            if (!(input >> var) || (input >> ws).peek() != EOF)
            {
                cout << "\tWrong number of arguments for the command P" << endl;
            }
            else
            {

                if (var == 'C')
                {
                    obj->PrintCurrentScope();
                }
                else if (var == 'A')
                {
                    obj->PrintAllScope();
                }
                else
                {
                    cout << "\tInvalid argument for the command P" << endl;
                }
            }
            // obj->Print();
            break;
        }
        case 'E':
        {
            if (((input >> ws).peek() != EOF))
            {
                cout << "\tWrong number of arguments for the command E" << endl;
            }
            else
            {
                if (obj->GetCurrent()->getId().compare("1") != 0)
                {
                    cout << "\tScopeTable# " << obj->GetCurrent()->getId() << " deleted" << endl;
                    obj->ExitScope();
                }
                else
                {
                    cout << "\tScopeTable# 1 cannot be deleted" << endl;
                }
            }
            // obj->Print();
            break;
        }
        case 'S':
        {
            if (((input >> ws).peek() != EOF))
            {
                cout << "\tWrong number of arguments for the command S" << endl;
            }
            else
            {
                obj->EnterScope();
                cout << "\tScopeTable# " << obj->GetCurrent()->getId() << " created" << endl;
            }
            // obj->Print();
            break;
        }
        case 'Q':
        {
             flag=1;  
             break;           
        }
        default:
            cout << "Invalid command" << endl;
            break;
        }
        if(flag)
        {
            break;
        }
    }
    delete obj;
    fclose(stdout);
    fclose(stdin);
    return 0;
}
