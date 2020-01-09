#include <iostream>

using namespace std;

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

int main() {
	int list[MAXSIZE] = { 10,8,6,20,4,3,22,1,0,15 };

	for (int i = 0; i < MAXSIZE; ++i) {
		cout << list[i] << " ";
	}

	ShellSort(list, MAXSIZE);

	cout << endl;
	for (int i = 0; i < MAXSIZE; ++i) {
		cout << list[i] << " ";
	}

	return 0;
}