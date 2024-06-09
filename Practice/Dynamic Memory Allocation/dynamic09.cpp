#include <iostream>
#include <string>
using namespace std;

int main() {

    int size = 2;
    string **ptr;       // Declaring a pointer to pointer
    ptr = new string*[size];   // Dynamic array of string pointers
    string name = "Test01", name2 = "Test02";   // Sample data

    // ptr[0] = &name;           // Address of name stored in the first element of the array
    *ptr = &name;           // Address of name stored in the first element of the array
    cout << ptr << endl;        // Address of first element in the dynamic array
    cout << *ptr << endl;       // Address of name stored in the first element of the dynamic array
    cout << **ptr << endl;       // Value at address of name
    
    ptr++;      // Increment to 2nd pointer in the array

    *ptr = &name2;          // Store address in the 2nd pointer (second element in the array)
    cout << **ptr << endl;  // Go at the address stored in the second element and print the data

    delete[] ptr;

    /* **ptr = the compiler will first read ptr (address of first element of dynamic array is stored in ptr),
    if we dereference it *ptr, the compiler will go at the first element of array (address of name is stored in the first element),
    then if we derefence it second time **ptr, the compiler will go at the address of name and print the data */ 

    return 0;
}