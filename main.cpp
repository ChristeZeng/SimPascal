#include <iostream>
#include <llvm/IR/Value.h>
#include "AST/AST.h"
#include "generator/CodeGenerator.h"
#include "VIS/VIS.h"
#include "parser.hpp"
#include <fstream>
using namespace std;
using namespace llvm;

Program *root;
extern int yyparse();
int main() {
	
    yyparse();
	if (root) {
		ofstream out("tree.json");
		out << root->Vis() << endl;
		out.close();
	}
	else {
		cout << "no" << endl;
	}
	InitializeNativeTarget();
	InitializeNativeTargetAsmPrinter();
	InitializeNativeTargetAsmParser();
	CodeGenerator codeGenerator;
    codeGenerator.generateCode(*root);

    return 0;
}