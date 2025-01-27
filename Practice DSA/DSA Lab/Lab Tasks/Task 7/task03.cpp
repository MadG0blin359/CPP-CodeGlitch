#include <iostream>
using namespace std;

class Node {
	Node* next;
	int data;
public:
	Node(int d) : data(d), next(NULL) {}

	friend class CircularQueue;
	friend class CircularDeque;
};

class CircularQueue {
	Node* front, * rear;
	int count;
public:
	CircularQueue() : front(NULL), rear(NULL), count(0) {}

	bool isEmpty() {
		return (front == NULL);
	}

	void enqueue(int num) {
		Node* newptr = new Node(num);

		if (isEmpty()) {
			front = rear = newptr;
			rear->next = front;
			count++;
			cout << "Total Elememts : " << count << endl;

			return;
		}

		rear->next = newptr;
		rear = newptr;
		rear->next = front;
		count++;
		cout << "Total Elememts : " << count << endl;

	}

	bool dequeue(int& num) {
		if (isEmpty()) {
			cout << "\nQueue is empty!\n";
			return false;
		}

		Node* temp = front;
		num = front->data;
		front = front->next;
		rear->next = front;
		count--;
		cout << "\nDequeue Total Elememts : " << count << endl;
		delete temp;
		return true;
	}

	bool peek(int& num) {
		if (isEmpty()) {
			return false;
		}

		num = front->data;
		return true;
	}

	void makeNULL() {
		if (isEmpty()) {
			return;
		}

		Node* temp = front;
		cout << "\nTotal Elememts : " << count << endl;
		while (front != rear) {
			temp = front;
			front = front->next;
			delete temp;
			count--;
			cout << "Elememts Remaining : " << count << endl;
		}
	}

	~CircularQueue() {
		makeNULL();
	}
};

class CircularDeque {
	int* arr;
	int front, rear, capacity, count;
public:
	CircularDeque(int size) {
		capacity = size;
		arr = new int[capacity];
		front = rear = -1;
		count = 0;
	}

	~CircularDeque() {
		delete[] arr;
	}

	
	bool isFull() {
		return (count == capacity);
	}

	
	bool isEmpty() {
		return (count == 0);
	}

	
	void insertFront(int value) {
		if (isFull()) {
			cout << "Deque is full!" << endl;
			return;
		}

		if (isEmpty()) {
			front = rear = 0;
		}

		else {
			front = (front - 1 + capacity) % capacity; 
		}

		arr[front] = value;
		count++;
	}

	
	void insertRear(int value) {
		if (isFull()) {
			cout << "Deque is full. Cannot insert " << value << " at rear." << endl;
			return;
		}
		if (isEmpty()) {
			front = rear = 0;
		}
		else {
			rear = (rear + 1) % capacity; 
		}
		arr[rear] = value;
		count++;
	}

	
	void deleteFront() {
		if (isEmpty()) {
			cout << "Deque is empty!" << endl;
			return;
		}
		if (front == rear) { 
			front = rear = -1;
		}
		else {
			front = (front + 1) % capacity; 
		}
		count--;
	}

	
	void deleteRear() {
		if (isEmpty()) {
			cout << "Deque is empty. Cannot delete from rear." << endl;
			return;
		}
		if (front == rear) { 
			front = rear = -1;
		}
		else {
			rear = (rear - 1 + capacity) % capacity; 
		}
		count--;
	}

	
	int getFront() {
		if (isEmpty()) {
			cout << "Deque is empty." << endl;
			return -1; 
		}
		return arr[front];
	}

	
	int getRear() {
		if (isEmpty()) {
			cout << "Deque is empty." << endl;
			return -1; 
		}
		return arr[rear];
	}

};

int main() {
	CircularQueue line1;
	CircularDeque line2(10);
	char choice;
	int num;

	do {
		cout << "\n-----Circular Queues-----"
			<< "\n1. Circular Queue"
			<< "\n2. Circular Deque"
			<< "\n0. Exit"
			<< "\n--Enter choice : ";
		cin >> choice;

		if (choice == '1') {
			cout << "-----Circular Queue-----"
				<< "\n1. Enqueue"
				<< "\n2. Dequeue"
				<< "\n3. Peek"
				<< "\n--Enter choice : ";
			cin >> choice;

			switch (choice)
			{
			case '1':
				cout << "\nEnter Number : ";
				cin >> num;
				line1.enqueue(num);
				break;
			case '2':
				line1.dequeue(num);
				cout << "\n" << num;
				break;
			case '3':
				line1.peek(num);
				cout << "\nFront : " << num << endl;
				break;
			default:
				cout << "\n-----Invalid Input!-----\n";
				break;
			}
		}

		else if (choice == '2') {
			cout << "-----Circular Dequeue-----"
				<< "\n1. Enqueue Front"
				<< "\n2. Dequeue Front"
				<< "\n3. Peek Front"
				<< "\n4. Enqueue Rear"
				<< "\n5. Dequeue Rear"
				<< "\n6. Peek Rear"
				<< "\n--Enter choice : ";
			cin >> choice;

			switch (choice)
			{
			case '1':
				cout << "\nEnter Number : ";
				cin >> num;
				line2.insertFront(num);
				break;
			case '2':
				line2.deleteFront();
				cout << "\nFront Deleted!" << endl;
				break;
			case '3':
				cout << "\nFront : " << line2.getFront();
				break;
			case '4':
				cout << "\nEnter Number : ";
				cin >> num;
				line2.insertRear(num);
				break;
			case '5':
				line2.deleteRear();
				cout << "\nRear Deleted!" << endl;
				break;
			case '6':
				cout << "\nRear : " << line2.getRear();
				break;
			default:
				cout << "\n-----Invalid Input!-----\n";
				break;
			}
		}

		else if (choice == '0') {
			cout << "\n-----Program Terminated!-----\n";
		}

		else {
			cout << "\n-----Invalid Input!-----\n";
		}

	} while (choice != '0');

	system("pause");
	return 0;
}