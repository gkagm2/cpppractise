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
	CTest* this2 = const_cast<CTest*>(this); // const, volatile 속성을 없애준다.
	this2->data += 1; // 수정가능해짐
	cout << data << "\n";
}

int main() {
	CTest t;
	t.f();
	cout << t.data << "\n";

	return 0;
}