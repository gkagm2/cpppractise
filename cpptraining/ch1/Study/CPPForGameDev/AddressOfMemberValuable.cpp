#include <iostream>
using namespace std;

class CTest {
public:
	int i;
public:
	CTest(int ti) {
		i = ti;
	}
	void Show() {
		cout << i << "\n";
	}
};

int main() {
	CTest t(5), u(6), v(8);

	int* ip = &t.i;
	int CTest::*ipp = &CTest::i; // 멤버 변수의 주소를 이용하면 

	*ip = 10;
	t.*ipp = 20; // *ipp는 CTest의 임의의 객체의 멤버 i(상대 주소)를 참조한다.
	u.*ipp = 30; // 이런식으로 사용 가능.
	t.Show();
	u.Show();
	v.Show();
	return 0;
}