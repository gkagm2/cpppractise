#include <iostream>
using namespace std;

////////////////////////////////////////////////
// 클래스 자체
class A {
private:
	int m1 =0;
	int m2 =0;
public:
	friend class B; // B의 모든 메서드는 A의 private, protected 멤버/메서드에 자유롭게 접근 할 수 있다.
};

class B {
private:
	int m1 =0;
	int m2 =0;
	A a;
public:
	void AccessAClass() {
		a.m1 = 3;
		a.m2 = 5;
	}
	void Print() {
		cout << a.m1 << " " <<  a.m2 << " " << m1 << " " << m2;
	}
};

////////////////////////////////////////////////
// 클래스 멤버 함수    
class C {
private:
	int mNum = 0;
public:
	friend void D::Func(C& c); 
};

class D {
private:
	int mNum = 0;
public:
	void Func(C& c) {
		// ---------------- - 이건 어떻게 사용해야 하나..?
	}
};

////////////////////////////////////////////////
// 외부 함수

class E {
private:
	int mNum =0;
	friend void OutFunc(E &e);
};

void OutFunc(E &e) {
	e.mNum = 4; // 이 함수에서  E클래스의에서 private로 되어있는 mNum에 접근할 수 있다.
}

int main() {

	B b;
	b.AccessAClass();
	b.Print();

	C c;
	

	D d;
	return 0;
}
