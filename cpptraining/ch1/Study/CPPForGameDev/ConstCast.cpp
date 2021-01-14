#include <iostream>
using namespace std;

class CTest {
public:
	int  data;
public:
	CTest() { data = 100; }
	void f() const;
};

void CTest::f() const {
	CTest* this2 = const_cast<CTest*>(this); // const, volatile �Ӽ��� �����ش�.
	this2->data += 1; // ������������
	cout << data << "\n";
}

int main() {
	CTest t;
	t.f();
	cout << t.data << "\n";

	return 0;
}