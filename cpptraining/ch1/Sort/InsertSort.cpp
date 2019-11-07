#include <iostream>
using namespace std;

#define MAXSIZE 5

// 배열 요소값들을 섞어준다.
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


void InsertSort(int elements[], int maxSize) {
	int i, j, key;

	for (i = 1; i < maxSize; ++i) {
		key = elements[i];
		for (j = i - 1; j >= 0 && elements[j] > key; --j) {
			elements[j + 1] = elements[j];
		}
		elements[j + 1] = key;
	}
}

int main() {

	int elements[MAXSIZE];

	for (int i = 0; i < MAXSIZE; ++i) {
		elements[i] = i + 1;
	}

	Shuffle(elements, MAXSIZE);
	PrintValue(elements, MAXSIZE);

	cout << endl;
	InsertSort(elements, MAXSIZE);
	PrintValue(elements, MAXSIZE);

	return 0;
}