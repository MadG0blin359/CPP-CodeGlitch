#include <iostream>
using namespace std;

void Search(int* arr, int size, int valueToFind) {
    bool found = false; // Flag to indicate if the value is found
    for (int i = 0; i < size; i++) { // Loop through the array
        if (*(arr + i) == valueToFind) { // Check if the current element matches the value
            found = true; // Set the flag to true if value is found
            break; // Exit the loop once the value is found
        }
    }

    if (found) { // Check the flag after the loop
        cout << "Value exists in the array." << endl; // Print message if value is found
    }
    else {
        cout << "Value does not exist in the array." << endl; // Print message if value is not found
    }
}

int main() {
    int size, valueToFind; 
    cout << "Enter the size of the array: "; // Prompt user to input the size of the array
    cin >> size; // Read the size of the array

    int* arr = new int[size]; // Dynamically allocate memory for the array

    cout << "Enter " << size << " integer values for the array:" << endl; // Prompt user to input array elements
    for (int i = 0; i < size; i++) {
        cin >> *(arr + i); // Populate the array using pointer arithmetic
    }

    cout << "Enter the value to find: "; // Prompt user to input the value to search for
    cin >> valueToFind; // Read the value to search for

    Search(arr, size, valueToFind); // Call the function to search for the value

    delete[] arr; // Deallocate the dynamically allocated memory
    system("pause"); 
    return 0; 
}
