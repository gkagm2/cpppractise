// Radix sort

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

queue<int> que[10];
vector<int> vec;

#define MAX_CNT 3 // 최대 자리 수

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int numCnt;

	cout << "입력하 숫자의 개수를 입력하세요 : ";
	cin >> numCnt;

	for (int i = 0; i < numCnt; ++i) {
		int n;
		cin >> n;
		vec.push_back(n);
	}

	int posCnt = 1; // 자리 수
	int maxCnt = MAX_CNT;
	while (maxCnt--) {
		int numberPos = 1;

		// 자리 수 계산 후 큐에 넣는다.
		for (int i = 0; i < vec.size(); ++i) {
			int num = vec[i];
			int restNum;
			// 첫번째 자리 수 비교
			for (int j = 0; j < posCnt; ++j) {
				restNum = num % 10;
				num /= 10;
			}

			que[restNum].push(vec[i]); // que에다가 넣어준다.
		}

		vec.clear();

		// 큐에 넣은것을 다시 벡터에 넣어준다.
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