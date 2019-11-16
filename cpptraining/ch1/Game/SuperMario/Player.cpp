#include "Player.h"
#include "MapManager.h"
#include "Stage.h"

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
			--m_tPos.x;
			if (m_tPos.x < 0) { // 왼쪽 범위 제한
				m_tPos.x = 0;
			}
		}
	}
	if (GetAsyncKeyState('D') & 0x8000) { // 우
		if (pStage->GetBlock(m_tPos.x + 1, m_tPos.y) != SBT_WALL) {
			++m_tPos.x;
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

	if (GetAsyncKeyState('V') & 0x8000) {
		
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
			else if (pStage->GetBlock(m_tPos.x, m_tPos.y - 1) == SBT_WALL) { // 바로 머리 위에가 벽이면
				--m_iJumpState;
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

	// 플레이어가 있는 위치가 코인이면
	if (pStage->GetBlock(m_tPos.x, m_tPos.y) == SBT_COIN) {
		pStage->ChangeBlock(m_tPos.x, m_tPos.y, SBT_ROAD);
		m_iScore += 1000;
	}
	// 플레이어가 있는 위치가 목적지이면
	else if (pStage->GetBlock(m_tPos.x, m_tPos.y) == SBT_END) {
		m_bComplete = true;
	}

	cout << "current m_tPos.x : " << m_tPos.x << ", m_tPos.y : " << m_tPos.y << endl;
	
	if (m_tPos.y >= BLOCK_Y) {
		cout << "플레이어 사망" << endl;
		m_tPos = pStage->GetStart();
		m_iScore = 0;
		pStage->ResetStage();
		system("pause");
	}
}
