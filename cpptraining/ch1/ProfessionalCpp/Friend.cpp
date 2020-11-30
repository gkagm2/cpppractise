#include <iostream>
using namespace std;

////////////////////////////////////////////////
// Ŭ���� ��ü
class A {
private:
	int m1 =0;
	int m2 =0;
public:
	friend class B; // B�� ��� �޼���� A�� private, protected ���/�޼��忡 �����Ӱ� ���� �� �� �ִ�.
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
// Ŭ���� ��� �Լ�    
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
		// ---------------- - �̰� ��� ����ؾ� �ϳ�..?
	}
};

////////////////////////////////////////////////
// �ܺ� �Լ�

class E {
private:
	int mNum =0;
	friend void OutFunc(E &e);
};

void OutFunc(E &e) {
	e.mNum = 4; // �� �Լ�����  EŬ�����ǿ��� private�� �Ǿ��ִ� mNum�� ������ �� �ִ�.
}

int main() {

	B b;
	b.AccessAClass();
	b.Print();

	C c;
	

	D d;
	return 0;
}
