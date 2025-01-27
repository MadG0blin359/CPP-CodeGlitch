#include <iostream>
using namespace std;

// Function prototye
void eliminateDuplicates(int arr[], int);

int main() {

    int size;

    cout << "\n\t-----Eliminate Duplicates-----\n";

    cout << "\nEnter the number of integers : ";        // Prompt the user to enter the size of the array
    cin >> size;

    int arr[size];          // Declare the array of size

    cout << endl;

    // Loop to take input in the array
    for (int i = 0; i < size; i++) {
        cout << "Enter integer " << i+1 << " : ";
        cin >> arr[i];
    }

    // Calling function to perform the task of elimination
    eliminateDuplicates(arr, size);

    return 0;
}

// Function to eliminate all duplicate integers in the user provided array
void eliminateDuplicates(int arr[], int size) {

    int new_size = 0;

    // Loop to look for duplicates
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            if (i == j) {
                continue;
            }

            if (arr[i] == arr[j]) {
                arr[j] = 0;         // Erasing the duplicates
                arr[j] = arr[j+1];  // Shifting the next cell value to the left 
                arr[j+1] = 0;       // Setting the next cell value to zero
            } 
        }

        // Print the refined array
        cout << arr[i] << " ";

    }

    int i = 0;

    // Loop to count new size
    while (arr[i] != 0) {
        new_size++;
        i++;
    }

    cout << "\nNew Size : " << new_size;

}