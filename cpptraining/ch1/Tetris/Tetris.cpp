#include "Tetris.h"
#include "Controller.h"
#include <Windows.h>

#define COL GetStdHandle(STD_OUTPUT_HANDLE) //Std ��� �ڵ� (�ʼ�)
#define ORIGINAL SetConsoleTextAttribute(COL, 0x0007); //�ܼ� ���� �ٲٱ� (0x0007 : ���� ȸ��)
#define GOLD SetConsoleTextAttribute(COL, 0x0006); //�ݻ�
#define RED SetConsoleTextAttribute(COL, 0x000c); //����

using namespace std;

Tetris::Tetris(Point reference_pos = Point(1, 1), int key_esc = KEY_ESC, int key_left = KEY_LEFT, int key_rotate = KEY_UP, int key_down = KEY_DOWN, int key_space = KEY_SPACE) {

}
