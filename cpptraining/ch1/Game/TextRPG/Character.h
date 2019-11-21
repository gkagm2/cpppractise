#pragma once

#include "Obj.h"

class CCharacter : public CObj
{
protected:
	CCharacter();
	virtual ~CCharacter() = 0;

public:
	OBJECT_TYPE m_eType;

public:
	virtual bool Init();

	void SetCharacterInfo(int iAttackMin, int iAttackMax, int iArmorMin, int iArmorMax, int iHp, int iMp, int Exp, int Level);
};