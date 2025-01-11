
#include <iostream>
#include "2005053-SymbolInfo.h"
#include "2005053-SymbolTable.h"
using namespace std;
SymbolInfo *tempSym;
// SymbolTable *table;
FILE *text;
vector<SymbolInfo *> varGlobal;
FILE *assembly;
int label = 1;
int totalOffset = 0;
bool isArgument = false;
bool isMain = false;
class ICG
{
public:
    void fileVar(FILE *codeasm, FILE *codeout, vector<SymbolInfo *> globalvar)
    {
        text = codeout;
        assembly = codeasm;
        varGlobal = globalvar;
        // cout<<globalvar.size();
        // cout<<varGlobal.size();
        //  *table=obj;
    }
    void printGlobal()
    {
        for (SymbolInfo *var : varGlobal)
        {
            if (!var->checkArrayGetter())
            {
                fprintf(assembly, "\t\t%s DW 1 DUP (0000H)\n", var->nameGetter().c_str());
            }
            else
            {
                fprintf(assembly, "\t\t%s DW %d DUP (0000H)\n", var->nameGetter().c_str(), var->sizeGetter());
            }
        }
        fprintf(assembly, ".CODE\n");
    }
    void printOut()
    {
        fprintf(assembly, "print_output proc  ;print what is in ax\n\t\tPUSH AX\n\t\tPUSH BX\n\t\tPUSH CX\n\t\tPUSH DX\n\t\tPUSH SI\n\t\tLEA SI,number\n\t\tMOV BX,10\n\t\tADD SI,4\n\t\tCMP AX,0\n\t\tJNGE negate\n\t\tprint:\n\t\tXOR DX,DX\n\t\tDIV BX\n\
\t\tMOV [SI],DL\n\
\t\tADD [SI],'0'\n\
\t\tDEC SI\n\
\t\tCMP AX,0\n\
\t\tJNE print\n\
\t\tINC SI\n\
\t\tLEA DX,SI\n\
\t\tMOV AH,9\n\
\t\tINT 21H\n\
\t\tPOP SI\n\
\t\tPOP DX\n\
\t\tPOP CX\n\
\t\tPOP BX\n\
\t\tPOP AX\n\
\t\tRET\n\
\t\tnegate:\n\
\t\tPUSH AX\n\
\t\tMOV AH,2\n\
\t\tMOV DL,'-'\n\
\t\tINT 21H\n\
\t\tPOP AX\n\
\t\tNEG AX\n\
\t\tJMP print\n\
print_output ENDP\n\n");
    }
    void printNewLine()
    {
        fprintf(assembly, "new_line proc\n\t\tpush ax\n\t\tpush dx\n\t\tmov ah,2\n\t\tmov dl,0Dh\n\t\tint 21h\n\t\tmov ah,2\n\t\tmov dl,0Ah\n\t\tint 21h\n\t\tpop dx\n\t\tpop ax\n\t\tret\nnew_line endp\n");
    }

    string getLabel()
    {
        string str = "L" + to_string(label);
        label++;
        return str;
    }
    void init()
    {
        fprintf(assembly, ".MODEL SMALL\n.STACK 1000H\n.DATA\n\t\tnumber DB \"00000$\"\n");
    }
    void mainInit()
    {
        isMain = true;
        fprintf(assembly, "main PROC\n\t\tMOV AX, @DATA\n\t\tMOV DS, AX\n\t\tPUSH BP\n\t\tMOV BP, SP\n");
        fprintf(text, "main PROC\n\t\tMOV AX, @DATA\n\t\tMOV DS, AX\n\t\tPUSH BP\n\t\tMOV BP, SP\n");
    }

