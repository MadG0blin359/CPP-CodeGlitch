#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    int max_rate;
    double rateCommunication, rateTeamwork, rateProblemSolving;
};

// Function to display employee data
void display_data(Employee employee[], int numOfEmp) {
    cout << "\n\t-----Employee Data-----\n";
    // Loop to display employee data
    for (int i = 0; i < numOfEmp; ++i) {
        cout << "\nEmployee " << i + 1 << ":\n";
        cout << "--Name : " << employee[i].name << endl;
        cout << "--Communication : " << employee[i].rateCommunication << endl;
        cout << "--Teamwork : " << employee[i].rateTeamwork << endl;
        cout << "--Problem Solving : " << employee[i].rateProblemSolving << endl;
        cout << "------------------------\n";
    }
}

// Functiont to change ratings
void change_ratings(int employeeIndex, Employee employee[]) {

    double newRating;
    // Prompting user to enter updated ratings
    cout << "Enter the updated rating for " << employee[employeeIndex].name << " :\n";

    cout << "--Communication : ";
    cin >> employee[employeeIndex].rateCommunication;
    
    cout << "--Teamwork : ";
    cin >> employee[employeeIndex].rateTeamwork;
    
    cout << "--Problem Solving : ";
    cin >> employee[employeeIndex].rateProblemSolving;

    cout << "------------------------\n";

    cout << "Ratings updated successfully!\n";

}

// Function to calculate average
void calc_average_rating(int employeeIndex, Employee employee[]) {
    double emp_avg;
    // Calculating average
    emp_avg = employee[employeeIndex].rateCommunication + employee[employeeIndex].rateTeamwork + employee[employeeIndex].rateProblemSolving;

    emp_avg /= 3;

    // Displaying the calculated average
    cout << "\n--Average Ratings : " << emp_avg;
    
}

int main() {
    int size = 50;
    Employee employee[size];
    int numOfEmp;

    cout << "\n\t-----Employee Ratings-----\n";

    cout << "\n--Enter the number of employees : ";     // Prompt the user to enter the number of employees
    cin >> numOfEmp;

    size = numOfEmp - 1;

    employee[size];

    // Loop to take input from the user
    for (int i = 0; i < numOfEmp; i++) {
        cout << "\n\t-----Employee " << i + 1 << "-----\n";
        
        cout << "Name: ";
        cin >> employee[i].name;
        
        cout << "Communication rating : ";
        cin >> employee[i].rateCommunication;
        
        cout << "Teamwork rating : ";
        cin >> employee[i].rateTeamwork;
        
        cout << "Problem Solving rating : ";
        cin >> employee[i].rateProblemSolving;
    }

    // Display initial employee data
    display_data(employee, numOfEmp);

     // Change ratings for an employee
    int employeeIndex;
    cout << "\nEnter the employee number (1-" << numOfEmp << ") to update ratings: ";
    cin >> employeeIndex;

    if (employeeIndex > numOfEmp) {
        cout << "\nError! Employee Not Found.\n";
    }

    else {
        // Update ratings
        change_ratings(employeeIndex, employee);\

        // Calculate average
        calc_average_rating(employeeIndex, employee);
    }

    return 0;
}