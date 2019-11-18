#pragma once

#include "value.h"

enum DIRECTION {
	DIR_LEFT = -1,
	DIR_RIGHT = 1
};

class CMonster
{
public:
	CMonster();
	~CMonster();

private:
	POINT m_tPos;
	int m_iDir; // ������ ����

public:
	void SetPos(int x, int y) {
		m_tPos.x = x;
		m_tPos.y = y;
	}
	
public:
	POINT GetPos() {
		return m_tPos;
	}
	
public:
	bool Init();
	void Update();
};