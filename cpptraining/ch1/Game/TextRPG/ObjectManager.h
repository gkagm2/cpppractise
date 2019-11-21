#pragma once

#include "value.h"
class CObjectManager {
private:
	// string�� ������ ������ ���Ǽ��� ���� ����ϱ�� �Ѵ�.
	// map�� ù��° template Ÿ�� : key, �ι�° template Ÿ�� : value�� ����.
	// key�� �̿��ؼ� Ž���ϰ� ��. ���� ���� value�� ������ Ÿ���� ���� ����.
	unordered_map<string, class CObj*> m_mapObj;

public:
	bool Init();
	CObj* CreateObject(const string&, OBJECT_TYPE eType);

	CObj* FindObject(const string& strKey);

public:
	DECLARE_SINGLE(CObjectManager)
};