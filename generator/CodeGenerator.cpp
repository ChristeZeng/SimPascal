#include "CodeGenerator.h"

using namespace std;
using namespace llvm;

void CodeGenerator::generateCode(Program& root) {
    root.codegen(*this);
    module->print(llvm::errs(), nullptr);
}