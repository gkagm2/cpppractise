// 어떤 자식 클래스 타입인지 아는 방법
// 1. Dynamic_case나 typeid를 이용하면 된다. (RTTI를 이용한다.)

#include <iostream>
#include <typeinfo>
using namespace std;

class Base {
public:
	virtual ~Base(){} // RTTI를 이용하기 위해 virtual 로 만들어 가상 테이블을 하나 만든다.
};

class Derived1 : public Base {
};

class Derived2 : public Base {

};

void Compare(Base* pBase) {

	cout << "현재 타입 출력 : " << typeid(*pBase).name() << "\n";

	// 타입 비교
	if (typeid(*pBase) == typeid(Derived1)) {
		cout << "베이스는 Derived1의 부모\n";
	}
	else if (typeid(*pBase) == typeid(Derived2)) {
		cout << "베이스는 Derived2의 부모\n";
	}

	// 성공 시 cast된 포인터 리턴, 실패시 null 리턴
	if (dynamic_cast<Derived1*>(pBase)) {
		cout << "베이스는 Derived1의 부모\n";
	}
	else if (dynamic_cast<Derived2*>(pBase)) {
		cout << "베이스는 Derived2의 부모\n";
	}
}

int main() {

	Base* pB1 = new Derived1;
	Base* pB2 = new Derived2;

	Compare(pB1);
	Compare(pB2);

	return 0;
}