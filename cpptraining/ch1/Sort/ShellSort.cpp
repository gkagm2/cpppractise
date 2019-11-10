#include <iostream>

using namespace std;

#define MAXSIZE 10

void IncInsertionSort(int list[], int first, int last, int gap) {
	int i, j, key;


	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];

		for (j = i - gap; j >= first && list[j] > key; j = j - gap) {
			list[j + gap] = list[j];
		}
		list[j + gap] = key;
	}
}

void ShellSort(int list[], int n) {
	int i, gap;

	for (gap = n / 2; gap > 0; gap = gap / 2)
	{
		if ((gap % 2) == 0) {
			gap++;
		}

		for (i = 0; i < gap; ++i) {
			IncInsertionSort(list, i, n - 1, gap);
		}
	}
}

int main() {
	int i;
	int n = MAXSIZE;
	int list[MAXSIZE] = { 10,8,6,20,4,3,22,1,0,15 };

	for (i = 0; i < n; ++i) {
		cout << list[i] << " ";
	}

	ShellSort(list, n);

	cout << endl;
	for (i = 0; i < n; ++i) {
		cout << list[i] << " ";
	}

	return 0;
}