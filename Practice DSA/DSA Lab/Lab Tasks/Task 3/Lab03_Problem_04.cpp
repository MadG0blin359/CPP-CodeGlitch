#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

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

	// Print all nodes in the list
	void printList() const {
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << " -> ";
			current = current->next;
		}
		cout << "None" << endl;
	}

	// Calculate the sum of all nodes' data
	int calculateSum() const {
		int sum = 0;
		Node* current = head;
		while (current != nullptr) {
			sum += current->data;
			current = current->next;
		}
		return sum;
	}

	// Calculate the number of nodes in the list
	int countNodes() const {
		int count = 0;
		Node* current = head;
		while (current != nullptr) {
			count++;
			current = current->next;
		}
		return count;
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
	// Seed the random number generator
	srand(static_cast<unsigned>(time(0)));

	// Create a linked list
	LinkedList list;

	// Insert 15 random integers from 0 to 100 into the linked list
	for (int i = 0; i < 15; ++i) {
		int randomValue = rand() % 101; // Random number between 0 and 100
		list.append(randomValue);
	}

	// Print the list
	cout << "Linked List:" << endl;
	list.printList();

	// Calculate sum and average
	int sum = list.calculateSum();
	int count = list.countNodes();
	float average = (count > 0) ? static_cast<float>(sum) / count : 0;

	// Print sum and average
	cout << "Sum of elements: " << sum << endl;
	cout << "Average of elements: " << average << endl;

	system("pause");
	return 0;
}
