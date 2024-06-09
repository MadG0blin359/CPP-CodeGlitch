#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

const int size = 10;

// Base class
class User {
    protected:
    string full_name;
    string password;

    // Destructor
    ~User() {};
};
    

class Income : virtual protected User {
    string income[size];
    float incomeAmount[size];
    int incomeCount = 0;
    char choice;
    
    public:
    // Destructor
    ~Income() {};

    void setIncome(string SourceOfIncome, float amount) {    
        for (int i = 0; i < incomeCount; i++) {
            if (income[i] == SourceOfIncome) {
                cout << "Income with the same description already exists." << endl;
                return;
            }
        }
        
        if (incomeCount < size) {
            income[incomeCount] = SourceOfIncome;
            incomeAmount[incomeCount] = amount;
            incomeCount++;
        } 
        
        else {
            cout << "Maximum income entries reached." << endl;
        }   
    }

    // Getter to get income
    string getIncome() {
        string incomeString = "";
        for (int i = 0; i < incomeCount; i++) {
            incomeString += "Description: " + income[i] + ", Amount: " + to_string(incomeAmount[i]) + "\n";
        }

        return incomeString;
    }

    // Method to calculate total income
    float calculateTotalIncome() {
        float totalIncome = 0.0;
        for (int i = 0; i < incomeCount; i++) {
            totalIncome += incomeAmount[i];
        }
        
        return totalIncome;
    }

    friend class FinancialReport; 


};

class Expense : virtual protected User {
    string categories[size];
    string descriptions[size][size];
    float amounts[size][size] = {0.0}; // Initializing to 0.0
    int numOfExpenses = 0;

public:
    void setExpense(string category, string description, float amount) {
        // Check if the category already exists
        for (int i = 0; i < numOfExpenses; i++) {
            if (categories[i] == category) {
                cout << "Expense with the same category already exists." << endl;
                return;
            }
        }
        
        // Check if the number of expenses has reached the maximum limit
        if (numOfExpenses < size) {
            categories[numOfExpenses] = category;
            descriptions[numOfExpenses][0] = description;
            amounts[numOfExpenses][0] = amount;
            numOfExpenses++;
        } 
        
        else {
            cout << "Maximum expense entries reached." << endl;
        }
    }

    string getExpenses() {
        string expenseString = "";
        for (int i = 0; i < numOfExpenses; i++) {
            expenseString += "Category: " + categories[i] + "\nDescription: " + descriptions[i][0] + "\nAmount: " + to_string(amounts[i][0]) + "\n";
        }
        return expenseString;
    }

    

    float calculateTotalExpense() {
        float totalExpense = 0.0;
        for (int i = 0; i < numOfExpenses; i++) {
            totalExpense += amounts[i][0];
        }
        return totalExpense;
    }

    void displayAllExpenses() {
        for (int i = 0; i < numOfExpenses; i++) {
            cout << "Category: " << categories[i] << ", Description: " << descriptions[i][0] << ", Amount: " << amounts[i][0] << endl;
        }
    }

    float calculateTotalFromSpecifcCategory(string category) {
        float total = 0;
        for (int i = 0; i < numOfExpenses; i++) {
            if (categories[i] == category) {
                total += amounts[i][0];
            }
        }
        return total;
    }
    
    // Destructor
    ~Expense() {}
    friend class FinancialReport; 
};

class FinancialReport : private Income, private Expense {
private:
    float savings;
    public:
    FinancialReport() {
        savings = 0.0;
    }

    // Method to calculate savings
    void calculateSavings() {
        float totalIncome = calculateTotalIncome();
        float totalExpense = calculateTotalExpense();
        savings = totalIncome - totalExpense;
    }

