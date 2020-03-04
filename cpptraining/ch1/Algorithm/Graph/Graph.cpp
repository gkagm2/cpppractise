#include <iostream>
#include <vector>
using namespace std;

// Without STL

void DirectedGraph() {
	/*int adjacencyMatrix[10][10] = {};
	int vertex, edge;

	cin >> vertex >> edge;

	for (int i = 0; i < edge; ++i) {
		int u, v;
		cin >> u >> v;
		adjacencyMatrix[u][v] = 1;
	}*/

	int edge[10][10];
	int deg[10]; // 각 정점의 outdegree
	int *adj[10];
	int idx[10]; // adj[i]에서 새로운 정점을 추가할 때의 위치

	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; ++i) {
		cin >> edge[i][0] >> edge[i][1];
		deg[edge[i][0]]++;
	}

	for (int i = 1; i <= v; ++i) {
		adj[i] = new int[deg[i] + 1];
	}

	for (int i = 0; i < e; ++i) {
		int u = edge[i][0], v = edge[i][1];
		adj[u][idx[u]] = v;
		++idx[u];
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
	DirectedGraph();
	return 0;
}