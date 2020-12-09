/*
*위상정렬*

위상 정렬은 사이클이 없는 방향성 그래프에서 적용할 수 있다.
queue와 stack을 이용할 수 있다. (queue 선호)

1. 진입차수가 0인 정점을 큐에 삽입한다. (진입차수란 현재 노드로 진입하기 위한 이전 노드의 간선 개수를 의미한다.)
2. 큐에서 원소를 꺼내	연결된 모든 간선을 제거한다.
3. 간선 제거 이후에 진입차수가 0이 된 정점을 큐에 삽입한다.
4. 큐가 빌 때까지 2~3번 과정을 반복한다. 모든 원소를 방문하기 전에 큐가 빈다면 사이클이 존재한다는 것이고, 모든 원소를 방문했다면 큐에서 꺼낸 순서가 위상 정렬의 결과이다.

결과가 여러개 존재 할 수 있다.

위상 정렬의 시간 복잡도 : O(V+E)  (정점의 개수 + 간선의 개수)
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 10;

int n, inDegree[MAX]; // inDegree : 진입 차수 (각 정점이 진입 차수의 정보를 담고있다.),  n : 노드의 개수
vector<int> node[MAX]; // 각 정점에 연결되어있는 노드들의 정보를 담고있다.

void TopologySort() {
	int result[MAX];
	queue<int> q;

	// 진입차수가 0인 노드를 큐에 삽입합니다.
	for (int i = 1; i <= n; ++i) {
		if (inDegree[i] == 0)
			q.push(i);
	}
	// 위상 정렬이 수행되려면 정확히 n개의 노드에 방문해야 한다.
	for (int i = 1; i <= n; ++i) {
		// n개를 방문하기 전에 큐가 비면 사이클이 발생한 것임.
		if (q.empty()) {
			cout << "사이클 발생\n";
			return;
		}
		int x = q.front();
		q.pop();

		result[i] = x; // 큐에서 꺼낸 순서가 위상정렬의 결과이므로 result 배열에 넣어줌.

		// 꺼낸 노드에 연결되어있는 모든 정점들을 확인해서 연결되어있는 모든 간선들을 지운다.
		for (int j = 0; j < node[x].size(); ++j) {
			int y = node[x][j];
			// 새롭게 진입차수가 0이 된 정점을 큐에 삽입한다.
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << result[i] << " ";
	}
}



int main() {
	/*
	예제 그래프 모양
	[1] -> [2] -> [3] -> [4]
	 ↓
	[5] -  -  -  -  - -> [6] -> [7]
	*/

	n = 7; // 전체 노드 개수
	node[1].push_back(2);
	++inDegree[2];
	node[1].push_back(5);
	++inDegree[5];
	node[2].push_back(3);
	++inDegree[3];
	node[3].push_back(4);
	++inDegree[4];
	node[4].push_back(6);
	++inDegree[6];
	node[5].push_back(6);
	++inDegree[6];
	node[6].push_back(7);
	++inDegree[7];

	TopologySort();

	// result value : 1, 2, 5, 3, 4, 6, 7
	return 0;
}

