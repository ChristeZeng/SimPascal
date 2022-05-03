%{
#include <iostream>
#include <string>
#include "AST/AST.h"
using namespace std;

void yyerror(const char *s);
int yylex();
%}

%union {
    int ival;
    double dval;
    string *sval; //?why
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
    Function_decl *procedure_decl;
    Function_head *function_head;
    Function_head *procedure_head;
    Para_decl *para_decl;
    Para_decl_list *para_decl_list;
    Para_type_list *para_type_list;
}

%token ASSIGN EQ NE LE LT GE GT
%token PROGRAM CONST ARRAY VAR FUNCTION PROCEDURE BEGIN END TYPE RECORD
%token IF THEN ELSE REPEAT UNTIL WHILE DO FOR TO DOWNTO CASE OF GOTO 
%token PLUS MINUS MUL DIV MOD AND OR NOT
%token DOT DOTDOT SEMI LP RP LS RS COMMA COLON

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
%type<routine_body> routine_body
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
%type<function_decl> function_decl
%type<procedure_decl> procedure_decl
%type<function_head> function_head
%type<procedure_head> procedure_head
%type<para_decl_list> parameters para_decl_list
%type<para_type_list> para_type_list
%%
name            : ID { $$ = new Identifier($1); }
                ;

program         : program_head routine DOT { $$ = new Program($1, $2); }
                ;

program_head    : PROGRAM ID SEMI { $$ = new Program_head($2); }
                ;

routine         : routine_head routine_body { $$ = new Routine($1, $2); }
                ;

sub_routine     : routine_head routine_body { $$ = new Routine($1, $2); }
                ;

routine_head    : const_part type_part var_part routine_part { $$ = new Routine_head($1, $2, $3, $4); }
                ;

const_part      : CONST const_expr_list { $$ = new Const_part($2); }
                |                       { $$ = new Const_part(); } //?
                ;

const_expr_list : const_expr_list name EQ const_value SEMI { $$ = $1; $$->push_back(new Const_expr($2, $4)); }
                | name EQ const_value SEMI                 { $$ = new Const_expr_list(); $$->push_back(new Const_expr($1, $3)); }
                ;

const_value     : INTEGER { $$ = new Const_value(Const_value::Const_type::INT, $1); }
                | REAL    { $$ = new Const_value(Const_value::Const_type::REAL, $1); }
                | CHAR    { $$ = new Const_value(Const_value::Const_type::CHAR, $1); }
                | SYS_CON { 
                            if ($1 == "true" || $1 == "false") {
                                $$ = new Const_value(Const_value::Const_type::BOOL, $1); 
                            }
                            else {
                                $$ = new Const_value(Const_value::Const_type::STRING, $1);
                            } //有问题
                          }
                ;

type_part       : TYPE type_decl_list { $$ = new Type_part($2); }
                |                     { $$ = new Type_part(); }
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
                                                    if ($1 == "integer") {
                                                        $$ = new Simple_type_decl(Base_type::INT);
                                                    } 
                                                    else if ($1 == "real") {
                                                        $$ = new Simple_type_decl(Base_type::REAL);
                                                    }
                                                    else if ($1 == "char") {
                                                        $$ = new Simple_type_decl(Base_type::CHAR);
                                                    }
                                                    else if ($1 == "boolean") {
                                                        $$ = new Simple_type_decl(Base_type::BOOLEN);
                                                    }
                                                }
                    | name                                          { $$ = new Simple_type_decl($1); }
                    | LP name_list RP                               { $$ = new Simple_type_decl(new Enum_Type($2)); }
                    | const_value DOTDOT const_value                { $$ = new Simple_type_decl(new Const_range(*$1, $3)); }
                    | MINUS const_value DOTDOT const_value          { $$ = new Simple_type_decl(new Const_range(-*$1, *$3)); }
                    | MINUS const_value DOTDOT MINUS const_value    { $$ = new Simple_type_decl(new Const_range(-*$1, -*$3)); }
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

name_list   : name_list COMMA ID                                    { $$ = $1; $$->push_back($3); }
            | ID                                                    { $$ = new Name_list(); $$->push_back($1); }
            ;

var_part    : VAR var_decl_list                                     { $$ = new Var_part($2); }
            | 
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

para_decl_list  : para_decl_list SEMI para_type_list   
                | para_type_list
                ;

para_type_list  : var_para_list COLON simple_type_decl
                | val_para_list COLON simple_type_decl
                ;

var_para_list   : VAR name_list
                ;

val_para_list   : name_list
                ;

routine_body    : compound_stmt

compound_stmt   : BEGIN stmt_list END
                ;

stmt_list       : stmt_list stmt SEMI  
                |  
                ;

stmt            : INTEGER COLON non_label_stmt  
                | non_label_stmt
                ;

non_label_stmt  : assign_stmt 
                | proc_stmt 
                | compound_stmt 
                | if_stmt 
                | repeat_stmt 
                | while_stmt
                | for_stmt 
                | case_stmt 
                | goto_stmt
                ;

assign_stmt     : ID ASSIGN expression
                | ID LS expression RS ASSIGN expression
                | ID DOT ID ASSIGN expression
                ;

proc_stmt       : ID
                | ID LP args_list RP
                /* | SYS_PROC
                | SYS_PROC LP expression_list RP
                | READ LP factor RP */
                ;

if_stmt         : IF expression THEN stmt else_clause
                ;

else_clause     : ELSE stmt 
                | 
                ;

repeat_stmt     : REPEAT stmt_list UNTIL expression
                ;

while_stmt      : WHILE expression DO stmt
                ;

for_stmt        : FOR ID ASSIGN expression direction expression DO stmt
                ;

direction       : TO 
                | DOWNTO
                ;

case_stmt       : CASE expression OF case_expr_list  END
                ;

case_expr_list  : case_expr_list case_expr  
                | case_expr
                ;

case_expr       : const_value COLON stmt SEMI
                | ID COLON stmt SEMI
                ;

goto_stmt       : GOTO INTEGER
                ;

expression_list : expression_list COMMA expression  
                | expression
                ;

expression      : expression GE expr  
                | expression GT expr  
                | expression LE expr
                | expression LT expr  
                | expression EQ expr  
                | expression NE expr  
                | expr
                ;

expr            : expr PLUS term  
                | expr MINUS term  
                | expr OR term  
                | term
                ;

term            : term MUL factor  
                | term DIV factor  
                | term MOD factor 
                | term AND factor  
                | factor
                ;

factor          : name  
                | name LP args_list RP  
                | SYS_FUNCT 
                | SYS_FUNCT LP args_list RP  
                | const_value  
                | LP expression RP
                | NOT factor  
                | MINUS factor  
                | ID LS expression RS
                | ID DOT ID
                ;

args_list       : args_list COMMA expression  
                | expression
                ;