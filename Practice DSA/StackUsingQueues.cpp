#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int d) : data(d), next(NULL) {}
};

class Queue {
	int numOfItems;
	Node* front, * rear;
public:
	Queue() : numOfItems(0), front(NULL), rear(NULL) {}

	bool isEmpty() {
		return (front == NULL);
	}

	int getFront() {
		if (isEmpty())
			return -1;

		return front->data;
	}

	void push(int val) {
		if (isEmpty()) {
			front = rear = new Node(val);
			numOfItems++;
			return;
		}

		rear->next = new Node(val);
		rear = rear->next;
		numOfItems++;
	}

	bool pop() {
		if (isEmpty())
			return false;

		Node* temp = front->next;
		delete front;
		front = temp;
		numOfItems--;
	}

	void swap(Queue& other) {
		Node* temp = other.front;
		other.front = this->front;
		this->front = temp;

		temp = other.rear;
		other.rear = this->rear;
		this->rear = temp;
	}

};

// Push Expensive
class Stack {
	Queue q1, q2;
public:
	int top() {
		if (q1.isEmpty())
			return -1;
		return q1.getFront();
	}

	void push(int val) {
		q2.push(val);

		while (!q1.isEmpty()) {
			q2.push(q1.getFront());
			q1.pop();
		}

		q2.swap(q1);
	}

	int pop() {
		int temp = q1.getFront();
		q1.pop();
		return temp;
	}

	bool isEmpty() {
		return (q1.isEmpty());
	}
};

int main() {
	Stack stack;  // Create an instance of Stack
	int choice, value;

	while (true) {
		cout << "\n--- Stack Operations Menu ---" << endl;
		cout << "1. Push an element" << endl;
		cout << "2. Pop an element" << endl;
		cout << "3. View the top element" << endl;
		cout << "4. Check if the stack is empty" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter a value to push: ";
			cin >> value;
			stack.push(value);
			cout << value << " has been pushed to the stack." << endl;
			break;

		case 2:
			if (stack.top() == -1) {
				cout << "Stack is empty. Nothing to pop." << endl;
			}
			else {
				cout << "Popped element: " << stack.pop() << endl;
			}
			break;

		case 3:
			value = stack.top();
			if (value == -1) {
				cout << "Stack is empty. No top element." << endl;
			}
			else {
				cout << "Top element: " << value << endl;
			}
			break;

		case 4:
			if (stack.isEmpty()) {
				cout << "Stack is empty!" << endl;
			}
			else {
				cout << "Stack is NOT empty!" << endl;
			}
			break;

		case 5:
			cout << "-----Program Terminated!-----" << endl;
			return 0;

		default:
			cout << "-----Invalid Input!-----" << endl;
		}
	}

	system("pause");
	return;
}