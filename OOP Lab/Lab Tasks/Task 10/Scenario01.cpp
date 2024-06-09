#include <iostream>
#include <string>
using namespace std;

// Class to represent date of birth
class Date {
    private:
    int day;
    int month;
    int year;

    public:
    Date() : day(0), month(0), year(0) {}       // Default Constructor

    // Setters
    void setDay() {
        do {
            cout << "--Contact Birth Day (1-31) : ";
            cin >> day;
            
            // Condition to handle invalid inputs
            if (day < 1 || day > 31)
                cout << "\nInvalid Input!\n";
        }

        while (day < 1 || day > 31);
    }

    void setMonth() {
        do {
            cout << "--Contact Birth Month (1-12) : ";
            cin >> month;

            // Condition to handle invalid inputs
            if (month < 1 || month > 12)
                cout << "\nInvalid Input!\n";
        }

        while (month < 1 || month > 12);
    }

    void setYear() {
        cout << "--Contact Birth Year : ";
        cin >> year;
        cin.ignore();   // Clear input buffer
    }

    // Getters
    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

};

// Class to represent a contact
class Contact {
    private:
    string name;
    string phone;
    string email;
    Date birthday;
    static int totalContacts;       // Automatically initialized to 0 (zero)

    public:
    // Default Constructor
    Contact() : name(""), phone(""), email("") {}

    // Function to get and verify the user input (month) with contact list
    bool isBirthdayMonth(int month) const {
        return birthday.getMonth() == month;
    }

    // Getters
    string getName() const {
        return name;
    }

    static int getTotalContacts() {     // Get the total number of contacts saved
        return totalContacts;
    }

    // Function to prompt the user to enter contact data
    void getData() {
        cout << "\n\t-----Add contact-----\n";

        cout << "--Contact Name : ";
        getline(cin, name);

        cout << "--Contact Phone : ";
        getline(cin, phone);

        cout << "--Contact E-mail : ";
        getline(cin, email);

        // Functions to set contact Birthday
        birthday.setDay();
        birthday.setMonth();
        birthday.setYear();

        // Increment the contacts count variable after every new contact created
        totalContacts++;
    }

    // Function to display the contact data
    void display() {
        cout << "\nName : " << name; 
        cout << "\nPhone : " << phone; 
        cout << "\nE-mail : " << email; 
        cout << "\nBirhtday : " << birthday.getDay() << "/" << birthday.getMonth() << "/" << birthday.getYear(); 
    }

};

// Definition of the static data member
int Contact::totalContacts = 0;

// Class to represent a contact book
class ContactBook {
    static const int size = 2;      // Fixed size of the contacts array
    Contact contacts[size];

    public:
    ContactBook() {}        // Default constructor

    // Function to add contacts
    void addContact() {
        for (int i = 0; i < size; i++) {
            contacts[i].getData();
        }
    }

    // Function to display all the contacts
    void displayAll() {
        int totalContacts = contacts[0].getTotalContacts();     // Get the total number of contacts already saved
        cout << "\n\t-----Contact List-----\n";
        cout << "\nTotal Contacts : " << totalContacts << endl;

        for (int i = 0; i < totalContacts; i++) {
            cout << "\n-------------------------";
            contacts[i].display();
            cout << endl;
        }
    }

    // Function to print specific month contacts
    void printBirthdayContacts() const {
        int totalContacts = contacts[0].getTotalContacts();     // Get the total number of contacts already saved
        int user_month;
        cout << "\n--Enter month to print contacts : ";
        cin >> user_month;

        cout << "\nContacts with birthday in month " << user_month << ":" << endl;
        
        // Loop to search for specific month contacts
        for (int i = 0; i < totalContacts; ++i) {
            if (contacts[i].isBirthdayMonth(user_month)) {
                cout << "->" << contacts[i].getName() << endl;
            }
        }
    }
};

int main() {

    ContactBook book;
    
    book.addContact();
    book.displayAll();
    book.printBirthdayContacts();

    return 0;
}