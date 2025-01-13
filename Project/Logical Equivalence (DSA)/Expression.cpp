#include "Expression.h"
using namespace std;

// Constructor to initialize expression and convert to postfix
Expression::Expression(const string& expr) : infixExpr(expr) {
    postfixExpr = infixToPostfix(infixExpr);
    findVariables();
}

// Helper function to get the precedence of operators
int Expression::getPrecedence(char op) {
    if (op == '!') return 3; // NOT operator has the highest precedence
    if (op == '&' || op == '|') return 2; // AND and OR
    if (op == '>' || op == '^') return 1; // Implies and Biconditional
    return 0; // Parentheses '('
}

// Function to evaluate an operator with operands
bool Expression::evaluate(char op, bool a, bool b) {
    if (op == '!') return !a; // NOT
    if (op == '&') return a && b; // AND
    if (op == '|') return a || b; // OR
    if (op == '>') return !a || b; // Implies
    if (op == '^') return a == b; // Biconditional
    return false;
}

// Convert infix expression to postfix notation
string Expression::infixToPostfix(const string& infix) {
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

// Evaluate a postfix expression
bool Expression::evaluatePostfix(const string& expr, const vector<bool>& values) {
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

// Find unique variables in the expression
void Expression::findVariables() {
    for (char ch : infixExpr) {
        if (isalpha(ch) && find(variables.begin(), variables.end(), ch) == variables.end()) {
            variables.push_back(ch);
        }
    }
}

// Generate the truth table for the expression
void Expression::generateTruthTable() {
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

// Evaluate the expression for all combinations of variables
vector<bool> Expression::evaluateAll() {
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