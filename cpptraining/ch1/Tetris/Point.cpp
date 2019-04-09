#include <Windows.h>
#include <conio.h>
#include <ctime>
#include "Point.h"

Point Point::operator+(const Point &pt) {
	return Point(x_ + pt.x_, y_ + pt.y_);
}

void Point::GotoXY(int x, int y) {
	//COORD : 좌표를 저장하는 구조체
	COORD Pos = {(short)x , (short)y};
	//콘솔 커서 이동 함수 (Std 출력 핸들을 얻어옴)
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Point::GotoXY(Point pos) {
	GotoXY(pos.GetX(), pos.GetY());
}

Point Point::GetScrPosFromCurPos(const Point &pos) { //배열 좌표를 화면 좌표로 가져온다.
	return Point(2 * pos.x_ + 2, (-1) * pos.y_ + 20);
}

