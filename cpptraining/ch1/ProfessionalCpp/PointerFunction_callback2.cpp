#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Super;
class A;
class B;

struct Info {
	string menuName;
	void(Super::*callback)();
	Super* pInst;
};

class Super
{
public:
	Super() {}
	virtual ~Super() {}
};

class A : public Super
{
public:
	void A_Func() { cout << "call A\n"; }
	A(){}
	A(Super _super){}
	~A(){}
};

class B : public Super
{
public:
	void B_Func() { cout << "call B\n"; }
	B(){}
	~B(){}
};

void ContextMenu(const vector<Info>& _vecMenuList, int _iSelectIdx)
{
	void(Super::*callback)() = _vecMenuList[_iSelectIdx].callback;
	Super* pInst = _vecMenuList[_iSelectIdx].pInst;
	((*pInst).*callback)(); // 콜백 함수 호출
	cout << "clicked " << _vecMenuList[_iSelectIdx].menuName << " menu\n";
}

int main() {
	vector<Info> vecMenuList;
	A a; B b;
	Info info;

	void(Super::*func)();
	func = (void (Super::*)())(&A::A_Func); // <- ???
	info.callback = func;
	info.pInst = (Super*)&a;
	info.menuName = "A menu";

	vecMenuList.push_back(info);
	ContextMenu(vecMenuList, 0);

	return 0;
}

