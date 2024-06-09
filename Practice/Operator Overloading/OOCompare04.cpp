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

    bool operator>(Compare &other) {
        if(this->hours > other.hours)
            return true;
        else if (this->hours == other.hours && this->minutes > other.minutes)
            return true;
        else
            return false;
    }
};

int main() {

    Compare Time1(5, 45), Time2(5, 30);

    if(Time1 > Time2)
        cout << "Time1 comes after Time2" << endl;
    else
        cout << "Time2 comes after Time1" << endl;

    return 0;
}