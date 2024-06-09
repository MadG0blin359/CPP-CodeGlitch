#include <iostream>
#include <climits>
using namespace std;

int main() {

    int choice;
    float num1, num2;

    cout << "\n\t\t********Arithmetic Operations********\n\n";

    do { 
        cout << "\tMenu\n";
        cout << "1. Division\n";
        cout << "2. Multiplication\n";
        cout << "3. Addition\n";
        cout << "4. Subtraction\n";
        cout << "\nEnter your choice : ";
        cin >> choice;

        if (choice < 1 || choice > 4) {
            cout << "\n***Invalid Input!***\n\n";
        }
    }

    while (choice < 1 || choice > 4);

    cout << "\nEnter first number : ";
    cin >> num1;
    cout << "Enter second number : ";
    cin >> num2;

    switch (choice) {
    case 1:
        cout << "\n" << num1 << " Divided by " << num2 << " : " << num1/num2;
        break;

    case 2:
        cout << "\n" << num1 << " Multiplied by " << num2 << " : " << num1*num2;
        break;

    case 3:
        cout << "\n" << num1 << "Added with " << num2 << " : " << num1+num2;
        break;

    case 4:
        cout << "\n" << num2 << " Subtracted from " << num1 << " : " << num1-num2;
        break; 
    }

    return 0;
}