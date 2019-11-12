// PROGRAM : �ؽ�Ʈ RPG
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

// bool�� �̿��ؼ������� ����� ����������� �Ǵ��Ѵ�.
bool SavePlayer(_tagPlayer* pPlayer) {
	FILE* pFile = NULL;
	fopen_s(&pFile, "Player.ply", "wb");

	if (pFile) {
		// �÷��̾� �̸��� �����Ѵ�.
		fwrite(pPlayer->strName, sizeof(char), NAME_SIZE, pFile);
		// ���� ������ �����Ѵ�.
		fwrite(&pPlayer->eJob, sizeof(JOB), 1, pFile); // ����ü�� ������ 4byte�� ó���ȴ�. �迭�� �ƴϹǷ� 1��
		fwrite(pPlayer->strJobName, 1, NAME_SIZE, pFile);

		// ���ݷ��� �����Ѵ�.
		fwrite(&pPlayer->iAttackMin, sizeof(int), 1, pFile);
		fwrite(&pPlayer->iAttackMax, sizeof(int), 1, pFile);

		// ������ �����Ѵ�.
		fwrite(&pPlayer->iArmorMin, sizeof(int), 1, pFile);
		fwrite(&pPlayer->iArmorMax, sizeof(int), 1, pFile);

		// ü���� �����Ѵ�.
		fwrite(&pPlayer->iHP, sizeof(int), 1, pFile);
		fwrite(&pPlayer->iHPMax, sizeof(int), 1, pFile);

		// ������ �����Ѵ�.
		fwrite(&pPlayer->iMP, sizeof(int), 1, pFile);
		fwrite(&pPlayer->iMPMax, sizeof(int), 1, pFile);

		// ������ ����ġ�� �����Ѵ�.
		fwrite(&pPlayer->iLevel, sizeof(int), 1, pFile);
		fwrite(&pPlayer->iExp, sizeof(int), 1, pFile);


		// ���� ������ ���뿩�θ� �����Ѵ�.
		fwrite(&pPlayer->bEquip[EQ_WEAPON], 1, 1, pFile);

		// ���� �����Ҷ� ���⸦ ���� �־��ٸ� �ش� ���������� ���� ������ �Ǿ���.
		// �׷��Ƿ� ���⼭ ���� ���� ��� �о�� �Ѵ�.
		if (pPlayer->bEquip[EQ_WEAPON]) {
			fwrite(&pPlayer->tEquip[EQ_WEAPON], sizeof(_tagItem), 1, pFile);
		}
		// �� ������ ���뿩�θ� �����Ѵ�.
		if (pPlayer->bEquip[EQ_ARMOR]) {
			fwrite(&pPlayer->tEquip[EQ_ARMOR], sizeof(_tagItem), 1, pFile);
		}

		/*
		int iGoldMin;
		int iGoldMax;*/

		// ��带 �����Ѵ�.
		fwrite(&pPlayer->tInventory.iGold, sizeof(int), 1, pFile);

		// �κ��丮 ������ ���� �����Ѵ�.
		fwrite(&pPlayer->tInventory.iItemCount, sizeof(int), 1, pFile);

		// ������ ����ŭ �κ��丮�� ������������ �����Ѵ�.
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
	// �÷��̾� �̸��� �Է¹޴´�.
	cout << "�̸� : ";
	InputString(pPlayer->strName, NAME_SIZE);
	cout << pPlayer->strName << "�� �Է��Ͽ����ϴ�." << endl;

	int iJob = JOB_NONE;
	while (iJob == JOB_NONE) {
		system("cls");
		cout << "========================= �κ� ===========================" << endl;
		cout << "1. ���" << endl;
		cout << "2. �ü�" << endl;
		cout << "3. ������" << endl;
		cout << "������ �����ϼ��� : ";
		iJob = InputInt();
		if (iJob == INT_MAX) {
			continue;
		}
		else if (iJob <= JOB_NONE || iJob >= JOB_END) {
			iJob = JOB_NONE;
		}
	}

	// �÷��̾��� ������ �����ϱ�
	pPlayer->iLevel = 1;
	pPlayer->iExp = 0;
	pPlayer->eJob = (JOB)iJob;
	pPlayer->tInventory.iGold = 100000;

	switch (pPlayer->eJob) {
	case JOB_KNIGHT:
		strcpy_s(pPlayer->strJobName, "���");
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
		strcpy_s(pPlayer->strJobName, "�ü�");
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
		strcpy_s(pPlayer->strJobName, "������");
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

		// �÷��̾� �̸��� �ҷ��´�.
		fread(pPlayer->strName, sizeof(char), NAME_SIZE, pFile);
		// ���� ������ �о�´�.
		fread(&pPlayer->eJob, sizeof(JOB), 1, pFile); // ����ü�� ������ 4byte�� ó���ȴ�. �迭�� �ƴϹǷ� 1��
		fread(pPlayer->strJobName, 1, NAME_SIZE, pFile);

		// ���ݷ��� �о�´�.
		fread(&pPlayer->iAttackMin, sizeof(int), 1, pFile);
		fread(&pPlayer->iAttackMax, sizeof(int), 1, pFile);

		// ������ �о�´�.
		fread(&pPlayer->iArmorMin, sizeof(int), 1, pFile);
		fread(&pPlayer->iArmorMax, sizeof(int), 1, pFile);

		// ü���� �о�´�.
		fread(&pPlayer->iHP, sizeof(int), 1, pFile);
		fread(&pPlayer->iHPMax, sizeof(int), 1, pFile);
		
		// ������ �о�´�.
		fread(&pPlayer->iMP, sizeof(int), 1, pFile);
		fread(&pPlayer->iMPMax, sizeof(int), 1, pFile);
		
		// ������ ����ġ�� �о�´�.
		fread(&pPlayer->iLevel, sizeof(int), 1, pFile);
		fread(&pPlayer->iExp, sizeof(int), 1, pFile);
		

		// ���� ������ ���뿩�θ� �о�´�.
		fread(&pPlayer->bEquip[EQ_WEAPON], 1, 1, pFile);
		
		// ���� �����Ҷ� ���⸦ ���� �־��ٸ� �ش� ���������� ���� ������ �Ǿ���.
		// �׷��Ƿ� ���⼭ ���� ���� ��� �о�� �Ѵ�.
		if (pPlayer->bEquip[EQ_WEAPON]) {
			fread(&pPlayer->tEquip[EQ_WEAPON], sizeof(_tagItem), 1, pFile);
		}
		// �� ������ ���뿩�θ� �о�´�.
		if (pPlayer->bEquip[EQ_ARMOR]) {
			fread(&pPlayer->tEquip[EQ_ARMOR], sizeof(_tagItem), 1, pFile);
		}

		/*
		int iGoldMin;
		int iGoldMax;*/

		// ��带 �о�´�.
		fread(&pPlayer->tInventory.iGold, sizeof(int), 1, pFile);

		// �κ��丮 ������ ���� �о�´�.
		fread(&pPlayer->tInventory.iItemCount, sizeof(int), 1, pFile);

		// �о�� ������ ����ŭ �κ��丮�� ������������ �о�´�.
		fread(pPlayer->tInventory.tItem, sizeof(_tagItem), pPlayer->tInventory.iItemCount, pFile);

		fclose(pFile);
		return true;
	}
	return false;
}

// ���� ������ ����Ѵ�.
void OutputMonster(_tagMonster* pMonster) {
	cout << "=========================== Monster ===================" << endl;
	cout << "�̸� : " << pMonster->strName << "\t���� : " << pMonster->iLevel << endl;
	cout << "���ݷ� : " << pMonster->iAttackMin << " - " << pMonster->iAttackMax <<
		"\t���� : " << pMonster->iArmorMin << " - " << pMonster->iArmorMax << endl;
	cout << "ü�� : " << pMonster->iHP << " / " << pMonster->iHPMax <<
		"\t���� : " << pMonster->iMP << " / /" << pMonster->iMPMax << endl;
	cout << "ȹ�����ġ : " << pMonster->iExp << "\tȹ����" << pMonster->iGoldMin << " - " << pMonster->iGoldMax << endl;
}

// �÷��̾� ������ ����Ѵ�.
void OutputPlayer(_tagPlayer* pPlayer) {
	cout << "=========================== Player ===================" << endl;
	cout << "�̸� : " << pPlayer->strName << "\t���� : " << pPlayer->strJobName << endl;
	cout << "���� : " << pPlayer->iLevel << "\t����ġ : " << pPlayer->iExp << endl;
	cout << "���ݷ� : " << pPlayer->iAttackMin << " - " << pPlayer->iAttackMax <<
		"\t���� : " << pPlayer->iArmorMin << " - " << pPlayer->iArmorMax << endl;
	cout << "ü�� : " << pPlayer->iHP << " / " << pPlayer->iHPMax <<
		"\t���� : " << pPlayer->iMP << " / /" << pPlayer->iMPMax << endl;
	cout << "������� : " << pPlayer->tInventory.iGold << " ���" << endl;
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

	/*pMonsterArr[0] = CreateMonster("���", 20, 30, 2, 5, 100, 10, 1, 1000, 500, 1500);
	pMonsterArr[1] = CreateMonster("Ʈ��", 80, 130, 60, 90, 2000, 100, 5, 7000, 6000, 8000);
	pMonsterArr[2] = CreateMonster("�巡��", 250, 500, 200, 400, 30000, 20000, 10, 30000, 20000, 50000);*/
}

_tagItem CreateItem(const char* strName, ITEM_TYPE eItemType, int iMin, int iMax, int iPrice, int iSell, const char* strDesc) {
	_tagItem tItem;
	strcpy_s(tItem.strName, strName);
	if (eItemType == IT_WEAPON) {
		strcpy_s(tItem.strTypeName, "����");
	}
	else if (eItemType == IT_ARMOR) {
		strcpy_s(tItem.strTypeName, "��");
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
	// �Ǹ� ����� �����ش�.
	for (int i = 0; i < iItemCount; ++i) {
		cout << i + 1 << ". �̸� : " << pStore[i].strName << "\t���� : " << pStore[i].strTypeName << endl;
		cout << "��/���� : " << pStore[i].iMin << " - " << pStore[i].iMax << endl;
		cout << "�ǸŰ��� : " << pStore[i].iPrice << "\t���Ű��� : " << pStore[i].iSell << endl;
		cout << "���� : " << pStore[i].strDesc << endl;
		cout << endl;

		cout << endl;
		cout << iItemCount + 1 << ". �ڷΰ���" << endl;
		cout << "�����ݾ� : " << pInventory->iGold << " Gold" << endl;
		cout << "�������� : " << INVENTORY_MAX - pInventory->iItemCount << endl;
		cout << "������ �������� �����ϼ��� : ";
	}

	int iMenu = InputInt();
	if (iMenu < 1 || iMenu > iItemCount + 1) {
		return INT_MAX;
	}
	return iMenu;
}


int main() {

	srand((unsigned int)time(0));

	// �������� �ʿ��� ����ġ ����� �����.
	const int iLevelUpExp[LEVEL_MAX] = { 2000,4000,10000,30000,50000,70000,100000,150000,200000,400000 };

	// ������ �����Ҷ� �÷��̾� ������ �����ϰ� �Ѵ�.
	_tagPlayer tPlayer = {};


	int iGameMode = 0;
	while (iGameMode <= GM_NONE || iGameMode > GM_LOAD) {
		system("cls");
		cout << "1. �����ϱ�" << endl;
		cout << "2. �̾��ϱ�" << endl;
		cout << "3. ����" << endl;
		cout << "���Ӹ�带 �����ϼ��� : ";
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
			cout << "�÷��̾� ���� ����!!" << endl;
			return 0;
		}
		break;
	}


	// ���͸� �����Ѵ�.
	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	for (int i = 0; i < 3; i++) {
		SetMonster(&tMonsterArr[i]); // ���� �ʱ�ȭ
	}
	


	// �������� �Ǹ��� ������ ����� �����Ѵ�.
	_tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem tStoreArmor[STORE_ARMOR_MAX] = {};


	// ���� ������ ���� ����
	tStoreWeapon[0] = CreateItem("���", IT_WEAPON, 5, 10, 1000, 500, "������ ���� Į");
	tStoreWeapon[1] = CreateItem("���", IT_WEAPON, 20, 40, 7000, 3500, "¯¯�� Ȱ");
	tStoreWeapon[2] = CreateItem("������", IT_WEAPON, 90, 150, 30000, 15000, "������ ���� ������");

	// �� ������ ���� ����
	tStoreArmor[0] = CreateItem("õ����", IT_ARMOR, 2, 5, 1000, 500, "õ���� ���� ������ ����");
	tStoreArmor[1] = CreateItem("���װ���", IT_ARMOR, 10, 20, 7000, 3500, "���� �������� ���� ���� ����");
	tStoreArmor[2] = CreateItem("Ǯ�÷���Ʈ�Ƹ�", IT_ARMOR, 70, 90, 30000, 15000, "��ö�� ���� �Ǳݰ���");

	while (true) {
		system("cls");
		cout << "===================== �κ� ==================" << endl;
		cout << "1. ��" << endl;
		cout << "2. ����" << endl;
		cout << "3. ����" << endl;
		cout << "4. ���� " << endl;
		cout << "�޴��� �����ϼ��� : ";

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
				cout << "===================== �� ==================" << endl;
				cout << "1. ����" << endl;
				cout << "2. ����" << endl;
				cout << "3. �����" << endl;
				cout << "4. �ڷΰ���" << endl;

				iMenu = InputInt();
				if (iMenu == INT_MAX) {
					continue;
				}

				// �� if���� ���� break�� �� �޴��� �����ֱ� ���� while�� ���� �����Ƿ� �� while�� ����������.
				if (iMenu == MT_BACK) {
					break;
				}

				// ������ �޴����� 1�� ���ָ� ���� �迭�� �ε����� �ȴ�.
				// �׷��� �ؼ� �ش� ���� ���͸� �������ش�.
				_tagMonster tMonster = tMonsterArr[iMenu - 1];

				while (true) {
					system("cls");
					switch (iMenu) {
					case MT_EASY:
						cout << "===================== ���� ==================" << endl;
						break;
					case MT_NORMAL:
						cout << "===================== ���� ==================" << endl;
						break;
					case MT_HARD:
						cout << "===================== ����� ==================" << endl;
						break;
					}

					OutputPlayer(&tPlayer);   // �÷��̾� ���� ���
					cout << "!!! " << tPlayer.strJobName << endl;
					OutputMonster(&tMonster); //���� ���� ���

					cout << "1. ����" << endl;
					cout << "2. ��������" << endl;
					cout << "�޴��� �����ϼ��� : ";
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

						// ���� HP�� ���ҽ�Ų��.
						tMonster.iHP -= iDamage;

						cout << tPlayer.strName << " �� " << tMonster.strName << "���� " << iDamage << " ���ظ� �������ϴ�. " << endl;

						// ���Ͱ� �׾��� ��츦 ó���Ѵ�.
						if (tMonster.iHP <= 0) {
							cout << tMonster.strName << " ���Ͱ� ����Ͽ����ϴ�." << endl;

							tPlayer.iExp += tMonster.iExp;
							int iGold = (rand() % tMonster.iGoldMax - tMonster.iGoldMin + 1) + tMonster.iGoldMin;
							tPlayer.tInventory.iGold += iGold;

							cout << tMonster.iExp << " ����ġ�� ȹ���Ͽ����ϴ�. " << endl;
							cout << iGold << " ��带 ȹ���Ͽ����ϴ�. " << endl;



							// ����ġ�� ������ �������� �Ѵ�.
							while (tPlayer.iExp >= iLevelUpExp[tPlayer.iLevel - 1]) {
								tPlayer.iExp = tPlayer.iExp - iLevelUpExp[tPlayer.iLevel - 1];
								++tPlayer.iLevel;
							}



							// ������ HP�� MP�� ȸ���Ѵ�.
							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;

							system("pause");
							break;
						}
						// ���Ͱ� ����ִٸ� �÷��̾ �����Ѵ�.
						iAttack = (rand() % (tMonster.iAttackMax - tMonster.iAttackMin + 1)) + tMonster.iAttackMin;
						iArmor = (rand() % (tPlayer.iArmorMax - tPlayer.iArmorMin + 1)) + tPlayer.iArmorMin;

						iDamage = iAttack - iArmor;

						iDamage = iDamage < 1 ? 1 : iDamage;

						// �÷��̾��� HP�� ���ҽ�Ų��.
						tPlayer.iHP -= iDamage;

						cout << tMonster.strName << " �� " << tPlayer.strName << "���� " << iDamage << " ���ظ� �������ϴ�. " << endl;

						// �÷��̾ �׾��� ���
						if (tPlayer.iHP <= 0) {
							cout << tPlayer.strName << " �÷��̾ ����Ͽ����ϴ�." << endl;

							int iExp = tPlayer.iExp * 0.1f;
							int iGold = tPlayer.tInventory.iGold * 0.1f;

							tPlayer.iExp -= iExp;
							tPlayer.tInventory.iGold -= iGold;

							cout << iExp << " ����ġ�� �Ҿ����ϴ�. " << endl;
							cout << iGold << " ��带 �Ҿ����ϴ�. " << endl;

							// �÷��̾��� HP�� MP�� ȸ���Ѵ�.
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
				cout << "===================== ���� ==================" << endl;
				cout << "1. �������" << endl;
				cout << "2. ������" << endl;
				cout << "3. �ڷΰ���" << endl;
				cout << "������ �����ϼ��� : ";
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
						cout << "===================== ������� ==================" << endl;

						int i;

						int iItemChoice = OutputStoreItemList(&tPlayer.tInventory, tStoreWeapon, STORE_WEAPON_MAX); // ���� ���

						if (iItemChoice == INT_MAX) {
							continue;
						}
						// �ڷΰ���
						else if (iItemChoice == STORE_ARMOR_MAX + 1) {
							break;
						}

						// ��尡 �����ϸ�
						if (tPlayer.tInventory.iGold < tStoreWeapon[iItemChoice - 1].iPrice) {
							cout << "�����ݾ��� �����մϴ�." << endl;
							system("pause");
							continue;
						}

						// �κ��丮�� �� á���� �˻��Ѵ�.
						if (tPlayer.tInventory.iItemCount >= INVENTORY_MAX) {
							cout << "������ �� á���ϴ�." << endl;
							system("pause");
							continue;
						}

						// �κ��丮�� �ִ´�.
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreWeapon[iItemChoice - 1];

						tPlayer.tInventory.iGold -= tStoreWeapon[iItemChoice - 1].iPrice;

						cout << tStoreWeapon[iItemChoice - 1].strName << "�������� �����Ͽ����ϴ�." << endl;
						++tPlayer.tInventory.iItemCount;

						system("pause");
					}
					break;
				case SM_ARMOR:
					while (true) {
						system("cls");
						cout << "===================== ������ ==================" << endl;

						int i;

						int iItemChoice = OutputStoreItemList(&tPlayer.tInventory, tStoreArmor, STORE_ARMOR_MAX); // �� ���

						if (iItemChoice == INT_MAX) {
							continue;
						}
						// �ڷΰ���
						else if (iItemChoice == STORE_ARMOR_MAX + 1) {
							break;
						}

						// ��尡 �����ϸ�
						if (tPlayer.tInventory.iGold < tStoreArmor[iItemChoice - 1].iPrice) {

							cout << "�����ݾ��� �����մϴ�." << endl;
							system("pause");
							continue;
						}

						// �κ��丮�� �� á���� �˻��Ѵ�.
						if (tPlayer.tInventory.iItemCount >= INVENTORY_MAX) {
							cout << "������ �� á���ϴ�." << endl;
							system("pause");
							continue;
						}

						// �κ��丮�� �ִ´�.
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreArmor[iItemChoice - 1];

						tPlayer.tInventory.iGold -= tStoreArmor[iItemChoice - 1].iPrice;
						++tPlayer.tInventory.iItemCount;
						cout << tStoreArmor[iItemChoice - 1].strName << "�������� �����Ͽ����ϴ�." << endl;
					}
					break;
				}
			}
			break;
		case MM_INVENTORY:
			while (true) {
				system("cls");
				cout << "===================== �κ��丮 ==================" << endl;
				cout << "================== Player =============" << endl;
				cout << "�̸� : " << tPlayer.strName << "\t���� : " << tPlayer.strJobName << endl;
				cout << "���� : " << tPlayer.iLevel << "\t����ġ : " << tPlayer.iExp << " / " << iLevelUpExp[tPlayer.iLevel - 1];

				// ���⸦ �����ϰ� ���� ��� ���ݷ¿� ������ݷ��� �߰��Ͽ� ����Ѵ�.
				if (tPlayer.bEquip[EQ_WEAPON]) {
					cout << "���ݷ� : " << tPlayer.iAttackMin << " + " << tPlayer.tEquip[EQ_WEAPON].iMin << " - " << tPlayer.iAttackMax << " + " << tPlayer.tEquip[EQ_WEAPON].iMax;
				}
				else {
					cout << "���ݷ� : " << tPlayer.iAttackMin << " - " << tPlayer.iAttackMax;
				}

				// ���� �����ϰ� ���� ��� ���¿� �� ������ �߰��Ͽ� ����Ѵ�.
				if (tPlayer.bEquip[EQ_ARMOR]) {
					cout << "\t���� : " << tPlayer.iArmorMin << " + " << tPlayer.tEquip[EQ_ARMOR].iMin << " - " << tPlayer.iArmorMax << " + " << tPlayer.tEquip[EQ_ARMOR].iMax << endl;
				}
				else {
					cout << "\t���� : " << tPlayer.iArmorMin << " - " << tPlayer.iArmorMax << endl;
				}

				cout << "ü�� : " << tPlayer.iHP << " / " << tPlayer.iHPMax << "\t���� : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;

				if (tPlayer.bEquip[EQ_WEAPON]) {
					cout << "�������� : " << tPlayer.tEquip[EQ_WEAPON].strName;
				}
				else {
					cout << "�������� : ����";
				}

				if (tPlayer.bEquip[EQ_ARMOR]) {
					cout << "\t������ : " << tPlayer.tEquip[EQ_ARMOR].strName << endl;
				}
				else {
					cout << "\t������ : ����" << endl;;
				}

				cout << "������� : " << tPlayer.tInventory.iGold << " ���" << endl << endl;

				for (int i = 0; i < tPlayer.tInventory.iItemCount; ++i) {
					cout << i + 1 << ". �̸� : " << tPlayer.tInventory.tItem[i].strName << endl;
					if (tPlayer.tInventory.tItem[i].eType == IT_WEAPON) {
						cout << "���ݷ� : " << tPlayer.tInventory.tItem[i].iMin << " - " << tPlayer.tInventory.tItem[i].iMax << endl;
					}
					else if (tPlayer.tInventory.tItem[i].eType == IT_ARMOR) {
						cout << "���� : " << tPlayer.tInventory.tItem[i].iMin << " - " << tPlayer.tInventory.tItem[i].iMax << endl;
					}
					cout << "���� ���� : " << tPlayer.tInventory.tItem[i].iPrice << "\t���Ĵ� ���� : " << tPlayer.tInventory.tItem[i].iSell << endl;
					cout << "���� : " << tPlayer.tInventory.tItem[i].strDesc << endl << endl;
				}

				cout << tPlayer.tInventory.iItemCount + 1 << ". �ڷΰ���" << endl;
				cout << "������ �������� �����ϼ��� : ";
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
					cout << "�߸� �Է��Ͽ����ϴ�." << endl;
					system("pause");
					continue;
				}

				// ������ �ε����� �����ش�.
				int idx = iMenu - 1;

				// ����� �������� ��� �ش� �������� ������ ���� ���� ������ �����ϰ� �ȴ�.
				EQUIP equip;

				switch (tPlayer.tInventory.tItem[idx].eType) {
				case IT_WEAPON:
					equip = EQ_WEAPON;
					break;
				case IT_ARMOR:
					equip = EQ_ARMOR;
					break;
				}

				// �������� �����Ǿ� ���� ��� �����Ǿ��ִ� �����۰� ������ �������� ��ü�� �־�� �Ѵ�. Swap �˰����� Ȱ���Ѵ�.
				if (tPlayer.bEquip[equip]) {
					_tagItem tSwap = tPlayer.tEquip[equip];
					tPlayer.tEquip[equip] = tPlayer.tInventory.tItem[idx];
					tPlayer.tInventory.tItem[idx] = tSwap;
				}
				else {
					// �����Ǿ����� ���� ��� �κ��丮 �������� ����â���� �ű�� �κ��丮�� 1ĭ ������� �ȴ�.
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
			cout << "�߸� �����Ͽ����ϴ�. " << endl;
			break;
		}
	}

	SavePlayer(&tPlayer);

	return 0;
}