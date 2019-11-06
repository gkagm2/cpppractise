#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

#define MAXSIZE 50

int a[MAXSIZE];

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


void Merge(int low, int mid, int high) {
	int h, i, j, b[50], k;
	h = low;
	i = low;
	j = mid + 1;
	
	while ((h <= mid) && (j <= high)) {
		if (a[h] <= a[j]) {
			b[i] = a[h];
			++h;
		}
		else {
			b[i] = a[j];
			++j;
		}
		++i;
	}
	if (h > mid) {
		for (k = j; j <= high; ++k) {
			b[i] = a[k];
			++i;
		}
	}
	else {
		for (k = h; k <= mid; ++k) {
			b[i] = a[k];
			++i;
		}
	}

	for (k = low; k <= high; ++k) {
		a[k] = b[k];
	}
}

void MergeSort(int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		MergeSort(low, mid);
		MergeSort(mid + 1, high);
		Merge(low, mid, high);
	}
}

int main() {

	int num, i;

	cout << "Please Enter the number of elemetns : ";
	cin >> num;
	cout << endl;
	cout << "Enter the elements : \n";
	for (i = 1; i <= num; ++i) {
		cin >> a[i];
	}

	MergeSort(1, num);

	cout << endl;
	cout << "Sorted list : " << endl;
	cout << endl << endl;
	
	for (i = 1; i <= num; ++i) {
		cout << a[i] << " ";
	}
	cout << endl << endl << endl;


	//srand((unsigned int)time(0));

	//int maxSize = MAXSIZE;

	//// 값 초기화d
	//for (int i = 0; i < MAXSIZE; ++i) {
	//	a[i] = i + 1;
	//}

	//// 값들을 섞는다.
	//Shuffle(a, MAXSIZE);

	//cout << "정렬하기 전 값들" << endl;
	//PrintValue(a, maxSize);

	////MergeSort 정렬
	//MergeSort(1, maxSize);
	//cout << endl << "정렬 한 후의 값들" << endl;
	//PrintValue(a, maxSize);

	return 0;
}