﻿#include "Stage.h"
#include "FileStream.h"
#include "Player.h"
#include "ObjectManager.h"

CStage::CStage()
{
}

CStage::~CStage()
{
}

bool CStage::Init()
{
	return true;
}

bool CStage::Init(const char * pFileName)
{
	CFileStream file;

	if (!file.Open(pFileName, "rt"))
		return false;

	for (int i = 0; i < BLOCK_Y; ++i) { // 10줄
		int iSize = 0;
		file.ReadLine(m_cStage[i], iSize);

		for (int j = 0; j < BLOCK_X; ++j) {
			if (m_cStage[i][j] == SBT_START) {
				m_tStart.x = j;
				m_tStart.y = i;
			}
			else if (m_cStage[i][j] == SBT_END) {
				m_tEnd.x = j;
				m_tEnd.y = i;
			}
		}

		// 출력 확인
		//for (int j = 0; j < 50; ++j) {
		//	cout << m_cStage[i][j];
		//}
		//cout << endl;
	}

	cout << endl << endl;
	file.Close();
	return true;
}

void CStage::Render()
{
	/*
	 맵은 스크롤 처리를 해야한다. 그렇기 때문에 현재 플레이어가
	 이동한 위치로부터 맵을 출력해주어야 한다. 출력 크기는 세로4칸
	 가로 10칸으로 해준다. 지금은 플레이어가 처음에 있다 라고 가정하고
	 처음 4 x 10 출력을 해준다.
	 0 : 벽, 1 :길, 2 : 시작점, 3 : 도착점, 4 : 코인
	 */

	CPlayer* pPlayer = CObjectManager::GetInst()->GetPlayer();

	// 현재 플레이어의 x, y 좌표를 얻어온다.
	int iX = pPlayer->GetX();
	int iY = pPlayer->GetY();
	
	// 플레이어의 좌표를 중심으로 맵을 보여준다.
	// 세로는 플레이어 2칸 위부터 한칸 아래까지 출력한다.
	// 총 4줄이 출력되는 것이다.
	// 가로는 플레이어 위치부터 오른쪽 10칸까지 출력한다.
	for (int i = iY - 2; i <= iY + 1; ++i) {
		for (int j = iX; j < iX + 10; ++j) {
			if (i == iY && j == iX) {
				cout << "§";
			}
			else if (m_cStage[i][j] == SBT_WALL) {
				cout << "■";
			}
			else if (m_cStage[i][j] == SBT_ROAD) {
				cout << "  "; // 2byte 
			}
			else if (m_cStage[i][j] == SBT_START) {
				cout << "◐"; // 2byte 
				m_tStart.x = j;
				m_tStart.y = i;
			}
			else if (m_cStage[i][j] == SBT_END) {
				cout << "◑"; // 2byte
			}
			else if (m_cStage[i][j] == SBT_COIN) {
				cout << "＠"; // 2byte 
			}
		}
		cout << endl;
	}
}
