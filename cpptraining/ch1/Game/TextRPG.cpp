// PROGRAM : 텍스트 RPG
// DEVELOPER : Sagacity Jang
// DATE : 2019.11.01 ~ 2019.11.2

#include <iostream>
#include <time.h>

using namespace std;

enum GAME_MODE {
	GM_NONE,
	GM_NEW,
	GM_LOAD,
	GM_END
};

enum MAIN_MENU {
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

enum MAT_TYPE {
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};

enum JOB {
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};

enum BATTLE {
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK
};

enum ITEM_TYPE {
	IT_NONE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK
};

enum STORE_MENU {
	SM_NONE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK
};

enum EQUIP {
	EQ_WEAPON,
	EQ_ARMOR,
	EQ_MAX
};

#define NAME_SIZE 32
#define ITEM_DECS_LENGTH 512
#define INVENTORY_MAX 20
#define STORE_WEAPON_MAX 3
#define STORE_ARMOR_MAX 3
#define LEVEL_MAX 10
struct _tagItem {
	char strName[NAME_SIZE];
	char strTypeName[NAME_SIZE];
	ITEM_TYPE eType;
	int iMin;
	int iMax;
	int iPrice;
	int iSell;
	char strDesc[ITEM_DECS_LENGTH];
};

struct _tagInventory {
	_tagItem tItem[INVENTORY_MAX];
	int iItemCount;
	int iGold;
};

struct _tagPlayer {
	char strName[NAME_SIZE];
	char strJobName[NAME_SIZE];
	JOB eJob;
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iExp;
	int iLevel;
	_tagItem tEquip[EQ_MAX];
	bool bEquip[EQ_MAX];
	_tagInventory tInventory;
};

struct _tagMonster {
	char strName[NAME_SIZE];
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iLevel;
	int iExp;
	int iGoldMin;
	int iGoldMax;
};

int InputInt() {
	int iInput;
	cin >> iInput;

	if (cin.fail()) {
		cin.clear(0);
		cin.ignore(1024, '\n');
		return INT_MAX;
	}
	return iInput;
}

void InputString(char* pString, int iSize) {
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSize - 1);
}

// bool을 이용해서파일이 제대로 만들어졌는지 판단한다.
bool SavePlayer(_tagPlayer* pPlayer) {
	FILE* pFile = NULL;
	fopen_s(&pFile, "Player.ply", "wb");

	if (pFile) {
		// 플레이어 이름을 저장한다.
		fwrite(pPlayer->strName, sizeof(char), NAME_SIZE, pFile);
		// 직업 정보를 저장한다.
		fwrite(&pPlayer->eJob, sizeof(JOB), 1, pFile); // 열거체는 무조건 4byte로 처리된다. 배열이 아니므로 1개
		fwrite(pPlayer->strJobName, 1, NAME_SIZE, pFile);

		// 공격력을 저장한다.
		fwrite(&pPlayer->iAttackMin, sizeof(int), 1, pFile);
		fwrite(&pPlayer->iAttackMax, sizeof(int), 1, pFile);

		// 방어력을 저장한다.
		fwrite(&pPlayer->iArmorMin, sizeof(int), 1, pFile);
		fwrite(&pPlayer->iArmorMax, sizeof(int), 1, pFile);

		// 체력을 저장한다.
		fwrite(&pPlayer->iHP, sizeof(int), 1, pFile);
		fwrite(&pPlayer->iHPMax, sizeof(int), 1, pFile);

		// 마나를 저장한다.
		fwrite(&pPlayer->iMP, sizeof(int), 1, pFile);
		fwrite(&pPlayer->iMPMax, sizeof(int), 1, pFile);

		// 레벨과 경험치를 저장한다.
		fwrite(&pPlayer->iLevel, sizeof(int), 1, pFile);
		fwrite(&pPlayer->iExp, sizeof(int), 1, pFile);


		// 무기 아이템 착용여부를 저장한다.
		fwrite(&pPlayer->bEquip[EQ_WEAPON], 1, 1, pFile);

		// 만약 저정할때 무기를 차고 있었다면 해당 무기정보도 같이 저장이 되었다.
		// 그러므로 여기서 차고 있을 경우 읽어야 한다.
		if (pPlayer->bEquip[EQ_WEAPON]) {
			fwrite(&pPlayer->tEquip[EQ_WEAPON], sizeof(_tagItem), 1, pFile);
		}
		// 방어구 아이템 착용여부를 저장한다.
		if (pPlayer->bEquip[EQ_ARMOR]) {
			fwrite(&pPlayer->tEquip[EQ_ARMOR], sizeof(_tagItem), 1, pFile);
		}

		/*
		int iGoldMin;
		int iGoldMax;*/

		// 골드를 저장한다.
		fwrite(&pPlayer->tInventory.iGold, sizeof(int), 1, pFile);

		// 인벤토리 아이템 수를 저장한다.
		fwrite(&pPlayer->tInventory.iItemCount, sizeof(int), 1, pFile);

		// 아이템 수만큼 인벤토리에 아이템정보를 저장한다.
		fwrite(pPlayer->tInventory.tItem, sizeof(_tagItem), pPlayer->tInventory.iItemCount, pFile);

		fclose(pFile);
		return true;
	}
	return false;
}

