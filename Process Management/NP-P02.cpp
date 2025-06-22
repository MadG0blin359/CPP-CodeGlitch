#include <iostream>
#include <vector>
using namespace std;

void NPP(vector<int> processID, vector<int> arrivalTime, vector<int> burstTime, vector<int> priority) {
	int totalProcess = processID.size();
	vector<int> remainingTime = burstTime, completionTime(totalProcess, 0), TAT(totalProcess, 0), WT(totalProcess, 0);
	int time = 0, completed = 0;

	cout << "Non-preemptive Priority (NP-P) Scheduling :\n"
		<< "Gantt Chart: |" << time << "\t";

	while (completed < totalProcess) {
		int index = -1;
		int maxPriority = -1;

		// Find process with max priority that has arrived and is not completed
		for (int i = 0; i < totalProcess; i++) {
			if (arrivalTime[i] <= time && remainingTime[i] > 0 && priority[i] > maxPriority) {
				maxPriority = priority[i];
				index = i;
			}
		}

		// Check if there are multiple processes with the same max priority
		vector<int> samePriority;
		for (int i = 0; i < totalProcess; i++) {
			if (arrivalTime[i] <= time && remainingTime[i] > 0 && priority[i] == maxPriority) {
				samePriority.push_back(i); // store index
			}
		}

		if (samePriority.size() > 1) {
			// Use Round Robin for same priority
			int timeQuantum = 2;
			int i = 0;
			while (!samePriority.empty()) {
				int current = samePriority[i];

				if (remainingTime[current] > 0) {
					if (remainingTime[current] <= timeQuantum) {
						time += remainingTime[current];
						remainingTime[current] = 0;
						completionTime[current] = time;
						TAT[current] = completionTime[current] - arrivalTime[current];
						WT[current] = TAT[current] - burstTime[current];
						completed++;
						samePriority.erase(samePriority.begin() + i);
						if (samePriority.empty()) break;
					}
					else {
						remainingTime[current] -= timeQuantum;
						time += timeQuantum;
						i++;
					}
					cout << "P" << processID[current] << "\t|" << time << "\t";
				}

				if (i >= samePriority.size()) i = 0;
			}
		}
		else if (index != -1) {
			// Non-preemptive normal execution
			time += burstTime[index];
			remainingTime[index] = 0;
			completionTime[index] = time;
			TAT[index] = completionTime[index] - arrivalTime[index];
			WT[index] = TAT[index] - burstTime[index];
			completed++;
			cout << "P" << processID[index] << "\t|" << time << "\t";
		}
		else {
			time++; // No process is ready, CPU is idle
		}
	}

	// Display results
	double AvgTAT = 0, AvgWT = 0;
	cout << "\n\nProcess\tArrival\tBurst\tPriority\tCompletion\tTAT\tWT\n"
		<< "------------------------------------------------------------------\n";
	for (int i = 0; i < totalProcess; i++) {
		cout << "P" << processID[i] << "\t" << arrivalTime[i] << "\t" << burstTime[i] << "\t" << priority[i]
			<< "\t\t" << completionTime[i] << "\t\t" << TAT[i] << "\t" << WT[i] << endl;
		AvgTAT += TAT[i];
		AvgWT += WT[i];
	}
	cout << "\nAverage TAT : " << AvgTAT / totalProcess << endl;
	cout << "Average WT  : " << AvgWT / totalProcess << endl;
}

int main() {
	vector<int> processID = { 1, 2, 3 };
	vector<int> arrivalTime = { 0, 0, 0 };
	vector<int> burstTime = { 24, 3, 3 };
	vector<int> priority = { 2, 1, 2 };

	NPP(processID, arrivalTime, burstTime, priority);

	system("pause");
	return 0;
}