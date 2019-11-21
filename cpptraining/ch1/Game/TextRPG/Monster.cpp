#include "Monster.h"

CMonster::CMonster()
{
	m_eType = OT_MONSTER;
}

CMonster::CMonster(const CMonster & monster) :
	CCharacter(monster)
{
	m_iGoldMin = monster.m_iGoldMin;
	m_iGoldMax = monster.m_iGoldMax;
}

CMonster::~CMonster()
{
}

bool CMonster::Init()
{
	return true;
}

void CMonster::Render()
{
	cout << "�̸� : " << m_strName << endl;
	cout << "���� : " << m_tInfo.iLevel << "\tȹ�� ����ġ : " << m_tInfo.iExp << endl;
	cout << "���ݷ� : " << m_tInfo.iAttackMin << " ~ " << m_tInfo.iAttackMax <<
		"\t���� : " << m_tInfo.iArmorMin << " ~ " << m_tInfo.iArmorMax << endl;
	cout << "ü�� : " << m_tInfo.iHp << " / " << m_tInfo.iHpMax << "\t���� : " << m_tInfo.iMp << " / " << m_tInfo.iMpMax << endl;
	cout << "ȹ��ݾ� : " << m_iGoldMin << " ~ " << m_iGoldMax << " Gold" << endl;
}

CMonster * CMonster::Clone()
{
	// this : �ڱ��ڽ��� �������̴�. �ڱ� �ڽ��� �����͸� �������� �ڱ� �ڽ� ��ü ��ü�� ��.
	return new CMonster(*this);
}