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
    char *sval; //?why
    char cval;

    Identifier *id;
    Program *program;
    Routine *routine;
    Routine_head *routine_head;
    Routine_body *routine_body;
    Const_part *const_part;
    Type_part *type_part;
    Var_part *var_part;
    Routine_part *routine_part;
    Const_expr_list *const_expr_list;
    Const_value *const_value;
    Type_decl_list *type_decl_list;
    Type_definition *type_definition;
    Type_decl *type_decl;
}
%token PROGRAM ID CONST ARRAY VAR FUNCTION PROCEDURE BEGIN END TYPE RECORD
%token INTEGER REAL CHAR STRING
%token SYS_CON SYS_FUNCT SYS_PROC SYS_TYPE
%token IF THEN ELSE REPEAT UNTIL WHILE DO FOR TO DOWNTO CASE OF GOTO READ
%token ASSIGN EQ NE LE LT GE GT
%token PLUS MINUS MUL DIV MOD AND OR NOT
%token DOT DOTDOT SEMI LP RP LS RS COMMA COLON

%type
%type<program> program
%type<sval> program_head
%type<routine> routine sub_routine
%type<routine_head> routine_head
%type<routine_body> routine_body
%type<const_part> const_part
%type<type_part> type_part
%type<var_part> var_part
%type<routine_part> routine_part
%type<const_expr_list> const_expr_list
%type<const_value> const_value
%type<type_decl_list> type_decl_list
%type<type_definition> type_definition
%type<type_decl> type_decl

%%
name: ID

program         : program_head routine DOT
                ;

program_head    : PROGRAM ID SEMI
                ;

routine         : routine_head routine_body
                ;

sub_routine : routine_head routine_body
            ;

routine_head : const_part type_part var_part routine_part

const_part : CONST const_expr_list  
           |  
           ;

const_expr_list : const_expr_list name EQ const_value SEMI
                | name EQ const_value SEMI
                ;

const_value : INTEGER 
            | REAL 
            | CHAR 
            | STRING  
            | SYS_CON
            ;

type_part : TYPE type_decl_list  
          |
          ;
        
type_decl_list  : type_decl_list type_definition  
                | type_definition
                ;

type_definition : name EQ type_decl SEMI
                ;
                
type_decl   : simple_type_decl  
            | array_type_decl  
            | record_type_decl
            ;

simple_type_decl    : SYS_TYPE  
                    | name  
                    | LP name_list RP  
                    | const_value DOTDOT const_value  
                    | MINUS const_value DOTDOT const_value
                    | MINUS const_value DOTDOT MINUS const_value
                    | name DOTDOT name
                    ;

array_type_decl : ARRAY LS simple_type_decl RS OF type_decl
                ;

record_type_decl    : RECORD field_decl_list END
                    ;

field_decl_list : field_decl_list field_decl  
                | field_decl
                ;

field_decl : name_list COLON type_decl SEMI

name_list   : name_list COMMA ID  
            | ID
            ;

var_part    : VAR var_decl_list  
            | 
            ;

var_decl_list   : var_decl_list var_decl  
                | var_decl
                ;

var_decl    : name_list COLON type_decl SEMI
            ;

routine_part    : routine_part function_decl  
                | routine_part  procedure_decl
                | function_decl  
                | procedure_decl  
                | 
                ;

function_decl   : function_head SEMI sub_routine SEMI
                ;

function_head   : FUNCTION name parameters COLON simple_type_decl
                ;
procedure_decl  : procedure_head SEMI sub_routine SEMI
                ;

procedure_head  : PROCEDURE name parameters
                ;           

parameters      : LP para_decl_list RP  
                |  
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