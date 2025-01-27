#include <iostream>
using namespace std;

class MinHeap {
	int* arr;
	int capacity, size;

public:
	MinHeap(int cap) {
		size = 0;
		capacity = cap;
		arr = new int[capacity + 1];  // 1-based indexing, allocate size + 1
	}

	void insertKey(int key) {
		if (size == capacity) {
			cout << "\nOverflow: Could not insertKey\n";
			return;
		}

		size++;
		int i = size;
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

	void deleteMin() {
		if (size <= 0) {
			cout << "Heap is empty, cannot delete!" << endl;
			return;
		}

		arr[1] = arr[size];
		size--;
		percolateDown(1);
	}

	void percolateDown(int i) {
		int left = 2 * i;
		int right = 2 * i + 1;
		int smallest = i;

		if (left <= size && arr[left] < arr[smallest]) {
			smallest = left;
		}

		if (right <= size && arr[right] < arr[smallest]) {
			smallest = right;
		}

		if (smallest != i) {
			swap(&arr[i], &arr[smallest]);
			percolateDown(smallest); 
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
		delete[] arr;
	}
};

int main() {
	int tree_size = 31;
	MinHeap minheap(tree_size);

	cout << "\nInserting Elements...\n";
	minheap.insertKey(12);
	minheap.insertKey(17);
	minheap.insertKey(15);
	minheap.insertKey(25);
	minheap.insertKey(19);
	minheap.insertKey(19);
	minheap.insertKey(41);
	minheap.insertKey(32);
	minheap.insertKey(33);
	minheap.insertKey(55);
	minheap.insertKey(31);
	minheap.insertKey(58);
	minheap.insertKey(42);
	minheap.insertKey(89);
	minheap.insertKey(39);
	minheap.insertKey(53);
	minheap.insertKey(88);
	minheap.insertKey(36);

	cout << "\nHeap After Insertions: ";
	minheap.display();

	cout << "\nDeleting Minimum Element (root)...\n";
	minheap.deleteMin();

	cout << "Heap After Deletion: ";
	minheap.display();

	return 0;
}
