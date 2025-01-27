#include <iostream>

using namespace std;

// Node class represents a node in a linked list
class Node {
public:
	int data;
	Node* next;

	Node(int d) : data(d), next(nullptr) {}
};

// LinkedList class manages the linked list
class LinkedList {
public:
	Node* head;

	LinkedList() : head(nullptr) {}

	// Append a new node with the given data to the end of the list
	void append(int data) {
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

	// Insert a new node with the given data at the middle of the list
	void insertAtMiddle(int data) {
		Node* newNode = new Node(data);

		if (head == nullptr) {
			// If the list is empty, insert at the beginning
			head = newNode;
			return;
		}

		Node* slow = head;
		Node* fast = head;
		Node* prev = nullptr;

		// Use the slow and fast pointer technique to find the middle
		while (fast != nullptr && fast->next != nullptr) {
			fast = fast->next->next;
			prev = slow;
			slow = slow->next;
		}

		// Insert the new node after the prev node (which points to the node before the middle)
		newNode->next = slow;
		if (prev != nullptr) {
			prev->next = newNode;
		}
		else {
			// If prev is null, this means the list was empty or had only one element
			head = newNode;
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

int main() {
	LinkedList list;

	// Create a linked list with an even number of nodes
	list.append(10);
	list.append(20);
	list.append(30);
	list.append(40);
	list.append(50);
	list.append(60);

	// Print the original list
	cout << "Original List:" << endl;
	list.printList();

	// Insert a new data item in the middle of the list
	list.insertAtMiddle(35);

	// Print the updated list
	cout << "Updated List with new middle element:" << endl;
	list.printList();

	system("pause");
	return 0;
}
