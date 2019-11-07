#include <iostream>
#include <time.h>
using namespace std;

#define MAXSIZE 20

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

void SelectSort(int elements[], int maxSize) {
	int i, j, least, temp;

	for (i = 0; i < maxSize - 1; ++i) {
		least = i;
		for (j = i + 1; j < maxSize; ++j) {
			if (elements[least] > elements[j]) {
				least = j;
			}
		}
		
		if (i != least) {
			temp = elements[least];
			elements[least] = elements[i];
			elements[i] = temp;
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

	int elements[MAXSIZE];

	for (int i = 0; i < MAXSIZE; ++i) {
		elements[i] = i + 1;
	}
	Shuffle(elements, MAXSIZE);
	PrintValue(elements, MAXSIZE);
	
	cout << endl;
	SelectSort(elements, MAXSIZE);
	PrintValue(elements, MAXSIZE);

	return 0;
}