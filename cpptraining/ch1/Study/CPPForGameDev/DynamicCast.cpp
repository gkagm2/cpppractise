#include <iostream>
using namespace std;

// dynamic_cast�� polymorphic Ŭ������ ���� �����Ѵ�.
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
	// dynamic_cast�� unsafe�ϸ� NULL�� �����Ѵ�.
	CDerived1* d1 = dynamic_cast<CDerived1*>(b);
	if (d1) // d1 �� NULL�� ������ CBase���� �Դ��� CDerived2�̱� �����̴�.
		d1->Print();
	CDerived2* d2 = dynamic_cast<CDerived2*>(b);
	if (d2)
		d2->Print();
}

// C ������ ĳ���� 
void f_C_Type(CBase* b) {
	CDerived1* d1 = (CDerived1*)b; // unsafe (���� ����)
	if (d1)
		d1->Print(); // ���� ��
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