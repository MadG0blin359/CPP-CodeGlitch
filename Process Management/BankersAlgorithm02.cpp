#include <iostream>
using namespace std;

const int numProcesses = 5; // P0 to P4
const int numResources = 3; // A, B, C

// Given resources and process data
int available[numResources] = {3, 3, 2};
int maxNeed[numProcesses][numResources] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
};
int allocation[numProcesses][numResources] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};

// Function to check for a safe sequence
bool bankersAlgorithm() {
    int need[numProcesses][numResources];
    bool finished[numProcesses] = {false};
    int safeSequence[numProcesses];
    int count = 0;

    // Compute need matrix
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            need[i][j] = maxNeed[i][j] - allocation[i][j];
        }
    }

    // sequence check
    while (count < numProcesses) {
        bool found = false;
        for (int i = 0; i < numProcesses; i++) {
            if (!finished[i]) {
                bool canExecute = true;
                for (int j = 0; j < numResources; j++) {
                    if (need[i][j] > available[j]) {
                        canExecute = false;
                        break;
                    }
                }
                if (canExecute) {
                    for (int j = 0; j < numResources; j++) {
                        available[j] += allocation[i][j]; // Release resources
                    }
                    safeSequence[count++] = i;
                    finished[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "System is in an \"UNSAFE\" state! Deadlock is possible." << endl;
            return false;
        }
    }

    // If a safe sequence is found
    cout << "System is in a \"SAFE\" state." << endl;
    cout << "Execution Sequence: ";
    for (int i = 0; i < numProcesses; i++)
        cout << "P" << safeSequence[i] << " ";
    cout << endl;

    return true;
}

int main() {
    bankersAlgorithm();
    return 0;
}
