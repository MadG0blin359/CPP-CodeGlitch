#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	Node* prev, * next;
	char data;
	
	// Initializing member variables using constant initializer list
	Node(char d) : data(d), prev(NULL), next(NULL) {}
};

// Doubly circular linked list class
class CircularList {
	Node* head;
public:
	CircularList() : head(NULL) {}

	void insertAtEnd(char input);
	bool isVowel(char input);
	bool isNumber();
	void rotate();
	void convertToPigLatin();
	void display();
};

// Menu based user interactive program
int main() {
	CircularList list;
	string input;

	cout << "\n-----Converting a String-----"
		<< "\n--Enter a String : ";
	getline(cin, input);

	for (int i = 0; i < input.length(); i++) {
		list.insertAtEnd(input[i]);
	}

	// Display the string
	cout << "\n--Original string: ";
	list.display();

	// Convert to Pig Latin
	cout << "\n--Pig Latin form: ";
	list.convertToPigLatin();

	system("pause");
	return 0;
}

// Function to insert every character into each node
void CircularList::insertAtEnd(char input) {
	Node* newNode = new Node(input);
	// When there is no node
	if (head == NULL) {
		head = newNode;
		newNode->next = head;
		head->prev = newNode;
		return;
	}

	Node* current = head;

	// When there is only one node
	if (current->next == head) {
		current->next = newNode;
		current->prev = newNode;
		newNode->prev = current;
		newNode->next = current;
	}

	// When there are n number of nodes
	do {
		current = current->next;
	} while (current->next != head);

	current->next = newNode;
	newNode->prev = current;
	newNode->next = head;
	head->prev = newNode;

}

// Function to find vowels
bool CircularList::isVowel(char input) {
	input = tolower(input);

	if (input == 'a' || input == 'e' || input == 'i' || input == 'o' || input == 'u') {
		return true;
	}

	return false;
}

// Function to check if a character is a string
bool CircularList::isNumber() {
	if (head == NULL) {
		cout << "\n-----List is Empty! Data Cannot Be Found-----\n";
		return false;
	}

	Node* current = head;

	do {
		if (!(current->data >= '0' && current->data <= '9')) {
			return false;
		}

		current = current->next;
	} while (current->next != head);
	
	return true;
}

// Function to rotate the string
void CircularList::rotate() {
	if (head == NULL) {
		cout << "\n-----List is Empty! Data Cannot Be Found-----\n";
		return;
	}

	head = head->next;

}

// Funtion to convert string into pigLatin
void CircularList::convertToPigLatin() {
	if (head == NULL) {
		cout << "\n-----List is Empty! Data Cannot Be Found-----\n";
		return;
	}

	Node* current = head;

	// When the first letter is a vowel
	if (isVowel(current->data)) {
		display();
		cout << "-way" << endl;
		return;
	}

	else {
		insertAtEnd('-');
	}

	if (isNumber()) {
		display();
		cout << "way" << endl;
		return;
	}

	Node* tail = NULL;

	do {
		current = current->next;
	} while (current->next != head);

	tail = current;
	current = head;

	do {
		if (isVowel(current->data)) {
			display();
			cout << "ay" << endl;
			return;
		}

		else {
			rotate();
		}

		current = current->next;
	} while (current->next != tail);

	// No vowels at all
	if (current->next == tail) {
		display();
		cout << "ay" << endl;
		return;
	}

}

// Function to display the data stored in doubly circular list
void CircularList::display() {
	if (head == NULL) {
		cout << "\n-----List is Empty! Data Cannot Be Found-----\n";
		return;
	}

	Node* current = head;

	do {
		cout << current->data;
		current = current->next;
	} while (current != head);
}