    void mainEnd()
    {
        isMain = false;
        fprintf(assembly, "%s:\n\t\tPOP BP\n\t\tMOV AX,4CH\n\t\tINT 21H\nmain ENDP\n", getLabel().c_str());
        fprintf(text, "%s:\n\t\tPOP BP\n\t\tMOV AX,4CH\n\t\tINT 21H\nmain ENDP\n", getLabel().c_str());
    }
    void varDeclaration(SymbolInfo *root)
    {
        int i = 1;
        tempSym = root->childArr[1];
        if (root->getScope() != 1)
        {
            // fprintf(text, "\t\tPUSH BP\n\t\tMOV BP, SP\n");
            // fprintf(assembly, "\t\tPUSH BP\n\t\tMOV BP, SP\n");
            //  printf("%d\n", tempSym->varList.size());
            for (SymbolInfo *var : tempSym->varList)
            {
                // cout<<var->nameGetter()<<" ";
                // cout<<var->typeGetter()<<endl;
                // var->widthSetter(2);
                if (!var->checkArrayGetter())
                {
                    var->offsetSetter(2 * i);
                    if (isMain)
                    {
                        fprintf(text, "\t\tSUB SP, %d\n", 2);
                    }
                    fprintf(assembly, "\t\tSUB SP, %d\n", 2);
                    // cout << var->offsetGetter() << endl;
                    i++;
                }
                else
                {
                    var->offsetSetter(2 * i);
                    if (isMain)
                    {
                        fprintf(text, "\t\tSUB SP, %d\n", 2 * var->sizeGetter());
                    }
                    fprintf(assembly, "\t\tSUB SP, %d\n", 2 * var->sizeGetter());
                    // cout <<"H"+ var->offsetGetter() << endl;
                    i += var->sizeGetter();
                }
            }
        }
        totalOffset += 2 * (i - 1);
        // else
        // {
        //     for (SymbolInfo *var : tempSym->varList)
        //     {
        //         fprintf(assembly, "\t\t%s DW 1 DUP (0000H)\n", var->nameGetter().c_str());
        //         i++;
        //     }
        // }
    }
    void funcInit(SymbolInfo *root)
    {

        tempSym = root->childArr[1];
        if (tempSym->nameGetter() == "main")
        {
            mainInit();
            // mainEnd();
        }
        else
        {
            fprintf(assembly, "%s PROC\n\t\tPUSH BP\n\t\tMOV BP, SP\n", tempSym->nameGetter().c_str());
        }
    }
    void funcEnd(SymbolInfo *root)
    {
        tempSym = root->childArr[1];
        if (tempSym->nameGetter() == "main")
        {
            // mainInit();
            mainEnd();
        }
        else
        {
            // fprintf(assembly, "%s:\n", getLabel().c_str());
            if (totalOffset)
            {
                fprintf(assembly, "\t\tADD SP, %d\n", totalOffset);
            }
            fprintf(assembly, "\t\tPOP BP\n");
            if (tempSym->argNumberGetter())
            {
                fprintf(assembly, "\t\tRET %d\n", 2 * tempSym->argNumberGetter());
            }
            else
            {
                fprintf(assembly, "\t\tRET\n");
            }
            fprintf(assembly, "%s ENDP\n", tempSym->nameGetter().c_str());
        }
    }
    string getAddress(SymbolInfo *node)
    {
        if (node->offsetGetter() == -1)
        {
            return node->nameGetter();
        }
        else
        {
            string str = "[BP" + (node->offsetGetter() ? ((node->offsetGetter() > 0 ? "-" : "+") + to_string(abs(node->offsetGetter()))) : "") + "]";
            return str;
        }
    }
    string relopSymbol(string str)
    {
        if (str == ">")
        {
            return "JG";
        }
        else if (str == "<")
        {
            return "JL";
        }
        else if (str == ">=")
        {
            return "JGE";
        }
        else if (str == "<=")
        {
            return "JLE";
        }
        else if (str == "==")
        {
            return "JE";
        }
        else if (str == "!=")
        {
            return "JNE";
        }
    }
    void relop(SymbolInfo *root)
    {
        string str = relopSymbol(root->childArr[1]->nameGetter());
        string trueLabel = "L" + to_string(label++);
        string falseLabel = "L" + to_string(label++);

        if (isMain)
        {
            fprintf(text, "\t\tCMP DX, AX\n");
            fprintf(text, "\t\t%s %s\n", str.c_str(), trueLabel.c_str());
            fprintf(text, "\t\tMOV AX, 0\n");
            fprintf(text, "\t\tJMP %s\n", falseLabel.c_str());
            fprintf(text, "%s:\n\t\tMOV AX, 1\n", trueLabel.c_str());
            fprintf(text, "%s:\n", falseLabel.c_str());
            fprintf(text, "\t\tPOP DX\n");
        }

        fprintf(assembly, "\t\tCMP DX, AX\n");
        fprintf(assembly, "\t\t%s %s\n", str.c_str(), trueLabel.c_str());
        fprintf(assembly, "\t\tMOV AX, 0\n");
        fprintf(assembly, "\t\tJMP %s\n", falseLabel.c_str());
        fprintf(assembly, "%s:\n\t\tMOV AX, 1\n", trueLabel.c_str());
        fprintf(assembly, "%s:\n", falseLabel.c_str());
        fprintf(assembly, "\t\tPOP DX\n");
    }
    void assignOP(SymbolInfo *root)
    {
        // cout << name << endl;

        string str = getAddress(root->childArr[0]->childArr[0]);

        if (!root->childArr[0]->childArr[0]->checkArrayGetter())
        {
            if (isMain)
                fprintf(text, "\t\tMOV %s, AX\n", str.c_str());
            fprintf(assembly, "\t\tMOV %s, AX\n", str.c_str());
        }
        else
        {
            if (isMain)
                fprintf(text, "\t\tPUSH CX\n\t\tMOV CX, AX\n");
            fprintf(assembly, "\t\tPUSH CX\n\t\tMOV CX, AX\n");
            if (root->childArr[0]->childArr[0]->offsetGetter() == -1)
            {
                fprintf(assembly, "\t\tLEA SI, %s\n\t\tSHL CX, 1\n\t\tADD SI, CX\n", root->childArr[0]->childArr[0]->nameGetter().c_str());
                if (isMain)
                    fprintf(text, "\t\tLEA SI, %s\n\t\tSHL CX, 1\n\t\tADD SI, CX\n", root->childArr[0]->childArr[0]->nameGetter().c_str());
            }
            else
            {
                fprintf(assembly, "\t\tSHL CX, 1\n\t\tADD CX, %d\n\t\tMOV SI, BP\n\t\tSUB SI, CX\n", root->childArr[0]->childArr[0]->offsetGetter());
                if (isMain)
                    fprintf(text, "\t\tSHL CX, 1\n\t\tADD CX, %d\n\t\tMOV SI, BP\n\t\tSUB SI, CX\n", root->childArr[0]->childArr[0]->offsetGetter());
            }
            fprintf(assembly, "\t\tPOP CX\n");
            if (isMain)
                fprintf(text, "\t\tPOP CX\n");
        }
    }
    void notOperation()
    {
        // int count=label;
        string trueLabel = "L" + to_string(label++);
        string falseLabel = "L" + to_string(label++);
        fprintf(assembly, "\t\tCMP AX, 0\n");
        fprintf(assembly, "\t\tJE %s\n\t\tMOV AX, 0\n", trueLabel.c_str());
        fprintf(assembly, "\t\tJMP %s\n", falseLabel.c_str());
        fprintf(assembly, "%s:\n\t\tMOV AX, 1\n", trueLabel.c_str());
        fprintf(assembly, "%s:\n", falseLabel.c_str());

        if (isMain)
        {
            fprintf(text, "\t\tCMP AX, 0\n");
            fprintf(text, "\t\tJE %s\n\t\tMOV AX, 0\n", trueLabel.c_str());
            fprintf(text, "\t\tJMP %s\n", falseLabel.c_str());
            fprintf(text, "%s:\n\t\tMOV AX, 1\n", trueLabel.c_str());
            fprintf(text, "%s:\n", falseLabel.c_str());
        }
    }
    void setParameter(SymbolInfo *root)
    {
        int i = 1;
        //    cout<< root->childArr[1]->nameGetter();
        int n = root->childArr[1]->listOfParameter.size();
        for (SymbolInfo *info : root->childArr[1]->listOfParameter)
        {
            int p = -2 * (n - i + 2);
            info->offsetSetter(p);
            i++;
            // cout<<"G";
            // info->setScope()
        }
    }
    void logicop(SymbolInfo *root)
    {
        if (root->childArr[1]->nameGetter() == "||")
        {
            if (isMain)
                fprintf(text, "\t\tOR AX, DX\n");
            fprintf(assembly, "\t\tOR AX, DX\n");
        }
        else if (root->childArr[1]->nameGetter() == "&&")
        {
            fprintf(assembly, "\t\tAND AX, DX\n");
            if (isMain)
                fprintf(text, "\t\tAND AX, DX\n");
        }
        fprintf(assembly, "\t\tPOP DX\n");
        if (isMain)
            fprintf(text, "\t\tPOP DX\n");
    }
    void incOp(SymbolInfo *root)
    {
        tempSym = root->childArr[0]->childArr[0];
        // cout<<tempSym->nameGetter()<<endl;
        string str = getAddress(tempSym);
        if (!tempSym->checkArrayGetter())
        {
            if (tempSym->offsetGetter() != -1)
            {
                if (isMain)
                {
                    fprintf(text, "\t\tPUSH AX\n");
                    fprintf(text, "\t\tINC AX\n");
                    fprintf(text, "\t\tMOV %s, AX\n", str.c_str());
                    fprintf(text, "\t\tPOP AX\n");
                }

                fprintf(assembly, "\t\tPUSH AX\n");
                fprintf(assembly, "\t\tINC AX\n");
                fprintf(assembly, "\t\tMOV %s, AX\n", str.c_str());
                fprintf(assembly, "\t\tPOP AX\n");
            }
            else
            {
                fprintf(assembly, "\t\tINC %s\n", str.c_str());
                if (isMain)
                    fprintf(text, "\t\tINC %s\n", str.c_str());
            }
        }
        else
        {
            fprintf(assembly, "\t\tPUSH AX\n");
            fprintf(assembly, "\t\tINC AX\n");
            // fprintf(text, "\t\tMOV %s, AX\n", str.c_str());
            fprintf(assembly, "\t\tMOV [SI], AX\n");
            fprintf(assembly, "\t\tPOP AX\n");

            if (isMain)
            {
                fprintf(text, "\t\tPUSH AX\n");
                fprintf(text, "\t\tINC AX\n");
                fprintf(text, "\t\tMOV [SI], AX\n");
                fprintf(text, "\t\tPOP AX\n");
            }
        }
    }

