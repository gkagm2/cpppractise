#include <iostream>
using namespace std;

class Parent2 {
public:
	virtual void Print() {
		cout << "Print2\n";
	}
};
class Child2 : public Parent2 {
public:
	virtual void Print() override {
		cout << "Child2\n";
	}
};




class Parent {
public:
	void Print() {
		cout << "Parent\n";
	}
};
class Child : public Parent {
public:
	void Print() {
		cout << "Child\n";
	}
};

int main() {
	
	Parent *pParent = new Child;
	pParent->Print();

	// pParent가 Child* 형으로 변환(다운 캐스팅)이 가능한지 검사한다. dynamic_cast<Child*>(pParent)
	// dynamic_cast는 내부적으로 RIIT정보를 체크하고 변환할 객체에 대한 형식 정보를 비교하는데 이 수행 비용이 커서 느림.
	Child *pChild = dynamic_cast<Child*>(pParent); // 다형식 클래스가 아니므로 에러가 난다.
	
	if (pChild)
		pChild->Print();\
	////////////////////////////////////////////////////

	Parent2 *pParent2 = new Child2;
	pParent2->Parent2::Print();
	pParent2->Print();

	Child2 *pChild2 = dynamic_cast<Child2*>(pParent2); // 부모클래스에서 virtual이 붙은 멤버 함수가 있으면  에러 안남
	pChild2->Print();
	pChild2->Print();

	return 0;
}