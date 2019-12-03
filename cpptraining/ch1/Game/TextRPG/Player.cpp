#include "Player.h"
#include "ItemWeapon.h"
#include "ItemArmor.h"

CPlayer::CPlayer()
{
	m_eType = OT_PLAYER;
	// 포인터 변수 배열 2개짜리를 0으로 초기화한다. EQ_END가 2이므로
	// 포인터 변수 크기 4*2가 되어 8바이트를 0으로 초기화한다.
	// 포인터 변수 2개를 NULL 포인터로 초기화 하는것이다.
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
	// 장착하고자 하는 아이템의 타입에 따라 장착 부위가 달라져야 한다.
	EQUIP eq;
	
	switch (pItem->GetItemInfo().eType) {
	case IT_WEAPON:
		eq = EQ_WEAPON;
		break;
	case IT_ARMOR:
		eq = EQ_ARMOR;
		break;
	}

	// 착용하고 있는 아이템이 있을 경우 착용하고 있던 아이템을 반환
	if (m_pEquip[eq]) {
		CItem* pEquip = m_pEquip[eq];
		m_pEquip[eq] = pItem;

		// 착용하고 있던 아이템을 반환.
		return pEquip;
	}

	m_pEquip[eq] = pItem;

	return NULL;
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
	cout << "공격력 : ";
	if (m_pEquip[EQ_WEAPON]) { // 무기를 장착 하고 있을 때
		cout << m_tInfo.iAttackMin << " + " << ((CItemWeapon*)m_pEquip[EQ_WEAPON])->GetAttackMin() <<
			" - " << m_tInfo.iAttackMax << " + " << ((CItemWeapon*)m_pEquip[EQ_WEAPON])->GetAttackMax();
	}
	else { // 무기를 장착하지 않고 있을 때
		cout << m_tInfo.iAttackMin << " ~ " << m_tInfo.iAttackMax;
	}

	cout << "\t방어력 : ";
	if (m_pEquip[EQ_ARMOR]) { // 방어구를 장착 하고 있을 때
		cout << m_tInfo.iArmorMin << " + " << ((CItemArmor*)m_pEquip[EQ_ARMOR])->GetArmorMin() <<
			" - " << m_tInfo.iArmorMax << " + " << ((CItemArmor*)m_pEquip[EQ_ARMOR])->GetArmorMax();
	}
	else { // 방어구를 장착하지 않고 있을 때
		cout << m_tInfo.iArmorMin << " ~ " << m_tInfo.iArmorMax;
	}
	cout << endl;
	cout << "체력 : " << m_tInfo.iHp << " / " << m_tInfo.iHpMax << "\t마나 : " << m_tInfo.iMp << " / " << m_tInfo.iMpMax << endl;
	cout << "보유금액 : " << m_iGold << " Gold" << endl<< endl;

	cout << "장착무기 : ";
	if (m_pEquip[EQ_WEAPON]) {
		cout << m_pEquip[EQ_WEAPON]->GetName();
	}
	else {
		cout << "없음";
	}
	cout << "\t 장착방어구 : ";
	if (m_pEquip[EQ_ARMOR]) {
		cout << m_pEquip[EQ_ARMOR]->GetName() << endl;
	}
	else {
		cout << "없음";
	}
	cout << endl;
}

CPlayer * CPlayer::Clone()
{
	// this : 자기자신의 포인터이다. 자기 자신의 포인터를 역참조시 자기 자신 객체 자체가 됨.
	return new CPlayer(*this);
}
