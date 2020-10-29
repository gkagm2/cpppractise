#include <iostream>
using namespace std;

// 1. 출발 노드 설정.
// 2. 출발 노드를 기준으로 각 노드의 최소 비용을 저장한다.
// 3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드를 선택한다.
// 4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소 비용을 갱신한다.
// 5. 위 과정에서 3번 ~ 4번을 반복한다.
#define NODE_CNT 6
int INF = 1000000000;

// 2차원 배열을 이용한다.
// 2차원 배열의 값은 Cost이다.
int map[NODE_CNT][NODE_CNT] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
};
bool visited[6]; // 방문한 노드
int dis[6]; // 최단 거리

int GetMinIndex() {
	int min = INF;
	int index = 0;
	// 선형 (이걸로하면 O(n^2))
	for (int i = 0; i < NODE_CNT; ++i) {
		if (dis[i] < min && !visited[i]) {
			min = dis[i];
			index = i;
		}
	}
	return index;
}

void Dijkstra(int start) {
	for (int i = 0; i < NODE_CNT; ++i) {
		dis[i] = map[start][i];
	}
	visited [start] = true;

	for (int i = 0; i < NODE_CNT - 2; ++i) {
		int curMinDisIndex = GetMinIndex();
		visited[curMinDisIndex] = true;
		for (int j = 0; j < NODE_CNT; ++j) {
			if (!visited[j]) {
				if (dis[curMinDisIndex] + map[curMinDisIndex][j] < dis[j])
					dis[j] = dis[curMinDisIndex] + map[curMinDisIndex][j];
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Dijkstra(0);
	for (int i = 0; i < NODE_CNT; ++i) {
		cout << dis[i] << " ";
	}

	return 0;
}