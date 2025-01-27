#include <iostream>
#include <vector>
using namespace std;

void primMST() {
    vector<int> key(V, INT_MAX);       // Initialize the key values for all vertices to infinity.
    vector<bool> mstSet(V, false);     // Initialize the MST set to false for all vertices.
    vector<int> parent(V, -1);         // Initialize the parent array to store the MST.

    // Loop to find the minimum spanning tree
    for (int count = 0; count < V; count++) {
        int u = -1;

        // Find the vertex with the minimum key value that is not yet included in MST
        for (int i = 0; i < V; i++) {
            if (mstSet[i] != true && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        mstSet[u] = true; // Include the selected vertex in the MST

        // Update the key values and parent index of the adjacent vertices
        for (int v = 0; v < V; v++) {
            if (matrix[u][v] && !mstSet[v] && matrix[u][v] < key[v]) {
                key[v] = matrix[u][v];  // Update the key value
                parent[v] = u;          // Update the parent index
            }
        }
    }

    // Print the constructed MST
    cout << "\nEdge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << matrix[i][parent[i]] << " \n";
    }
}