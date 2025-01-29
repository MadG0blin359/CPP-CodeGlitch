#include <iostream>
using namespace std;

class Queue {
	int* arr;
	int front, rear, size;
public:
	Queue(int s) {
		size = s;
		arr = new int[size];
		front = rear = -1;
	}

	bool isEmpty() {
		return (front == -1);
	}

	bool isFull() {
		return (front == rear);
	}

	bool peek(int &num) {
		if (isEmpty()) {
			return false;
		}

		num = arr[front];

		return true;
	}

	void enqueue(int num) {
		if (isEmpty()) {
			front = rear = 0;
		}

		else {
			rear = (rear + 1) % size;
		}

		arr[rear] = num;
	}

	bool dequeue(int &num) {
		if (isEmpty()) {
			cout << "\nQueue is empty!\n";
			return false;
		}

		if (front == rear) {
			num = arr[front];
			front = rear = -1;
			return true;
		}

		num = arr[front];
		front = (front + 1) % size;
		return true;
	}

	void makeNULL() {
		front = rear = -1;
	}

	~Queue() {
		delete[] arr;
	}
};

int main() {
	Queue line(5);
	int num;
	cout << "\nDequeue elements : ";
	line.dequeue(num);

	cout << "\nEnqueue elements...\n";
	line.enqueue(7);
	line.enqueue(5);
	line.enqueue(8);
	line.enqueue(6);
	line.enqueue(7);

	line.peek(num);
	cout << "\nPeek elements : " << num << endl;

	line.dequeue(num);
	cout << "\nDequeue elements : " << num << endl;

	line.dequeue(num);
	cout << "\nDequeue elements : " << num << endl;

	line.dequeue(num);
	cout << "\nDequeue elements : " << num << endl;

	line.peek(num);
	cout << "\nPeek elements : " << num << endl;

	cout << "\nMake NULL...";
	line.makeNULL();

	cout << "\nPeek elements : " << endl;
	
	if (line.peek(num))
		cout << num;
	else 
		cout << "\nQueue is empty!\n";

	system("pause");
	return 0;
}