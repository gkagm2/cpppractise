#include <iostream>
#include <Windows.h>
#include "Board.h"

#define COL GetStdHandle(STD_OUTPUT_HANDLE) //Std 출력 핸들 (필수)
#define ORIGINAL SetConsoleTextAttribute(COL, 0x0007) //콘솔 색깔 바꾸기 (0x0007 : 밝은 회색)

Board::Board(){

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++) {
			board_[i][j] = EMPTY;

		}
	}
}

int Board::GetState(Point pos) {

}
