#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

void getTime()
{
    // Get the current time
    time_t currentTime = time(nullptr);

    // Convert the time to a tm struct (broken down time)
    tm *currentTm = localtime(&currentTime);

    // Extract date components from the tm struct
    int year = currentTm->tm_year + 1900; // Years since 1900
    int month = currentTm->tm_mon + 1;    // Month (0-based, so add 1)
    int day = currentTm->tm_mday;         // Day of the month

    // Print the current date
    cout << "\n"
         << setfill('0')
         << setw(2) << day << '/'
         << setw(2) << month << '/'
         << setw(4) << year;

    // Extract hour, minute, and second components
    int hour = currentTm->tm_hour;
    int minute = currentTm->tm_min;
    int second = currentTm->tm_sec;

    // Display the current time
    cout << "\t" << setfill('0')
         << setw(2) << hour << ":"
         << setw(2) << minute << ":"
         << setw(2) << second << endl;
}

int main() {

    getTime();

    return 0;
}