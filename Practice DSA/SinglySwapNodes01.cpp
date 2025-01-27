#include <iostream>
using namespace std;

template <class T>
class List;  // Forward declaration of the templated List class

template <class T>
class Node {
	Node* next;
	T data;
public:
	Node(T d) : data(d), next(NULL) {}
	friend class List<T>;
};

template <class W>
class List {
	Node<W>* head;
public:
	List() : head(NULL) {}

	bool isEmpty() {
		return (head == NULL);
	}

	bool insertAtHead(W data) {
		Node<W>* newNode = new Node<W>(data);
		if (isEmpty()) {
			head = newNode;
			return true;
		}

		newNode->next = head;
		head = newNode;
		return true;
	}

	bool insertAtTail(W data) {
		Node<W>* newNode = new Node<W>(data);
		if (isEmpty()) {
			head = newNode;
			return true;
		}

		Node<W>* current = head;

		while (current->next != NULL) {
			current = current->next;
		}

		current->next = newNode;
		return true;
	}

	W deleteAtHead() {
		if (isEmpty()) {
			cout << "\nList Underflow!\n";
			return W();
		}

		Node<W>* temp = head;
		W value;

		head = head->next;
		value = temp->data;
		delete temp;
		return value;
	}

	W deleteAtTail() {
		if (isEmpty()) {
			cout << "\nList Underflow!\n";
			return W();
		}

		Node<W>* temp = head, * prev = NULL;
		W value;

		while (temp->next != NULL) {
			prev = temp;
			temp = temp->next;
		}

		value = temp->data;

		// If only one node was in the list
		if (prev == NULL) {
			head = NULL;
		}
		
		else {
			prev->next = NULL;
		}

		delete temp;
		return value;
	}

	bool isOdd(int count) {
		return (count % 2 != 0);
	}

	void swapOddNodes() {
		if (isEmpty()) {
			cout << "\nList is Empty!\n";
			return;
		}

		else if (head->next == NULL) {
			cout << "\nCannot Swap! Only One Node Exist.\n";
		}

		Node<W>* current = head, *prev = NULL;
		int count = 0;

		while (current != NULL) {
			if (isOdd(count)) {
				Node<W>* temp = current;
				current = current->next;
				prev->next = current;
				temp->next = head;
				head = temp;
			}

			else {
				prev = current;
				current = current->next;
			}
			count++;
		}
	}

	void display() {
		if (isEmpty()) {
			cout << "\nList is Empty!\n";
			return;
		}

		Node<W>* current = head;

		while (current != NULL) {
			cout << current->data << "->";
			current = current->next;
		}
		cout << "NULL" << endl;
	}

	~List() {
		Node<W>* current = head, *temp;

		while (current != NULL) {
			temp = current;
			current = current->next;
			delete temp;
		}
	}
};

int main() {
	List<int> list;

	cout << "\nInserting Data...";
	for (int i = 0; i < 8; i++) {
		list.insertAtTail(i);
	}

	cout << "\nData Listed : ";
	list.display();

	cout << "\nSwaping Odd Nodes...";
	list.swapOddNodes();

	cout << "\nNew Data List : ";
	list.display();

	system("pause");
	cin.get();
	return 0;
}