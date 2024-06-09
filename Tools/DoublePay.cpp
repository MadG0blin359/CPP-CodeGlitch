#include <iostream>
using namespace std;

int main() {

    const float value_of_penny = 0.01;
    int num_of_days;
    double sum, salary;

    do {
        cout << "Enter the number of days worked : ";
        cin >> num_of_days;

        if (num_of_days < 1) {
            cout << "\nInvald Input!\n\n";
        }
    }

    while (num_of_days < 1);

    cout << "\n---------------\n";
    cout << "Day\tSalary";
    cout << "\n---------------\n";

    salary = value_of_penny;

    for (int i = 1; i <= num_of_days; i++) {
        
        sum += salary;
        cout << i << "\t $" << salary << "\n";
        salary *= 2;
        
    }

    cout << "---------------\n";
    cout << "Total :  $" << sum;
    cout << "\n---------------\n";

    return 0;
}