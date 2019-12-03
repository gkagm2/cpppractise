#include "Player.h"
#include "ItemWeapon.h"
#include "ItemArmor.h"

CPlayer::CPlayer()
{
	m_eType = OT_PLAYER;
	// ������ ���� �迭 2��¥���� 0���� �ʱ�ȭ�Ѵ�. EQ_END�� 2�̹Ƿ�
	// ������ ���� ũ�� 4*2�� �Ǿ� 8����Ʈ�� 0���� �ʱ�ȭ�Ѵ�.
	// ������ ���� 2���� NULL �����ͷ� �ʱ�ȭ �ϴ°��̴�.
	memset(m_pEquip, 0, sizeof(CItem*) * EQ_END);
}

CPlayer::CPlayer(const CPlayer & player) :
	CCharacter(player)
{
	m_eJob = player.m_eJob;
	m_strJobName = player.m_strJobName;
	m_iGold = player.m_iGold;
	memset(m_pEquip, 0, sizeof(CItem*) * EQ_END);
}

CPlayer::~CPlayer()
{
	for (int i = 0; i < EQ_END; ++i) {
		SAFE_DELETE(m_pEquip[i]);
	}
}

void CPlayer::AddGold(int iGold)
{
	m_iGold += iGold;
}

void CPlayer::UseGold(int iGold)
{
	m_iGold -= iGold;
}

void CPlayer::DropGold()
{
	m_iGold *= 0.9f; // 10% drop
}

CItem* CPlayer::Equip(CItem * pItem)
{
	// �����ϰ��� �ϴ� �������� Ÿ�Կ� ���� ���� ������ �޶����� �Ѵ�.
	EQUIP eq;
	
	switch (pItem->GetItemInfo().eType) {
	case IT_WEAPON:
		eq = EQ_WEAPON;
		break;
	case IT_ARMOR:
		eq = EQ_ARMOR;
		break;
	}

	// �����ϰ� �ִ� �������� ���� ��� �����ϰ� �ִ� �������� ��ȯ
	if (m_pEquip[eq]) {
		CItem* pEquip = m_pEquip[eq];
		m_pEquip[eq] = pItem;

		// �����ϰ� �ִ� �������� ��ȯ.
		return pEquip;
	}

	m_pEquip[eq] = pItem;

	return NULL;
}

bool CPlayer::Init()
{
	cout << "�̸��� �Է��ϼ��� : ";
	char strName[32] = {};
	cin.getline(strName, 31);

	SetName(strName);

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
		SetCharacterInfo(10, 15, 15, 20, 500, 100, 1, 0);
		break;
	case JOB_ARCHER:
		m_strJobName = "�ü�";
		SetCharacterInfo(15, 20, 10, 15, 400, 200, 1, 0);
		break;
	case JOB_WIZARD:
		m_strJobName = "������";
		SetCharacterInfo(15, 20, 10, 15, 200, 400, 1, 0);
		break;
	}
	m_iGold = 10000;
	return true;
}

void CPlayer::Render()
{
	system("cls");
	cout << "�̸� : " << m_strName << "\t���� : " << m_strJobName << endl;
	cout << "���� : " << m_tInfo.iLevel << "\t����ġ : " << m_tInfo.iExp << endl;
	cout << "���ݷ� : ";
	if (m_pEquip[EQ_WEAPON]) { // ���⸦ ���� �ϰ� ���� ��
		cout << m_tInfo.iAttackMin << " + " << ((CItemWeapon*)m_pEquip[EQ_WEAPON])->GetAttackMin() <<
			" - " << m_tInfo.iAttackMax << " + " << ((CItemWeapon*)m_pEquip[EQ_WEAPON])->GetAttackMax();
	}
	else { // ���⸦ �������� �ʰ� ���� ��
		cout << m_tInfo.iAttackMin << " ~ " << m_tInfo.iAttackMax;
	}

	cout << "\t���� : ";
	if (m_pEquip[EQ_ARMOR]) { // ���� ���� �ϰ� ���� ��
		cout << m_tInfo.iArmorMin << " + " << ((CItemArmor*)m_pEquip[EQ_ARMOR])->GetArmorMin() <<
			" - " << m_tInfo.iArmorMax << " + " << ((CItemArmor*)m_pEquip[EQ_ARMOR])->GetArmorMax();
	}
	else { // ���� �������� �ʰ� ���� ��
		cout << m_tInfo.iArmorMin << " ~ " << m_tInfo.iArmorMax;
	}
	cout << endl;
	cout << "ü�� : " << m_tInfo.iHp << " / " << m_tInfo.iHpMax << "\t���� : " << m_tInfo.iMp << " / " << m_tInfo.iMpMax << endl;
	cout << "�����ݾ� : " << m_iGold << " Gold" << endl<< endl;

	cout << "�������� : ";
	if (m_pEquip[EQ_WEAPON]) {
		cout << m_pEquip[EQ_WEAPON]->GetName();
	}
	else {
		cout << "����";
	}
	cout << "\t ������ : ";
	if (m_pEquip[EQ_ARMOR]) {
		cout << m_pEquip[EQ_ARMOR]->GetName() << endl;
	}
	else {
		cout << "����";
	}
	cout << endl;
}

CPlayer * CPlayer::Clone()
{
	// this : �ڱ��ڽ��� �������̴�. �ڱ� �ڽ��� �����͸� �������� �ڱ� �ڽ� ��ü ��ü�� ��.
	return new CPlayer(*this);
}
