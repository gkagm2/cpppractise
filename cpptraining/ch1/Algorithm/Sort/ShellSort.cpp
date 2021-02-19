#include <iostream>
using namespace std;

// ���������� ���Ե� ��ǥ�� ���ڸ��� ã�� ���� �񱳿� ��ȯȽ���� �ʹ� ����. �̷��� ������ ������.




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

// ������ 3h(n-1) + 1�� �ؾ� �����ٰ� ��. 
void ShellSort3h(int list[], int maxSize) {
	int i, gap;

	for (gap = 1; gap < maxSize; gap = 3 * gap + 1); // maxSize���� ���� �ִ��� gap�� ã�´�.
	for (gap = maxSize / 3; gap > 0; gap = gap / 3) {
		for (i = 0; i < gap; ++i) { // ����
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