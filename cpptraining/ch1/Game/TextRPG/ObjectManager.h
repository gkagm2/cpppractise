#pragma once

#include "value.h"
class CObjectManager {
private:
	// string이 빠르지 않지만 편의성에 의해 사용하기로 한다.
	// map은 첫번째 template 타입 : key, 두번째 template 타입 : value로 구성.
	// key를 이용해서 탐색하게 됨. 실제 값은 value에 지정된 타입의 값을 저장.
	unordered_map<string, class CObj*> m_mapObj;

public:
	bool Init();
	CObj* CreateObject(const string&, OBJECT_TYPE eType);

	CObj* FindObject(const string& strKey);

public:
	DECLARE_SINGLE(CObjectManager)
};