#include <iostream>
#include <string>
using namespace std;

class StringManipulator {
    private:
    string first_name;
    string last_name;
    string full_name;

    public:
    StringManipulator() {
        // Initialize strings to empty strings
        first_name = " ";
        last_name = " ";

        cout << "\n--Both Strings set to zero";
    }

    StringManipulator(string name1, string name2) {
        first_name = name1;
        last_name = name2;
    }

    void reverseString() {
        // Reverse the first name
        int name1_size = first_name.length();
        int index = name1_size - 1;
        string temp = first_name;

        for (int i = 0; i <= name1_size; i++) {
            first_name[i] = temp[index];       // Start from the zeroth index
            index--;
        }
    }

    void concatenateString() {
        full_name = first_name + " " + last_name;
    }

    void displayString() {
        cout << "\n--Reversed and Manipulated String : " << full_name;
    }

    ~StringManipulator() {
        cout << "\n\n--StringManipulator object is destroyed and the memory has been deallocated!" << endl;
    }
};

int main() {
    string first_name, last_name;

    cout << "\n--Enter First Name : ";
    cin >> first_name;

    cout << "--Enter Last Name : ";
    cin >> last_name;

    // StringManipulator person1;
    StringManipulator person1(first_name, last_name);
    
    person1.reverseString();
    person1.concatenateString();
    person1.displayString();

    return 0;

}