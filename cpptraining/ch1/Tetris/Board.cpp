#include <iostream>
#include <Windows.h>
#include "Board.h"

#define COL GetStdHandle(STD_OUTPUT_HANDLE) //Std ��� �ڵ� (�ʼ�)
#define ORIGINAL SetConsoleTextAttribute(COL, 0x0007) //�ܼ� ���� �ٲٱ� (0x0007 : ���� ȸ��)

Board::Board(){

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++) {
			board_[i][j] = EMPTY;

		}
	}
}

int Board::GetState(Point pos) {

}
