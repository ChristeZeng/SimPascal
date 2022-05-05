#include <iostream>
#include <llvm/IR/Value.h>
#include "AST/AST.h"
#include "generator/CodeGenerator.h"
//#include "parser.hpp"
using namespace std;
using namespace llvm;

extern int yyparse();
extern Program *program;
int main() {
    yyparse();
	InitializeNativeTarget();
	InitializeNativeTargetAsmPrinter();
	InitializeNativeTargetAsmParser();
	CodeGenerator context;
	context.generateCode(*program);

    return 0;
}