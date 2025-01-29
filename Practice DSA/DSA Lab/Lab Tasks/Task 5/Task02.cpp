#include <iostream>
#include <string>
using namespace std;

class Node {
	Node* next;
	char data;
public:
	Node(char d) : next(NULL), data(d) {}
	friend class Stack;
};

class Stack {
	Node* top;
	string postFix;
public:
	Stack() : top(NULL), postFix("") {}

	void push(char data);
	bool pop(char&);
	char peek();
	bool isEmpty();
	int precedence(char op);
	bool isOperand(char ch);
	string infixToPostfix();
	void display();

};

void Stack::push(char ch) {
	Node* newNode = new Node(ch);
		top = newNode;
		newNode->next = top;
}

bool Stack::pop(char &returnVal) {
	if (isEmpty()) {
		cout << "\nStack Underflow\n";
		return false;
	}

	returnVal = top->data;
	Node* temp = top;
	top = top->next;
	delete temp;
}

char Stack::peek() {
	if (isEmpty()) {
		cout << "\nStack Empty\n";
		return;
	}

	return top->data;
}

bool Stack::isEmpty() {
	return (top == NULL);
}

int Stack::precedence(char op) {
	if (op == '+' || op == '-')
		return 1;

	else if (op == '*' || op == '/')
		return 2;

	else if (op == '^')
		return 3;

	return 0;
}

bool Stack::isOperand(char ch) {
	return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'));
}

string Stack::infixToPostfix() {
	Node* current = top;
	Stack opStk;
	char temp;
	while (current != NULL) {

		if (isOperand(current->data)) {
			postFix += current->data;
		}

		else if (current->data == '(') {
			opStk.push(current->data);
		}

		else if (current->data == ')') {
			while (!opStk.isEmpty() && opStk.peek() != '(') {
				opStk.pop(temp);
				postFix += temp;
			}
		}

		else {
			int opPrecedence = 0;
			opPrecedence = precedence(current->data);
			if (opPrecedence == 1) {

			}

			else if (opPrecedence == 2) {

			}

			else if (opPrecedence == 3) {

			}
		}



		current = current->next;
	}
}

void Stack::display() {
	Node* current = top;
	while (current != NULL) {
		cout << current->data;
		current = current->next;
	}
	cout << endl;
}

int main() {
	Stack input;
	string sample;
	sample = "((a + b) * c - d) / (e * f - g)";

	for (char ch : sample) {
		input.push(ch);
	}

	cout << "\nInfix: ";
	input.display();

	input.infixToPostfix();

	cout << "\nPostfix: ";
	input.display();

	system("pause");
	return 0;
}