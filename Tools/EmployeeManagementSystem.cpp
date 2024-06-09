#include <iostream>
#include <string>
using namespace std;

// Structure to store employee data
struct Employee {
    int empID = 0;
    string name;
    float salary = 0;

    void calculateBonus();      // Member function declaration
    // Member function inside the structure to prompt the user to enter employee data
    void inputEmployeeData() {
        static int i = 1;
        do {
            cout << endl << "-----------------------------" << endl;
            cout << "\tEmployee " << i << endl;
            cout << "-----------------------------" << endl;
            
            cout << "Enter ID (3-digit) : ";
            cin >> empID;

            cout << "Enter Name : ";
            cin >> name;

            cout << "Enter Salary : ";
            cin >> salary;

            i++;

            if (empID < 100 || empID > 999)
                cout << "\n-----Invalid Employee ID!-----\n";
            else if (salary < 0)
                cout << "\n-----Invalid Salary!-----\n";
        }

        while (empID < 100 || empID > 999 || salary < 0);
    }

};

// Member function outside the structure
void Employee::calculateBonus() {
    const float bonus = salary * 0.1;

    salary += bonus;

}

// Function to display the employee data
void displayEmployeeData(Employee employee[], int numOfEmployees) {

    cout << endl << "-----------------------------" << endl;
    cout << "\tEmployee Data" << endl;
    cout << "-----------------------------" << endl;
    
    for (int i = 0; i < numOfEmployees; ++i) {
        cout << "Employee ID: " << employee[i].empID << endl;
        cout << "Employee Name: " << employee[i].name << endl;
        cout << "Employee Salary: " << employee[i].salary << endl;
        cout << "-----------------------------" << endl;
    }
}

// Function to update salary
void giveRaise(Employee employee[], int numOfEmployees, float raise = 5.0) {
    for (int i = 0; i < numOfEmployees; i++) {
        employee[i].salary *= (1 + (raise/100)); 
    }

    cout << "\n-----All Employee's Salaries Updated Successfully!-----\n";
}

int main() {
    
    const int size = 50;
    Employee employee[size] = {};
    char menu_choice;
    int numOfEmployees = 0;

    cout << "\n\t*****Employee Management System*****\n";

    do {
        cout << "\n-----Menu-----\n";
        cout << "1. Record Employees\n";
        cout << "2. Display Records\n";
        cout << "3. Give Raise\n";
        cout << "4. Exit\n";
        cout << "--Select : ";
        cin >> menu_choice;

        if (menu_choice == '1') {
            cout << "\n--Enter the number of employees : ";
            cin >> numOfEmployees;
        }

        switch (menu_choice) {
        case '1':
            if (numOfEmployees < 1) {
                cout << "\n-----Invalid Input!-----\n";
            }

            else {
                for (int i = 0; i < numOfEmployees; i++) {
                    employee[i].inputEmployeeData();
                    employee[i].calculateBonus();
                }
            }
            break;

        case '2':
            if (numOfEmployees == 0)
                cout << "\n-----No Record Found!-----\n";
            else
                displayEmployeeData(employee, numOfEmployees);
            break;

        case '3':
            char raise_choice;
            float raise;
            
            do {
                cout << "\n-----Options-----";
                cout << "\n1. Default Raise";
                cout << "\n2. Custom Raise";
                cout << "\n3. Menu";
                cout << "\n--Select : ";
                cin >> raise_choice;

                if (numOfEmployees == 0 && raise_choice != '3')
                    cout << "\n-----No Record Found!-----\n";

                else
                    switch (raise_choice) {
                    case '1':
                        giveRaise(employee, numOfEmployees);
                        break;

                    case '2':
                        cout << "\n--Enter Raise Percentage : ";
                        cin >> raise;

                        giveRaise(employee, numOfEmployees, raise);
                        break;

                    case '3':
                        break;
                    
                    default:
                        cout << "\n-----Invalid Input!-----\n";
                        break;
                    }
            }

            while (raise_choice < '1' || raise_choice > '3');
            
            break;

        case '4':
            cout << "\nThank You! Have a Good Day\n";
            break;

        default:
            cout << "\n-----Invalid Input!-----\n";
            break;
        }
    }

    while (menu_choice != '4');

    return 0;
}