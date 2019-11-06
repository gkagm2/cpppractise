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
	pivot = left; // �Ǻ��� ����.
	left = l;
	right = r;

	if (left < pivot) {
		QuickSort(elements, left, pivot - 1);
	}
	if( right > pivot){
		QuickSort(elements, pivot + 1, right);
	}

}

// �迭 ��Ұ����� �����ش�.
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

	return 0;
}