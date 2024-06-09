#include <iostream>
using namespace std;

const int size = 9;
// Function prototype
int mostOccurringNum(int[]);

int main() {
    const int numOfMaximums = 3;
    int arr[size] = {2,3,4,2,6,4,1,2,1};
    int largestNum[numOfMaximums];

    // Initializing largestNum to zero to avoid garbage values
    for (int i = 0; i < numOfMaximums; i++) {
        largestNum[i] = 0;
    }

    largestNum[0] = arr[0];

    cout << "\nThree Largest Numbers in the Array are : ";

    // Nested loop to find 3 largest numbers in the array
    for (int i = 0; i < numOfMaximums; i++) {
        for (int j = 0; j < size; j++) {
            if (largestNum[i] < arr[j]) {
                int duplicate = 0;      // Reset the variable to zero for each iteration
                for (int k = 0; k < i; k++) {
                    if (largestNum[k] == arr[j]) {      // Mark the repeated element to avoid counting it again
                        duplicate++;
                        break;
                    }
                }

                if (duplicate == 0) {
                    largestNum[i] = arr[j];
                }
            }
        }

        cout << largestNum[i] << " ";

    }
    
    int duplicateNum;

    // Call the function to get the most occurring number in the array
    duplicateNum = mostOccurringNum(arr);

    cout << "\nMost Occuring Number in the array is : " << duplicateNum;

    return 0;
}

// Function to find a number with a max frquency of occurence
int mostOccurringNum(int arr[]) {

    int currentNum = 0, maxFrequency = 0;

    for (int i = 0; i < size; i++) {
        int currentFrequency = 0;
        for (int j = 0; j < size; j++) {

            if (arr[i] == arr[j]) {
                currentFrequency++;
            }
        }

        if (currentFrequency > maxFrequency) {
            maxFrequency = currentFrequency;
            currentNum = arr[i];
        }
    }

    return currentNum;
}