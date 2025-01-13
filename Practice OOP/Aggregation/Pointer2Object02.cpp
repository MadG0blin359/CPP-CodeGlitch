#include <iostream>
#include <string>
using namespace std;

class A {
    int a;
    public:
    A() : a(0) {}

    int geta() const {
        return a;
    }

    void seta(int x) {
        a = x;
    }
};

class B {
    A *ptr;

    public:
    B() : ptr(new A[5]) {
        cout << ptr->geta();
    }

    void update() {
        ptr->seta(9);
    }
};

int main() {

    B ob;    

    return 0;
}