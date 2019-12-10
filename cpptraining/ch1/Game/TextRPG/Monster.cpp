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
	cout << "�̸� : " << m_strName;
	switch (m_eStageType) {
	case ST_EASY:
		cout << "\t���̵� : Easy" << endl;
		break;
	case ST_NORMAL:
		cout << "\t���̵� : Normal" << endl;
		break;
	case ST_HARD:
		cout << "\t���̵� : Hard" << endl;
		break;
	}
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
