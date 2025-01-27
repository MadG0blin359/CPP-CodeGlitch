#include <iostream>
#include <vector>
using namespace std;

template <class T = int>
struct Node {
	T value;
	Node* next;

	Node(T val) : value(val), next(NULL) {}
};

template <class T = int>
class Queue {
	Node<T>* head, * tail;

public:
	Queue() : head(NULL), tail(NULL) {}

	void enqueue(T val) {
		Node<T>* newNode = new Node<T>(val);
		if (isEmpty()) {
			head = tail = newNode;
			return;
		}

		tail->next = newNode;
		tail = tail->next;
	}

	T getFront() {
		if (isEmpty())
			throw runtime_error("Queue is empty");
		return head->value;
	}

	bool isEmpty() {
		return (head == NULL);
	}

	bool dequeue() {
		if (isEmpty())
			return false;
		
		if (head == tail) {
			delete head;
			head = tail = NULL;
			return true;
		}
			
		Node<T>* temp = head;
		head = head->next;
		if (head == nullptr)
			tail = NULL;
		
		delete temp;
		return true;
	}

	void display() {
		Node<T>* temp = head;
		while (temp != NULL) {
			cout << temp->value << " ";
			temp = temp->next;
		}
	}
};

template <class T>
class MultiQueue {
	vector<Queue<T>> Level;
public:
	MultiQueue(int levels) {
		Level = vector<Queue<T>>(levels, Queue<T>());
	}

	void MultiQueueEnqueue(T data, int priority) {
		if (priority < 1 || priority > Level.size()) {
			cout << "\nInvalid priority: " << priority << endl;
			return;
		}
		
		Level[priority - 1].enqueue(data);
	}

	bool MultiQueueDequeue(int priority) {
		if (priority < 1 || priority > Level.size()) {
			cout << "\nInvalid priority: " << priority << endl;
			return false;
		}

		else if (Level[priority - 1].isEmpty()) {
			cout << "\nQueue at priority " << priority << " is empty." << endl;
			return false;
		}

		Level[priority - 1].dequeue();
		return true;
	}

	void displayQueue() {
		for (int i = 0; i < Level.size(); i++) {
			cout << "\nPriority " << i + 1 << " Queue : ";
			Level[i].display();
		}
		cout << endl;
	}
};

int main() {
	MultiQueue<string> q(4);

	q.MultiQueueEnqueue("Test1", 1); 
	q.MultiQueueEnqueue("Test2", 1);
	q.MultiQueueEnqueue("Test2", 1);
	q.MultiQueueEnqueue("Test2", 1);
	q.MultiQueueEnqueue("Test2", 3);
	q.MultiQueueEnqueue("Test2", 4);
	q.MultiQueueEnqueue("Test2", 4);
	q.MultiQueueEnqueue("Test2", 3);
	q.MultiQueueEnqueue("Test2", 3);
	q.MultiQueueEnqueue("Test2", 4);

	cout << "Queues after enqueuing:" << endl;
	q.displayQueue();

	q.MultiQueueDequeue(2);
	cout << "Queues after dequeuing from priority 2:" << endl;
	q.displayQueue();

	system("pause");
	return 0;
}