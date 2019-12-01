#pragma once
#include <iostream>
#include <vector>
#include <list>
//#include <map> // red blakc binary tree�� �����. ������ unordered_map�� �����
#include <unordered_map>
#include <string>
#include <time.h>

// ����� ���� ���
#include "Defines.h"
#include "Flags.h"

using namespace std;

template <typename T>
T Input() {
	T data;
	cin >> data;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		return 0;
	}
	return data;
}

template <typename T>
void Safe_Delete_VecList(T& p) {
	typename T::iterator iter;
	typename T::iterator iterEnd = p.end();

	for (iter = p.begin(); iter != iterEnd; ++iter) {
		SAFE_DELETE(*iter);
	}
	p.clear();
}

template <typename T>
void Safe_Delete_Map(T& p) {
	typename T::iterator iter;
	typename T::iterator iterEnd = p.end();

	for (iter = p.begin(); iter != iterEnd; ++iter) {
		// first : key, second : value
		SAFE_DELETE(*iter->second);
	}
	p.clear();
}

typedef struct tag_CharacterInfo {
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHp;
	int iHpMax;
	int iMp;
	int iMpMax;
	int iLevel;
	int iExp;
}CHARACTERINFO, *PCHARACTERINFO;

// Item info
typedef struct _tagItemInfo {
	ITEM_TYPE eType;
	string strTypeName;
	int iPrice;
	int iSell;
	string strDesc;
}ITEMINFO, *PITEMINFO;