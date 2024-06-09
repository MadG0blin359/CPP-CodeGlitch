#include <iostream>
#include <string>
using namespace std;

// Forward declaration of Programmer class
class Programmer;

// Base Class
class Employee {
    long id;
    double salary;

    public:
    string name;

    void displayDerivedClass(Programmer dcName);

    // Employee() {
    //     cout << "\n--I'm the Default Constructor of Class Employee.";
    // }

    // Employee(double eSalary) {
    //     salary = eSalary;
    //     cout << "\n--Salary : " << salary;
    // }

};

// Derived Class
class Programmer : public Employee {
    public:
    // void displayDerivedClass() {
    //     cout << "\nhello";  
    // }
    Programmer(string pName) {
        name = pName;
        cout << "\n--Name : " << name;
        // displayDerivedClass();
        // cout << "\n--Enter Name : ";
        // cin >> name;
    }
};

void Employee::displayDerivedClass(Programmer dcName) {
        cout << "\n--Displaying form Base Class : " << dcName.name;
    }

int main() {

    // Employee e1(15), e2(25);
    Programmer p1("Shawaiz");
    Employee e1;
    e1.displayDerivedClass(p1);
    

    return 0;
}