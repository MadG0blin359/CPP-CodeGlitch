#include <iostream>
using namespace std;

int calculateFactorial(int);

int main() {

    int num;

    cout << "\n\t-----Calculate Factorial Of A Number-----\n\n";

    do {
        cout << "Enter a Positive Integer : ";
        cin >> num;

        if (num < 1) {
            cout << "\nInvlaid Input! Enter a positive integer.\n\n";
        }
    }

    while (num < 1);

    cout << "The factorial of " << num << " is : " << calculateFactorial(num);

    return 0;
}

int calculateFactorial(int num) {
    static int fact = num; 
    --num;
    fact *= num;
    
    if (num == 1) {
        return fact;
    }

    else {
        calculateFactorial(num);
    }
}