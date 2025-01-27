#include <iostream>
using namespace std;

void inputValues(int* arr, int size) {
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void removeDuplicates(int* arr, int& size) {
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        bool duplicate = false;
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == arr[j]) {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            arr[newSize++] = arr[i];
        }
    }
    size = newSize;
}

void findCommonElements(int* arr1, int size1, int* arr2, int size2, int* arr3, int& size3) {
    size3 = 0;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                bool isDuplicate = false;
                for (int k = 0; k < size3; k++) {
                    if (arr3[k] == arr1[i]) {
                        isDuplicate = true;
                        break;
                    }
                }
                if (!isDuplicate) {
                    arr3[size3++] = arr1[i];
                }
            }
        }
    }
}

void printArray(int* arr, int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size1, size2, size3;

    cout << "Enter the size of the first array: ";
    cin >> size1;


    int* array1 = new int[size1];
    inputValues(array1, size1);

    cout << "Enter the size of the second array: ";
    cin >> size2;
    int* array2 = new int[size2];
    inputValues(array2, size2);

    removeDuplicates(array1, size1);
    removeDuplicates(array2, size2);

    int* array3 = new int[size1 + size2]; // Max size of common elements

    findCommonElements(array1, size1, array2, size2, array3, size3);

    cout << "Common elements: ";
    printArray(array3, size3);

    delete[] array1;
    delete[] array2;
    delete[] array3;
    system("pause");
    return 0;
}