#include <iostream>
#include <string>
using namespace std;

const int Usedsize = 10;

// Base class
class User
{
private:
    string *username; // Dynamically allocated array to store usernames
    string *password; // Dynamically allocated array to store passwords
    int usercount;  // Keep track of the total users
    int capacity; // Capacity of the arrays

public:
    User()
    { // default constructor
        username = 0;
        password = 0;
        usercount = 0;
        capacity = 0;
    }
    
    User(int Usedsize) : capacity(Usedsize), usercount(0)
    { // parametrized constructor
        username = new string[Usedsize];
        password = new string[Usedsize];
    }

    ~User()
    {                      // destructor
        delete[] username; // deallocating dynamic memory
        delete[] password; // deallocating dynamic memory
    }

    bool signUp(string u, string p)
    {
        if (usercount < capacity)
        {
            username[usercount] = u;
            password[usercount] = p;
            usercount++;
            cout << "User signed up successfully!" << endl;
            return true;
        }
        else
        {
            cout << "Maximum users limit reached!" << endl;
            return false;
        }
    }

    bool signIn(string u, string p)
    {
        for (int i = 0; i < usercount; i++)
        {
            if (username[i] == u && password[i] == p)
            {
                cout << "User logged in successfully!" << endl;
                return true;
            }
        }
        cout << "Invalid username or password. Please try again." << endl;
        return false;
    }
};

class Income : virtual protected User
{
    string income[Usedsize];
    float incomeAmount[Usedsize];
    int incomeCount = 0;

public:
    // Destructor
    ~Income(){};

    void setIncome()//string SourceOfIncome, float amount)
    {
        string sourceOfIncome;
        float amount;

        cout << "Enter Source of Income: ";
        cin.ignore(); // Ignore newline character from previous input
        getline(cin, sourceOfIncome);


        for (int i = 0; i < incomeCount; i++)
        {
            if (income[i] == sourceOfIncome)
            {
                cout << "Source of Income with the already exists." << endl;
                return;
            }
        }
        cout << "Enter Amount: ";
        cin >> amount;
        if (incomeCount < Usedsize)
        {
            income[incomeCount] = sourceOfIncome;
            incomeAmount[incomeCount] = amount;
            incomeCount++;
        }
        else
        {
            cout << "Maximum income entries reached." << endl;
        }
    }

    // Getter to get income
    string getIncome()
    {
        
        string incomeString = "";
        for (int i = 0; i < incomeCount; i++)
        {
            incomeString += "Description: " + income[i] + ", Amount: " + to_string(incomeAmount[i]) + "\n";
        }
        return incomeString;
    }

    // Method to calculate total income
    float calculateTotalIncome()
    {
        float totalIncome = 0.0;
        for (int i = 0; i < incomeCount; i++)
        {
            totalIncome += incomeAmount[i];
        }
        return totalIncome;
    }
    
    void removeIncome()
    {
        if (incomeCount == 0)
        {
            cout << "No income entries exist to remove." << endl;
            return;
        }

        // Display existing income entries
        cout << "Existing Income Entries:\n";
        for (int i = 0; i < incomeCount; i++)
        {
            cout << i + 1 << ". " << income[i] << ": $" << incomeAmount[i] << endl;
        }

        // Prompt user for index of entry to remove
        int index;
        cout << "Enter the index of the income entry you want to remove: ";
        cin >> index;

        // Validate user input
        if (index >= 1 && index <= incomeCount)
        {
            // Shift remaining entries to remove the chosen one
            for (int i = index - 1; i < incomeCount - 1; i++)
            {
                income[i] = income[i + 1];
                incomeAmount[i] = incomeAmount[i + 1];
            }
            incomeCount--;
            cout << "Income entry removed successfully." << endl;
        }
        else
        {
            cout << "Invalid index. Please enter a valid index." << endl;
        }
    }
    void updateIncome()
     {
         if (incomeCount == 0) {
             cout << "No income exists." << endl;
             return;
         }

         cout << "Existing income options:\n";
         for (int i = 0; i < incomeCount; i++)
         {
             cout << i + 1 << ". " << income[i] << ": $" << incomeAmount[i] << endl;
    }

        int choice;
         cout << "Select the number of the income you want to update: ";
         cin >> choice;

         if (choice >= 1 && choice <= incomeCount)
         {
             float newAmount;
             cout << "Enter the new amount: $";
             cin >> newAmount;

             incomeAmount[choice - 1] = newAmount;
             cout << "Income updated successfully." << endl;
         }
         else
         {
             cout << "Invalid choice. Please select a valid index from the list." << endl;
         }
     }
     
