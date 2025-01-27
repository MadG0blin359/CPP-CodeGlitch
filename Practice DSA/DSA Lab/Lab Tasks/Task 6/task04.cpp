#include <iostream>
#include <string>
using namespace std;

struct Node {
	string ID;
	int time;
};

class CircularQueue {
	static int const size = 4;
	Node arr[size];
	int front, rear, count;
public:
	CircularQueue() {
		front = rear = -1;
		count = 0;
	}

	bool isEmpty() {
		return (count == 0);
	}

	bool isFull() {
		return (count == size);
	}

	void enqueue(Node process) {
		if (isFull()) {
			cout << "\nQueue is Full!" << endl;
			return;
		}

		if (isEmpty()) {
			front = rear = 0;
		}
		else {
			rear = (rear + 1) % size;
		}

		arr[rear] = process;
		count++;
	}

	Node dequeue() {
		if (isEmpty()) {
			cout << "\nQueue is Empty!" << endl;
		}


		else {
			Node temp = arr[front];

			front = (front + 1) % size;
			count--;

			if (count == 0) {
				front = rear = -1;
			}
			return temp;
		}
		Node temp = arr[front];
		return temp;
	}

	void roundRobinScheduling(CircularQueue& queue, int timeSlice) {
		int currentTime = 0;
		while (!queue.isEmpty()) {
			Node currentProcess = queue.dequeue();
			cout << "\nTime " << currentTime << ": " << currentProcess.ID << " enters the queue. " << currentProcess.ID << " is Processed. ";

			if (currentProcess.time > 0) {
				currentProcess.time -= timeSlice;
				currentTime += timeSlice;
				queue.enqueue(currentProcess);
			}

			else {
				currentTime += timeSlice;
				cout << " " << currentProcess.ID << " is Processed Completely.";
			}
		}
	}
};


int main() {
	CircularQueue queue;

	Node p1 = { "p1", 4 };
	Node p2 = { "p2", 6 };
	Node p3 = { "p3", 2 };
	Node p4 = { "p4", 5 };

	queue.enqueue(p1);
	queue.enqueue(p2);
	queue.enqueue(p3);
	queue.enqueue(p4);

	int timeSlice = 2;

	queue.roundRobinScheduling(queue, timeSlice);
	cout << endl;
	
	system("pause");
	return 0;
}