#include <iostream>
#include <vector>
using namespace std;

// Function for Non-preemptive Priority Scheduling
void NPP(vector<int> processID, vector<int> arrivalTime, vector<int> burstTime, vector<int> priority) {
	int totalProcess = processID.size();
	vector<int> remainingTime = burstTime, completionTime(totalProcess), TAT(totalProcess), WT(totalProcess);
	int time = 0, completed = 0;

	cout << "Non-preemptive Priority (NP-P) Scheduling :\n"
		<< "Gantt Chart: |0\t\t";

	// Loop until all processes are completed
	while (completed < totalProcess) {
		int currentProcess = -1;
		int maxPriority = -1;
		
		// Find the process with the highest priority that is ready
		for (int i = 0; i < totalProcess; i++) {	// Larger priority numeber implies high priority
			if (arrivalTime[i] <= time && remainingTime[i] > 0 && priority[i] > maxPriority) {
				maxPriority = priority[i];
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

	cout << "\n\nProcess\tArrival\tBurst\tPriority\tCompletion\tTAT\tWT\n"
		<< "--------------------------------------------------------------------\n";
	for (int i = 0; i < totalProcess; i++) {
		cout << "P" << processID[i] << "\t" << arrivalTime[i] << "\t" << burstTime[i] << "\t" << priority[i] << "\t\t" << completionTime[i]
			<< "\t\t" << TAT[i] << "\t" << WT[i] << endl;
	}

	cout << endl;
	cout << "Average TAT : " << AvgTAT << endl;
	cout << "Average WT : " << AvgWT << endl;
}

int main() {
	vector<int> processID = { 1, 2, 3 },
		arrivalTime = { 0, 0, 0 },
		burstTime = { 24, 3, 3 },
		priority = { 2, 1, 3 };

	NPP(processID, arrivalTime, burstTime, priority);

	system("pause");
	return 0;
}