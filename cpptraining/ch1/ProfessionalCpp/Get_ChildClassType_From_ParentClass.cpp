// � �ڽ� Ŭ���� Ÿ������ �ƴ� ���
// 1. Dynamic_case�� typeid�� �̿��ϸ� �ȴ�. (RTTI�� �̿��Ѵ�.)

#include <iostream>
#include <typeinfo>
using namespace std;

class Base {
public:
	virtual ~Base(){} // RTTI�� �̿��ϱ� ���� virtual �� ����� ���� ���̺��� �ϳ� �����.
};

class Derived1 : public Base {
};

class Derived2 : public Base {

};

void Compare(Base* pBase) {

	cout << "���� Ÿ�� ��� : " << typeid(*pBase).name() << "\n";

	// Ÿ�� ��
	if (typeid(*pBase) == typeid(Derived1)) {
		cout << "���̽��� Derived1�� �θ�\n";
	}
	else if (typeid(*pBase) == typeid(Derived2)) {
		cout << "���̽��� Derived2�� �θ�\n";
	}

	// ���� �� cast�� ������ ����, ���н� null ����
	if (dynamic_cast<Derived1*>(pBase)) {
		cout << "���̽��� Derived1�� �θ�\n";
	}
	else if (dynamic_cast<Derived2*>(pBase)) {
		cout << "���̽��� Derived2�� �θ�\n";
	}
}

int main() {

	Base* pB1 = new Derived1;
	Base* pB2 = new Derived2;

	Compare(pB1);
	Compare(pB2);

	return 0;
}