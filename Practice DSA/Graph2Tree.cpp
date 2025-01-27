#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> Graph2Tree(vector<vector<int>> graph) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    int vertex = graph[0][0];
    vector<vector<int>> tree;
    tree[0][0] = vertex;

    visited[vertex] = true;
    q.push(vertex);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (auto k : graph[current]) {
            if (!visited[k]) {
                visited[k] = true;
                q.push(k);
                tree[current].push_back(k);
            }
        }
    }

    return tree;
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

    vector<vector<int>> tree = Graph2Tree(graph);

    system("pause");
    return 0;
}