    void decOp(SymbolInfo *root)
    {
        tempSym = root->childArr[0]->childArr[0];
        // cout<<tempSym->nameGetter()<<endl;
        string str = getAddress(tempSym);
        if (!tempSym->checkArrayGetter())
        {
            if (tempSym->offsetGetter() != -1)
            {

                // fprintf(text, "\t\tMOV AX, %s\n", str.c_str());
                // fprintf(assembly, "\t\tMOV AX, %s\n", str.c_str());
                fprintf(assembly, "\t\tPUSH AX\n");
                fprintf(assembly, "\t\tDEC AX\n");
                // fprintf(text, "\t\tMOV %s, AX\n", str.c_str());
                fprintf(assembly, "\t\tMOV %s, AX\n", str.c_str());
                fprintf(assembly, "\t\tPOP AX\n");
                // fprintf(text, "\t\tPOP AX\n");

                if (isMain)
                {
                    fprintf(text, "\t\tPUSH AX\n");
                    fprintf(text, "\t\tDEC AX\n");
                    fprintf(text, "\t\tMOV %s, AX\n", str.c_str());
                    fprintf(text, "\t\tPOP AX\n");
                }
            }
            else
            {
                fprintf(assembly, "\t\tDEC %s\n", str.c_str());
                if (isMain)
                    fprintf(text, "\t\tDEC %s\n", str.c_str());
            }
        }
        else
        {
            fprintf(assembly, "\t\tPUSH AX\n");
            fprintf(assembly, "\t\tDEC AX\n");
            // fprintf(text, "\t\tMOV %s, AX\n", str.c_str());
            fprintf(assembly, "\t\tMOV [SI], AX\n");
            fprintf(assembly, "\t\tPOP AX\n");
            if (isMain)
            {
                fprintf(text, "\t\tPUSH AX\n");
                fprintf(text, "\t\tINC AX\n");
                fprintf(text, "\t\tMOV [SI], AX\n");
                fprintf(text, "\t\tPOP AX\n");
            }
        }
    }

