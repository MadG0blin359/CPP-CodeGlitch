#include <iostream>
#include <string>
using namespace std;

// Forward declaration
class Employee;
class DataBackUp;
class Company;

class DataBackUp {
    Employee *emp_list_backup;
    int max_emp_backup;
    int count_emp_backup;

    public:
    DataBackUp() {}
    // This initializer points to the same array as emp_list, this copy only copies the pointer value itself, not the data that the pointer is pointing to (adddress of array).
    DataBackUp(Employee *emp_list, int count_emp, int max_emp) : emp_list_backup(emp_list), max_emp_backup(max_emp), count_emp_backup(count_emp) {}

};

class Employee {
    string name;
    int age;
    string rank;

    public:
    Employee() : name(""), age(0), rank("") {}

    // Getters
    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    string getRank() {
        return rank;
    }

    // Setters
    void setName() {
        cout << "--Enter Name : ";
        cin.ignore();
        getline(cin, name);
    }

    void setAge() {
        cout << "--Enter Age : ";
        cin >> age;
    }

    void setRank() {
        cout << "--Enter Rank : ";
        cin.ignore();
        getline(cin, rank);
    }
};

class Company {
    string dept_name;
    double salary;
    static const int max_emp = 25;      // Max capacity
    static int count_emp;           // Total size
    Employee *emp_list;
    DataBackUp bckp;

    public:
    Company() : bckp(emp_list, count_emp, max_emp) {        // Default constructor
        emp_list = new Employee[max_emp];
    }

    void addEmployee() {
        cout << "\n\t-----Add Employee " << count_emp + 1 << "-----\n";
        emp_list[count_emp].setName();
        emp_list[count_emp].setAge();
        
        cout << "--Enter Department : ";
        cin.ignore();
        getline(cin, dept_name);

        emp_list[count_emp].setRank();
        
        cout << "--Enter Salary : ";
        cin >> salary;

        count_emp++;
    }

    void displayEmployees() {
        cout << "\n\t-----Employee Details-----\n";

        for (int i = 0; i < count_emp; i++) {
            cout << "\n-------------------------"
                 << "\n-------Employee " << i+1 << "--------"
                 << "\n-------------------------"
                 << "\nName : " << emp_list[i].getName()
                 << "\nAge : " <<emp_list[i].getAge()
                 << "\nDepartment : " << dept_name
                 << "\nRank : " << emp_list[i].getRank()
                 << "\nSalary : " << "$" << salary;
        }
    }

    // No need to deallocate the memory as the employee data is still needed for use in other functions/classes
    // We can deallocate the memory for emp_list if we are performing deep copy
    ~Company() {
        delete[] emp_list;
    }

};

int Company::count_emp = 0;

// Defining the constructor outside the class to avoid incomplete/undefined class/datatype error
DataBackUp::DataBackUp(Employee *emp_list, int count_emp, int max_emp) {
    // Allocate memory for emp_list_backup to copy the actual data (Deep copy)
        emp_list_backup = new Employee[max_emp];

        // Copy each Employee object from emp_list to emp_list_backup (Deep Copy)
        for (int i = 0; i < max_emp; ++i) {
            emp_list_backup[i] = emp_list[i];
        }
}

int main() {

    Company tesla;
    char menu_choice;

    cout << "\n\t-----Employee Management System-----\n";

    do {
        cout << "\n\n-----Menu-----"
             << "\n1. Add Employee"
             << "\n2. Display Employees"
             << "\n3. Exit"
             << "\n--Enter choice : ";
        cin >> menu_choice;

        switch (menu_choice) {
            case '1':
                tesla.addEmployee();
            break;

            case '2':
                tesla.displayEmployees();
            break;

            case '3':
                // Exit the program
            break;
            
            default:
                cout << "\n-----Invalid Input!-----\n";
            break;
        }
    }

    while (menu_choice != '3');

    return 0;
}