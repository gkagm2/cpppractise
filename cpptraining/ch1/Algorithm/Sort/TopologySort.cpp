/*
*��������*

���� ������ ����Ŭ�� ���� ���⼺ �׷������� ������ �� �ִ�.
queue�� stack�� �̿��� �� �ִ�. (queue ��ȣ)

1. ���������� 0�� ������ ť�� �����Ѵ�. (���������� ���� ���� �����ϱ� ���� ���� ����� ���� ������ �ǹ��Ѵ�.)
2. ť���� ���Ҹ� ����	����� ��� ������ �����Ѵ�.
3. ���� ���� ���Ŀ� ���������� 0�� �� ������ ť�� �����Ѵ�.
4. ť�� �� ������ 2~3�� ������ �ݺ��Ѵ�. ��� ���Ҹ� �湮�ϱ� ���� ť�� ��ٸ� ����Ŭ�� �����Ѵٴ� ���̰�, ��� ���Ҹ� �湮�ߴٸ� ť���� ���� ������ ���� ������ ����̴�.

����� ������ ���� �� �� �ִ�.

���� ������ �ð� ���⵵ : O(V+E)  (������ ���� + ������ ����)
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 10;

int n, inDegree[MAX]; // inDegree : ���� ���� (�� ������ ���� ������ ������ ����ִ�.),  n : ����� ����
vector<int> node[MAX]; // �� ������ ����Ǿ��ִ� ������ ������ ����ִ�.

void TopologySort() {
	int result[MAX];
	queue<int> q;

	// ���������� 0�� ��带 ť�� �����մϴ�.
	for (int i = 1; i <= n; ++i) {
		if (inDegree[i] == 0)
			q.push(i);
	}
	// ���� ������ ����Ƿ��� ��Ȯ�� n���� ��忡 �湮�ؾ� �Ѵ�.
	for (int i = 1; i <= n; ++i) {
		// n���� �湮�ϱ� ���� ť�� ��� ����Ŭ�� �߻��� ����.
		if (q.empty()) {
			cout << "����Ŭ �߻�\n";
			return;
		}
		int x = q.front();
		q.pop();

		result[i] = x; // ť���� ���� ������ ���������� ����̹Ƿ� result �迭�� �־���.

		// ���� ��忡 ����Ǿ��ִ� ��� �������� Ȯ���ؼ� ����Ǿ��ִ� ��� �������� �����.
		for (int j = 0; j < node[x].size(); ++j) {
			int y = node[x][j];
			// ���Ӱ� ���������� 0�� �� ������ ť�� �����Ѵ�.
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
	���� �׷��� ���
	[1] -> [2] -> [3] -> [4]
	 ��
	[5] -  -  -  -  - -> [6] -> [7]
	*/

	n = 7; // ��ü ��� ����
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
