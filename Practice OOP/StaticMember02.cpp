#include <iostream>
using namespace std;

class Employee {
    static int count;
    static int id;

    public:
    void display(void) {
        cout << "\n--Displaying ID--" << endl;
        cout << "\n--Count is : " << ++count;     // Displaying the static data member in a non-static member function
    }

    static int getId() {
        return id;
    }
};

int Employee::count = 0, Employee::id = 5668;    // Explicitly initializing the static data member

int main() {

    //Employee::display();     // Must be a static member function to be called without an object
    
    Employee obj1;

    obj1.display();
    cout << "\n--ID : " << Employee::getId();

    return 0;
}