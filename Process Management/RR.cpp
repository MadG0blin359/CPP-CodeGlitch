#include <iostream>
#include <vector>
using namespace std;

// Function for Round Robin Scheduling
void RR(vector<int> processID, vector<int> arrivalTime, vector<int> burstTime, int timeQuantum) {
	int totalProcess = processID.size();
	vector<int> remainingTime = burstTime, readyQueue, completionTime(totalProcess), TAT(totalProcess), WT(totalProcess);
	int time = 0, completed = 0, currentProcess = 0;
	vector<bool> isReady(totalProcess, false);

	cout << "Round Robin (RR) Scheduling :\n"
		<< "Gantt Chart: |0\t\t";

	// Loop until all processes are completed
	while (completed < totalProcess) {
		// Find the process to add in the queue that is ready
		for (int i = 0; i < totalProcess; i++) {
			if (arrivalTime[i] <= time && remainingTime[i] > 0 && !isReady[i]) {
				isReady[i] = true;
				readyQueue.push_back(i);
			}
		}

		// If no process is ready, increment time and continue
		if (readyQueue.empty()) {
			time++;
			continue;
		}

		// Get the current process and erase from queue
		currentProcess = readyQueue.front();
		readyQueue.erase(readyQueue.begin());

		// Process the current process
		int executionTime = min(timeQuantum, remainingTime[currentProcess]);
		remainingTime[currentProcess] -= executionTime;
		time += executionTime;

		// Update completion, TAT (Turn Around Time), and WT (Waiting Time) for the current process if completed
		if (remainingTime[currentProcess] == 0) {
			completionTime[currentProcess] = time;
			TAT[currentProcess] = completionTime[currentProcess] - arrivalTime[currentProcess];
			WT[currentProcess] = TAT[currentProcess] - burstTime[currentProcess];
			completed++;
			// Add the current process to the Gantt chart
			cout << "P" << processID[currentProcess] << "\t|" << time << "\t";
		}
		
		else {
			for (int i = 0; i < totalProcess; i++) {
				if (arrivalTime[i] <= time && remainingTime[i] > 0 && !isReady[i]) {
					readyQueue.push_back(i);
					isReady[i] = true;
				}
			}
			readyQueue.push_back(currentProcess);
		}
	}

	// Calculate average TAT and WT
	double AvgTAT = 0, AvgWT = 0;
	for (int i = 0; i < totalProcess; i++) {
		AvgTAT += TAT[i];
		AvgWT += WT[i];
	}
	AvgWT /= totalProcess;

	cout << "\n\nProcess\tArrival\tBurst\tCompletion\tTAT\tWT\n"
		<< "-------------------------------------------------------------\n";
	for (int i = 0; i < totalProcess; i++) {
		cout << "P" << processID[i] << "\t" << arrivalTime[i] << "\t" << burstTime[i] << "\t\t" << completionTime[i]
			<< "\t" << TAT[i] << "\t" << WT[i] << endl;
	}
	
	cout << endl;
	cout << "Average TAT : " << AvgTAT << endl;
	AvgTAT /= totalProcess;
	cout << "Average WT : " << AvgWT << endl;
}

int main() {
	int timeQuantum = 2;
	vector<int> processID = { 1, 2, 3 },
		arrivalTime = { 7, 5, 8 },
		burstTime = { 24, 3, 3 };
	
	RR(processID, arrivalTime, burstTime, timeQuantum);

	system("pause");
	return 0;
}