#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// DSU (Disjoint Set Union) class for union-find operations
class DSU {
	vector<int> parent, rank;

public:
	DSU(int n) {
		parent.resize(n, -1);
		rank.resize(n, 1);
	}

	// Find operation with path compression
	int find(int i) {
		if (parent[i] == -1)
			return i;
		return parent[i] = find(parent[i]);
	}

	// Union operation by rank
	void unite(int x, int y) {
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
			}
			else if (rank[s1] > rank[s2]) {
				parent[s2] = s1;
			}
			else {
				parent[s2] = s1;
				rank[s1]++;
			}
		}
	}
};

class MST {
	vector<vector<int>> mat;
	int vertices;
public:
	MST(int V) {
		vertices = V;			// (rows, vector<int>(vertices));
		mat = vector<vector<int>>(vertices, vector<int>(vertices));
	}

	void insertMatrix() {
		cout << "Enter the adjacency matrix (use O for no edge): " << endl;
		for (int row = 0; row < mat.size(); row++) {
			for (int col = 0; col < mat[row].size(); col++) {
				cin >> mat[row][col];
			}
		}
		cout << endl;
	}

	void kruskalMST() {
		vector<vector<int>> edges; // {weight, u, v}

        // Extract edges from the adjacency matrix
        for (int i = 0; i < vertices; i++) {
            for (int j = i + 1; j < vertices; j++) { // Avoid duplicate edges
                if (mat[i][j] != 0) {  // Only consider non-zero edges
                    edges.push_back({ mat[i][j], i, j });
                }
            }
        }

        // Sort edges based on weight
        sort(edges.begin(), edges.end());

        DSU dsu(vertices);
        int mstWeight = 0;

        cout << "Kruskal's MST:" << endl;

        for (auto edge : edges) {
            int weight = edge[0];
            int u = edge[1];
            int v = edge[2];

            // Check if including this edge forms a cycle
            if (dsu.find(u) != dsu.find(v)) {
                dsu.unite(u, v);
                mstWeight += weight;
                cout << u << " - " << v << "\tWeight: " << weight << endl;
            }
        }
        // Output the total cost
        cout << "Minimum cost using Kruskal's: " << mstWeight << endl;
    }

	// Function to implement Prim's algorithm
	void primsMST() {
		vector<int> key(vertices, 1000);   // Values used to pick minimum weight edge
		vector<bool> inMST(vertices, false); // keep track of vertices included in MST
		vector<int> parent(vertices, -1);    // store the constructed MST
		key[0] = 0;                   // Starting from first vertex
		int mstWeight = 0;

		cout << "\nPrim's MST:\n";

		for (int count = 0; count < vertices - 1; count++) {
			// Find the minimum key value vertex that isn't in MST yet
			int minKey = 1000, u = -1;
			for (int v = 0; v < vertices; v++) {
				if (!inMST[v] && key[v] < minKey) {
					minKey = key[v];
					u = v;
				}
			}

			inMST[u] = true; // Add the chosen vertex to MST

			// Update key and parent for adjacent vertices
			for (int v = 0; v < vertices; v++) {
				if (mat[u][v] != 0 && mat[u][v] != 1000 && !inMST[v] && mat[u][v] < key[v]) {
					key[v] = mat[u][v];
					parent[v] = u;
				}
			}
		}

		// Display MST edges and calculate total weight
		for (int v = 1; v < vertices; v++) {
			if (parent[v] != -1) {
				cout << parent[v] << " - " << v << "\tWeight: " << mat[parent[v]][v] << endl;
				mstWeight += mat[parent[v]][v];
			}
		}
		// Output the total cost
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
	graph.kruskalMST();			// Calling function to calculate kruskal's MST
	graph.primsMST();			// // Calling function to calculate Prim's MST

	system("pause");
	return 0;
}