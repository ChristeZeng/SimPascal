#include <iostream>
#include <llvm/IR/Value.h>
#include "AST/AST.h"
#include "generator/CodeGenerator.h"
#include "parser.hpp"
using namespace std;
using namespace llvm;

Program *root;
extern int yyparse();
int main() {
	
    yyparse();
	// InitializeNativeTarget();
	// InitializeNativeTargetAsmPrinter();
	// InitializeNativeTargetAsmParser();
	// CodeGenerator context;
	// context.generateCode(*root);

    return 0;
}