#include <iostream> // For input/output operations.
#include <vector>   // For using dynamic arrays (vectors).
using namespace std; // Use standard namespace.

// Function for First-Come-First-Serve (FCFS) Scheduling.
void FCFS(vector<int> processID, vector<int> arrivalTime, vector<int> burstTime) {
    int totalProcess = processID.size(); // Total number of processes.
    vector<int> remainingTime = burstTime; // Remaining execution time for each process.
    vector<int> CT(totalProcess, 0);    // Completion time for each process.
    vector<int> TAT(totalProcess, 0);   // Turnaround time for each process.
    vector<int> WT(totalProcess, 0);    // Waiting time for each process.
    int time = 0;                       // Current time in the simulation.
    int completed = 0;                  // Number of processes completed.

    cout << "First-Come-First-Serve (FCFS) Scheduling :\n"
         << "Gantt Chart: 0|\t\t"; // Print FCFS header and start Gantt chart.

    // Loop until all processes are completed.
    while (completed < totalProcess) {
        int index = -1;  // Index of the process to be executed next.
        int minTime = 1000; // Smallest arrival time found so far.

        // Find the process with the earliest arrival time that is ready.
        for (int i = 0; i < totalProcess; i++) {
            if (arrivalTime[i] <= time && remainingTime[i] > 0 && arrivalTime[i] < minTime) {
                index = i;      // Set this as the next process.
                minTime = arrivalTime[i]; // Update minimum arrival time.
            }
        }

        // If no process is ready at the current time, increment time.
        if (index == -1) {
            time++;
            continue;
        }

        // Execute the selected process completely.
        time += remainingTime[index];     // Advance time by process's burst time.
        remainingTime[index] = 0;         // Mark process as finished.

        CT[index] = time;                 // Record completion time.
        TAT[index] = CT[index] - arrivalTime[index]; // Calculate turnaround time.
        WT[index] = TAT[index] - burstTime[index];   // Calculate waiting time.
        completed++;                                  // Increment completed processes count.

        // Add the completed process to the Gantt chart.
        cout << "P" << processID[index] << "\t\t" << CT[index] << "|\t\t";
    }
    cout << endl; // End Gantt chart line.

    // Calculate and print average Turnaround Time (TAT) and Waiting Time (WT).
    double AvgTAT = 0, AvgWT = 0;
    for (int i = 0; i < totalProcess; i++) {
        AvgTAT += TAT[i]; // Sum up TATs.
        AvgWT += WT[i];   // Sum up WTs.
    }
    AvgTAT /= totalProcess; // Calculate average TAT.
    AvgWT /= totalProcess;  // Calculate average WT.

    // Print detailed process information.
    cout << "\n\nProcess\tArrival\tBurst\tCompletion\tTAT\tWT\n"
         << "-------------------------------------------------------------\n";
    for (int i = 0; i < totalProcess; i++) {
        cout << "P" << processID[i] << "\t" << arrivalTime[i] << "\t" << burstTime[i] << "\t\t" << CT[i] // CT, not completionTime
             << "\t" << TAT[i] << "\t" << WT[i] << endl;
    }

    cout << "Average TAT : " << AvgTAT << endl; // Print average TAT.
    cout << "Average WT : " << AvgWT << endl;   // Print average WT.
}

int main() {
    // Define process IDs, arrival times, and burst times.
    vector<int> processID = { 1, 2, 3 },
                arrivalTime = { 0, 0, 0 },
                burstTime = { 24, 3, 3 };

    FCFS(processID, arrivalTime, burstTime); // Call FCFS scheduling function.
    return 0;        // Indicate successful execution.
}