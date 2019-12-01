#include "StoreWeapon.h"
#include "ItemWeapon.h"
#include "Player.h"
#include "ObjectManager.h"

CStoreWeapon::CStoreWeapon()
{
}


CStoreWeapon::~CStoreWeapon()
{
}

bool CStoreWeapon::Init()
{
	// �Ǹ� ����� ����� �ش�.
	CItemWeapon* pItem = (CItemWeapon*)CreateItem("���", IT_WEAPON, 1000, 500, "������ ���� ��");
	pItem->SetWeaponInfo(5, 10, 10.f);

	pItem = (CItemWeapon*)CreateItem("ö��", IT_WEAPON, 3000, 1500, "ö�� ���� ��");
	pItem->SetWeaponInfo(20, 30, 20.f);

	pItem = (CItemWeapon*)CreateItem("������ ���", IT_WEAPON, 25000, 12500, "���� ���� ���");
	pItem->SetWeaponInfo(70, 100, 35.f);

	return true;
}

void CStoreWeapon::Run()
{
	CPlayer* pPlayer = (CPlayer*)GET_SINGLE(CObjectManager)->FindObject("Player");

	while (true) {
		system("cls");
		OutputTag("Weapon Store");
		OutputItemList();
		cout << m_vecItem.size() + 1 << ". �ڷΰ���" << endl;
		cout << "�����ݾ� : " << pPlayer->GetGold() << "Gold" << endl;
	}
}
