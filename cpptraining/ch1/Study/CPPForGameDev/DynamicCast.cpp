#include <iostream>
using namespace std;

// dynamic_cast는 polymorphic 클래스에 대해 동작한다.
class CBase {
	virtual void Print() = 0;
};

class CDerived1 : public CBase {
private:
	int a;
public:
	CDerived1() { a = 1; }
	void Print() { cout << a << "\n"; }
};

class CDerived2 : public CBase {
private:
	int b;
public:
	CDerived2() { b = 2; }
	void Print() { cout << b << "\n"; }
};

void f(CBase* b) {
	// dynamic_cast는 unsafe하면 NULL을 리턴한다.
	CDerived1* d1 = dynamic_cast<CDerived1*>(b);
	if (d1) // d1 은 NULL인 이유가 CBase에서 왔던게 CDerived2이기 때문이다.
		d1->Print();
	CDerived2* d2 = dynamic_cast<CDerived2*>(b);
	if (d2)
		d2->Print();
}

// C 형식의 캐스팅 
void f_C_Type(CBase* b) {
	CDerived1* d1 = (CDerived1*)b; // unsafe (논리적 에러)
	if (d1)
		d1->Print(); // 실행 됨
	CDerived2* d2 = (CDerived2*)b;
	if (d2)
		d2->Print();
}

int main() {
	CDerived2 d;

	f(&d);
	// result
	// 2


	f_C_Type(&d);
	// result
	// 2
	// 2

	return 0;
}