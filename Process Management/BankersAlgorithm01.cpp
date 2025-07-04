#include <iostream> // For input/output operations (cout, endl).
using namespace std; // Use standard namespace to avoid std:: prefix.

int main() {
    const int numProcesses = 3; // Define the number of processes.
    int totalResources = 24;    // Total available resources in the system.

    int allocated[] = {10, 5, 4}; // Resources currently allocated to each process.
    int maxNeed[] = {20, 8, 18};  // Maximum resources each process might need.
    int need[numProcesses];       // Remaining resources each process still needs.
    int available = totalResources; // Resources currently available.

    // Calculate 'need' for each process and update 'available' resources.
    for (int i = 0; i < numProcesses; i++) {
        need[i] = maxNeed[i] - allocated[i]; // Need = Max - Allocated.
        available -= allocated[i];           // Subtract allocated resources from total to get initial available.
    }

    bool finished[numProcesses] = {false}; // Tracks if a process has finished execution.
    int safeSequence[numProcesses];        // Stores the safe sequence of processes.
    int count = 0;                         // Counter for processes in the safe sequence.

    // Banker's Algorithm: Find a safe sequence.
    while (count < numProcesses) {
        bool found = false; // Flag to check if any process can proceed in this iteration.
        for (int i = 0; i < numProcesses; i++) {
            // Check if process 'i' is not finished and its need can be satisfied by available resources.
            if (!finished[i] && need[i] <= available) {
                // Process 'i' can execute.
                available += allocated[i];     // Release resources held by process 'i'.
                finished[i] = true;            // Mark process 'i' as finished.
                safeSequence[count++] = i;     // Add process 'i' to the safe sequence.
                found = true;                  // A process was found that could execute.
            }
        }
        // If no process could proceed in this iteration, the system is in an unsafe state.
        if (!found) {
            cout << "System is in an \"UNSAFE\" state! Deadlock possible." << endl;
            return 1; // Exit with error.
        }
    }

    // If a safe sequence exists, print it.
    cout << "System is in a \"SAFE\" state. Safe sequence: ";
    for (int i = 0; i < numProcesses; i++)
        cout << "P" << safeSequence[i] << " "; // Print process ID in the safe sequence.
    cout << endl;

    return 0; // Indicate successful execution.
}