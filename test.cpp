#include <iostream>

using namespace std;

class A {
public:
    virtual int getA() = 0;
};

class B : public A {
private:
    int a;
public:
    B(int a) : a(a) {}
    int getA() {
        return a;
    }
};

int main() {
    A* a = new B(1);
    cout << a->getA() << endl;
}