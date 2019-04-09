#include "Tetris.h"
#include "Controller.h"
#include <Windows.h>

#define COL GetStdHandle(STD_OUTPUT_HANDLE) //Std 출력 핸들 (필수)
#define ORIGINAL SetConsoleTextAttribute(COL, 0x0007); //콘솔 색깔 바꾸기 (0x0007 : 밝은 회색)
#define GOLD SetConsoleTextAttribute(COL, 0x0006); //금색
#define RED SetConsoleTextAttribute(COL, 0x000c); //빨강

using namespace std;

Tetris::Tetris(Point reference_pos = Point(1, 1), int key_esc = KEY_ESC, int key_left = KEY_LEFT, int key_rotate = KEY_UP, int key_down = KEY_DOWN, int key_space = KEY_SPACE) {

}
