//#include <iostream>
//using namespace std;
//
//class Node {
//	Node* next;
//	int data;
//public:
//	Node(int d) : data(d), next(NULL) {}
//
//	friend class Queue;
//};
//
//class Queue {
//	Node* front, * rear;
//	int count;
//public:
//	Queue() : front(NULL), rear(NULL), count(0) {}
//
//	bool isEmpty() {
//		return (front == NULL);
//	}
//
//	void enqueue(int num) {
//		Node* newptr = new Node(num);
//
//		if (isEmpty()) {
//			front = rear = newptr;
//			count++;
//			cout << "Total Elememts : " << count << endl;
//
//			return;
//		}
//
//		rear->next = newptr;
//		rear = newptr;
//		count++;
//		cout << "Total Elememts : " << count << endl;
//
//	}
//
//	bool dequeue(int& num) {
//		if (isEmpty()) {
//			cout << "\nQueue is empty!\n";
//			return false;
//		}
//
//		Node* temp = front;
//		num = front->data;
//		front = front->next;
//		count--;
//		cout << "\nDequeue Total Elememts : " << count << endl;
//		delete temp;
//		return true;
//	}
//
//	bool peek(int& num) {
//		if (isEmpty()) {
//			return false;
//		}
//
//		num = front->data;
//		return true;
//	}
//
//	void makeNULL() {
//		if (isEmpty()) {
//			return;
//		}
//
//		Node* temp = front;
//		cout << "\nTotal Elememts : " << count << endl;
//		while (front != NULL) {
//			temp = front;
//			front = front->next;
//			delete temp;
//			count--;
//			cout << "Elememts Remaining : " << count << endl;
//		}
//	}
//
//	~Queue() {
//		makeNULL();
//	}
//};
//
//int main() {
//	Queue line;
//
//	int num;
//	cout << "\nDequeue elements : ";
//	line.dequeue(num);
//
//	cout << "\nEnqueuing elements...\n";
//	line.enqueue(1);
//	line.enqueue(2);
//	line.enqueue(3);
//	line.enqueue(4);
//	line.enqueue(5);
//
//	line.peek(num);
//	cout << "\nPeek elements : " << num << endl;
//
//	line.dequeue(num);
//	cout << "Dequeue elements : " << num << endl;
//
//	line.dequeue(num);
//	cout << "Dequeue elements : " << num << endl;
//
//	line.dequeue(num);
//	cout << "Dequeue elements : " << num << endl;
//
//	line.peek(num);
//	cout << "\nPeek elements : " << num << endl;
//
//	cout << "\nMake NULL...";
//	line.makeNULL();
//
//	cout << "\nPeek elements : " << endl;
//
//	if (line.peek(num))
//		cout << num;
//	else
//		cout << "\nQueue is empty!\n";
//
//	system("pause");
//	return 0;
//}