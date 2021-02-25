// Radix sort (기수정렬)
// digit의 단위를 이용하여 정렬
// 양의 정수만을 정렬할 수 있음.
// 비트 조작을 통해 정렬
// 기수 교환 정렬(비트교환을 이용한 정렬), 직접 기수 정렬

/*
- 퀵정렬과 유사한 partion의 재귀적 반복(MSB -> LSB)
- Partion의 기준은 비트(0, 1)
- MSB가 최대지분을 갖는 양의정수에만 적용가능
  - 음수는 MSB가 부호를 나타냄
  - 실수형은 숫자체계가 다름
  unsigned int에서만 사용
*/

/*
최상위비트부터 시작해섯 Bit partition실행
Bit Partition으로 분할된 영역에 대해서 재귀 호출
*/

// (Straight Radix Sort, 직접 기수 정렬)
// 작은 숫자부터 정렬하여 넣음. 
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

	int digit = 1; // 자리 수
	int maxDigitCnt = MAX_CNT;
	while (maxDigitCnt--) {
		int numberPos = 1;

		// 자리 수 계산 후 큐에 넣는다.
		for (int i = 0; i < vec.size(); ++i) {
			int num = vec[i];
			int restNum;
			// 첫번째 자리 수부터 가져오기
			for (int j = 0; j < digit; ++j) {
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

		++digit;
	}

	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << '\n';
	}

	return 0;
}