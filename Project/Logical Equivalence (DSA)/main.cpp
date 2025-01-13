#include <iostream>
#include <vector>
#include <string>
#include "Expression.h"
using namespace std;

int main() {
    cout << "Instructions:\n";
    cout << "Use '!' for NOT operations\n";
    cout << "Use '&' for AND operations\n";
    cout << "Use '|' for OR operations\n";
    cout << "Use '>' for IMPLIES operations\n";
    cout << "Use '^' for BICONDITIONAL operations\n";
    cout << "Use only () parenthesis\n\n";

    string expr1, expr2;
    cout << "Enter Expression 1: ";
    cin >> expr1;
    cout << "Enter Expression 2: ";
    cin >> expr2;

    Expression exprObj1(expr1);
    Expression exprObj2(expr2);

    // Generate truth tables
    exprObj1.generateTruthTable();
    exprObj2.generateTruthTable();

    // Evaluate both expressions
    vector<bool> results1 = exprObj1.evaluateAll();
    vector<bool> results2 = exprObj2.evaluateAll();

    // Check if the results are logically equivalent
    bool equivalent = (results1 == results2);

    // Print the result
    cout << "\nBoth expressions are ";
    if (!equivalent)
        cout << "NOT ";
    cout << "logically equivalent.\n";

    system("pause");
    return 0;
}