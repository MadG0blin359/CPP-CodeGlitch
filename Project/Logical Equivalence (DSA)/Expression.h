#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Expression {
private:
    string infixExpr; // The infix expression
    string postfixExpr; // The postfix equivalent
    vector<char> variables; // List of variables in the expression
    vector<pair<string, bool>> subresults; // Subexpressions and their results

    // Helper methods
    int getPrecedence(char op);
    bool evaluate(char op, bool a, bool b = false);
    string infixToPostfix(const string& infix);
    bool evaluatePostfix(const string& expr, const vector<bool>& values);

public:
    // Constructor
    Expression(const string& expr);

    // Method to find unique variables in the expression
    void findVariables();

    // Method to generate and print the truth table
    void generateTruthTable();

    // Method to evaluate the expression for all combinations of variables
    vector<bool> evaluateAll();
};