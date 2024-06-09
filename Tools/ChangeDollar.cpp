// Penny - 1 cent
// Nickel - 5 cents
// Dime - 10 cents
// Quarter - 25 cents

#include <iostream>
using namespace std;

int main() {

    int num_of_penny, num_of_nickel, num_of_dime, num_of_quarter;
    const float value_of_penny = 0.01, value_of_nickel = 0.05, value_of_dime = 0.10, value_of_quarter = 0.25;
    float sum;

    cout << "\n\t\t******Change for a Dollar Game******\n";
    
    cout << "\nNote : Enter the number of coins required to make exactly one dollar (100 cents).\n";
    cout << "\nThe value of each coin is : \nPenny = " << value_of_penny << " cents" << "\nNickel = " << value_of_nickel << " cents" << "\nDime = " << value_of_dime << " cents" << "\nQuarter = " << value_of_quarter << " cents\n\n";

    cout << "Pennie(s) : ";
    cin >> num_of_penny;

    cout << "Nickel(s) : ";
    cin >> num_of_nickel;

    cout << "Dime(s) : ";
    cin >> num_of_dime;

    cout << "Quarter(s) : ";
    cin >> num_of_quarter;

    sum = (num_of_penny * value_of_penny) + (num_of_nickel * value_of_nickel) + (num_of_dime * value_of_dime) + (num_of_quarter * value_of_quarter);

    if (sum == 1) {
        cout << "\nYou are absolutely correct!\n" << num_of_penny << " Pennie(s) + " << num_of_nickel << " Nickel(s) + "  << num_of_dime << " Dime(s) + "  << num_of_quarter << " Quarter(s) : makes exactly One dollar or a 100 cents.";
    }

    else {
        cout << "\nTotal : " << sum << " cents";
        cout << "\nSorry! Better luch next time.";
    }

    return 0;
}