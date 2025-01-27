#include <iostream>

using namespace std;

// Node class represents a node in a linked list
class Node {
public:
	char data;
	Node* next;

	Node(char d) : data(d), next(nullptr) {}
};

// LinkedList class manages the linked list
class LinkedList {
public:
	Node* head;

	LinkedList() : head(nullptr) {}

	// Append a new node with the given data to the end of the list
	void append(char data) {
		Node* newNode = new Node(data);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node* current = head;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = newNode;
		}
	}

	// Print all nodes in the list
	void printList() const {
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << " -> ";
			current = current->next;
		}
		cout << "None" << endl;
	}

	// Destructor to clean up memory
	~LinkedList() {
		Node* current = head;
		while (current != nullptr) {
			Node* nextNode = current->next;
			delete current;
			current = nextNode;
		}
	}
};

// Function to concatenate two linked lists
void concatenate(LinkedList& list1, LinkedList& list2) {
	if (list1.head == nullptr) {
		list1.head = list2.head;
	}
	else {
		Node* current = list1.head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = list2.head;
	}

	// After concatenation, clear the second list's head to avoid double deletion
	list2.head = nullptr;
}

int main() {
	// Create the first linked list and append characters
	LinkedList list1;
	char chars1[] = { 'A', 'B', 'C', 'D', 'E' };
	for (char ch : chars1) {
		list1.append(ch);
	}

	// Create the second linked list and append characters
	LinkedList list2;
	char chars2[] = { 'F', 'G', 'H', 'I', 'J' };
	for (char ch : chars2) {
		list2.append(ch);
	}

	// Print the original lists
	cout << "List 1 before concatenation:" << endl;
	list1.printList();
	cout << "List 2 before concatenation:" << endl;
	list2.printList();

	// Concatenate list2 to list1
	concatenate(list1, list2);

	// Print the concatenated list
	cout << "List 1 after concatenation:" << endl;
	list1.printList();
	cout << "List 2 after concatenation (should be empty):" << endl;
	list2.printList();

	system("pause");
	return 0;
}
