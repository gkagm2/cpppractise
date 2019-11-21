#pragma once

#include "Obj.h"

class CCharacter : public CObj
{
protected:
	CCharacter();
	CCharacter(const CCharacter& character);
	virtual ~CCharacter() = 0;

public:
	OBJECT_TYPE m_eType;

protected:
	CHARACTERINFO m_tInfo;

public:
	CHARACTERINFO GetCharacterInfo() const {
		return m_tInfo;
	}

	void SetCharacterInfo(int iAttackMin, int iAttackMax, int iArmorMin, int iArmorMax, int iHp, int iMp, int iLevel, int iExp);

public:
	virtual bool Init();
	virtual void Render();
	virtual CCharacter* Clone() = 0;
};