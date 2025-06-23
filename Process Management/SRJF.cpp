#include <iostream>
#include <vector>
using namespace std;

void SRJF(vector<int> processID, vector<int> arrivalTime, vector<int> burstTime) {
	int totalProcess = processID.size();
	vector<int> remainingTime = burstTime, completionTime(totalProcess, 0), TAT(totalProcess, 0), WT(totalProcess, 0);
	int time = 0, completed = 0;

	cout << "Shortest-Remaining-Job-First (SRJF) Scheduling :\n"
		<< "Gantt Chart: |0\t\t";

	while (completed < totalProcess) {
		int index = -1;
		int minProcessTime = INT_MAX;

		for (int i = 0; i < totalProcess; i++) {
			if (arrivalTime[i] <= time && remainingTime[i] > 0 && burstTime[i] < minProcessTime) {
				index = i;
				minProcessTime = burstTime[i];
			}
		}

		if (index == -1) {
			time++;
			continue;
		}

		remainingTime[index]--;
		time++;

		if (remainingTime[index] == 0) {
			completionTime[index] = time;
			TAT[index] = completionTime[index] - arrivalTime[index];
			WT[index] = TAT[index] - burstTime[index];
			completed++;
			// Add the current process to the Gantt chart
			cout << "P" << processID[index] << "\t|" << time << "\t";
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
		<< "-------------------------------------------------------------\n";
	for (int i = 0; i < totalProcess; i++) {
		cout << "P" << processID[i] << "\t" << arrivalTime[i] << "\t" << burstTime[i] << "\t\t" << completionTime[i]
			<< "\t" << TAT[i] << "\t" << WT[i] << endl;
	}

	cout << "Average TAT : " << AvgTAT << endl;
	cout << "Average WT : " << AvgWT << endl;
}

int main() {
	vector<int> processID = { 1, 2, 3, 4 },
				arrivalTime = { 0, 1, 2, 3 },
				burstTime = { 8, 4, 9, 5 };

	SRJF(processID, arrivalTime, burstTime);

	system("pause");
	return 0;
}