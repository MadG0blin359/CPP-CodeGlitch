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
	int peek();
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
int Stack::peek() {
	if (isEmpty()) {
		return 0;
	}

	int returnValue = top->data;
	return returnValue;
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

void towerOfHanoi(int n, Stack& source, Stack& target, Stack& auxiliary);

int main() {
	Stack s1, s2, s3;
	int numberOfRecords;

	// Get the number of records
	cout << "Enter the number of records: ";
	cin >> numberOfRecords;

	// Fill Shelf 1 (s1) with records in descending order
	for (int i = numberOfRecords; i >= 1; --i) {
		s1.push(i);
	}

	// Display the initial state of the shelves
	cout << "Initial state of Shelf 1:" << endl;
	s1.displayStack();

	// Solve the puzzle by moving records from Shelf 1 (s1) to Shelf 3 (s3)
	towerOfHanoi(numberOfRecords, s1, s3, s2);

	// Display the final state of the shelves
	cout << "Final state of Shelf 3:" << endl;
	s3.displayStack();

	return 0;
}


void towerOfHanoi(int n, Stack& source, Stack& target, Stack& auxiliary) {
	// Base case: if there is only one record to move

	if (n == 1) {
		int temp;
		source.pop(temp);  // Remove from source
		target.push(temp); // Add to target
		cout << "Move record " << temp << " from Shelf " << &source << " to Shelf " << &target << endl;
		return;
	}

	// Move n-1 records from source to auxiliary
	towerOfHanoi(n - 1, source, auxiliary, target);

	// Move the nth record from source to target
	int temp;
	source.pop(temp);
	target.push(temp);
	cout << "Move record " << temp << " from Shelf " << &source << " to Shelf " << &target << endl;

	// Move n-1 records from auxiliary to target
	towerOfHanoi(n - 1, auxiliary, target, source);
}

