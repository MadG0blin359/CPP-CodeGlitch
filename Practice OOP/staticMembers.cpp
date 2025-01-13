#include <iostream>
using namespace std;

class Employee {
    long id;
    static int count;       // By default, static member variables are initialized to zero
    
    public:
    // Default constructor to cout the number of objects created
    Employee() {
        count++;
    }

    // Setters (Mutators)
    void setId(void) {
        cout << "\n--Enter ID : ";
        cin >> id;
    }

    // Getters (Accessors)
    void getId(void) {
        cout << "\n--ID : " << id;
        // return id;
    }

    static int getCount(void) {
        return count;
    }

};

// Explicit initialization of static member variable outside the class definition
// int Employee::count = 0;

int main() {

    class Employee e1;      // Object/instances

    // cout << "\n--Enter ID : ";
    e1.setId();

    // cout << "\n--ID : " << e1.getId();
    e1.getId();

    cout << "\n--Total Employees : " << Employee::getCount();

    return 0;
}