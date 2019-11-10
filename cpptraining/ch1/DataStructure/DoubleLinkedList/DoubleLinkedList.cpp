#include <iostream>
#include "List.h"

using namespace std;

enum MAIN_MENU {
	MM_NONE,
	MM_INSERT,
	MM_DELETE,
	MM_SEARCH,
	MM_OUTPUT,
	MM_EXIT
};



void InitList(LIST* pList) {
	pList->iSize= 0;

	pList->pBegin = new NODE;
	pList->pEnd = new NODE;

	pList->pBegin->pNext = pList->pEnd;
	pList->pEnd->pPrev = pList->pBegin;

	pList->pEnd->pNext = NULL;
	pList->pBegin->pPrev = NULL;
}

int OutputMenu() {
	system("cls");
	cout << "1. �л��߰�" << endl;
	cout << "2. �л�����" << endl;
	cout << "3. �л�Ž��" << endl;
	cout << "4. �л����" << endl;
	cout << "5. ����" << endl;
	cout << "�޴��� �����ϼ��� : ";
	int iInput = InputInt();

	if (iInput < MM_NONE || iInput > MM_EXIT) {
		return MM_NONE;
	}
	return iInput;
}

int main() {
	LIST tList;

	InitList(&tList);
	while (true) {
		int iMenu = OutputMenu();

		if (iMenu == MM_EXIT) {
			break;
		}

		switch (iMenu) {
		case MM_INSERT:
			Push_Back(&tList);
			break;
		case MM_DELETE:
			Delete(&tList);
			break;
		case MM_OUTPUT:
			Output(&tList);
			break;
		case MM_SEARCH:
			Search(&tList);
			break;
		default:
			break;
		}
	}

	DestroyList(&tList);

	return 0;
}
