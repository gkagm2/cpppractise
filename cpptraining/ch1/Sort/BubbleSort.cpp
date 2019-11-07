#include <iostream>
#include <time.h>

using namespace std;


void Shuffle(int elements[], int maxSize) {
	int aTemp, bTemp, temp;
	for (int i = 0; i < maxSize * 10; ++i) {
		aTemp = rand() % maxSize;
		bTemp = rand() % maxSize;

		temp = elements[aTemp];
		elements[aTemp] = elements[bTemp];
		elements[bTemp] = temp;
	}
}

void BubbleSort(int elements[], int maxSize) {
	int i, j, temp;

	for (i = maxSize - 1; i > 0; --i) {
		for (j = 0; j < i; ++j) {
			if (elements[j] > elements[j + 1]) {
				temp = elements[j];
				elements[j] = elements[j + 1];
				elements[j + 1] = temp;
			}
		}
	}
}

void PrintValue(int elements[], int maxSize) {
	for (int i = 0; i < maxSize; ++i) {
		cout << "(" << elements[i] << ")";
	}
}

int main() {
	srand((unsigned int)time(0));

	int elements[20];

	for (int i = 0; i < 20; ++i) {
		elements[i] = i + 1;
	}

	Shuffle(elements, 20);
	PrintValue(elements, 20);

	cout << endl;
	BubbleSort(elements, 20);
	PrintValue(elements, 20);



	return 0;
}