#include <iostream>
#include <vector>
using namespace std;

// Function for First-Come-First-Serve Scheduling
void FCFS(vector<int> processID, vector<int> arrivalTime, vector<int> burstTime) {
	int totalProcess = processID.size();
	vector<int> remainingTime = burstTime, completionTime(totalProcess), TAT(totalProcess), WT(totalProcess);
	int time = 0, completed = 0;

	cout << "First-Come-First-Serve (FCFS) Scheduling :\n"
		<< "Gantt Chart: |0\t\t";
	
	// Loop until all processes are completed
	while (completed < totalProcess) {
		int first = -1;
		int minTime = 1000;

		// Find the process with the earliest arrival time that is ready
		for (int i = 0; i < totalProcess; i++) {
			if (arrivalTime[i] <= time && remainingTime[i] > 0 && arrivalTime[i] < minTime) {
				minTime = arrivalTime[i];
				first = i;
			}
		}

		// If no process is ready, increment time and continue
		if (first == -1) {
			time++;
			continue;
		}

		// Process the current process
		remainingTime[first]--;
		time++;

		// Update completion, TAT (Turn Around Time), and WT (Waiting Time) for the current process if completed
		if (remainingTime[first] == 0) {
			completionTime[first] = time;
			TAT[first] = completionTime[first] - arrivalTime[first];
			WT[first] = TAT[first] - burstTime[first];
			completed++;

			// Add the current process to the Gantt chart
			cout << "P" << processID[first] << "\t|" << time << "\t";
		}
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
		<< "------------------------------------------------------\n";
	for (int i = 0; i < totalProcess; i++) {
		cout << "P" << processID[i] << "\t" << arrivalTime[i] << "\t" << burstTime[i] << "\t\t" << completionTime[i]
			<< "\t" << TAT[i] << "\t" << WT[i] << endl;
	}

	cout << endl;
	cout << "Average TAT : " << AvgTAT << endl;
	cout << "Average WT : " << AvgWT << endl;
}

int main() {
	vector<int> processID = {1, 2, 3},
				arrivalTime = {0, 0, 0},
				burstTime = {24, 3, 3};

	FCFS(processID, arrivalTime, burstTime);

	system("pause");
	return 0;
}