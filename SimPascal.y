%code requires {
#include "AST/AST.h"
#include "generator/CodeGenerator.h"
#include <iostream>
#include <string>
extern Program *root;
using namespace std;

}

%{
int yyerror(const char *s);
int yywrap(void);
extern int yylex(void);
%}

%union {
    int ival;
    double dval;
    string *sval;
    char cval;

    Identifier *id;
    Name_list *name_list;
    Program *program;
    Program_head *program_head;
    Routine *routine;
    Routine_head *routine_head;
    Routine_body *routine_body;
    Const_part *const_part;
    Type_part *type_part;
    Var_part *var_part;
    Var_decl *var_decl;
    Var_decl_list *var_decl_list;
    Routine_part *routine_part;
    Const_expr_list *const_expr_list;
    Const_value *const_value;
    Type_decl_list *type_decl_list;
    Type_definition *type_definition;
    Type_decl *type_decl;
    Simple_type_decl *simple_type_decl;
    Array_type_decl *array_type_decl;
    Record_type_decl *record_type_decl;
    Field_decl_list *field_decl_list;
    Field_decl *field_decl;
    Function_decl *function_decl; 
    Function_head *function_head;
    Para_decl *para_type_list;
    Para_decl_list *para_decl_list;
    Va_para_list *val_para_list;
    Va_para_list *var_para_list;
    Stmt_list *stmt_list;
    Stmt *stmt;
    Expression *expression;
    Expression_list *expression_list;
    Direction *direction;
    Case_expr_list *case_expr_list;
    Case_expr *case_expr;
    Args_list *args_list;
}

%token ASSIGN EQ NE LE LT GE GT
%token PROGRAM CONST ARRAY VAR FUNCTION PROCEDURE PBEGIN END TYPE RECORD
%token IF THEN ELSE REPEAT UNTIL WHILE DO FOR TO DOWNTO CASE OF GOTO 
%token PLUS MINUS MUL DIV MOD AND OR NOT
%token DOT DOTDOT SEMI LP RP LS RS COMMA COLON PACKED

%token<ival> INTEGER
%token<dval> REAL 
%token<sval> ID SYS_CON SYS_FUNCT SYS_PROC SYS_TYPE READ
%token<cval> CHAR

%type<id> name
%type<name_list> name_list
%type<program> program
%type<program_head> program_head
%type<routine> routine sub_routine
%type<routine_head> routine_head
%type<routine_body> routine_body compound_stmt
%type<const_part> const_part
%type<type_part> type_part
%type<var_part> var_part
%type<var_decl> var_decl
%type<var_decl_list> var_decl_list
%type<routine_part> routine_part
%type<const_expr_list> const_expr_list
%type<const_value> const_value
%type<type_decl_list> type_decl_list
%type<type_definition> type_definition
%type<type_decl> type_decl
%type<simple_type_decl> simple_type_decl
%type<array_type_decl> array_type_decl
%type<record_type_decl> record_type_decl
%type<field_decl_list> field_decl_list
%type<field_decl> field_decl
%type<function_decl> function_decl procedure_decl
%type<function_head> function_head procedure_head
%type<para_decl_list> parameters para_decl_list
%type<para_type_list> para_type_list
%type<val_para_list> val_para_list
%type<var_para_list> var_para_list
%type<stmt_list> stmt_list
%type<stmt> stmt non_label_stmt assign_stmt if_stmt repeat_stmt while_stmt for_stmt goto_stmt case_stmt proc_stmt else_clause
%type<expression> expression expr term factor
%type<direction> direction
%type<case_expr_list> case_expr_list
%type<case_expr> case_expr
%type<expression_list> expression_list
%type<args_list> args_list

%start program
%%
name            : ID { $$ = new Identifier(*$1); }
                ;

program         : program_head routine DOT { $$ = new Program($1, $2); root = $$;}
                ;

program_head    : PROGRAM ID SEMI { $$ = new Program_head(*$2); }
                ;

routine         : routine_head routine_body { $$ = new Routine($1, $2); }
                ;

sub_routine     : routine_head routine_body { $$ = new Routine($1, $2); }
                ;

routine_head    : const_part type_part var_part routine_part { $$ = new Routine_head($1, $2, $3, $4); }
                ;

const_part      : CONST const_expr_list { $$ = new Const_part($2); }
                |                       { $$ = nullptr; } 
                ;

const_expr_list : const_expr_list name EQ const_value SEMI { $$ = $1; $$->push_back(new Const_expr($2, $4)); }
                | name EQ const_value SEMI                 { $$ = new Const_expr_list(); $$->push_back(new Const_expr($1, $3)); }
                ;

