#include <iostream>
using namespace std;

class Node {
	Node* next;
	char data;
public:
	Node(int d) : data(d), next(NULL) {}

	friend class Stack;
};

class Stack {
	Node* top;
public:
	Stack() : top(NULL) {}

	void push(char ch);
	char pop();
	bool isEmpty();
	bool isOperand(char);
	int Precedence(char);
	string infixToPostfix(string);
	string infixToPrefix(string);
	void evaluatePostfix(string);
	void evaluatePrefix(string);
};

// Function to push elements into the stack
void Stack::push(char ch) {
	Node* newptr = new Node(ch);
	if (isEmpty()) {
		top = newptr;
		return;
	}

	newptr->next = top;
	top = newptr;
}

// Function to pop elements from the top
char Stack::pop() {
	if (isEmpty()) {
		cout << "\nList is Empty!\n";
		return '\0';
	}

	Node* temp = top;
	char returnVal = top->data;
	top = top->next;
	delete temp;
	return returnVal;
}

// Function to check if the stack is empty
bool Stack::isEmpty() {
	return (top == NULL);
}

// Function to check if the character is operand
bool Stack::isOperand(char ch) {
	return (ch >= '0' && ch <= '9');
}

// Function to check the precedence of the operator
int Stack::Precedence(char op) {
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/' || op == '%')
		return 2;

	return 0;
}

// Function to convert infix to postfix
string Stack::infixToPostfix(string infix) {
	string postfix = "";
	int p1;				// Precedence
	char temp;

	cout << "\nSymbols :\n";

	for (char token : infix) {

		if (token == '(') {
			cout << token << endl;
			push(token);
		}

		else if (token == ')') {
			while (top->data != '(') {
				cout << token << endl;
				temp = pop();
				postfix += temp;
			}
			pop();		// Remove the opening bracket
		}

		else if (!isOperand(token)) {
			cout << token << endl;

			p1 = Precedence(token);

			while (!isEmpty() && Precedence(top->data) >= p1) {  // Pop operators of higher or equal precedence
				temp = pop();
				postfix += temp;
			}
			push(token);  // Push current operator
		}

		else {
			cout << token << endl;
			postfix += token;
		}
	}

	// Empty the stack at the end to operation
	while (top != NULL) {
		temp = pop();
		postfix += temp;
	}

	cout << "\nPostfix Expression : " << postfix << endl;

	return postfix;
}

// Function to convert infix to prefix
string Stack::infixToPrefix(string infix) {
	string reverse = "";
	string prefix = "";

	cout << "\nReversing infix..."
		<< "\nSwitching brackets...";

	for (int i = infix.length() - 1; i >= 0; i--) {

		if (infix[i] == '(') {
			infix[i] = ')';
		}

		else if (infix[i] == ')') {
			infix[i] = '(';
		}

		reverse += infix[i];
	}

	cout << "\nReversed Infix Expression :" << reverse << endl;
	
	reverse = infixToPostfix(reverse);

	for (int i = reverse.length() - 1; i >= 0; i--) {
		prefix += reverse[i];
	}

	cout << "\nReversing Postfix Expression..."
		<< "\nPrefix Expression :" << prefix << endl;

	return prefix;
}

// Function to evaluate the postfix expression
void Stack::evaluatePostfix(string postfix) {

	int const size = postfix.length();
	int* arr = new int[size];
	int i = 0;

	cout << "\nPostfix Evaluation :";

	// Evaluate postfix expression
	for (char token : postfix) {

		if (isOperand(token)) {
			arr[i] = token - '0';
			i++;
		}

		else {
			// Handle operators (+, -, *, /, %)
			int operand2 = arr[i - 1];
			int operand1 = arr[i - 2];
			int result = 0;

			if (token == '+') {
				cout << "\n" << operand1 << " + " << operand2 << " = ";
				result = operand1 + operand2;
			}
			else if (token == '-') {
				cout << "\n" << operand1 << " - " << operand2 << " = ";
				result = operand1 - operand2;
			}
			else if (token == '*') {
				cout << "\n" << operand1 << " * " << operand2 << " = ";
				result = operand1 * operand2;
			}
			else if (token == '/') {
				if (operand2 == 0) {
					cout << "\nError: Division by zero" << endl;
					cout << "\nFinal Result: NaN" << endl;

					delete[] arr; // Clean up
					return;
				}

				cout << "\n" << operand1 << " / " << operand2 << " = ";
				result = operand1 / operand2;
			}
			else if (token == '%') {
				cout << "\n" << operand1 << " % " << operand2 << " = ";
				result = operand1 % operand2;
			}

			arr[i - 2] = result; // Replace the last two operands with the result
			i--; // Decrease the index as two operands are replaced by one result

			cout << result;
		}

	}

	// Final result is stored in arr[0]
	cout << "\nFinal Result: " << arr[0] << endl;
	cout << endl;

	delete[] arr; // Clean up dynamically allocated memory
}

