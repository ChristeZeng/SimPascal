#pragma once
#include "../AST/AST.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

string Out(string name) {
    return "{ \"name\" : \"" + name + "\" }";
}

string Out(string name, vector<string> vec) {
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

string Out(string name, string value) {
    return "{\"name\" : \"" + name + "\", \"children\" : \"" + value + "\"}";
}

string Out(string name, string value, vector<string> children) {
    string res = "";
    res += "{";
    res += "\"name\" : \"" + name + "\",";
    res += "\"value\" : \"" + value + "\",";
    res += "\"children\" : [";
    for (int i = 0; i < children.size(); i++) {
        res += children[i];
        if (i != children.size() - 1) {
            res += ",";
        }
    }
    res += "]";
    res += "}";
    return res;
}