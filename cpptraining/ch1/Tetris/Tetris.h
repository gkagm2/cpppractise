#pragma once
using namespace std;
#include "Point.h"
#include "Controller.h"
class Tetris {
	bool running_;				//종료 조건인 경우 이 값이 true가 됨
	Point reference_pos_;		//화면상에 나타낼 기준 위치 (1, 1)인 경우 실제 (0, 0)으로 맵핑됨
	


public:
	//생성자 : 기준 위치, 컨트롤 키 설정 가능
	Tetris(Point reference_pos = Point(1, 1), int key_esc = KEY_ESC, int key_left = KEY_LEFT, int key_rotate = KEY_UP, int key_down = KEY_DOWN, int key_space = KEY_SPACE);


};
