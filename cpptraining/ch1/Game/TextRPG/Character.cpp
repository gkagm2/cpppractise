#include "Character.h"

CCharacter::CCharacter()
{
}

// Obj의 복사생성자를 먼저 호출하여 Obj의 값을 복사하고 character의 값을 복사하도록 한다.
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