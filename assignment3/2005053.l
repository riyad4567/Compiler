%option noyywrap  

%x StringState
%x multicomment
%x singlecomment

%{
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<string>
#include "2005053-SymbolTable.cpp"
#include "y.tab.h"

using namespace std;

extern FILE *logout;
//FILE *tokenout;
int line_count=1;
int line_store=0;
bool flag=false;
extern ScopeTable *symtable;
SymbolInfo *ptr;
string str;
string logStr;
string commentStr;
extern YYSTYPE yylval;

//chmod +x command.sh
char *ToUpper(char *text)
{    
    char *arr=new char[strlen(text)+1];
	//strcpy(arr,text);	
	for(int i=0;i<strlen(text);i++)
	{
		arr[i]=toupper(text[i]);
	}
	arr[strlen(text)]='\0';
	return arr;
}
void logPrint(string tokenName,char *lexeme,int lineno)
{
	 fprintf(logout,"Line# %d: Token <%s> Lexeme %s found\n",lineno,tokenName.c_str(),lexeme); 
}

char *charPrint(char *lexeme)
{   
	char *ptr=new char[2];
	switch(lexeme[1])
	{   
		case 't':
		{
		    ptr[0]='\t';
			//return ptr;
			break;
		}
		case 'n':
		{
			ptr[0]='\n';
			break;
		}
		case '0':
	    {
		
		 ptr[0]='\0';
		 //return ptr;
		 break;
	    }
		case 'a':
		{
		
			ptr[0]='\a';
			break;
		
		}
		case 'r':
		{
			ptr[0]='\r';
			break;
		}
		case 'b':
		{
		
			ptr[0]='\b';
			break;
		}
		case 'v':
		{
			 ptr[0]='\v';
			 break;
		}
		case '"':
		{
			ptr[0]='\"';
			break;
		}
		case '\'':
		{
			ptr[0]='\'';
			break;
		}
		case 'f':
		{
			ptr[0]='f';
			break;
		}
		case '\\':
		{
			ptr[0]='\\';
			break;
		}

	}
	return ptr;
}

%}

