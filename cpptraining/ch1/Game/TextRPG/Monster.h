#pragma once

#include "Character.h"

class CMonster : public CCharacter {
private:
	CMonster();
	CMonster(const CMonster& monster);
public:
	~CMonster();

private:
	friend class CObjectManager;
private:
	int m_iGoldMin;
	int m_iGoldMax;

public:
	void SetGold(int iMin, int iMax) {
		m_iGoldMin = iMin;
		m_iGoldMax = iMax;
	}

public:
	int GetGoldMin() const {
		return m_iGoldMin;
	}

	int GetGoldMax() const {
		return m_iGoldMax;
	}

	int GetDropGold() const {
		return rand() % (m_iGoldMax - m_iGoldMin + 1) + m_tInfo.iArmorMin;
	}

public:
	virtual bool Init();
	virtual void Render();
	virtual CMonster* Clone();
};