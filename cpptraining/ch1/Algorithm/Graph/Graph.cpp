#include <iostream>
using namespace std;

int adjacencyMatrix[10][10] = {};
int vertex, edge;

void DirectedGraph() {
	cin >> vertex >> edge;

	for (int i = 0; i < edge; ++i) {
		int u, v;
		cin >> u >> v;
		adjacencyMatrix[u][v] = 1;
	}
}

void UnDirectedGraph() {
	cin >> vertex >> edge;

	for (int i = 0; i < edge; ++i) {
		int u, v;
		cin >> u >> v;
		adjacencyMatrix[u][v] = 1;
		adjacencyMatrix[v][u] = 1;
	}
}

int main() {

	return 0;
}