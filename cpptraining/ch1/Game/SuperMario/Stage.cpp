#include "Stage.h"
#include "FileStream.h"
#include "Player.h"
#include "ObjectManager.h"
#include "Monster.h"

CStage::CStage() : 
	m_pMonsterArray(NULL),
	m_iMonsterCount(0),
	m_iMonsterArrayCount(0)
{
}

CStage::~CStage()
{
	for (int i = 0; i < m_iMonsterCount; ++i) {
		SAFE_DELETE(m_pMonsterArray[i]);
	}
	delete[] m_pMonsterArray;
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
			else if (m_cOriginStage[i][j] == SBT_MONSTER) {
				CreateMonster(j, i);
				// 몬스터인지 체크하여 몬스터만 생성하고 ROAD로 실제 맵을 바꿔준다.
				m_cStage[i][j] = SBT_ROAD;
			}
		}
	}
	return true;
}

void CStage::Update()
{
	for (int i = 0; i < m_iMonsterCount; ++i) {
		m_pMonsterArray[i]->Update();
	}
}

void CStage::Render()
{
	/*
	 맵은 스크롤 처리를 해야한다. 그렇기 때문에 현재 플레이어가
	 이동한 위치로부터 맵을 출력해주어야 한다. 출력 크기는 세로4칸
	 가로 10칸으로 해준다. 지금은 플레이어가 처음에 있다 라고 가정하고
	 처음 4 x 10 출력을 해준다.
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
		for (int y = 0; y < BLOCK_Y; ++y) {
			for (int x = 0; x < BLOCK_X; ++x) {
				if ((y == iY || (y == iY - 1 && pPlayer->GetBigItemEnable())) && x == iX) {
					cout << "§";
				}
				// 현재 위치에 총알이 있을 경우 총알로 출력
				else if (CObjectManager::GetInst()->CheckBullet(x, y)) {
					cout << "→";
				}
				// 몬스터가 현재 위치에 있다면 몬스터로 출력한다.
				else if (CheckMonster(y, x)) {
					cout << "▼";
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
				else if (m_cStage[y][x] == SBT_ITEM_BULLET) {
					cout << "⊙"; // 2byte 
				}
				else if (m_cStage[y][x] == SBT_ITEM_BIG) {
					cout << "↕"; // 2byte 
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
				if ((y == iY || (y == iY - 1 && pPlayer->GetBigItemEnable())) && x == iX) {
					cout << "§";
				}
				// 현재 위치에 총알이 있을 경우 총알로 출력
				else if (CObjectManager::GetInst()->CheckBullet(x, y)) {
					cout << "→";
				}
				// 몬스터가 현재 위치에 있다면 몬스터로 출력한다.
				else if (CheckMonster(y, x)) {
					cout << "▼";
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
				else if (m_cStage[y][x] == SBT_ITEM_BULLET) {
					cout << "⊙"; // 2byte 
				}
				else if (m_cStage[y][x] == SBT_ITEM_BIG) {
					cout << "↕"; // 2byte 
				}
			}
			cout << endl;
		}
	}
}

void CStage::ResetStage()
{
	for (int i = 0; i < m_iMonsterCount; ++i) {
		SAFE_DELETE(m_pMonsterArray[i]);
	}
	m_iMonsterCount = 0;

	for (int i = 0; i < BLOCK_Y; ++i) {
		for (int j = 0; j < BLOCK_X; ++j) {
			m_cStage[i][j] = m_cOriginStage[i][j];
			if (m_cOriginStage[i][j] == SBT_MONSTER) {
				CreateMonster(j, i);
				// 몬스터인지 체크하여 몬스터만 생성하고 ROAD로 실제 맵을 바꿔준다.
				m_cStage[i][j] = SBT_ROAD;
			}
		}
	}
}

CMonster * CStage::CreateMonster(int x, int y)
{
	// 배열이 동적할당 되지 않았을 경우에 동적할당 해준다.
	if (!m_pMonsterArray) {
		m_iMonsterArrayCount = 2;
		m_pMonsterArray = new CMonster*[m_iMonsterArrayCount];
	}
	// 만약 몬스터가 꽉 차있을 경우 배열을 늘려준다.
	if (m_iMonsterCount == m_iMonsterArrayCount) {
		// 공간을 늘려서 할당해준다. 2배만큼 공간을 늘려준다.
		m_iMonsterArrayCount *= 2;
		CMonster**  ppArray = new CMonster*[m_iMonsterArrayCount];

		// 기존에 있는 주소 정보를 이 배열로 옮겨준다.
		/*
		 memcpy : 메모리 복사 함수이다. :

		 memcpy(목적지포인터, 원본포인터, 크기);
		 void *memcpy(void *_Dst, void const *_Src, size_t _Size);
		 목적지 포인터를 반환

		 1번 인자에 들어간 메모리 주소에 2번 인자에 들어간 메모리 주소로부터
		 3번 인자에 들어간 바이트 수만큼 메모리를 복사한다.
		 몬스터가 꽉 찼다면 기존 배열은 이미 가득 차있다.
		 그래서 위에서 공간을 2배만큼 동적배열로 할당해주고
		 아래에서 새로 할당한 공간이 ex) 20개라면 기존 공간은 10개이다.
		 기존 공간의(2번인자) 동적할당된 메모리 주소들을 새로 할당된 공간으로
		 10개만큼 복사해주는 것이다.
		*/

		// ppArray에 있던 메모리를 sizeof(CMonster*) * m_iMonsterCount만큼의 크기로 m_pMonsterArray로 복사한다.
		memcpy(ppArray, m_pMonsterArray, sizeof(CMonster*) * m_iMonsterCount);
		delete[] m_pMonsterArray;
		m_pMonsterArray = ppArray;
	}

	// 실제 몬스터 객체를 할당한다.
	CMonster* pMonster = new CMonster;

	if (!pMonster->Init()) {
		SAFE_DELETE(pMonster);
		return NULL;
	}

	// 몬스터 위치정보를 설정한다.
	pMonster->SetPos(x, y);

	// 몬스터 배열에 넣어준다.
	m_pMonsterArray[m_iMonsterCount] = pMonster;
	++m_iMonsterCount;

	return pMonster;
}

bool CStage::CheckMonster(int x, int y)
{
	for (int i = 0; i < m_iMonsterCount; ++i) {
		if (m_pMonsterArray[i]->GetPos().x == x && m_pMonsterArray[i]->GetPos().y == y) {
			return true;
		}
	}
	return false;
}