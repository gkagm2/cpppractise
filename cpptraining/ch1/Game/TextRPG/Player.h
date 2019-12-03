#pragma once

#include "Character.h"


class CPlayer : public CCharacter {
private:
	CPlayer();
	CPlayer(const CPlayer& player);
	~CPlayer();

private:
	friend class CObjectManager;

private:
	enum EQUIP {
		EQ_WEAPON,
		EQ_ARMOR,
		EQ_END
	};

private:
	JOB m_eJob;
	string m_strJobName;
	int m_iGold;
	class CItem* m_pEquip[EQ_END];

public:
	void AddGold(int iGold);
	void UseGold(int iGold);
	void DropGold();

public:
	JOB GetJob() const {
		return m_eJob;
	}

	int GetGold() const {
		return m_iGold;
	}
	
	class CItem* GetEquip(EQUIP eq) const {
		return m_pEquip[eq];
	}

	virtual int GetDamage();
	virtual int GetArmor();

public:
	class CItem* Equip(class CItem* pItem);

public:
	virtual bool Init();
	virtual void Render();
	virtual CPlayer* Clone();
};