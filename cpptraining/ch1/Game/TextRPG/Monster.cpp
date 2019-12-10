#include "Monster.h"
#include "FileStream.h"

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
	cout << "이름 : " << m_strName;
	switch (m_eStageType) {
	case ST_EASY:
		cout << "\t난이도 : Easy" << endl;
		break;
	case ST_NORMAL:
		cout << "\t난이도 : Normal" << endl;
		break;
	case ST_HARD:
		cout << "\t난이도 : Hard" << endl;
		break;
	}
	cout << "레벨 : " << m_tInfo.iLevel << "\t획득 경험치 : " << m_tInfo.iExp << endl;
	cout << "공격력 : " << m_tInfo.iAttackMin << " ~ " << m_tInfo.iAttackMax <<
		"\t방어력 : " << m_tInfo.iArmorMin << " ~ " << m_tInfo.iArmorMax << endl;
	cout << "체력 : " << m_tInfo.iHp << " / " << m_tInfo.iHpMax << "\t마나 : " << m_tInfo.iMp << " / " << m_tInfo.iMpMax << endl;
	cout << "획득금액 : " << m_iGoldMin << " ~ " << m_iGoldMax << " Gold" << endl;
}

CMonster * CMonster::Clone()
{
	// this : 자기자신의 포인터이다. 자기 자신의 포인터를 역참조시 자기 자신 객체 자체가 됨.
	return new CMonster(*this);
}

void CMonster::Save(CFileStream * pFile)
{
	CCharacter::Save(pFile);

	pFile->Write(&m_iGoldMin, 4);
	pFile->Write(&m_iGoldMax, 4);

}

void CMonster::Load(CFileStream * pFile)
{
	CCharacter::Load(pFile);

	pFile->Read(&m_iGoldMin, 4);
	pFile->Read(&m_iGoldMax, 4);
	pFile->Read(&m_eStageType, 4);
}
