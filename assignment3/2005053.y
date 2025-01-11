%{
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include "2005053-SymbolTable.cpp"
#include "2005053-ParseTree.cpp"


using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;
extern int line_count;
FILE *logout;
FILE *errorout;
FILE *parseout;
SymbolTable symtable(11);
SymbolInfo *temp;
ParseTree obj;
vector<SymbolInfo*>parameterList;
vector<SymbolInfo*>varDeclarationList;
string varType;
int errors=0;
int store=0;

bool errorflag=false;
string retType;

void yyerror(char *s)
{   
	
	//write your code
}


%}

%union
{
    SymbolInfo *symbol;
}

%token <symbol> RELOP IF ELSE RETURN LTHIRD RTHIRD INCOP DECOP LPAREN RPAREN ASSIGNOP NOT SEMICOLON LCURL RCURL COMMA 
%token <symbol> ADDOP MULOP CONST_INT CONST_FLOAT LOGICOP ID FOR WHILE INT FLOAT VOID PRINTLN CHAR CONST_CHAR DO BITOP 


%type <symbol> start program unit compound_statement type_specifier declaration_list parameter_list var_declaration variable func_declaration statement statements 
%type <symbol> expression factor arguments argument_list expression_statement simple_expression unary_expression rel_expression term logic_expression func_definition 

%nonassoc LOW_PREC
%nonassoc ELSE


%%

start : program
	{
		fprintf(logout,"start : program\n");
		fprintf(logout,"Total Lines: %d\n",line_count);
		fprintf(logout,"Total Errors: %d\n",errors);
		$$=new SymbolInfo();
		obj.currSymbolSetter($$);
		$$->exprSetter("start : program");
		$$->addChild({$1});
		$$->startlineSetter($1->startlineGetter());
		$$->endlineSetter($1->endlineGetter());
		//cout<<"hello"<<endl;
		//cout<<$$->childArr.size()<<endl;
		obj.printParse(parseout,$$);
		//delete $$;
	}
	;

program : program unit 
    {
        fprintf(logout,"program : program unit \n");
        //$1->nameSetter();
        //$$=$1;
		$$=new SymbolInfo();
		obj.currSymbolSetter($$);
		$$->exprSetter("program : program unit");
		$$->addChild({$1,$2});
		$$->startlineSetter($1->startlineGetter());
		$$->endlineSetter($2->endlineGetter());
    }
	| unit
    {
        fprintf(logout,"program : unit\n");
        $$=new SymbolInfo();
		obj.currSymbolSetter($$);
		$$->exprSetter("program : unit");
		$$->addChild({$1});
		$$->startlineSetter($1->startlineGetter());
		$$->endlineSetter($1->endlineGetter());
    }
	;
	
