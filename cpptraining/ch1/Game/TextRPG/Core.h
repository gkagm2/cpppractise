#pragma once

#include "value.h"
#include "StageManager.h"

class CCore {
private:
	LEVELUPINFO m_tLevelUpInfo[JOB_END - 1];

public:
	LEVELUPINFO GetLevelUpInfo(JOB eJob);

public:
	bool Init();
	void Run();

private:
	int OutputMenu();
	void SetLevelUpInfo();
	LEVELUPINFO CreateLevelUpInfo(int iAttackMin, int iAttackMax, int iArmorMin, int iArmorMax, int iHp, int iMp);

	DECLARE_SINGLE(CCore)
};