         void showIncomeDetails()
    {
        if (incomeCount == 0) {
        cout << "No income entries found." << endl;
        return;
    }
        cout << "Income Details:\n";
        cout << getIncome() << endl;
    }

    friend class FinancialReport;
};

class Expense : virtual protected User
{
    string categories[Usedsize];
    string descriptions[Usedsize][10]={"0"};
    float amounts[Usedsize][10] = {0.0}; // Initializing to 0.0
    int numOfExpenses = 0;
    int descriptionCounts[Usedsize] = {0}; // Initialize descriptionCounts array

public:
   void setExpense()//string category, string description, float amount) {
    {
                string category, description;
        float amount;

        cout << "Enter Expense Category: ";
        cin.ignore(); // Ignore newline character from previous input
        getline(cin, category);

        cout << "Enter Expense Description: ";
        getline(cin, description);

        cout << "Enter Expense Amount: ";
        cin >> amount;

        int categoryIndex = -1;

        for (int i = 0; i < numOfExpenses; i++) {
            if (categories[i] == category) {
                categoryIndex = i;
                break;
            }
        }

        if (categoryIndex == -1) {
            if (numOfExpenses < Usedsize) {
                categories[numOfExpenses] = category;
                categoryIndex = numOfExpenses;
                numOfExpenses++;
            } else {
                cout << "Maximum expense entries reached." << endl;
                return;
            }
        } else {
            for (int j = 0; j < descriptionCounts[categoryIndex]; j++) {
                if (descriptions[categoryIndex][j] == description) {
                    amounts[categoryIndex][j] = amount;
                    cout << "Expense updated successfully." << endl;
                    return;
                }
            }
            cout << "Expense with a new description detected. Please use the update expense option." << endl;
            return;
        }

        if (descriptionCounts[categoryIndex] < 10) {
            descriptions[categoryIndex][descriptionCounts[categoryIndex]] = description;
            amounts[categoryIndex][descriptionCounts[categoryIndex]] = amount;
            descriptionCounts[categoryIndex]++;
        } else {
            cout << "Maximum descriptions for this category reached." << endl;
        }
    }



    string getExpenses()
    {
        string expenseString = "";
        for (int i = 0; i < numOfExpenses; i++)
        {
            expenseString += "Category: " + categories[i] + "\n";
            for (int j = 0; j < descriptionCounts[i]; j++)
            {
                expenseString += "  Description: " + descriptions[i][j] + ", Amount: " + to_string(amounts[i][j]) + "\n";
            }
        }
        return expenseString;
    }

    float calculateTotalExpense()
    {
        float totalExpense = 0.0;
        for (int i = 0; i < numOfExpenses; i++)
        {
            totalExpense += amounts[i][0];
        }
        return totalExpense;
    }

    void displayAllExpenses()
    {
        if (numOfExpenses == 0) {
            cout << "No expense exists." << endl;
            return;
        }
        cout << getExpenses();
    }

    float calculateTotalFromSpecifcCategory(string category)
    {
        float total = 0;
        for (int i = 0; i < numOfExpenses; i++)
        {
            if (categories[i] == category)
            {
                total += amounts[i][0];
            }
        }
        return total;
    }

