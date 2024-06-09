#include <iostream>
using namespace std;

class Person {
    int a;
    
    public:
    // Overloading Constructors, there can only be one default constructor
    // Person() {      // Default Constructor
    //     a = 0;    
    // }

    Person(int num = 0) {   // Default Parameterized Constructor - Two in one, this constructor behaves as both default and parameterized constructor. No need to define a separate default constructor
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