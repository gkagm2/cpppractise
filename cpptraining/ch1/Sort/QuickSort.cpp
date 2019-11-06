#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

#define MAXSIZE 500

void QuickSort(int elements[], int left, int right) {
	int pivot = elements[left];
	int l = left;
	int r = right;

	while (left < right) {
		while (elements[right] >= pivot && left < right) {
			--right;
		}
		if (left != right) {
			elements[left] = elements[right];
			++left;
		}

		while (elements[left] <= pivot && left < right) {
			++left;
		}
		if (left != right) {
			elements[right] = elements[left];
			--right;
		}
	}
	
	elements[left] = pivot;
	pivot = left; // 피봇값 설정.
	left = l;
	right = r;

	if (left < pivot) {
		QuickSort(elements, left, pivot - 1);
	}
	if( right > pivot){
		QuickSort(elements, pivot + 1, right);
	}

}

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

int main() {
	srand((unsigned int)time(0));
	int elements[MAXSIZE] = {};

	int maxSize;

	cout << "정렬할 값들의 개수를 입력 : ";
	cin >> maxSize;

	// 값을 설정
	for (int i = 0; i < maxSize; ++i) {
		elements[i] = i + 1;
	}

	// 값들을 섞는다.
	Shuffle(elements, maxSize);

	cout << "정렬하기 전 값들" << endl;
	PrintValue(elements, maxSize);

	// QuickSort 정렬
	QuickSort(elements, 0, maxSize - 1); 

	cout << endl << "정렬 한 후의 값들" << endl;
	PrintValue(elements, maxSize);

	return 0;
}