#include<iostream>
using namespace std;

class MinHeap {
	int* heap;
	int capacity, size;

	bool isEmpty() const {
		return (size == 0);
	}

	bool isFull() const {
		return (size == capacity);
	}

	// Function to resize the heap when it's full
	void resize() {
		int* newHeap = new int[capacity * 2 + 1];
		for (int i = 0; i < size; i++) {
			newHeap[i] = heap[i];
		}
		delete[] heap;
		heap = newHeap; 
		capacity = (capacity * 2) + 1;
	}

	void percolateDown(int i) {
		int temp;
		while (true) {
			int left = 2 * i + 1;
			int right = 2 * i + 2;
			int smallest = i;

			// Check left child
			if (left < size && heap[left] < heap[smallest]) {
				smallest = left;
			}

			// Check right child
			if (right < size && heap[right] < heap[smallest]) {
				smallest = right;
			}

			// If no swapping is needed, break
			else if (smallest == i) {
				break;
			}
			
			temp = heap[i];
			heap[i] = heap[smallest];
			heap[smallest] = temp;
			i = smallest;
		}
	}

public:
	MinHeap(int cap) {
		capacity = cap;
		heap = new int[capacity];
		size = 0;
	}

	void buildHeap(int arr[]) {
		if (isFull()) {
			resize();
		}

		// Build Heap
		for (int i = 0; i < capacity; i++) {
			heap[i] = arr[i];
			++size;
		}

		// Heapify
		for (int i = ((size / 2) - 1); i >= 0; i--) {
			percolateDown(i);
		}
	}

	int getMinimum() {
		if (isEmpty())
			return -1;

		int min = heap[0];
		heap[0] = heap[size - 1];
		--size;

		percolateDown(0);
		return min;
	}

	// Utility function to print the heap
	void printHeap() {
		for (int i = 0; i < size; i++) {
			cout << heap[i] << " ";
		}
		cout << endl;
	}

	~MinHeap() {
		delete[] heap;
	}
};

int main() {
	int arr[] = { 5,4,3,2,8,6,1,7 };
	const int size = sizeof(arr) / sizeof(arr[0]);

	MinHeap heap(size);

	cout << "Building Heap..." << endl;
	heap.buildHeap(arr);
	cout << "Print Heap : ";
	heap.printHeap();

	system("pause");
	return 0;
}