#include <iostream>
using namespace std;

class bioData {
    private:
        string name;
        int age;
        double CGPA;
    
    public:
        char gender;
        double height;

    void getData() {
        cout << "Enter your name : ";
        cin >> name;

        cout << "Enter your age : ";
        cin >> age;

        cout << "Enter your CGPA : ";
        cin >> CGPA;
    }
};

int main() {

    bioData student1, student2;

    student1.getData();

    cout << "Enter your gender : ";
    cin >> student1.gender;

    cout << "Enter your height : ";
    cin >> student1.height;

    cout << "Enter your gender : ";
    cin >> student2.gender;

    cout << "Enter your height : ";
    cin >> student2.height;

    return 0;
}