    // Method to display savings
    void displaySavings() {
        cout << "Savings: $" << savings << endl;
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

    // Setters
void setIncome() {
    string SourceOfIncome;
    float amount;
    
    cout << "Enter Your Source of Income: ";
    cin >> SourceOfIncome;
    
    // Check if the income source already exists
    for (int i = 0; i < Income::incomeCount; i++) {
        if (Income::income[i] == SourceOfIncome) {
            cout << "Income with the same description already exists." << endl;
            return;
        }
    }
    
    cout << "Enter Amount: ";
    cin >> amount;
    
    // Call the setIncome function of the Income class
    Income::setIncome(SourceOfIncome, amount);
}

    
    void setExpense() {
        string category, description;
        float amount;
        cout << "Enter Expense Category: ";
        cin >> category;
        cout << "Enter Expense Description: ";
        cin >> description;
        cout << "Enter Expense Amount: ";
        cin >> amount;
        Expense::setExpense(category, description, amount);
    }

    // Getters
    string getIncome() {
        return Income::getIncome();
    }
        float calculateTotalIncome() {
        return Income::calculateTotalIncome();
    }

    void displayAllExpenses() {
        Expense::displayAllExpenses();
    }

    float calculateTotalFromSpecifcCategory(string category) {
        return Expense::calculateTotalFromSpecifcCategory(category);
    }
    float calculateTotalExpense() {
        return Expense::calculateTotalExpense();
    }

void updateIncome() {
    cout << "Existing income options:\n";
    for (int i = 0; i < incomeCount; i++) {
        cout << i+1 << ". " << income[i] << ": $" << incomeAmount[i] << endl;
    }

    int choice;
    cout << "Select the number of the income you want to update: ";
    cin >> choice;

    if (choice >= 1 && choice <= incomeCount) {
        float newAmount;
        cout << "Enter the new amount: $";
        cin >> newAmount;

        incomeAmount[choice - 1] = newAmount;
        cout << "Income updated successfully." << endl;
    } else {
        cout << "Invalid choice. Please select a valid index from the list." << endl;
    }
}

void updateExpense() {
    cout << "Existing expense options:\n";
    for (int i = 0; i < numOfExpenses; i++) {
        cout << i+1 << ". Category: " << categories[i] << ", Description: " << descriptions[i][0] << ", Amount: $" << amounts[i][0] << endl;
    }

    int choice;
    cout << "Select the number of the expense you want to update: ";
    cin >> choice;

    if (choice >= 1 && choice <= numOfExpenses) {
        float newAmount;
        cout << "Enter the new amount: $";
        cin >> newAmount;

        amounts[choice - 1][0] = newAmount;
        cout << "Expense updated successfully." << endl;
    } else {
        cout << "Invalid choice. Please select a valid index from the list." << endl;
    }
}
    // Destructor
    ~FinancialReport() {}
};

int main() {
    // Will be incrementing as needed
    int numOfIncome=0;
    int numOfExpense=0;
    string IncomeList[numOfIncome];
    int num_of_users = 1;
    FinancialReport obj1;
            

    // Display income report and total income

    string incomeReport,category;
    FinancialReport obj[num_of_users];
    float totalIncome,totalExpense;
    char menu_choice;
    
    do{
    system("CLS");
    cout << "███████╗██╗  ██╗██████╗ ███████╗███╗   ██╗███████╗███████╗    ████████╗██████╗  █████╗  ██████╗██╗  ██╗███████╗██████╗     ███████╗██╗   ██╗███████╗████████╗███████╗███╗   ███╗" << endl;
    cout << "██╔════╝╚██╗██╔╝██╔══██╗██╔════╝████╗  ██║██╔════╝██╔════╝    ╚══██╔══╝██╔══██╗██╔══██╗██╔════╝██║ ██╔╝██╔════╝██╔══██╗    ██╔════╝╚██╗ ██╔╝██╔════╝╚══██╔══╝██╔════╝████╗ ████║" << endl;
    cout << "█████╗   ╚███╔╝ ██████╔╝█████╗  ██╔██╗ ██║███████╗█████╗         ██║   ██████╔╝███████║██║     █████╔╝ █████╗  ██████╔╝    ███████╗ ╚████╔╝ ███████╗   ██║   █████╗  ██╔████╔██║" << endl;
    cout << "██╔══╝   ██╔██╗ ██╔═══╝ ██╔══╝  ██║╚██╗██║╚════██║██╔══╝         ██║   ██╔══██╗██╔══██║██║     ██╔═██╗ ██╔══╝  ██╔══██╗    ╚════██║  ╚██╔╝  ╚════██║   ██║   ██╔══╝  ██║╚██╔╝██║" << endl;
    cout << "███████╗██╔╝ ██╗██║     ███████╗██║ ╚████║███████║███████╗       ██║   ██║  ██║██║  ██║╚██████╗██║  ██╗███████╗██║  ██║    ███████║   ██║   ███████║   ██║   ███████╗██║ ╚═╝ ██║" << endl;
    cout << "╚══════╝╚═╝  ╚═╝╚═╝     ╚══════╝╚═╝  ╚═══╝╚══════╝╚══════╝       ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝    ╚══════╝   ╚═╝   ╚══════╝   ╚═╝   ╚══════╝╚═╝     ╚═╝" << endl;
    cout << "                                                                                                                                                                                " << endl;

    cout << "\n\t-----Menu-----";
    cout << "\n1. Add User";
    cout << "\n2. Add Income";
    cout << "\n3. Update Income";
    cout << "\n4. Calculate Total Income";
    // cout << "\n4. Show Income Details";
    cout << "\n5. Add Expense";
    cout << "\n6. Show All The Expense";
    cout << "\n7. Update Expense";

    cout << "\n8. Calculate The Total Expense From Specific Category ";
    cout << "\n9. Calculate The Total Expense ";
    // cout << "\n8. Generate Financial Report";
    cout << "\n10. Display Saving";
    cout << "\n11. Exit";
    cout << "\n--Enter Your Choice : ";
    cin >> menu_choice;
    switch (menu_choice)
    {
    case '1': 
        cout<<" Placeholder \n"; 
        system("PAUSE");
        break;
    case '2':
        system("CLS");
        cout<<"---------------------------Setting Income---------------------------\n";
        obj1.setIncome();
        incomeReport = obj1.getIncome();  
        // cout<<"Press Any Key To Continue\n";
        system("PAUSE");
        break;
               case '3':
                system("CLS");
                cout << "---------------------------Update Income---------------------------\n";
                obj1.updateIncome();
                system("PAUSE");
                break;
    case '4':  
        system("CLS");
        cout<<"---------------------------Calculating Total Income---------------------------\n";
        totalIncome = obj1.calculateTotalIncome();  
    cout << "\nIncome Report:\n" << incomeReport;
    cout << "\nTotal Income: $" << totalIncome << "\n";
        // cout<<"Press Any Key To Continue\n";
        system("PAUSE");
        break;
    case '5':  
        system("CLS");
        cout<<"---------------------------Setting Expense---------------------------\n";
            obj1.setExpense();
        // cout<<"Press Any Key To Continue\n";
        system("PAUSE");
        break;
    case '6':
        system("CLS");
        cout<<"---------------------------Display All Expense---------------------------\n";
                obj1.displayAllExpenses();
        // cout<<"Exit";
        // cout<<"Press Any Key To Continue\n";
        system("PAUSE");
    break;
    case '7':
        system("CLS");
        cout<<"---------------------------Update Expense---------------------------\n";
        obj1.updateExpense();
        // system("PAUSE");
        // cout<<"Exit";
        // cout<<"Press Any Key To Continue\n";
        system("PAUSE");
    break;
    case '8':
        system("CLS");
        cout<<"---------------------------Calculate Total Expense From Specific Category---------------------------\n";
        cout << "Enter Category: ";
        cin >> category;
        cout << "Total Expenses in Category " << category << ": $" << obj1.calculateTotalFromSpecifcCategory(category) << "\n";
        // cout<<"Press Any Key To Continue\n";
        system("PAUSE");
        break;
    case '9':
        system("CLS");
        cout<<"---------------------------Calculate Total Expense---------------------------\n";
        totalExpense = obj1.calculateTotalExpense();
        cout << "Total Expense: $" << totalExpense << "\n";
        // cout<<"Press Any Key To Continue\n";
        system("PAUSE");
        break;
    case '10':
        system("CLS");
        cout<<"---------------------------Calculating & Displaying Savings---------------------------\n";
        obj1.calculateSavings(); // Calculate savings
        obj1.displaySavings();   // Display savings
        // cout<<"Press Any Key To Continue\n";
        system("PAUSE");
        break;
    case '11':
        cout<<"Thanks for using Our Program....\n";
    break;
    default:
        cout<<"Invalid Input, Please Enter any from menu\n";
        break;
    }
    }
    while(menu_choice!='11');  
    
    

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