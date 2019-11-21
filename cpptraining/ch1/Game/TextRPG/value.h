#pragma once
#include <iostream>

using namespace std;

// 사용자 정의 헤더
#include "Defines.h"

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