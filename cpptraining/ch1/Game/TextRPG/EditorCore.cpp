#include "EditorCore.h"
#include "EditorMonster.h"
#include "EditorItem.h"

DEFINITION_SINGLE(CEditorCore)

enum EDIT_MENU {
	EM_NONE,
	EM_MONSTER,
	EM_ITEM,
	EM_EXIT
};

CEditorCore::CEditorCore() {

}

CEditorCore::~CEditorCore() {
	DESTROY_SINGLE(CEditorMonster);
	DESTROY_SINGLE(CEditorItem);
}

bool CEditorCore::Init()
{
	if (!GET_SINGLE(CEditorMonster)->Init()) {
		return false;
	}
	if (!GET_SINGLE(CEditorItem)->Init()) {
		return false;
	}

	return true;
}

void CEditorCore::Run()
{
	while (true) {
		switch (OutputMenu()) {
		case EM_MONSTER:
			GET_SINGLE(CEditorMonster)->Run();
			break;

		case EM_ITEM:
			GET_SINGLE(CEditorItem)->Run();
			break;

		case EM_EXIT:
			return;
		}
	}
}

int CEditorCore::OutputMenu()
{
	system("cls");
	cout << "1. ���� ����" << endl;
	cout << "2. ������ ����" << endl;
	cout << "3. ����" << endl;
	cout << "�޴��� �����ϼ��� : ";
	int iMenu = Input<int>();

	if (iMenu <= EM_NONE || iMenu > EM_EXIT) {
		return EM_NONE;
	}
	
	return iMenu;
}