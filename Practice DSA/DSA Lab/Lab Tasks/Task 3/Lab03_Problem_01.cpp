#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

// Function to insert a new node at the beginning
void insertBeginning(Node *&head, int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = head;
	head = newNode;
}

// Function to insert a new node at the end
void insertEnd(Node*& head, int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;		// New node is pointing to null as its the last node

	if (head == nullptr)
		head = newNode;
	else {
		Node* temp = head;

	while (temp->next != nullptr) {
		temp = temp->next;
	}

	temp->next = newNode;		// Linked the last node to a new one

	}
}

// Function to insert a new node in the middle
void insertMiddle(Node*& head, int value, int position) {
	Node* newNode = new Node;
	newNode->data = value;

	if (position == 1) {
		newNode->data = value;
		head = newNode;
	}

	else {
		Node* temp = head;
		for (int i = 1; i < position - 1 && temp != nullptr; i++) {
			temp = temp->next;
		}

		if (temp == nullptr) {
			cout << "\nPositions out of bound\n";
			delete newNode;
		}

		else {
			newNode->next = newNode;
		}
	}
}

// Function to print data stored in the list
void printList(Node* head) {
	Node* temp = head;

	while (temp != nullptr) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

int main() {
	Node* head = nullptr;

	insertEnd(head, 11);
	insertEnd(head, 22);
	insertEnd(head, 33);

	cout << "\n\nList after inserting at the end : ";
	printList(head);

	insertBeginning(head, 7);
	insertBeginning(head, 4);
	insertBeginning(head, 3);

	cout << "\n\nList after inserting at the beginning : ";
	printList(head);

	insertMiddle(head, 9, 3);
	cout << "\n\nList after inserting at the Middle : ";
	printList(head);


	system("pause");
	return 0;
}