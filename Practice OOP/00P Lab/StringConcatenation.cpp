#include <iostream>
#include <string>
using namespace std;

int main() {

    string first_name = "Shawaiz";
    string last_name = "Shahid";

    // String concatenation
    // Method One : concatenate (+) operator
    string full_name = first_name + " " + last_name; // Both are correct = ' ' or " "

    cout << "\nMethod One : \n";
    cout << "Full Name : " << full_name;

    // Method Two : append() function
    first_name.append(last_name);

    cout << "\n\nMethod Two : \nFull Name : " << first_name;
    
    // Access single characters in a string
    cout << "\n\nAccess Single Characters : ";
    cout << "\n" << first_name[0];      // 1st character = 0th position of index in the string
    cout << "\n" << first_name[5];      // 6th character = 5th position of index in the string

    cout << "\n\nLength of the string : " << first_name.length();
    cout << "\nSize of the string : " << first_name.size();

    first_name.clear();     // Clear the string
    first_name.erase();     // Erase the string

    return 0;
}