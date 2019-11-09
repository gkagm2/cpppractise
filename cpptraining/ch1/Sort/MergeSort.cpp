#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

#define MAXSIZE 50

int sorted[MAXSIZE];

void Shuffle(int elements[], int maxSize) {
	int iTempA, iTempB, iTemp;
	for (int i = 0; i < 10 * maxSize; ++i) {
		iTempA = rand() % maxSize;
		iTempB = rand() % maxSize;
		
		iTemp = elements[iTempA];
		elements[iTempA] = elements[iTempB];
		elements[iTempB] = iTemp;
	}
}

void PrintValue(int elements[], int maxSize) {
	for (int i = 0; i < maxSize; ++i) {
		cout << "(" << elements[i] << ")";
	}
}

void Merge(int elements[], int left, int mid, int right) {
	int l, m, k;
	l = k = left;
	m = mid + 1;

	// 합병
	while (l <= mid && m <= right) {
		if (elements[l] <= elements[m]) {
			sorted[k++] = elements[l++];
		}
		else {
			sorted[k++] = elements[m++];
		}
	}

	// 나머지 처리
	if (l > mid) {
		for (int i = m; i <= right; ++i) {
			sorted[k++] = elements[i];
		}
	}
	else {
		for (int i = l; i <= mid; ++i) {
			sorted[k++] = elements[i];
		}
	}

	// 복사
	for (int i = left; i <= right; ++i) {
		elements[i] = sorted[i];
	}
}

void MergeSort(int elements[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(elements, left, mid);
		MergeSort(elements, mid + 1, right);
		Merge(elements, left, mid, right);
	}
}

int main() {
	srand((unsigned int)time(0));

	int maxSize = MAXSIZE;
	int elements[MAXSIZE];
	// 값 초기화
	for (int i = 0; i < MAXSIZE; ++i) {
		elements[i] = i + 1;
	}

	// 값들을 섞는다.
	Shuffle(elements, MAXSIZE);
	PrintValue(elements, maxSize);

	cout << endl;
	cout << endl;
	//MergeSort 정렬	
	MergeSort(elements, 0, MAXSIZE - 1);
	PrintValue(elements, maxSize);

	return 0;
}