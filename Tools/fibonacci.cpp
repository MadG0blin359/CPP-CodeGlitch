#include <iostream>
using namespace std;

void calculateFibonacci(long end_term, long start_term = 1) {

    long num1 = 0, num2 = 1, term_value = 0;

    cout << "\n-----------\t--------";
    cout << "\nCalculation\tSequence";
    cout << "\n-----------\t--------";

    for (long i = 1; i <= end_term; i++) {
        term_value = num1 + num2;
        if (i >= start_term)
            cout << "\n" << num1 << " + " << num2 << " = " << term_value << "\t --> " << num1;
        num1 = num2;
        num2 = term_value;
    }
}

int main() {

    char menu_choice;
    long start_term, end_term;

    cout << "\n\t*****Fibonacci Series Calculator*****\n";

    cout << "\n-----Menu-----";
    cout << "\n1. Start Term & End Term";
    cout << "\n2. End Term";
    cout << "\n--Select : ";
    cin >> menu_choice;

    switch (menu_choice) {
        case '1':
            cout << "\n--Enter the Start Term : ";
            cin >> start_term;

            cout << "--Enter the End Term : ";
            cin >> end_term;

            calculateFibonacci(end_term, start_term);
            break;
        case '2':
            cout << "\n--Enter the End Term : ";
            cin >> end_term;
            calculateFibonacci(end_term);
            break;
        
        default:
            cout << "\n-----Invalid Input!-----\n";
            break;
    }

    return 0;
}