#include <iostream>
#include <string>
using namespace std;

// Class representing a node in the stack
class Node {
public:
	Node* next;		// Pointer to the next node
	char data;		// Character data stored in the node

	// Constructor to initialize a node with data and set next to NULL
	Node(char d) : data(d), next(NULL) {}
};

// Class representing a stack
class Stack {
	Node* top;		// Pointer to the top of the stack
public:
	Stack() : top(NULL) {}

	// Function to remove and return the top element of the stack
	char pop() {
		if (isEmpty()) {
			cout << "\nStack is Empty!\n";
			return '\0';			// Returning null character
		}

		Node* tmp = top;             // Temporary pointer to hold the top node
		char returnValue = top->data; // Store the data of the top node
		top = top->next;             // Move the top pointer to the next node
		delete tmp;                  // Delete the old top node
		return returnValue;          // Return the popped data
	}

	// Function to add an element to the stack
	bool push(char data) {
		Node* newptr = new Node(data);

		if (isEmpty()) {
			top = newptr;
			return true;
		}

		newptr->next = top;
		top = newptr;
		return true;
	}

	// Function to check if the stack is empty
	bool isEmpty(void) {
		return (top == NULL);
	}

	// Function to display all elements in the stack
	void display() {
		if (isEmpty()) {
			cout << "\nList is Empty!\n";
			return;
		}

		Node* current = top;

		cout << "\nDisplaying Data in Stack...\n";

		while (current != NULL) {
			cout << current->data << endl;
			current = current->next;
		}

	}
};

int main() {

	Stack data;
	string wordstring = "MADAM";
	char temp;

	cout << "\nPushing Elements...\n";
	for (auto i : wordstring)
		data.push(i);

	data.display();

	cout << "\nPoping Elements...\n";
	for (auto i : wordstring) {			    // Check if the string formed by the popped elements is a palindrome
		temp = data.pop();
		if (!data.isEmpty() && i == temp)
			continue;
		cout << wordstring << " is not Palindrome\n";
		system("pause");
		return 0;
	}

	cout << wordstring << " is Plaindrome\n";

	system("pause");
	return 0;
}