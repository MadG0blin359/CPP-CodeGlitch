#include <iostream>
using namespace std;

class A {
    public:
    void hello() {
        cout << "\n--Hello from A";
    }
};

class B : public A {
    public:
    void hello() {
        cout << "\n--Hello from B";
    }
};

int main() {

    B obj1;

    obj1.A::hello();
    obj1.hello();

    return 0;
}