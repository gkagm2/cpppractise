// PROGRAM : ���� �������
// DEV : Sagacity Jang
// DATE : 2019.10.30

#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

// ���� ������� �����
// 1 ~ 25 ������ ���ڰ� �ְ� �� ���ڸ� ���� ��� 5 X 5�� ����Ѵ�.
// �÷��̾�� ���ڸ� �Է¹޴´�. 1 ~ 25 ������ ���ڸ� �Է¹޾ƾ� �Ѵ�.
// 0�� �Է��ϸ� ������ �����Ѵ�.

// ���ڸ� �Է¹޾����� ���� ����� �Է¹��� ���ڸ� ã�Ƽ� *�� ������ش�.
// ���ڸ� *�� ���� �Ŀ� ���� �� ���� üũ�Ѵ�. 5 X 5 �̱� ������ ���� 5�� ���� 5�� �밢�� 2���� ���� �� �ִ�.
// �������� �� �������� üũ�ؼ� ȭ�鿡 �����ش�.
// 5�� �̻��� ��� ������ �����Ѵ�.

enum AI_MODE {
	AM_EASY = 1,
	AM_HARD
};

enum TURN {
	T_PLAYER,
	T_AI
};

enum LINE_NUMBER {
	LN_H1, // ���� ����
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5, 
	LN_V1, // ���� ����
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT, // ���� �� -> ������ �Ʒ� �밢�� ����
	LN_RT  // ������ �� -> ���� �Ʒ� �밢�� ����
};

bool g_bGame = true;

