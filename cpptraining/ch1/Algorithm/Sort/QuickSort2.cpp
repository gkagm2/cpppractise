#include <iostream>
#include <ctime>
using namespace std;

#define MAXSIZE 500

void Swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void QuickSort(int elements[], int left, int right) {
	int l = left, r = right;
	int pivot = elements[(left + right) / 2];

	while (l < r) {
		while (elements[l] < pivot)
			++l;
		while (elements[r] > pivot)
			--r;

		if (l <= r) {
			if (l < r) {
				Swap(&elements[l], &elements[r]);
			}
			++l;
			--r;
		}
	}
	
	if (left < r)
		QuickSort(elements, left, r);
	if (right > l)
		QuickSort(elements, l, right);
}

void Shuffle(int elements[], int maxSize) {
	for (int i = 0; i < maxSize * 10; ++i) {
		int iTempA = rand() % maxSize;
		int iTempB = rand() % maxSize;

		int iTemp = elements[iTempA];
		elements[iTempA] = elements[iTempB];
		elements[iTempB] = iTemp;
	}
}

void PrintValue(int elements[], int maxSize) {
	for (int i = 0; i < maxSize; ++i) {
		cout << "(" << elements[i] << ")";
	}
}

int main() {
	srand((unsigned int)time(0));
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	
	int elements[MAXSIZE] = {};
	int maxSize;

	cout << "������ ������ ������ �Է� : ";
	cin >> maxSize;

	// ���� ����
	for (int i = 0; i < maxSize; ++i) {
		elements[i] = i + 1;
	}

	// ������ ���´�.
	Shuffle(elements, maxSize);

	cout << "�����ϱ� �� ����" << endl;
	PrintValue(elements, maxSize);

	// QuickSort ����
	QuickSort(elements, 0, maxSize - 1);

	cout << endl << "���� �� ���� ����" << endl;
	PrintValue(elements, maxSize);
}