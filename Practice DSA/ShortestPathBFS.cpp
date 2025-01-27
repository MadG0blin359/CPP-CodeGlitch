#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsShortestPath(vector<vector<int>> graph, int start, int target) {
    int size = graph.size();
    vector<bool> visited(size, false);
    vector<int> parent(size, -1);
    queue<int> q;

    visited[start] = true;
    q.push(start);
    parent[start] = -1;      // None

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int k : graph[current]) {
            if (!visited[k]) {
                visited[k] = true;
                q.push(k);
                parent[k] = current;

                if (k == target)
                    break;
            }
        }
    }

    vector<int> path;
    if (!visited[target]) {
        cout << "No path found from " << start << " to " << target << endl;
        return path;
    }

    for (int v = target; v != -1; v = parent[v]) {
        path.push_back(v);
    }

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    // Un-weighted example graph as an adjacency list
    vector<vector<int>> graph = {
        {1, 2},    // Neighbors of node 0
        {0, 3, 4}, // Neighbors of node 1
        {0, 5},    // Neighbors of node 2
        {1},       // Neighbors of node 3
        {1, 5},    // Neighbors of node 4
        {2, 4}     // Neighbors of node 5
    };

    int start = 3; // Starting vertex
    int target = 5; // Target vertex
    
    // Find the shortest path
    vector<int> path = bfsShortestPath(graph, start, target);

     // Print the path
    if (!path.empty()) {
        cout << "Shortest path from " << start << " to " << target << ": ";
        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}