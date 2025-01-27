#include <iostream>
using namespace std;

class Node {
protected:
	Node* next;
	int data;
public:
	Node(int d) : data(d), next(NULL) {}

	friend class Stack;
};

class Stack {
	Node* top;
public:
	Stack() : top(NULL) {}

	void push(int);
	bool pop(int&);
	bool peek(int&);
	bool isEmpty();
	void makeNULL();
	void displayStack();
	~Stack();
};

// Function to insert a new node at the top
void Stack::push(int element) {
	Node* newptr = new Node(element);
	if (isEmpty()) {
		top = newptr;
		return;
	}

	newptr->next = top;
	top = newptr;

}

// Function to delete the top node in the stack
bool Stack::pop(int& returnValue) {
	if (isEmpty()) {
		return false;
	}

	Node* temp = top;
	returnValue = top->data;
	top = top->next;

	delete temp;
	return true;

}

// Function to display the top element
bool Stack::peek(int& returnValue) {
	if (isEmpty()) {
		return false;
	}

	returnValue = top->data;
	return true;
}

// Function to verify if the stack is empty
bool Stack::isEmpty() {
	return (top == NULL);
}

// Function to reset the stack to NULL
void Stack::makeNULL() {
	int x;
	while (pop(x));
}

// Function to display the stack
void Stack::displayStack() {
	if (isEmpty()) {
		cout << "\n-----Stack Underflow Error!-----\n";
		return;
	}

	Node* current = top;

	while (current != NULL) {
		cout << "\t" << current->data << endl;
		current = current->next;
	}

}

// Destructor resets everything to NULL
Stack::~Stack() {
	makeNULL();
}

int main() {

	Stack stack;
	char choice;
	int element;

	do {
		cout << "\n-----My Stack Database-----"
			<< "\n1. Push"
			<< "\n2. Pop"
			<< "\n3. Peek"
			<< "\n4. Reset"
			<< "\n5. Display"
			<< "\n6. Exit"
			<< "\n--Enter choice (1-6) : ";
		cin >> choice;

		switch (choice)
		{
		case '1':
			cout << "\n-----Push New Element-----"
				<< "\n--Enter Element : ";
			cin >> element;

			stack.push(element);

			cout << "\n-----Top Element Pushed Successfully!-----\n";
			break;

		case '2':
			cout << "\n-----Pop Top Element-----\n";

			if (!stack.pop(element)) {
				cout << "\n-----Stack Underflow Error!-----\n";
			}

			else {
				cout << "\n-----Top Element " << element << " Popped Successfully!-----\n";
			}
			break;

		case '3':
			cout << "\n-----Peek at Top-----\n";

			if (!stack.peek(element)) {
				cout << "\n-----Stack Underflow Error!-----\n";
			}

			else {
				cout << "\n-----Element at Top is " << element << "-----\n";
			}
			break;

		case '4':
			cout << "\n-----Resetting Stack-----\n";

			stack.makeNULL();

			cout << "\n-----Stack Reset Successfully!-----\n";
			break;

		case '5':
			cout << "\n-----Stack Data-----\n";
			stack.displayStack();
			break;

		case '6':
			cout << "\n-----Program Terminated-----\n";
			break;

		default:
			cout << "\n-----Invalid Input!-----\n";
			break;
		}
	} while (choice != '6');

	system("pause");
	return 0;
}