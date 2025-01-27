#include <iostream>
using namespace std;

class Node {
public:
	Node* next;
	int data;

	Node(int d) : data(d), next(NULL) {}
};

class List {
	Node* head = NULL;
public:
	void insertAtHead(int d) {
		Node* newNode = new Node(d);
		Node* current = head;

		if (head == NULL) {
			head = newNode;
			return;
		}

		newNode->next = head;
		head = newNode;


	}

	void searchNode(int num) {
		if (head == NULL) {
			cout << "List is Empty! No Data Found.\n";
			return;
		}

		Node* current = head;
		int position = 1;

		while (current != NULL) {
			if (current->data == num) {
				cout << "Node Found! At Position " << position << "." << endl;
				return;
			}
			current = current->next;
			position++;
		}
		
		cout << "\nSearched Node Not Found!" << endl;
	}

	void printList() {
		if (head == NULL) {
			cout << "List is Empty! No Data Found.\n";
			return;
		}

		Node* current = head;

		while (current != NULL) {
			cout << current->data << "->";
			current = current->next;
		}
		cout << "NULL" << endl;
	}
};

int main() {

	List data;

	data.insertAtHead(5);
	data.insertAtHead(10);
	data.insertAtHead(15);
	data.insertAtHead(20);

	data.searchNode(15);

	data.printList();


	system("pause");
	return 0;
}