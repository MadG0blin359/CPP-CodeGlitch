#include <iostream>
#include <string>
using namespace std;

class Insertion  {
    int data;

    public:
    Insertion(int d) : data(d) {}

    friend ostream& operator<<(ostream&, Insertion&);
};

ostream& operator<<(ostream& os, Insertion &other) {
    os << "Data : " << other.data;
    return os;
}

int main() {

    Insertion obj1(15);

    cout << "\nobj1 " << obj1;

    return 0;
}