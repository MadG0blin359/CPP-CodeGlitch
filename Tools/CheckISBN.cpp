#include <iostream>
using namespace std;

int main() {
    const int digits = 10;
    char ISBN[digits];
    int weight = digits, weight_sum = 0;     // Weight of each digit

    cout << "\n\t*****Validate ISBN*****\n";

    cout << "\n--Enter the 10-digit ISBN (Without Dashes) : ";

    for (int i = 0; i < digits; i++) {
        cin >> ISBN[i];
        weight_sum += ISBN[i] * weight;
        weight--;
    }

    if (weight_sum %11 == 0)
        cout << "\n-----The provided ISBN is VALID-----";

    else
        cout << "\n-----The provided ISBN is Invalid!-----\n";

    return 0;
}