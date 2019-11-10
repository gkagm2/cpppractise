#include <iostream>

using namespace std;

enum MAIN_MENU {
	MM_NONE,
	MM_INSERT,
	MM_DELETE,
	MM_SEARCH,
	MM_OUTPUT,
	MM_EXIT
};

#define NAME_SIZE 32

typedef struct _tagStudent {
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
}STUDENT;


typedef struct _tagNode {
	STUDENT tStudent;
	_tagNode* pNext;
}NODE;

typedef struct _tagList
{
	NODE* pBegin;
	NODE* pEnd;
	int iSize;
}LIST;

void InitList(LIST* pList) {
	// 포인터는 초기화할때 NULL(0)으로 초기화해두고 쓰는 것이 좋다.
	pList->pBegin = NULL;
	pList->pEnd = NULL;
	pList->iSize = NULL;
} 

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
	cin.getline(pString, iSize - 1); // 제일 마지막 1바이트는 null로 들어가 한다. 그래야 문자열인것을 알 수 있다.
}

int OutputMenu() {
	system("cls");
	cout << "1. 학생추가" << endl;
	cout << "2. 학생삭제" << endl;
	cout << "3. 학생탐색" << endl;
	cout << "4. 학생출력" << endl;
	cout << "5. 종료" << endl;
	cout << "메뉴를 선택하세요 : ";
	int iInput = InputInt();

	if (iInput < MM_NONE || iInput > MM_EXIT) {
		return MM_NONE;
	}
	return iInput;
}

void Insert(LIST* pList) {
	system("cls");
	cout << "================ 학생추가 =============" << endl;

	STUDENT tStudent = {};

	cout << "이름 : ";
	InputString(tStudent.strName, NAME_SIZE);
	cout << "국어 : ";
	tStudent.iKor = InputInt();

	cout << "영어 : ";
	tStudent.iEng = InputInt();

	cout << "수학 : ";
	tStudent.iMath = InputInt();
	tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
	tStudent.fAvg = tStudent.iTotal / 3.f;

	// 추가할 리스트 노드를 생성한다.
	NODE * pNode = new NODE;

	pNode->pNext = NULL;
	pNode->tStudent = tStudent;

	if (pList->pBegin == NULL) {
		pList->pBegin = pNode;
	}
	else {
		pList->pEnd->pNext = pNode;
	}

	pList->pEnd = pNode;
	++pList->iSize;
}

void ClearList(LIST * pList) {
	NODE* pNode = pList->pBegin;
	while (pNode != NULL) {
		NODE* pNext = pNode->pNext;
		delete pNode;
		pNode = pNext;
	}
	pList->pBegin = NULL;
	pList->pEnd = NULL;
	pList->iSize = 0;
}

void OutputStudent(const STUDENT* pStudent) {
	cout << "이름 : " << pStudent->strName << "\t학번 : " << pStudent->iNumber << endl;
	cout << "국어 : " << pStudent->iKor << "\t영어 : " << pStudent->iEng << endl;
	cout << "수학 : " << pStudent->iMath << endl;
	cout << fixed; // 소수점
	cout.precision(2); // 2개만 출력하게 한다
	cout << "총점 : " << pStudent->iTotal << "\t평균 : " << pStudent->fAvg << endl;
	cout << endl;
}

void Output(LIST * pList) {
	system("cls");
	cout << "=================== 학생출력 ====================" << endl;
	NODE* pNode = pList->pBegin;
	
	while (pNode != NULL) {
		OutputStudent(&pNode->tStudent);
		pNode = pNode->pNext;
	}

	cout << "학생 수 : " << pList->iSize << endl;
	system("pause");
}

void Search(LIST* pList) {
	system("cls");
	cout << "================== 학생탐색 ======================" << endl;

	cout << "탐색할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);
	
	NODE* pNode = pList->pBegin;

	while (pNode != NULL) {
		if (strcmp(pNode->tStudent.strName, strName) == 0) {
			OutputStudent(&pNode->tStudent);
			system("pause");
			return;
		}
		pNode = pNode->pNext;
	}

	// 못찾으면
	cout << "찾을 학생이 없습니다.";
	system("pause");
}

void Delete(LIST* pList) {
	system("cls");
	cout << "===================== 학생삭제 ===================" << endl;

	cout << "삭제할 이름을 입력하세요 : ";
	char strName[NAME_SIZE];
	InputString(strName, NAME_SIZE);

	NODE* pNode = pList->pBegin;
	NODE* pPrev = NULL;

	while (pNode != NULL) {
		if (strcmp(pNode->tStudent.strName, strName) == 0) {
			// 지울 노드의 다음 노드를 얻어온다.
			NODE* pNext = pNode->pNext;
			// 만약 이전 노드가 NULL이라면 제일 첫번째 노드를 지운다.
			if (pPrev == NULL) {
				delete pNode;
				pList->pBegin = pNext;

				if (pNext == NULL) {
					pList->pEnd = NULL;
				}
			}
			else { // 이전 노드가 있을 경우에는 이전 노드의 다음을 지운 노드의 다음노드로 연결해준다.
				delete pNode;
				pPrev->pNext = pNext;

				if (pNext == NULL) {
					pList->pEnd = pPrev;
				}
			}
			cout << strName << "학생 삭제완료" << endl;
			--pList->iSize;
			system("pause");
			return;
		}
		// 해당 학생이 아니라면 현재 노드가 이전노드가 된다.
		pPrev = pNode;
		pNode = pNode->pNext;
	}
	cout << "삭제할 학생을 찾을 수 없습니다. " << endl;
	system("pause");
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
			Insert(&tList);
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

	return 0;
}
