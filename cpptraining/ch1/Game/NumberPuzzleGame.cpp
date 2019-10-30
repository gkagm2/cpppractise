// PROGRAM : ���� ���� ����
// DEV : Sagacity Jang
// DATE : 2019.10.30

#include <iostream>
#include <time.h>

// console input output �������. �ܼ�â���� ����� �ϴ� ��ɵ��� �������ִ� ��������̴�.
#include <conio.h>

using namespace std;

int main() {
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	for (int i = 0; i < 24; ++i) {
		iNumber[i] = i + 1;
	}

	// ���� ������ ĭ�� �������� ����д�. ������ �ǹ��ϴ� ������ Ư���� ���� ����� �� INT_MAX ���� ����� ���̴�.
	iNumber[24] = INT_MAX; // singed int �� ���� ū ����

	// ���� �ִ� ��ġ�� ������ ����
	int iStarIndex = 24;

	// ������ ������ �����ϰ� 1 ~ 24 ������ ���ڸ�  �����ش�. �� �ε��� 0 ~ 23�� �ε��� ������ �����ش�.
	int iTemp, idx1, idx2;

	// Shuffle
	for (int i = 0; i < 100; ++i) {
		idx1 = rand() % 24;
		idx2 = rand() % 24;
		
		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	bool bGame = true;

	while (bGame) {
		cout << endl;
		// Show
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {

				// Print numbers
				if (iNumber[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				}
				else {
					cout << iNumber[i * 5 + j] << "\t"; // �ٹ�ȣ * ���ΰ��� + ĭ��ȣ (1���� �迭�� 2���� ��������)
				}
			}
			cout << endl;
		}
		cout << endl;

		cout << "w : ��, s : �Ʒ�, a : ����, d : ������, q : ����";

		// _getch() �Լ��� ���� 1���� �Է¹޴� �Լ�. Enter�� ġ�� �ʴ��� ������ ���� ���ڸ� ��ȯ�ϰ� ����.
		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q') {
			break;
		}

		switch (cInput) {
		case 'q':
		case'Q':
			bGame = false;
			break;

		case 'w':
		case 'W':;
			if (iStarIndex >= 5) { // �� ������ �ƴϸ�
				iNumber[iStarIndex] = iNumber[iStarIndex - 5]; // ���� �ִ� ��ġ�� �ٷ� ���� �ִ� ���� �־��ش�.
				iNumber[iStarIndex - 5] = INT_MAX; //��ü�Ѵ�.
				iStarIndex -= 5; // ���� ��ĭ ���� �ö����Ƿ� ���� �ε����� �־��ش�.
			}
			break;

		case 's':
		case 'S':
			if (iStarIndex < 20) {
				iNumber[iStarIndex] = iNumber[iStarIndex + 5];
				iNumber[iStarIndex + 5] = INT_MAX;
				iStarIndex += 5;
			}
			break;

		case 'a':
		case 'A':
			if (iStarIndex % 5 != 0) {
				iNumber[iStarIndex] = iNumber[iStarIndex - 1];
				iNumber[iStarIndex - 1] = INT_MAX;
				iStarIndex -= 1;
			}
			break;

		case 'd':
		case 'D':
			if (iStarIndex % 5 != 4) {
				iNumber[iStarIndex] = iNumber[iStarIndex + 1];
				iNumber[iStarIndex + 1] = INT_MAX;
				iStarIndex += 1;
			}

			break;
		}

		bool bWin = true;

		// ������ ���߾����� üũ.
		for (int i = 0; i < 24; ++i) {
			if (iNumber[i] != i + 1) {
				bWin = false;
				cout << " bWin : false : " << iNumber[i] << ", " << i << endl;
				break;
			}
		}

		if (bWin) {
			cout << "���ڸ� ��� ������ϴ�." << endl;
			break;
		}

		if (!bGame) { // ���� ����
			break;
		}
		//system("cls");
	}
	cout << "������ �����մϴ�." << endl;


	return 0;
}