    void mulOP(SymbolInfo *root)
    {
        // fprintf(assembly,"\t\tPUSH CX\n");
        if (isMain)
        {
            fprintf(text, "\t\tPUSH DX\n");
        }
        fprintf(assembly, "\t\tPUSH DX\n");
        if (root->childArr[1]->nameGetter() == "*")
        {
            if (isMain)
                fprintf(text, "\t\tCWD\n\t\tMUL CX\n");
            fprintf(assembly, "\t\tCWD\n\t\tMUL CX\n");
        }
        else if (root->childArr[1]->nameGetter() == "%")
        {
            // fprintf(text, "\t\tSUB DX, AX\n");
            // need to alter CX, AX
            fprintf(assembly, "\t\tPUSH AX\n\t\tPUSH CX\n\t\tPOP AX\n\t\tPOP CX\n");
            fprintf(assembly, "\t\tCWD\n\t\tDIV CX\n");
            fprintf(assembly, "\t\tMOV AX, DX\n");

            if (isMain)
            {
                fprintf(text, "\t\tPUSH AX\n\t\tPUSH CX\n\t\tPOP AX\n\t\tPOP CX\n");
                fprintf(text, "\t\tCWD\n\t\tDIV CX\n");
                fprintf(text, "\t\tMOV AX, DX\n");
            }
        }
        else
        {
            // need to alter CX, AX
            fprintf(assembly, "\t\tPUSH AX\n\t\tPUSH CX\n\t\tPOP AX\n\t\tPOP CX\n");
            fprintf(assembly, "\t\tCWD\n\t\tDIV CX\n");
            if (isMain)
            {
                fprintf(text, "\t\tPUSH AX\n\t\tPUSH CX\n\t\tPOP AX\n\t\tPOP CX\n");
                fprintf(text, "\t\tCWD\n\t\tDIV CX\n");
            }
        }
        fprintf(assembly, "\t\tPOP DX\n");
        fprintf(assembly, "\t\tPOP CX\n");
        if (isMain)
        {
            fprintf(text, "\t\tPOP DX\n");
            fprintf(text, "\t\tPOP CX\n");
        }
    }
    void addOPUnary(SymbolInfo *root)
    {
        if (root->childArr[0]->nameGetter() == "-")
        {
            // fprintf(text, "\t\tMOV DX, AX\n");
            fprintf(assembly, "\t\tNEG AX\n");
            if (isMain)
                fprintf(text, "\t\tNEG AX\n");
        }
    }
    void addTerm(SymbolInfo *root)
    {
        // fprintf(text,"\t\tMOV DX, AX\n");
        if (root->childArr[1]->nameGetter() == "+")
        {
            if (isMain)
                fprintf(text, "\t\tADD AX, DX\n");
            fprintf(assembly, "\t\tADD AX, DX\n");
        }
        else
        {
            if (isMain)
                fprintf(text, "\t\tSUB DX, AX\n");
            fprintf(assembly, "\t\tSUB DX, AX\n");
            fprintf(assembly, "\t\tMOV AX, DX\n");
            if (isMain)
                fprintf(text, "\t\tMOV AX, DX\n");
        }
        fprintf(assembly, "\t\tPOP DX\n");
        if (isMain)
            fprintf(text, "\t\tPOP DX\n");
    }

