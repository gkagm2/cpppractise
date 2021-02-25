// Radix sort (�������)
// digit�� ������ �̿��Ͽ� ����
// ���� �������� ������ �� ����.
// ��Ʈ ������ ���� ����
// ��� ��ȯ ����(��Ʈ��ȯ�� �̿��� ����), ���� ��� ����

/*
- �����İ� ������ partion�� ����� �ݺ�(MSB -> LSB)
- Partion�� ������ ��Ʈ(0, 1)
- MSB�� �ִ������� ���� ������������ ���밡��
  - ������ MSB�� ��ȣ�� ��Ÿ��
  - �Ǽ����� ����ü�谡 �ٸ�
  unsigned int������ ���
*/

/*
�ֻ�����Ʈ���� �����ؼ� Bit partition����
Bit Partition���� ���ҵ� ������ ���ؼ� ��� ȣ��
*/

// (Straight Radix Sort, ���� ��� ����)
// ���� ���ں��� �����Ͽ� ����. 
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

	int digit = 1; // �ڸ� ��
	int maxDigitCnt = MAX_CNT;
	while (maxDigitCnt--) {
		int numberPos = 1;

		// �ڸ� �� ��� �� ť�� �ִ´�.
		for (int i = 0; i < vec.size(); ++i) {
			int num = vec[i];
			int restNum;
			// ù��° �ڸ� ������ ��������
			for (int j = 0; j < digit; ++j) {
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

		++digit;
	}

	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << '\n';
	}

	return 0;
}