void InitPuzzle(int iNumber[25]);
void Shuffle(int  iNumber[25]);
void ShowPuzzle(int iNumber[25]);
void CheckLine(int iNumber[25], int &iBingoCount);
void PrintBingoCount(const char *name, int iBingoCount);
void InputNumberChangeToStar(int iNumber[25], int size, int iInputNumber);
int main() {

	int iNumber[25] = {};
	int iAINumber[25] = {};

	InitPuzzle(iNumber);	// Player
	InitPuzzle(iAINumber);	// Ai
	Shuffle(iNumber);		// Player
	Shuffle(iAINumber);		// Ai

	int iAIMode;

	// Choice AI mode
	while (true) {
		// AI ���̵��� �����Ѵ�.
		cout << "==�������==" << endl << "AI ��带 �����ϼ���." << endl << "1. easy" << endl << "2. hard" << endl;
		cin >> iAIMode;

		if (iAIMode == AM_EASY || iAIMode == AM_HARD) {
			system("cls");

			break;
		}
		else {
			system("cls");
			cout << "�߸� �Է��Ͽ����ϴ�." << endl << endl;
		}
	}
	
	bool bDuplication = true; // �ߺ��˻�

	int iNoneSelect[25] = {}; // ���þȵ� ��� �迭�� ������ش�.
	int iNoneSelectCount = 0; // ���þȵ� ���� ����.

	int turn = 0;
	int iBingoCount = 0, iAIBingoCount = 0;
	

	// Game start
	while (g_bGame) {

		cout << endl;
#pragma region Player Print
		cout << "--------------Player------------" << endl;
		ShowPuzzle(iNumber);
		PrintBingoCount("Player", iBingoCount);
#pragma endregion
		cout << endl;
#pragma region AI Print
		cout << "---------------AI---------------" << endl;
		cout << "AI Mode : ";
		switch (iAIMode) {
		case AM_EASY:
			cout << "EASY" << endl;
			break;
		case AM_HARD:
			cout << "HARD" << endl;
			break;
		}

		ShowPuzzle(iAINumber);
		PrintBingoCount("AI", iAIBingoCount);
#pragma endregion
		cout << endl;

		if (!g_bGame) { // ���� ����
			break;
		}


		if (turn == T_PLAYER && bDuplication == false) {
			turn = T_AI;
		}
		else if (turn == T_AI && bDuplication == false) {
			turn = T_PLAYER;
		}
		
		int iInput;

		switch (turn) {
		case T_PLAYER:
			// Player�� �����Ѵ�.
			cout << "'0'�Է� �� ����.  ���ڸ� �Է��ϼ��� : ";
			cin >> iInput;

			// Check number
			if (iInput == 0) { // ���� ����
				g_bGame = false;
				continue;
			}
			else if (iInput < 0 || iInput > 25) { // ���� �ʰ�
				system("cls");
				cout << "���� ������ ������ϴ�." << endl;
				continue;
			}

			bDuplication = true;
			for (int i = 0; i < 25; ++i) { // �� ���鼭 
				if (iInput == iNumber[i]) { // �Է��� ���� �迭 �ȿ� ������
					bDuplication = false; // �ߺ� ����
					break;
				}
			}

			if (bDuplication) { // �ߺ��� ���̸�
				system("cls");
				cout << " �ߺ��� �� �Դϴ�." << endl;
				continue;
			}
			break;

		case T_AI:
			// AI�� �����Ѵ�.
			switch (iAIMode) {
			case AM_EASY:
				// AI Easy ���� ���� AI�� ���ڸ���� *�� �ٲ��� ���� ���� ����� ���� �� ����� �ϳ��� �����ϰ� �ȴ�.(�����ϰ�)

				iNoneSelectCount = 0; // ���þȵ� ���� ������ ����� ���鶧 ī���� ���ش�.
				// ���þȵ� ���� ����� ����� �ش�.
				for (int i = 0; i < 25; ++i) {
					if (iAINumber[i] != INT_MAX) { // ���� ���ڰ� *�� �ƴ� ���
						iNoneSelect[iNoneSelectCount] = iAINumber[i];
						++iNoneSelectCount;
					}
				}
				// ������ �ȵ� ������ ������ �ϳ��� ���ڸ� ������ ����	 �ε������������� �����ش�.
				iInput = iNoneSelect[rand() % iNoneSelectCount];
				break;
			case AM_HARD:
				// �ϵ���� ���� ������ ������ �ϼ� ���ɼ��� ���� ���� ���� ã�Ƽ� �� �ٿ� �ִ� ������ �ϳ��� *�� ������ش�.
				int iLine = 0;
				int iStarCount = 0;
				int iSaveCount = 0;

				// ���� ���� �� ���� *�� ���� ������ ã�Ƴ���.
				for (int i = 0; i < 5; ++i) {
					iStarCount = 0;
					for (int j = 0; j < 5; ++j) {
						if (iAINumber[i * 5 + j] == INT_MAX) {
							++iStarCount;
						}
					}
					// ���� 5�� �̸��̿��� ���� ���� �ƴϰ� ������ ���帹�� ������ ������ Ŀ�� ���� ���� ���� �����̹Ƿ�
					// ������ ��ü���ְ� ����� �� ���� ��ü�Ѵ�.
					if (iStarCount < 5 && iSaveCount < iStarCount) {
						// ���� ������ ���� ���� ���� ������ üũ�ϴ� ���̴�. ���ζ����� 0 ~ 4 �� �ǹ̸� �ο��ߴ�.
						iLine = i;
						iSaveCount = iStarCount;
					}
				}

				// ����� ���ΰ� ���� ���ε��� ���Ͽ� ���� ���� ���� ������ ���Ѵ�.
				for (int i = 0; i < 5; ++i) {
					iStarCount = 0;
					for (int j = 0; j < 5; ++j) {
						if (iAINumber[j * 5 + i] == INT_MAX) {
							++iStarCount;
						}
					}

					if (iStarCount < 5 && iSaveCount < iStarCount) {
						iLine = 5 + i;
						iSaveCount = iStarCount;
					}
				}

				// ����� ���ΰ� ���� ��� -> ������ �ϴ� ������ ���Ͽ� ���� ���� ���� ������ ���Ѵ�.
				iStarCount = 0;
				for (int i = 0; i < 5; ++i) {
					
					if (iAINumber[i * 6] == INT_MAX) {
						++iStarCount;
					}
				}

				if (iStarCount < 5 && iSaveCount <iStarCount ) {
					iLine = LN_LT;
					iSaveCount = iStarCount;
				}

				// ����� ���ΰ� ������ ��� -> ���� �ϴ� ������ ���Ͽ� ���� ���� ���� ������ ���Ѵ�.
				iStarCount = 0;
				for (int i = 0; i < 5; ++i) {
					if (iAINumber[i * 4] == INT_MAX) {
						++iStarCount;
					}
				}
				if (iStarCount < 5 && iSaveCount < iStarCount) {
					iLine = LN_RT;
					iSaveCount = iStarCount;
				}

				// ��� ������ ���������� iLine�� ���� ���� �� ��ȣ�� �����.

				// �� �ٿ� �ִ� *�� �ƴ� ������ �ϳ��� �����ϰ� �ȴ�.
				// �������� ��� iLine 0 ~ 4 ������ ��
				if (iLine <= LN_H5) { 
					for (int i = 0; i < 5; ++i) {
						if (iAINumber[iLine * 5 + i] != INT_MAX) { // ���� �ٿ��� *�� �ƴ� ���ڸ� ã�´�.
							iInput = iAINumber[iLine * 5 + i];
							break;
						}
					}
				}
				// �������� ��� iLine 5 ~ 9 ������ ��
				else if (iLine <= LN_V5) {
					for (int i = 0; i < 5; ++i) {
						if (iAINumber[i * 5 + (iLine - 5)] != INT_MAX) {
							iInput = iAINumber[i * 5 + (iLine - 5)];
							break;
						}
					}
				}
				// ���� ��� -> ������ �ϴ� 
				else if (iLine == LN_LT) {
					for (int i = 0; i < 5; ++i) {
						if (iAINumber[i * 6] != INT_MAX) {
							iInput = iAINumber[i * 6];
							break;
						}
					}
				}
				// ������ ��� -> ���� �ϴ�
				else if (iLine == LN_RT) {
					for (int i = 0; i < 5; ++i) {
						if (iAINumber[i * 4] != INT_MAX) {
							iInput = iAINumber[i * 4];
							break;
						}
					}
				}
				break;
			}
			break;
		}

		InputNumberChangeToStar(iNumber, 25, iInput); // Input number change *(Player)
		InputNumberChangeToStar(iAINumber, 25, iInput); // Input number change *(AI)

		iBingoCount = 0, iAIBingoCount = 0;
		CheckLine(iNumber, iBingoCount);
		CheckLine(iAINumber, iAIBingoCount);

		system("cls");
	}
	cout << "���� ����" << endl;

	return 0;
}

