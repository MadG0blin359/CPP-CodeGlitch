#include <iostream>
using namespace std;

class MinHeap {
	int* arr;
	int capacity, size;

public:
	MinHeap(int cap) {
		size = 0;
		capacity = cap;
		arr = new int[capacity + 1];  // 1-based indexing, allocate size+1
	}

	void insertKey(int key) {
		if (size == capacity) {
			cout << "\nOverflow: Could not insertKey\n";
			return;
		}

		size++;
		int i = size;  // 1-based index for heap
		arr[i] = key;

		percolateUp(i);
	}

	void percolateUp(int i) {
		int parent = i / 2; 
		while (i > 1 && arr[parent] > arr[i]) {
			swap(&arr[i], &arr[parent]);
			i = parent;
			parent = i / 2;
		}
	}

	void swap(int *x, int *y) {
		int temp = *x;
		*x = *y;
		*y = temp;
	}

	void display() {
		for (int i = 1; i <= size; i++) { 
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	~MinHeap() {
		delete[] arr;  // Free allocated memory
	}
};

int main() {
	int tree_size = 15;
	MinHeap minheap(tree_size); 

	cout << "\nInserting Elements...\n";
	minheap.insertKey(13);
	minheap.insertKey(21);
	minheap.insertKey(16);
	minheap.insertKey(24);
	minheap.insertKey(31);
	minheap.insertKey(19);
	minheap.insertKey(68);
	minheap.insertKey(65);
	minheap.insertKey(26);
	minheap.insertKey(32);

	cout << "\nElements Inserted Successfully!...\n";
	minheap.display();

	cout << "\nInserting Elements 14 & 25...\n";
	minheap.insertKey(14);
	minheap.insertKey(25);

	cout << "\nInserted Elements Successfully!...\n";
	minheap.display();

	return 0;
}
