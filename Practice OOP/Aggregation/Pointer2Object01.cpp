#include <iostream>
using namespace std;

class A {
    public:
    int a;
    A(int x = 0) : a(x) {

    }

    void display() {
        cout << "Test " << a;
    }
};

// ptr can access public members directly.
// ptr can access private & protected members indirectly through Encapsulation

class B {
    private:
    A *ptr;
    string name;
    
    public:
    B() : ptr(new A) {
        ptr->a = 3;
        ptr->display();
    }
    
};

int main() {

    B ob;

    return 0;
}
