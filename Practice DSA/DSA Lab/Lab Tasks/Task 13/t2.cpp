#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Graph {
	vector<vector<int>> mat;
	unordered_map<char, int> vertexMap;  
public:
	Graph(int size) {
		mat = vector<vector<int>>(size, vector<int>(size, 0));
	}

	void addEdge(char i, char j) {
		int u = vertexMap[i];  
		int v = vertexMap[j];  
		mat[u][v] = 1;
		mat[v][u] = 1;  
	}

	void printMatrix() const {
		for (const auto& row : mat) {
			for (const auto& col : row)
				cout << col << " ";
			cout << endl;
		}
	}

	void printAdjList() const {
		for (int i = 0; i < mat.size(); ++i) {
			cout << (char)('a' + i) << ": ";  
			for (int j = 0; j < mat[i].size(); ++j) {
				if (mat[i][j] == 1) {
					cout << (char)('a' + j) << " ";
				}
			}
			cout << endl;
		}
	}

	void mapVertices(const vector<char>& vertices) {
		for (int i = 0; i < vertices.size(); ++i) {
			vertexMap[vertices[i]] = i;
		}
	}
};

int main() {
	vector<char> vertices = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	int V = vertices.size();

	Graph g(V);


	g.mapVertices(vertices);

	g.addEdge('a', 'b');
	g.addEdge('a', 'c');
	g.addEdge('a', 'e');
	g.addEdge('b', 'a');
	g.addEdge('b', 'd');
	g.addEdge('b', 'f');
	g.addEdge('c', 'a');
	g.addEdge('c', 'd');
	g.addEdge('c', 'f');
	g.addEdge('c', 'g');
	g.addEdge('d', 'b');
	g.addEdge('d', 'c');
	g.addEdge('d', 'e');
	g.addEdge('d', 'h');
	g.addEdge('e', 'a');
	g.addEdge('e', 'b');
	g.addEdge('e', 'f');
	g.addEdge('e', 'g');
	g.addEdge('f', 'b');
	g.addEdge('f', 'e');
	g.addEdge('f', 'h');
	g.addEdge('g', 'c');
	g.addEdge('g', 'e');
	g.addEdge('g', 'h');
	g.addEdge('h', 'd');
	g.addEdge('h', 'f');
	g.addEdge('h', 'g');

	cout << "Adjacency Matrix:" << endl;
	g.printMatrix();

	cout << "\nAdjacency List:" << endl;
	g.printAdjList();

	system("pause");
	return 0;
}
