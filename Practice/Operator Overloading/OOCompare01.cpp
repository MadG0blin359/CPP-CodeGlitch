#include <iostream>
#include <string>
using namespace std;

class Compare {
    int hours, minutes;

    public:
    Compare(int hours = 0, int minutes = 0) {
        this->hours = hours;
        this->minutes = minutes;
    }

    void operator<(Compare &other) {
        if (this->hours < other.hours)
            cout << "Time1 comes before Time2" << endl;
        else if(this->hours > other.hours)
            cout << "Time2 comes before Time1" << endl;
        else if(this->hours == other.hours && this->minutes < other.minutes)
            cout << "Time1 comes before Time2" << endl;
        else 
            cout << "Time2 comes before Time1" << endl;
    }
};

int main() {

    Compare Time1(5, 5), Time2(5, 15);

    Time1 < Time2;

    return 0;
}