//_tagMonster CreateMonster(_tagMonster monster) {
//
//}

void SetPlayer(_tagPlayer* pPlayer) {
	system("cls");
	// 플레이어 이름을 입력받는다.
	cout << "이름 : ";
	InputString(pPlayer->strName, NAME_SIZE);
	cout << pPlayer->strName << "을 입력하였습니다." << endl;

	int iJob = JOB_NONE;
	while (iJob == JOB_NONE) {
		system("cls");
		cout << "========================= 로비 ===========================" << endl;
		cout << "1. 기사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;
		cout << "직업을 선택하세요 : ";
		iJob = InputInt();
		if (iJob == INT_MAX) {
			continue;
		}
		else if (iJob <= JOB_NONE || iJob >= JOB_END) {
			iJob = JOB_NONE;
		}
	}

	// 플레이어의 정보를 정의하기
	pPlayer->iLevel = 1;
	pPlayer->iExp = 0;
	pPlayer->eJob = (JOB)iJob;
	pPlayer->tInventory.iGold = 100000;

	switch (pPlayer->eJob) {
	case JOB_KNIGHT:
		strcpy_s(pPlayer->strJobName, "기사");
		pPlayer->iAttackMin = 5;
		pPlayer->iAttackMax = 10;
		pPlayer->iArmorMin = 15;
		pPlayer->iArmorMax = 20;
		pPlayer->iHPMax = 500;
		pPlayer->iHP = 500;
		pPlayer->iMP = 100;
		pPlayer->iMPMax = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(pPlayer->strJobName, "궁수");
		pPlayer->iAttackMin = 10;
		pPlayer->iAttackMax = 15;
		pPlayer->iArmorMin = 10;
		pPlayer->iArmorMax = 15;
		pPlayer->iHPMax = 400;
		pPlayer->iHP = 400;
		pPlayer->iMP = 200;
		pPlayer->iMPMax = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(pPlayer->strJobName, "마법사");
		pPlayer->iAttackMin = 15;
		pPlayer->iAttackMax = 20;
		pPlayer->iArmorMin = 5;
		pPlayer->iArmorMax = 10;
		pPlayer->iHPMax = 300;
		pPlayer->iHP = 300;
		pPlayer->iMP = 300;
		pPlayer->iMPMax = 300;
		break;
	}
}

