#include <iostream>
#include <vector>
using namespace std;

class MST {
	vector<vector<int>> mat;
	int vertices;
public:
    // Constructor to initialize the graph with V vertices
	MST(int V) {
		vertices = V;			// (rows, vector<int>(vertices));
		mat = vector<vector<int>>(vertices, vector<int>(vertices));
	}

    // Function to input the adjacency matrix from the user
	void insertMatrix() {
		cout << "Enter the adjacency matrix (use O for no edge): " << endl;
		for (int row = 0; row < mat.size(); row++) {
			for (int col = 0; col < mat[row].size(); col++) {
				cin >> mat[row][col];
			}
		}
		cout << endl;
	}

    // Function to calculate and display the Minimum Spanning Tree using Prim's algorithm
	void primsMST() {
		vector<int> key(vertices, 1000);    // Stores the minimum edge weight for each vertex
        vector<bool> inMST(vertices, false); // Tracks vertices included in the MST
        vector<int> parent(vertices, -1);   // Stores the parent of each vertex in the MST
        key[0] = 0;                         // Start from the first vertex
        int mstWeight = 0;                  // Total weight of the MST

		cout << "\nPrim's MST:\n";

        // Loop to construct the MST with (vertices - 1) edges
		for (int count = 0; count < vertices - 1; count++) {
			
			int minKey = 1000, u = -1;
			for (int v = 0; v < vertices; v++) {
				if (!inMST[v] && key[v] < minKey) {
					minKey = key[v];
					u = v;
				}
			}

			inMST[u] = true; 

			
			for (int v = 0; v < vertices; v++) {
				if (mat[u][v] != 0 && mat[u][v] != 1000 && !inMST[v] && mat[u][v] < key[v]) {
					key[v] = mat[u][v];
					parent[v] = u;
				}
			}
		}

        // Display the edges and their weights in the MST
		for (int v = 1; v < vertices; v++) {
			if (parent[v] != -1) {
				cout << parent[v] << " - " << v << "\tWeight: " << mat[parent[v]][v] << endl;
				mstWeight += mat[parent[v]][v];
			}
		}
		
		cout << "Minimum cost using Prim's: " << mstWeight << endl;
	}
};

int main() {
	int V;

	// Prompt the user to enter the number of vertices
	cout << "Enter the number of vertices : ";
	cin >> V;

	MST graph(V);

	graph.insertMatrix();		// Calling function take user input
	graph.primsMST();			// Calling function to calculate Prim's MST

	system("pause");
	return 0;
}