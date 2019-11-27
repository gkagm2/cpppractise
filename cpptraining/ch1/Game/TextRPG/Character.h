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
	int GetDamage() {
		return (rand() % (m_tInfo.iAttackMax - m_tInfo.iAttackMin + 1)) + m_tInfo.iAttackMin;
	}

	int GetArmor() {
		return (rand() % (m_tInfo.iArmorMax - m_tInfo.iArmorMin + 1)) + m_tInfo.iArmorMin;
	}

	bool Damage(int iDamage);
	bool AddExp(int iExp);
	bool CheckLevelUp();

public:
	virtual bool Init();
	virtual void Render();
	virtual CCharacter* Clone() = 0;
};