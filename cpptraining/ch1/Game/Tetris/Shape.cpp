#include "Shape.h"
#include "Core.h"


CShape::CShape()
{
	m_iWidthCount = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m_cShape[i][j] = '1'; // 빈공간으로 
		}
	}
}

CShape::~CShape()
{
}

bool CShape::Init()
{
	m_tPivot.x = 0;
	m_tPivot.y = 3;
	return true;
}

void CShape::Render()
{
	// 콘솔창에 출력할 좌표를 설정한 후 출력.
	CCore::GetInst()->SetConsolePos(m_tPos.x, m_tPos.y);

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (m_cShape[i][j] == '0') { // 블록이면
				cout << "□";
			}
			else { // 빈 공간이면
				cout << ' ';
			}
		}
	}
}

void CShape::MoveDown()
{
	if (m_tPos.y == STAGE_HEIGHT - 1) {
		return;
	}

	++m_tPos.y;
}

void CShape::MoveLeft()
{
	if (m_tPos.x == 0) {
		return;
	}
	--m_tPos.x;
}

void CShape::MoveRight()
{
	if (m_tPos.x + m_iWidthCount == STAGE_WIDTH) {
		return;
	}

	++m_tPos.x;
}
