#include <iostream>
using namespace std;

// 삽입정열은 삽입될 자표가 제자리를 찾기 위해 비교와 교환횟수가 너무 많다. 이러한 문제를 개선함.




#define MAXSIZE 10

void IncInsertionSort(int list[], int first, int last, int gap) {
	int i, j, key;

	for (i = first + gap; i <= last; i += gap) {
		key = list[i];
		for (j = i - gap; j >= first && list[j] > key; j -= gap) {
			list[j + gap] = list[j];
		}
		list[j + gap] = key;
	}
}

void ShellSort(int list[], int maxSize) {
	int i, gap;

	for (gap = maxSize / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) {
			++gap;
		}

		for (i = 0; i < gap; ++i) {
			IncInsertionSort(list, i, maxSize - 1, gap);
		}
	}
}

// 수열이 3h(n-1) + 1로 해야 빠르다고 함. 
void ShellSort3h(int list[], int maxSize) {
	int i, gap;

	for (gap = 1; gap < maxSize; gap = 3 * gap + 1); // maxSize보다 작은 최대의 gap을 찾는다.
	for (gap = maxSize / 3; gap > 0; gap = gap / 3) {
		for (i = 0; i < gap; ++i) { // 변이
			IncInsertionSort(list, i, maxSize - 1, gap);
		}
	}
}

int main() {
	int list[MAXSIZE] = { 10,8,6,20,4,3,22,1,0,15 };

	for (int i = 0; i < MAXSIZE; ++i) {
		cout << list[i] << " ";
	}

	 ShellSort(list, MAXSIZE);
	//ShellSort3h(list, MAXSIZE);
	cout << endl;
	for (int i = 0; i < MAXSIZE; ++i) {
		cout << list[i] << " ";
	}

	return 0;
}