#include <iostream>
using namespace std;

class Person {
    int a;
    
    public:
    // Overloading Constructors
    Person() : a(0) {}         // Default Constructor with initializer list
    Person(int num) {   // Parameterized Constructor
        a = num;
    }

    void display() {
        cout << a << endl;
    }

};

int main() {

    Person obj01, obj02(7);

    obj01.display();
    obj02.display();

    return 0;
}