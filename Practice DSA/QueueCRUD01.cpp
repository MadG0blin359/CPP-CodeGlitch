#include <iostream>
using namespace std;

class Queue {
	int* queueArray;
	int front, rear, queueSize;
public:
	Queue(int s) {
		queueSize = s;
		queueArray = new int[queueSize];
		front = rear = -1;
	}

	bool isEmpty() const {
		return (front == -1);
	}

	bool isFull() const {
		return ((rear + 1) % queueSize == front);
	}

	bool enqueue(int num) {
		if (isFull()) {
			cout << "\nOverflow!\n";
			return false;
		}

		if (isEmpty())
			front = rear = 0;

		else // Wrap around the array
			rear = (rear + 1) % queueSize;

		queueArray[rear] = num;
		return true;
	}

	bool dequeue(int& num) {
		if (isEmpty()) {
			cout << "\nUnderflow!\n";
			return false;
		}

		num = queueArray[front];

		// When only one element
		if (front == rear)
			front = rear = -1;
		else // Wrap around the array
			front = (front + 1) % queueSize;

		return true;
	}

	void makeNULL() {
		front = rear = -1;
	}

	~Queue() {
		delete[] queueArray;
	}
};

int main() {
	Queue line(5);
	int x;

	cout << "Enqueing 5 Elements...\n";
	for (int x = 0; x < 5; x++) {
		line.enqueue(x);
	}

	cout << "Now attempting to enqueue again...\n";
	line.enqueue(5);

	cout << "The values in the queue were:\n";
	while (!line.isEmpty()) {
		line.dequeue(x);
		cout << x << endl;
	}

	system("pause");
	return 0;
}