bool LoadPlayer(_tagPlayer* pPlayer) {
	FILE* pFile = NULL;

	fopen_s(&pFile, "Player.ply", "rb");

	if (pFile) {

		// 플레이어 이름을 불러온다.
		fread(pPlayer->strName, sizeof(char), NAME_SIZE, pFile);
		// 직업 정보를 읽어온다.
		fread(&pPlayer->eJob, sizeof(JOB), 1, pFile); // 열거체는 무조건 4byte로 처리된다. 배열이 아니므로 1개
		fread(pPlayer->strJobName, 1, NAME_SIZE, pFile);

		// 공격력을 읽어온다.
		fread(&pPlayer->iAttackMin, sizeof(int), 1, pFile);
		fread(&pPlayer->iAttackMax, sizeof(int), 1, pFile);

		// 방어력을 읽어온다.
		fread(&pPlayer->iArmorMin, sizeof(int), 1, pFile);
		fread(&pPlayer->iArmorMax, sizeof(int), 1, pFile);

		// 체력을 읽어온다.
		fread(&pPlayer->iHP, sizeof(int), 1, pFile);
		fread(&pPlayer->iHPMax, sizeof(int), 1, pFile);
		
		// 마나를 읽어온다.
		fread(&pPlayer->iMP, sizeof(int), 1, pFile);
		fread(&pPlayer->iMPMax, sizeof(int), 1, pFile);
		
		// 레벨과 경험치를 읽어온다.
		fread(&pPlayer->iLevel, sizeof(int), 1, pFile);
		fread(&pPlayer->iExp, sizeof(int), 1, pFile);
		

		// 무기 아이템 착용여부를 읽어온다.
		fread(&pPlayer->bEquip[EQ_WEAPON], 1, 1, pFile);
		
		// 만약 저정할때 무기를 차고 있었다면 해당 무기정보도 같이 저장이 되었다.
		// 그러므로 여기서 차고 있을 경우 읽어야 한다.
		if (pPlayer->bEquip[EQ_WEAPON]) {
			fread(&pPlayer->tEquip[EQ_WEAPON], sizeof(_tagItem), 1, pFile);
		}
		// 방어구 아이템 착용여부를 읽어온다.
		if (pPlayer->bEquip[EQ_ARMOR]) {
			fread(&pPlayer->tEquip[EQ_ARMOR], sizeof(_tagItem), 1, pFile);
		}

		/*
		int iGoldMin;
		int iGoldMax;*/

		// 골드를 읽어온다.
		fread(&pPlayer->tInventory.iGold, sizeof(int), 1, pFile);

		// 인벤토리 아이템 수를 읽어온다.
		fread(&pPlayer->tInventory.iItemCount, sizeof(int), 1, pFile);

		// 읽어온 아이템 수만큼 인벤토리에 아이템정보를 읽어온다.
		fread(pPlayer->tInventory.tItem, sizeof(_tagItem), pPlayer->tInventory.iItemCount, pFile);

		fclose(pFile);
		return true;
	}
	return false;
}

// 몬스터 정보를 출력한다.
void OutputMonster(_tagMonster* pMonster) {
	cout << "=========================== Monster ===================" << endl;
	cout << "이름 : " << pMonster->strName << "\t레벨 : " << pMonster->iLevel << endl;
	cout << "공격력 : " << pMonster->iAttackMin << " - " << pMonster->iAttackMax <<
		"\t방어력 : " << pMonster->iArmorMin << " - " << pMonster->iArmorMax << endl;
	cout << "체력 : " << pMonster->iHP << " / " << pMonster->iHPMax <<
		"\t마나 : " << pMonster->iMP << " / /" << pMonster->iMPMax << endl;
	cout << "획득경험치 : " << pMonster->iExp << "\t획득골드" << pMonster->iGoldMin << " - " << pMonster->iGoldMax << endl;
}

// 플레이어 정보를 출력한다.
void OutputPlayer(_tagPlayer* pPlayer) {
	cout << "=========================== Player ===================" << endl;
	cout << "이름 : " << pPlayer->strName << "\t직업 : " << pPlayer->strJobName << endl;
	cout << "레벨 : " << pPlayer->iLevel << "\t경험치 : " << pPlayer->iExp << endl;
	cout << "공격력 : " << pPlayer->iAttackMin << " - " << pPlayer->iAttackMax <<
		"\t방어력 : " << pPlayer->iArmorMin << " - " << pPlayer->iArmorMax << endl;
	cout << "체력 : " << pPlayer->iHP << " / " << pPlayer->iHPMax <<
		"\t마나 : " << pPlayer->iMP << " / /" << pPlayer->iMPMax << endl;
	cout << "보유골드 : " << pPlayer->tInventory.iGold << " 골드" << endl;
}

