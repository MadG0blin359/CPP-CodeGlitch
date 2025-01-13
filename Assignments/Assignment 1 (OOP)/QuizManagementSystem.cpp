#include <iostream>
using namespace std;

const int maxStudents = 40, maxQuizes = 5;      // Constant global variables 

// Function to display overall quiz stats
void displayQuizStats(double marks[][maxQuizes], int numOfStudents, int numOfQuiz) {
    double maxMarks[numOfQuiz], minMarks[numOfQuiz], avgMarks[numOfQuiz];

    // Initializing avgMarks to zero to avoid garbage values
    for (int i = 0; i < numOfQuiz; i++) {
        avgMarks[i] = 0;
        // Initializing the minMarks array to a greater value so that the minimum value in the marks can be easily found and simultaneously avoiding garbage value
        minMarks[i] = 10000;
    }

    maxMarks[0] = marks[0][0];
    minMarks[0] = marks[0][0];

    cout << "\n\t*****Quiz Statistics*****\n";

    // Keeping the outer loop on the first column until all the rows have been read succesfully by the inner loop
    for (int j = 0; j < numOfQuiz; j++) {
        for (int i = 0; i < numOfStudents; i++) {
            // Condition to look for maximum value
            if (maxMarks[j] < marks[i][j]) {
                maxMarks[j] = marks[i][j];
            }

            // Condition to look for minimum value
            else if (minMarks[j] > marks[i][j]) {
                minMarks[j] = marks[i][j];
            }

            // Storing and adding all marks for each quiz
            avgMarks[j] += marks[i][j]; 
            
        }

        // Calculating average marks for each quiz of whole class
        avgMarks[j] /= numOfStudents;

        // Display the final results
        cout << "\n\t-----Quiz " << j+1 << "-----";
        cout << "\nMaximum Marks : " << maxMarks[j];
        cout << "\nMinimum Marks : " << minMarks[j];
        cout << "\nAverage Marks : " << avgMarks[j] << endl;

    }
    
}

// Function to display quiz stats for each student
void displayStudentStats(double marks[][maxQuizes], int numOfStudents, int numOfQuiz, string name[]) {
    
    double studentAvg[numOfStudents], maxMarks[numOfStudents];

    // Initializing studentAvg to zero to avoid garbage values
    for (int i = 0; i < numOfQuiz; i++) {
        studentAvg[i] = 0;
    }

    maxMarks[0] = marks[0][0];

    cout << "\n\t*****Student Stats*****\n";

    // Loop to display each student results
    for (int i = 0; i < numOfStudents;i++) {
        cout << "\n\t-----Student " << i+1 << "-----\n";
        cout << "\n--Name : " << name[i];
        cout << "\nMarks Obtained :";
        for (int j = 0; j < numOfQuiz; j++) {
            cout << "\n--Quiz " << j+1 << " : " << marks[i][j];
            studentAvg[i] += marks[i][j];

            // Condition to look for maximum value at the current row 
            if (maxMarks[i] < marks[i][j]) {
                maxMarks[i] = marks[i][j];
            }

        }

        // Calculating average of all quizes for each student
        studentAvg[i] /= numOfQuiz;

        // Display final result for each student
        cout << "\n--Average Marks : " << studentAvg[i];
        cout << "\n--Maximum Marks : " << maxMarks[i] << endl;
    }
}

int main() {
    double marks[maxStudents][maxQuizes];
    int numOfStudents, numOfQuiz;
    
    cout << "\n\tWelcome to Quiz Management System\n\n";

    // Prompting the user to enter the number of students and quizes
    do {
        cout << "--Enter the number of students (up to 40): ";
        cin >> numOfStudents;

        cout << "--Enter the number of quizes : ";
        cin >> numOfQuiz;

        if (numOfStudents <= 0 || numOfQuiz <= 0) {
            cout << "\nInvalid Input! Enter a Positive Value.\n";
        }

        else if (numOfStudents > maxStudents) {
            cout << "\nInvalid Input! Max Number of Students Exceeded.\n";
        }

        else if (numOfQuiz > maxQuizes) {
            cout << "\nInvalid Input! Max Number of Quizes Exceeded.\n";
        }
    }

    while (numOfStudents <= 0 || numOfQuiz <= 0 || numOfStudents > maxStudents || numOfQuiz > maxQuizes);

    // Declaring string for storing student names
    string name[numOfStudents];

    // Loop to take user input for name and marks
    for (int i = 0; i < numOfStudents; i++) {

        cout << "\n\t-----Student " << i+1 << "-----\n";
        cout << "--Name : ";
        cin >> name[i];

        for (int j = 0; j < numOfQuiz; j++) {
            cout << "--Quiz " << j+1 << " Marks : ";
            cin >> marks[i][j];
        }
    }

    // Calling the function to display the maximum, minimum, and the average of wach quiz
    displayQuizStats(marks, numOfStudents, numOfQuiz);
    // Calling the funciton to display results for each student
    displayStudentStats(marks, numOfStudents, numOfQuiz, name);

    return 0;
}