#include <iostream>
using namespace std;

template <class T>
class Stack;

template <class W>
class Node {
	Node<W>* next;
	W data;
public:
	Node(W d) : next(NULL), data(d) {}
	friend class Stack<W>;
};

template <class T>
class Stack {
	Node<T>* topptr;
public:
	Stack() : topptr(NULL) {}

	bool isEmpty() {
		return (topptr == NULL);
	}

	T top() {
		return topptr->data;
	}

	bool push(T data) {
		Node<T>* newptr = new Node<T>(data);
		if (isEmpty()) {
			topptr = newptr;
			return true;
		}

		newptr->next = topptr;
		topptr = newptr;
		return true;
	}

	void pop() {
		if (isEmpty()) {
			cout << "\nStack Underflow!\n";
			return;
		}

		Node<T>* temp = topptr->next;
		delete topptr;
		topptr = temp;
	}
};

template <class T>
class Queue {
	Stack<T> input, output;			// Composition
public:
	bool isEmpty() {
		return (input.isEmpty() && output.isEmpty());
	}

	T front() {
		if (isEmpty()) {
			cout << "\nQueue is Empty!\n";
			return T();
		}

		if (output.isEmpty()) {
			while (!input.isEmpty()) {
				output.push(input.top());
				input.pop();
			}
		}

		return output.top();
	}

	void enqueue(T data) {
		input.push(data);
	}

	T dequeue() {
		if (isEmpty()) {
			cout << "\nQueue Underflow!\n";
			return T();
		}

		if (output.isEmpty()) {
			while (!input.isEmpty()) {
				output.push(input.top());
				input.pop();
			}
		}

		T temp = output.top();
		output.pop();
		return temp;
	}
};

int main() {
	Queue<int> line;

	cout << "\nEnqueing Elements...";
	line.enqueue(1);
	line.enqueue(2);
	line.enqueue(3);

	cout << "\nFront element is : " << line.front();

	cout << "\nEnqueing More Elements...";
	line.enqueue(4);
	line.enqueue(5);

	while (!line.isEmpty()) {
		cout << "\nDequeing Elements : " << line.dequeue() << " ";
	}

	cout << "\nPress any key to exit...";
	cin.get();
	return 0;
}