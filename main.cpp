#include <iostream>
#include "AST/AST.h"
using namespace std;

extern int yyparse();
int main() {
    yyparse();
    return 0;
}