_tagMonster CreateMonster(const char *strName, int iAttackMin, int iAttackMax, int iArmorMin,
	int iArmorMax, int iHP, int iMP, int iLevel, int iExp, int iGoldMin,int iGoldMax) {
	_tagMonster tMonster;
	strcpy_s(tMonster.strName, strName);
	tMonster.iAttackMin = iAttackMin;
	tMonster.iAttackMax = iAttackMax;
	tMonster.iArmorMin = iArmorMin;
	tMonster.iArmorMax = iArmorMax;
	tMonster.iHP = tMonster.iHPMax = iHP;
	tMonster.iMP = tMonster.iMPMax = iMP;
	tMonster.iLevel = iLevel;
	tMonster.iExp = iExp;
	tMonster.iGoldMin = iGoldMin;
	tMonster.iGoldMax = iGoldMax;

	return tMonster;
}

void SetMonster(_tagMonster* pMonsterArr) {
	
	FILE* pFile = NULL;

	fopen_s(&pFile, "Monster.mst", "rb");

	if (pFile) {
		fread(pMonsterArr, sizeof(_tagMonster), MT_BACK-1, pFile);
		fclose(pFile);
	}

	/*pMonsterArr[0] = CreateMonster("고블린", 20, 30, 2, 5, 100, 10, 1, 1000, 500, 1500);
	pMonsterArr[1] = CreateMonster("트롤", 80, 130, 60, 90, 2000, 100, 5, 7000, 6000, 8000);
	pMonsterArr[2] = CreateMonster("드래곤", 250, 500, 200, 400, 30000, 20000, 10, 30000, 20000, 50000);*/
}

_tagItem CreateItem(const char* strName, ITEM_TYPE eItemType, int iMin, int iMax, int iPrice, int iSell, const char* strDesc) {
	_tagItem tItem;
	strcpy_s(tItem.strName, strName);
	if (eItemType == IT_WEAPON) {
		strcpy_s(tItem.strTypeName, "무기");
	}
	else if (eItemType == IT_ARMOR) {
		strcpy_s(tItem.strTypeName, "방어구");
	}
	tItem.eType = eItemType;
	tItem.iMin = iMin;
	tItem.iMax = iMax;
	tItem.iPrice = iPrice;
	tItem.iSell = iSell;
	strcpy_s(tItem.strDesc, strDesc);

	return tItem;
}

int OutputStoreItemList(_tagInventory* pInventory, _tagItem* pStore, int iItemCount) {
	// 판매 목록을 보여준다.
	for (int i = 0; i < iItemCount; ++i) {
		cout << i + 1 << ". 이름 : " << pStore[i].strName << "\t종류 : " << pStore[i].strTypeName << endl;
		cout << "공/방어력 : " << pStore[i].iMin << " - " << pStore[i].iMax << endl;
		cout << "판매가격 : " << pStore[i].iPrice << "\t구매가격 : " << pStore[i].iSell << endl;
		cout << "설명 : " << pStore[i].strDesc << endl;
		cout << endl;

		cout << endl;
		cout << iItemCount + 1 << ". 뒤로가기" << endl;
		cout << "보유금액 : " << pInventory->iGold << " Gold" << endl;
		cout << "남은공간 : " << INVENTORY_MAX - pInventory->iItemCount << endl;
		cout << "구입할 아이템을 선택하세요 : ";
	}

	int iMenu = InputInt();
	if (iMenu < 1 || iMenu > iItemCount + 1) {
		return INT_MAX;
	}
	return iMenu;
}


