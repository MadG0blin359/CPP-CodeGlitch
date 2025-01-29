//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//class Graph {
//	vector<vector<int>> mat;
//public:
//	Graph(int size) {
//		mat = vector<vector<int>>(size, vector<int>(size, 0));
//	}
//
//	void printMatrix() const {
//		for (const auto& row : mat) {
//			for (const auto& col : row)
//				cout << col << " ";
//			cout << endl;
//		}
//	}
//
//	void addEdge(int i, int j)
//	{
//		mat[i][j] = 1;
//	}
//
//	void printAdjList() const {
//		for (int i = 0; i < mat.size(); ++i) {
//			 
//			cout << i << ": ";
//			for (int j = 0; j < mat[i].size(); ++j) {
//				if (mat[i][j] == 1) {
//					cout << j << " ";
//				}
//			}
//			cout << endl;
//		}
//	}
//
//	void bfs(int start) {
//		queue<int> q;
//		vector<bool> visited(mat.size(), false);
//
//		q.push(start);
//		visited[start] = true;
//
//		cout << "\nBFS traversal order: ";
//
//		while (!q.empty()) {
//			int vertex = q.front();
//			q.pop();
//
//			cout << vertex << " ";
//
//			
//			for (int neighbor = 0; neighbor < mat[vertex].size(); ++neighbor) {
//				if (mat[vertex][neighbor] == 1 && !visited[neighbor]) { 
//					q.push(neighbor);
//					visited[neighbor] = true;
//				}
//			}
//		}
//		cout << endl;
//	}
//};
//
//int main() {
//	int V = 7;
//	Graph g(V);
//
//	g.addEdge(0, 1);
//	g.addEdge(0, 4);
//	g.addEdge(1, 5);
//	g.addEdge(1, 0);
//	g.addEdge(1, 3);
//	g.addEdge(1, 6);
//	g.addEdge(2, 6);
//	g.addEdge(2, 5);
//	g.addEdge(3, 4);
//	g.addEdge(3, 1);
//	g.addEdge(3, 5);
//	g.addEdge(4, 3);
//	g.addEdge(4, 6);
//	g.addEdge(4, 0);
//	g.addEdge(5, 1);
//	g.addEdge(5, 2);
//	g.addEdge(5, 3);
//	g.addEdge(6, 4);
//	g.addEdge(6, 2);
//	g.addEdge(6, 1);
//
//	cout << "Adjacency Matrix:" << endl;
//	g.printMatrix();
//
//	cout << "\nAdjacency List:" << endl;
//	g.printAdjList();
//
//	g.bfs(0);
//
//	system("pause");
//	return 0;
//}
