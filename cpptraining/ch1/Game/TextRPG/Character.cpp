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

bool CCharacter::Damage(int iDamage)
{
	m_tInfo.iHp -= iDamage;
	
	return m_tInfo.iHp <= 0; // 죽으면 true 리턴
}

bool CCharacter::AddExp(int iExp)
{
	m_tInfo.iExp += iExp;
	
	// false 리턴 시에는 레벨업이 아니다.
	return false;
}

bool CCharacter::CheckLevelUp()
{
	if (g_iLvUpTable[m_tInfo.iLevel - 1] <= m_tInfo.iExp) {
		return true;
	}

	return false;
}

void CCharacter::DropExp()
{
	m_tInfo.iExp *= 0.9f; // 10% drop
}

void CCharacter::FullHPMP()
{
	m_tInfo.iMp = m_tInfo.iMpMax;
	m_tInfo.iHp = m_tInfo.iHpMax;
}

void CCharacter::LevelUp()
{
	m_tInfo.iExp -= g_iLvUpTable[m_tInfo.iLevel - 1];
	++m_tInfo.iLevel;
}

void CCharacter::AddLevelUpStatus(const LEVELUPINFO & tInfo)
{
	m_tInfo.iAttackMin += tInfo.iAttackMin;
	m_tInfo.iAttackMax += tInfo.iAttackMax;
	m_tInfo.iArmorMin += tInfo.iArmorMin;
	m_tInfo.iArmorMax += tInfo.iArmorMax;
	m_tInfo.iHpMax += tInfo.iHp;
	m_tInfo.iHp = m_tInfo.iHpMax;
	m_tInfo.iMpMax += tInfo.iMp;
	m_tInfo.iMp = m_tInfo.iMpMax;
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