#include<iostream>
using namespace std;

// Class representing a node in the stack
class Node {
public:
	Node* next;		// Pointer to the next node
	char data;		// Character data stored in the node

	// Constructor to initialize a node with data and set next to NULL
	Node(char d) : data(d), next(NULL) {}
};

// Class representing a stack using linked list
class Stack {
	Node* top;
public:
	// Constructor to initialize an empty stack
	Stack() : top(NULL) {}

	// Function to check if the stack is empty
	bool isEmpty() {
		return (top == NULL);
	}

	// Function to push a value onto the stack
	void push(int value) {
		Node* newptr = new Node(value);
		if (isEmpty()) {
			top = newptr;
			return;
		}

		newptr->next = top;
		top = newptr;
	}

	// Function to pop the top value from the stack
	int pop() {
		if (isEmpty()) {
			cout << "\n-----Stack is Empty!-----\n";
			return -1;
		}
		Node* temp = top;
		delete top;

		top = temp->next;
		return temp->data;
	}

	// Function to get the value at the top of the stack
	int peek() {
		if (isEmpty()) {
			return -1;
		}

		return top->data;
	}
};

int main() {
	int disk, moves = 0;
	char choice;

	cout << "\n-----*****TOWER OF HANOI GAME*****-----\n";

	// Loop to ensure the user enters a valid number of disks
	do {	
		cout << "\n--Enter Number of Disk : ";
		cin >> disk;

		if (disk <= 0) {	// Check for invalid input
			cout << "\n-----Invalid Input!-----\n";
		}
	} while (disk <= 0);

	// Three stacks to represent the towers
	Stack s1, s2, s3;

	// Push the disks onto the stack 1 in descending order
	for (int i = disk; i > 0; i--) {
		s1.push(i);
	}

	// Main game loop
	do {
		cout << "\n*****Play Your Moves*****\n"
			<< "1. Move Stack 1 to Stack 3\n"
			<< "2. Move Stack 1 to Stack 2\n"
			<< "3. Move Stack 2 to Stack 1\n"
			<< "4. Move Stack 2 to Stack 3\n"
			<< "5. Move Stack 3 to Stack 1\n"
			<< "6. Move Stack 3 to Stack 2\n"
			<< "--Your Move : ";
		cin >> choice;

		// Peek the top values of all three stacks
		int s1Num = s1.peek();
		int s2Num = s2.peek();
		int s3Num = s3.peek();

		// Process the user's move based on their choice
		switch (choice) {
		case '1':
			if (s3Num > s1Num || s3Num == -1) {
				s3.push(s1.pop());
				moves++;
			}
			else {
				cout << "Cannot Move " << s1Num << " to Stack 3 Because " << s1Num << " is Greater than " << s3Num << endl;
			}
			break;

		case '2':
			if (s2Num > s1Num || s2Num == -1) {
				s2.push(s1.pop());
				moves++;
			}
			else {
				cout << "Cannot Move " << s1Num << " to Stack 2 Because " << s1Num << " is Greater than " << s2Num << endl;
			}
			break;

		case '3':
			if (s1Num > s2Num || s1Num == -1) {
				s1.push(s2.pop());
				moves++;
			}
			else {
				cout << "Cannot Move " << s2Num << " to Stack 1. " << s2Num << " is Greater than " << s1Num << endl;
			}
			break;

		case '4':
			if (s3Num > s2Num || s3Num == -1) {
				s3.push(s2.pop());
				moves++;
			}
			else {
				cout << "Cannot Move " << s2Num << " to Stack 3. " << s2Num << " is Greater than " << s3Num << endl;
			}
			break;

		case '5':
			if (s1Num > s3Num || s1Num == -1) {
				s1.push(s3.pop());
				moves++;
			}
			else {
				cout << "Cannot Move " << s3Num << " to Stack 1. " << s1Num << " is Greater than " << s3Num << endl;
			}
			break;

		case '6':
			if (s2Num > s3Num || s2Num == -1) {
				s2.push(s3.pop());
				moves++;
			}
			else {
				cout << "Cannot Move " << s3Num << " to Stack 2. " << s2Num << " is Greater than " << s3Num << endl;
			}
			break;

		default:	// Handle invalid input
			cout << "\n-----Invalid Input!-----\n";
			break;
		}

	// Check if all disks are moved to Stack 3 and if the largest disk is on top
	} while (!s3.isEmpty() && s3.peek() != disk);

	// If the user completes the game successfully
	if (!s3.isEmpty() && s3.peek() != disk) {
		cout << "\nCongratulations! You Won the Game\nMoves : " << moves << endl;
	}

	system("pause");
	return 0;
}