const_value     : INTEGER { $$ = new Const_value(S_INT, $1); }
                | REAL    { $$ = new Const_value(S_REAL, $1); }
                | CHAR    { $$ = new Const_value(S_CHAR, $1); }
                | SYS_CON { 
                            if (*$1 == "true") {
                                $$ = new Const_value(S_BOOLEAN, true); 
                            }
                            else if (*$1 == "false") {
                                $$ = new Const_value(S_BOOLEAN, false);
                            }
                            else {
                                $$ = new Const_value(S_INT, 0x7FFFFFFF);
                            }
                          }
                ;

type_part       : TYPE type_decl_list { $$ = new Type_part($2); }
                |                     { $$ = nullptr; }
                ;
        
type_decl_list  : type_decl_list type_definition { $$ = $1; $$->push_back($2); }
                | type_definition                { $$ = new Type_decl_list(); $$->push_back($1); }
                ;

type_definition : name EQ type_decl SEMI         { $$ = new Type_definition($1, $3); }
                ;
                
type_decl       : simple_type_decl               { $$ = new Type_decl($1); }
                | array_type_decl                { $$ = new Type_decl($1); }
                | record_type_decl               { $$ = new Type_decl($1); }
                ;

simple_type_decl    : SYS_TYPE                  { 
                                                    if (*$1 == "integer") {
                                                        $$ = new Simple_type_decl(S_INT);
                                                    } 
                                                    else if (*$1 == "real") {
                                                        $$ = new Simple_type_decl(S_REAL);
                                                    }
                                                    else if (*$1 == "char") {
                                                        $$ = new Simple_type_decl(S_CHAR);
                                                    }
                                                    else if (*$1 == "boolen") {
                                                        $$ = new Simple_type_decl(S_BOOLEAN);
                                                    }
                                                }
                    | name                                          { $$ = new Simple_type_decl($1); }
                    | LP name_list RP                               { $$ = new Simple_type_decl(new Enum_Type($2)); }
                    | const_value DOTDOT const_value                { $$ = new Simple_type_decl(new Const_range($1, $3)); }
                    | MINUS const_value DOTDOT const_value          { $$ = new Simple_type_decl(new Const_range(-*$2, $4)); }
                    | MINUS const_value DOTDOT MINUS const_value    { $$ = new Simple_type_decl(new Const_range(-*$2, -*$5)); }
                    | name DOTDOT name                              { $$ = new Simple_type_decl(new Enum_range($1, $3)); }
                    ;

array_type_decl     : ARRAY LS simple_type_decl RS OF type_decl     { $$ = new Array_type_decl($3, $6); }
                    ;

record_type_decl    : RECORD field_decl_list END                    { $$ = new Record_type_decl($2); }
                    ;

field_decl_list     : field_decl_list field_decl                    { $$ = $1; $$->push_back($2); }
                    | field_decl                                    { $$ = new Field_decl_list(); $$->push_back($1); } 
                    ;

field_decl          : name_list COLON type_decl SEMI                { $$ = new Field_decl($1, $3); }
                    ;

name_list   : name_list COMMA name                                    { $$ = $1; $$->push_back($3); }
            | name                                                    { $$ = new Name_list(); $$->push_back($1); }
            ;

var_part    : VAR var_decl_list                                     { $$ = new Var_part($2); }
            |                                                       { $$ = nullptr; }
            ;

var_decl_list   : var_decl_list var_decl                            { $$ = $1; $$->push_back($2); }
                | var_decl                                          { $$ = new Var_decl_list(); $$->push_back($1); }
                ;

var_decl    : name_list COLON type_decl SEMI                        { $$ = new Var_decl($1, $3); }
            ;

routine_part    : routine_part function_decl                        { $$ = $1; $$->push_back($2); }                
                | routine_part procedure_decl                       { $$ = $1; $$->push_back($2); }
                | function_decl                                     { $$ = new Routine_part(); $$->push_back($1); }
                | procedure_decl                                    { $$ = new Routine_part(); $$->push_back($1); }
                |                                                   { $$ = new Routine_part(); }
                ;

function_decl   : function_head SEMI sub_routine SEMI               { $$ = new Function_decl($1, $3); }
                ;

function_head   : FUNCTION name parameters COLON simple_type_decl   { $$ = new Function_head($2, $3, $5); }
                ;

procedure_decl  : procedure_head SEMI sub_routine SEMI              { $$ = new Function_decl($1, $3); }
                ;

