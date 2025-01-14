#include <iostream>
using namespace std;

int main() {

    int num1;
    int num2;

    cout << "\n";
    cout << "Enter number 1 : ";
    cin >> num1;

    cout << "Enter number 2 : ";
    cin >> num2;

    num2 = num2 + num1;
	num1 = num2 - num1; 
	num2 = num2 - num1; 

    cout << "\n\tAfter Swaping\nThe value of num1 is : " << num1 << "\nThe value of num2 is : " << num2 << endl;

    return 0;
}