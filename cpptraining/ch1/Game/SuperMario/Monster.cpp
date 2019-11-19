#include "Monster.h"
#include "Stage.h"
#include "MapManager.h"

CMonster::CMonster()
{
}


CMonster::~CMonster()
{
}

bool CMonster::Init()
{
	m_tPos.x = 0;
	m_tPos.y = 0;
	m_iFrameCount = 0;

	// 랜덤으로 움직일 방향을 정해준다.
	/*int iRandom = rand() % 2;*/
	//if (iRandom < 1) {
	//	m_iDir = DIR_LEFT; // 왼쪽 방향
	//}
	//else {
	//	m_iDir = DIR_RIGHT; // 오른쪽 방향
	//}
	m_iDir = -1;
	m_iSpeed = 3;

	return true;
}

void CMonster::Update()
{
	++m_iFrameCount;
	if (m_iFrameCount == m_iSpeed) {
		m_iFrameCount = 0;
		CStage* pStage = CMapManager::GetInst()->GetStage();
		pStage->GetBlock(m_tPos.x + m_iDir, m_tPos.y + 1);
		pStage->GetBlock(m_tPos.x + m_iDir, m_tPos.y);

		// 움직일 다음칸 아래가(움직s 칸의 발밑) 떨어지는 곳이라면 방향을 바꿔준다.
		if (pStage->GetBlock(m_tPos.x + m_iDir, m_tPos.y + 1) != SBT_WALL) {
			// 방향을 반대 방향으로 바꿔준다.
			m_iDir *= -1;
		}
		// 움직일 다음칸이 벽이면 방향을 바꿔준다.
		else if (pStage->GetBlock(m_tPos.x + m_iDir, m_tPos.y) == SBT_WALL) {
			// 방향을 반대 방향으로 바꿔준다.
			m_iDir *= -1;
		}

		m_tPos.x += m_iDir;
	}
}