#include <iostream>
#include <vector>
using namespace std;

// 배열 사용

void DirectedGraph() {
	int adjacencyMatrix[10][10] = {};
	int vertex, edge;

	cin >> vertex >> edge;

	for (int i = 0; i < edge; ++i) {
		int u, v;
		cin >> u >> v;
		adjacencyMatrix[u][v] = 1;
	}
}

void UnDirectedGraph() {
	int adjacencyMatrix[10][10] = {};
	int vertex, edge;

	cin >> vertex >> edge;

	for (int i = 0; i < edge; ++i) {
		int u, v;
		cin >> u >> v;
		adjacencyMatrix[u][v] = 1;
		adjacencyMatrix[v][u] = 1;
	}
}

// STL 사용

void DirectedGraphSTL() {
	vector<int> adjacency[10];
	int vertex, edge;

	cin >> vertex >> edge;

	for (int i = 0; i < edge; ++i) {
		int u, v;
		cin >> u >> v;
		adjacency[u].push_back(v);
	}
}

void UnDirectedGraphSTL() {
	vector<int> adjacency[10];
	int vertex, edge;

	cin >> vertex >> edge;

	for (int i = 0; i < edge; ++i) {
		int u, v;
		cin >> u >> v;
		adjacency[u].push_back(v);
		adjacency[v].push_back(u);
	}
}

int main() {

	return 0;
}