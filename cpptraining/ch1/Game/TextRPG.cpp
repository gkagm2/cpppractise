// PROGRAM : �ؽ�Ʈ RPG
// DEVELOPER : Sagacity Jang
// DATE : 2019.11.01 ~ *

#include <iostream>
#include <time.h>

using namespace std;


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

int main() {

	srand((unsigned int)time(0));

	// ������ �����Ҷ� �÷��̾� ������ �����ϰ� �Ѵ�.
	_tagPlayer tPlayer = {};

	// �÷��̾� �̸��� �Է¹޴´�.
	cout << "�̸� : ";
	cin.getline(tPlayer.strName, NAME_SIZE - 1);

	int iJob = JOB_NONE;
	while (iJob == JOB_NONE) {
		system("cls");
		cout << "========================= �κ� ===========================" << endl;
		cout << "1. ���" << endl;
		cout << "2. �ü�" << endl;
		cout << "3. ������" << endl;
		cout << "������ �����ϼ��� : ";
		cin >> iJob;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (iJob <= JOB_NONE || iJob >= JOB_END) {
			iJob = JOB_NONE;
		}
	}

	tPlayer.iLevel = 1;
	tPlayer.iExp = 0;
	tPlayer.eJob = (JOB)iJob;
	tPlayer.tInventory.iGold = 10000;

	switch (tPlayer.eJob) {
	case JOB_KNIGHT:
		strcpy_s(tPlayer.strJobName, "���");
		tPlayer.iAttackMin = 5;
		tPlayer.iAttackMax = 10;
		tPlayer.iArmorMin = 15;
		tPlayer.iArmorMax = 20;
		tPlayer.iHPMax = 500;
		tPlayer.iHP = 500;
		tPlayer.iMP = 100;
		tPlayer.iMPMax = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(tPlayer.strJobName, "�ü�");
		tPlayer.iAttackMin = 10;
		tPlayer.iAttackMax = 15;
		tPlayer.iArmorMin = 10;
		tPlayer.iArmorMax = 15;
		tPlayer.iHPMax = 400;
		tPlayer.iHP = 400;
		tPlayer.iMP = 200;
		tPlayer.iMPMax = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(tPlayer.strJobName, "������");
		tPlayer.iAttackMin = 15;
		tPlayer.iAttackMax = 20;
		tPlayer.iArmorMin = 5;
		tPlayer.iArmorMax = 10;
		tPlayer.iHPMax = 300;
		tPlayer.iHP = 300;
		tPlayer.iMP = 300;
		tPlayer.iMPMax = 300;
		break;
	}

	// ���͸� �����Ѵ�.
	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	// ������ ����
	strcpy_s(tMonsterArr[0].strName, "������");
	tMonsterArr[0].iAttackMin = 20;
	tMonsterArr[0].iAttackMax = 30;
	tMonsterArr[0].iArmorMin = 2;
	tMonsterArr[0].iArmorMax = 5;
	tMonsterArr[0].iHP = 100;
	tMonsterArr[0].iHPMax = 100;
	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iLevel = 1;
	tMonsterArr[0].iExp = 1000;
	tMonsterArr[0].iGoldMin = 500;
	tMonsterArr[0].iGoldMax = 1500;

	// Ʈ�� ����
	strcpy_s(tMonsterArr[1].strName, "Ʈ��");
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMax = 130;
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
	tMonsterArr[1].iHP = 2000;
	tMonsterArr[1].iHPMax = 2000;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iLevel = 5;
	tMonsterArr[1].iExp = 7000;
	tMonsterArr[1].iGoldMin = 6000;
	tMonsterArr[1].iGoldMax = 8000;

	// �巡�� ����
	strcpy_s(tMonsterArr[2].strName, "�巡��");
	tMonsterArr[2].iAttackMin = 250;
	tMonsterArr[2].iAttackMax = 500;
	tMonsterArr[2].iArmorMin = 200;
	tMonsterArr[2].iArmorMax = 400;
	tMonsterArr[2].iHP = 30000;
	tMonsterArr[2].iHPMax = 30000;
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iLevel = 10;
	tMonsterArr[2].iExp = 30000;
	tMonsterArr[2].iGoldMin = 20000;
	tMonsterArr[2].iGoldMax = 50000;


	// �������� �Ǹ��� ������ ����� �����Ѵ�.
	_tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem tStoreArmor[STORE_ARMOR_MAX] = {};

	// �� ������ �������� �������ش�.

	// ���� ������ ���� ����
	// ��� ������
	strcpy_s(tStoreWeapon[0].strName, "���");
	strcpy_s(tStoreWeapon[0].strTypeName, "����");
	strcpy_s(tStoreWeapon[0].strDesc, "������ ���� Į");
	tStoreWeapon[0].eType = IT_WEAPON;
	tStoreWeapon[0].iMin = 5;
	tStoreWeapon[0].iMax = 10;
	tStoreWeapon[0].iPrice = 1000;
	tStoreWeapon[0].iSell = 500;

	// ��� ������
	strcpy_s(tStoreWeapon[1].strName, "���");
	strcpy_s(tStoreWeapon[1].strTypeName, "����");
	strcpy_s(tStoreWeapon[1].strDesc, "¯¯�� Ȱ");
	tStoreWeapon[1].eType = IT_WEAPON;
	tStoreWeapon[1].iMin = 20;
	tStoreWeapon[1].iMax = 40;
	tStoreWeapon[1].iPrice = 7000;
	tStoreWeapon[1].iSell = 3500;

	// ������ ������
	strcpy_s(tStoreWeapon[2].strName, "������");
	strcpy_s(tStoreWeapon[2].strTypeName, "����");
	strcpy_s(tStoreWeapon[2].strDesc, "������ ���� ������");
	tStoreWeapon[2].eType = IT_WEAPON;
	tStoreWeapon[2].iMin = 90;
	tStoreWeapon[2].iMax = 150;
	tStoreWeapon[2].iPrice = 30000;
	tStoreWeapon[2].iSell = 15000;

	// �� ������ ���� ����
	// õ����
	strcpy_s(tStoreArmor[0].strName, "õ����");
	strcpy_s(tStoreArmor[0].strTypeName, "��");
	strcpy_s(tStoreArmor[0].strDesc, "õ���� ���� ������ ����");
	tStoreArmor[0].eType = IT_ARMOR;
	tStoreArmor[0].iMin = 2;
	tStoreArmor[0].iMax = 5;
	tStoreArmor[0].iPrice = 1000;
	tStoreArmor[0].iSell = 500;
	
	strcpy_s(tStoreArmor[1].strName, "���װ���");
	strcpy_s(tStoreArmor[1].strTypeName, "��");
	strcpy_s(tStoreArmor[1].strDesc, "���� �������� ���� ���� ����");
	tStoreArmor[1].eType = IT_ARMOR;
	tStoreArmor[1].iMin = 10;
	tStoreArmor[1].iMax = 20;
	tStoreArmor[1].iPrice = 7000;
	tStoreArmor[1].iSell = 3500;

	strcpy_s(tStoreArmor[2].strName, "Ǯ�÷���Ʈ�Ƹ�");
	strcpy_s(tStoreArmor[2].strTypeName, "��");
	strcpy_s(tStoreArmor[2].strDesc, "��ö�� ���� �Ǳݰ���");
	tStoreArmor[2].eType = IT_ARMOR;
	tStoreArmor[2].iMin = 70;
	tStoreArmor[2].iMax = 90;
	tStoreArmor[2].iPrice = 30000;
	tStoreArmor[2].iSell = 15000;


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
				cin >> iMenu;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
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

					// �÷��̾� ������ ����Ѵ�.
					cout << "=========================== Player ===================" << endl;
					cout << "�̸� : " << tPlayer.strName << "\t���� : " << tPlayer.strJobName << endl;
					cout << "���� : " << tPlayer.iLevel << "\t����ġ : " << tPlayer.iExp << endl;
					cout << "���ݷ� : " << tPlayer.iAttackMin << " - " << tPlayer.iAttackMax <<
						"\t���� : " << tPlayer.iArmorMin << " - " << tPlayer.iArmorMax << endl;
					cout << "ü�� : " << tPlayer.iHP << " / " << tPlayer.iHPMax <<
						"\t���� : " << tPlayer.iMP << " / /" << tPlayer.iMPMax << endl;
					cout << "������� : " << tPlayer.tInventory.iGold << " ���" << endl;


					// ���� ������ ����Ѵ�.
					cout << "=========================== Monster ===================" << endl;
					cout << "�̸� : " << tMonster.strName << "\t���� : " << tMonster.iLevel << endl;
					cout << "���ݷ� : " << tMonster.iAttackMin << " - " << tMonster.iAttackMax <<
						"\t���� : " << tMonster.iArmorMin << " - " << tMonster.iArmorMax << endl;
					cout << "ü�� : " << tMonster.iHP << " / " << tMonster.iHPMax <<
						"\t���� : " << tMonster.iMP << " / /" << tMonster.iMPMax << endl;
					cout << "ȹ�����ġ : " << tMonster.iExp << "\tȹ����" << tMonster.iGoldMin << " - " << tMonster.iGoldMax << endl;

					cout << "1. ����" << endl;
					cout << "2. ��������" << endl;
					cout << "�޴��� �����ϼ��� : ";
					cin >> iMenu;

					if (cin.fail()) {
						cin.clear();
						cin.ignore(1024, '\n');
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
						// �Ǹ� ����� �����ش�.
						for (i = 0; i < STORE_WEAPON_MAX; ++i) {
							cout << i + 1 << ". �̸� : " << tStoreWeapon[i].strName << "\t���� : " << tStoreWeapon[i].strTypeName << endl;
							cout << "���ݷ� : " << tStoreWeapon[i].iMin << " - " << tStoreWeapon[i].iMax << endl;
							cout << "�ǸŰ��� : " << tStoreWeapon[i].iPrice << "\t���Ű��� : " << tStoreWeapon[i].iSell << endl;
							cout << "���� : " << tStoreWeapon[i].strDesc << endl;
							cout << endl;
						}

						cout << endl;
						cout << STORE_WEAPON_MAX + 1 << ". �ڷΰ���" << endl;
						cout << endl;

						cout << "������ �������� �����ϼ��� : ";
						int iItemChoice;
						cin >> iItemChoice;
						if (cin.fail()) {
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						// �ڷΰ���
						else if (iItemChoice == STORE_ARMOR_MAX + 1) {
							break;
						}

						// ��尡 �����ϸ�
						if (tPlayer.tInventory.iGold < tStoreWeapon[iItemChoice - 1].iPrice)
						{
							cout << "�����ݾ��� �����մϴ�." << endl;
							system("pause");
							continue;
						}

						// �κ��丮�� ��������� �κ��丮�� �ִ´�.
						if (tPlayer.tInventory.iItemCount < INVENTORY_MAX) {
							tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreWeapon[iItemChoice - 1];

							tPlayer.tInventory.iGold -= tStoreWeapon[iItemChoice - 1].iPrice;

							cout << tStoreWeapon[iItemChoice - 1].strName << "�������� �����Ͽ����ϴ�." << endl;
						}
						else { // �κ��丮�� ������� ������ ������� �ʴ´ٴ� ���� ���.
							cout << "�κ��丮�� �� ���� �������� ������ �� �����ϴ�." << endl;
						}
						system("pause");
					}
					break;
				case SM_ARMOR:
					while (true) {
						system("cls");
						cout << "===================== ������ ==================" << endl;

						int i;
						// �Ǹ� ����� �����ش�.
						for (i = 0; i < STORE_ARMOR_MAX; ++i) {
							cout << i + 1 <<". �̸� : " << tStoreArmor[i].strName << "\t���� : " << tStoreArmor[i].strTypeName << endl;
							cout << "���� : " << tStoreArmor[i].iMin << " - " << tStoreArmor[i].iMax << endl;
							cout << "�ǸŰ��� : " << tStoreArmor[i].iPrice << "\t���Ű��� : " << tStoreArmor[i].iSell << endl;
							cout << "���� : " << tStoreArmor[i].strDesc << endl;
							cout << endl;
						}

						cout << endl;
						cout << STORE_ARMOR_MAX + 1 << ". �ڷΰ���" << endl;
						cout << endl;

						cout << "������ �������� �����ϼ��� : ";
						int iItemChoice;
						cin >> iItemChoice;
						if (cin.fail()) {
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						// �ڷΰ���
						else if(iItemChoice == STORE_ARMOR_MAX + 1) {
							break;
						}

						// ��尡 �����ϸ�
						if (tPlayer.tInventory.iGold < tStoreArmor[iItemChoice - 1].iPrice)
						{
							cout << "�����ݾ��� �����մϴ�." << endl;
							system("pause");
							continue;
						}
						
						// �κ��丮�� ��������� �κ��丮�� �ִ´�.
						if (tPlayer.tInventory.iItemCount < INVENTORY_MAX) {
							tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreArmor[iItemChoice - 1];

							tPlayer.tInventory.iGold -= tStoreArmor[iItemChoice - 1].iPrice;

							cout << tStoreArmor[iItemChoice - 1].strName << "�������� �����Ͽ����ϴ�." << endl;
						}
						else { // �κ��丮�� ������� ������ ������� �ʴ´ٴ� ���� ���.
							cout << "�κ��丮�� �� ���� �������� ������ �� �����ϴ�." << endl;
						}
						system("pause");
					}
					break;
				}

			}
			break;
		case MM_INVENTORY:
			/*while (true) {
				system("cls");
				cout << "===================== �κ��丮 ==================" << endl;
			}*/
			break;
		default:
			cout << "�߸� �����Ͽ����ϴ�. " << endl;
		}
	}


	return 0;
}