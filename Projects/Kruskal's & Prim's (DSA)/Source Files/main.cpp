#include <iostream>
#include "MST.h"
using namespace std;

int main() {
	int V;

	// Prompt the user to enter the number of vertices
	cout << "Enter the number of vertices : ";
	cin >> V;

	MST graph(V);

	graph.insertMatrix();		// Calling function take user input
	graph.kruskalMST();			// Calling function to calculate kruskal's MST
	graph.primsMST();			// // Calling function to calculate Prim's MST

	system("pause");
	return 0;
}