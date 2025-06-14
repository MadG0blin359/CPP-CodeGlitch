#include <iostream>
#include <iomanip>
#include <ctime>
#include <unistd.h>

using namespace std;

void display_calendar() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int curr_year = 1900 + ltm->tm_year;
    int curr_month = 1 + ltm->tm_mon;
    int curr_day = ltm->tm_mday;

    // Set to first day of month
    tm first_day = *ltm;
    first_day.tm_mday = 1;
    mktime(&first_day);
    int start_day = first_day.tm_wday; // 0 = Sunday
    
    // Get number of days in month
    tm next_month = first_day;
    next_month.tm_mon++;
    mktime(&next_month);
    int days_in_month = next_month.tm_mday - 1;

    cout << "\033[2J\033[1;1H"; // Clear screen
    cout << "  ┌───────────────────────┐\n";
    cout << "  │      " << put_time(ltm, "%B %Y") << "      │\n";
    cout << "  ├──┬──┬──┬──┬──┬──┬──┤\n";
    cout << "  │Su│Mo│Tu│We│Th│Fr│Sa│\n";
    cout << "  ├──┼──┼──┼──┼──┼──┼──┤\n";

    int day = 1;
    for (int i = 0; i < 6; i++) {
        cout << "  │";
        for (int j = 0; j < 7; j++) {
            if ((i == 0 && j < start_day) || day > days_in_month) {
                cout << "  │";
            } else {
                if (day == curr_day) cout << "\033[7m";
                cout << setw(2) << day << "\033[0m│";
                day++;
            }
        }
        cout << "\n";
        if (day > days_in_month) break;
        cout << "  ├──┼──┼──┼──┼──┼──┼──┤\n";
    }
    cout << "  └──┴──┴──┴──┴──┴──┴──┘\n";
    cout.flush();
}

int main() {
    while(true) {
        display_calendar();
        sleep(60); // Update every minute
    }
    return 0;
}
