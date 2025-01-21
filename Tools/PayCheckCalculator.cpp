#include <iostream>

using namespace std;

int main() {
    // Declare variables to store user input and calculated data
    float baseSalary, numOfServiceYears, bonus, totalSales, additionalBonus, payCheck;

    cout << "\n\t***********Monthly Pay Check Calculator***********\n";

    cout << "\nEnter The Base Salary : ";       // Prompt the user to enter base salary
    cin >> baseSalary;                          // Read & store user input
    
    cout << "Enter The Number Of Service Years : ";         // Prompt the user to enter number of years worked
    cin >> numOfServiceYears;                                // Read & store user input

    cout << "Enter The Total Sales Made By The Salesperson For The Month : ";       // Prompt the user to enter total sales generated in the month
    cin >> totalSales;                                                              // Read & store user input

    // Determine the number of years
    if (numOfServiceYears >= 0 || numOfServiceYears <= 5) {
        bonus = numOfServiceYears * 10;          // Bonus percentage for less than or equal to 5 years is 10%
    }

    else if (numOfServiceYears > 5) {
        bonus = numOfServiceYears * 20;          // Bonus percentage for more than 5 years is 20%
    }

    // Determine total sales generated in the month
    if (totalSales >= 5000 && totalSales < 10000) {
        additionalBonus = totalSales * 0.03;            // Additional bonus percentage for total sales of more than $5,000 and but less than $10,000 is 3%  
    }

    else if (totalSales >= 10000) {
        additionalBonus = totalSales * 0.06;            // Additional bonus percentage for total sales of more than $10,000 is 6%
    }

    // Calculate final paycheck
    payCheck = baseSalary + bonus + additionalBonus;

    // Display the calculated results
    cout << "\nBonus : " << bonus << "\nAdditional Bonus : " << additionalBonus;
    cout << "\nPaycheck : " << payCheck << endl;

    return 0;
}