#include <iostream>
#include <string>
using namespace std;

// 항상 빠르지는 않지만 일반적인 경우 빠르게 작동하는 간단한 구조의 문자열 매칭 알고리즘이다.
// 해시를 이용함.
// 상징하는 데이터를 바꾸어 처리함. 따라서 연산 속도 O(1)

// 해시값을 만들 때 오버플로수가 발생해도 일반적인 CPU의 경우 동일한 간격으로 음의 부호화 양의 부호를 왔다갔다 하므로 해시 값이 일치하는 것. 더 안정적인 프로그램을 작성하고자 하면 나머지 연산을 이용(MOD)하자.


// parent : 특정한 긴 글, pattern : 어떠한 작은 문자열의 패텬
// 을 찾는다.
void FindString(string parent, string pattern) {
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int parentHash = 0, patternHash = 0, power = 1;

	// 전체 위치에서 다 하나씩 검사하기
	for (int i = 0; i <= parentSize - patternSize; ++i) {
		if (i == 0) { // i가 0일경우 해쉬값을 구할 수 있도록 만들자 (초기화 시)
			for (int j = 0; j < patternSize; ++j) { 
				parentHash += parent[patternSize - 1 - j] * power; // (긴 글) 패턴 사이즈 위치(오른쪽)에서  왼쪽으로 값을 구해줌.
				patternHash += pattern[patternSize - 1 - j] * power; // (패턴) 패턴 해쉬도 위의 방법대로 구해줌.
				if (j < patternSize - 1) // power에 2를 계속해서 곱한다.
					power <<= 1;
			}
		}
		else {
			//앞에서부터 뒤로 쭉 읽으면서 값을 구하기 위해 
			// 긴 글 해시 값 = 2 * (긴 글 해시 값 - 가장 앞에 있는 문자의 수치) + 새롭게 들어온 문자의 수치
			parentHash = 2 * (parentHash - parent[i - 1] * power) + parent[patternSize - 1 + i];
		}

		// 긴 문장에서의 해시값과 찾을 패턴의 해시값이 일치하면
		if (parentHash == patternHash) {
			bool finded = true;
			for (int j = 0; j < patternSize; ++j) { // 정확히 일치하는지 확인
				// 모든 문자열을 검색함.
				if (parent[i + j] != pattern[j]) {
					finded = false; // 동일하지 않으면
					break;
				}
			}

			// 문자열을 찾았으면
			if (finded) {
				cout << i + 1 << "번째에서 발견함.\n";
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";
	FindString(parent, pattern);

	return 0;
}