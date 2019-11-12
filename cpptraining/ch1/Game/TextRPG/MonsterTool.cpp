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
		cout << "1. 쉬움" << endl;
		cout << "2. 보통" << endl;
		cout << "3. 어려움" << endl;
		cout << "4. 취소" << endl;
		cout << "추가할 난이도를 선택하세요 : ";
		iMap = InputInt();
		if (iMap == 4) {
			return;
		}
		else if(iMap <1 || iMap >4) {
			continue;
		}

		// 1부터 시작이기 때문에 1을 감소시켜야 사냥터 인덱스가 된다.
		--iMap;
		break;
	}
	// 플레이어 이름을 입력받는다.
	cout << "이름 : ";
	InputString(pMonsterArr[iMap].strName, NAME_SIZE);

	cout << "최소 공격력 : ";
	pMonsterArr[iMap].iAttackMin = InputInt();

	cout << "최대 공격력 : ";
	pMonsterArr[iMap].iAttackMax = InputInt();

	cout << "최소 방어력 : ";
	pMonsterArr[iMap].iArmorMin = InputInt();

	cout << "최대 방어력 : ";
	pMonsterArr[iMap].iArmorMax = InputInt();

	cout << "체력 : ";
	pMonsterArr[iMap].iHP = InputInt();
	pMonsterArr[iMap].iHPMax = pMonsterArr[iMap].iHP;

	cout << "마나 : ";
	pMonsterArr[iMap].iMP = InputInt();
	pMonsterArr[iMap].iMPMax = pMonsterArr[iMap].iMP;

	cout << "레벨 : ";
	pMonsterArr[iMap].iLevel = InputInt();

	cout << "획득 경험치 : ";
	pMonsterArr[iMap].iExp = InputInt(); 

	cout << "획득 최소 골드 : ";
	pMonsterArr[iMap].iGoldMin = InputInt();

	cout << "획득 최대 골드 : ";
	pMonsterArr[iMap].iGoldMax = InputInt();

	cout << "몬스터 추가 완료" << endl;
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
	cout << "이름 : " << pMonster->strName << "\t레벨 : " << pMonster->iLevel << endl;
	cout << "공격력 : " << pMonster->iAttackMin << " - " << pMonster->iAttackMax <<
		"\t방어력 : " << pMonster->iArmorMin << " - " << pMonster->iArmorMax << endl;
	cout << "체력 : " << pMonster->iHP << " / " << pMonster->iHPMax <<
		"\t마나 : " << pMonster->iMP << " / /" << pMonster->iMPMax << endl;
	cout << "획득경험치 : " << pMonster->iExp << "\t획득골드" << pMonster->iGoldMin << " - " << pMonster->iGoldMax << endl;
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
		cout << "1. 몬스터 추가 " << endl;
		cout << "2. 읽어오기" << endl;
		cout << "3. 저장" << endl;
		cout << "4. 몬스터 출력" << endl;
		cout << "5. 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
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
			cout << "불러왔습니다.";
			system("pause");
			break;
		case MM_SAVE:
			SaveMonster(tMonster);
			cout << "저장되었습니다.";
			system("pause");
			break;
		case MM_OUTPUT:
			Output(tMonster);
			break;
		}
	}
	// 자동 저장 기능. 저장을 하지 않더라도 프로그램이 종료될 때 자동으로 저장되도록 한다.
	SaveMonster(tMonster);
	
	return 0;
}