procedure_head  : PROCEDURE name parameters                         { $$ = new Function_head($2, $3); }
                ;           

parameters      : LP para_decl_list RP                              { $$ = $2; }
                |                                                   { $$ = new Para_decl_list(); }
                ;

para_decl_list  : para_decl_list SEMI para_type_list                { $$ = $1; $$->push_back($3); }  
                | para_type_list                                    { $$ = new Para_decl_list(); $$->push_back($1); }
                ;

para_type_list  : var_para_list COLON simple_type_decl              { $$ = new Para_decl($1, $3); }
                | val_para_list COLON simple_type_decl              { $$ = new Para_decl($1, $3); }
                ;

var_para_list   : VAR name_list                                     { $$ = new Va_para_list($2, true); }
                ;

val_para_list   : name_list                                         { $$ = new Va_para_list($1, false); }
                ;

routine_body    : compound_stmt                                     { $$ = $1; }
                ;

compound_stmt   : PBEGIN stmt_list END                               { $$ = new Routine_body($2); } 
                ;

stmt_list       : stmt_list stmt SEMI                               { $$ = $1; $$->push_back($2); }
                |                                                   { $$ = new Stmt_list(); }
                ;

stmt            : INTEGER COLON non_label_stmt                      { $$ = $3; $3->Setlabel($1); }
                | non_label_stmt                                    { $$ = $1; }
                ;

non_label_stmt  : assign_stmt                                       { $$ = $1; }                                         
                | proc_stmt                                         { $$ = $1; }
                | compound_stmt                                     { $$ = $1; }
                | if_stmt                                           { $$ = $1; }
                | repeat_stmt                                       { $$ = $1; }
                | while_stmt                                        { $$ = $1; }
                | for_stmt                                          { $$ = $1; }
                | case_stmt                                         { $$ = $1; }
                | goto_stmt                                         { $$ = $1; }
                ;

assign_stmt     : name ASSIGN expression                              { $$ = new Assign_stmt($1, $3); }
                | name LS expression RS ASSIGN expression             { $$ = new Assign_stmt($1, $3, $6); }
                | name DOT name ASSIGN expression                       { $$ = new Assign_stmt($1, $5, $3); }
                ;

proc_stmt       : name                                                { $$ = new Proc_stmt($1); }
                | name LP args_list RP                                { $$ = new Proc_stmt($1, $3); }
                | SYS_PROC                                          {
                                                                        if (*$1 == "write")
                                                                            $$ = new Sysproc_stmt(S_WRITE); 
                                                                        else if (*$1 == "writeln") 
                                                                            $$ = new Sysproc_stmt(S_WRITELN);
                                                                    }
                | SYS_PROC LP expression_list RP                    { 
                                                                        if (*$1 == "write")
                                                                            $$ = new Sysproc_stmt(S_WRITE, $3); 
                                                                        else if (*$1 == "writeln")
                                                                            $$ = new Sysproc_stmt(S_WRITELN, $3);
                                                                    }
                | READ LP factor RP                                 { 
                                                                        $$ = new Sysproc_stmt(S_READ, $3); 
                                                                    } 
                ;

if_stmt         : IF expression THEN stmt else_clause               { $$ = new If_stmt($2, $4, $5); }
                ;

else_clause     : ELSE stmt                                         { $$ = $2; }       
                |                                                   { $$ = nullptr; }
                ;

repeat_stmt     : REPEAT stmt_list UNTIL expression                 { $$ = new Repeat_stmt($2, $4); }
                ;

while_stmt      : WHILE expression DO stmt                          { $$ = new While_stmt($2, $4); }
                ;

for_stmt        : FOR name ASSIGN expression direction expression DO stmt     { $$ = new For_stmt($2, $4, $5, $6, $8); }
                ;

direction       : TO                            { $$ = new Direction(S_TO); }
                | DOWNTO                        { $$ = new Direction(S_DOWNTO); }
                ;

case_stmt       : CASE expression OF case_expr_list END                 { $$ = new Case_stmt($2, $4); }
                ;

case_expr_list  : case_expr_list case_expr                              { $$ = $1; $$->push_back($2); } 
                | case_expr                                             { $$ = new Case_expr_list(); $$->push_back($1); }
                ;

case_expr       : const_value COLON stmt SEMI                           { $$ = new Case_expr($1, $3); }
                | name COLON stmt SEMI                                    { $$ = new Case_expr($1, $3); }
                ;

goto_stmt       : GOTO INTEGER                                          { $$ = new Goto_stmt($2); }
                ;