    void removeExpense()
    {
        if (numOfExpenses == 0)
        {
            cout << "No expense entries exist to remove." << endl;
            return;
        }

        // Display existing expense entries
        cout << "Existing Expense Entries:\n";
        for (int i = 0; i < numOfExpenses; i++)
        {
            cout << i + 1 << ". " << categories[i] << ": ";
            for (int j = 0; j < descriptionCounts[i]; j++)
            {
                cout << j + 1 << ". " << descriptions[i][j] << ", $" << amounts[i][j] << " ";
            }
            cout << endl;
        }

        // Prompt user for index of category to remove
        int categoryIndex;
        cout << "Enter the index of the expense category you want to remove: ";
        cin >> categoryIndex;

        // Validate user input
        if (categoryIndex >= 1 && categoryIndex <= numOfExpenses)
        {
            // Ask user if they want to remove entire category or specific entry
            char choice;
            cout << "Do you want to remove the entire category (C) or a specific expense entry (E)? (C/E): ";
            cin >> choice;

            if (choice == 'C' || choice == 'c')
            {
                // Shift remaining categories to remove the chosen one
                for (int i = categoryIndex - 1; i < numOfExpenses - 1; i++)
                {
                    categories[i] = categories[i + 1];
                    for (int j = 0; j < descriptionCounts[i + 1]; j++)
                    {
                        descriptions[i][j] = descriptions[i + 1][j];
                        amounts[i][j] = amounts[i + 1][j];
                    }
                    descriptionCounts[i] = descriptionCounts[i + 1];
                }
                numOfExpenses--;
                cout << "Expense category removed successfully." << endl;
            }
            else if (choice == 'E' || choice == 'e')
            {
                // Prompt user for index of entry within the category to remove
                int entryIndex;
                cout << "Enter the index of the expense entry you want to remove within the category: ";
                cin >> entryIndex;

                // Validate user input
                if (entryIndex >= 1 && entryIndex <= descriptionCounts[categoryIndex - 1])
                {
                    // Shift remaining entries to remove the chosen one
                    for (int j = entryIndex - 1; j < descriptionCounts[categoryIndex - 1] - 1; j++)
                    {
                        descriptions[categoryIndex - 1][j] = descriptions[categoryIndex - 1][j + 1];
                        amounts[categoryIndex - 1][j] = amounts[categoryIndex - 1][j + 1];
                    }
                    descriptionCounts[categoryIndex - 1]--;
                    cout << "Expense entry removed successfully." << endl;
                }
                else
                {
                    cout << "Invalid entry index. Please enter a valid index." << endl;
                }
            }
            else
            {
                cout << "Invalid choice. Please enter 'C' to remove the entire category or 'E' to remove a specific entry." << endl;
            }
        }
        else
        {
            cout << "Invalid category index. Please enter a valid index." << endl;
        }
    }
        void updateExpense()
    {
        
    if (numOfExpenses == 0) {
        cout << "No expense exists." << endl;
        return;
    }
        cout << "Existing expense categories:\n";
        for (int i = 0; i < numOfExpenses; i++)
        {
            cout << i + 1 << ". " << categories[i] << endl;
        }

        int categoryChoice;
        cout << "Select the number of the expense category you want to update: ";
        cin >> categoryChoice;

        if (categoryChoice >= 1 && categoryChoice <= numOfExpenses)
        {
            int categoryIndex = categoryChoice - 1;
            cout << "Selected Category: " << categories[categoryIndex] << endl;

            for (int j = 0; j < descriptionCounts[categoryIndex]; j++)
            {
                cout << "  " << j + 1 << ". " << descriptions[categoryIndex][j] << ": $" << amounts[categoryIndex][j] << endl;
            }

            cout << "1. Add new description and amount" << endl;
            cout << "2. Update existing description amount" << endl;
            int choice;
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1)
            {
                if (descriptionCounts[categoryIndex] < 10)
                {
                    string newDescription;
                    float newAmount;
                    cout << "Enter new description: ";
                    cin.ignore();
                    getline(cin, newDescription);
                    cout << "Enter new amount: $";
                    cin >> newAmount;
                    descriptions[categoryIndex][descriptionCounts[categoryIndex]] = newDescription;
                    amounts[categoryIndex][descriptionCounts[categoryIndex]] = newAmount;
                    descriptionCounts[categoryIndex]++;
                    cout << "New description and amount added successfully." << endl;
                }
                else
                {
                    cout << "Maximum descriptions for this category reached." << endl;
                }
            }
            else if (choice == 2)
            {
                int descChoice;
                cout << "Select the number of the description you want to update: ";
                cin >> descChoice;

                if (descChoice >= 1 && descChoice <= descriptionCounts[categoryIndex])
                {
                    float newAmount;
                    cout << "Enter new amount: $";
                    cin >> newAmount;
                    amounts[categoryIndex][descChoice - 1] = newAmount;
                    cout << "Description amount updated successfully." << endl;
                }
                else
                {
                    cout << "Invalid choice. Please select a valid index from the list." << endl;
                }
            }
            else
            {
                cout << "Invalid choice. Please select a valid option." << endl;
            }
        }
        else
        {
            cout << "Invalid choice. Please select a valid category number." << endl;
        }
    }

    // Destructor
    ~Expense() {}
    friend class FinancialReport;
};

