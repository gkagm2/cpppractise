// 2021.01.08 Made by Sagacity Jang
#include <iostream>
#include <time.h>
using namespace std;

void Swap(int *a, int *b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void Shuffle(int arr[], const int &size) {
	int t1, t2;
	for (int i = 0; i < 100 * size; ++i) {
		t1 = rand() % size;
		t2 = rand() % size;
		Swap(&arr[t1], &arr[t2]);
	}
}

int main() {
	srand((unsigned)time(nullptr));
	int cnt = 1;
	int ballNums[9];
	int inpNums[3];
	bool isSuccess = false;

	// init ball arr
	for (int i = 0; i < 9; ++i)
		ballNums[i] = i + 1;

	Shuffle(ballNums, 9);

	for (; cnt < 10; ++cnt) {

		int strikeCnt = 0;
		int ballCnt = 0;

		cout << cnt << " 회차 입력: ";
		cin >> inpNums[0] >> inpNums[1] >> inpNums[2];

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (ballNums[i] == inpNums[j]) {
					if (i == j)
						++strikeCnt;
					else
						++ballCnt;
				}
			}
		}

		cout << strikeCnt << " Strike! " << ballCnt << " Ball!\n";
		if (strikeCnt >= 3) {
			isSuccess = true;
			break;
		}
		cout << "\n";

	}

	if (isSuccess)
		cout << "\n" << cnt << " 회차 승리 !!!\n";
	else
		cout << "\n패배!!!\n";

	system("pause");
	return 0;
}