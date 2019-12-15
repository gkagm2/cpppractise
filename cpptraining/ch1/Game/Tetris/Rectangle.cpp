#include "Rectangle.h"



CRectangle::CRectangle()
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m_cShape[i][j] = '1'; // ºó°ø°£
		}
	}
}


CRectangle::~CRectangle()
{
}

bool CRectangle::Init()
{
	
	return true;
}
