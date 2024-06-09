#include <iostream>
#include <string>
using namespace std;

class A {
    public:
    A() {
        cout << "This memory address : " << this;
    }
};

int main() {

    A obj1;

    cout << "\nObj1 memory address : " << &obj1;

    return 0;
}