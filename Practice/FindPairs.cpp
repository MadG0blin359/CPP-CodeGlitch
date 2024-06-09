#include <iostream>
using namespace std;

int main() {

    int user_input, num_of_pairs, count;

    cout << "\n\t**********Find Every Pair a Positive Integer Can Have**********\n\n";

    do {
        cout << "Enter any integer : ";
        cin >> user_input;
        
        if (user_input < 1) {
            cout << "\nInvalid Input!\n\n";
        }
    }

    while (user_input < 1);
    
    do {
        cout << "How many pairs do you want to find : ";
        cin >> num_of_pairs;

        if (num_of_pairs < 1) {
        cout << "\nInvalid Input!\n\n";
        }
    }

    while (num_of_pairs < 1);

    cout << "\nFirst " << num_of_pairs << " Pair(s) :\n";

    for (int i = 0; i <= user_input; i++) {
        for (int j = 0; j <= user_input; j++) {

            if (i + j == user_input) {
                cout << "-- " << i << " + " << j << " = " << i + j << "\n";
                count++;
            }

            if (count == num_of_pairs) {
                break;
            }

        }
        
        if (count == num_of_pairs) {
            break;
        }

    }

    return 0;
}