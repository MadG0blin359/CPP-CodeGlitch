#include <iostream>
#include <vector>
using namespace std;

// Function for Non-Preemptive Shortest-Job-First Scheduling
void SJF(vector<int> processID, vector<int> arrivalTime, vector<int> burstTime) {
	int totalProcess = processID.size();
	vector<int> remainingTime = burstTime, completionTime(totalProcess), TAT(totalProcess), WT(totalProcess);
	int time = 0, completed = 0;

	cout << "Non-Preemptive Shortest-Job-First (NP-SJF) Scheduling :\n"
		<< "Gantt Chart: |0\t\t";

	// Loop until all processes are completed
	while (completed < totalProcess) {
		int currentProcess = -1;
		int minProcessTime = INT_MAX;

		// Find the process with the shortest burst time that is ready
		for (int i = 0; i < totalProcess; i++) {
			if (arrivalTime[i] <= time && remainingTime[i] > 0 && burstTime[i] < minProcessTime) {
				minProcessTime = burstTime[i];
				currentProcess = i;
			}
		}
		
		// If no process is ready, increment time and continue
		if (currentProcess == -1) {
			time++;
			continue;
		}

		// Process the current process
		remainingTime[currentProcess] -= burstTime[currentProcess];
		time += burstTime[currentProcess];

		// Update completion, TAT (Turn Around Time), and WT (Waiting Time) for the current process
		completionTime[currentProcess] = time;
		TAT[currentProcess] = completionTime[currentProcess] - arrivalTime[currentProcess];
		WT[currentProcess] = TAT[currentProcess] - burstTime[currentProcess];
		completed++;
		// Add the current process to the Gantt chart
		cout << "P" << processID[currentProcess] << "\t|" << time << "\t";
	}

	// Calculate average TAT and WT
	double AvgTAT = 0, AvgWT = 0;
	for (int i = 0; i < totalProcess; i++) {
		AvgTAT += TAT[i];
		AvgWT += WT[i];
	}
	AvgTAT /= totalProcess;
	AvgWT /= totalProcess;

	cout << "\n\nProcess\tArrival\tBurst\tCompletion\tTAT\tWT\n"
		<< "-------------------------------------------------------------\n";
	for (int i = 0; i < totalProcess; i++) {
		cout << "P" << processID[i] << "\t" << arrivalTime[i] << "\t" << burstTime[i] << "\t\t" << completionTime[i]
			<< "\t" << TAT[i] << "\t" << WT[i] << endl;
	}

	cout << "Average TAT : " << AvgTAT << endl;
	cout << "Average WT : " << AvgWT << endl;
}

int main() {
	vector<int> processID = { 1, 2, 3 },
		arrivalTime = { 0, 0, 0 },
		burstTime = { 24, 3, 3 };

	SJF(processID, arrivalTime, burstTime);

	system("pause");
	return 0;
}