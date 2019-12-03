#include "Core.h"
#include "ObjectManager.h"
#include "ObjectManager.h"
#include "StoreManager.h"
#include "Inventory.h"

DEFINITION_SINGLE(CCore)

enum MAIN_MENU {
	MM_NONE,
	MM_STAGE,
	MM_STORE,
	MM_INVENTORY,
	MM_STATUS,
	MM_EXIT
};
CCore::CCore() {
}

CCore::~CCore() {
	DESTROY_SINGLE(CInventory);
	DESTROY_SINGLE(CStoreManager);
	DESTROY_SINGLE(CObjectManager);
	DESTROY_SINGLE(CStageManager);
	
}

bool CCore::Init()
{
	// 오브젝트 관리자 초기화.
	if (!GET_SINGLE(CObjectManager)->Init())
		return false;

	// Stage를 초기화한다.
	if (!GET_SINGLE(CStageManager)->Init())
		return false;

	// 상점 관리자를 초기화한다.
	if (!GET_SINGLE(CStoreManager)->Init()) {
		return false;
	}

	// 인벤토리를 초기화한다.
	if (!GET_SINGLE(CInventory)->Init()) {
		return false;
	}

	return true;
}

void CCore::Run()
{
	while (true) {
		switch (OutputMenu()) {
		case MM_STAGE:
			GET_SINGLE(CStageManager)->Run();
			break;
		case MM_STORE:
			GET_SINGLE(CStoreManager)->Run();
			break;
		case MM_INVENTORY:
			GET_SINGLE(CInventory)->Run();
			break;
		case MM_STATUS:
			break;
		case MM_EXIT:
			return;
		}
	}
}

int CCore::OutputMenu()
{
	system("cls");
	cout << "1. 맵" << endl;
	cout << "2. 상점" << endl;
	cout << "3. 인벤토리" << endl;
	cout << "4. 캐릭터 정보" << endl;
	cout << "5. 종료" << endl;
	cout << "메뉴를 선택하세요 : ";
	int iMenu = Input<int>();

	if (iMenu <= MM_NONE || iMenu > MM_EXIT) {
		return MM_NONE;
	}

	return iMenu;
}
