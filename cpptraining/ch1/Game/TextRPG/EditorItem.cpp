#include "EditorItem.h"
#include "ItemWeapon.h"
#include "ItemArmor.h"
#include "FileStream.h"

DEFINITION_SINGLE(CEditorItem)

enum EDIT_ITEM_MENU {
	EIM_NONE,
	EIM_INSERT,
	EIM_MODIFY,
	EIM_DELETE,
	EIM_OUTPUT,
	EIM_SAVE,
	EIM_LOAD,
	EIM_BACK
};

CEditorItem::CEditorItem()
{
}


CEditorItem::~CEditorItem()
{
	Safe_Delete_VecList(m_vecWeapon);
	Safe_Delete_VecList(m_vecArmor);
}

bool CEditorItem::Init()
{
	return true;
}

void CEditorItem::Run()
{
	while (true) {
		switch (OutputMenu()) {
		case EIM_INSERT:
			Insert();
			break;
		case EIM_MODIFY:
			break;
		case EIM_DELETE:
			break;
		case EIM_OUTPUT:
			OutputStoreList();
			break;
		case EIM_SAVE:
			Save();
			break;
		case EIM_LOAD:
			Load();
			break;
		case EIM_BACK:
			return;
		}
	}
}

int CEditorItem::OutputMenu()
{
	system("cls");
	cout << "1. 아이템 추가" << endl;
	cout << "2. 아이템 수정" << endl;
	cout << "3. 아이템 삭제" << endl;
	cout << "4. 아이템 목록" << endl;
	cout << "5. 저장하기" << endl;
	cout << "6. 불러오기" << endl;
	cout << "7. 뒤로가기" << endl;
	cout << "메뉴를 선택하세요 : ";

	int iMenu = Input<int>();
	if (iMenu <= EIM_NONE || iMenu > EIM_BACK) {
		return EIM_NONE;
	}

	return iMenu;
}

void CEditorItem::Insert()
{
	CItem* pItem = NULL;



	int iItemType = -1;
	while (iItemType <= IT_WEAPON || iItemType > IT_MAX) {
		system("cls");
		cout << "============ 아이템 추가 ==========" << endl;
		cout << "1. 무기" << endl;
		cout << "2. 방어구" << endl;
		cout << "아이템 종류를 선택하세요 : ";
		iItemType = Input<int>();
	}
	--iItemType;

	switch (iItemType) {
	case IT_WEAPON:
		pItem = new CItemWeapon;
		break;
	case IT_ARMOR:
		pItem = new CItemArmor;
		break;
	}

	switch (iItemType) {
	case IT_WEAPON:
		cout << "무기 ";
		break;
	case IT_ARMOR:
		cout << "방어구 ";
		break;
	}
	cout << "이름 : ";
	cin.ignore(1024, '\n');
	char strName[256] = {};
	cin.getline(strName, 255);

	pItem->SetName(strName);

	int iPrice, iSell;
	
	

	cout << "Price : ";
	iPrice = Input<int>();
	cout << "Sell : ";
	iSell = Input<int>();

	switch (iItemType) {
	case IT_WEAPON:
	{
		int iAttackMin, iAttackMax;
		cout << "최소 공격력 : ";
		iAttackMin = Input<int>();
		cout << "최대 공격력 : ";
		iAttackMax = Input<int>();

		float fCritical;
		cout << "치명타 확률 : ";
		fCritical = Input<float>();
		((CItemWeapon*)pItem)->SetWeaponInfo(iAttackMin, iAttackMax, fCritical);
	}
	break;
	case IT_ARMOR:
	{
		int iArmorMin, iArmorMax;
		cout << "최소 방어력 : ";
		iArmorMin = Input<int>();
		cout << "최대 방어력 : ";
		iArmorMax = Input<int>();
		((CItemArmor*)pItem)->SetArmorInfo(iArmorMin, iArmorMax);
	}
		break;
	}

	char strDesc[256] = {};

	cin.ignore(1024, '\n');
	cout << "아이템 설명 : ";
	cin.getline(strDesc, 255);
	/*ITEM_TYPE eItemType;
	cout << "아이템 타입 : ";*/
	pItem->SetItemInfo((ITEM_TYPE)(iItemType), iPrice, iSell, strDesc);

	switch (iItemType) {
	case IT_WEAPON:
		m_vecWeapon.push_back(pItem);
		break;
	case IT_ARMOR:
		m_vecArmor.push_back(pItem);
		break;
	}
}

void CEditorItem::OutputStoreList()
{
	system("cls");
	cout << "============== 무기 상점 ===============" << endl;
	for (size_t i = 0; i < m_vecWeapon.size(); ++i) {
		cout << i + 1 << ". ";
		m_vecWeapon[i]->Render();
		cout << endl;
	}

	cout << "============== 방어구 상점 ===============" << endl;
	for (size_t i = 0; i < m_vecArmor.size(); ++i) {
		cout << i + 1 << ". ";
		m_vecArmor[i]->Render();
		cout << endl;
	}

	system("pause");
}

void CEditorItem::Save()
{
	CFileStream file(g_strWeaponStoreItemListFileName.c_str(), "wb");

	// 무기 상점

	if (file.GetOpen()) {
		// 무기 수를 저장한다.
		size_t iCount = m_vecWeapon.size();

		file.Write(&iCount, 4);

		for (size_t i = 0; i < iCount; ++i) {
			m_vecWeapon[i]->Save(&file);
		}

		file.Close();
	}

	// 방어구 상점

	if (file.Open(g_strArmorStoreItemListFileName.c_str(), "wb")) {
		// 방어구 수를 저장한다.
		size_t iCount = m_vecArmor.size();

		file.Write(&iCount, 4);

		for (size_t i = 0; i < iCount; ++i) {
			m_vecArmor[i]->Save(&file);
		}

		file.Close();
	}

	cout << "상점 목록 저장 완료" << endl;
	system("puase");
}

void CEditorItem::Load()
{
	Safe_Delete_VecList(m_vecWeapon);
	Safe_Delete_VecList(m_vecArmor);

	CFileStream file(g_strWeaponStoreItemListFileName.c_str(), "rb");

	// 무기 상점

	if (file.GetOpen()) {
		// 무기 수를 불러온다.
		size_t iCount = 0;

		file.Read(&iCount, 4);

		for (size_t i = 0; i < iCount; ++i) {
			CItem* pItem = new CItemWeapon;
			if (!pItem->Init()) {
				SAFE_DELETE(pItem);
				return;
			}

			pItem->Load(&file);

			m_vecWeapon.push_back(pItem);
		}

		file.Close();
	}

	// 방어구 상점

	if (file.Open(g_strArmorStoreItemListFileName.c_str(), "rb")) {
		// 방어구 수를 불러온다.
		size_t iCount = 0;

		file.Read(&iCount, 4);

		for (size_t i = 0; i < iCount; ++i) {
			CItem* pItem = new CItemArmor;
			if (!pItem->Init()) {
				SAFE_DELETE(pItem);
				return;
			}

			pItem->Load(&file);

			m_vecArmor.push_back(pItem);
		}

		file.Close();
	}

	cout << "상점 목록 저장 완료" << endl;
	system("puase");
}
