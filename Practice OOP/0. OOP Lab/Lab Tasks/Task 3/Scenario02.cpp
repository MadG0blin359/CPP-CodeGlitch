#include <iostream>
using namespace std;

// Function prototype
void subTotal(float arr[], int size);

int main() {

    const int size = 5;         // Array size
    float arr[size] = {5.8, 2.6, 9.1, 3.4, 7.0};    // Array elements to test the program logic

    cout << "\n\t-----Replacing All The Array Elements With Their Sum-----\n";

    // Calling the to function
    subTotal(arr, size);

    return 0;
}

// Function to replace and add all elements 
void subTotal(float arr[], int size) {

    cout << endl;
    // Loop to add all the next elements
    for (int i = 0; i < size; i++) {
        arr[i+1] += arr[i];
        cout << arr[i] << " ";
    }    

    cout << endl;

}