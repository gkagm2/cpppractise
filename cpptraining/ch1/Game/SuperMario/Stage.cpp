#include "Stage.h"
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
	m_bDebugViewMode = false;
	return true;
}

bool CStage::Init(const char * pFileName)
{
	Init();

	CFileStream file;

	if (!file.Open(pFileName, "rt"))
		return false;

	for (int i = 0; i < BLOCK_Y; ++i) { // 10줄
		int iSize = 0;
		file.ReadLine(m_cOriginStage[i], iSize);

		for (int j = 0; j < BLOCK_X; ++j) {
			m_cStage[i][j] = m_cOriginStage[i][j];

			if (m_cOriginStage[i][j] == SBT_START) {
				m_tStart.x = j;
				m_tStart.y = i;
			}
			else if (m_cOriginStage[i][j] == SBT_END) {
				m_tEnd.x = j;
				m_tEnd.y = i;
			}
		}

		//// 출력 확인
		//for (int j = 0; j < 50; ++j) {
		//	cout << m_cStage[i][j];
		//}
		cout << endl;
	}

	cout << endl << endl;
	//file.Close();
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



	if (GetAsyncKeyState('V') && 0x8000) {
		if (m_bDebugViewMode) {
			m_bDebugViewMode = false;

		}
		else {
			m_bDebugViewMode = true;
		}
	}

	cout << "V : View 바꾸기" << endl;
	if (m_bDebugViewMode) {
		for (int i = 0; i < BLOCK_Y; ++i) {
			for (int j = 0; j < BLOCK_X; ++j) {
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
					cout << "☆"; // 2byte 
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
	else {
		// 플레이어의 좌표를 중심으로 맵을 보여준다.
		// 세로는 플레이어 세칸 위부터 한칸 아래까지 출력한다.
		// 총 5줄이 출력되는 것이다.
		// 가로는 플레이어 위치부터 오른쪽 10칸까지 출력한다

		// 렌더링 할 Y의 시작점을 계산한다. (맵 밖의 구역은 렝더링하지 않게 정해줌)
		int iYTop = iY - (RENDER_BLOCK_Y - 2);
		if (iYTop <= 0) {
			iYTop = 0;
		}
		else if (iYTop >= BLOCK_Y - RENDER_BLOCK_Y) {
			iYTop = BLOCK_Y - RENDER_BLOCK_Y - 1;
		}
		
		// 렌더링 할 X의 시작점을 계산한다. (맵 밖의 구역은 렝더링하지 않게 정해줌)
		int iXLeft= iX;
		if (iXLeft >= BLOCK_X - RENDER_BLOCK_X) {
			iXLeft = BLOCK_X - RENDER_BLOCK_X - 1;
		}

		for (int y = iYTop; y <= iYTop + RENDER_BLOCK_Y; ++y) {
			for(int x = iXLeft; x <= iXLeft + RENDER_BLOCK_X ; ++x) {
				if (y == iY && x == iX) {
					cout << "§";
				}
				else if (m_cStage[y][x] == SBT_WALL) {
					cout << "■";
				}
				else if (m_cStage[y][x] == SBT_ROAD) {
					cout << "  "; // 2byte 
				}
				else if (m_cStage[y][x] == SBT_START) {
					cout << "☆"; // 2byte 
				}
				else if (m_cStage[y][x] == SBT_END) {
					cout << "◑"; // 2byte
				}
				else if (m_cStage[y][x] == SBT_COIN) {
					cout << "＠"; // 2byte 
				}
			}
			cout << endl;
		}
	}
}

void CStage::ResetStage()
{
	for (int i = 0; i < BLOCK_Y; ++i) {
		for (int j = 0; j < BLOCK_X; ++j) {
			m_cStage[i][j] = m_cOriginStage[i][j];
		}
	}
}
