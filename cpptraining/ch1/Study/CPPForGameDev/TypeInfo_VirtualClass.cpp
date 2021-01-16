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
	CBase* pb = pd; // subtype principle을 위반하지 않는다.

	const type_info& t = typeid(pb);
	const type_info& t1 = typeid(*pb);

	cout << t.name() << "\n"; // class CBase *
	cout << t1.name() << "\n";// class CDerived  <------------------------
	// CDerived의 객체가 만들어졌지만 이름은 class CBase가 출력된다.
	cout << t1.before(t) << "\n";// (1) t1이 t의 상위형인가?
	delete pd;
}


int main() {

	//g();
	f();

	return 0;
}