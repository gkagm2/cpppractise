#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class T;
class SUPER;
typedef void(SUPER::*SUPER_CALLBACK)(); // (�ֻ��� Ŭ������ SUPER Ŭ���� ����) �Լ� ������
//typedef void(*CALLBACK)(); // �Ϲ� �Լ� ������

struct Info {
	string name;
	SUPER_CALLBACK func;
	SUPER* pInst;
};

class SUPER {
public:
	SUPER() {}
	virtual ~SUPER() {}
};
class T : public SUPER {
public:
	void Add() { cout << "call add\n"; }
	void Minus() { cout << "call minus\n"; }
	T() {}
	virtual ~T() {}
};

class A : public SUPER {
public:
	void Div() { cout << "call div\n"; }
	void Plus() { cout << "call plus\n"; }
};

void ContextMenu(const vector<Info>& _vecList, string strMenuClick) {
	for (int i = 0; i < _vecList.size(); ++i) {
		if(strMenuClick == _vecList[i].name) {
			SUPER* inst = _vecList[i].pInst;
			SUPER_CALLBACK func = _vecList[i].func;
			((*inst).*func)();
		}
	}
}

int main() {
	T t;
	vector<Info> vecfuncList;
	Info info;
	info.name = "add";
	info.pInst = (SUPER*)&t; // �ֻ��� Ŭ������ �̿��ϴ� ������ �ֻ��� Ŭ������ ��ӹ��� Ŭ������ ȣȯ�ǰԲ� �ϱ� ���ؼ� 
	info.func = (SUPER_CALLBACK)&T::Add;

	Info info2;
	info2.name = "minus";
	info2.pInst = (SUPER*)&t;
	info2.func = (SUPER_CALLBACK)&T::Minus;

	A a;
	Info info3;
	info3.name = "plus";
	info3.pInst = (SUPER*)&a;
	info3.func = (SUPER_CALLBACK)&A::Plus;

	Info info4;
	info4.name = "div";
	info4.pInst = (SUPER*)&a;
	info4.func = (SUPER_CALLBACK)&A::Div;

	vecfuncList.push_back(info);
	vecfuncList.push_back(info2);
	vecfuncList.push_back(info3);
	vecfuncList.push_back(info4);

	ContextMenu(vecfuncList,"add");
	ContextMenu(vecfuncList, "div");
	ContextMenu(vecfuncList, "plus");
	ContextMenu(vecfuncList, "minus");
	return 0;
}