#pragma once
using namespace std;
#include "Point.h"
#include "Controller.h"
class Tetris {
public:
	//생성자 : 기준 위치, 컨트롤 키 설정 가능
	Tetris(Point reference_pos = Point(1, 1), int key_esc = KEY_ESC, int key_left = KEY_LEFT, int key_rotate = KEY_UP, int key_down = KEY_DOWN, int key_space = KEY_SPACE);


};
