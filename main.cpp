#include <iostream>
#include <llvm/IR/Value.h>
#include "AST/AST.h"
#include "parser.hpp"
using namespace std;

extern int yyparse();
int main() {
    yyparse();
    return 0;
}