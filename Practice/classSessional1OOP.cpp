#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    int employee_id;

    void input();  
    void output(); 

public:
    void input() {  
        cout << "\nEnter Name : ";
        cin >> name;

        cout << "\nEnter Employee ID : ";
        cin >> employee_id;
    }

    void output() {  
        cout << "\nName : " << name;
        cout << "\nID : " << employee_id;
    }
};

int main() {
    Employee Emp;

    Emp.input();
    Emp.output();

    return 0;
}
