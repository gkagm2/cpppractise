#include <iostream>

using namespace std;

#define NAME_SIZE 32

enum MAT_TYPE {
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_END
};

enum MAIN_MENU {
	MM_NONE,
	MM_ADD,
	MM_LOAD,
	MM_SAVE,
	MM_OUTPUT,
	MM_EXIT
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
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}
	return iInput;
}

void InputString(char* pString, int iSize) {
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSize -1);
}

void AddMonster(_tagMonster* pMonsterArr) {
	int iMap = 0;
	while (true) {
		system("cls");
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. �����" << endl;
		cout << "4. ���" << endl;
		cout << "�߰��� ���̵��� �����ϼ��� : ";
		iMap = InputInt();
		if (iMap == 4) {
			return;
		}
		else if(iMap <1 || iMap >4) {
			continue;
		}

		// 1���� �����̱� ������ 1�� ���ҽ��Ѿ� ����� �ε����� �ȴ�.
		--iMap;
		break;
	}
	// �÷��̾� �̸��� �Է¹޴´�.
	cout << "�̸� : ";
	InputString(pMonsterArr[iMap].strName, NAME_SIZE);

	cout << "�ּ� ���ݷ� : ";
	pMonsterArr[iMap].iAttackMin = InputInt();

	cout << "�ִ� ���ݷ� : ";
	pMonsterArr[iMap].iAttackMax = InputInt();

	cout << "�ּ� ���� : ";
	pMonsterArr[iMap].iArmorMin = InputInt();

	cout << "�ִ� ���� : ";
	pMonsterArr[iMap].iArmorMax = InputInt();

	cout << "ü�� : ";
	pMonsterArr[iMap].iHP = InputInt();
	pMonsterArr[iMap].iHPMax = pMonsterArr[iMap].iHP;

	cout << "���� : ";
	pMonsterArr[iMap].iMP = InputInt();
	pMonsterArr[iMap].iMPMax = pMonsterArr[iMap].iMP;

	cout << "���� : ";
	pMonsterArr[iMap].iLevel = InputInt();

	cout << "ȹ�� ����ġ : ";
	pMonsterArr[iMap].iExp = InputInt(); 

	cout << "ȹ�� �ּ� ��� : ";
	pMonsterArr[iMap].iGoldMin = InputInt();

	cout << "ȹ�� �ִ� ��� : ";
	pMonsterArr[iMap].iGoldMax = InputInt();

	cout << "���� �߰� �Ϸ�" << endl;
	system("pause");
}

bool SaveMonster(_tagMonster* pMonsterArr) {
	FILE* pFile = NULL;

	fopen_s(&pFile, "Monster.mst", "wb");

	if (pFile) {
		fwrite(pMonsterArr, sizeof(_tagMonster), MT_END, pFile);
		fclose(pFile);
		return true;
	}
	return false;
}

bool LoadMonster(_tagMonster* pMonsterArr) {
	FILE* pFile = NULL;

	fopen_s(&pFile, "Monster.mst", "rb");

	if (pFile) {
		fread(pMonsterArr, sizeof(_tagMonster), MT_END, pFile);
		fclose(pFile);
		return true;
	}
	return false;
}

void OutputMonster(_tagMonster* pMonster) {
	cout << "=========================== Monster ===================" << endl;
	cout << "�̸� : " << pMonster->strName << "\t���� : " << pMonster->iLevel << endl;
	cout << "���ݷ� : " << pMonster->iAttackMin << " - " << pMonster->iAttackMax <<
		"\t���� : " << pMonster->iArmorMin << " - " << pMonster->iArmorMax << endl;
	cout << "ü�� : " << pMonster->iHP << " / " << pMonster->iHPMax <<
		"\t���� : " << pMonster->iMP << " / /" << pMonster->iMPMax << endl;
	cout << "ȹ�����ġ : " << pMonster->iExp << "\tȹ����" << pMonster->iGoldMin << " - " << pMonster->iGoldMax << endl;
}

void Output(_tagMonster* pMonsterArr) {
	system("cls");
	cout << "========================= Monster =========================" << endl;
	for (int i = 0; i < MT_END; ++i) {
		OutputMonster(&pMonsterArr[i]);
	}
	system("pause");
}

int main() {
	
	_tagMonster tMonster[MT_END] = {};

	while (true) {
		system("cls");
		cout << "1. ���� �߰� " << endl;
		cout << "2. �о����" << endl;
		cout << "3. ����" << endl;
		cout << "4. ���� ���" << endl;
		cout << "5. ����" << endl;
		cout << "�޴��� �����ϼ��� : ";
		int iMenu = InputInt();
		
		if (iMenu == MM_EXIT) {
			break;
		}

		switch (iMenu) {
		case MM_ADD:
			AddMonster(tMonster);
			break;
		case MM_LOAD:
			LoadMonster(tMonster);
			cout << "�ҷ��Խ��ϴ�.";
			system("pause");
			break;
		case MM_SAVE:
			SaveMonster(tMonster);
			cout << "����Ǿ����ϴ�.";
			system("pause");
			break;
		case MM_OUTPUT:
			Output(tMonster);
			break;
		}
	}
	// �ڵ� ���� ���. ������ ���� �ʴ��� ���α׷��� ����� �� �ڵ����� ����ǵ��� �Ѵ�.
	SaveMonster(tMonster);
	
	return 0;
}