unit : var_declaration
     {
         fprintf(logout,"unit : var_declaration\n");
         $$=new SymbolInfo();
		 obj.currSymbolSetter($$);
		 $$->exprSetter("unit : var_declaration");
		 $$->addChild({$1});
		 $$->startlineSetter($1->startlineGetter());
		$$->endlineSetter($1->endlineGetter());
     }
     | func_declaration
     {
         fprintf(logout,"unit : func_declaration\n");
         $$=new SymbolInfo();
		 obj.currSymbolSetter($$);
		 $$->exprSetter("unit : func_declaration");
		 $$->addChild({$1});
		 $$->startlineSetter($1->startlineGetter());
		$$->endlineSetter($1->endlineGetter());
     }
     | func_definition
     {
         fprintf(logout,"unit : func_definition\n");
         $$=new SymbolInfo();
		 obj.currSymbolSetter($$);
		 $$->exprSetter("unit : func_definition");
		 $$->addChild({$1});
		 $$->startlineSetter($1->startlineGetter());
		 $$->endlineSetter($1->endlineGetter());
     }
     ;
     
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
        {
          fprintf(logout,"func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n");
          $$=new SymbolInfo(); 
		  obj.currSymbolSetter($$);
		  $$->exprSetter("func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
		  $$->addChild({$1,$2,$3,$4,$5,$6});
		  $$->startlineSetter($1->startlineGetter());
		  $$->endlineSetter($6->endlineGetter());
		  errorflag=symtable.Insert($2->nameGetter(),"ID");
		  temp=symtable.LookUp($2->nameGetter());
		//   if(errorflag==false)
		//   {
		// 	//printf("Hello");
		// 	if(temp->checkFunctionGetter())
		// 	{
		// 		fprintf(errorout,"Line# %d: Conflicting types for '%s'\n",line_count,$2->nameGetter().c_str());
		// 	}
		// 	else{
		// 		fprintf(errorout,"Line# %d: Conflicting types for '%s'\n",line_count,$2->nameGetter().c_str());
		// 	}
		// 	errors++;
		//   } 
		  //else{
          temp->checkFunctionSetter(true);
          temp->listOfParameter=parameterList;
          temp->retTypeSetter($1->varTypeGetter());
          parameterList.clear();
		 // }
        }
		| type_specifier ID LPAREN RPAREN SEMICOLON
		{
			$$=new SymbolInfo();
			obj.currSymbolSetter($$);
		    $$->exprSetter("func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
		    $$->addChild({$1,$2,$3,$4,$5});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($5->endlineGetter());
			errorflag=symtable.Insert($2->nameGetter(),"ID");
			// if(errorflag==false)
		    // {
			// //printf("Hello");
			//   errors++;
	        //   fprintf(errorout,"Line# %d: Conflicting types for '%s'\n",line_count,$2->nameGetter().c_str());
		    // } 
			temp=symtable.LookUp($2->nameGetter());
			temp->checkFunctionSetter(true);
            temp->retTypeSetter($1->varTypeGetter());
            fprintf(logout,"func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n");			

		}
		;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN {
        symtable.EnterScope();
		for(int i=0;i<parameterList.size();i++)
		{   
			string name=parameterList[i]->nameGetter();
			string s=parameterList[i]->varTypeGetter();
			errorflag=symtable.Insert(name,"ID");
			if(errorflag)
			{
				temp=symtable.LookUp(name);
				temp->varTypeSetter(s);
			}
			else{
				 errors++;
	             fprintf(errorout,"Line# %d: Redefinition of parameter '%s'\n",line_count,name.c_str());
			}
		}	
		}
		compound_statement
		{
			$$=new SymbolInfo();
			$2->retTypeSetter($1->varTypeGetter());
			symtable.ExitScope();
			obj.currSymbolSetter($$);
		    $$->exprSetter("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");
		    $$->addChild({$1,$2,$3,$4,$5,$7});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($7->endlineGetter());
			fprintf(logout,"func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n");			
			errorflag=symtable.Insert($2->nameGetter(),"ID");
			temp=symtable.LookUp($2->nameGetter());
			if(errorflag==false)
			{   
				if(temp->checkFunctionGetter()==false)
				{
					fprintf(errorout,"Line# %d: '%s'redeclared as different kind of symbol\n",store,$2->nameGetter().c_str());
					errors++;
				}
				else if(temp->retTypeGetter()!=$1->varTypeGetter())
				{
					fprintf(errorout,"Line# %d: Conflicting types for '%s'\n",store,$2->nameGetter().c_str());
					errors++;
				}
				
			}	
			if(errorflag)
			{
				temp->retTypeSetter($1->varTypeGetter());
				temp->checkFunctionSetter(true);
			}						
			for(int i=0;i<parameterList.size();i++)
		    {   
				temp->listOfParameter.push_back(parameterList[i]);
		    }	
			parameterList.clear();
			
			//symtable.PrintAllScope(logout);
		}
		| type_specifier ID LPAREN RPAREN {
			symtable.EnterScope();
		}
		compound_statement
		{
			$$=new SymbolInfo();
			$2->retTypeSetter($1->varTypeGetter());
			obj.currSymbolSetter($$);
			symtable.ExitScope();
		    $$->exprSetter("func_definition : type_specifier ID LPAREN RPAREN compound_statement");
		    $$->addChild({$1,$2,$3,$4,$6});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($6->endlineGetter());
			fprintf(logout,"func_definition : type_specifier ID LPAREN RPAREN compound_statement\n");			
			symtable.Insert($2->nameGetter(),"ID");
			temp=symtable.LookUp($2->nameGetter());
			temp->retTypeSetter($1->varTypeGetter());
			temp->checkFunctionSetter(true);
			//symtable.PrintAllScope(logout);
		}
 		;				


parameter_list  : parameter_list COMMA type_specifier ID
		{   
			$$ = new SymbolInfo();
			fprintf(logout,"parameter_list  : parameter_list COMMA type_specifier ID\n");
			$4->varTypeSetter(varType);
			$4->retTypeSetter($3->retTypeGetter());
			parameterList.push_back($4);
			obj.currSymbolSetter($$);
		    $$->exprSetter("parameter_list  : parameter_list COMMA type_specifier ID");
		    $$->addChild({$1,$2,$3,$4});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($4->endlineGetter());
		}
		| parameter_list COMMA type_specifier
		{
			$$ = new SymbolInfo();
			obj.currSymbolSetter($$);
		    $$->exprSetter("parameter_list  : parameter_list COMMA type_specifier");
		    $$->addChild({$1,$2,$3});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($3->endlineGetter());
			fprintf(logout,"parameter_list  : parameter_list COMMA type_specifier\n");
		}
 		| type_specifier ID
		{   
			$$=new SymbolInfo();
			parameterList.clear();
			parameterList.push_back($2);
			$2->varTypeSetter(varType);
			obj.currSymbolSetter($$);
		    $$->exprSetter("parameter_list  : type_specifier ID");
		    $$->addChild({$1,$2});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($2->endlineGetter());
			fprintf(logout,"parameter_list  : type_specifier ID\n");

		}
		| type_specifier
		{   
			$$=new SymbolInfo();
			$$->varTypeSetter(varType);
			obj.currSymbolSetter($$);
		    $$->exprSetter("parameter_list  : type_specifier");
		    $$->addChild({$1});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($1->endlineGetter());
			fprintf(logout,"parameter_list  : type_specifier\n");
			
		}
 		;

 		
compound_statement : LCURL statements RCURL
			{   
				$$= new SymbolInfo();
				obj.currSymbolSetter($$);
		        $$->exprSetter("compound_statement : LCURL statements RCURL");
		        $$->addChild({$1,$2,$3});
				$$->startlineSetter($1->startlineGetter());
		        $$->endlineSetter($3->endlineGetter());
				fprintf(logout,"compound_statement : LCURL statements RCURL\n");
				symtable.PrintAllScope(logout);
			}
 		    | LCURL RCURL
			{
				 $$=new SymbolInfo();
				 obj.currSymbolSetter($$);
		         $$->exprSetter("compound_statement : LCURL RCURL");
		         $$->addChild({$1,$2});
				 $$->startlineSetter($1->startlineGetter());
		    	 $$->endlineSetter($2->endlineGetter());
				 fprintf(logout,"compound_statement : LCURL RCURL\n");
				 symtable.PrintAllScope(logout);
			}
 		    ;
 		    
var_declaration : type_specifier declaration_list SEMICOLON
			{   
				fprintf(logout,"var_declaration : type_specifier declaration_list SEMICOLON\n");
				$$= new SymbolInfo();
				$$->varTypeSetter($1->nameGetter());
				obj.currSymbolSetter($$);
		        $$->exprSetter("var_declaration : type_specifier declaration_list SEMICOLON");
		        $$->addChild({$1,$2,$3});
				$$->startlineSetter($1->startlineGetter());
		        $$->endlineSetter($3->endlineGetter());
				if($1->varTypeGetter()=="VOID")
				{
					for(SymbolInfo *sym:varDeclarationList)
					{
						fprintf(errorout,"Line# %d: Variable or field '%s' declared void\n",line_count,sym->nameGetter().c_str());
						symtable.Remove(sym->nameGetter());
						errors++;					
					}
				}
				varDeclarationList.clear();			
			}
 		 ;
 		 
type_specifier	: INT
		{	
			fprintf(logout,"type_specifier	: INT\n");
			$$=new SymbolInfo();
			varType="INT";
			$$->varTypeSetter("INT");
			obj.currSymbolSetter($$);
		    $$->exprSetter("type_specifier	: INT");
		    $$->addChild({$1});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($1->endlineGetter());
			store=line_count;
		}
 		| FLOAT
		{
			fprintf(logout,"type_specifier	: FLOAT\n");
			$$=new SymbolInfo();
			varType="FLOAT";
			$$->varTypeSetter("FLOAT");
			obj.currSymbolSetter($$);
		    $$->exprSetter("type_specifier	: FLOAT");
		    $$->addChild({$1});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($1->endlineGetter());
			store=line_count;
		}
 		| VOID
		{
			fprintf(logout,"type_specifier	: VOID\n");
			$$=new SymbolInfo();
			varType="VOID";
			$$->varTypeSetter("VOID");
			obj.currSymbolSetter($$);
		    $$->exprSetter("type_specifier	: VOID");
		    $$->addChild({$1});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($1->endlineGetter());
			store=line_count;
		}
 		;
 		
declaration_list : declaration_list COMMA ID
		  { 
			$$=new SymbolInfo();
			errorflag=symtable.Insert($3->nameGetter(),"ID");
			temp=symtable.LookUp($3->nameGetter());
			if(errorflag)
			{
				temp->varTypeSetter(varType);
			}	
			else{
				if(temp->varTypeGetter()!=varType)
				{
					fprintf(errorout,"Line# %d: Conflicting types for '%s'\n",store,temp->nameGetter().c_str());
					errors++;
				}
			}	
			fprintf(logout,"declaration_list : declaration_list COMMA ID\n");
			obj.currSymbolSetter($$);
		    $$->exprSetter("declaration_list : declaration_list COMMA ID");
		    $$->addChild({$1,$2,$3});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($3->endlineGetter());
			//symtable.PrintAllScope(logout);
        
		  }
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
		  {
			$$=new SymbolInfo();
			errorflag=symtable.Insert($3->nameGetter(),"ID");
			temp=symtable.LookUp($3->nameGetter());
			if(errorflag)
			{
				temp->checkArraySetter(true);
			    temp->varTypeSetter(varType);
			}	
			else{
				if(temp->varTypeGetter()!=varType)
				{
					fprintf(errorout,"Line# %d: Conflicting types for '%s'\n",store,temp->nameGetter().c_str());
					errors++;
				}
			}
			fprintf(logout,"declaration_list : declaration_list COMMA ID LSQUARE CONST_INT RSQUARE\n");	
			obj.currSymbolSetter($$);
		    $$->exprSetter("declaration_list : declaration_list COMMA ID LSQUARE CONST_INT RSQUARE");
		    $$->addChild({$1,$2,$3,$4,$5,$6});	
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($6->endlineGetter());	
				
		  }
 		  | ID
		  {
			$$=new SymbolInfo();
			errorflag=symtable.Insert($1->nameGetter(),"ID");
			temp=symtable.LookUp($1->nameGetter());
			if(errorflag)
			{
				temp->varTypeSetter(varType);
			}
			else{
				if(temp->varTypeGetter()!=varType)
				{
					fprintf(errorout,"Line# %d: Conflicting types for '%s'\n",store,temp->nameGetter().c_str());
					errors++;
				}
			}
			varDeclarationList.push_back(temp);
			fprintf(logout,"declaration_list : ID\n");
			obj.currSymbolSetter($$);
		    $$->exprSetter("declaration_list : ID");
		    $$->addChild({$1});		
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($1->endlineGetter());
			
			//symtable.PrintAllScope(logout);
		  }
 		  | ID LTHIRD CONST_INT RTHIRD
		  {
			$$=new SymbolInfo();
			symtable.Insert($1->nameGetter(),"ID");
			temp=symtable.LookUp($1->nameGetter());
			if(errorflag)
			{
				temp->checkArraySetter(true);
			    temp->varTypeSetter(varType);
			}
			fprintf(logout,"declaration_list : ID LSQUARE CONST_INT RSQUARE\n");
			obj.currSymbolSetter($$);
		    $$->exprSetter("declaration_list : ID LSQUARE CONST_INT RSQUARE");
		    $$->addChild({$1,$2,$3,$4});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($4->endlineGetter());		
		  }
 		  ;
 		  
statements : statement
		{
			$$=new SymbolInfo();
			fprintf(logout,"statements : statement\n");
			obj.currSymbolSetter($$);
		    $$->exprSetter("statements : statement");
		    $$->addChild({$1});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($1->endlineGetter());
		}
	   | statements statement
	   {
		    $$=new SymbolInfo();
			fprintf(logout,"statements : statements statement\n");
			obj.currSymbolSetter($$);
		    $$->exprSetter("statements : statements statement");
		    $$->addChild({$1,$2});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($2->endlineGetter());		
	   }
	   ;
	   
statement : var_declaration
	  {
		 $$=new SymbolInfo();
		 obj.currSymbolSetter($$);
		 $$->exprSetter("statement : var_declaration");
		 $$->addChild({$1});	
		 $$->startlineSetter($1->startlineGetter());
		 $$->endlineSetter($1->endlineGetter());
		 fprintf(logout,"statement : var_declaration\n");
	  }
	  | expression_statement
	  {
		 $$=new SymbolInfo();
		 obj.currSymbolSetter($$);
		 $$->exprSetter("statement : expression_statement");
		 $$->addChild({$1});	
		 $$->startlineSetter($1->startlineGetter());
		 $$->endlineSetter($1->endlineGetter());
		 fprintf(logout,"statement : expression_statement\n");
	  }
	  | compound_statement
	  {
		 $$=new SymbolInfo();
		 obj.currSymbolSetter($$);
		 $$->exprSetter("statement : compound_statement");
		 $$->addChild({$1});
		 $$->startlineSetter($1->startlineGetter());
		 $$->endlineSetter($1->endlineGetter());
		 fprintf(logout,"statement : compound_statement\n");
	  }
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement
	  {
		 $$=new SymbolInfo();
		 obj.currSymbolSetter($$);
		 $$->exprSetter("statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement");
		 $$->addChild({$1,$2,$3,$4,$5,$6,$7});
		 $$->startlineSetter($1->startlineGetter());
		 $$->endlineSetter($7->endlineGetter());
		 fprintf(logout,"statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n");
	  }
	  | IF LPAREN expression RPAREN statement %prec LOW_PREC
	  {
		 $$=new SymbolInfo();
		 obj.currSymbolSetter($$);
		 $$->exprSetter("statement : IF LPAREN expression RPAREN statement");
		 $$->addChild({$1,$2,$3,$4,$5});
		 $$->startlineSetter($1->startlineGetter());
		 $$->endlineSetter($5->endlineGetter());
		 fprintf(logout,"statement : IF LPAREN expression RPAREN statement\n");
	  }
	  | IF LPAREN expression RPAREN statement ELSE statement
	  {
		 $$=new SymbolInfo();
		 obj.currSymbolSetter($$);
		 $$->exprSetter("statement : IF LPAREN expression RPAREN statement ELSE statement");
		 $$->addChild({$1,$2,$3,$4,$5,$6,$7});
		 $$->startlineSetter($1->startlineGetter());
		 $$->endlineSetter($7->endlineGetter());
		 fprintf(logout,"statement : IF LPAREN expression RPAREN statement ELSE statement\n");
	  }
	  | WHILE LPAREN expression RPAREN statement
	  {
		 $$=new SymbolInfo();
		 obj.currSymbolSetter($$);
		 $$->exprSetter("statement : WHILE LPAREN expression RPAREN statement");
		 $$->addChild({$1,$2,$3,$4,$5});
		 $$->startlineSetter($1->startlineGetter());
		$$->endlineSetter($5->endlineGetter());
		 fprintf(logout,"statement : WHILE LPAREN expression RPAREN statement\n");
	  }
	  | PRINTLN LPAREN ID RPAREN SEMICOLON
	  {  
		 $$=new SymbolInfo();
		 obj.currSymbolSetter($$);
		 $$->exprSetter("statement : PRINTLN LPAREN ID RPAREN SEMICOLON");
		 $$->addChild({$1,$2,$3,$4,$5});
		 $$->startlineSetter($1->startlineGetter());
		 $$->endlineSetter($5->endlineGetter());
		 fprintf(logout,"statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n");
	  }
	  | RETURN expression SEMICOLON
	  {
		 $$=new SymbolInfo();
		 retType=$2->varTypeGetter();
		 obj.currSymbolSetter($$);
		 $$->exprSetter("statement : RETURN expression SEMICOLON");
		 $$->addChild({$1,$2,$3});
		 $$->startlineSetter($1->startlineGetter());
		 $$->endlineSetter($3->endlineGetter());
		 fprintf(logout,"statement : RETURN expression SEMICOLON\n");
	  }
	  ;
	  
expression_statement : SEMICOLON	
	  		 {
				$$=new SymbolInfo();
				obj.currSymbolSetter($$);
		 		$$->exprSetter("expression_statement : SEMICOLON");
		 		$$->addChild({$1});
				$$->startlineSetter($1->startlineGetter());
		   		 $$->endlineSetter($1->endlineGetter());
		        fprintf(logout,"expression_statement : SEMICOLON\n");
			 }	
			| expression SEMICOLON 
			{
				$$=new SymbolInfo("","expression_statement");
				obj.currSymbolSetter($$);
		 		$$->exprSetter("expression_statement : expression SEMICOLON");
		 		$$->addChild({$1,$2});
				$$->startlineSetter($1->startlineGetter());
		    	$$->endlineSetter($2->endlineGetter());
		        fprintf(logout,"expression_statement : expression SEMICOLON \n");
			}
			;
	  
variable : ID
	 {  
		$$=new SymbolInfo();
		temp=symtable.LookUp($1->nameGetter());
		if(temp!=NULL)
		{
			$$->varTypeSetter(temp->varTypeGetter());
		}
		else{
			fprintf(errorout,"Line# %d: Undeclared variable '%s'\n",line_count,$1->nameGetter().c_str());
			errors++;
		}
		fprintf(logout,"variable : ID\n");
		obj.currSymbolSetter($$);
		$$->exprSetter("variable : ID");
		$$->addChild({$1});
		$$->startlineSetter($1->startlineGetter());
		$$->endlineSetter($1->endlineGetter());

	 }
	 | ID LTHIRD expression RTHIRD 
	 {  
		$$=new SymbolInfo();
		temp=symtable.LookUp($1->nameGetter());
		if(temp!=NULL)
		{
			$$->varTypeSetter(temp->varTypeGetter());
		}
		else{
			fprintf(errorout,"Line# %d: Undeclared variable '%s'\n",line_count,$1->nameGetter().c_str());
			errors++;
		}
		obj.currSymbolSetter($$);
		$$->exprSetter("variable : ID LSQUARE expression RSQUARE");
		$$->addChild({$1,$2,$3,$4});
		$$->startlineSetter($1->startlineGetter());
		$$->endlineSetter($4->endlineGetter());
		fprintf(logout,"variable : ID LSQUARE expression RSQUARE\n");
	 }
	 ;
	 
expression : logic_expression	
	   {
		$$=new SymbolInfo();
		$$->varTypeSetter($1->varTypeGetter());
		fprintf(logout,"expression : logic_expression\n");
		obj.currSymbolSetter($$);
		$$->exprSetter("expression : logic_expression	");
		$$->addChild({$1});
		$$->startlineSetter($1->startlineGetter());
		$$->endlineSetter($1->endlineGetter());
	   }
	   | variable ASSIGNOP logic_expression 
	   { 
		 $$=new SymbolInfo();
		 $$->varTypeSetter($1->varTypeGetter());
		 fprintf(logout,"expression : variable ASSIGNOP logic_expression\n");
		 obj.currSymbolSetter($$);
		 $$->exprSetter("expression : variable ASSIGNOP logic_expression");
		 $$->addChild({$1,$2,$3});
		 $$->startlineSetter($1->startlineGetter());
		 $$->endlineSetter($3->endlineGetter());
	   }	
	   ;
			
logic_expression : rel_expression 	
		 {
			$$=new SymbolInfo();
			$$->varTypeSetter($1->varTypeGetter());
			obj.currSymbolSetter($$);
		    $$->exprSetter("logic_expression : rel_expression");
		    $$->addChild({$1});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($1->endlineGetter());
			fprintf(logout,"logic_expression : rel_expression\n");

		 }
		 | rel_expression LOGICOP rel_expression
		 {
			$$=new SymbolInfo();
			$$->varTypeSetter($1->varTypeGetter());
			obj.currSymbolSetter($$);
		    $$->exprSetter("logic_expression : rel_expression LOGICOP rel_expression");
		    $$->addChild({$1,$2,$3});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($3->endlineGetter());
			fprintf(logout,"logic_expression : rel_expression LOGICOP rel_expression\n");
		 } 	
		 ;
			
rel_expression	: simple_expression 
		{
			$$=new SymbolInfo();
			$$->varTypeSetter($1->varTypeGetter());
			obj.currSymbolSetter($$);
		    $$->exprSetter("rel_expression	: simple_expression");
		    $$->addChild({$1});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($1->endlineGetter());
			fprintf(logout,"rel_expression	: simple_expression\n");
		}
		| simple_expression RELOP simple_expression	
		{
			$$=new SymbolInfo();
			$$->varTypeSetter($1->varTypeGetter());
			obj.currSymbolSetter($$);
		    $$->exprSetter("rel_expression	: simple_expression RELOP simple_expression");
		    $$->addChild({$1,$2,$3});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($3->endlineGetter());
			fprintf(logout,"rel_expression	: simple_expression RELOP simple_expression\n");
		}
		;
				
simple_expression : term 
		  { 
			$$=new SymbolInfo();
			$$->varTypeSetter($1->varTypeGetter());
			obj.currSymbolSetter($$);
		    $$->exprSetter("simple_expression : term");
		    $$->addChild({$1});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($1->endlineGetter());
			fprintf(logout,"simple_expression : term\n");
		  }
		  | simple_expression ADDOP term 
		  {
			$$=new SymbolInfo();
			fprintf(logout,"simple_expression : simple_expression ADDOP term\n");
			if($1->varTypeGetter()=="INT" && $3->varTypeGetter()=="INT")
			{
				$$->varTypeSetter("INT");
			}
			else if($1->varTypeGetter()=="FLOAT" && $3->varTypeGetter()=="FLOAT")
			{
				$$->varTypeSetter("FLOAT");
			}
			else if($1->varTypeGetter()=="VOID" ||$3->varTypeGetter()=="VOID")
		    {
				fprintf(errorout,"Line# %d: Void cannot be used in expression \n",line_count);
			    errors++;
		    }
			obj.currSymbolSetter($$);
		    $$->exprSetter("simple_expression : simple_expression ADDOP term");
		    $$->addChild({$1,$2,$3});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($3->endlineGetter());
		  }
		  ;
					
term :	unary_expression
	 {  
		$$=new SymbolInfo();
		$$->varTypeSetter($1->varTypeGetter());
		obj.currSymbolSetter($$);
		$$->exprSetter("term :	unary_expression");
		$$->addChild({$1});
		$$->startlineSetter($1->startlineGetter());
		$$->endlineSetter($1->endlineGetter());
		fprintf(logout,"term :	unary_expression\n");
	 }
     |  term MULOP unary_expression
	 {
		$$=new SymbolInfo();
		fprintf(logout,"term : term MULOP unary_expression\n");
		if($1->varTypeGetter()=="INT" && $3->varTypeGetter()=="INT")
		{
			$$->varTypeSetter("INT");
		}
		else if($1->varTypeGetter()=="FLOAT" && $3->varTypeGetter()=="FLOAT")
		{
			$$->varTypeSetter("FLOAT");
		}
        else if($1->varTypeGetter()=="VOID" ||$3->varTypeGetter()=="VOID")
		{
				fprintf(errorout,"Line# %d: Void cannot be used in expression \n",line_count);
			    errors++;
		}
		obj.currSymbolSetter($$);
		$$->exprSetter("term : term MULOP unary_expression");
		$$->addChild({$1,$2,$3});
		$$->startlineSetter($1->startlineGetter());
		$$->endlineSetter($3->endlineGetter());
	 }
     ;

unary_expression : ADDOP unary_expression 
		 {
			$$=new SymbolInfo();
			if($2->varTypeGetter()=="VOID")
			{
				fprintf(errorout,"Line# %d: Void cannot be used in expression \n",line_count);
			    errors++;
			}
			else{
				$$->varTypeSetter($2->varTypeGetter());
			}
		    fprintf(logout,"unary_expression : ADDOP unary_expression\n");
			obj.currSymbolSetter($$);
		    $$->exprSetter("unary_expression : ADDOP unary_expression");
			$$->addChild({$1,$2});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($2->endlineGetter());
		 }
		 | NOT unary_expression 
		 {
			$$=new SymbolInfo();
			$$->varTypeSetter($2->varTypeGetter());
			if($2->varTypeGetter()=="VOID")
			{
				fprintf(errorout,"Line# %d: Void cannot be used in expression \n",line_count);
			    errors++;
			}
			else{
				$$->varTypeSetter($2->varTypeGetter());
			}
		    fprintf(logout,"unary_expression : NOT unary_expression\n");
			obj.currSymbolSetter($$);
		    $$->exprSetter("unary_expression : NOT unary_expression");
			$$->addChild({$1,$2});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($2->endlineGetter());
		 }
		 | factor 
		 {
			$$=new SymbolInfo();
			if($1->varTypeGetter()=="VOID")
			{
				fprintf(errorout,"Line# %d: Void cannot be used in expression \n",line_count);
			    errors++;
			}
			else{
				$$->varTypeSetter($1->varTypeGetter());
			}

		    fprintf(logout,"unary_expression : factor\n");
			obj.currSymbolSetter($$);
		    $$->exprSetter("unary_expression : factor");
			$$->addChild({$1});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($1->endlineGetter());
		 }
		 ;
	
factor	: variable 
	{
		$$=new SymbolInfo();
		$$->varTypeSetter($1->varTypeGetter());
		obj.currSymbolSetter($$);
		$$->exprSetter("factor	: variable");
		$$->addChild({$1});
		$$->startlineSetter($1->startlineGetter());
		$$->endlineSetter($1->endlineGetter());
		fprintf(logout,"factor	: variable\n");
	}
	| ID LPAREN argument_list RPAREN
	{
		$$=new SymbolInfo();
		temp=symtable.LookUp($1->nameGetter());
		if(temp!=NULL)
		{   
			temp->varTypeSetter(temp->retTypeGetter());
			
			if(parameterList.size()>temp->listOfParameter.size())
			{
				fprintf(errorout,"Line# %d: Too many arguments to function '%s'\n",line_count,$1->nameGetter().c_str());
				errors++;
			}
			else if(parameterList.size()<temp->listOfParameter.size())
			{
				fprintf(errorout,"Line# %d: Too few arguments to function '%s'\n",line_count,$1->nameGetter().c_str());
				errors++;
			}
			else {
				for(int i=0;i<parameterList.size();i++)
				{   
                    if(parameterList[i]->checkArrayGetter()!=temp->listOfParameter[i]->checkArrayGetter())
					{
						fprintf(errorout,"Line# %d: Type mismatch for argument %d of '%s'\n",line_count,i+1,$1->nameGetter().c_str());
				        errors++;
					}
					else if(parameterList[i]->varTypeGetter()!=temp->listOfParameter[i]->varTypeGetter())
					{
						fprintf(errorout,"Line# %d: Type mismatch for argument %d of '%s'\n",line_count,i+1,$1->nameGetter().c_str());
				        errors++;
					}
				}
			}

		}
		else{
			fprintf(errorout,"Line# %d: Undeclared function '%s'\n",line_count,$1->nameGetter().c_str());
			errors++;
		}
		parameterList.clear();
		fprintf(logout,"factor : ID LPAREN argument_list RPAREN\n");
		obj.currSymbolSetter($$);
		$$->exprSetter("factor : ID LPAREN argument_list RPAREN");
		$$->addChild({$1,$2,$3,$4});
		$$->varTypeSetter($1->retTypeGetter());
		$$->startlineSetter($1->startlineGetter());
		$$->endlineSetter($4->endlineGetter());
	}
	| LPAREN expression RPAREN
	{
		$$=new SymbolInfo();
		$$->varTypeSetter($2->varTypeGetter());
		obj.currSymbolSetter($$);
		$$->exprSetter("factor : LPAREN expression RPAREN");
		$$->addChild({$1,$2,$3});
		$$->startlineSetter($1->startlineGetter());
		$$->endlineSetter($3->endlineGetter());
		fprintf(logout,"factor : LPAREN expression RPAREN\n");
	}
	| CONST_INT 
	{
		$$=new SymbolInfo();
		$$->varTypeSetter($1->typeGetter());
		obj.currSymbolSetter($$);
		$$->exprSetter("factor : CONST_INT");
		$$->addChild({$1});
		$$->startlineSetter($1->startlineGetter());
		$$->endlineSetter($1->endlineGetter());
		fprintf(logout,"factor : CONST_INT\n");
	}
	| CONST_FLOAT
	{
		$$=new SymbolInfo();
		$$->varTypeSetter($1->typeGetter());
		obj.currSymbolSetter($$);
		$$->exprSetter("factor : CONST_FLOAT");
		$$->addChild({$1});
		$$->startlineSetter($1->startlineGetter());
		$$->endlineSetter($1->endlineGetter());
		fprintf(logout,"factor : CONST_FLOAT\n");
	}
	| variable INCOP 
	{
		$$=new SymbolInfo();
		$$->varTypeSetter($1->varTypeGetter());
		fprintf(logout,"factor : variable INCOP\n");
		obj.currSymbolSetter($$);
		$$->exprSetter("factor : variable INCOP");
		$$->addChild({$1,$2});
		$$->startlineSetter($1->startlineGetter());
		$$->endlineSetter($2->endlineGetter());
	}
	| variable DECOP
	{
		$$=new SymbolInfo();
		$$->varTypeSetter($1->varTypeGetter());
		fprintf(logout,"factor : variable DECOP\n");
		obj.currSymbolSetter($$);
		$$->exprSetter("factor : variable DECOP");
		$$->addChild({$1,$2});
		$$->startlineSetter($1->startlineGetter());
		$$->endlineSetter($2->endlineGetter());
	}
	;
	
argument_list : arguments
			  {
				$$=new SymbolInfo();
		        fprintf(logout,"argument_list : arguments\n");
				obj.currSymbolSetter($$);
				$$->exprSetter("argument_list : arguments");
				$$->addChild({$1});
				$$->startlineSetter($1->startlineGetter());
		        $$->endlineSetter($1->endlineGetter());
			  }
			  | { }
			  ;
	
arguments : arguments COMMA logic_expression
		  {
			$$=new SymbolInfo();
			parameterList.push_back($3);
		    fprintf(logout,"arguments : arguments COMMA logic_expression\n");
			obj.currSymbolSetter($$);
			$$->exprSetter("arguments : arguments COMMA logic_expression");
			$$->addChild({$1,$2,$3});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($3->endlineGetter());
		  }
	      | logic_expression
		  {
			$$=new SymbolInfo();
			parameterList.push_back($1);
		    fprintf(logout,"arguments : logic_expression\n");
			obj.currSymbolSetter($$);
			$$->exprSetter("arguments : logic_expression");
			$$->addChild({$1});
			$$->startlineSetter($1->startlineGetter());
		    $$->endlineSetter($1->endlineGetter());
		  }
	      ;
 

%%

int main(int argc,char *argv[]){
	
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
    logout= fopen("log.txt","w");
	errorout= fopen("error.txt","w");
	parseout= fopen("parsetree.txt","w");
	//tokenout= fopen("token.txt","w");
	yyin= fin;
	yyparse();
	fclose(yyin);
	//fclose(tokenout);
	fclose(logout);
	return 0;
} 