expression_list : expression_list COMMA expression                      { $$ = $1; $$->push_back($3); }
                | expression                                            { $$ = new Expression_list(); $$->push_back($1); }
                ;

expression      : expression GE expr                                    { $$ = new Binary_expression(S_GE, $1, $3); }
                | expression GT expr                                    { $$ = new Binary_expression(S_GT, $1, $3); }
                | expression LE expr                                    { $$ = new Binary_expression(S_LE, $1, $3); }
                | expression LT expr                                    { $$ = new Binary_expression(S_LT, $1, $3); }
                | expression EQ expr                                    { $$ = new Binary_expression(S_EQ, $1, $3); }
                | expression NE expr                                    { $$ = new Binary_expression(S_NE, $1, $3); }
                | expr                                                  { $$ = $1; }
                ;

expr            : expr PLUS term                                        { $$ = new Binary_expression(S_PLUS, $1, $3); }
                | expr MINUS term                                       { $$ = new Binary_expression(S_MINUS, $1, $3); }
                | expr OR term                                          { $$ = new Binary_expression(S_OR, $1, $3); }
                | term                                                  { $$ = $1; }
                ;

term            : term MUL factor                                       { $$ = new Binary_expression(S_MUL, $1, $3); }
                | term DIV factor                                       { $$ = new Binary_expression(S_DIV, $1, $3); }
                | term MOD factor                                       { $$ = new Binary_expression(S_MOD, $1, $3); }
                | term AND factor                                       { $$ = new Binary_expression(S_AND, $1, $3); }
                | factor                                                { $$ = $1; }
                ;

factor          : name                                                  { $$ = $1; }
                | name LP args_list RP                                  { $$ = new Func_stmt($1, $3); }
                | SYS_FUNCT                                             {
                                                                            if (*$1 == "ads")  
                                                                                $$ = new Sysfunc_stmt(S_ADS);
                                                                            else if (*$1 == "chr")
                                                                                $$ = new Sysfunc_stmt(S_CHR);
                                                                            else if (*$1 == "odd")
                                                                                $$ = new Sysfunc_stmt(S_ODD);
                                                                            else if (*$1 == "ord")
                                                                                $$ = new Sysfunc_stmt(S_ORD); 
                                                                            else if (*$1 == "pred")
                                                                                $$ = new Sysfunc_stmt(S_PRED);
                                                                            else if (*$1 == "sqr")
                                                                                $$ = new Sysfunc_stmt(S_SQR);
                                                                            else if (*$1 == "sqrt")
                                                                                $$ = new Sysfunc_stmt(S_SQRT);
                                                                            else if (*$1 == "succ")
                                                                                $$ = new Sysfunc_stmt(S_SUCC);
                                                                        }
                | SYS_FUNCT LP args_list RP                             {
                                                                            if (*$1 == "ads")  
                                                                                $$ = new Sysfunc_stmt(S_ADS, $3);
                                                                            else if (*$1 == "chr")
                                                                                $$ = new Sysfunc_stmt(S_CHR, $3);
                                                                            else if (*$1 == "odd")
                                                                                $$ = new Sysfunc_stmt(S_ODD, $3);
                                                                            else if (*$1 == "ord")
                                                                                $$ = new Sysfunc_stmt(S_ORD, $3); 
                                                                            else if (*$1 == "pred")
                                                                                $$ = new Sysfunc_stmt(S_PRED, $3);
                                                                            else if (*$1 == "sqr")
                                                                                $$ = new Sysfunc_stmt(S_SQR, $3);
                                                                            else if (*$1 == "sqrt")
                                                                                $$ = new Sysfunc_stmt(S_SQRT, $3);
                                                                            else if (*$1 == "succ")
                                                                                $$ = new Sysfunc_stmt(S_SUCC, $3);
                                                                        }
                | const_value                                           { $$ = $1; }
                | LP expression RP                                      { $$ = $2; }
                | NOT factor                                            { $$ = new Binary_expression(S_NOT, new Const_value(S_BOOLEAN, true), $2); }
                | MINUS factor                                          { $$ = new Binary_expression(S_MINUS, new Const_value(S_INT, 0), $2); }
                | name LS expression RS                                   { $$ = new Array_access($1, $3); }
                | name DOT name                                             { $$ = new Record_access($1, $3); }
                ;

args_list       : args_list COMMA expression                            { $$ = $1; $$->push_back($3); }
                | expression                                            { $$ = new Args_list(); $$->push_back($1); }
                ;

%%

int yyerror(const char *s) {
    printf("%s\n", s);
    return 0;
}

int yywrap() { 
   return 1;
}