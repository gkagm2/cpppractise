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

	cout << tBase.before(tDerived) << "\n"; // ��ü b (base)�� d (derived)�� ������(supertype)���� �˻��Ѵ�. (1)
	cout << tDerived.before(tBase) << "\n"; // (0)
	cout << (tBase == tDerived) << "\n"; // ��ü b�� �̸��� ��ü d�� �̸��� ������ �˻��Ѵ�. (0)
}

void f() {
	CDerived* pd = new CDerived;
	CBase* pb = pd; // subtype principle�� �������� �ʴ´�.

	const type_info& t = typeid(pb);
	const type_info& t1 = typeid(*pb);

	cout << t.name() << "\n"; // class CBase *
	cout << t1.name() << "\n";// class CBase
	// CDerived�� ��ü�� ����������� �̸��� class CBase�� ��µȴ�.
	cout << t1.before(t) << "\n";// (1) t1�� t�� �������ΰ�?
	delete pd;
}


int main() {

	//g();
	f();

	return 0;
}