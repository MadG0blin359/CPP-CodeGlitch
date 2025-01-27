#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;

	Node(int d) : data(d), next(NULL) {}
};

class LinkedList {
	Node* head;
public:
	LinkedList() : head(NULL) {}

	bool isEmpty() {
		return (head == NULL);
	}

	void insert(int data) {
		Node* newNode = new Node(data);
		if (isEmpty) {
			head = newNode;
			return;
		}

		Node* temp = head;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = newNode;
	}

	bool rotateLeft(int k) {
		if (isEmpty())
			return false;

		Node* temp = head;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = head;			// is Circular Linked List Now

		temp = head;
		for (int i = 1; i < k; i++)
			temp = temp->next;

		head = temp->next;
		temp->next = NULL;
		return true;
	}

	bool rotateRight(int k) {
		if (isEmpty())
			return false;

		int length = 0;
		Node* temp = head;
		while (temp->next != NULL) {
			length++;
			temp = temp->next;
		}

		temp->next = head;			// is Circular Linked List Now
		k = k % length;

		for (int i = 0; i < length - k; i++)
			temp = temp->next;
		
		head = temp->next;
		temp->next = NULL;
		return true;
	}
};

int main() {

	system("pause");
	return 0;
}