// Function to evaluate the prefix expression
void Stack::evaluatePrefix(string prefix) {
	int const size = prefix.length();
	int* arr = new int[size];
	int index = -1;

	cout << "\nPrefix Evaluation :";

	// Evaluate postfix expression
	for (int i = size - 1; i >= 0; i--) {

		char token = prefix[i];

		if (isOperand(token)) {
			// Convert char to int and push to array
			arr[++index] = token - '0'; // Store in the next position
		}

		else {
			// Ensure there are at least two operands available for the operation
			if (index < 1) {
				cout << "\nError: Not enough operands for the operator " << token << endl;
				cout << "\nFinal Result: NaN" << endl;

				delete[] arr; // Clean up
				return;
			}

			// Pop two operands from the stack
			int operand1 = arr[index--]; // Last pushed operand
			int operand2 = arr[index--]; // Second last pushed operand
			int result = 0;

			if (token == '+') {
				cout << "\n" << operand1 << " + " << operand2 << " = ";
				result = operand1 + operand2;
			}
			else if (token == '-') {
				cout << "\n" << operand1 << " - " << operand2 << " = ";
				result = operand1 - operand2;
			}
			else if (token == '*') {
				cout << "\n" << operand1 << " * " << operand2 << " = ";
				result = operand1 * operand2;
			}
			else if (token == '/') {
				if (operand2 == 0) {
					cout << "\nError: Division by zero" << endl;
					cout << "\nFinal Result: NaN" << endl;

					delete[] arr; // Clean up
					return;
				}
				cout << "\n" << operand1 << " / " << operand2 << " = ";
				result = operand1 / operand2;
			}
			else if (token == '%') {
				cout << "\n" << operand1 << " % " << operand2 << " = ";
				result = operand1 % operand2;
			}
			else {
				cout << "\nError: Unknown operator " << token << endl;
				cout << "\nFinal Result: NaN" << endl;

				delete[] arr; // Clean up
				return;
			}

			// Push result back to the array
			arr[++index] = result;
			cout << result;
		}

	}

	// Final result is stored in arr[0]
	cout << "\nFinal Result: " << arr[0] << endl;
	cout << endl;

	delete[] arr; // Clean up dynamically allocated memory
}

// Menu based main function
int main() {
	Stack calculate;
	string infix = "";
	string expression = "";
	char choice;

	do {
		cout << "\n-----Infix Notation Evaluator-----\n"
			<< "\n1. Postfix"
			<< "\n2. Prefix"
			<< "\n3. Exit"
			<< "\n--Enter (1-3) : ";
		cin >> choice;

		if (choice == '1' || choice == '2') {
			cout << "\n--Enter Infix : ";
			cin >> infix;
		}

		switch (choice)
		{
		case '1':
			cout << "\n-----Converting to Postfix...";
			expression = calculate.infixToPostfix(infix);
			calculate.evaluatePostfix(expression);
			break;
		case '2':
			cout << "\n-----Converting to Prefix...";
			expression = calculate.infixToPrefix(infix);
			calculate.evaluatePrefix(expression);
			break;
		case '3':
			cout << "\n-----Program Terminated!-----\n";
			break;
		default:
			cout << "\n-----Invalid Input!-----\n";
			break;
		}
	} while (choice != '3');

	system("pause");
	return 0;
}