#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

const int category_size = 20;

// Base class
class User {
    protected:
    string full_name;
    string password;

    public:
    User() {
        full_name = "";
        password = "";
    }

    // Setters
    void setFullName() {

    }

    void setPassword() {

    }

    // Getters
    string getFullName() {

    }

    string getPassword() {

    }

    // Destructor
    ~User() {};
};

class Income : virtual protected User {
    string *income;
    
    public:
    Income() {
        income = new string[category_size];
    }

    // Setter
    void setIncome() {
        
    }

    // Getter
    string getIncome() {

    }

    // Destructor
    ~Income() {};
};

class Expense : virtual protected User {
    string *expense;

    public:
    Expense() {
        expense = new string[category_size];
    }

    void setExpense() {

    }

    string getExpense() {

    }

    // Destructor
    ~Expense() {}
};

class FinancialReport : private Income, private Expense {
    public:


    // Destructor
    ~FinancialReport() {}
};

// Function declaration
void getTime();

int main() {
    
    FinancialReport obj[category_size];
  
    char menu_choice;

    cout << "\n\t-----Menu-----";
    cout << "\n1. Add User";
    cout << "\n2. Add Income";
    cout << "\n3. Add Expense";
    cout << "\n4. Generate Financial Report";
    cout << "\n5. Exit";
    cout << "\n--Enter Your Choice : ";
    cin >> menu_choice;
    
    while (true) {
        switch (menu_choice) {
            case '1':

            break;
            
            case '2':

            break;
            
            case '3':

            break;
            
            case '4':

            break;
            
            case '5':
                cout << "\n\t-----Expense Tracker Made With ♥-----";
                return 0;       // Exit the program
            break;
            
            default:
            
            break;
        }
    }

    return 0;
}

// Function to get the current system clock time & date
void getTime() {
    // Get the current time
    time_t currentTime = time(nullptr);

    // Convert the time to a tm struct (broken down time)
    tm* currentTm = localtime(&currentTime);

    // Extract date components from the tm struct
    int year = currentTm->tm_year + 1900; // Years since 1900
    int month = currentTm->tm_mon + 1;     // Month (0-based, so add 1)
    int day = currentTm->tm_mday;          // Day of the month

    // Print the current date
    cout << "\n" << setfill('0')
            << setw(2) << day << '/' 
            << setw(2) << month << '/'
            << setw(4) << year;
    
    // Extract hour, minute, and second components
    int hour = currentTm->tm_hour;
    int minute = currentTm->tm_min;
    int second = currentTm->tm_sec;

    // Display the current time
    cout << "\t" << setfill('0') 
            << setw(2) << hour << ":"
            << setw(2) << minute << ":"
            << setw(2) << second << endl;
}