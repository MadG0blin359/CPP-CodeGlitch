#include <iostream>
#include <string>
using namespace std;

class Grade {
    string name;
    double total, average;
    int count;

    public:
    Grade(string n) : name(n), total(0), average(0), count(0) {}

    Grade& addGrade(double grades) {
        total += grades;
        count++;
        return *this;
    }

    Grade& getAverage() {
        average = total/count;
        return *this;
    }

    void display() {
        cout << "\nStudent Name : " << name
             << "\nGrade Average : " << average
             << endl;
    }
};

int main() {

    Grade s1("John");

    s1.addGrade(73).addGrade(64).addGrade(89).getAverage().display();

    return 0;
}