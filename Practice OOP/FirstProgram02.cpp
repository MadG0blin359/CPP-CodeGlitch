#include <iostream>
// #include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

class Employee {
    private:
    string name;
    int gpa, age;

    public:
    int roll;

    void getData() {
        cout << "Enter name : ";
        cin >> name;

        cout << "Enter GPA : ";
        cin >> gpa;

        cout << "Enter Age : ";
        cin >> age;
    }

    void getData2(int result);

    int sendData(int num1, int num2) {
        cout << "Num 1 : " << num1;
        cout << "\nNum 2 : " << num2 << endl;
        return num1+num2;
    }

};

void Employee :: getData2(int result) {
        cout << "Result : " << result;
        cout << "\nEnter roll : ";
        cin >> roll;
}

int main() {

    Employee e1;

    e1.getData();
    int result = e1.sendData(5,8);
    e1.getData2(result);

    return 0;
}