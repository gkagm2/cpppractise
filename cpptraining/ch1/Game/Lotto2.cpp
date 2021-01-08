// Date :2021.01.08
// DEV  : Sagacity Jang
#include <iostream>
#include <time.h>
using namespace std;
#define MAX_ARR_SIZE 45
#define MAX_SELECT_SIZE 6

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

void Sort(int arr[], int left, int right) {
	int l = left, r = right;
	int pivot = arr[(left + right) / 2];

	while (l < r) {
		while (arr[l] < pivot)
			++l;
		while (arr[r] > pivot)
			--r;
		if (l <= r) {
			if (l < r)
				Swap(&arr[l], &arr[r]);
			++l;
			--r;
		}
	}
	if (left < r)
		Sort(arr, left, r);
	if (right > l)
		Sort(arr, l, right);
}

void InitArr(int arr[]) {
	for (int i = 0; i < MAX_ARR_SIZE; ++i) {
		arr[i] = i + 1;
	}
}

void Lotto() {
	int arr[MAX_ARR_SIZE];
	int selectArr[MAX_SELECT_SIZE];
	InitArr(arr);

	int cnt = 1;
	for (int cnt = 1; cnt <= MAX_SELECT_SIZE; ++cnt) {
		Shuffle(arr, MAX_ARR_SIZE);
		Sort(arr, 0, MAX_SELECT_SIZE - 1);
		cout << "============================================================\n";
		cout << cnt << " È¸Â÷ : ";
		for (int i = 0; i < MAX_SELECT_SIZE; ++i) {
			cout << arr[i] << "\t";
		}
		cout << "\n";
	}
	cout << "============================================================\n";
}

int main() {
	srand((unsigned)time(nullptr));
	Lotto();
	system("pause");
	return 0;
}