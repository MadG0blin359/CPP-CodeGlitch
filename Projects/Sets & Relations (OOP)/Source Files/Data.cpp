#include "Data.h"

// Constructor
Data::Data(int s) {
    size = s;
    if (size > 0)
        data = new int[size];
    else
        data = nullptr;
}

// Copy Constructor
Data::Data(const Data& other) {
    size = other.size;
    if (size > 0) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];  // Deep copy the array
        }
    }
    else {
        data = nullptr;
    }
}

// Assignment Operator Overloading
Data& Data::operator=(const Data& other) {
    if (this != &other) {
        delete[] data;  // Free current memory

        size = other.size;
        if (size > 0) {
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];  // Deep copy the array
            }
        }
        else {
            data = nullptr;
        }
    }
    return *this;
}

// Function to input elements
void Data::inputElements() {
    int element;
    for (int i = 0; i < size; i++) {
        cin >> element;

        if (!isDuplicate(element, i))
            data[i] = element;  // Store only the unique element
        else {
            cout << "Duplicate Element Detected! Please enter a different value: ";
            --i;
        }
    }
}

// Function to check duplicates
bool Data::isDuplicate(const int& element, const int i) {
    for (int j = 0; j <= i; j++) {
        if (data[j] == element) {
            return true;
        }
    }
    return false;
}

// Function to insert an element
void Data::insertElement(const int index, const int value) {
    if (index >= 0 && index < size) {
        data[index] = value;
    }
}

// Function to sort the set using bubble sort
void Data::sortSet(int s) {
    if (s == -1)
        s = size;
    for (int i = 0; i < s - 1; i++) {
        for (int j = 0; j < s - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                // Swap the elements
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

// Function to print data
void Data::printData(int s) const {
    if (s == -1)
        s = size;
    cout << "{";
    if (s > 0) {
        for (int i = 0; i < s; i++) {
            cout << data[i] << ", ";
        }
        cout << "\b\b}";
    }
    else
        cout << "}";
}

// Get element at a specific index
int Data::getElement(int index) const {
    if (index >= 0 && index < size)
        return data[index];
    return -1;
}

// Get the size of the data array
int Data::getSize() const {
    return size;
}

// Check if the set is empty
bool Data::isEmpty() const {
    return (size == 0);
}

// Destructor
Data::~Data() {
    delete[] data;
}