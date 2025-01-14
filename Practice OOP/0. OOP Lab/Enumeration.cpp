#include <iostream>
using namespace std;

// Enumeration
// Default - 0       1        2        3          4       5         6
enum week {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday}; // Counting list - starts with zero like an array

// Changing the default value
enum num{a = 5, b = 4, c = 2};      // Enum works with only integer

// Another method for changing the default values
enum suit {
    club = 0,
    diamonds = 10,
    hearts = 20,
    spades = 3
} card;     // variable of type suit, pre declared outside main

int main() {

    week today;
    today = Sunday;
    cout << "\n--Day " << today+1;  // Outputs 1

    num choice;
    choice = a;
    cout << "\n--Choice : " << choice;     // Outputs 5

    card = diamonds;
    cout << "\n--Card Type : " << diamonds;     // Outputs 10

    return 0;
}