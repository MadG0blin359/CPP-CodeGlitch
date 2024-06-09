#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;
    int age;
    string country;
    static int count;

    public:
    // Increment the count with each object created
    Person() {
        count++;
    }

    // Setters
    void setName() {
        cout << "--Enter Name : ";
        cin.ignore();
        getline(cin, name);
    }

    void setAge() {
        do {
            cout << "--Enter Age : ";
            cin >> age;

            if (age < 1)
                cout << "\n-----Invalid Input!-----\n";
        }

        while (age < 1);
    }

    void setCountry() {
        cout << "--Enter Country : ";
        cin.ignore();
        getline(cin, country);
    }

    // Getters
    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    string getCountry() {
        return country;
    }

    static int getCount() {
        return count;
    }

};

// Explicit initialization of static data member outside the class
int Person::count = 0;

int main() {

    int numOfPerson;

    cout << "\n\t-----Personal Information-----\n";

    cout << "\n--Enter the number of persons : ";
    cin >> numOfPerson;

    Person arr[numOfPerson];

    cout << "\n\t-----Add Personal Information-----\n";

    // Loop to prompt the user, read and store the input values
    for (int i = 0; i < numOfPerson; i++) {
        cout << "\n-----Person " << i + 1 << "-----\n";
        arr[i].setName();
        arr[i].setAge();
        arr[i].setCountry();
    }

    cout << "\n\t-----Displaying Personal Information-----\n";

    // Loop to display the personal information stored
    for (int i = 0; i < numOfPerson; i++) {
        cout << "\n-----Person " << i + 1 << "-----";
        cout << "\n--Name : " << arr[i].getName();
        cout << "\n--Age : " << arr[i].getAge();
        cout << "\n--Country : " << arr[i].getCountry();
        cout << "\n------------------" << endl;
    }

    cout << "\n-----Total Persons : " << Person::getCount() << "-----" << endl;

    return 0;
}