%{

#include "thescanner.h"
#include <string>
#include <iostream>
#include "triestructure.h"

%}


%%

"/*"(([^*]|(("*"+)[^*/]))*)("*"+)"/"\n          ;//multiline comments
"//"((.)*)\n					                ;// single line comments
"boolean"	                       				{insertToTrie(yytext); printf("boolean "); return BOOLEAN;}
"break"						                    {insertToTrie(yytext); printf("break "); return BREAK;}
"class"						                    {insertToTrie(yytext); printf("class "); return CLASS;}
"double"					                    {insertToTrie(yytext); printf("double "); return DOUBLE;}
"else"					                    	{insertToTrie(yytext); printf("else "); return ELSE;}
"extends"		                    			{insertToTrie(yytext); printf("extends "); return EXTENDS;}
"for"				                    		{insertToTrie(yytext); printf("for "); return FOR;}
"if"				                    		{insertToTrie(yytext); printf("if "); return IF;}
"implements"		                    		{insertToTrie(yytext); printf("implements "); return IMPLEMENTS;}
"int"					                    	{insertToTrie(yytext); printf("int "); return INT;}
"interface"		                    			{insertToTrie(yytext); printf("interface "); return INTERFACE;}
"newarray"	                    				{insertToTrie(yytext); printf("newarray "); return NEWARRAY;}
"println"	                    				{insertToTrie(yytext); printf("println "); return PRINTLN;}
"readln"	                    				{insertToTrie(yytext); printf("readln "); return READLN;}
"return"			                    		{insertToTrie(yytext); printf("return "); return RETURN;}
"string"			                    		{insertToTrie(yytext); printf("string "); return STRING;}
"void"					                    	{insertToTrie(yytext); printf("void "); return VOID;}
"while"		                    				{insertToTrie(yytext); printf("while "); return WHILE;}
"+"							                    {printf("plus "); return PLUS;}
"-"					                    		{printf("minus "); return MINUS;}
"*"                 							{printf("multiplication "); return MULTIPLICATION;}
"/"							                    {printf("division "); return DIVISION;}
%							                    {printf("mod "); return MOD;}
"<"					                    		{printf("less "); return LESS;}
"<="		                    				{printf("lessequal "); return LESSEQUAL;}
">"			                    				{printf("greater "); return GREATER;}
">="	                    					{printf("greaterequal "); return GREATEREQUAL;}
"=="					                    	{printf("equal "); return EQUAL;}
"!="                    						{printf("notequal "); return NOTEQUAL;}
"&&"					                    	{printf("and "); return AND;}
"||"                    						{printf("or "); return OR;}
"!"						                    	{printf("not "); return NOT;}
"="	                    						{printf("assignop "); return ASSIGNOP;}
";"							                    {printf("semicolon "); return SEMICOLON;}
","					                    		{printf("coma "); return COMMA;}
"."					                    		{printf("period "); return PERIOD;}
"("                 							{printf("leftparen "); return LEFTPAREN;}
")"					                    		{printf("rightparen "); return RIGHTPAREN;}
"{"                 							{printf("leftbrace "); return LEFTBRACE;}
"}"								                {printf("rightbrace "); return RIGHTBRACE;}
(0x|0X)[0-9A-Fa-f]*+|[0-9]+	                    {printf("intconstant "); return INTCONSTANT;}
[0-9]+"."[0-9]+((E|e)("+"|"-")?([0-9]+))? 		{printf("doubleconstant "); return DOUBLECONSTANT;}
[0-9]+((E|e)("+"|"-")+([0-9]+))                 {printf("doubleconstant "); return DOUBLECONSTANT;}
[a-zA-Z_]?\"(\\.|[^\\"])*\"	                    {printf("stringconstant "); return STRINGCONSTANT;}
"true"						                    {insertToTrie(yytext);printf("booleanconstant "); return BOOLEANCONSTANT;}
"false"						                    {insertToTrie(yytext);printf("booleanconstant "); return BOOLEANCONSTANT;}
[a-zA-Z]([a-zA-Z]|[0-9]|"_")*	    	        {insertToTrie(yytext);printf("id "); return ID;}
\n	                       						{printf("\n");}
[ \t]+						                    ; // ignore whitespace
.							                    ;




%%
// keeps on going until there is not more input then prints out switch and symbol table
int main(int argc, char *argv[]){

    // initialize the triestructure with vectors and arrays.
    initTrieStruct();


    while(yylex()){}
    printSwitchTable();
    printSymbolTable();
    return 0;
}

// no clue what this does but the video tutorial wanted told me to add this.
int yywrap(void){

	return 1;
}