ID       [a-zA-Z_][A-Za-z0-9_]*
CHARACTER ([^\n\t\r\0\a\f\v\b\'\"\\]|\\[tbrna\'v\"f0\\])
DIGIT [0-9]
DIGITS ({DIGIT}+)
BITOP "&"|"|"|"^"|"<<"|">>"
RELOP ">"|"<"|">="|"<="|"=="|"!="
MULOP "*"|"/"|"%"
NEWLINE \n|\r\n
%%
"if" {
	 fprintf(logout,"Line# %d: Token <%s> Lexeme %s found\n",line_count,ToUpper(yytext),yytext);
	 ptr=new SymbolInfo(yytext,"IF");
	 ptr->startlineSetter(line_count);
	 ptr->endlineSetter(line_count);
	 yylval.symbol=ptr;
	 return IF;
}
"else" {
       fprintf(logout,"Line# %d: Token <%s> Lexeme %s found\n",line_count,ToUpper(yytext),yytext);
	   ptr=new SymbolInfo(yytext,"ELSE");
	    ptr->startlineSetter(line_count);
	    ptr->endlineSetter(line_count);
	   yylval.symbol=ptr;
	   return ELSE;
}
"for" {
       fprintf(logout,"Line# %d: Token <%s> Lexeme %s found\n",line_count,ToUpper(yytext),yytext);
	   ptr=new SymbolInfo(yytext,"FOR");
	   ptr->startlineSetter(line_count);
	   ptr->endlineSetter(line_count);
	   yylval.symbol=ptr;
	   return FOR;	
}
"while" {
       fprintf(logout,"Line# %d: Token <%s> Lexeme %s found\n",line_count,ToUpper(yytext),yytext);
	   ptr=new SymbolInfo(yytext,"WHILE");
	   ptr->startlineSetter(line_count);
	   ptr->endlineSetter(line_count);
	   yylval.symbol=ptr;
	   return WHILE;
}
"do" {
       fprintf(logout,"Line# %d: Token <%s> Lexeme %s found\n",line_count,ToUpper(yytext),yytext);
	   ptr=new SymbolInfo(yytext,"DO");
	   ptr->startlineSetter(line_count);
	   ptr->endlineSetter(line_count);
	   yylval.symbol=ptr;
	   return DO;	
}
"int" {
       fprintf(logout,"Line# %d: Token <%s> Lexeme %s found\n",line_count,ToUpper(yytext),yytext);
	   ptr=new SymbolInfo(yytext,"INT");
	   ptr->startlineSetter(line_count);
	   ptr->endlineSetter(line_count);
	   yylval.symbol=ptr;
	   return INT;
}
"char" {
       fprintf(logout,"Line# %d: Token <%s> Lexeme %s found\n",line_count,ToUpper(yytext),yytext);
	   ptr=new SymbolInfo(yytext,"CHAR");
	    ptr->startlineSetter(line_count);
	    ptr->endlineSetter(line_count);   
	   yylval.symbol=ptr;
	   return CHAR;
}
"println" {
       fprintf(logout,"Line# %d: Token <%s> Lexeme %s found\n",line_count,ToUpper(yytext),yytext);
	   ptr=new SymbolInfo(yytext,"PRINTLN");
	    ptr->startlineSetter(line_count);
	    ptr->endlineSetter(line_count);   
	   yylval.symbol=ptr;
	   return PRINTLN;
}
"float" {
       fprintf(logout,"Line# %d: Token <%s> Lexeme %s found\n",line_count,ToUpper(yytext),yytext);
	   ptr=new SymbolInfo(yytext,"FLOAT");
	   ptr->startlineSetter(line_count);
	    ptr->endlineSetter(line_count);   
	   yylval.symbol=ptr;
	   return FLOAT;
}

"void" {
       fprintf(logout,"Line# %d: Token <%s> Lexeme %s found\n",line_count,ToUpper(yytext),yytext);
	   ptr=new SymbolInfo(yytext,"VOID");
	   ptr->startlineSetter(line_count);
	    ptr->endlineSetter(line_count);   
	   yylval.symbol=ptr;
	   return VOID;
}
"return" {
       fprintf(logout,"Line# %d: Token <%s> Lexeme %s found\n",line_count,ToUpper(yytext),yytext);
	   ptr=new SymbolInfo(yytext,"RETURN");
	   ptr->startlineSetter(line_count);
	    ptr->endlineSetter(line_count);   
	   yylval.symbol=ptr;
	   return RETURN;
}


{ID} {
	
     fprintf(logout,"Line# %d: Token <ID> Lexeme %s found\n",line_count,yytext); 
	 ptr=new SymbolInfo(yytext,"ID");
	 ptr->startlineSetter(line_count);
	 ptr->endlineSetter(line_count);   
	 yylval.symbol=ptr;
	 return ID;
	
   }
"(" { //tokenPrint("LPAREN",yytext);
      
      logPrint("LPAREN",yytext,line_count);
	  ptr=new SymbolInfo(yytext,"LPAREN");
	  ptr->startlineSetter(line_count);
	 ptr->endlineSetter(line_count);  
	  yylval.symbol=ptr;
	  return LPAREN;
     //fprintf(logout,"Line# %d: Token <LPAREN> Lexeme %s found\n",line_count,yytext); 
	 }
")" { //tokenPrint("RPAREN",yytext);
     logPrint("RPAREN",yytext,line_count);
	 ptr=new SymbolInfo(yytext,"RPAREN");
	 ptr->startlineSetter(line_count);
	 ptr->endlineSetter(line_count);  
	 yylval.symbol=ptr;
	 return RPAREN;
	}
"{" { //tokenPrint("LCURL",yytext);
     //symtable->EnterScope();
	 logPrint("LCURL",yytext,line_count);
	 ptr=new SymbolInfo(yytext,"LCURL");
	 ptr->startlineSetter(line_count);
	 ptr->endlineSetter(line_count);  
	 yylval.symbol=ptr;
	 return LCURL;
	 }
"}" { //tokenPrint("RCURL",yytext);
     //symtable->ExitScope();
	 logPrint("RCURL",yytext,line_count);
	 ptr=new SymbolInfo(yytext,"RCURL");
	 ptr->startlineSetter(line_count);
	 ptr->endlineSetter(line_count);  
	 yylval.symbol=ptr;
	 return RCURL;
	}
"[" { //tokenPrint("LSQUARE",yytext);
    logPrint("LSQUARE",yytext,line_count);
	ptr=new SymbolInfo(yytext,"LSQUARE");
	ptr->startlineSetter(line_count);
	 ptr->endlineSetter(line_count);  
	yylval.symbol=ptr;
	return LTHIRD;
    }
"]" { 
	//tokenPrint("RSQUARE",yytext);
     logPrint("RSQUARE",yytext,line_count); 
	 ptr=new SymbolInfo(yytext,"RSQUARE");
	 ptr->startlineSetter(line_count);
	 ptr->endlineSetter(line_count);  
	 yylval.symbol=ptr;
	 return RTHIRD;
}
"," { 
	//tokenPrint("COMMA",yytext);
    logPrint("COMMA",yytext,line_count);
	ptr=new SymbolInfo(yytext,"COMMA");
	ptr->startlineSetter(line_count);
	 ptr->endlineSetter(line_count);  
	yylval.symbol=ptr;
	return COMMA;
}
";" { 
	//tokenPrint("SEMICOLON",yytext);
    logPrint("SEMICOLON",yytext,line_count); 
	ptr=new SymbolInfo(yytext,"SEMICOLON");
	ptr->startlineSetter(line_count);
	 ptr->endlineSetter(line_count);  
	yylval.symbol=ptr;
	return SEMICOLON;
}
"="  { //tokenPrint("ASSIGNOP",yytext);
       logPrint("ASSIGNOP",yytext,line_count);
	   ptr=new SymbolInfo(yytext,"ASSIGNOP");
	   ptr->startlineSetter(line_count);
	 ptr->endlineSetter(line_count);  
	   yylval.symbol=ptr;
	   return ASSIGNOP;
 }
"!"  { //tokenPrint("NOT",yytext);
       logPrint("NOT",yytext,line_count);
	   ptr=new SymbolInfo(yytext,"NOT");
	   ptr->startlineSetter(line_count);
	 ptr->endlineSetter(line_count);  
	   yylval.symbol=ptr;
	   return NOT;
	 }
"+"|"-" { //tokenPrint("ADDOP",yytext);
         logPrint("ADDOP",yytext,line_count);
		 ptr=new SymbolInfo(yytext,"ADDOP");
		 ptr->startlineSetter(line_count);
	     ptr->endlineSetter(line_count);  
		 yylval.symbol=ptr;
		 return ADDOP;
		 
}
"++" {// tokenPrint("INCOP",yytext);
           logPrint("INCOP",yytext,line_count);
		   ptr=new SymbolInfo(yytext,"INCOP");
		   ptr->startlineSetter(line_count);
	       ptr->endlineSetter(line_count);  
	       yylval.symbol=ptr;
		   return INCOP;
}
"--" {
	     logPrint("DECOP",yytext,line_count);
		 ptr=new SymbolInfo(yytext,"DECOP");
		 ptr->startlineSetter(line_count);
	     ptr->endlineSetter(line_count);  
	     yylval.symbol=ptr;
		 return DECOP;
}
"&&"|"||" { //tokenPrint("LOGICOP",yytext);
           logPrint("LOGICOP",yytext,line_count);
		   ptr=new SymbolInfo(yytext,"LOGICOP");
		   ptr->startlineSetter(line_count);
	       ptr->endlineSetter(line_count);  
		   yylval.symbol=ptr;
		   return LOGICOP;
}

{NEWLINE} {line_count++;}
{BITOP} { //tokenPrint("BITOP",yytext);;
         logPrint("BITOP",yytext,line_count);
		 ptr=new SymbolInfo(yytext,"BITOP");
		 ptr->startlineSetter(line_count);
	     ptr->endlineSetter(line_count);  
		 yylval.symbol=ptr;
		 return BITOP;
		 
}
{RELOP} { //tokenPrint("RELOP",yytext);
         logPrint("RELOP",yytext,line_count);
		 ptr=new SymbolInfo(yytext,"RELOP");
		 ptr->startlineSetter(line_count);
	     ptr->endlineSetter(line_count);  
		 yylval.symbol=ptr;
		 return RELOP;		 
}
{MULOP} { //tokenPrint("MULOP",yytext);
         logPrint("MULOP",yytext,line_count);
		 ptr=new SymbolInfo(yytext,"MULOP");
		  ptr->startlineSetter(line_count);
	     ptr->endlineSetter(line_count);  
		 yylval.symbol=ptr;
		 return MULOP;
}
{DIGITS}  {// tokenPrint("CONST_INT",yytext);
          logPrint("CONST_INT",yytext,line_count);
		  ptr=new SymbolInfo(yytext,"CONST_INT");
		   ptr->startlineSetter(line_count);
	     ptr->endlineSetter(line_count);  
		  yylval.symbol=ptr;
		  return CONST_INT;
}
{DIGIT}*(\.{DIGITS})?(E[+-]?{DIGITS})?  {
	 //tokenPrint("CONST_FLOAT",yytext);
     logPrint("CONST_FLOAT",yytext,line_count);
	 ptr=new SymbolInfo(yytext,"CONST_FLOAT");
	  ptr->startlineSetter(line_count);
	     ptr->endlineSetter(line_count);  
	 yylval.symbol=ptr;
	 return CONST_FLOAT;
}
{DIGIT}*(\.{DIGIT}*)+(E[+-]?{DIGITS})?  {
	fprintf(logout,"Error at line# %d: TOO_MANY_DECIMAL_POINTS %s\n",line_count,yytext);
	//errors++;
}
{DIGIT}*(\.{DIGIT}*)?(E[+-]?{DIGITS}?)(\.{DIGIT}*)+  {
	fprintf(logout,"Error at line# %d: ILLFORMED_NUMBER %s\n",line_count,yytext);
	//errors++;
}
{DIGITS}{ID} {
	fprintf(logout,"Error at line# %d: INVALID_ID_SUFFIX_NUM_PREFIX %s\n",line_count,yytext);
	//errors++;
}
\'{CHARACTER}\'  {
	char *temp=new char[strlen(yytext)-1];
	for(int i=1;i<strlen(yytext)-1;i++)
	{
			temp[i-1]=yytext[i];															
	}
	if(strlen(temp)>1)
	{   
		//cout<<strlen(temp)<<endl;
		//tokenPrint("CONST_CHAR",charPrint(temp));
		logPrint("CONST_CHAR",charPrint(temp),line_count);
		ptr=new SymbolInfo(charPrint(temp),"CONST_CHAR");
		 ptr->startlineSetter(line_count);
	     ptr->endlineSetter(line_count);  
	    yylval.symbol=ptr;
	    return CONST_CHAR;
	}
	else{
		//tokenPrint("CONST_CHAR",temp);
		logPrint("CONST_CHAR",temp,line_count);
		ptr=new SymbolInfo(temp,"CONST_CHAR");
		 ptr->startlineSetter(line_count);
	     ptr->endlineSetter(line_count);  
	    yylval.symbol=ptr;
	    return CONST_CHAR;
	}
}
\'{CHARACTER}{CHARACTER}+\' {
	fprintf(logout,"Error at line# %d: MULTICHAR_CONST_CHAR %s\n",line_count,yytext);
	//errors++;
}

