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
	m_bBigItem = false;

	return true;
}

void CPlayer::Update()
{
	CStage* pStage = CMapManager::GetInst()->GetStage();
	// 키 입력을 받는다.

	// GetAsyncKeyState 함수는 Win32 API에서 제공되는 키 입력 함수이다.
	// W키를 눌렀을 때 바로 반응하게 하기 위해서 0x8000과 &연산을 하여 
	// 눌렀을 경우 true가 나오게 된다.
	if (GetAsyncKeyState('A') & 0x8000) { // 좌
		if (pStage->GetBlock(m_tPos.x - 1, m_tPos.y) != SBT_WALL) {
			if (!m_bBigItem) {
				--m_tPos.x;
			}
			else {
				// 커지는 아이템을 획득한 상태라면 위칸의 왼쪽도 체크
				if (pStage->GetBlock(m_tPos.x - 1, m_tPos.y - 1) != SBT_WALL) {
					--m_tPos.x;
				}
			}

			if (m_tPos.x < 0) { // 왼쪽 범위 제한
				m_tPos.x = 0;
			}
		}
	}
	if (GetAsyncKeyState('D') & 0x8000) { // 우
		if (pStage->GetBlock(m_tPos.x + 1, m_tPos.y) != SBT_WALL) {
			if (!m_bBigItem) {
				++m_tPos.x;
			}
			else {
				// 커지는 아이템을 획득한 상태라면 위칸의 왼쪽도 체크
				if (pStage->GetBlock(m_tPos.x + 1, m_tPos.y - 1) != SBT_WALL) {
					++m_tPos.x;
				}
			}
			if (m_tPos.x >= BLOCK_X) { // 오른쪽 범위 제한
				m_tPos.x = 49;
			}
		}
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000 && !m_bJump) { // 점프
		m_bJump = true;
		m_iJumpDir = JD_UP;
		m_iJumpState = 0;
	}

	int iBigCount = 1;

	if (m_bBigItem) { // 커지는 아이템을 획득한 상태면 
		iBigCount = 2;
	}

	if (m_bJump) { // 점프 상태면
		CStage* pStage = CMapManager::GetInst()->GetStage();


		switch (m_iJumpDir) {
		case JD_UP:
			++m_iJumpState;

			if (m_iJumpState > JUMP_BLOCK_MAX) { // 끝까지 올라갔으면
				m_iJumpState = JUMP_BLOCK_MAX;
				m_iJumpDir = JD_DOWN;
			}
			else if (pStage->GetBlock(m_tPos.x, m_tPos.y - iBigCount) == SBT_WALL ){ // 바로 머리 위에가 벽이면
				--m_iJumpState;
				// 벽을 깼을 때 아이템을 랜덤하게 둘 중 하나로 나오게한다.
				int iRand = rand() % 100;
				STAGE_BLOCK_TYPE eBlockType;

				char cItem;
				if (iRand < 50) // 확률 반반씩
					eBlockType = SBT_ITEM_BULLET;
				else
					eBlockType = SBT_ITEM_BIG;

				pStage->ChangeBlock(m_tPos.x, m_tPos.y - iBigCount, eBlockType); // 블록을 길로 바꾼다. 
				m_iJumpDir = JD_DOWN;
			}
			else { // 덜 올라갔으면
				--m_tPos.y;
			}
			break;
		case JD_DOWN:
			if (pStage->GetBlock(m_tPos.x, m_tPos.y + 1) == SBT_WALL) { // 밑에가 벽이면
				m_iJumpDir = JD_STOP;
				m_bJump = false;
			}
			else {
				++m_tPos.y;
			}
			break;
		}
	}

	// 중력?
	if (pStage->GetBlock(m_tPos.x, m_tPos.y + 1) != SBT_WALL && !m_bJump) { // 발 밑이 벽이 아니고 점프상태가 아니라면
		++m_tPos.y;
	}

	STAGE_BLOCK_TYPE eCurBlockType = (STAGE_BLOCK_TYPE)pStage->GetBlock(m_tPos.x, m_tPos.y);
	STAGE_BLOCK_TYPE eUpBlockType= (STAGE_BLOCK_TYPE)pStage->GetBlock(m_tPos.x, m_tPos.y - 1);

	// 플레이어가 있는 위치가 코인이면
	if (eCurBlockType == SBT_COIN || (eUpBlockType == SBT_COIN && m_bBigItem)) {
		pStage->ChangeBlock(m_tPos.x, m_tPos.y, SBT_ROAD);
		pStage->ChangeBlock(m_tPos.x, m_tPos.y - 1, SBT_ROAD); // 커져있는 상태도 포함
		m_iScore += 1000;
	}
	// 총알 발사
	else if (eCurBlockType == SBT_ITEM_BULLET || (eUpBlockType == SBT_ITEM_BULLET && m_bBigItem)) {
		m_bBulletFire = true;
		pStage->ChangeBlock(m_tPos.x, m_tPos.y, SBT_ROAD);
		pStage->ChangeBlock(m_tPos.x, m_tPos.y - 1, SBT_ROAD);
	}
	// 커지는 아이템
	else if (eCurBlockType == SBT_ITEM_BIG || (eUpBlockType == SBT_ITEM_BIG && m_bBigItem)) {
		m_bBigItem = true;
		pStage->ChangeBlock(m_tPos.x, m_tPos.y, SBT_ROAD);
		pStage->ChangeBlock(m_tPos.x, m_tPos.y - 1, SBT_ROAD);
	}
	// 플레이어가 있는 위치가 목적지이면
	else if (eCurBlockType == SBT_END || (eUpBlockType == SBT_END && m_bBigItem)) {
		m_bComplete = true;
	}

	cout << "current m_tPos.x : " << m_tPos.x << ", m_tPos.y : " << m_tPos.y << endl;

	if (m_tPos.y >= BLOCK_Y) {
		cout << "플레이어 사망" << endl;
		m_tPos = pStage->GetStart();
		pStage->ResetStage();
		Reset();
		system("pause");
		return;
	}

	if (GetAsyncKeyState('L') & 0x8000 && m_bBulletFire) {
		//// 마우스 왼쪽 버튼을 눌렀을 때 총알 생성
		//if (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && m_bBulletFire) {
		POINT tPos = m_tPos;
		++tPos.x; // 한칸 오른쪽에 생성하게 한다.
		CObjectManager::GetInst()->CreateBullet(tPos);
	}
}

