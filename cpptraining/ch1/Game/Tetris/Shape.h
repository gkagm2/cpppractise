#pragma once

#include "value.h"

class CShape
{
public:
	CShape();
	virtual ~CShape();

protected:
	char m_cShape[4][4];
	POSITION m_tPos;
	POSITION m_tPivot;
	int m_iWidthCount;

public:
	void SetPosition(const int x, const int y) {
		m_tPos.x = x;
		m_tPos.y = y;
	}

	void SetPosition(const POSITION& pos) {
		m_tPos = pos;
	}

	POSITION GetPosition() const {
		return m_tPos;
	}

	POSITION GetPivot() const {
		return m_tPivot;
	}

public:
	virtual bool Init();

public:
	void Render();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
};