//#include <iostream>
//#include <vector>
//using namespace std;
//
//void FCFS(vector<int> processID, vector<int> arrivalTime, vector<int> burstTime) {
//    int totalProcess = processID.size();
//    vector<int> remainingTime = burstTime, CT(totalProcess, 0), TAT(totalProcess, 0), WT(totalProcess, 0);
//    int time = 0, completed = 0;
//
//    cout << "First-Come-First-Serve (FCFS) Scheduling :\n"
//        << "Gantt Chart: 0|\t\t";
//
//    while (completed < totalProcess) {
//        int index = -1;
//        int minTime = 1000;
//
//        for (int i = 0; i < totalProcess; i++) {
//            if (arrivalTime[i] <= time && remainingTime[i] > 0 && arrivalTime[i] < minTime) {
//                index = i;
//                minTime = arrivalTime[i];
//            }
//        }
//
//        if (index == -1) {
//            time++;
//            continue;
//        }
//
//        time += remainingTime[index];
//        remainingTime[index] = 0;
//
//        CT[index] = time;
//        TAT[index] = CT[index] - arrivalTime[index];
//        WT[index] = TAT[index] - burstTime[index];
//        completed++;
//
//        cout << "P" << processID[index] << "\t\t" << CT[index] << "|\t\t";
//
//    }
//    cout << endl;
//
//    double AvgTAT = 0, AvgWT = 0;
//    for (int i = 0; i < totalProcess; i++) {
//        AvgTAT += TAT[i];
//        AvgWT += WT[i];
//    }
//    AvgTAT /= totalProcess;
//    AvgWT /= totalProcess;
//
//    cout << "\n\nProcess\tArrival\tBurst\tCompletion\tTAT\tWT\n"
//        << "-------------------------------------------------------------\n";
//    for (int i = 0; i < totalProcess; i++) {
//        cout << "P" << processID[i] << "\t" << arrivalTime[i] << "\t" << burstTime[i] << "\t\t" << completionTime[i]
//            << "\t" << TAT[i] << "\t" << WT[i] << endl;
//    }
//
//    cout << "Average TAT : " << AvgTAT << endl;
//    cout << "Average WT : " << AvgWT << endl;
//}
//
//int main() {
//    vector<int> processID = { 1, 2, 3 },
//        arrivalTime = { 0, 0, 0 },
//        burstTime = { 24, 3, 3 };
//
//    FCFS(processID, arrivalTime, burstTime);
//    return 0;
//}