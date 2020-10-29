#include <iostream>
using namespace std;

// 1. ��� ��� ����.
// 2. ��� ��带 �������� �� ����� �ּ� ����� �����Ѵ�.
// 3. �湮���� ���� ��� �߿��� ���� ����� ���� ��带 �����Ѵ�.
// 4. �ش� ��带 ���ļ� Ư���� ���� ���� ��츦 ����Ͽ� �ּ� ����� �����Ѵ�.
// 5. �� �������� 3�� ~ 4���� �ݺ��Ѵ�.
#define NODE_CNT 6
int INF = 1000000000;

// 2���� �迭�� �̿��Ѵ�.
// 2���� �迭�� ���� Cost�̴�.
int map[NODE_CNT][NODE_CNT] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0}
};
bool visited[6]; // �湮�� ���
int dis[6]; // �ִ� �Ÿ�

int GetMinIndex() {
	int min = INF;
	int index = 0;
	// ���� (�̰ɷ��ϸ� O(n^2))
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