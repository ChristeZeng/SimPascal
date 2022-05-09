#include "VIS.h"

using namespace std;

string Identifier::Vis() {
    return Out("Identifier", name);
}

string Stmt::Vis() {
    return Out("Stmt");
}