\'\' {
	fprintf(logout,"Error at line# %d: EMPTY_CONST_CHAR %s\n",line_count,yytext);
	//errors++;
}
\'{CHARACTER}* {
	fprintf(logout,"Error at line# %d: UNFINISHED_CONST_CHAR %s\n",line_count,yytext);
	//errors++;
}
\" {
    line_store=line_count;
	BEGIN(StringState);
	str = "";
	logStr="\"";
	flag=false;
}

<StringState>{
<<EOF>> {
	string tokenName="UNFINISHED_STRING";
	fprintf(logout,"Error at line# %d: %s %s\n",line_count,tokenName.c_str(),logStr.c_str());
	//errors++;
	yyterminate();
	BEGIN(INITIAL);
}
{NEWLINE}	{
	string tokenName="UNFINISHED_STRING";
	fprintf(logout,"Error at line# %d: %s %s\n",line_count,tokenName.c_str(),logStr.c_str());
	//errors++;
	line_count++;
	BEGIN(INITIAL);
}
\\\r\n 		|
\\\r 		|
\\\n 		{
   flag=true;
   line_count++;
   logStr +='\\';
   logStr +='\n';
}

\\ {
	str +='\\';
	logStr += yytext;
}

\\t {
   str +='\t';
   logStr +=yytext;
}
\\n {
	str +='\n';
	logStr +=yytext;
}
\\v  {
	str +='\v';
	logStr +=yytext;
}
\\b {
	str +='\b';
	logStr +=yytext;
}
\\a {
	str +='\a';
	logStr +=yytext;
}
\\f {
	str +='\f';
	logStr +=yytext;
}
\\r {
	str +='\r';
	logStr +=yytext;
}
\\0 {
	str +='\0';
	logStr +=yytext;
}
\\' {
	str +='\'';
	logStr +=yytext;
}
\\\" {
	str +='\"';
	logStr +=yytext;
}
\\\\ {
	str +='\\';
	logStr += yytext;
}


