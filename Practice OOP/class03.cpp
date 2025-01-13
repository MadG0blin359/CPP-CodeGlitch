#include <iostream>
using namespace std;

class Employee {
    private:        // Cannot be accessed outside the class
    double salary;

    public:

    // Setter
    void setSalary(double s) {
        salary = s;
    }

    // Getter
    double getSalary() {
        return salary;
    }
};

int main() {

    Employee e1;
    double salary, result;

    cout << "\n--Enter salary : ";
    cin >> salary;
    
    e1.setSalary(salary);
    result = e1.getSalary();

    cout << "\nSalary is : " << result;

    return 0;
}