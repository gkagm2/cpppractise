// PROGRAM : Baseball game
// DEV : Sagacity Jang
// DATE : 2019.10.29

/*
�߱����� �����
1 ~ 9 ������ ������ ���� 3���� ���´�. ��, ���ڴ� �ߺ��Ǿ�� �ȵȴ�.
3���� ���ڴ� ***�� ���·� ��µǰ� �� 3���� ���ڸ� ���ߴ� �����̴�.
����ڴ� �� 3���� ���ڸ� ���⶧���� ����ؼ� 3���� ���ڸ� �Է��Ѵ�.
���� ����� �� ���ڰ� 7 3 8 �� ��� ����ڴ� 3���� ���ڸ� ��� �Է��Ѵ�.
�Է� : 1 2 4�� �Է����� ��� 1 2 4�� ������� ������ �ƹ��͵� �����Ƿ� Out�� ����Ѵ�.

�Է� : 7 5 9�� �Է����� ��� 7�� ������� ������ �ְ� ��ġ�� �����Ƿ� strike�̴�.
5, 9�� �����Ƿ� ����� 1strike 0ball�� ����Ѵ�.

�Է� : 7 8 6�� �Է����� ��� 7�� 1strike 8�� ���ڴ� ������ ��ġ�� �ٸ��Ƿ� ball�� �ȴ�.
1strike 1ball�� ����Ѵ�.

�̷��� ����� �ϰ� �Է��� �����鼭 ���������� 3���� ���ڸ� �ڸ����� ��� ��ġ�ϰ� �Է��ϸ� ������ ����ȴ�.
���� �Է¹��� ���� 3���� �Ѱ��� 0�� ���� ��� ������ �����Ѵ�.
*/

#include <iostream>
#include <ctime>
using namespace std;

#define MAX_INPUT_NUMBER 3
#define MAX_HIT_NUMBER 9
int main() {

	srand((unsigned int)time(0)); // Random

	bool bGameStart = true;

	int iBallNums[MAX_INPUT_NUMBER] = {}; // �⺻�� �����Ǵ� ��
	int iInputNums[MAX_INPUT_NUMBER] = {};		// �Է��� ��
	int iBallNumList[MAX_HIT_NUMBER] = {};

	int iStrike = 0;
	int iBall = 0;
	int iTurnCount = 1;

	// Insert number
	for (int i = 0; i < MAX_HIT_NUMBER; ++i) {
		iBallNumList[i] = i + 1;
	}

	// Shuffle
	int idx1, idx2, iTemp;
	for (int i = 0; i < 50; ++i) {
		idx1 =(rand() % MAX_HIT_NUMBER); // 1 ~ 9 index�� ����
		idx2 = (rand() % MAX_HIT_NUMBER);// 1 ~ 9 index�� ����

		iTemp = iBallNumList[idx1];
		iBallNumList[idx1] = iBallNumList[idx2];
		iBallNumList[idx2] = iTemp;
	}

	// Print iBallNumList
	for (int i = 0; i < MAX_HIT_NUMBER; i++)
	{
		cout << iBallNumList[i] << ", ";
	}

	// Ball init
	for (int i = 0; i < MAX_INPUT_NUMBER; ++i) {
		iBallNums[i] = iBallNumList[i];
	}

	cout << endl;

	// Game start
	while (bGameStart) {
	_START:
		iStrike = iBall = 0;

		// Input number
		cout << "1 ~ 9���� ���� 3���� �Է��ϼ��� : ";
		for (int i = 0; i < MAX_INPUT_NUMBER; ++i) {
			cin >> iInputNums[i];
			if (iInputNums[i] == 0) { // 0���� üũ�Ѵ�.
				bGameStart = false;
				break;
			}
			else if (iInputNums[i] < 0 || iInputNums[i] > MAX_HIT_NUMBER) { // ������ �����
				cout << "���� ������ ������ϴ�." << endl;
				goto _START;
			}
		}

		if (!bGameStart) { // Game close
			break;
		}
		
		// ������ üũ�Ѵ�.
		for (int i = 0; i < MAX_INPUT_NUMBER - 1; ++i) {
			for (int j = i + 1; j < MAX_INPUT_NUMBER; ++j) {
				if (iInputNums[i] == iInputNums[j]) {
					cout << "���� ���ڸ� �Է��Ͽ����ϴ�. " << endl;
					goto _START;
				}
			}
		}

		// Check strike or ball
		for (int i = 0; i < MAX_INPUT_NUMBER; ++i) {
			// ���ԵǾ��ִ��� Ȯ���Ѵ�.
			for (int j = 0; j < MAX_INPUT_NUMBER; ++j) {
				if (iBallNums[i] == iInputNums[j]) { // ������ ������
					if (i == j) {
						++iStrike;
					}
					else {
						++iBall;
					}
				}
			}
			// �ڸ��� �´��� Ȯ���Ѵ�.
		}

		system("cls");

		// print
		cout << iStrike << "strike, " << iBall <<"ball" << endl;
		
		if (iStrike == MAX_INPUT_NUMBER) {
			cout << iTurnCount <<"��°�� ������ϴ�." << endl;
			break;
		}

		// Init value
		++iTurnCount;
		
	}
	cout << "Game�� �����մϴ�." << endl;

	return 0;
}