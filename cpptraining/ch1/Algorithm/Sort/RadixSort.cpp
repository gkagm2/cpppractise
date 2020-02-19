// Radix sort

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

queue<int> que[10];
vector<int> vec;

#define MAX_CNT 3 // �ִ� �ڸ� ��

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int numCnt;

	cout << "�Է��� ������ ������ �Է��ϼ��� : ";
	cin >> numCnt;

	for (int i = 0; i < numCnt; ++i) {
		int n;
		cin >> n;
		vec.push_back(n);
	}

	int posCnt = 1; // �ڸ� ��
	int maxCnt = MAX_CNT;
	while (maxCnt--) {
		int numberPos = 1;

		// �ڸ� �� ��� �� ť�� �ִ´�.
		for (int i = 0; i < vec.size(); ++i) {
			int num = vec[i];
			int restNum;
			// ù��° �ڸ� �� ��
			for (int j = 0; j < posCnt; ++j) {
				restNum = num % 10;
				num /= 10;
			}

			que[restNum].push(vec[i]); // que���ٰ� �־��ش�.
		}

		vec.clear();

		// ť�� �������� �ٽ� ���Ϳ� �־��ش�.
		int queSize = 10;
		for (int i = 0; i < queSize; ++i) {
			while (!que[i].empty()) {
				vec.push_back(que[i].front());
				que[i].pop();
			}
		}

		++posCnt;
	}

	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << '\n';
	}

	return 0;
}