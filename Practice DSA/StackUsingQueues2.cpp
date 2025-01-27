#include <iostream>
using namespace std;

class Queue {
	int* queueArray;
	int capacity;
	int front, rear, size;
public:
	Queue(int c) {
		capacity = c;
		size = 0;
		front = rear = -1;
		queueArray = new int[capacity];
	}

	bool isEmpty() {
		return (front == -1);
	}

	bool isFull() {
		return ((rear + 1) % capacity == front);
	}

	int getFront() {
		return (queueArray[front]);
	}

	bool enqueue(int val) {
		if (isFull())
			return false;

		if (isEmpty())
			front = rear = 0;
		else
			rear = (rear + 1) % capacity;

		queueArray[rear] = val;
		size++;
		return true;
	}

	bool dequeue() {
		if (isEmpty())
			return false;

		if (front == rear)
			front = rear = -1;
		else
			front = (front + 1) % capacity;
		
		size--;
		return true;
	}

	~Queue() {
		delete[] queueArray;
	}
};

class Stack {
	Queue q1, q2;
public:
	Stack(int capacity) : q1(capacity), q2(capacity) {}

	void swap() {
		Queue temp = q1;
		q1 = q2;
		q2 = temp;
	}

	void push(int val) {
		q2.enqueue(val);

		while (!q1.isEmpty()) {
			q2.enqueue(q1.getFront());
			q1.dequeue();
		}

		swap();
	}

	bool pop(int& data) {
		if (q1.isEmpty())
			return false;

		data = q1.getFront();
		q1.dequeue();
		return true;
	}
};

int main() {
	Stack s1(10);

	system("pause");
	return 0;
}