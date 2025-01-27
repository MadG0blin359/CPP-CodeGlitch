#include <iostream>
using namespace std;

template <class T>
class Deque {
	T* dequeArr;
	int size, front, rear;
public:
	Deque(int s) {
		size = s;
		dequeArr = new T[size];
		front = rear = -1;
	}

	bool isEmpty() {
		return (front == -1);
	}

	bool isFull() {
		return ((rear + 1) % size == front);
	}

	void insertFront(T value) {
		if (isFull()) {
			cout << "\n-----Queue Overflow!-----\n";
			return;
		}

		if (isEmpty())
			front = rear = 0;
		else if (front == 0)
			front = size - 1;	// Wrap around
		else
			front--;		// Move front backward

		dequeArr[front] = value;
	}

	void insertBack(T value) {
		if (isFull()) {
			cout << "\n-----Queue Overflow!-----\n";
			return;
		}

		if (isEmpty())
			front = rear = 0;
		else // Wrap around
			rear = (rear + 1) % size;

		dequeArr[rear] = value;
	}

	T removeFront() {
		if (isEmpty()) {
			cout << "\n-----Queue Underflow!-----\n";
			return 0;
		}

		int temp;

		// When only one element
		if (front == rear) {
			temp = dequeArr[front];
			front = rear = -1;
			return temp;
		}

		temp = dequeArr[front];
		front = (front + 1) % size;		// Move front to the next element
		return temp;
	}

	T removeBack() {
		if (isEmpty()) {
			cout << "\n-----Queue Underflow!-----\n";
		}

		else {
			int temp;
			temp = dequeArr[rear];
			
			// When only one element
			if (rear == front)
				front = rear = -1;
			else if (rear == 0)
				rear = size - 1;	// Wrap around
			else
				rear--;

			return temp;
		}
	}

	void display() {
		if (isEmpty()) {
			cout << "\n-----Queue is Empty!-----\n";
			return;
		}

		int f = front, r = rear;

		while (f != r) {
			cout << dequeArr[f] << ", ";
			f = (f + 1) % size;
		}

		cout << dequeArr[rear] << endl;  // Print the last element
	}

	~Deque() {
		delete[] dequeArr;
	}
};

int main() {
	Deque<int> deque(10);

	cout << "\nInserting at Front...";
	deque.insertFront(5);
	deque.insertFront(4);
	deque.insertFront(3);
	deque.insertFront(2);

	cout << "\nInserting at Back...";
	deque.insertBack(6);
	deque.insertBack(7);
	deque.insertBack(8);
	deque.insertBack(9);

	cout << "\nInserting at Front Again...";
	deque.insertFront(1);
	deque.insertFront(0);
	deque.insertFront(11);			// 11th element... Overflow

	cout << "\nDisplaying Deque..." << endl;
	deque.display();

	cout << "\nRemoving at Front...";
	deque.removeFront();
	deque.removeFront();

	cout << "\nRemoving at Back...";
	deque.removeBack();
	deque.removeBack();

	cout << "\nDisplaying Deque..." << endl;
	deque.display();



	cout << endl;
	system("pause");
	return 0;
}