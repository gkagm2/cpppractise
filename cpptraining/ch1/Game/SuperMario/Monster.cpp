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

	// �������� ������ ������ �����ش�.
	/*int iRandom = rand() % 2;*/
	//if (iRandom < 1) {
	//	m_iDir = DIR_LEFT; // ���� ����
	//}
	//else {
	//	m_iDir = DIR_RIGHT; // ������ ����
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

		// ������ ����ĭ �Ʒ���(����s ĭ�� �߹�) �������� ���̶�� ������ �ٲ��ش�.
		if (pStage->GetBlock(m_tPos.x + m_iDir, m_tPos.y + 1) != SBT_WALL) {
			// ������ �ݴ� �������� �ٲ��ش�.
			m_iDir *= -1;
		}
		// ������ ����ĭ�� ���̸� ������ �ٲ��ش�.
		else if (pStage->GetBlock(m_tPos.x + m_iDir, m_tPos.y) == SBT_WALL) {
			// ������ �ݴ� �������� �ٲ��ش�.
			m_iDir *= -1;
		}

		m_tPos.x += m_iDir;
	}
}