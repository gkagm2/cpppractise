#pragma once
#include <iostream>
#include <vector>
#include <list>
//#include <map> // red blakc binary tree를 사용함. 느려서 unordered_map을 사용함
#include <unordered_map>
#include <string>
using namespace std;

// 사용자 정의 헤더
#include "Defines.h"
#include "Flags.h"

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