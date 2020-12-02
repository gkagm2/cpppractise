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

	// pParent�� Child* ������ ��ȯ(�ٿ� ĳ����)�� �������� �˻��Ѵ�. dynamic_cast<Child*>(pParent)
	// dynamic_cast�� ���������� RIIT������ üũ�ϰ� ��ȯ�� ��ü�� ���� ���� ������ ���ϴµ� �� ���� ����� Ŀ�� ����.
	Child *pChild = dynamic_cast<Child*>(pParent); // ������ Ŭ������ �ƴϹǷ� ������ ����.
	
	if (pChild)
		pChild->Print();\
	////////////////////////////////////////////////////

	Parent2 *pParent2 = new Child2;
	pParent2->Parent2::Print();
	pParent2->Print();

	Child2 *pChild2 = dynamic_cast<Child2*>(pParent2); // �θ�Ŭ�������� virtual�� ���� ��� �Լ��� ������  ���� �ȳ�
	pChild2->Print();
	pChild2->Print();

	return 0;
}