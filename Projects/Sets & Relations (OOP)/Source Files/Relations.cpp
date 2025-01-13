#include <iostream>
#include "Relations.h"
using namespace std;

// Constructor
Relations::Relations() : relation(nullptr), size(0) {}

// Function to input relations
void Relations::inputRelation() {
    if (relation != nullptr) {
        // Free previously allocated memory
        for (int i = 0; i < size; i++)
            delete[] relation[i];
        delete[] relation;
    }

    do {
        cout << "Enter the number of pairs in the relation: ";
        cin >> size;

        if (size < 1)
            cout << "\n-----Invalid Input! Number of pairs must be greater than 0.-----\n";

    } while (size < 1);

    // Allocate memory for relations
    relation = new int* [size];
    for (int i = 0; i < size; i++)
        relation[i] = new int[2];

    // Input relation pairs
    cout << "Enter pairs (a, b) in the relation:\n";
    for (int i = 0; i < size; i++) {
        cin >> relation[i][0] >> relation[i][1];
    }
}

// Function to check Reflexive Relation
void Relations::checkReflexive() {
    if (relation == nullptr) {
        cout << "\n-----Relation is Empty! Input Relation First.-----\n";
        return;
    }

    // Extract unique elements
    int* elements = new int[size * 2];
    int elementCount = 0;

    for (int i = 0; i < size; i++) {
        bool foundA = false, foundB = false;

        // Add unique elements from pairs
        for (int j = 0; j < elementCount; j++) {
            if (relation[i][0] == elements[j])
                foundA = true;
            if (relation[i][1] == elements[j])
                foundB = true;
        }
        if (!foundA) elements[elementCount++] = relation[i][0];
        if (!foundB) elements[elementCount++] = relation[i][1];
    }

    // Check reflexivity for each element
    for (int i = 0; i < elementCount; i++) {
        bool reflexive = false;
        for (int j = 0; j < size; j++) {
            if (relation[j][0] == elements[i] && relation[j][1] == elements[i]) {
                reflexive = true;
                break;
            }
        }
        if (!reflexive) {
            cout << "\nRelation is not Reflexive.\n";
            delete[] elements;
            return;
        }
    }

    cout << "\nRelation is Reflexive.\n";
    delete[] elements;
}

// Function to check Symmetric Relation
void Relations::checkSymmetric() {
    if (relation == nullptr) {
        cout << "\n-----Relation is Empty! Input Relation First.-----\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        int a = relation[i][0], b = relation[i][1];
        bool symmetric = (a == b); // Reflexive pairs are inherently symmetric

        for (int j = 0; j < size; j++) {
            if (relation[j][0] == b && relation[j][1] == a) {
                symmetric = true;
                break;
            }
        }

        if (!symmetric) {
            cout << "\nRelation is not Symmetric.\n";
            return;
        }
    }

    cout << "\nRelation is Symmetric.\n";
}

// Function to check Anti-Symmetric Relation
void Relations::checkAntiSymmetric() {
    if (relation == nullptr) {
        cout << "\n-----Relation is Empty! Input Relation First.-----\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        int a = relation[i][0], b = relation[i][1];
        if (a != b) { // Skip reflexive pairs
            for (int j = 0; j < size; j++) {
                if (relation[j][0] == b && relation[j][1] == a) {
                    cout << "\nRelation is not Anti-Symmetric.\n";
                    return;
                }
            }
        }
    }

    cout << "\nRelation is Anti-Symmetric.\n";
}

// Destructor to free memory
Relations::~Relations() {
    if (relation != nullptr) {
        for (int i = 0; i < size; i++)
            delete[] relation[i];
        delete[] relation;
    }
}