#include <iostream>
using namespace std;

double userInput();
void nearestOnesPlace(float);

int main() {

    float num;

    cout << "\n\t*********Decimal Round off Calculator*********";
    cout << "\n\t\t\tNearest Ones\n";      // Round to the Nearest Ones Calculator

    num = userInput();
    nearestOnesPlace(num);

    return 0;
}

double userInput() {
    float num;
    int before_decimal;

    do { 
        cout << "\nEnter any decimal number : ";
        cin >> num;

        before_decimal = num;

        if (num - before_decimal == 0) {
            cout << "Error! Please enter a decimal number.\n";
        }
    }

    while (num - before_decimal == 0);

    return num;
}

void nearestOnesPlace(float num) {
    // int verify;
    // if (num < 0) {
    //     num *= -1;
    //     verify++;
    // }

    int before_decimal;
    before_decimal = num;

    if ((num - before_decimal < 0.5 && num - before_decimal > 0) || (num - before_decimal < 0 && num - before_decimal > -0.5)) {
        cout << "Rounded To the nearest whole number : " << before_decimal << endl;
    }

    else if (num - before_decimal == 0.5 || num - before_decimal == -0.5) {
        if (before_decimal %2 == 0) {
            cout << "Rounded To the nearest even number : " << before_decimal << endl;
        }

        else {
            if (num > 0) {
                cout << "Rounded To the nearest even number : " << before_decimal + 1 << endl;
            }

            else {
                cout << "Rounded To the nearest even number : " << before_decimal - 1 << endl;
            }
        }
    }

    else if (num - before_decimal > 0.5 || num - before_decimal < -0.5 ) {
        if (num > 0) {
            cout << "Rounded To the nearest whole number : " << before_decimal + 1 << endl;
        }

        else {
             cout << "Rounded To the nearest whole number : " << before_decimal - 1 << endl;
        }
    }
}