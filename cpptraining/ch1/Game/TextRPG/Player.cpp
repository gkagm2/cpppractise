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
	cout << "�̸��� �Է��ϼ��� : ";
	char strName[32] = {};
	cin.getline(strName, 31);

	//SetName(strName);

	int iJob;

	while (true) {
		system("cls");
		cout << "1. ���" << endl;
		cout << "2. �ü�" << endl;
		cout << "3. ������" << endl;
		cout << "������ �����ϼ��� : ";
		iJob = Input<int>();

		if (iJob < JOB_KNIGHT || iJob >= JOB_END)
			continue;

		break;
	}

	m_eJob = (JOB)iJob;

	switch (m_eJob) {
	case JOB_KNIGHT:
		m_strJobName = "���";
		// TODO (Sagacity Jang) : Set character information
		//SetCharacterInfo();
		break;
	case JOB_ARCHER:
		m_strJobName = "�ü�";

		break;
	case JOB_WIZARD:
		m_strJobName = "������";

		break;
	}

	return true;
}
