#include <iostream>
#include <string>
using namespace std;

class Compare {
    int hours, minutes;

    public:
    Compare(int hours, int minutes) {
        this->hours = hours;
        this->minutes = minutes;
    }

    bool isEarlierThan(Compare &other) {
        if (this->hours < other.hours)
            return true;
        else if (this->hours == other.hours && this->minutes < other.minutes)
            return true;
        else
            return false;
    }
};

int main() {

    Compare Time1(3, 45), Time2(3, 25);
    bool check;

    Time1.isEarlierThan(Time2);

    if (check)
        cout << "\nTime1 comes before Time2" << endl;
    else
        cout << "\nTime2 comes before Time1" << endl;

    return 0;
}