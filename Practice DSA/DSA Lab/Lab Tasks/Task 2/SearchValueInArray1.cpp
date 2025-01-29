#include <iostream>
using namespace std;

int main() {
    int size, valueToFind;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter " << size << " integer values for the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value to find: "; // Prompt user to input the value to search for
    cin >> valueToFind; // Read the value to search for

    bool found = false;
    for (int i = 0; i < size; i++) {       // Loop through the array
        if (arr[i] == valueToFind) {
            found = true;
            break;
        }
    }

     if (found) { // Check the flag after the loop
        cout << "Value exists in the array." << endl; // Value found
    }
    else {
        cout << "Value does not exist in the array." << endl; // Value not found
    }

    delete[] arr;
    system("pause");
    return 0;
}