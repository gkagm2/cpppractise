#include "Player.h"



CPlayer::CPlayer()
{
	m_eType = OT_PLAYER;
}

CPlayer::~CPlayer()
{
}

bool CPlayer::Init()
{
	cout << "이름을 입력하세요 : ";
	char strName[32] = {};
	cin.getline(strName, 31);

	//SetName(strName);

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
		// TODO (Sagacity Jang) : Set character information
		//SetCharacterInfo();
		break;
	case JOB_ARCHER:
		m_strJobName = "궁수";

		break;
	case JOB_WIZARD:
		m_strJobName = "마법사";

		break;
	}

	return true;
}
