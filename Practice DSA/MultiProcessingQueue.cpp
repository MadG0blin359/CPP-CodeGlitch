#include <iostream>
using namespace std;

template <class T>
class Queue {
	T* arr;
	int front, rear, capacity;
public:
	Queue(int c) {		// Parametrized Constructor
		capacity = c;
		arr = new T[capacity];
		front = rear = -1;
	}

	bool isEmpty() {
		return (front == -1);
	}

	bool isFull() {
		return ((rear + 1) % capacity == front);
	}

	bool enqueue(int num) {
		if (isFull()) {
			cout << "\n-----Queue Overflow!-----\n";
			return false;
		}

		if (isEmpty())
			front = rear = 0;
		else // Wrap around the array
			rear = (rear + 1) % capacity;

		arr[rear] = num;
		return true;
	}

	bool dequeue(int& num) {
		if (isEmpty()) {
			cout << "\n-----Queue Underflow!-----\n";
			return false;
		}

		num = arr[front];

		// When only one element
		if (front == rear)
			front = rear = -1;
		else // Wrap around the array
			front = (front + 1) % capacity;

		return true;
	}

	~Queue() {
		delete[] arr;
	}
};

int main() {
	int N, peopleCount, person;

	// Loops to verify the user inputs
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
			cout << "\n-----The minimum number of people in a queue must be 10!-----\n" << endl;
	} while (peopleCount < 10);

	Queue<int>** line = new Queue<int>*[N];

	for (int i = 0; i < N; i++) {
		line[i] = new Queue<int>(peopleCount);
		cout << "Enqueueing people in Queue " << i << "..." << endl;
		for (int j = 1; j <= peopleCount; j++) {
			line[i]->enqueue(j);
		}
	}

	int lastQueue = N - 1;
	// Variables declared for output formating
	int currentQueue = lastQueue;
	int prevQueue = currentQueue - 1;
	int count = peopleCount;

	cout << "\nProcessing Last Queue - Queue " << lastQueue << "...\n" << endl;
	
	for (int i = lastQueue; i >= 0; i--) {
		cout << "\tQueue " << i;
		cout << "\t\t\t\t";
	}
	cout << "\n-------------------------------------------------------------------------------------------------------------------" << endl;

	// Loop until the last queue is empty
	while (!line[lastQueue]->isEmpty()) {
		
		if (count == 0) {
			currentQueue--;
			count = peopleCount;
			cout << endl;
		}

		line[lastQueue]->dequeue(person);		// Dequeue the front person of the last queue
		cout << "\n--Processing person : " << currentQueue << "-" << person;

		prevQueue = currentQueue - 1;

		// Dequeue from the previous queues and enqueue to the last queue
		for (int i = lastQueue - 1; i >= 0; i--) {
			if (!line[i]->isEmpty()) {
				line[i]->dequeue(person);
				line[i + 1]->enqueue(person);
				cout << "\t; Person : " << prevQueue << "-" << person << " has moved into Queue " << i + 1;
				prevQueue--;	
			}
		}
		count--;
	}

	cout << endl;

	// Clean up memory
	for (int i = 0; i < N; i++)
		delete line[i];

	delete[] line;		// Delete the array of pointers

	system("pause");
	return 0;
}