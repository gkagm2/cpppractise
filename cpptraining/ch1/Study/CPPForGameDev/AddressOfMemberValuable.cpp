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
	int CTest::*ipp = &CTest::i; // ��� ������ �ּҸ� �̿��ϸ� 

	*ip = 10;
	t.*ipp = 20; // *ipp�� CTest�� ������ ��ü�� ��� i(��� �ּ�)�� �����Ѵ�.
	u.*ipp = 30; // �̷������� ��� ����.
	t.Show();
	u.Show();
	v.Show();
	return 0;
}