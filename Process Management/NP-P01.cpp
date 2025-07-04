#include <iostream> // For input/output operations.
#include <vector>   // For using dynamic arrays (vectors).
using namespace std; // Use standard namespace.

// Function for Non-preemptive Priority (NPP) Scheduling.
void NPP(vector<int> processID, vector<int> arrivalTime, vector<int> burstTime, vector<int> priority) {
    int totalProcess = processID.size(); // Total number of processes.
    vector<int> remainingTime = burstTime; // Remaining execution time (initially full burst time).
    vector<int> completionTime(totalProcess); // Time when each process finishes.
    vector<int> TAT(totalProcess);       // Turnaround time for each process.
    vector<int> WT(totalProcess);        // Waiting time for each process.
    int time = 0;                        // Current time in the simulation.
    int completed = 0;                   // Number of processes completed.

    cout << "Non-preemptive Priority (NP-P) Scheduling :\n"
         << "Gantt Chart: |0\t\t"; // Print NPP header and start Gantt chart.

    // Loop until all processes are completed.
    while (completed < totalProcess) {
        int currentProcess = -1; // Index of the process to be executed next.
        int maxPriority = -1;    // Highest priority found so far among ready processes.

        // Find the process with the highest priority that has arrived and is not yet completed.
        for (int i = 0; i < totalProcess; i++) {
            // Check if process has arrived, is not completed, and has higher priority.
            if (arrivalTime[i] <= time && remainingTime[i] > 0 && priority[i] > maxPriority) {
                maxPriority = priority[i];  // Update max priority.
                currentProcess = i;         // Set this as the next process to execute.
            }
        }

        // If no process is ready to execute, increment time and continue.
        if (currentProcess == -1) {
            time++;
            continue;
        }

        // Execute the chosen process completely (non-preemptive).
        remainingTime[currentProcess] = 0; // Mark remaining time as zero.
        time += burstTime[currentProcess]; // Advance time by its burst time.

        // Calculate and update metrics for the completed process.
        completionTime[currentProcess] = time;              // Record completion time.
        TAT[currentProcess] = completionTime[currentProcess] - arrivalTime[currentProcess]; // Calculate turnaround time.
        WT[currentProcess] = TAT[currentProcess] - burstTime[currentProcess]; // Calculate waiting time.
        completed++;                                        // Increment completed processes count.

        // Add the completed process to the Gantt chart.
        cout << "P" << processID[currentProcess] << "\t|" << time << "\t";
    }

    // Calculate and print average Turnaround Time (TAT) and Waiting Time (WT).
    double AvgTAT = 0, AvgWT = 0;
    for (int i = 0; i < totalProcess; i++) {
        AvgTAT += TAT[i]; // Sum TATs.
        AvgWT += WT[i];   // Sum WTs.
    }
    AvgTAT /= totalProcess; // Calculate average TAT.
    AvgWT /= totalProcess;  // Calculate average WT.

    // Print detailed process information.
    cout << "\n\nProcess\tArrival\tBurst\tPriority\tCompletion\tTAT\tWT\n"
         << "--------------------------------------------------------------------\n";
    for (int i = 0; i < totalProcess; i++) {
        cout << "P" << processID[i] << "\t" << arrivalTime[i] << "\t" << burstTime[i] << "\t" << priority[i] << "\t\t" << completionTime[i]
             << "\t\t" << TAT[i] << "\t" << WT[i] << endl;
    }

    cout << endl;
    cout << "Average TAT : " << AvgTAT << endl; // Print average TAT.
    cout << "Average WT : " << AvgWT << endl;   // Print average WT.
}

int main() {
    // Define process IDs, arrival times, burst times, and priorities.
    vector<int> processID = { 1, 2, 3 },
                arrivalTime = { 0, 0, 0 },
                burstTime = { 24, 3, 3 },
                priority = { 2, 1, 3 }; // Larger priority number implies higher priority.

    NPP(processID, arrivalTime, burstTime, priority); // Call NPP scheduling function.

    system("pause"); // Pause console (Windows-specific).
    return 0;        // Indicate successful execution.
}