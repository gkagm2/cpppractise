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
	// 정 사각형 블록
	m_cShape[2][1] = '0'; 
	m_cShape[2][2] = '0';
	m_cShape[3][1] = '0';
	m_cShape[3][2] = '0';
	
	
	return true;
}
