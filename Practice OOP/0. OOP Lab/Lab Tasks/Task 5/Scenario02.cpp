#include <iostream>
#include <string>
using namespace std;

class Employee {
    private:

    long ID;
    string name;
    string title;
    double hours;

    public:
    // Member function to calculate each employee salary
    double calculateSalary() {

        double hourlyRate, salary;
        int base_hours = 40;

        cout << "\n\t-----Calculate Salary-----\n";

        cout << "\n--Enter Hourly Rate : ";
        cin >> hourlyRate;

        if (hours <= base_hours) {
            salary = hours * hourlyRate;
        }

        else if (hours > base_hours) {
            double overTimeHours = hours - base_hours;
            salary = hourlyRate * overTimeHours * 2;         // Calculating salary for overtime hours
            salary += hourlyRate * base_hours;               // Calculating salary for base hours separately
        }

        return salary;
    }

    // Getters
    // long getID() {
    //     return ID;
    // }

    string getName() {
        return name;
    }

    // string getTitle() {
    //     return title;
    // }

    // double getHours() {
    //     return hours;
    // }

    // Setters
    void setID(long empID) {
        ID = empID;
    }

    void setName(string empName) {
        name = empName;
    }

    void setTitle(string empTitle) {
        title = empTitle;
    }

    void setHours(int empHours) {
        hours = empHours;
    }
};

// Function to display Employee Data
void displayEmpData(Employee empData[], int numOfEmp, double salary[]) {

    cout << "\n\t-----Displaying All Employees-----\n";
    // Loop to display the employee data
    for (int i = 0; i < numOfEmp; i++) {

        cout << "\n-----Employee " << i + 1 << "-----";

        cout << "\n--Name : " << empData[i].getName();
        cout << "\n--Salary : " << salary[i] << endl;
    }
}

int main() {

    const int limit = 5;        // Setting maximum limit to 5 employees only
    Employee empData[limit];
    int numOfEmp;

    // Variables to store user input
    long empID;
    string empName;
    string empTitle;
    double empHours;

    cout << "\n\t-----Employee Management System-----\n";

    cout << "\n--Enter the total number of employees (1-5) : ";
    cin >> numOfEmp;
    
    if (numOfEmp <= limit && numOfEmp > 0) {
        empData[numOfEmp];     // Adjusting the array according to the user needs
        double salary[numOfEmp];

        cout << "\n\t-----Add Employee Information-----\n";
        
        for (int i = 0; i < numOfEmp; i++) {        // Loop to prompt and take the input from the user

            cout << "\n-----Employee " << i + 1 << "-----\n";
            
            cout << "--ID : ";
            cin >> empID;
            empData[i].setID(empID);

            cout << "--Name : ";
            cin >> empName;
            empData[i].setName(empName);

            cout << "--Title : ";
            cin >> empTitle;
            empData[i].setTitle(empTitle);

            cout << "--Hours Worked : ";
            cin >> empHours;
            empData[i].setHours(empHours);

            salary[i] = empData[i].calculateSalary();       // Member function to calculate salary of each employee
        }

        displayEmpData(empData, numOfEmp, salary);          // Function to display all employees
    }

    // Display an error message if the number of employees entered by user is more than the limit
    else {
        cout << "\nSorry! The maximum limit is set to 5 employees only.\n";
    }

    return 0;
}