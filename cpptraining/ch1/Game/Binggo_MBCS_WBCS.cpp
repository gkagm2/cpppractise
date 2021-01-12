// Title : Binggo game
// Date : 2021.01.12
// Devloper : Hyeon Myeong Jang
// Explain : 5번의 빙고가 되면 승리
// MBCS와 WBCS 동시지원 프로그래밍 연습 겸 빙고 게임 제작
#include <iostream>
#include <tchar.h>
#include <locale.h>
#include <Windows.h>
#include <time.h>
using namespace std;

const int BINGGO_SIZE = 5;
const int VICTORY_BINGGO_CNT = 5;

bool IsCorrectInput(const int _binggoBoard[][BINGGO_SIZE], int _inputNum);
void EraseBoardNumber(int _binggoBoard[][BINGGO_SIZE], int _inputNum);
int GetBinggoCnt(const int _binggoBoard[][BINGGO_SIZE]);
void ShuffleBoard(int _binggoBoard[][BINGGO_SIZE]);
void InitBoard(int _binggoBoard[][BINGGO_SIZE]);

int _tmain(int argc, TCHAR *argv[]) {
	srand((unsigned)time(nullptr));

	_wsetlocale(LC_ALL, _T("korean"));
	bool isGameOver = false;

	int binggoCnt = 0;
	int roundCnt = 0;

	int binggoBoard[BINGGO_SIZE][BINGGO_SIZE];

	// Init Biggo board
	InitBoard(binggoBoard);

	while (!isGameOver) {
		system("cls");
		_tprintf(_T("현재 빙고: %d    라운드: %d\n"), binggoCnt, roundCnt);
		_tprintf(_T("=========================================\n"));
		for (int y = 0; y < BINGGO_SIZE; ++y) {
			for (int x = 0; x < BINGGO_SIZE; ++x) {
				cout << binggoBoard[y][x] << "\t";
			}
			cout << "\n";
		}
		_tprintf(_T("=========================================\n"));
		if (binggoCnt >= VICTORY_BINGGO_CNT) {
			isGameOver = true;
			continue;
		}

		_tprintf(_T("빙고 입력: "));
		int inputNum;
		_tscanf_s(_T("%d"), &inputNum);

		if (!IsCorrectInput(binggoBoard, inputNum)) {
			_tprintf(_T("잘못 입력하였습니다.\n"));
			system("pause");
			continue;
		}

		EraseBoardNumber(binggoBoard, inputNum);
		binggoCnt = GetBinggoCnt(binggoBoard);
		++roundCnt;
	}

	_tprintf(_T("승리!!!\n"));
	system("pause");
	return 0;
}

bool IsCorrectInput(const int _binggoBoard[][BINGGO_SIZE], int _inputNum) {
	if (_inputNum <= 0 || _inputNum > BINGGO_SIZE * BINGGO_SIZE)
		return false;
	for (int y = 0; y < BINGGO_SIZE; ++y) {
		for (int x = 0; x < BINGGO_SIZE; ++x) {
			if (_binggoBoard[y][x] == _inputNum)
				return true; // 찾았으면 
		}
	}
	return false;
}

void EraseBoardNumber(int _binggoBoard[][BINGGO_SIZE], int _inputNum) {
	for (int y = 0; y < BINGGO_SIZE; ++y) {
		for (int x = 0; x < BINGGO_SIZE; ++x) {
			if (_binggoBoard[y][x] == _inputNum) {
				_binggoBoard[y][x] = 0;
				return;
			}
		}
	}
}
int GetBinggoCnt(const int _binggoBoard[][BINGGO_SIZE]) {
	int binggoCnt = 0;
	int tempCnt;

	// cross check (left top to right bottom)
	tempCnt = 0;
	for (int i = 0; i < BINGGO_SIZE; ++i) {
		if (_binggoBoard[i][i] == 0)
			++tempCnt;
	}
	if (tempCnt == BINGGO_SIZE)
		++binggoCnt;

	// cross check (right top to left bottom)
	tempCnt = 0;
	for (int i = 0; i < BINGGO_SIZE; ++i) {
		if (_binggoBoard[i][BINGGO_SIZE - i - 1] == 0)
			++tempCnt;
	}
	if (tempCnt == BINGGO_SIZE)
		++binggoCnt;


	// row check
	for (int y = 0; y < BINGGO_SIZE; ++y) {
		tempCnt = 0;
		for (int x = 0; x < BINGGO_SIZE; ++x) {
			if (_binggoBoard[y][x] == 0)
				++tempCnt;
		}
		if (tempCnt == BINGGO_SIZE)
			++binggoCnt;
	}

	// column check
	for (int y = 0; y < BINGGO_SIZE; ++y) {
		tempCnt = 0;
		for (int x = 0; x < BINGGO_SIZE; ++x) {
			if (_binggoBoard[x][y] == 0)
				++tempCnt;
		}
		if (tempCnt == BINGGO_SIZE)
			++binggoCnt;
	}
	return binggoCnt;
}

void ShuffleBoard(int _binggoBoard[][BINGGO_SIZE]) {
	int y1, x1, y2, x2;
	int t;
	for (int i = 0; i < BINGGO_SIZE * 100; ++i) {
		x1 = rand() % BINGGO_SIZE;
		y1 = rand() % BINGGO_SIZE;
		x2 = rand() % BINGGO_SIZE;
		y2 = rand() % BINGGO_SIZE;

		t = _binggoBoard[y1][x1];
		_binggoBoard[y1][x1] = _binggoBoard[y2][x2];
		_binggoBoard[y2][x2] = t;
	}
}

void InitBoard(int _binggoBoard[][BINGGO_SIZE]) {
	int tempNum = 1;
	for (int y = 0; y < BINGGO_SIZE; ++y)
		for (int x = 0; x < BINGGO_SIZE; ++x)
			_binggoBoard[y][x] = tempNum++;
	ShuffleBoard(_binggoBoard);
}