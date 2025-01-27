#include <iostream>
using namespace std;

class MaxHeap {
private:
	int* arr;
	int size;
	int capacity;

public:
	MaxHeap(int cap) {
		size = 0;
		capacity = cap;
		arr = new int[capacity];
	}

	void swap(int &x, int &y) {
		int temp = x;
		x = y;
		y = temp;
	}

	void heapify(int i) {
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (left < size && arr[left] > arr[largest]) {
			largest = left;
		}

		if (right < size && arr[right] > arr[largest]) {
			largest = right;
		}

		if (largest != i) {
			swap(arr[i], arr[largest]);
			heapify(largest);
		}
	}

	void buildMaxHeap() {
		for (int i = (size / 2) - 1; i >= 0; i--) {
			heapify(i);
		}
	}

	void insert(int key) {
		if (size == capacity) {
			cout << "Overflow: Cannot insert key\n";
			return;
		}

		size++;
		arr[size - 1] = key;
	}

	void display() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	~MaxHeap() {
		delete[] arr;
	}
};

int main() {
	int arr[] = {23,19,72,65,15,53,59,79,30,10,90};
	int n = 11;

	MaxHeap maxHeap(n);

	for (int i = 0; i < n; i++) {
		maxHeap.insert(arr[i]);
	}

	cout << "the unsorted array: ";
	maxHeap.display();

	maxHeap.buildMaxHeap();

	cout << "after heapifying: ";
	maxHeap.display();

	system("pause");
	return 0;
}
