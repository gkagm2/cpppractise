// PROGRAM : 숫자 빙고게임
// DEV : Sagacity Jang
// DATE : 2019.10.30

#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

// 숫자 빙고게임 만들기
// 1 ~ 25 까지의 숫자가 있고 이 숫자를 골고루 섞어서 5 X 5로 출력한다.
// 플레이어는 숫자를 입력받는다. 1 ~ 25 사이의 숫자를 입력받아야 한다.
// 0을 입력하면 게임을 종료한다.

// 숫자를 입력받았으면 숫자 목록중 입력받은 숫자를 찾아서 *로 만들어준다.
// 숫자를 *로 만든 후에 빙고 줄 수를 체크한다. 5 X 5 이기 때문에 가로 5줄 세로 5줄 대각선 2줄이 나올 수 있다.
// 빙고줄이 몇 줄인지를 체크해서 화면에 보여준다.
// 5줄 이상일 경우 게임을 종료한다.

enum AI_MODE {
	AM_EASY = 1,
	AM_HARD
};

enum TURN {
	T_PLAYER,
	T_AI
};

enum LINE_NUMBER {
	LN_H1, // 가로 라인
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5, 
	LN_V1, // 세로 라인
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT, // 왼쪽 위 -> 오른쪽 아래 대각선 라인
	LN_RT  // 오른쪽 위 -> 왼쪽 아래 대각선 라인
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
		// AI 난이도를 선택한다.
		cout << "==빙고게임==" << endl << "AI 모드를 선택하세요." << endl << "1. easy" << endl << "2. hard" << endl;
		cin >> iAIMode;

		if (iAIMode == AM_EASY || iAIMode == AM_HARD) {
			system("cls");

			break;
		}
		else {
			system("cls");
			cout << "잘못 입력하였습니다." << endl << endl;
		}
	}
	
	bool bDuplication = true; // 중복검사

	int iNoneSelect[25] = {}; // 선택안된 목록 배열을 만들어준다.
	int iNoneSelectCount = 0; // 선택안된 숫자 개수.

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

		if (!g_bGame) { // 게임 종료
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
			// Player가 선택한다.
			cout << "'0'입력 시 종료.  숫자를 입력하세요 : ";
			cin >> iInput;

			// Check number
			if (iInput == 0) { // 게임 종료
				g_bGame = false;
				continue;
			}
			else if (iInput < 0 || iInput > 25) { // 범위 초과
				system("cls");
				cout << "숫자 범위를 벗어났습니다." << endl;
				continue;
			}

			bDuplication = true;
			for (int i = 0; i < 25; ++i) { // 다 돌면서 
				if (iInput == iNumber[i]) { // 입력한 값이 배열 안에 있으면
					bDuplication = false; // 중복 해제
					break;
				}
			}

			if (bDuplication) { // 중복된 값이면
				system("cls");
				cout << " 중복된 값 입니다." << endl;
				continue;
			}
			break;

		case T_AI:
			// AI가 선택한다.
			switch (iAIMode) {
			case AM_EASY:
				// AI Easy 모드는 현재 AI의 숫자목록중 *로 바뀌지 않은 숫자 목록을 만들어서 그 목록중 하나를 선택하게 된다.(랜덤하게)

				iNoneSelectCount = 0; // 선택안된 숫자 개수는 목록을 만들때 카운팅 해준다.
				// 선택안된 숫자 목록을 만들어 준다.
				for (int i = 0; i < 25; ++i) {
					if (iAINumber[i] != INT_MAX) { // 현재 숫자가 *이 아닐 경우
						iNoneSelect[iNoneSelectCount] = iAINumber[i];
						++iNoneSelectCount;
					}
				}
				// 선택이 안된 숫자중 랜덤한 하나의 숫자를 얻어오기 위해	 인덱스를랜덤으로 구해준다.
				iInput = iNoneSelect[rand() % iNoneSelectCount];
				break;
			case AM_HARD:
				// 하드모드는 현재 숫자중 빙고줄 완성 가능성이 가장 높은 줄을 찾아서 그 줄에 있는 숫자중 하나를 *로 만들어준다.
				int iLine = 0;
				int iStarCount = 0;
				int iSaveCount = 0;

				// 가로 라인 중 가장 *이 많은 라인을 찾아낸다.
				for (int i = 0; i < 5; ++i) {
					iStarCount = 0;
					for (int j = 0; j < 5; ++j) {
						if (iAINumber[i * 5 + j] == INT_MAX) {
							++iStarCount;
						}
					}
					// 별이 5개 미만이여야 빙고 줄이 아니고 기존에 가장많은 라인의 별보다 커야 가장 별이 많은 라인이므로
					// 라인을 교체해주고 저장된 별 수를 교체한다.
					if (iStarCount < 5 && iSaveCount < iStarCount) {
						// 가로 라인중 가장 별이 많은 라인을 체크하는 곳이다. 가로라인은 0 ~ 4 로 의미를 부여했다.
						iLine = i;
						iSaveCount = iStarCount;
					}
				}

				// 저장된 라인과 세로 라인들을 비교하여 별이 가장 많은 라인을 구한다.
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

				// 저장된 라인과 왼쪽 상단 -> 오른쪽 하단 라인을 비교하여 별이 가장 많은 라인을 구한다.
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

				// 저장된 라인과 오른쪽 상단 -> 왼쪽 하단 라인을 비교하여 별이 가장 많은 라인을 구한다.
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

				// 모든 라인을 조사했으면 iLine에 가장 높은 줄 번호가 저장됨.

				// 그 줄에 있는 *이 아닌 숫자중 하나를 선택하게 된다.
				// 가로줄일 경우 iLine 0 ~ 4 사이의 값
				if (iLine <= LN_H5) { 
					for (int i = 0; i < 5; ++i) {
						if (iAINumber[iLine * 5 + i] != INT_MAX) { // 현재 줄에서 *이 아닌 숫자를 찾는다.
							iInput = iAINumber[iLine * 5 + i];
							break;
						}
					}
				}
				// 세로줄일 경우 iLine 5 ~ 9 사이의 값
				else if (iLine <= LN_V5) {
					for (int i = 0; i < 5; ++i) {
						if (iAINumber[i * 5 + (iLine - 5)] != INT_MAX) {
							iInput = iAINumber[i * 5 + (iLine - 5)];
							break;
						}
					}
				}
				// 왼쪽 상단 -> 오른쪽 하단 
				else if (iLine == LN_LT) {
					for (int i = 0; i < 5; ++i) {
						if (iAINumber[i * 6] != INT_MAX) {
							iInput = iAINumber[i * 6];
							break;
						}
					}
				}
				// 오른쪽 상단 -> 왼쪽 하단
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
	cout << "게임 종료" << endl;

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
	cout << name <<"은(는) "<< iBingoCount << "개의 빙고" << endl;

	if (iBingoCount >= 5) {
		cout << name << "이(가) " << "먼저 빙고를 맞췄습니다!" << endl;
		g_bGame = false;
	}
}

void CheckLine(int iNumber[25], int &iBingoCount) {
	
	for (int i = 0; i < 5; ++i) {
		int iStarCountW = 0, iStarCountH = 0;

		// 세로줄 체크
		for (int j = 0; j < 5; ++j) {
			if (iNumber[i * 5 + j] == INT_MAX) {
				++iStarCountH;
			}
		}

		// 가로줄 체크
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

	// 왼쪽 상단 -> 오른쪽 하단 대각선 체크
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
	// 오른쪽 상단 -> 왼쪽 하단 대각선 체크
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
