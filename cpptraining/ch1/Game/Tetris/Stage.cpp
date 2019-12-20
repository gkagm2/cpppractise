#include "Stage.h"



CStage::CStage() : m_iSpeed(10) // 1초에 10번 반복
{
}


CStage::~CStage()
{
}

bool CStage::Init()
{
	memset(m_Stage, 0, STAGE_HEIGHT * STAGE_WIDTH);
	return true;
}

void CStage::Render()
{
	for (int h = 0; h < STAGE_HEIGHT + 2; ++h) {
		for (int w = 0; w < STAGE_WIDTH + 2; ++w) {
			if (h == 0) { // 바깥쪽 벽이면
				cout << "□";
			}
			else if (w == 0) {
				cout << "□";
			}
			else if (h == STAGE_HEIGHT + 1) {
				cout << "□";
			}
			else if (w == STAGE_WIDTH + 1) {
				cout << "□";
			}
			else { // 블록이 쌓여지는 공간이라면
				cout << "  ";
			}

		}
		cout << endl;
	}
}