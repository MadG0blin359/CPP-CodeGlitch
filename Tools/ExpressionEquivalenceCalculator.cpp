#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class to handle logical expressions
class Expression {
private:
    string infixExpr; // The infix expression
    string postfixExpr; // The postfix equivalent
    vector<char> variables; // List of variables in the expression
    vector<pair<string, bool>> subresults; // Subexpressions and their results

    // Function to get the priority of operators
    int getPrecedence(char op) {
        if (op == '!') return 3; // NOT operator has the highest precedence
        if (op == '&' || op == '|') return 2; // AND and OR
        if (op == '>' || op == '^') return 1; // Implies and Biconditional
        return 0; // Parentheses '('
    }

    // Function to evaluate an operator with operands
    bool evaluate(char op, bool a, bool b = false) {
        if (op == '!') return !a; // NOT
        if (op == '&') return a && b; // AND
        if (op == '|') return a || b; // OR
        if (op == '>') return !a || b; // Implies
        if (op == '^') return a == b; // Biconditional
        return false;
    }

    // Function to convert infix expression to postfix
    string infixToPostfix(const string& infix) {
        string postfix = "";
        vector<char> stack;

        for (char ch : infix) {
            if (isalpha(ch)) {
                postfix += ch; // Append variables directly to postfix
            }
            else if (ch == '(') {
                stack.push_back(ch);
            }
            else if (ch == ')') {
                while (!stack.empty() && stack.back() != '(') {
                    postfix += stack.back();
                    stack.pop_back();
                }
                stack.pop_back(); // Remove '('
            }
            else { // Operators
                while (!stack.empty() && getPrecedence(stack.back()) >= getPrecedence(ch)) {
                    postfix += stack.back();
                    stack.pop_back();
                }
                stack.push_back(ch);
            }
        }

        while (!stack.empty()) {
            postfix += stack.back();
            stack.pop_back();
        }

        return postfix;
    }

    // Function to evaluate a postfix expression and store subresults
    bool evaluatePostfix(const string& expr, const vector<bool>& values) {
        vector<bool> stack; // Stack to store intermediate results
        vector<string> subStack; // Stack to store subexpression strings

        for (char ch : expr) {
            if (isalpha(ch)) { // Check if it's a variable
                for (size_t i = 0; i < variables.size(); i++) {
                    if (variables[i] == ch) {
                        stack.push_back(values[i]); // Push variable value
                        subStack.push_back(string(1, ch));
                        break;
                    }
                }
            }
            else if (ch == '!') { // Unary operator
                bool top = stack.back();
                stack.pop_back();
                string subTop = subStack.back();
                subStack.pop_back();

                bool result = !top;
                string subexpr = "!" + subTop;

                stack.push_back(result);
                subStack.push_back(subexpr);
                subresults.push_back({ subexpr, result });
            }
            else { // Binary operators
                bool b = stack.back(); stack.pop_back();
                bool a = stack.back(); stack.pop_back();

                string subB = subStack.back(); subStack.pop_back();
                string subA = subStack.back(); subStack.pop_back();

                bool result = evaluate(ch, a, b);
                string subexpr = "(" + subA + ch + subB + ")";

                stack.push_back(result);
                subStack.push_back(subexpr);
                subresults.push_back({ subexpr, result });
            }
        }

        return stack.back();
    }

public:
    // Constructor
    Expression(const string& expr) : infixExpr(expr) {
        postfixExpr = infixToPostfix(infixExpr);
        findVariables();
    }

    // Function to find unique variables in the expression
    void findVariables() {
        for (char ch : infixExpr) {
            if (isalpha(ch) && find(variables.begin(), variables.end(), ch) == variables.end()) {
                variables.push_back(ch);
            }
        }
    }

    // Function to generate and print the truth table
    void generateTruthTable() {
        int rows = 1 << variables.size(); // Total combinations = 2^n
        vector<bool> values(variables.size());
        
        // Print header
        cout << "\n";
        for (char var : variables) {
            cout << var << " ";
        }
        cout << "| ";

        vector<string> subexpressions;
        evaluatePostfix(postfixExpr, vector<bool>(variables.size(), false));
        for (const auto& sub : subresults) {
            subexpressions.push_back(sub.first);
            cout << sub.first << " | ";
        }
        cout << "\n" << string(70, '-') << "\n";

        // Loop for all possible combinations of truth values
        for (int i = 0; i < rows; i++) {
            vector<pair<string, bool>> currentSubresults;

            // Assign truth values
            for (size_t j = 0; j < variables.size(); j++) {
                values[j] = (i & (1 << j)) != 0;
                cout << values[j] << " ";
            }

            cout << "| ";
            subresults.clear();
            evaluatePostfix(postfixExpr, values);

            for (const auto& subexpr : subexpressions) {
                for (const auto& result : subresults) {
                    if (result.first == subexpr) {
                        cout << result.second << "     | ";
                        break;
                    }
                }
            }
            cout << subresults.back().second << "\n";
        }
    }

    // Function to evaluate the expression for all combinations of variables
    vector<bool> evaluateAll() {
        int rows = 1 << variables.size(); // Total combinations = 2^n
        vector<bool> results;

        for (int i = 0; i < rows; i++) {
            vector<bool> values(variables.size());
            for (size_t j = 0; j < variables.size(); j++) {
                values[j] = (i & (1 << j)) != 0;
            }
            results.push_back(evaluatePostfix(postfixExpr, values));
        }

        return results;
    }
};

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