class FinancialReport : private Income, private Expense
{
private:
    User users;
    float savings;

public:
    FinancialReport(int capacity) : users(capacity), savings(0.0) {}

    void signUp()
    {
        string user, pass;
        cout << "Enter Username: ";
        cin >> user;
        cout << "Enter Password: ";
        cin >> pass;
        users.signUp(user, pass);
    }

    bool signIn()
    {
        string user, pass;
        cout << "Enter Username: ";
        cin >> user;
        cout << "Enter Password: ";
        cin >> pass;
        return users.signIn(user, pass);
    }

    void addIncome()
    {
        setIncome();//sourceOfIncome, amount);
    }

    void addExpense()
    {
        setExpense();//category, description, amount);
    }

    void generateFinancialReport()
    {
        if (incomeCount == 0 && numOfExpenses == 0) {
            cout << "No income or expense found. Cannot generate financial report.\n" ;
        return;
    }
        // Print Income Details
        cout << "----- Income Details -----" << endl;
        cout << getIncome() << endl;

        // Print Expense Details
        cout << "----- Expense Details -----" << endl;
        displayAllExpenses();
        

        // Calculate and Print Savings
        float totalIncome = calculateTotalIncome();
        float totalExpense = calculateTotalExpense();
        float savings = totalIncome - totalExpense;

        cout << "----- Financial Report -----" << endl;
        cout << "Total Income: $" << totalIncome << endl;
        cout << "Total Expense: $" << totalExpense << endl;
        cout << "Savings: $" << savings << endl;
    }

    void alertsAndNotifications(float savings, float budgetLimit)
    {
        if (savings < 0)
        {
            cout << "Alert: Your expenses have exceeded your income!" << endl;
        }
        else if (savings > budgetLimit)
        {
            cout << "Notification: Congratulations! You have achieved your savings goal." << endl;
        }
        else if (savings < budgetLimit * 0.25)
        {
            cout << "Notification: You are approaching your budget limit. Review your expenses." << endl;
        }
        else
        {
            cout << "No alerts or notifications at this time." << endl;
        }
    }

    void setGoals(float &savingsGoal, float &expenseTarget)
    {
        cout << "Enter your savings goal: $";
        cin >> savingsGoal;
        cout << "Enter your monthly expense target: $";
        cin >> expenseTarget;
        cout << "Goals set successfully!" << endl;
    }

    void taxManagement(float income, float expenses)
    {
        const float taxRate = 0.15; // Assume a tax rate of 15%
        float taxableIncome = income - expenses;

        if (taxableIncome > 0)
        {
            float taxAmount = taxableIncome * taxRate;
            cout << "Taxable Income: $" << taxableIncome << endl;
            cout << "Tax Amount (15%): $" << taxAmount << endl;
            cout << "Net Income after Tax: $" << (income - taxAmount) << endl;
        }
        else
        {
            cout << "No taxable income. No taxes apply." << endl;
        }
    }

    // Getters
    string getIncome()
    {
        return Income::getIncome();
    }
    float calculateTotalIncome()
    {
        return Income::calculateTotalIncome();
    }

