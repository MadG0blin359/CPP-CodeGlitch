#include <iostream>
using namespace std;

int main() {
    int numProcesses = 3;
    int totalResources = 24;
    
    int allocated[] = {10, 5, 4};
    int maxNeed[] = {20, 8, 18};
    int need[numProcesses];
    int available = totalResources;

    for (int i = 0; i < numProcesses; i++) {
        need[i] = maxNeed[i] - allocated[i];
        available -= allocated[i];
    }

    bool finished[numProcesses] = {false};	// Bankers Algorithm Check for a safe sequence
    int safeSequence[numProcesses];
    int count = 0;

    while (count < numProcesses) {
        bool found = false;
        for (int i = 0; i < numProcesses; i++) {
            if (!finished[i] && need[i] <= available) {
                // Process can proceed
                available += allocated[i];
                finished[i] = true;
                safeSequence[count++] = i;
                found = true;
            }
        }
        if (!found) {
            cout << "System is in an \"UNSAFE\" state! Deadlock possible." << endl;
            return 1;
        }
    }

    // onlyIf a safe sequence exists
    cout << "System is in a \"SAFE\" state. Safe sequence: ";
    for (int i = 0; i < numProcesses; i++)
        cout << "P" << safeSequence[i] << " ";
    cout << endl;

    return 0;
}
