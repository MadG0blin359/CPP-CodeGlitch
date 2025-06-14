#include <iostream>
#include <limits>

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double getNumber(const string& prompt) {
    double num;
    while (true) {
        cout << prompt;
        cin >> num;
        if (cin.fail()) {
            cout << "Invalid input! Please enter a number.\n";
            clearInputBuffer();
        } else {
            clearInputBuffer();
            return num;
        }
    }
}

void performOperation(char operation) {
    double num1 = getNumber("Enter first number: ");
    double num2 = getNumber("Enter second number: ");

    switch(operation) {
        case '+':
            cout << "Result: " << num1 << " + " << num2 << " = " << num1 + num2 << "\n\n";
            break;
        case '-':
            cout << "Result: " << num1 << " - " << num2 << " = " << num1 - num2 << "\n\n";
            break;
        case '*':
            cout << "Result: " << num1 << " * " << num2 << " = " << num1 * num2 << "\n\n";
            break;
        case '/':
            if (num2 != 0) {
                cout << "Result: " << num1 << " / " << num2 << " = " << num1 / num2 << "\n\n";
            } else {
                cout << "Error! Division by zero is not allowed.\n\n";
            }
            break;
    }
}

int main() {
    char choice;
    
    cout << "=== CyberOS Calculator ===\n";
    
    do {
        cout << "Choose operation:\n"
             << "1. Addition (+)\n"
             << "2. Subtraction (-)\n"
             << "3. Multiplication (*)\n"
             << "4. Division (/)\n"
             << "5. Exit\n"
             << "Enter choice (1-5): ";

        cin >> choice;
        clearInputBuffer();

        switch(choice) {
            case '1':
                performOperation('+');
                break;
            case '2':
                performOperation('-');
                break;
            case '3':
                performOperation('*');
                break;
            case '4':
                performOperation('/');
                break;
            case '5':
                cout << "Exiting calculator...\n";
                break;
            default:
                cout << "Invalid choice! Please enter 1-5.\n\n";
        }
    } while (choice != '5');

    return 0;
}
