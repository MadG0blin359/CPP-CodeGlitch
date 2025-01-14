#include <iostream>
#include <string>
using namespace std;

class User {
    protected:
    string name;
};

class FinancialReport : protected User{
    public:
    long income, expense, savings;
    
    FinancialReport(string user_name) {
        name = user_name;
    }
    
    void display() {
        cout << "\nName : " << name;
        cout << "\nIncome : " << income;
        cout << "\nExpense : " << expense;
        cout << "\nSavings : " << income - expense << endl;
    }
    
};

int main() {
    
    FinancialReport user1("Shawaiz");
    
    user1.income = 500;
    user1.expense = 150;
    
    user1.display();

    return 0;
}
