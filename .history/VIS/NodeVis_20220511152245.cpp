#include "VIS.h"

using namespace std;

string Identifier::Vis() {
    cout << "Identifier" << endl;
    return Out("Identifier", Out(name));
}