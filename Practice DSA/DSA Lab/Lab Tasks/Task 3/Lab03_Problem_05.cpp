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

	// Create a reversed copy of the list
	LinkedList reverse() const {
		LinkedList reversedList;
		Node* current = head;
		while (current != nullptr) {
			Node* newNode = new Node(current->data);
			newNode->next = reversedList.head;
			reversedList.head = newNode;
			current = current->next;
		}
		return reversedList;
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

int main() {
	// Create the original linked list and append 10 characters
	LinkedList originalList;
	char characters[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

	for (char ch : characters) {
		originalList.append(ch);
	}

	// Print the original list
	cout << "Original List:" << endl;
	originalList.printList();

	// Create and print the reversed list
	LinkedList reversedList = originalList.reverse();
	cout << "Reversed List:" << endl;
	reversedList.printList();

	system("pause");
	return 0;
}
