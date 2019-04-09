#pragma once

#include "Point.h"

#define EMPTY -1

class Board {
	int board_[10][20];
public:
	Board();
	int GetState(Point pos);				//Pos ��ġ�� ���¸� ��ȯ�� : �ܼ��� board_[][] ���� ��ȯ�ϸ� ��
	void SetState(Point pos, int state);	//Pos ��ġ�� ���� State ������ ������
	int CheckLineFull(Point reference_pos); //Ư�� ���� ��Ʈ�ι̳�� ���� �� �ִ��� ����. ���� �� �ִٸ� �� ���� ���ε��� �� ĭ�� ���� 
											//���������� ������ ���� �� ��ȯ
};


