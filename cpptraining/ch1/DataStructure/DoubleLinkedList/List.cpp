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
	cout << "================ 학생추가 =============" << endl;

	STUDENT tStudent = {};

	cout << "이름 : ";
	InputString(tStudent.strName, NAME_SIZE);

	cout << "학번 : ";
	tStudent.iNumber = InputInt();

	cout << "국어 : ";
	tStudent.iKor = InputInt();

	cout << "영어 : ";
	tStudent.iEng = InputInt();

	cout << "수학 : ";
	tStudent.iMath = InputInt();
	tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
	tStudent.fAvg = tStudent.iTotal / 3.f;

	NODE* pNewNode = new NODE;

	pNewNode->tStudent = tStudent;

	//  새로 추가되는 노드는 End노드의 이전노드와 End노드 사이에 추가해야 한다.
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
	cout << "================== 학생탐색 ======================" << endl;

	cout << "탐색할 이름을 입력하세요 : ";
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

	// 못찾으면
	cout << "찾을 학생이 없습니다.";
	system("pause");
}

void Delete(LIST *pList) 
{
	system("cls");
	cout << "================== 학생삭제 ======================" << endl;

	cout << "삭제할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	NODE* pNode = pList->pBegin->pNext;

	while (pNode != pList->pEnd) {
		if (strcmp(pNode->tStudent.strName, strName) == 0) {
			pNode->pPrev->pNext = pNode->pNext;
			pNode->pNext->pPrev = pNode->pPrev;
			delete pNode;
			--pList->iSize;
			cout << strName << " 학생을 삭제하였습니다." << endl;
			system("pause");
			return;
		}
		pNode = pNode->pNext;
	}

	cout << "삭제할 대상을 찾을 수 없습니다." << endl;
	system("pause");
}

void Output(LIST * pList)
{
	int iMenu;
	while (true) {
		system("cls");
		cout << "=================== 학생출력 ====================" << endl;

		cout << "1. 정방향 출력" << endl;
		cout << "2. 역방향 출력" << endl;
		cout << "메뉴를 선택하세요 : ";
		iMenu = InputInt();

		if (iMenu > OT_NONE || iMenu <= OT_INVERSE) { // 제대로 입력했으면
			break;
		}
	}
	
	NODE* pNode = NULL;

	switch (iMenu) {
	case OT_OUTPUT:
		// 추가되는 노드들은 begin과 end사이에 배치된다.
		pNode = pList->pBegin->pNext;

		while (pNode != pList->pEnd) {
			OutputStudent(&pNode->tStudent);
			pNode = pNode->pNext;
		}
		break;
	case OT_INVERSE:
		// 역방향으로 출력 시 end의 이전 노드를 얻어오고 계속 이전 노드로 진행한다.
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
	cout << "이름 : " << pStudent->strName << "\t학번 : " << pStudent->iNumber << endl;
	cout << "국어 : " << pStudent->iKor << "\t영어 : " << pStudent->iEng << endl;
	cout << "수학 : " << pStudent->iMath << endl;
	cout << fixed; // 소수점
	cout.precision(2); // 2개만 출력하게 한다
	cout << "총점 : " << pStudent->iTotal << "\t평균 : " << pStudent->fAvg << endl;
	cout << endl;
}

void Sort(LIST* pList) {
	system("cls");
	cout << "========================== 학생정렬 ========================" << endl;
	cout << "1. 학번기준" << endl;
	cout << "2. 평균기준" << endl;
	cout << "메뉴를 선택하세요 : ";
	int iInput = InputInt();
	
	if (iInput <= ST_NONE || iInput >= ST_BACK) {
		cout << "잘못 선택하였습니다." << endl;
		system("pause");
		return;
	}

	NODE* pFirst = pList->pBegin->pNext;
	NODE* pSecond = pFirst->pNext;
	STUDENT tTempStudent;

	//Bubble sort
	for (int i = 1; i < pList->iSize; ++i) {
		for (int j = pList->iSize - 1; j > 0; --j) {
			bool bSwap = false;
			switch (iInput) {
			case ST_NUMBER:
				if (pFirst->tStudent.iTotal > pSecond->tStudent.iTotal) {
					bSwap = true;
				}
				break;
			case ST_AVG:
				if (pFirst->tStudent.fAvg > pSecond->tStudent.fAvg) {
					bSwap = true;
				}
				break;
			}

			if (bSwap) {
				NODE* pFirstPrev = pFirst->pPrev;
				NODE* pFirstNext = pFirst->pNext;

				NODE* pSecondPrev = pSecond->pPrev;
				NODE* pSecondNext = pSecond->pNext;

				// 두 노드를 바꿈
				NODE* pTemp = pFirst;
				pFirst = pSecond;
				pSecond = pTemp;


				// 노드의 연결을 바꿔준다.
				pFirstPrev->pNext = pFirst;
				pFirst->pPrev = pFirstPrev;

				pFirst->pNext = pSecond;
				pSecond->pPrev = pFirst;

				pSecond->pNext = pSecondNext;
				pSecondNext->pPrev = pSecond;
			}
			
			pFirst = pFirst->pNext;
			pSecond = pSecond->pNext;
		}
		pFirst = pList->pBegin->pNext;
		pSecond = pFirst->pNext;
	}

	cout << "정렬을 완료하였습니다." << endl;
	system("pause");
}