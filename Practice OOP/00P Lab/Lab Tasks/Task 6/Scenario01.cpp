#include <iostream>
#include <string>
using namespace std;

const int numOfCourses = 3;     // Number of courses of each student

class Student {
    private:
    string Name;
    const string Id;
    string Courses[numOfCourses];
    static int totalStudent;

    public:
    // Default Constructor
    Student() {
        totalStudent++;     // Counting each student
    }

    // Setters
    void setName(string sName) {
        Name = sName;
    }

    // Parameterized Constructor working as a setter
    Student(string id) : Id(id) {}    // By this initialization method called Constructor Initializer List, const member variable can be modified

    void setCourses(string sCourses[]) {
        for (int i = 0; i < numOfCourses; ++i) {
            Courses[i] = sCourses[i];
        }
    }

    // //Getters
    // string getName() {
    //     return Name;
    // }

    // string getId() const {
    //     return Id;
    // }

    // string getCourses() {
    //     // return Courses;
    // }

    // Member function to display each students info
    void displayInfo() {
        int num = 1;
        cout << "\n--Name : " << Name;
        cout << "\n--ID : " << Id;
        cout << "\n--Courses : ";
        for (auto i : Courses) {
            cout << "\n" << num << ". " << i;
            num++;
        }
        cout << endl;
    }
    
    // Static function to return the static totalStudent member variable
    static int getTotalStudents() {
        return totalStudent;
    }

};

// Definition of static member variable outside the class
int Student::totalStudent = numOfCourses;

int main() {

    const int numOfStudents = 3;
    string sName;
    string sCourses[numOfCourses];
    Student student[numOfStudents] = {
        Student("23P-0599"),   // Initializing const data member (Id) in constructor initializer list
        Student("23P-0566"),
        Student("23P-0533")
    };
    
    cout << "\n\t-----------------------------------";
    cout << "\n\t     Student Management System";
    cout << "\n\t-----------------------------------";

    cout << "\n\n\t    -----Add Student Info-----\n";

    // Loop to prompt the user to enter the details for each student
    for (int i = 0; i < numOfStudents; i++) {
        cout << "\n--Student " << i + 1;
        cout << "\n--Name : ";
        cin >> sName;
        student[i].setName(sName);

        cout << "\n--Courses :\n";

        for (int j = 0; j < numOfCourses; j++) {
            cout << "Course " << j + 1 << " : ";
            cin >> sCourses[j];
        }

        student[i].setCourses(sCourses);
        cout << "------------------------" << endl;
    }

    // Display total students
    cout << "\n--Total Students : " << Student::getTotalStudents() << endl;

    cout << "\n-----Displaying Student Info-----";
    
    // Loop to call the member function to display each student info
    for (int i = 0; i < numOfStudents; i++) {
        student[i].displayInfo();
    }

    return 0;
}