void InputNumberChangeToStar(int iNumber[25], int iSize, int iInputNumber) {
	// Input number change *(Player)
	for (int i = 0; i < iSize; ++i) {
		if (iNumber[i] == iInputNumber) { // change INT_MAX
			iNumber[i] = INT_MAX;
			break;
		}
	}
}

void PrintBingoCount(const char *name, int iBingoCount) {
	cout << name <<"��(��) "<< iBingoCount << "���� ����" << endl;

	if (iBingoCount >= 5) {
		cout << name << "��(��) " << "���� ���� ������ϴ�!" << endl;
		g_bGame = false;
	}
}

void CheckLine(int iNumber[25], int &iBingoCount) {
	
	for (int i = 0; i < 5; ++i) {
		int iStarCountW = 0, iStarCountH = 0;

		// ������ üũ
		for (int j = 0; j < 5; ++j) {
			if (iNumber[i * 5 + j] == INT_MAX) {
				++iStarCountH;
			}
		}

		// ������ üũ
		for (int j = 0; j < 5; ++j) {
			if (iNumber[j * 5 + i] == INT_MAX) {
				++iStarCountW;
			}
		}

		if (iStarCountW == 5) {
			++iBingoCount;
		}

		if (iStarCountH == 5) {
			++iBingoCount;
		}
	}

	// ���� ��� -> ������ �ϴ� �밢�� üũ
	int iStarCount = 0;
	for (int i = 0; i < 5; ++i) {
		if (iNumber[i * 6] == INT_MAX) {
			++iStarCount;
		}
	}
	if (iStarCount == 5) {
		++iBingoCount;
	}

	iStarCount = 0;
	// ������ ��� -> ���� �ϴ� �밢�� üũ
	for (int i = 0; i < 5; ++i) {
		if (iNumber[i * 4] == INT_MAX) {
			++iStarCount;
		}

	}

	if (iStarCount == 5) {
		++iBingoCount;
	}
}

void InitPuzzle(int iNumber[25]) {
	for (int i = 0; i < 25; ++i) {
		iNumber[i] = i + 1;
	}
}

void ShowPuzzle(int iNumber[25]) {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (iNumber[i * 5 + j] == INT_MAX) {
				cout << "*\t";
			}
			else {
				cout << iNumber[i * 5 + j] << "\t";
			}
		}
		cout << endl;
	}	
}

void Shuffle(int iNumber[25])
{
	int idx1, idx2, iTemp;

	
	// Shuffle
	for (int i = 0; i < 100; ++i) {
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}
}
