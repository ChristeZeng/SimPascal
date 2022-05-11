%option noyywrap

%{
#include <iostream>
#include <string>
#include "parser.hpp"
using namespace std;
%}

%%
"("    { return LP; }
")"    { return RP; }
"["    { return LS; }
"]"    { return RS; }
"."    { return DOT; }
","    { return COMMA; }
":"    { return COLON; }
"*"    { return MUL; }
"/"    { return DIV; }
"<>"   { return NE; }
"not"  { return NOT; }
"+"    { return PLUS; }
"-"    { return MINUS; }
">="   { return GE; }
"<="   { return LE; }
">"    { return GT; }
"<"    { return LT; }
"="    { return EQ; }
":="   { return ASSIGN; }
"mod"  { return MOD; }
".."   { return DOTDOT; }
";"    { return SEMI; }
"and"       { return AND; }
"array"     { return ARRAY; }
"begin"     { return PBEGIN; }
"case"      { return CASE; }
"const"     { return CONST; }
"div"       { return DIV; }
"do"        { return DO; }
"downto"    { return DOWNTO; }
"else"      { return ELSE; }
"end"       { return END; }
"for"       { return FOR; }
"function"  { return FUNCTION; }
"goto"      { return GOTO; }
"if"        { return IF; }
"of"        { return OF; }
"or"        { return OR; }
"packed"    { return PACKED; }
"procedure" { return PROCEDURE; }
"program"   { return PROGRAM; }
"record"    { return RECORD; }
"repeat"    { return REPEAT; }
"then"      { return THEN; }
"to"        { return TO; }
"type"      { return TYPE; }
"until"     { return UNTIL; }
"var"       { return VAR; }
"while"     { return WHILE; }
"boolen"|"char"|"integer"|"real"            { 
                                                yylval.sval = new string(yytext);
                                                return SYS_TYPE; 
                                            }
"true"|"false"|"maxint"                     { 
                                                yylval.sval = new string(yytext);
                                                return SYS_CON;
                                            }   
"ads"|"chr"|"odd"|"ord"|"pred"|"sqr"|"sqrt"|"succ" {
                                                yylval.sval = new string(yytext);
                                                return SYS_FUNCT;
                                            }
"write"|"writeln"                           {
                                                yylval.sval = new string(yytext);
                                                return SYS_PROC;
                                            }
"read"                                      {
                                                yylval.sval = new string(yytext);
                                                return READ;
                                            }                                            

[ \t\n]                     { /* ignore */ }

[a-zA-Z][a-zA-Z0-9]*        {
                                std::cout << "Identifier: " << yytext << std::endl;
                                yylval.sval = new string(yytext);
                                return ID;
                            }

[+-]?[0-9]+                 {
                                std::cout << "Integer: " << yytext << std::endl;
                                yylval.ival = atoi(yytext);
                                return INTEGER;
                            }

[+-]?[0-9]+\.[0-9]+         {
                                std::cout << "Real: " << yytext << std::endl;
                                yylval.dval = atof(yytext);
                                return REAL;
                            }

\'(\\.|[^"\\])*\'           {
                                std::cout << "Char: " << yytext << std::endl;
                                yylval.cval = *yytext;
                                return CHAR;
                            }
%%