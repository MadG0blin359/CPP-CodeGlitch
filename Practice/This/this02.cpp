// Returning by Pointer
#include <iostream>
#include <string>
using namespace std;

class A {
    int n;
    string name;

    public:
    int num;
    A(int n = 0, string setn = "NULL", int num = 0) {
        this->n = n;        // Data member = parameter
        name = setn;
        this->num = num;
    }

    A* update() {
        return this;       // Returns a pointer (address) to the current object
    }

    void display() {
        cout << n << endl;
        cout << name << endl;
        cout << num << endl;
    }
};

int main() {

    A obj1(5, "Test0X", 10), obj2;
    A *ptr;

    ptr = obj1.update();        // Shallow Copy (Both entities are dependent)
    
    cout << "\nptr display" << endl;
    ptr->display();

    ptr->num = 15;
    obj2 = *ptr;        // Deep Copy (Both entities are independent)

    cout << "\nobj1 display" << endl;
    obj1.display();
    
    cout << "\nobj2 display" << endl;
    obj2.display();

    cout << "\nupdate obj2" << endl;
    obj2.num = 20;

    cout << "\nobj1 display again" << endl;
    obj1.display();


    return 0;
}