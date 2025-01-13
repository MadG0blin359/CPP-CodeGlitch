#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

    ofstream myFile;
    string studentName;
    int numOfVolunteers, numOfBoxesSold, numOfTotalBoxesSold, counter;
    double costOfOneBox;
    
    cout << "Enter The Number Of Volunteers : ";
    cin >> numOfVolunteers;

    numOfTotalBoxesSold = 0;
    counter = 0;

    myFile.open ("VolunteerData.txt");
    myFile << "No.\t\tName\tBoxes Sold\n";

    while (counter < numOfVolunteers) {

        cout << "Enter The Volunteer's Name : ";
        cin >> studentName;
        myFile << counter+1 << ".\t\t" << studentName << "\t";

        cout << "Enter The Number of Boxes Sold By the Volunteer : ";
        cin >> numOfBoxesSold;
        myFile << "\t" << numOfBoxesSold << "\n";

        numOfTotalBoxesSold += numOfBoxesSold;
        counter++;

    }

    cout << "Enter The Cost Of One Box : ";
    cin >> costOfOneBox;

    if (counter != 0) {
        cout << "\nTotal Number Of Boxes Sold : " << numOfTotalBoxesSold;
        cout << "\nAverage Number Of Boxes Sold By Each Volunteer : " << numOfTotalBoxesSold/counter;
        cout << "\nTotal Money Made By Selling Cookies : $" << numOfTotalBoxesSold * costOfOneBox;

        myFile << "\nTotal Cookie Boxes Sold : " << numOfTotalBoxesSold;
        myFile << "\nTotal Revenue Generated : $" << numOfTotalBoxesSold * costOfOneBox;
    }

    else {
        cout << "No Input!";
    }

    myFile.close ();

}