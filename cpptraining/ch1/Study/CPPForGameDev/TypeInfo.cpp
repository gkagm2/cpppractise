#include <iostream>
#include <typeinfo>
using namespace std;

class CBase {
};

class CDerived : public CBase {
};

void g() {
	CBase b;
	CDerived d;

	cout << typeid(b).name() << "\n";
	cout << typeid(d).name() << "\n";

	const type_info & tBase = typeid(b);
	const type_info& tDerived = typeid(d);

	cout << tBase.before(tDerived) << "\n"; // 객체 b (base)가 d (derived)의 상위형(supertype)인지 검사한다. (1)
	cout << tDerived.before(tBase) << "\n"; // (0)
	cout << (tBase == tDerived) << "\n"; // 객체 b의 이름과 객체 d의 이름이 같은지 검사한다. (0)
}

void f() {
	CDerived* pd = new CDerived;
	CBase* pb = pd; // subtype principle을 위반하지 않는다.

	const type_info& t = typeid(pb);
	const type_info& t1 = typeid(*pb);

	cout << t.name() << "\n"; // class CBase *
	cout << t1.name() << "\n";// class CBase
	// CDerived의 객체가 만들어졌지만 이름은 class CBase가 출력된다.
	cout << t1.before(t) << "\n";// (1) t1이 t의 상위형인가?
	delete pd;
}


int main() {

	//g();
	f();

	return 0;
}