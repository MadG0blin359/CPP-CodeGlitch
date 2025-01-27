#include <iostream>
using namespace std;

class Node {
public:
	Node* next;
	int data;

	Node(int d) : data(d), next(NULL) {}
};

class List {
	Node* head;

public:
	List() : head(NULL) {}

	void insertNodeAtBeginning(int data);				// O(1)
	void insertNodeInMiddle(int data, int key);			// O(n)
	void insertNodeAtEnd(int data);						// O(n)
	bool deleteFirstNode();								// O(1)
	bool deleteNode(int key);							// O(n)
	bool deleteLastNode();								// O(n)
	void display();										// O(n)
	bool search(int data);								// O(n)
};

// Function to insert a new node at the beginning of the singly linked list
void List::insertNodeAtBeginning(int data) {
	Node* newNode = new Node(data);
	
	if (head == NULL) {
		head = newNode;
		cout << "\n-----First Node Created Successfully!-----\n";
		return;
	}
	// If head not empty, new node added
	newNode->next = head;
	head = newNode;

	cout << "\n-----New Node Inserted At Beginning Successfully!-----\n";
}
// Function to find a node whose data member matches the provided key. 
// Once found, a new node (with the provided data) will be inserted after this found node.
void List::insertNodeInMiddle(int data, int key) {
	if (head == NULL) {
		cout << "\n-----List is Empty! Key Cannot Be Found-----\n";
		return;
	}

	Node* newNode = new Node(data);
	Node* current = head;

	// Find and compare the data with key
	while (current != NULL) {
		if (current->data == key) {
			newNode->next = current->next;
			current->next = newNode;
			
			cout << "\n-----Key Found! New Node Inserted-----\n";
			break;
		}
		current = current->next;
	}

	if (current == NULL) {
		cout << "\n-----Key Does Not Exist! New Node Not Inserted-----\n";
	}
}

// Function to insert a new node at the end of the singly linked list
void List::insertNodeAtEnd(int data) {
	// If the list is empty, insert at the beginning
	if (head == NULL) {
		insertNodeAtBeginning(data);
		return;
	}

	// If the list is not empty, traverse the list to the end
	Node* current = head;
	while (current->next != NULL) {
		current = current->next;
	}

	// Add a new node at the end of the list
	Node* newNode = new Node(data);
	current->next = newNode;

	cout << "\n-----New Node Inserted At End Successfully!-----\n";

}

// Function to delete first node
bool List::deleteFirstNode() {
	if (head == NULL) {
		cout << "\n-----List is Empty! Node Cannot Be Found-----\n";
		return false;
	}

	Node* temp = head;
	head = head->next;

	delete temp;		// Node deleted
	return true;
}

// Function to delete any node in the singly linked list
bool List::deleteNode(int key) {
	if (head == NULL) {
		cout << "\n-----List is Empty! Node Cannot Be Found-----\n";
		return false;
	}

	Node* current = head;

	// Find and delete the specified node
	while (current != NULL) {
		if (current->next->data == key) {
			Node* temp = current->next;
			current->next = current->next->next;
			delete temp;
			return true;
		}
		current = current->next;
	}

	// If key not found
	if (current == NULL) {
		cout << "\n-----Key Does Not Exist! Node Cannot Be Deleted-----\n";
		return false;
	}
}

// Function to delete the last node in the list
bool List::deleteLastNode() {
	if (head == NULL) {
		cout << "\n-----List is Empty! Node Cannot Be Found-----\n";
		return false;
	}

	Node* current = head;
	Node* temp = NULL;

	while (current->next->next != NULL) {
		current = current->next;
	}
	
	temp = current;
	current = current->next;
	temp->next = NULL;

	delete current;
	return true;
}

// Function to display complete singly linked list data
void List::display() {
	if (head == NULL) {
		cout << "\n-----List is Empty! Data Cannot Be Found-----\n";
		return;
	}

	cout << "\n-----Data List-----\n";

	Node* current = head;

	while (current != NULL) {

		cout << current->data << "->";

		current = current->next;
	}

	cout << "NULL" << endl;
}

// Function to search the singly linked list for specific data
bool List::search(int data) {
	if (head == NULL) {
		cout << "\n-----List is Empty! Data Cannot Be Found-----\n";
		return false;
	}

	Node* current = head;

	while (current != NULL) {
		if (current->data == data) {
			cout << "\n-----Data " << data << " found in the list!-----\n";
			return true;
		}
		current = current->next;
	}

	return false;
}

int main() {
	List list;
	char choice;
	int data, key;

	do {		// Interactive Menu
		cout << "\n\t-----Singly Node Menu-----"
			<< "\n1. Insert at Beginning"
			<< "\n2. Insert in Middle"
			<< "\n3. Insert at End"
			<< "\n4. Delete First Node"
			<< "\n5. Delete any Node"
			<< "\n6. Delete Last Node"
			<< "\n7. Display Nodes"
			<< "\n8. Search Nodes"
			<< "\n9. Exit"
			<< "\n--Enter choice (1-9) : ";
		cin >> choice;

		// Calling functions according to the user choice
		switch (choice)
		{
		case '1':
			cout << "\n-----Adding a Node at Beginning-----\n"
				<< "--Enter Data : ";
			cin >> data;
			list.insertNodeAtBeginning(data);
			break;

		case '2':
			cout << "\n-----Adding a Node in Middle-----\n"
				<< "--Enter Data : ";
			cin >> data;

			cout << "--Enter Key : ";
			cin >> key;

			list.insertNodeInMiddle(data, key);
			break;

		case '3':
			cout << "\n-----Adding a Node at End-----\n"
				<< "--Enter Data : ";
			cin >> data;

			list.insertNodeAtEnd(data);
			break;

		case '4':
			cout << "\n-----Deleting First Node-----\n";
			if (list.deleteFirstNode()) {
				cout << "\n-----First Node Deleted Successfully!-----\n";
			}

			break;

		case '5':
			cout << "\n-----Deleting a Node-----\n"
				<< "--Enter Key : ";
			cin >> key;

			if (list.deleteNode(key)) {
				cout << "\n-----Key Found! Node Deleted Successfully-----\n";
			}

			break;

		case '6':
			cout << "\n-----Deleting Last Node-----\n";
			if (list.deleteLastNode()) {
				cout << "\n-----Last Node Deleted Successfully!-----\n";
			}
			break;

		case '7':
			cout << "\n-----Singly Linked List Nodes-----\n";
			list.display();
			break;

		case '8':
			cout << "\n-----Searching Node-----\n"
				<< "--Enter Data : ";
			cin >> data;

			if (!list.search(data)) {
				cout << "\n-----Data Does Not Exist!-----\n";
			}
			break;

		case '9':
			cout << "\n-----Program Terminated-----\n";
			break;

		default:
			cout << "\n-----Invalid Input!-----\n";
			break;
		}
	} while (choice != '9');


	system("pause");
	return 0;
}