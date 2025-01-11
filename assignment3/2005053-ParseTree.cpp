#include <bits/stdc++.h>
// #include<ofstream>
#include "2005053-SymbolInfo.h"

using namespace std;

class ParseTree
{
private:
       SymbolInfo *currSymbol;

public:
       SymbolInfo *currSymbolGetter()
       {
              return currSymbol;
       }
       void currSymbolSetter(SymbolInfo *ptr)
       {
              currSymbol = ptr;
       }
       void printParse(FILE *parseout, SymbolInfo *node, int level = 0)
       {
              // SymbolInfo *store=currSymbol;
              // cout<<node->childArr.size()<<endl;
              bool flag=false;
              for (int i = 0; i < level; i++)
              {
                     fprintf(parseout, " ");
              }
              if (node->exprGetter().size() == 0)
              {
                     fprintf(parseout, "%s : %s\t", node->typeGetter().c_str(), node->nameGetter().c_str());
                     flag=true;
              }
              else
              {
                     fprintf(parseout, "%s \t", node->exprGetter().c_str());
              }
              fprintf(parseout, "<Line: ");
              if(flag)
              {
                 fprintf(parseout,"%d>\n",node->startlineGetter());
              }
              else{
                 fprintf(parseout,"%d-%d>\n",node->startlineGetter(),node->endlineGetter());
              }
              if (node->childArr.size() == 0)
              {
                     return;
              }
              for (SymbolInfo *child : node->childArr)
              {
                     printParse(parseout, child, level + 1);
              }
              // currSymbol=store;
       }
};