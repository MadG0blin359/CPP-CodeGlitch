#include <iostream>
using namespace std;

const int numOfFloors = 4, numOfRooms = 5;          // Number floors and rooms in the hotel
const long eliteRooms = 10000, economyRooms = 6000;         // Cost of rooms in the hotel

// Function prototypes
void bookARoom(char arr[][numOfRooms]);
void showAvailableRooms(char arr[][numOfRooms]);

int main() {

    int menu_choice;
    char arr[numOfFloors][numOfRooms];

    // Loop to set available rooms
    for (int i = 0; i < numOfFloors; i++) {
        cout << "\t  ";
        for (int j = 0; j < numOfRooms; j++) {
            arr[i][j] = '-'; 
        }
    }

    // Loop to keep displaying the menu
    do {

        cout << "\n\t-----Hotel Room Booking System-----\n";

        cout << "\n1. Book a Room";
        cout << "\n2. Show Available Rooms";
        cout << "\n3. Exit";

        cout << "\n--Enter your choice : ";
        cin >> menu_choice;

        switch (menu_choice) {
        case 1:
            bookARoom(arr);
            break;

        case 2:
            showAvailableRooms(arr);
            break;

        case 3:
            cout << "\nExiting the program. Thank you!\n";
            break; 
        
        default:
            cout << "\n--Invalid Input. Choose from the menu.\n";
            break;
        }
    }
    // Condition to when to exit the menu
    while (menu_choice != 3);

    return 0;
}

// Function to book a new room
void bookARoom(char arr[][numOfRooms]) {
    // Variables to read and store the user input
    int floorNum, roomNum, daysNum;
    long totalCost = 0;

    // Loop to help validate the user input
    do {
        cout << "\n--Enter the floor number (1-4) : ";
        cin >> floorNum;

        cout << "\n--Enter the room number (1-5) : ";
        cin >> roomNum;

        cout << "\n--Enter the number of days : ";
        cin >> daysNum;

        if (floorNum < 1 || floorNum > 4) {
            cout << "\n--Invalid Input! Choose between 1-4.\n";
        }

        else if (roomNum < 1 || roomNum > 5) {
            cout << "\n--Invalid Input! Choose between 1-5.\n";
        }

        else if (daysNum < 1) {
            cout << "\n--Invalid Input!.\n";
        }
    }
    // Conditions to validate the user input
    while (floorNum < 1 || floorNum > 4 || roomNum < 1 || roomNum > 5 || daysNum < 1);

    // Condition to check if the room is already booked
    if (arr[floorNum-1][roomNum-1] == '*') {
        cout << "\nSorry! The room is already booked, select another.\n";
    }

    else {
        arr[floorNum-1][roomNum-1] = {'*'};       // Book the specified room

        cout << "\n\n--Floor : " << floorNum << ", Room : " << roomNum << " successfully booked.";

        // First two floors are elite, costing 10000 rupees per room per day
        if (floorNum <= 2) {
            totalCost = eliteRooms * daysNum;        // Calculating the total cost for elite rooms
        }

        else {
            totalCost = economyRooms * daysNum;        // Calculating the total cost for economy rooms
        }

        cout << "\n--Your total cost for " << daysNum << " days is " << totalCost << " Rupees.\n";
    }

}

// Function to display all available rooms in the hotel
void showAvailableRooms(char arr[][numOfRooms]) {

    cout << "\nRoom Status : \n(*) = Booked\t(-) = Available\n\n";

    // Display the available rooms
    for (int i = 0; i < numOfFloors; i++) {
        cout << "\t  ";
        for (int j = 0; j < numOfRooms; j++) {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }

}
