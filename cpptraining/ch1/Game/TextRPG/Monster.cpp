#include "Monster.h"

CMonster::CMonster()
{
	m_eType = OT_MONSTER;
}

CMonster::~CMonster()
{
}

bool CMonster::Init()
{
	return true;
}
