// Title : �迭�� 0������ �̵��ϱ�
// Date : 2021.01.12
// Devloper : Hyeon Myeong Jang
// MBCS�� WBCS �������� ���α׷��� ���� �� ����.
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
	TCHAR ssDir[4][20] = { _T("����"), _T("������"), _T("��") ,_T("�Ʒ�") };

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
		_tprintf(_T("�̵�: ��(%d) ��(%d) ��(%d) ��(%d) ����(%d)\n"), UP, DOWN, LEFT, RIGHT, EXIT);
		_tprintf(_T("�Է�: "));
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
			_tprintf(_T("�߸� �Է��ϼ̽��ϴ�.\n"));
			system("pause");
			system("cls");
			continue;
		}
		if (moveX < 0 || moveY < 0 || moveX >= MAX_SIZE || moveY >= MAX_SIZE) {
			_tprintf(_T("%s���� �̵��� �� �����ϴ�.\b"), sDir);
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