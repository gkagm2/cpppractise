#include "Player.h"

CPlayer::CPlayer()
{
	m_eType = OT_PLAYER;
}

CPlayer::CPlayer(const CPlayer & player) :
	CCharacter(player)
{
	m_eJob = player.m_eJob;
	m_strJobName = player.m_strJobName;
	m_iGold = player.m_iGold;
}

CPlayer::~CPlayer()
{
}

bool CPlayer::Init()
{
	cout << "이름을 입력하세요 : ";
	char strName[32] = {};
	cin.getline(strName, 31);

	SetName(strName);

	int iJob;

	while (true) {
		system("cls");
		cout << "1. 기사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;
		cout << "직업을 선택하세요 : ";
		iJob = Input<int>();

		if (iJob < JOB_KNIGHT || iJob >= JOB_END)
			continue;

		break;
	}

	m_eJob = (JOB)iJob;

	switch (m_eJob) {
	case JOB_KNIGHT:
		m_strJobName = "기사";
		SetCharacterInfo(10, 15, 15, 20, 500, 100, 1, 0);
		break;
	case JOB_ARCHER:
		m_strJobName = "궁수";
		SetCharacterInfo(15, 20, 10, 15, 400, 200, 1, 0);
		break;
	case JOB_WIZARD:
		m_strJobName = "마법사";
		SetCharacterInfo(15, 20, 10, 15, 200, 400, 1, 0);
		break;
	}
	m_iGold = 10000;
	return true;
}

void CPlayer::Render()
{
	system("cls");
	cout << "이름 : " << m_strName << "\t직업 : " << m_strJobName << endl;
	cout << "레벨 : " << m_tInfo.iLevel << "\t경험치 : " << m_tInfo.iExp << endl;
	cout << "공격력 : " << m_tInfo.iAttackMin << " ~ " << m_tInfo.iAttackMax <<
		"\t방어력 : " << m_tInfo.iArmorMin << " ~ " << m_tInfo.iArmorMax << endl;
	cout << "체력 : " << m_tInfo.iHp << " / " << m_tInfo.iHpMax << "\t마나 : " << m_tInfo.iMp << " / " << m_tInfo.iMpMax << endl;
	cout << "보유금액 : " << m_iGold << " Gold" << endl<< endl;
}

CPlayer * CPlayer::Clone()
{
	// this : 자기자신의 포인터이다. 자기 자신의 포인터를 역참조시 자기 자신 객체 자체가 됨.
	return new CPlayer(*this);
}
