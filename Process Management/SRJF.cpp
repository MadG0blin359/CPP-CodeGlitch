#include <iostream> // For input/output operations (cout)
#include <vector>   // For using std::vector
#include <limits>   // For std::numeric_limits, specifically INT_MAX
#include <algorithm> // For std::min (though not directly used, good to include for general algorithm use)

// Using standard namespace
using namespace std;

// Function to simulate Shortest-Remaining-Job-First (SRJF) CPU scheduling
void SRJF(vector<int> processID, vector<int> arrivalTime, vector<int> burstTime) {
    int totalProcess = processID.size(); // Total number of processes
    // Vectors to store remaining time, completion time, turn-around time (TAT), and waiting time (WT)
    vector<int> remainingTime = burstTime; 
    vector<int> completionTime(totalProcess, 0); 
    vector<int> TAT(totalProcess, 0); 
    vector<int> WT(totalProcess, 0);
    
    int time = 0;     // Current time in the simulation
    int completed = 0; // Number of processes completed

    // Print header for Gantt Chart
    cout << "Shortest-Remaining-Job-First (SRJF) Scheduling :\n"
         << "Gantt Chart: |0\t\t";

    // Loop until all processes are completed
    while (completed < totalProcess) {
        int index = -1; // Index of the process to execute next
        int minProcessTime = numeric_limits<int>::max(); // Stores minimum burst time found

        // Find the process with the shortest remaining burst time that has arrived
        for (int i = 0; i < totalProcess; i++) {
            // Check if process has arrived, has remaining time, and its burst time is currently shortest
            if (arrivalTime[i] <= time && remainingTime[i] > 0 && remainingTime[i] < minProcessTime) {
                index = i;
                minProcessTime = remainingTime[i]; // Correctly use remainingTime for SRJF comparison
            }
        }
        
        // If no process is ready, increment time and continue
        if (index == -1) {
            time++;
            cout << "IDLE\t|" << time << "\t"; // Show idle time in Gantt chart
            continue;
        }

        remainingTime[index]--; // Decrement remaining time of selected process
        time++;                 // Increment current time

        // If process has completed execution
        if (remainingTime[index] == 0) {
            completionTime[index] = time; // Set completion time
            TAT[index] = completionTime[index] - arrivalTime[index]; // Calculate Turn-Around Time
            WT[index] = TAT[index] - burstTime[index]; // Calculate Waiting Time
            completed++; // Increment completed process count
            // Add the current process to the Gantt chart
            cout << "P" << processID[index] << "\t|" << time << "\t";
        } else {
            // If the process is not yet completed, but was executed, show its presence in Gantt
            // This part is crucial for showing preemption correctly if needed,
            // but for a simple single-unit time step decrement, the above if block covers it.
            // If showing every time slice for the active process is desired:
            // cout << "P" << processID[index] << "\t|" << time << "\t";
        }
    }

    // Calculate average TAT and WT
    double AvgTAT = 0, AvgWT = 0;
    for (int i = 0; i < totalProcess; i++) {
        AvgTAT += TAT[i];
        AvgWT += WT[i];
    }
    AvgTAT /= totalProcess; // Calculate average Turn-Around Time
    AvgWT /= totalProcess;   // Calculate average Waiting Time

    // Print process details table
    cout << "\n\nProcess\tArrival\tBurst\tCompletion\tTAT\tWT\n"
         << "-------------------------------------------------------------\n";
    for (int i = 0; i < totalProcess; i++) {
        cout << "P" << processID[i] << "\t" << arrivalTime[i] << "\t" << burstTime[i] << "\t\t" << completionTime[i]
             << "\t" << TAT[i] << "\t" << WT[i] << endl;
    }

    // Print average metrics
    cout << "Average TAT : " << AvgTAT << endl;
    cout << "Average WT : " << AvgWT << endl;
}

// Main function to define processes and call SRJF
int main() {
    // Process IDs
    vector<int> processID = { 1, 2, 3, 4 };
    // Process arrival times
    vector<int> arrivalTime = { 0, 1, 2, 3 };
    // Process burst times
    vector<int> burstTime = { 8, 4, 9, 5 };

    // Call SRJF scheduling function
    SRJF(processID, arrivalTime, burstTime);

    // system("pause"); // For Windows compatibility, typically not used in Linux/macOS
    return 0; // Program exit
}