int main() {

	srand((unsigned int)time(0));

	// 레벨업에 필요한 경험치 목록을 만든다.
	const int iLevelUpExp[LEVEL_MAX] = { 2000,4000,10000,30000,50000,70000,100000,150000,200000,400000 };

	// 게임을 시작할때 플레이어 정보를 설정하게 한다.
	_tagPlayer tPlayer = {};


	int iGameMode = 0;
	while (iGameMode <= GM_NONE || iGameMode > GM_LOAD) {
		system("cls");
		cout << "1. 새로하기" << endl;
		cout << "2. 이어하기" << endl;
		cout << "3. 종료" << endl;
		cout << "게임모드를 선택하세요 : ";
		iGameMode = InputInt();
	}
	
	if (iGameMode == GM_END) {
		return 0;
	}
	switch (iGameMode) {
	case GM_NEW:
		SetPlayer(&tPlayer);
		break;
	case GM_LOAD:
		if (!LoadPlayer(&tPlayer)) {
			cout << "플레이어 파일 오류!!" << endl;
			return 0;
		}
		break;
	}


	// 몬스터를 생성한다.
	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	for (int i = 0; i < 3; i++) {
		SetMonster(&tMonsterArr[i]); // 몬스터 초기화
	}
	


	// 상점에서 판매할 아이템 목록을 생성한다.
	_tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem tStoreArmor[STORE_ARMOR_MAX] = {};


	// 무기 아이템 정보 설정
	tStoreWeapon[0] = CreateItem("목검", IT_WEAPON, 5, 10, 1000, 500, "나무로 만든 칼");
	tStoreWeapon[1] = CreateItem("장궁", IT_WEAPON, 20, 40, 7000, 3500, "짱짱한 활");
	tStoreWeapon[2] = CreateItem("지팡이", IT_WEAPON, 90, 150, 30000, 15000, "나무로 만든 지팡이");

	// 방어구 아이템 정보 설정
	tStoreArmor[0] = CreateItem("천갑옷", IT_ARMOR, 2, 5, 1000, 500, "천으로 만든 허접한 갑옷");
	tStoreArmor[1] = CreateItem("가죽갑옷", IT_ARMOR, 10, 20, 7000, 3500, "동물 가죽으로 만든 질긴 갑옷");
	tStoreArmor[2] = CreateItem("풀플레이트아머", IT_ARMOR, 70, 90, 30000, 15000, "강철로 만든 판금갑옷");

	while (true) {
		system("cls");
		cout << "===================== 로비 ==================" << endl;
		cout << "1. 맵" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 가방" << endl;
		cout << "4. 종료 " << endl;
		cout << "메뉴를 선택하세요 : ";

		int iMenu;
		
		cin >> iMenu;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MM_EXIT) {
			break;
		}

		switch (iMenu) {
		case MM_MAP:
			while (true) {
				system("cls");
				cout << "===================== 맵 ==================" << endl;
				cout << "1. 쉬움" << endl;
				cout << "2. 보통" << endl;
				cout << "3. 어려움" << endl;
				cout << "4. 뒤로가기" << endl;

				iMenu = InputInt();
				if (iMenu == INT_MAX) {
					continue;
				}

				// 이 if문에 속한 break는 맵 메뉴를 돌려주기 위한 while에 속해 있으므로 이 while을 빠져나간다.
				if (iMenu == MT_BACK) {
					break;
				}

				// 선택한 메뉴에서 1을 빼주면 몬스터 배열의 인덱스가 된다.
				// 그렇게 해서 해당 맵의 몬스터를 생성해준다.
				_tagMonster tMonster = tMonsterArr[iMenu - 1];

				while (true) {
					system("cls");
					switch (iMenu) {
					case MT_EASY:
						cout << "===================== 쉬움 ==================" << endl;
						break;
					case MT_NORMAL:
						cout << "===================== 보통 ==================" << endl;
						break;
					case MT_HARD:
						cout << "===================== 어려움 ==================" << endl;
						break;
					}

					OutputPlayer(&tPlayer);   // 플레이어 정보 출력
					cout << "!!! " << tPlayer.strJobName << endl;
					OutputMonster(&tMonster); //몬스터 정보 출력

					cout << "1. 공격" << endl;
					cout << "2. 도망가기" << endl;
					cout << "메뉴를 선택하세요 : ";
					iMenu = InputInt();
					if (iMenu == INT_MAX) {
						continue;
					}
					else if (iMenu == BATTLE_BACK) {
						break;
					}

					switch (iMenu) {
					case BATTLE_ATTACK:
						int iAttack = (rand() % (tPlayer.iAttackMax - tPlayer.iAttackMin + 1)) + tPlayer.iAttackMin;
						int iArmor = (rand() % (tMonster.iArmorMax - tMonster.iArmorMin + 1)) + tMonster.iArmorMin;
						int iDamage = iAttack - iArmor;
						iDamage = iDamage < 1 ? 1 : iDamage;

						// 몬스터 HP를 감소시킨다.
						tMonster.iHP -= iDamage;

						cout << tPlayer.strName << " 가 " << tMonster.strName << "에게 " << iDamage << " 피해를 입혔습니다. " << endl;

						// 몬스터가 죽었을 경우를 처리한다.
						if (tMonster.iHP <= 0) {
							cout << tMonster.strName << " 몬스터가 사망하였습니다." << endl;

							tPlayer.iExp += tMonster.iExp;
							int iGold = (rand() % tMonster.iGoldMax - tMonster.iGoldMin + 1) + tMonster.iGoldMin;
							tPlayer.tInventory.iGold += iGold;

							cout << tMonster.iExp << " 경험치를 획득하였습니다. " << endl;
							cout << iGold << " 골드를 획득하였습니다. " << endl;



							// 경험치가 꽉차면 레벨업을 한다.
							while (tPlayer.iExp >= iLevelUpExp[tPlayer.iLevel - 1]) {
								tPlayer.iExp = tPlayer.iExp - iLevelUpExp[tPlayer.iLevel - 1];
								++tPlayer.iLevel;
							}



							// 몬스터의 HP와 MP를 회복한다.
							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;

							system("pause");
							break;
						}
						// 몬스터가 살아있다면 플레이어를 공격한다.
						iAttack = (rand() % (tMonster.iAttackMax - tMonster.iAttackMin + 1)) + tMonster.iAttackMin;
						iArmor = (rand() % (tPlayer.iArmorMax - tPlayer.iArmorMin + 1)) + tPlayer.iArmorMin;

						iDamage = iAttack - iArmor;

						iDamage = iDamage < 1 ? 1 : iDamage;

						// 플레이어의 HP를 감소시킨다.
						tPlayer.iHP -= iDamage;

						cout << tMonster.strName << " 가 " << tPlayer.strName << "에게 " << iDamage << " 피해를 입혔습니다. " << endl;

						// 플레이어가 죽었을 경우
						if (tPlayer.iHP <= 0) {
							cout << tPlayer.strName << " 플레이어가 사망하였습니다." << endl;

							int iExp = tPlayer.iExp * 0.1f;
							int iGold = tPlayer.tInventory.iGold * 0.1f;

							tPlayer.iExp -= iExp;
							tPlayer.tInventory.iGold -= iGold;

							cout << iExp << " 경험치를 잃었습니다. " << endl;
							cout << iGold << " 골드를 잃었습니다. " << endl;

							// 플레이어의 HP와 MP를 회복한다.
							tPlayer.iHP = tPlayer.iHPMax;
							tPlayer.iMP = tPlayer.iMPMax;
							break;
						}
						break;
					}
				}
			}
			break;
		case MM_STORE:
			while (true) {
				system("cls");
				cout << "===================== 상점 ==================" << endl;
				cout << "1. 무기상점" << endl;
				cout << "2. 방어구상점" << endl;
				cout << "3. 뒤로가기" << endl;
				cout << "상점을 선택하세요 : ";
				cin >> iMenu;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else if (iMenu == SM_BACK) {
					break;
				}
				switch (iMenu) {
				case SM_WEAPON:
					while (true) {
						system("cls");
						cout << "===================== 무기상점 ==================" << endl;

						int i;

						int iItemChoice = OutputStoreItemList(&tPlayer.tInventory, tStoreWeapon, STORE_WEAPON_MAX); // 무기 출력

						if (iItemChoice == INT_MAX) {
							continue;
						}
						// 뒤로가기
						else if (iItemChoice == STORE_ARMOR_MAX + 1) {
							break;
						}

						// 골드가 부족하면
						if (tPlayer.tInventory.iGold < tStoreWeapon[iItemChoice - 1].iPrice) {
							cout << "보유금액이 부족합니다." << endl;
							system("pause");
							continue;
						}

						// 인벤토리가 꽉 찼는지 검사한다.
						if (tPlayer.tInventory.iItemCount >= INVENTORY_MAX) {
							cout << "가방이 꽉 찼습니다." << endl;
							system("pause");
							continue;
						}

						// 인벤토리에 넣는다.
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreWeapon[iItemChoice - 1];

						tPlayer.tInventory.iGold -= tStoreWeapon[iItemChoice - 1].iPrice;

						cout << tStoreWeapon[iItemChoice - 1].strName << "아이템을 구매하였습니다." << endl;
						++tPlayer.tInventory.iItemCount;

						system("pause");
					}
					break;
				case SM_ARMOR:
					while (true) {
						system("cls");
						cout << "===================== 방어구상점 ==================" << endl;

						int i;

						int iItemChoice = OutputStoreItemList(&tPlayer.tInventory, tStoreArmor, STORE_ARMOR_MAX); // 방어구 출력

						if (iItemChoice == INT_MAX) {
							continue;
						}
						// 뒤로가기
						else if (iItemChoice == STORE_ARMOR_MAX + 1) {
							break;
						}

						// 골드가 부족하면
						if (tPlayer.tInventory.iGold < tStoreArmor[iItemChoice - 1].iPrice) {

							cout << "보유금액이 부족합니다." << endl;
							system("pause");
							continue;
						}

						// 인벤토리가 꽉 찼는지 검사한다.
						if (tPlayer.tInventory.iItemCount >= INVENTORY_MAX) {
							cout << "가방이 꽉 찼습니다." << endl;
							system("pause");
							continue;
						}

						// 인벤토리에 넣는다.
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreArmor[iItemChoice - 1];

						tPlayer.tInventory.iGold -= tStoreArmor[iItemChoice - 1].iPrice;
						++tPlayer.tInventory.iItemCount;
						cout << tStoreArmor[iItemChoice - 1].strName << "아이템을 구매하였습니다." << endl;
					}
					break;
				}
			}
			break;
		case MM_INVENTORY:
			while (true) {
				system("cls");
				cout << "===================== 인벤토리 ==================" << endl;
				cout << "================== Player =============" << endl;
				cout << "이름 : " << tPlayer.strName << "\t직업 : " << tPlayer.strJobName << endl;
				cout << "레벨 : " << tPlayer.iLevel << "\t경험치 : " << tPlayer.iExp << " / " << iLevelUpExp[tPlayer.iLevel - 1];

				// 무기를 장착하고 있으 경우 공격력에 무기공격력을 추가하여 출력한다.
				if (tPlayer.bEquip[EQ_WEAPON]) {
					cout << "공격력 : " << tPlayer.iAttackMin << " + " << tPlayer.tEquip[EQ_WEAPON].iMin << " - " << tPlayer.iAttackMax << " + " << tPlayer.tEquip[EQ_WEAPON].iMax;
				}
				else {
					cout << "공격력 : " << tPlayer.iAttackMin << " - " << tPlayer.iAttackMax;
				}

				// 방어구를 장착하고 있을 경우 방어력에 방어구 방어력을 추가하여 출력한다.
				if (tPlayer.bEquip[EQ_ARMOR]) {
					cout << "\t방어력 : " << tPlayer.iArmorMin << " + " << tPlayer.tEquip[EQ_ARMOR].iMin << " - " << tPlayer.iArmorMax << " + " << tPlayer.tEquip[EQ_ARMOR].iMax << endl;
				}
				else {
					cout << "\t방어력 : " << tPlayer.iArmorMin << " - " << tPlayer.iArmorMax << endl;
				}

				cout << "체력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax << "\t마나 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;

				if (tPlayer.bEquip[EQ_WEAPON]) {
					cout << "장착무기 : " << tPlayer.tEquip[EQ_WEAPON].strName;
				}
				else {
					cout << "장착무기 : 없음";
				}

				if (tPlayer.bEquip[EQ_ARMOR]) {
					cout << "\t장착방어구 : " << tPlayer.tEquip[EQ_ARMOR].strName << endl;
				}
				else {
					cout << "\t장착방어구 : 없음" << endl;;
				}

				cout << "보유골드 : " << tPlayer.tInventory.iGold << " 골드" << endl << endl;

				for (int i = 0; i < tPlayer.tInventory.iItemCount; ++i) {
					cout << i + 1 << ". 이름 : " << tPlayer.tInventory.tItem[i].strName << endl;
					if (tPlayer.tInventory.tItem[i].eType == IT_WEAPON) {
						cout << "공격력 : " << tPlayer.tInventory.tItem[i].iMin << " - " << tPlayer.tInventory.tItem[i].iMax << endl;
					}
					else if (tPlayer.tInventory.tItem[i].eType == IT_ARMOR) {
						cout << "방어력 : " << tPlayer.tInventory.tItem[i].iMin << " - " << tPlayer.tInventory.tItem[i].iMax << endl;
					}
					cout << "구매 가격 : " << tPlayer.tInventory.tItem[i].iPrice << "\t되파는 가격 : " << tPlayer.tInventory.tItem[i].iSell << endl;
					cout << "설명 : " << tPlayer.tInventory.tItem[i].strDesc << endl << endl;
				}

				cout << tPlayer.tInventory.iItemCount + 1 << ". 뒤로가기" << endl;
				cout << "장착할 아이템을 선택하세요 : ";
				cin >> iMenu;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else if (iMenu == tPlayer.tInventory.iItemCount + 1) {
					break;
				}
				else if (iMenu < 1 || iMenu > tPlayer.tInventory.iItemCount + 1) {
					cout << "잘못 입력하였습니다." << endl;
					system("pause");
					continue;
				}

				// 아이템 인덱스를 구해준다.
				int idx = iMenu - 1;

				// 제대로 선택했을 경우 해당 아이템의 종류에 따라 장착 부위를 결정하게 된다.
				EQUIP equip;

				switch (tPlayer.tInventory.tItem[idx].eType) {
				case IT_WEAPON:
					equip = EQ_WEAPON;
					break;
				case IT_ARMOR:
					equip = EQ_ARMOR;
					break;
				}

				// 아이템이 장착되어 있을 경우 장착되어있는 아이템과 장착할 아이템을 교체해 주어야 한다. Swap 알고리즘을 활용한다.
				if (tPlayer.bEquip[equip]) {
					_tagItem tSwap = tPlayer.tEquip[equip];
					tPlayer.tEquip[equip] = tPlayer.tInventory.tItem[idx];
					tPlayer.tInventory.tItem[idx] = tSwap;
				}
				else {
					// 장착되어있지 않을 경우 인벤토리 아이템을 장착창으로 옮기고 인벤토리는 1칸 비워지게 된다.
					tPlayer.tEquip[equip] = tPlayer.tInventory.tItem[idx];

					for (int i = idx; i < tPlayer.tInventory.iItemCount - 1; ++i) {
						tPlayer.tInventory.tItem[i] = tPlayer.tInventory.tItem[i + 1];
					}
					--tPlayer.tInventory.iItemCount;
					tPlayer.bEquip[equip] = true;
				}
			}
			break;
		default:
			cout << "잘못 선택하였습니다. " << endl;
			break;
		}
	}

	SavePlayer(&tPlayer);

	return 0;
}