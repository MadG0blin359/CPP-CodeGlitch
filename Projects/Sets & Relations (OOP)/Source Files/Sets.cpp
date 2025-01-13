#include <iostream>
#include <cmath>
#include "Data.h"
#include "Sets.h"
using namespace std;

// Function to create sets A & B
void Sets::createSet(const char& name) {
    int n;
    do {
        cout << "\nNumber of elements in Set " << name << ": ";
        cin >> n;

        if (n <= 3)
            cout << "\n-----Invalid Input! Number of Elements Must Be Greater Than \"3\"-----\n";

    } while (n <= 3);

    cout << "Enter elements of Set " << name << ": ";

    if (name == 'A') {
        A = Data(n);
        A.inputElements();
    }
    else if (name == 'B') {
        B = Data(n);
        B.inputElements();
    }
}

// Function to display set elements
bool Sets::printSets() {
    if (A.isEmpty() && B.isEmpty())
        return false;

    cout << "Set A = ";
    A.printData();
    cout << "\nSet B = ";
    B.printData();

    return true;
}

// Function to get the union of sets
bool Sets::getUnion() {
    if (A.isEmpty() && B.isEmpty())
        return false;

    int newSize = A.getSize() + B.getSize();
    Data unionSet(newSize);

    int index = 0;

    // Insert elements of set A
    for (int i = 0; i < A.getSize(); i++) {
        if (!unionSet.isDuplicate(A.getElement(i), index)) {
            unionSet.insertElement(index, A.getElement(i));
            index++;
        }
    }

    // Insert elements of set B
    for (int i = 0; i < B.getSize(); i++) {
        if (!unionSet.isDuplicate(B.getElement(i), index)) {
            unionSet.insertElement(index, B.getElement(i));
            index++;
        }
    }

    cout << "\nUnion A U B = ";
    unionSet.sortSet(index);
    unionSet.printData(index);

    return true;
}

// Function to get the intersection of sets
bool Sets::getIntersection() {
    if (A.isEmpty() && B.isEmpty())
        return false;

    int newSize = A.getSize();
    Data intersectionSet(newSize);

    int index = 0;

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            if (A.getElement(i) == B.getElement(j)) {
                intersectionSet.insertElement(index, A.getElement(i));
                index++;
                break;
            }
        }
    }

    cout << "\nIntersection A n B = ";
    intersectionSet.sortSet(index);
    intersectionSet.printData(index);

    return true;
}

// Function to get the difference of sets
bool Sets::getDifference(const bool flag) {
    if (A.isEmpty() && B.isEmpty())
        return false;

    if (flag) {
        cout << "\nDifference A - B = ";
        getDifference(A, B);
    }
    else {
        cout << "\nDifference B - A = ";
        getDifference(B, A);
    }

    return true;
}

// Helper function to calculate the difference of two sets
void Sets::getDifference(const Data& set1, const Data& set2) {
    int newSize = set1.getSize();
    Data differenceSet(newSize);

    int index = 0;

    for (int i = 0; i < set1.getSize(); i++) {
        bool flag = false;
        for (int j = 0; j < set2.getSize(); j++) {
            if (set1.getElement(i) == set2.getElement(j)) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            differenceSet.insertElement(index, set1.getElement(i));
            index++;
        }
    }

    differenceSet.sortSet(index);
    differenceSet.printData(index);
}

// Function to calculate the total number of relations between sets A and B
bool Sets::getNumberOfRelations() {
    if (A.isEmpty() && B.isEmpty())
        return false;

    int relations = A.getSize() * B.getSize();
    relations = pow(2, relations);
    cout << "\nTotal number of relations: " << relations << endl;

    return true;
}