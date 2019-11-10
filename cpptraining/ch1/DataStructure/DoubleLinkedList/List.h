#pragma once

#include <iostream>
using namespace std;

enum OUTPUT_TYPE {
	OT_NONE,
	OT_OUTPUT, // 정방향
	OT_INVERSE // 역방향
};

enum SORT_TYPE {
	ST_NONE,
	ST_NUMBER,
	ST_AVG,
	ST_BACK
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
	_tagNode* pPrev;
	_tagNode* pNext;
}NODE;

typedef struct _tagList
{
	NODE* pBegin;
	NODE* pEnd;
	int iSize;
}LIST;


void ClearList(LIST* pList);
void DestroyList(LIST* pList);
void Push_Back(LIST* pList);
void Push_Front(LIST* pList);
void Search(LIST* pList);
void Delete(LIST *pList);
void Sort(LIST* pList);

void Output(LIST* pList);
void OutputStudent(const STUDENT* pStudent);

static int InputInt() {
	int iInput;
	cin >> iInput;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}

	return iInput;
}

static void InputString(char* pString, int iSize) {
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSize - 1); // 제일 마지막 1바이트는 null로 들어가 한다. 그래야 문자열인것을 알 수 있다.
}