#include <iostream>
#include <string>
#include<cstdio>
using namespace std;
const int Usedsize = 10;

// Base class
class User
{
private:
    string *username;
    string *password;
    int usercount;
    int capacity; 

public:
    User()
    { 
        username = 0;
        password = 0;
        usercount = 0;
        capacity = 0;
    }
    User(int Usedsize) : capacity(Usedsize), usercount(0)
    { 

        username = new string[Usedsize];
        password = new string[Usedsize];
    }
// destructor
    ~User()
    {                      
        delete[] username; // deallocating dynamic memory
        delete[] password; // deallocating dynamic memory
    }
// signUp function
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
//signIn Function
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
// income class
class Income 
{
    string income[Usedsize];
    float incomeAmount[Usedsize];
    int incomeCount = 0;


public:
    // Destructor
    ~Income(){};
// function to set income
    void setIncome() 
    {
        string sourceOfIncome;
        float amount;

        cout << "Enter Source of Income: ";
        cin.ignore(); 
        getline(cin, sourceOfIncome);

        for (int i = 0; i < incomeCount; i++)
        {
            if (income[i] == sourceOfIncome)
            {
                cout << "Source of Income with the already exists." << endl;
                return;
            }
        }
        do{
        cout << "Enter Amount: ";
        cin >> amount;
        if (amount<0)
        {
            cout<<"amount cant be less than zero\n";
        }
        }
        while (amount<0);
        
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

    // Function to get Income
    string getIncome()
    {

        string incomeString = "";
        for (int i = 0; i < incomeCount; i++)
        {
            incomeString += "Description: " + income[i] + ", Amount: " + to_string(incomeAmount[i]) + "\n";
        }
        return incomeString;
    }

    // Function ot calculate total income
    float calculateTotalIncome()
    {
        float totalIncome = 0.0;
        for (int i = 0; i < incomeCount; i++)
        {
            totalIncome += incomeAmount[i];
        }
        return totalIncome;
    }
    // function to remove Income
    void removeIncome()
    {
        if (incomeCount == 0)
        {
            cout << "No income exist to remove." << endl;
            return;
        }

        cout << "Existing Income :\n";
        for (int i = 0; i < incomeCount; i++)
        {
            cout << i + 1 << ". " << income[i] << ": $" << incomeAmount[i] << endl;
        }

        int index;
        cout << "Enter the number of the income  you want to remove: ";
        cin >> index;

        
        if (index >= 1 && index <= incomeCount)
        {

            for (int i = index - 1; i < incomeCount - 1; i++)
            {
                income[i] = income[i + 1];
                incomeAmount[i] = incomeAmount[i + 1];
            }
            incomeCount--;
            cout << "Income removed successfully." << endl;
        }
        else
        {
            cout << "Invalid number. Please enter a valid number." << endl;
        }
    }
    void updateIncome()
    {
        if (incomeCount == 0)
        {
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
            do{

            cout << "Enter the new amount: $";
            cin >> newAmount;

            if(newAmount<0){
                cout<<"Amount Cannot be less than Zero"<<endl;
            }

            }

            while(newAmount<0);

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
        if (incomeCount == 0)
        {
            cout << "No income entries found." << endl;
            return;
        }
        cout << "Income Details:\n";
        cout << getIncome() << endl;
    }

    friend class FinancialReport;
};

class Expense
{
    string categories[Usedsize];
    string descriptions[Usedsize][10] = {"0"};
    float amounts[Usedsize][10] = {0.0};
    int numOfExpenses = 0;
    int descriptionCounts[Usedsize] = {0}; 

public:
    void setExpense() 
    {
        string category, description;
        float amount;

        cout << "Enter Expense Category: ";
        cin.ignore(); 
        getline(cin, category);

        cout << "Enter Expense Description: ";
        getline(cin, description);
    do{
        cout << "Enter Expense Amount: ";
        cin >> amount;
    if (amount<0)
    {
        cout<<"Amount can't be less than zero\nPlease enter correct amount\n"<<endl;
    }
    
    }
    while(amount<0);
        int categoryIndex = -1;

        for (int i = 0; i < numOfExpenses; i++)
        {
            if (categories[i] == category)
            {
                categoryIndex = i;
                break;
            }
        }

        if (categoryIndex == -1)
        {
            if (numOfExpenses < Usedsize)
            {
                categories[numOfExpenses] = category;
                categoryIndex = numOfExpenses;
                numOfExpenses++;
            }
            else
            {
                cout << "Maximum expense entries reached." << endl;
                return;
            }
        }
        else
        {
            for (int j = 0;j <descriptionCounts[categoryIndex]; j++)
            {
                if (descriptions[categoryIndex][j] == description)
                {
                    amounts[categoryIndex][j] = amount;
                    cout << "Expense updated successfully." << endl;
                    return;
                }
            }
            cout << "Expense with a new description detected. Please use the update expense option." << endl;
            return;
        }

        if (descriptionCounts[categoryIndex] < 10)
        {
            descriptions[categoryIndex][descriptionCounts[categoryIndex]] = description;
            amounts[categoryIndex][descriptionCounts[categoryIndex]] = amount;
            descriptionCounts[categoryIndex]++;
        }
        else
        {
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
        if (numOfExpenses == 0)
        {
            cout << "No expense exists." << endl;
            return;
        }
        cout << getExpenses();
    }


    void removeExpense()
    {
        if (numOfExpenses == 0)
        {
            cout << "No expense entries exist to remove." << endl;
            return;
        }

        // Display existing expenses
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

        int categoryIndex;
        cout << "Enter the index of the expense category you want to remove: ";
        cin >> categoryIndex;

        if (categoryIndex >= 1 && categoryIndex <= numOfExpenses)
        {
            char choice;
            cout << "Do you want to remove the entire category (C) or a specific expense entry (E)? (C/E): ";
            cin >> choice;

            if (choice == 'C' || choice == 'c')
            {
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
                int expensenumber;
                cout << "Enter the number of the expense entry you want to remove within the category: ";
                cin >> expensenumber;

                if (expensenumber >= 1 && expensenumber <= descriptionCounts[categoryIndex - 1])
                {

                    for (int j = expensenumber - 1; j < descriptionCounts[categoryIndex - 1] - 1; j++)
                    {
                        descriptions[categoryIndex - 1][j] = descriptions[categoryIndex - 1][j + 1];
                        amounts[categoryIndex - 1][j] = amounts[categoryIndex - 1][j + 1];
                    }
                    descriptionCounts[categoryIndex - 1]--;
                    cout << "Expense entry removed successfully." << endl;
                }
                else
                {
                    cout << "Invalid entry number. Please enter a valid number." << endl;
                }
            }
            else
            {
                cout << "Invalid choice. Please enter 'C' to remove the entire category or 'E' to remove a specific entry." << endl;
            }
        }
        else
        {
            cout << "Invalid category number. Please enter a valid number." << endl;
        }
    }
    void updateExpense()
    {

        if (numOfExpenses == 0)
        {
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
                    do{

                    cout << "Enter new description: ";
                    cin.ignore();
                    getline(cin, newDescription);
                    
                    cout << "Enter new amount: $";
                    cin >> newAmount;

                    if(newAmount<0){
                        cout<<"Amount Cannot be less than zero"<<endl;
                    }

                    }

                    while(newAmount<0);

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
        setIncome(); 
    }

    void addExpense()
    {
        setExpense(); 
    }

    void generateFinancialReport()
    {
       if (incomeCount == 0 && numOfExpenses == 0)
        {
            cout << "No income or expense found. Cannot generate financial report.\n";
            return;
        }
        
        // Print Income Details
        cout << "----- Income Details -----" << endl;
            if(incomeCount == 0){
            cout<<"No Income Entries Found"<<endl;
        }
        cout << getIncome() << endl;

        // Print Expense Details
        cout << "----- Expense Details -----" << endl;
          if(numOfExpenses == 0){
            cout<<"No Expense Entries Found\n"<<endl;
        }
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
        if(savings < 0)
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

        do{
        cout << "Enter your savings goal: $";
        cin >> savingsGoal;
        cout << "Enter your monthly expense target: $";
        cin >> expenseTarget;

        if(savingsGoal<0 || expenseTarget<0){
            cout<<"Savings Goals or Expense Target cannot be less than Zero"<<endl;
        }

        } while(savingsGoal<0 || expenseTarget<0);
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

    float calculateTotalExpense()
    {
        return Expense::calculateTotalExpense();
    }

    void updateIncome()
    {
        Income::updateIncome();
    }
    void removeIncome()
    {
        Income::removeIncome();
    }
    void showIncomeDetails()
    {
        Income::showIncomeDetails();
    }
    void updateExpense()
    {
        Expense::updateExpense();
    }
    void removeExpense()
    {
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
    system("clear");
        cout << "███████╗██╗  ██╗██████╗ ███████╗███╗   ██╗███████╗███████╗    ████████╗██████╗  █████╗  ██████╗██╗  ██╗███████╗██████╗     ███████╗██╗   ██╗███████╗████████╗███████╗███╗   ███╗" << endl;
        cout << "██╔════╝╚██╗██╔╝██╔══██╗██╔════╝████╗  ██║██╔════╝██╔════╝    ╚══██╔══╝██╔══██╗██╔══██╗██╔════╝██║ ██╔╝██╔════╝██╔══██╗    ██╔════╝╚██╗ ██╔╝██╔════╝╚══██╔══╝██╔════╝████╗ ████║" << endl;
        cout << "█████╗   ╚███╔╝ ██████╔╝█████╗  ██╔██╗ ██║███████╗█████╗         ██║   ██████╔╝███████║██║     █████╔╝ █████╗  ██████╔╝    ███████╗ ╚████╔╝ ███████╗   ██║   █████╗  ██╔████╔██║" << endl;
        cout << "██╔══╝   ██╔██╗ ██╔═══╝ ██╔══╝  ██║╚██╗██║╚════██║██╔══╝         ██║   ██╔══██╗██╔══██║██║     ██╔═██╗ ██╔══╝  ██╔══██╗    ╚════██║  ╚██╔╝  ╚════██║   ██║   ██╔══╝  ██║╚██╔╝██║" << endl;
        cout << "███████╗██╔╝ ██╗██║     ███████╗██║ ╚████║███████║███████╗       ██║   ██║  ██║██║  ██║╚██████╗██║  ██╗███████╗██║  ██║    ███████║   ██║   ███████║   ██║   ███████╗██║ ╚═╝ ██║" << endl;
        cout << "╚══════╝╚═╝  ╚═╝╚═╝     ╚══════╝╚═╝  ╚═══╝╚══════╝╚══════╝       ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝    ╚══════╝   ╚═╝   ╚══════╝   ╚═╝   ╚══════╝╚═╝     ╚═╝" << endl;
        cout << "                                                                                                                                                                                " << endl;

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
            cout << "Press Enter to continue...";
            getchar();
            break;

        case '2':
            cout << "\n-------------"
                 << "\n   Sign Up"
                 << "\n-------------\n";
            Report.signUp();
              cout << "Press Enter to continue...";
             getchar(); 
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
                    system("clear");
                    cout << "\n-------------"
                         << "\n  Add Income"
                         << "\n-------------\n";
                    Report.addIncome();

                    cout << "Press Enter to continue...";
                    getchar();
                    break;
                case 'b':
                    system("clear");
                    cout << "\n-------------"
                         << "\n  Remove Income"
                         << "\n-------------\n";
                    Report.removeIncome();
                    cout << "Press Enter to continue...";
                    getchar();
                    
                    break;

                case 'c':
                    system("clear");
                    cout << "\n-------------"
                         << "\n  Update Income"
                         << "\n-------------\n";
                    Report.updateIncome();

                    
                    cout << "Press Enter to continue...";
                    getchar();
                    break;

                case 'd':
                    system("clear");
                    cout << "\n-------------"
                         << "\n  Income Details"
                         << "\n-------------\n";
                    Report.showIncomeDetails();

                    cout << "Press Enter to continue...";
                    getchar();

                    break;

                case 'e':
                    system("clear");
                    cout << "\n-------------"
                         << "\n  Add Expense"
                         << "\n-------------\n";
                    Report.addExpense();

                    cout << "Press Enter to continue...";
                    getchar();
                    
                    break;

                case 'f':
                    system("clear");
                    cout << "\n-------------"
                         << "\n  Update Expense"
                         << "\n-------------\n";
                    Report.removeExpense();
                    cout << "Press Enter to continue...";
                    getchar();
                    
                    break;

                case 'g':
                    system("clear");
                    cout << "\n-------------"
                         << "\n  Update Expense"
                         << "\n-------------\n";
                    Report.updateExpense();
                    cout << "Press Enter to continue...";
                    getchar();
                    
                    break;

                case 'h':
                    system("clear");
                    cout << "\n-------------"
                         << "\n  Expense Details"
                         << "\n-------------\n";
                    Report.displayAllExpenses();

                    cout << "Press Enter to continue...";
                    getchar();
                    
                    break;

                case 'i':
                    system("clear");
                    cout << "\n-------------"
                         << "\n  Financial Report"
                         << "\n-------------\n";
                    Report.generateFinancialReport();

                    cout << "Press Enter to continue...";
                    getchar();
                    
                    break;

                case 'j':
                    system("clear");
                    cout << "\n-------------"
                         << "\n  Set Goals"
                         << "\n-------------\n";
                    float savingsGoal, expenseTarget;
                    Report.setGoals(savingsGoal, expenseTarget);

                    cout << "Press Enter to continue...";
                    getchar();
                    
                    break;

                case 'k':
                    system("clear");
                    cout << "\n-------------"
                         << "\n  Alerts and Notifications"
                         << "\n-------------\n";
                    float savings, budgetLimit;
                    // Calculate savings and budgetLimit based on your program's logic
                    savings = Report.calculateTotalIncome() - Report.calculateTotalExpense();
                    
                    do{

                    
                    cout << "Enter your budget limit: $";
                    cin >> budgetLimit;
                    if(budgetLimit<0){
                        cout<<"Budget Limit cannot be zero "<<endl;
                    }
                    }
                    while(budgetLimit<0);

                    Report.alertsAndNotifications(savings, budgetLimit);
                    cout << "Press Enter to continue...";
                    getchar();
                    
                    break;

                case 'l':
                    system("clear");
                    cout << "\n-------------"
                         << "\n  Tax Management"
                         << "\n-------------\n";
                    float income, expenses;
                    // Get income and expenses values from your program's logic
                   do{
                    cout << "Enter your income: $";
                    cin >> income;
                    cout << "Enter your expenses: $";
                    cin >> expenses;

                    if(income < 0 || expenses < 0){
                        cout<<"Income or Expense cannot be zero "<<endl;
                    }
                   
                   }

                    while(income<0 || expenses<0);
                    Report.taxManagement(income, expenses);
                    cout << "Press Enter to continue...";
                    getchar();
                    
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
