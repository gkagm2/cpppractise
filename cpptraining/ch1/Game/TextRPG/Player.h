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
	enum JOB {
		JOB_NONE,
		JOB_KNIGHT,
		JOB_ARCHER,
		JOB_WIZARD,
		JOB_END
	};

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
	int GetGold() const {
		return m_iGold;
	}
public:
	class CItem* Equip(class CItem* pItem);

public:
	virtual bool Init();
	virtual void Render();
	virtual CPlayer* Clone();
};