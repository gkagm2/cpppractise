#include "List.h"


void ClearList(LIST * pList)
{
}

void DestroyList(LIST * pList)
{
	NODE* pNode = pList->pBegin;

	while (pNode != NULL) {
		NODE* pNext = pNode->pNext;
		delete pNode;
		pNode = pNext;
	}

	pList->iSize = 0;
	pList->pBegin = NULL;
	pList->pEnd = NULL;
}

void Push_Back(LIST* pList)
{
	system("cls");
	cout << "================ �л��߰� =============" << endl;

	STUDENT tStudent = {};

	cout << "�̸� : ";
	InputString(tStudent.strName, NAME_SIZE);
	cout << "���� : ";
	tStudent.iKor = InputInt();

	cout << "���� : ";
	tStudent.iEng = InputInt();

	cout << "���� : ";
	tStudent.iMath = InputInt();
	tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
	tStudent.fAvg = tStudent.iTotal / 3.f;

	NODE* pNewNode = new NODE;

	pNewNode->tStudent = tStudent;

	//  ���� �߰��Ǵ� ���� End����� �������� End��� ���̿� �߰��ؾ� �Ѵ�.
	NODE* pPrev = pList->pEnd->pPrev;
	pPrev->pNext = pNewNode;
	pNewNode->pPrev = pPrev;

	pNewNode->pNext = pList->pEnd;
	pList->pEnd->pPrev = pNewNode;
	++pList->iSize;
}
void Push_Front(LIST* pList)
{

}

void Search(LIST* pList) {
	system("cls");
	cout << "================== �л�Ž�� ======================" << endl;

	cout << "Ž���� �̸��� �Է��ϼ��� : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	NODE* pNode = pList->pBegin->pNext;

	while (pNode != pList->pEnd) {
		if (strcmp(pNode->tStudent.strName, strName) == 0) {
			OutputStudent(&pNode->tStudent);
			system("pause");
			return;
		}
	}

	// ��ã����
	cout << "ã�� �л��� �����ϴ�.";
	system("pause");
}

void Delete(LIST *pList) 
{
	system("cls");
	cout << "================== �л����� ======================" << endl;

	cout << "������ �̸��� �Է��ϼ��� : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	NODE* pNode = pList->pBegin->pNext;

	while (pNode != pList->pEnd) {
		if (strcmp(pNode->tStudent.strName, strName) == 0) {
			pNode->pPrev->pNext = pNode->pNext;
			pNode->pNext->pPrev = pNode->pPrev;
			delete pNode;
			--pList->iSize;
			cout << strName << " �л��� �����Ͽ����ϴ�." << endl;
			system("pause");
			return;
		}
		pNode = pNode->pNext;
	}

	cout << "������ ����� ã�� �� �����ϴ�." << endl;
	system("pause");
}

void Output(LIST * pList)
{
	int iMenu;
	while (true) {
		system("cls");
		cout << "=================== �л���� ====================" << endl;

		cout << "1. ������ ���" << endl;
		cout << "2. ������ ���" << endl;
		cout << "�޴��� �����ϼ��� : ";
		iMenu = InputInt();

		if (iMenu > OT_NONE || iMenu <= OT_INVERSE) { // ����� �Է�������
			break;
		}
	}
	
	NODE* pNode = NULL;

	switch (iMenu) {
	case OT_OUTPUT:
		// �߰��Ǵ� ������ begin�� end���̿� ��ġ�ȴ�.
		pNode = pList->pBegin->pNext;

		while (pNode != pList->pEnd) {
			OutputStudent(&pNode->tStudent);
			pNode = pNode->pNext;
		}
		break;
	case OT_INVERSE:
		// ���������� ��� �� end�� ���� ��带 ������ ��� ���� ���� �����Ѵ�.
		pNode = pList->pEnd->pPrev;

		while (pNode != pList->pBegin) {
			OutputStudent(&pNode->tStudent);
			pNode = pNode->pPrev;
		}
		break;
	}
	system("pause");
}

void OutputStudent(const STUDENT* pStudent)
{
	cout << "�̸� : " << pStudent->strName << "\t�й� : " << pStudent->iNumber << endl;
	cout << "���� : " << pStudent->iKor << "\t���� : " << pStudent->iEng << endl;
	cout << "���� : " << pStudent->iMath << endl;
	cout << fixed; // �Ҽ���
	cout.precision(2); // 2���� ����ϰ� �Ѵ�
	cout << "���� : " << pStudent->iTotal << "\t��� : " << pStudent->fAvg << endl;
	cout << endl;
}
