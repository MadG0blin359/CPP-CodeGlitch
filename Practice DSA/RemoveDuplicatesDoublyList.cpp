#include <iostream>
using namespace std;

class Node {
public:
	Node* prev; // Pointer to the previous node in the doubly linked list
	Node* next; // Pointer to the next node in the doubly linked list
	int ID; // Unique identifier for the node
	string Description; // Description associated with the node

	// Default Parametrized Constructor to initialize a node with an ID and Description
	Node(int id = 0, string des = NULL) : ID(id), Description(des), prev(NULL), next(NULL) {}
};

class List {
public:
	Node* head = NULL; // Pointer to the head of the linked list

	// Function to add a new item at the end of the list
	void addItemsEnd(int id, string des) {
		Node *newNode = new Node(id, des);
		Node* current = head;
		
		if (head == NULL) {
			head = newNode;
			return;
		}

		else {
			while (current->next != NULL) {
				current = current->next;
			}

			current->next = newNode;
			newNode->prev = current;
			
		}
		
	}

	// Function to remove duplicates based on the ID
	void removeDuplicates() {
		if (head == NULL) {
			cout << "List is empty. No duplicates to remove.\n";
			return;
		}

		Node* current = head;

		while (current != NULL) {
			Node* compare = current;
			while (compare != NULL) {

				if (current->ID == compare->ID) {
					cout << "\nID : " << compare->ID;
				}

				compare = compare->next;
			}
			current = current->next;
		}

	}

	// Function to print the list of items
	void printList() {
		Node* current = head;

		while (current != NULL) {
			cout << "ID: " << current->ID << "\t" << "Description: " << current->Description << endl;
			current = current->next;
		}
		cout << endl;
	}
};

int main() {

	List items; // Create a List object

	// Add items to the list
	items.addItemsEnd(55, "Test01");
	items.addItemsEnd(66, "Test02");
	items.addItemsEnd(77, "Test03");
	items.addItemsEnd(66, "Test02"); // Duplicate item
	items.addItemsEnd(55, "Test01"); // Duplicate item

	// Print the list before removing duplicates
	items.printList();

	// Remove duplicates from the list (currently only prints duplicate IDs)
	items.removeDuplicates();

	cout << "\nAfter Removing Duplicates: " << endl;

	// Print the list after duplicates removal (duplicates are still present in the list)
	items.printList();

	cout << endl;
	system("pause");
	return 0;
}