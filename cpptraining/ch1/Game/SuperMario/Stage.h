#pragma once

#include "value.h"

enum STAGE_BLOCK_TYPE {
	SBT_WALL = '0', //ASCII CODE : 48
	SBT_ROAD = '1', //ASCII CODE : 49
	SBT_START = '2', //ASCII CODE : 50
	SBT_END = '3', //ASCII CODE : 51
	SBT_COIN = '4' //ASCII CODE : 52
};

class CStage
{
public:
	CStage();
	~CStage();
private:
	char m_cOriginStage[BLOCK_Y][BLOCK_X];
	char m_cStage[BLOCK_Y][BLOCK_X];
	POINT m_tStart;
	POINT m_tEnd;

public:
	POINT GetStart() {
		return m_tStart;
	}

	POINT GetEnd() {
		return m_tEnd;
	}

	char GetBlock(int x, int y) {
		return m_cStage[y][x];
	}

	void ChangeBlock(int x, int y, STAGE_BLOCK_TYPE eBlock) {
		m_cStage[y][x] = eBlock;
	}
public:
	// �� �Լ��� �׳� �ʱ�ȭ�� ������ �Լ��̴�.
	bool Init();

	// �� �Լ��� ���Ͽ��� ������ �о�ͼ� ������ ������ �Լ��̴�.
	bool Init(const char* pFileName);
	void Render();
	void ResetStage();

public :
	bool m_bDebugViewMode;
};

