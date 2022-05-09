#pragma once
#include "../AST/AST.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

inline string Out(string name) {
    return "{ \"name\" : \"" + name + "\" }";
}

inline string Out(string name, vector<string> vec) {
    string res = "";
    res += "{";
    res += "\"name\" : \"" + name + "\",";
    res += "\"children\" : [";
    for (int i = 0; i < vec.size(); i++) {
        res += vec[i];
        if (i != vec.size() - 1) {
            res += ",";
        }
    }
    res += "]";
    res += "}";
    return res;
}

inline string Out(string name, string value) {
    return Out(name, vector<string>{value});
}