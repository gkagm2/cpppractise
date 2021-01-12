// Title : 배열에 0번숫자 이동하기
// Date : 2021.01.12
// Devloper : Hyeon Myeong Jang
// MBCS와 WBCS 동시지원 프로그래밍 연습 겸 제작.
#include <iostream>
#include <tchar.h>
#include <Windows.h>
#include <time.h>

const int MAX_SIZE = 5;
const int UP = 8;
const int DOWN = 2;
const int LEFT = 4;
const int RIGHT = 6;
const int EXIT = 5;

void ShuffleExceptZeroIdx(int mat[]) {
	int n1, n2;
	int t;
	for (int i = 0; i < MAX_SIZE * MAX_SIZE * 1000; ++i) {	
		n1 = (rand() % (MAX_SIZE * MAX_SIZE - 1)) + 1;
		n2 = (rand() % (MAX_SIZE * MAX_SIZE - 1)) + 1;
		t = mat[n1];
		mat[n1] = mat[n2];
		mat[n2] = t;
	}
}

void Swap(int *a, int *b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

int main(int argc, TCHAR* argv[]) {
	srand((unsigned)time(nullptr));
	_wsetlocale(LC_ALL, _T("korean"));
	int mat[MAX_SIZE * MAX_SIZE];

	int curX, curY;
	curX = curY = 0;
	TCHAR ssDir[4][20] = { _T("왼쪽"), _T("오른쪽"), _T("위") ,_T("아래") };

	int t = 0;
	for (int i = 0; i < MAX_SIZE * MAX_SIZE; ++i) {
		mat[i] = t++;
	}
	ShuffleExceptZeroIdx(mat);
	
	while (true) {
		for (int i = 0; i < MAX_SIZE; ++i) {
			for (int j = 0; j < MAX_SIZE; ++j) {
				_tprintf(_T("%d\t"), mat[i * MAX_SIZE + j]);
			}
			_fputtc('\n', stdout);
		}
		_tprintf(_T("이동: 상(%d) 하(%d) 좌(%d) 우(%d) 종료(%d)\n"), UP, DOWN, LEFT, RIGHT, EXIT);
		_tprintf(_T("입력: "));
		int input;
		_tscanf_s(_T("%d"), &input);
		if (input == EXIT)
			break;

		int moveX, moveY;
		moveX = curX;
		moveY = curY;
		TCHAR sDir[20];
		switch (input) {
		case LEFT:
			--moveX;
			_tcscpy_s(sDir, ssDir[0]);
			break;
		case RIGHT:
			++moveX;
			_tcscpy_s(sDir, ssDir[1]);
			break;
		case UP:
			--moveY;
			_tcscpy_s(sDir, ssDir[2]);
			break;
		case DOWN:
			++moveY;
			_tcscpy_s(sDir, ssDir[3]);
			break;
		default:
			_tprintf(_T("잘못 입력하셨습니다.\n"));
			system("pause");
			system("cls");
			continue;
		}
		if (moveX < 0 || moveY < 0 || moveX >= MAX_SIZE || moveY >= MAX_SIZE) {
			_tprintf(_T("%s으로 이동할 수 없습니다.\b"), sDir);
			system("pause");
			system("cls");
			continue;
		}

		Swap(&mat[curY * MAX_SIZE + curX], &mat[moveY * MAX_SIZE + moveX]);
		curX = moveX;
		curY = moveY;
		
		system("cls");
	}


	system("pause");

	return 0;
}