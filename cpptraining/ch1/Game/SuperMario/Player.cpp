#include "Player.h"
#include "MapManager.h"
#include "Stage.h"
#include "ObjectManager.h"

CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
}

bool CPlayer::Init()
{
	m_tPos.x = 0;
	m_tPos.y = 8;

	m_bJump = false;
	m_bComplete = false;
	m_iJumpDir = JD_STOP;
	m_iJumpState = 0;
	m_iScore = 0;

	m_bBulletFire = false;

	return true;
}

void CPlayer::Update()
{
	CStage* pStage = CMapManager::GetInst()->GetStage();
	// Ű �Է��� �޴´�.

	// GetAsyncKeyState �Լ��� Win32 API���� �����Ǵ� Ű �Է� �Լ��̴�.
	// WŰ�� ������ �� �ٷ� �����ϰ� �ϱ� ���ؼ� 0x8000�� &������ �Ͽ� 
	// ������ ��� true�� ������ �ȴ�.
	if (GetAsyncKeyState('A') & 0x8000) { // ��
		if (pStage->GetBlock(m_tPos.x - 1, m_tPos.y) != SBT_WALL) {
			--m_tPos.x;
			if (m_tPos.x < 0) { // ���� ���� ����
				m_tPos.x = 0;
			}
		}
	}
	if (GetAsyncKeyState('D') & 0x8000) { // ��
		if (pStage->GetBlock(m_tPos.x + 1, m_tPos.y) != SBT_WALL) {
			++m_tPos.x;
			if (m_tPos.x >= BLOCK_X) { // ������ ���� ����
				m_tPos.x = 49;
			}
		}
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000 && !m_bJump) { // ����
		m_bJump = true;
		m_iJumpDir = JD_UP;
		m_iJumpState = 0;
	}

	if (GetAsyncKeyState('V') & 0x8000) {
		
	}

	if (m_bJump) { // ���� ���¸�
		CStage* pStage = CMapManager::GetInst()->GetStage();

		switch (m_iJumpDir) {
		case JD_UP:
			++m_iJumpState;

			if (m_iJumpState > JUMP_BLOCK_MAX) { // ������ �ö�����
				m_iJumpState = JUMP_BLOCK_MAX;
				m_iJumpDir = JD_DOWN;
			}
			else if (pStage->GetBlock(m_tPos.x, m_tPos.y - 1) == SBT_WALL) { // �ٷ� �Ӹ� ������ ���̸�
				--m_iJumpState;
				// ���� ���� �� �������� �����ϰ� �� �� �ϳ��� �������Ѵ�.
				int iRand = rand() % 100;
				cout << "iRand : " << iRand << endl;
				system("pause");
				STAGE_BLOCK_TYPE eBlockType;
				char cItem;
				if (iRand < 90)
					eBlockType = SBT_ITEM_BULLET;
				else
					eBlockType = SBT_ITEM_BIG;

				pStage->ChangeBlock(m_tPos.x,  m_tPos.y - 1, eBlockType); // ����� ��� �ٲ۴�. 
				m_iJumpDir = JD_DOWN;
			}
			else { // �� �ö�����
				--m_tPos.y;
			}
			break;
		case JD_DOWN: 
			if (pStage->GetBlock(m_tPos.x, m_tPos.y + 1) == SBT_WALL) { // �ؿ��� ���̸�
				m_iJumpDir = JD_STOP;
				m_bJump = false;
			}
			else {
				++m_tPos.y;
			}
			break;
		}
	}

	// �߷�?
	if (pStage->GetBlock(m_tPos.x, m_tPos.y + 1) != SBT_WALL && !m_bJump) { // �� ���� ���� �ƴϰ� �������°� �ƴ϶��
 		++m_tPos.y;
	}

	STAGE_BLOCK_TYPE eCurBlockType = (STAGE_BLOCK_TYPE)pStage->GetBlock(m_tPos.x, m_tPos.y);

	// �÷��̾ �ִ� ��ġ�� �����̸�
	if (eCurBlockType == SBT_COIN) {
		pStage->ChangeBlock(m_tPos.x, m_tPos.y, SBT_ROAD);
		m_iScore += 1000;
	}
	// �Ѿ� �߻�
	else if (eCurBlockType == SBT_ITEM_BULLET) {
		m_bBulletFire = true;
		pStage->ChangeBlock(m_tPos.x, m_tPos.y, SBT_ROAD);
	}

	// �÷��̾ �ִ� ��ġ�� �������̸�
	else if (eCurBlockType == SBT_END) {
		m_bComplete = true;
	}

	cout << "current m_tPos.x : " << m_tPos.x << ", m_tPos.y : " << m_tPos.y << endl;
	
	if (m_tPos.y >= BLOCK_Y) {
		cout << "�÷��̾� ���" << endl;
		m_tPos = pStage->GetStart();
		m_iScore = 0;
		pStage->ResetStage();
		system("pause");
		return;
	}

	// ���콺 ���� ��ư�� ������ �� �Ѿ� ����
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && m_bBulletFire) {
		CObjectManager::GetInst()->CreateBullet();
	}
}
