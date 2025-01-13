#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    int age;
    double marks;
};

void updateMarks(Student &s1, int N = 8) {
    s1.marks += N;
}

int main() {

    Student s1 = {230599, "Shark", 19, 18.5};

    cout << "\nBefore";
    cout << "\nRoll : " << s1.roll;
    cout << "\nName : " << s1.name;
    cout << "\nAge : " << s1.age;
    cout << "\nMarks : " << s1.marks << endl;

    updateMarks(s1);

    cout << "\nAfter";
    cout << "\nRoll : " << s1.roll;
    cout << "\nName : " << s1.name;
    cout << "\nAge : " << s1.age;
    cout << "\nMarks : " << s1.marks << endl;

    updateMarks(s1, 12);

    cout << "\nAfter 2";
    cout << "\nRoll : " << s1.roll;
    cout << "\nName : " << s1.name;
    cout << "\nAge : " << s1.age;
    cout << "\nMarks : " << s1.marks << endl;

    return 0;
}