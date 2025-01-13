#include <iostream>
#include <string>
using namespace std;

class Extraction {
    int data;

    public:
    Extraction(int d = 0) : data(d) {}

    void display() {
        cout << "\nobj1 : " << data;
    }

    friend istream& operator>>(istream&, Extraction&);
};

istream& operator>>(istream &is, Extraction &other) {
    cout << "\nEnter Data : ";
    is >> other.data;
    return is;
}

int main() {

    Extraction obj1;

    cin >> obj1;

    obj1.display();

    return 0;
}