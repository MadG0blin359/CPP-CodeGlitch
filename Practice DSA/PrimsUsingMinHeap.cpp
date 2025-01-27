#include <iostream>
#include <vector>
using namespace std;

struct Edge {
	int src, dest, weight;
	Edge(int s = 0, int d = 0, int w = 0) : src(s), dest(d), weight(w) {}
};

class MinHeap {
	Edge* heap;
	int size, capacity;

	void swap(Edge& x, Edge& y) {
		Edge temp = x;
		x = y;
		y = temp;
	}

	void percolateUp(int index) {
		while (true) {
			int parent = index / 2;
			if (heap[index].weight < heap[parent].weight && parent > 0)
				swap(heap[index], heap[parent]);
			else
				break;
		}
	}

public:
	MinHeap(int c) {
		capacity = c;
		heap = new Edge[capacity];
		size = 0;
	}
	
	Edge heapFront() {
		return heap[1];
	}

	bool isEmpty() const {
		return (size == 0);
	}

	void insertHeap(Edge data) {
		heap[++size] = data;		// 1-indexed
		percolateUp(size);
	}
};

class Prim {
	Edge* mst;		// Total Edges in MST = Vertices - 1
	int size;
public:
	Prim(int s) {
		size = s;
		mst = new Edge[size];
	}

	void primsMst(vector<vector<int>>& graph, int start) {
		vector<bool> inMST(graph.size(), false);
		MinHeap pq(size * size);	// V^2 possible edges
		int edgeCount = 0;
		
		
		while (edgeCount < size) {

			for (int i = 0; i < size; i++) {

			}
		}


	}
};

int main() {
	int const vertices = 5;
	vector<vector<int>> graph = {
		{0, 2, 0, 6, 0},
		{2, 0, 3, 8, 5},
		{0, 3, 0, 0, 7},
		{6, 8, 0, 0, 9},
		{0, 5, 7, 9, 0}
	};

	Prim mst(vertices);

	mst.primsMst(graph, 0);

	system("pause");
	return 0;
}