    void writeICG(SymbolInfo *root)
    {
        if (root->exprGetter() == "start : program")
        {
            writeICG(root->childArr[0]);
        }
        else if (root->exprGetter() == "program : program unit")
        {
            writeICG(root->childArr[0]);
            writeICG(root->childArr[1]);
        }
        else if (root->exprGetter() == "program : unit")
        {
            writeICG(root->childArr[0]);
        }
        else if (root->exprGetter() == "unit : var_declaration")
        {
            writeICG(root->childArr[0]);
        }
        else if (root->exprGetter() == "unit : func_declaration")
        {
            writeICG(root->childArr[0]);
        }

        else if (root->exprGetter() == "unit : func_definition")
        {
            writeICG(root->childArr[0]);
        }

        else if (root->exprGetter() == "compound_statement : LCURL statements RCURL")
        {
            writeICG(root->childArr[1]);
        }

        else if (root->exprGetter() == "statements : statement")
        {
            // fprintf(assembly,"%s",getLabel().c_str());
            root->childArr[0]->setNextLabel(getLabel());
            // cout<<root->childArr[0]->getNextLabel()<<endl;
            writeICG(root->childArr[0]);
            fprintf(assembly, "%s:\n", root->childArr[0]->getNextLabel().c_str());
            if (isMain)
                fprintf(text, "%s:\n", root->childArr[0]->getNextLabel().c_str());
        }

        else if (root->exprGetter() == "statements : statements statement")
        {
            writeICG(root->childArr[0]);
            root->childArr[1]->setNextLabel(getLabel());
            // cout<<root->childArr[1]->getNextLabel()<<endl;
            writeICG(root->childArr[1]);
            fprintf(assembly, "%s:\n", root->childArr[1]->getNextLabel().c_str());
            if (isMain)
                fprintf(text, "%s:\n", root->childArr[1]->getNextLabel().c_str());
        }

        else if (root->exprGetter() == "statement : var_declaration")
        {
            // fprintf(assembly,"%s",getLabel().c_str());
            writeICG(root->childArr[0]);
            // fprintf(assembly,"%s:\n",root->getNextLabel().c_str());
        }

        else if (root->exprGetter() == "statement : expression_statement")
        {
            // fprintf(assembly,"%s",getLabel().c_str());
            writeICG(root->childArr[0]);
            // fprintf(assembly,"%s:\n",root->getNextLabel().c_str());
        }

        else if (root->exprGetter() == "statement : compound_statement")
        {
            // fprintf(assembly,"%s",getLabel().c_str());
            writeICG(root->childArr[0]);
            // fprintf(assembly,"%s:\n",root->getNextLabel().c_str());
        }

        else if (root->exprGetter() == "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement")
        {
            // fprintf(assembly,"%s",getLabel().c_str());
            root->childArr[2]->setNextLabel(getLabel());
            writeICG(root->childArr[2]);

            root->childArr[3]->setTrueLabel(getLabel());
            root->childArr[3]->setFalseLabel(root->getNextLabel());
            fprintf(assembly, "%s:\n", root->childArr[2]->getNextLabel().c_str());
            if (isMain)
                fprintf(text, "%s:\n", root->childArr[2]->getNextLabel().c_str());
            writeICG(root->childArr[3]);

            root->childArr[4]->setNextLabel(root->childArr[2]->getNextLabel());
            fprintf(assembly, "\t\tCMP AX, 0\n");
            fprintf(assembly, "\t\tJE %s\n", root->childArr[3]->getFalseLabel().c_str());
            fprintf(assembly, "%s:\n", root->childArr[3]->getTrueLabel().c_str());
            if (isMain)
            {
                fprintf(text, "\t\tCMP AX, 0\n");
                fprintf(text, "\t\tJE %s\n", root->childArr[3]->getFalseLabel().c_str());
                fprintf(text, "%s:\n", root->childArr[3]->getTrueLabel().c_str());
            }
            writeICG(root->childArr[6]);
            root->childArr[6]->setNextLabel(getLabel());
            fprintf(assembly, "%s:\n", root->childArr[6]->getNextLabel().c_str());
            if (isMain)
                fprintf(text, "%s:\n", root->childArr[6]->getNextLabel().c_str());

            writeICG(root->childArr[4]);
            fprintf(assembly, "\t\tJMP %s\n", root->childArr[4]->getNextLabel().c_str());
            if (isMain)
                fprintf(text, "\t\tJMP %s\n", root->childArr[4]->getNextLabel().c_str());
            // fprintf(assembly,"%s:\n",root->childArr[3]->getFalseLabel().c_str());

            // fprintf(assembly,"%s:\n",root->getNextLabel());
        }

        else if (root->exprGetter() == "statement : IF LPAREN expression RPAREN statement")
        {
            // fprintf(assembly,"%s",getLabel().c_str());
            root->childArr[2]->setFalseLabel(root->getNextLabel());
            root->childArr[2]->setTrueLabel(getLabel());
            writeICG(root->childArr[2]);
            fprintf(assembly, "\t\tCMP AX, 0\n");
            fprintf(assembly, "\t\tJE %s\n", root->childArr[2]->getFalseLabel().c_str());
            fprintf(assembly, "%s:\n", root->childArr[2]->getTrueLabel().c_str());
            root->childArr[4]->setNextLabel(root->getNextLabel());

            if (isMain)
            {
                fprintf(text, "\t\tCMP AX, 0\n");
                fprintf(text, "\t\tJE %s\n", root->childArr[2]->getFalseLabel().c_str());
                fprintf(text, "%s:\n", root->childArr[2]->getTrueLabel().c_str());
                root->childArr[4]->setNextLabel(root->getNextLabel());
            }
            // fprintf(assembly,"%s",getLabel().c_str());
            writeICG(root->childArr[4]);
            // fprintf(assembly,"%s:\n",root->childArr[2]->getFalseLabel().c_str());
        }

        else if (root->exprGetter() == "statement : IF LPAREN expression RPAREN statement ELSE statement")
        {
            root->childArr[2]->setTrueLabel(getLabel());
            root->childArr[2]->setFalseLabel(getLabel());

            // fprintf(assembly,"%s",getLabel().c_str());
            writeICG(root->childArr[2]);

            fprintf(assembly, "\t\tCMP AX, 0\n");
            fprintf(assembly, "\t\tJE %s\n", root->childArr[2]->getFalseLabel().c_str());
            fprintf(assembly, "%s:\n", root->childArr[2]->getTrueLabel().c_str());

            if (isMain)
            {
                fprintf(text, "\t\tCMP AX, 0\n");
                fprintf(text, "\t\tJE %s\n", root->childArr[2]->getFalseLabel().c_str());
                fprintf(text, "%s:\n", root->childArr[2]->getTrueLabel().c_str());
            }

            root->childArr[4]->setNextLabel(root->getNextLabel());
            writeICG(root->childArr[4]);
            fprintf(assembly, "\t\tJMP %s\n", root->getNextLabel().c_str());
            fprintf(assembly, "%s:\n", root->childArr[2]->getFalseLabel().c_str());
            if (isMain)
            {
                fprintf(text, "\t\tJMP %s\n", root->getNextLabel().c_str());
                fprintf(text, "%s:\n", root->childArr[2]->getFalseLabel().c_str());
            }
            root->childArr[6]->setNextLabel(root->getNextLabel());
            writeICG(root->childArr[6]);

            // fprintf(assembly,"%s:\n",root->getNextLabel().c_str());
        }

        else if (root->exprGetter() == "statement : WHILE LPAREN expression RPAREN statement")
        {
            // fprintf(assembly,"%s",getLabel().c_str());
            string begin = getLabel();

            root->childArr[2]->setTrueLabel(getLabel());
            root->childArr[2]->setFalseLabel(root->getNextLabel());
            if (isMain)
                fprintf(text, "%s:\n", begin.c_str());
            fprintf(assembly, "%s:\n", begin.c_str());
            writeICG(root->childArr[2]);

            fprintf(assembly, "\t\tCMP AX, 0\n");
            fprintf(assembly, "\t\tJE %s\n", root->childArr[2]->getFalseLabel().c_str());
            fprintf(assembly, "%s:\n", root->childArr[2]->getTrueLabel().c_str());

            if (isMain)
            {
                fprintf(text, "\t\tCMP AX, 0\n");
                fprintf(text, "\t\tJE %s\n", root->childArr[2]->getFalseLabel().c_str());
                fprintf(text, "%s:\n", root->childArr[2]->getTrueLabel().c_str());
            }

            root->childArr[4]->setNextLabel(begin);
            writeICG(root->childArr[4]);
            fprintf(assembly, "\t\tJMP %s\n", begin.c_str());
            if (isMain)
                fprintf(text, "\t\tJMP %s\n", begin.c_str());
            // fprintf(assembly,"%s:\n",root->childArr[2]->getFalseLabel().c_str());
        }

        else if (root->exprGetter() == "statement : PRINTLN LPAREN ID RPAREN SEMICOLON")
        {
            // fprintf(assembly,"%s",getLabel().c_str());
            // writeICG(root->childArr[0]);
            string str = getAddress(root->childArr[2]);
            fprintf(assembly, "\t\tMOV AX, %s\n\t\tCALL print_output\n\t\tCALL new_line\n", str.c_str());
            if (isMain)
                fprintf(text, "\t\tMOV AX, %s\n\t\tCALL print_output\n\t\tCALL new_line\n", str.c_str());
            // fprintf(assembly,"%s:\n",root->getNextLabel().c_str());
        }

        else if (root->exprGetter() == "statement : RETURN expression SEMICOLON")
        {
            // fprintf(assembly,"%s",getLabel().c_str());
            writeICG(root->childArr[1]);
            fprintf(assembly, "\t\tMOV BX,AX\n");
            if (isMain)
                fprintf(text, "\t\tMOV BX,AX\n");
            // fprintf(assembly,"%s:\n",root->getNextLabel().c_str());
        }

        else if (root->exprGetter() == "expression_statement : expression SEMICOLON")
        {

            writeICG(root->childArr[0]);
        }
        else if (root->exprGetter() == "expression_statement : SEMICOLON")
        {

            // writeICG(root->childArr[0]);
        }

        else if (root->exprGetter() == "variable : ID LSQUARE expression RSQUARE")
        {
            writeICG(root->childArr[2]);
            tempSym = root->childArr[0];
            // tempSym = table->LookUp(tempSym->nameGetter());
            root->setScope(tempSym->getScope());
            root->offsetSetter(tempSym->offsetGetter());
            root->checkArraySetter(tempSym->checkArrayGetter());
            fprintf(assembly, "\t\tPUSH CX\n");
            fprintf(assembly, "\t\tMOV CX, AX\n");
            if (isMain)
            {
                fprintf(text, "\t\tPUSH CX\n");
                fprintf(text, "\t\tMOV CX, AX\n");
            }
            if (root->childArr[0]->offsetGetter() == -1)
            {
                fprintf(assembly, "\t\tLEA SI, %s\n\t\tSHL CX, 1\n\t\tADD SI, CX\n\t\tMOV AX, [SI]\n", root->childArr[0]->nameGetter().c_str());
                if (isMain)
                    fprintf(text, "\t\tLEA SI, %s\n\t\tSHL CX, 1\n\t\tADD SI, CX\n\t\tMOV AX, [SI]\n", root->childArr[0]->nameGetter().c_str());
            }
            else
            {
                fprintf(assembly, "\t\tMOV SI, BP\n\t\tSHL CX, 1\n\t\tADD CX, %d\n\t\tSUB SI, CX\n\t\tMOV AX, [SI]\n", root->childArr[0]->offsetGetter());
                if (isMain)
                    fprintf(text, "\t\tMOV SI, BP\n\t\tSHL CX, 1\n\t\tADD CX, %d\n\t\tSUB SI, CX\n\t\tMOV AX, [SI]\n", root->childArr[0]->offsetGetter());
            }
            fprintf(assembly, "\t\tPOP CX\n");
            if (isMain)
                fprintf(text, "\t\tPOP CX\n");

            // cout<<"A"<<root->checkArrayGetter();
            // fprintf(assembly,"\t\tMOV CX, AX\n");
        }

        else if (root->exprGetter() == "expression : logic_expression")
        {
            writeICG(root->childArr[0]);
        }

        else if (root->exprGetter() == "logic_expression : rel_expression")
        {

            writeICG(root->childArr[0]);
        }

        else if (root->exprGetter() == "logic_expression : rel_expression LOGICOP rel_expression")
        {
            writeICG(root->childArr[0]);
            fprintf(assembly, "\t\tPUSH DX\n\t\tMOV DX, AX\n");
            if (isMain)
                fprintf(text, "\t\tPUSH DX\n\t\tMOV DX, AX\n");
            writeICG(root->childArr[2]);
            logicop(root);
        }

        else if (root->exprGetter() == "rel_expression	: simple_expression")
        {

            writeICG(root->childArr[0]);
        }

        else if (root->exprGetter() == "rel_expression	: simple_expression RELOP simple_expression")
        {
            writeICG(root->childArr[0]);
            fprintf(assembly, "\t\tPUSH DX\n\t\tMOV DX, AX\n");
            if (isMain)
                fprintf(text, "\t\tPUSH DX\n\t\tMOV DX, AX\n");
            writeICG(root->childArr[2]);
            relop(root);
        }

        // "logic_expression : rel_expression LOGICOP rel_expression"

        else if (root->exprGetter() == "simple_expression : term")
        {
            writeICG(root->childArr[0]);
        }
        else if (root->exprGetter() == "simple_expression : simple_expression ADDOP term")
        {
            writeICG(root->childArr[0]);
            fprintf(assembly, "\t\tPUSH DX\n\t\tMOV DX, AX\n");
            if (isMain)
                fprintf(text, "\t\tPUSH DX\n\t\tMOV DX, AX\n");
            writeICG(root->childArr[2]);
            addTerm(root);
        }
        else if (root->exprGetter() == "term :	unary_expression")
        {
            writeICG(root->childArr[0]);
        }

        else if (root->exprGetter() == "unary_expression : NOT unary_expression")
        {
            writeICG(root->childArr[1]);
            notOperation();
        }

        else if (root->exprGetter() == "unary_expression : factor")
        {
            writeICG(root->childArr[0]);
        }

        else if (root->exprGetter() == "factor : ID LPAREN argument_list RPAREN")
        {
            isArgument = true;
            writeICG(root->childArr[2]);
            fprintf(assembly, "\t\tCALL %s\n", root->childArr[0]->nameGetter().c_str());
            if (root->childArr[0]->retTypeGetter() != "VOID")
            {
                fprintf(assembly, "\t\tMOV AX, BX\n");
                if (isMain)
                    fprintf(text, "\t\tMOV AX, BX\n");
            }
            isArgument = false;
        }
        else if (root->exprGetter() == "factor	: variable")
        {
            writeICG(root->childArr[0]);
            // string str = getAddress(root->childArr[0]);
            // fprintf(assembly, "\t\tMOV AX,%s\n", str.c_str());
        }

        else if (root->exprGetter() == "factor : LPAREN expression RPAREN")
        {
            writeICG(root->childArr[1]);
        }

        else if (root->exprGetter() == "factor : variable DECOP")
        {
            writeICG(root->childArr[0]);
            decOp(root);
        }
        else if (root->exprGetter() == "argument_list : arguments")
        {
            writeICG(root->childArr[0]);
        }
        else if (root->exprGetter() == "arguments : arguments COMMA logic_expression")
        {
            writeICG(root->childArr[0]);
            writeICG(root->childArr[2]);
        }

        else if (root->exprGetter() == "arguments : logic_expression")
        {
            writeICG(root->childArr[0]);
        }

        else if (root->exprGetter() == "var_declaration : type_specifier declaration_list SEMICOLON")
        {
            // printf("%s\n", root->exprGetter().c_str());
            varDeclaration(root);
        }
        else if (root->exprGetter() == "func_definition : type_specifier ID LPAREN RPAREN compound_statement")
        {
            totalOffset = 0;
            funcInit(root);
            writeICG(root->childArr[4]);
            funcEnd(root);
            totalOffset = 0;
        }
        else if (root->exprGetter() == "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement")
        {
            // cout<<root->childArr[1]->listOfParameter.size();
            // cout << root->childArr[1]->nameGetter() << endl;
            // cout<<root->childArr[1]->argNumberGetter();
            totalOffset = 0;
            funcInit(root);
            setParameter(root);
            writeICG(root->childArr[5]);
            funcEnd(root);
            totalOffset = 0;
        }
        else if (root->exprGetter() == "factor : CONST_INT")
        {
            if (isMain)
                fprintf(text, "\t\tMOV AX, %s\n", root->childArr[0]->nameGetter().c_str());
            fprintf(assembly, "\t\tMOV AX, %s\n", root->childArr[0]->nameGetter().c_str());
            if (isArgument)
            {
                fprintf(assembly, "\t\tPUSH AX\n");
                if (isMain)
                    fprintf(text, "\t\tPUSH AX\n");
            }
        }
        else if (root->exprGetter() == "expression : variable ASSIGNOP logic_expression")
        {
            writeICG(root->childArr[2]);
            // cout<<root->childArr[0]->nameGetter()<<endl;
            if (!root->childArr[0]->childArr[0]->checkArrayGetter())
            {
                // writeICG(root->childArr[0]);
                assignOP(root);
            }
            else
            {
                fprintf(assembly, "\t\tPUSH AX\n");
                if (isMain)
                    fprintf(text, "\t\tPUSH AX\n");
                writeICG(root->childArr[0]->childArr[2]);

                assignOP(root);
                // writeICG(root->childArr[2]);
                fprintf(assembly, "\t\tPOP AX\n\t\tMOV [SI], AX\n");
                if (isMain)
                    fprintf(text, "\t\tPOP AX\n\t\tMOV [SI], AX\n");
            }
        }
        else if (root->exprGetter() == "term : term MULOP unary_expression")
        {
            writeICG(root->childArr[0]);
            fprintf(assembly, "\t\tPUSH CX\n\t\tMOV CX, AX\n");
            if (isMain)
                fprintf(text, "\t\tPUSH CX\n\t\tMOV CX, AX\n");
            writeICG(root->childArr[2]);
            mulOP(root);
        }
        else if (root->exprGetter() == "unary_expression : ADDOP unary_expression")
        {
            writeICG(root->childArr[1]);
            addOPUnary(root);
        }
        // else if(root->exprGetter()=="simple_expression : simple_expression ADDOP term")
        // {
        //    addTerm(root);
        // }
        else if (root->exprGetter() == "variable : ID")
        {
            tempSym = root->childArr[0];
            // tempSym = table->LookUp(tempSym->nameGetter());
            root->setScope(tempSym->getScope());
            root->offsetSetter(tempSym->offsetGetter());
            root->checkArraySetter(tempSym->checkArrayGetter());
            // cout<<tempSym->checkArrayGetter();
            string str = getAddress(tempSym);
            fprintf(assembly, "\t\tMOV AX, %s\n", str.c_str());
            if (isMain)
                fprintf(text, "\t\tMOV AX, %s\n", str.c_str());
            if (isArgument)
            {
                fprintf(assembly, "\t\tPUSH AX\n");
                if (isMain)
                {
                    fprintf(text, "\t\tPUSH AX\n");
                }
            }
        }
        else if (root->exprGetter() == "factor : variable INCOP")
        {
            writeICG(root->childArr[0]);
            incOp(root);
        }
        // for (SymbolInfo *child : root->childArr)
        // {
        //     // printf("%s\n", child->exprGetter().c_str());
        //     writeICG(child);
        // }
    }
};