[^\n\r\"\\]  { str += yytext;logStr += yytext;}
\"  {
	if(flag)
	{   
		logStr+="\"";
		//fprintf(tokenout,"<MULTI LINE STRING, %s>\n",str.c_str());	
		string tokenName="MULTI LINE STRING";
		fprintf(logout,"Line# %d: Token <%s> Lexeme %s found\n",line_store,tokenName.c_str(),logStr.c_str()); 
	}
	else{
		logStr+="\"";
		//fprintf(tokenout,"<SINGLE LINE STRING, %s>\n",str.c_str());
		string tokenName="SINGLE LINE STRING";
		fprintf(logout,"Line# %d: Token <%s> Lexeme %s found\n",line_store,tokenName.c_str(),logStr.c_str()); 
	
	}	
	BEGIN(INITIAL);
}
}


"/*" {
	 BEGIN(multicomment);
	 line_store=line_count;
	 commentStr = "/*";	
}
<multicomment>{
 <<EOF>> {
	string tokenName="UNFINISHED_COMMENT";
	fprintf(logout,"Error at line# %d: %s %s\n",line_count,tokenName.c_str(),commentStr.c_str());
	//errors++;
	yyterminate();
	BEGIN(INITIAL);
 }

{NEWLINE} {
	commentStr +='\n';
	line_count++;	
}
"*/" {
  commentStr += "*/";	
  string tokenName="MULTI LINE COMMENT";
  fprintf(logout,"Line# %d: Token <%s> Lexeme %s found\n",line_store,tokenName.c_str(),commentStr.c_str()); 
  BEGIN(INITIAL);
}
. {commentStr +=yytext;}
}

"//" {
	 line_store=line_count;
	 BEGIN(singlecomment);
	 commentStr = "//";	
}
<singlecomment>{
 <<EOF>> {
	yyterminate();
	BEGIN(INITIAL);
 }
\\\r\n 		|
\\\r 		|
\\\n 		{
   line_count++;
   commentStr +='\\';
   commentStr +='\n';
}

\r\n 	|
\r 		|
\n 		{
	string tokenName="SINGLE LINE COMMENT";
    fprintf(logout,"Line# %d: Token <%s> Lexeme %s found\n",line_store,tokenName.c_str(),commentStr.c_str()); 
	line_count++;	
	BEGIN(INITIAL);
}
. {commentStr +=yytext;}
}
[ \t]+ { }
. 	{
	string tokenName="UNRECOGNIZED_CHAR";
	//errors++;
	fprintf(logout,"Error at line# %d: %s %s\n",line_count,tokenName.c_str(),yytext);
}
<<EOF>> {
	yyterminate();
}

%%
/* int main(int argc,char *argv[]){
	
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
	//tokenout= fopen("token.txt","w");
	yyin= fin;
	yylex();
	fclose(yyin);
	//fclose(tokenout);
	fclose(logout);
	return 0;
} */