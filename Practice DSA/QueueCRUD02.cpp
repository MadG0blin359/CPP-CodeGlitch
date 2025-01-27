#include <iostream>
using namespace std;

template <class T>
class Queue {
	T* queueArray;
	int front, rear, queueSize;
public:
	Queue(int);
	bool isEmpty();
	bool isFull();
	bool enqueue(int);
	bool dequeue(int&);
	~Queue();
};

template <class T>
Queue<T>::Queue(int s) {
	queueSize = s;
	queueArray = new T[queueSize];
	front = rear = -1;
}

template <class T>
bool Queue<T>::isEmpty() {
	return (front == -1);
}

template <class T>
bool Queue<T>::isFull() {
	return ((rear + 1) % queueSize == front);
}

template <class T>
bool Queue<T>::enqueue(int num) {
	if (isFull()) {
		cout << "\n-----Queue Overflow!-----\n";
		return false;
	}

	if (isEmpty())
		front = rear = 0;
	else // Wrap around the array
		rear = (rear + 1) % queueSize;

	queueArray[rear] = num;
	return true;
}

template <class T>
bool Queue<T>::dequeue(int& num) {
	if (isEmpty()) {
		cout << "\n-----Queue Underflow!-----\n";
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

template <class T>
Queue<T>::~Queue() {
	delete[] queueArray;
}

int main() {
	int N = 1, peopleCount, person;

	do {
		cout << "\n--Enter the number of queues: ";
		cin >> N;

		if (N < 1)
			cout << "\n-----Invalid Input!-----\n";
	} while (N < 1);

	do {
		cout << "\n--Enter the number of people in each queue (minimum 10) : ";
		cin >> peopleCount;

		if (peopleCount < 10)
			cout << "\n-----The minimum number of people in a queue must be 10!-----\n";
	} while (peopleCount < 10);

	// line is a pointer to an array of pointers.
	Queue<int>** line = new Queue<int>*[N];

	for (int i = 0; i < N; i++) {
		line[i] = new Queue<int>(peopleCount);
		cout << "\nEnqueueing people in Queue " << i + 1 << "..." << endl;
		for (int j = 1; j <= peopleCount; j++) {
			line[i]->enqueue(j);
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		cout << "\nProcessing Queue " << i + 1 << "..." << endl;
		while (!line[i]->isEmpty()) {
			line[i]->dequeue(person);
			cout << "\n--Processing person: " << person;
		}
		cout << "\n-----Queue " << i + 1 << " is now empty-----\n";
	}

	// Clean up memory
	for (int i = 0; i < N; ++i) {
		delete line[i];  // Delete each queue
	}

	delete[] line;  // Delete the array of pointers

	system("pause");
	return 0;
}