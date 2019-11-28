#pragma once

#include "Character.h"

enum JOB {
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};

class CPlayer : public CCharacter {
private:
	CPlayer();
	CPlayer(const CPlayer& player);
	~CPlayer();

private:
	friend class CObjectManager;

public:
	JOB m_eJob;
	string m_strJobName;
	int m_iGold;

public:
	void AddGold(int iGold);

public:
	virtual bool Init();
	virtual void Render();
	virtual CPlayer* Clone();
};