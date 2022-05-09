#include "VIS.h"

using namespace std;

string Identifier::Vis() {
    return Out("Identifier", Out(name));
}