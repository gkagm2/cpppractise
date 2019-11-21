#pragma once

#include "Character.h"

class CPlayer : public CCharacter {
private:
	CPlayer();
	~CPlayer();

private:
	friend class CObjectManager;

public:
	string m_strJobName;
	JOB m_eJob;

public:
	virtual bool Init();
};

enum JOB {
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};