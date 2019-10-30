// PROGRAM : Lotto program
// DEV : Sagacity Jang
// DATE : 2019.10.29

#include <iostream>
#include <time.h>

using namespace std;

#define MAX_NUMBER 45

int main() {
	system("cls");

	int iLotto[MAX_NUMBER] = {};

	srand((unsigned int)time(0));


	// Lotto program Init
	for (int i = 0; i < MAX_NUMBER; ++i) {
		iLotto[i] = i + 1;
	}

	// Shuffle
	int iTemp, idx1, idx2;
	
	for (int i = 0; i < 100; ++i) { // 100¹ø Á¤µµ °ñ°í·ç ¼¯¾îÁØ´Ù.
		idx1 = rand() % 45;
		idx2 = rand() % 45;

		iTemp = iLotto[idx1];
		iLotto[idx1] = iLotto[idx2];
		iLotto[idx2] = iTemp;
	}

	// Show number
	for (int i = 0; i < 6; ++i) {
		cout << iLotto[i] << " ";
	}
	cout << "bonus number : " << iLotto[6] << endl;

	return 0;
}