    void displayAllExpenses()
    {
        Expense::displayAllExpenses();
    }

    float calculateTotalFromSpecifcCategory(string category)
    {
        return Expense::calculateTotalFromSpecifcCategory(category);
    }
    float calculateTotalExpense()
    {
        return Expense::calculateTotalExpense();
    }
    void updateIncome()
    {
        Income::updateIncome();
    }
    void removeIncome(){
        Income::removeIncome();
    }
    void showIncomeDetails(){
        Income::showIncomeDetails();
    }
    void updateExpense(){
        Expense::updateExpense();
    }
    void removeExpense(){
        Expense::removeExpense();
    }

    // Destructor
    ~FinancialReport() {}

 
};

int main()
{
    string username, password;
    char menu_choice;
    FinancialReport Report(Usedsize);
    bool loggedIn = false;

    do
    {
        system("CLS");
        // cout << "███████╗██╗  ██╗██████╗ ███████╗███╗   ██╗███████╗███████╗    ████████╗██████╗  █████╗  ██████╗██╗  ██╗███████╗██████╗     ███████╗██╗   ██╗███████╗████████╗███████╗███╗   ███╗" << endl;
        // cout << "██╔════╝╚██╗██╔╝██╔══██╗██╔════╝████╗  ██║██╔════╝██╔════╝    ╚══██╔══╝██╔══██╗██╔══██╗██╔════╝██║ ██╔╝██╔════╝██╔══██╗    ██╔════╝╚██╗ ██╔╝██╔════╝╚══██╔══╝██╔════╝████╗ ████║" << endl;
        // cout << "█████╗   ╚███╔╝ ██████╔╝█████╗  ██╔██╗ ██║███████╗█████╗         ██║   ██████╔╝███████║██║     █████╔╝ █████╗  ██████╔╝    ███████╗ ╚████╔╝ ███████╗   ██║   █████╗  ██╔████╔██║" << endl;
        // cout << "██╔══╝   ██╔██╗ ██╔═══╝ ██╔══╝  ██║╚██╗██║╚════██║██╔══╝         ██║   ██╔══██╗██╔══██║██║     ██╔═██╗ ██╔══╝  ██╔══██╗    ╚════██║  ╚██╔╝  ╚════██║   ██║   ██╔══╝  ██║╚██╔╝██║" << endl;
        // cout << "███████╗██╔╝ ██╗██║     ███████╗██║ ╚████║███████║███████╗       ██║   ██║  ██║██║  ██║╚██████╗██║  ██╗███████╗██║  ██║    ███████║   ██║   ███████║   ██║   ███████╗██║ ╚═╝ ██║" << endl;
        // cout << "╚══════╝╚═╝  ╚═╝╚═╝     ╚══════╝╚═╝  ╚═══╝╚══════╝╚══════╝       ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝    ╚══════╝   ╚═╝   ╚══════╝   ╚═╝   ╚══════╝╚═╝     ╚═╝" << endl;
        // cout << "                                                                                                                                                                                " << endl;

        cout << "\n\n-----Main Menu-----"
             << "\n1. Sign In"
             << "\n2. Sign Up"
             << "\n3. Exit"
             << "\nEnter Your Choice: ";
        cin >> menu_choice;

        switch (menu_choice)
        {
        case '1':
            cout << "\n-------------"
                 << "\n   Sign In"
                 << "\n-------------\n";
            loggedIn = Report.signIn();
            break;

        case '2':
            cout << "\n-------------"
                 << "\n   Sign Up"
                 << "\n-------------\n";
            Report.signUp();
            continue;

        case '3':
            cout << "\n\t-----Exiting Program-----" << endl;
            return 0; // End program

        default:
            cout << "\n\t-----Invalid Input!-----" << endl;
            continue;
        }

        if (loggedIn == true)
        {

            do
            {
                cout << "\n\t-----Menu-----"
                     << "\na. Add Income"
                     << "\nb. Remove Income"
                     << "\nc. Update Income"
                     << "\nd. Show Income Details"
                     << "\ne. Add Expense"
                     << "\nf. Remove Expense"
                     << "\ng. Update Expense"
                     << "\nh. Show Expense Details"
                     << "\ni. Generate Financial Report"
                     << "\nj. Set Goals"
                     << "\nk. Alerts and Notifications"
                     << "\nl. Tax Management"
                     << "\nm. Sign Out"
                     << "\n--Enter Your Choice : ";
                cin >> menu_choice;

                switch (menu_choice)
                {
                case 'a':
                    system("CLS");
                    cout << "\n-------------"
                         << "\n  Add Income"
                         << "\n-------------\n";
                    Report.addIncome();

                    system("PAUSE");
                    break;
                case 'b':
                    system("CLS");
                    cout << "\n-------------"
                         << "\n  Remove Income"
                         << "\n-------------\n";
                    Report.removeIncome();
                    system("PAUSE");
                    break;

                case 'c':
                    system("CLS");
                    cout << "\n-------------"
                         << "\n  Update Income"
                         << "\n-------------\n";
                    Report.updateIncome();

                    system("PAUSE");
                    break;

                case 'd':
                    system("CLS");
                    cout << "\n-------------"
                         << "\n  Income Details"
                         << "\n-------------\n";
                    Report.showIncomeDetails();

                    system("PAUSE");
                    break;

                case 'e':
                    system("CLS");
                    cout << "\n-------------"
                         << "\n  Add Expense"
                         << "\n-------------\n";
                    Report.addExpense();

                    system("PAUSE");
                    break;

                case 'f':
                    system("CLS");
                    cout << "\n-------------"
                         << "\n  Update Expense"
                         << "\n-------------\n";
                    Report.removeExpense();
                    system("PAUSE");
                    break;

                case 'g':
                    system("CLS");
                    cout << "\n-------------"
                         << "\n  Update Expense"
                         << "\n-------------\n";
                    Report.updateExpense();
                    system("PAUSE");
                    break;

                case 'h':
                    system("CLS");
                    cout << "\n-------------"
                         << "\n  Expense Details"
                         << "\n-------------\n";
                    Report.displayAllExpenses();

                    system("PAUSE");
                    break;

                case 'i':
                    system("CLS");
                    cout << "\n-------------"
                         << "\n  Financial Report"
                         << "\n-------------\n";
                    Report.generateFinancialReport();

                    system("PAUSE");
                    break;

                case 'j':
                    system("CLS");
                    cout << "\n-------------"
                         << "\n  Set Goals"
                         << "\n-------------\n";
                    float savingsGoal, expenseTarget;
                    Report.setGoals(savingsGoal, expenseTarget);

                    system("PAUSE");
                    break;

                case 'k':
                    system("CLS");
                    cout << "\n-------------"
                         << "\n  Alerts and Notifications"
                         << "\n-------------\n";
                    float savings, budgetLimit;
                    // Calculate savings and budgetLimit based on your program's logic
                    savings = Report.calculateTotalIncome() - Report.calculateTotalExpense();
                    cout << "Enter your budget limit: $";
                    cin >> budgetLimit;
                    Report.alertsAndNotifications(savings, budgetLimit);
                    system("PAUSE");
                    break;

                case 'l':
                    system("CLS");
                    cout << "\n-------------"
                         << "\n  Tax Management"
                         << "\n-------------\n";
                    float income, expenses;
                    // Get income and expenses values from your program's logic
                    cout << "Enter your income: $";
                    cin >> income;
                    cout << "Enter your expenses: $";
                    cin >> expenses;
                    Report.taxManagement(income, expenses);
                    system("PAUSE");
                    break;

                case 'm':
                    cout << "\n\t-----Thanks for using Our Program-----\n";
                    break;

                default:
                    cout << "\n\t-----Invalid Input!-----\n";
                    break;
                }

            } while (menu_choice != 'm');
        }

        else
        {
            cout << "Sign In to Access the Menu\n";
        }

    }

    while (menu_choice != '3');

    return 0;
}