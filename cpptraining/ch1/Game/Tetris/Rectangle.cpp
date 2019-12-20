#include "Rectangle.h"



CRectangle::CRectangle()
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m_cShape[i][j] = '1'; // 빈공간
		}
	}
}


CRectangle::~CRectangle()
{
}

bool CRectangle::Init()
{
	if (!CShape::Init()) {
		return false;
	}

	/*
	1111
	1111
	0011
	0011
	*/
	
	// 정 사각형 블록
	m_cShape[2][0] = '0'; 
	m_cShape[2][1] = '0';
	m_cShape[3][0] = '0';
	m_cShape[3][1] = '0';

	m_iWidthCount = 2; // 가로 개수는 2개
	m_tPos.x = 4;
	m_tPos.y = 0;
	
	return true;
}
