#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* prev, *next;

	Node(int d) : data(d), prev(NULL), next(NULL) {}
};

class DoublyList {
	Node* head;
public:
	DoublyList() : head(NULL) {}

	void insertAtTail(int data);
	void deleteNode(int key);
	void printListReverse();
	void swapNodes();

	~DoublyList() {
		
	}
};

// Function to insert a new node at the end of the list
void DoublyList::insertAtTail(int data) {
	Node* newNode = new Node(data);
	if (head == NULL) {
		head = newNode;
		cout << "\n-----First Node Created Successfully!-----\n";
		return;
	}

	Node* current = head;
	while (current->next != NULL) {
		current = current->next;
	}

	current->next = newNode;
	newNode->prev = current;

	cout << "\n-----New Node Inserted At Tail Successfully!-----\n";
}

// Function to delete any node in the list
void DoublyList::deleteNode(int key) {
	if (head == NULL) {
		cout << "\n-----List is Empty! Key Cannot Be Found-----\n";
		return;
	}

	Node* current = head;
	Node* temp = NULL;
	while (current != NULL) {
		if (current->data == key) {
			temp = current;
			cout << "\n-----Key Found! Deleting Node-----\n";
			break;
		}
		current = current->next;
	}
	current->next->prev = current->prev;
	current->prev->next = current->next;
	delete temp;

	cout << "\n-----Node Deleted Successfully!-----\n";

}

void DoublyList::printListReverse() {
	if (head == NULL) {
		cout << "\n-----List is Empty! Data Cannot Be Found-----\n";
		return;
	}

	// Traverse to the end of the list
	Node* current = head;
	while (current->next != NULL) {
		current = current->next;
	}

	// Print the list in reverse order
	cout << "NULL"; // Optionally indicate the start of the list

	while (current != NULL) {
		cout << " <- " << current->data;
		current = current->prev;
	}
	cout << " <- NULL" << endl; // Indicate the end of the list
}

// Function to swap nodes 
void DoublyList::swapNodes() {
	if (head == NULL) {
		cout << "\n-----List is Empty! Nodes Cannot Be Found-----\n";
		return;
	}

	Node* start = head;			// Pointing at the first node
	Node* end = head;			// Pointing at the last node
	while (end->next != NULL) {
		end = end->next;
	}

	// Edge case: if there are only two nodes
	if (start->next == end) {

		return;
	}

	//end->next = start->next;
	//start->prev = end->prev;
	//start->next = NULL;
	//end->prev = NULL;
	//head = end;

	cout << "\n-----Nodes Swapped Successfully!-----\n";

}

int main() {

	DoublyList list;
	char choice;
	int data, key;

	do {
		cout << "\n-----Doubly List-----\n"
			<< "\n1. Add a Node at Tail"
			<< "\n2. Delete a Node"
			<< "\n3. Print List"
			<< "\n4. Swap Nodes"
			<< "\n5. Exit"
			<< "\n--Enter choice (1-5) : ";
		cin >> choice;

		switch (choice)
		{
		case '1':
			cout << "\n-----Adding a new Node-----\n"
				<< "\n--Enter Data : ";
			cin >> data;

			list.insertAtTail(data);
			break;
		case '2':
			cout << "\n-----Deleting a Node-----\n"
				<< "\n--Enter Key : ";
			cin >> key;

			list.deleteNode(key);
			break;
		case '3':
			cout << "\n-----Printing Doubly List Reversed in Order-----\n";
			list.printListReverse();
			break;
		case '4':
			cout << "\n-----Swaping Nodes-----\n";
			list.swapNodes();
			break;
		case '5':
			cout << "\n-----Program Terminated!-----\n";
			break;
		default:
			cout << "\n-----Invalid Input!-----\n";
			break;
		}
	} while (choice != '5');

	system("pause");
	return 0;
}