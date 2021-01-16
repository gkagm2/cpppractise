#include <iostream>
#include <typeinfo>
using namespace std;

class CBase {
	virtual void Print() = 0;
};

class CDerived : public CBase {
	virtual void Print() { }
};

void f(){
	CDerived* pd = new CDerived;
	CBase* pb = pd; // subtype principle�� �������� �ʴ´�.

	const type_info& t = typeid(pb);
	const type_info& t1 = typeid(*pb);

	cout << t.name() << "\n"; // class CBase *
	cout << t1.name() << "\n";// class CDerived  <------------------------
	// CDerived�� ��ü�� ����������� �̸��� class CBase�� ��µȴ�.
	cout << t1.before(t) << "\n";// (1) t1�� t�� �������ΰ�?
	delete pd;
}


int main() {

	//g();
	f();

	return 0;
}