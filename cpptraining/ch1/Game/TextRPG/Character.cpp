#include "Character.h"

CCharacter::CCharacter()
{
}

// Obj�� ��������ڸ� ���� ȣ���Ͽ� Obj�� ���� �����ϰ� character�� ���� �����ϵ��� �Ѵ�.
CCharacter::CCharacter(const CCharacter & character) :
	CObj(character)
{
	m_tInfo = character.m_tInfo;
}

CCharacter::~CCharacter()
{
}

bool CCharacter::Init()
{
	return true;
}

void CCharacter::Render()
{
}

CCharacter * CCharacter::Clone()
{
	return nullptr;
}

void CCharacter::SetCharacterInfo(int iAttackMin, int iAttackMax, int iArmorMin, int iArmorMax, int iHp, int iMp, int iLevel, int iExp)
{
	m_tInfo.iAttackMin = iAttackMin;
	m_tInfo.iAttackMax = iAttackMax;
	m_tInfo.iArmorMin = iArmorMin;
	m_tInfo.iArmorMax = iArmorMax;
	m_tInfo.iHpMax = m_tInfo.iHp = iHp;
	m_tInfo.iMpMax = m_tInfo.iMp = iMp;
	m_tInfo.iLevel = iLevel;
	m_tInfo.iExp = iExp;
}