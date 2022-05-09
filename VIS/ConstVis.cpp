#pragma once
#include "VIS.h"

using namespace std;

string Const_part::Vis() {
    string res = "";
    return res;
}

string Const_expr::Vis() {
    vector<string> children;
    children.push_back(id->Vis());
    children.push_back(const_value->Vis());
    return Out("Const_expr", children);
}

string Const_value::Vis() {
    switch(base_type) {
        case S_INT:
            return Out("Const_value", Out(to_string(Value.int_value)));
        case S_REAL:
            return Out("Const_value", Out(to_string(Value.double_value)));
        case S_CHAR:
            return Out("Const_value", Out(to_string(Value.char_value)));
        case S_BOOLEN:
            return Out("Const_value", Out(to_string(Value.bool_value)));
        default:
            return "";
    }
}