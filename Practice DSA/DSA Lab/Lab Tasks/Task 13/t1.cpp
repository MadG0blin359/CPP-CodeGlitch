//#include <iostream>
//#include <vector>
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
//	void countEdgesPerNode() const {
//		for (int i = 0; i < mat.size(); ++i) {
//			int outgoingCount = 0;
//			for (int j = 0; j < mat[i].size(); ++j) {
//				if (mat[i][j] == 1) {
//					outgoingCount++;
//				}
//			}
//			cout << "Vertex " << i << ": " << outgoingCount << " edges." << endl;
//		}
//	}
//
//};
//
//int main() {
//	int V = 10;
//	Graph g(V);
//
//	g.addEdge(0, 1);
//	g.addEdge(0, 6);
//	g.addEdge(0, 8);
//	g.addEdge(1, 4);
//	g.addEdge(1, 6);
//	g.addEdge(1, 9);
//	g.addEdge(2, 4);
//	g.addEdge(2, 6);
//	g.addEdge(3, 4);
//	g.addEdge(3, 5);
//	g.addEdge(3, 8);
//	g.addEdge(4, 5);
//	g.addEdge(4, 9);
//	g.addEdge(7, 8);
//	g.addEdge(7, 9);
//
//	cout << "Adjacency Matrix:" << endl;
//	g.printMatrix();
//
//	cout << "\nNumber of edges: " << endl;
//	g.countEdgesPerNode();
//
//	system("pause");
//	return 0;
//}
