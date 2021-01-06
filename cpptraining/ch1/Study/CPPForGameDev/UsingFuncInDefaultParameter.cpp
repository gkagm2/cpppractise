#pragma warning(disable:4996)
#include <stdio.h>
#include <memory.h>
using namespace std;

class CTest {
public:
	int buffer[10];
public:
	CTest() { memset(buffer, 0, sizeof(buffer)); }
	CTest(const CTest& copy); // copy constructor
	void Print();
};

void CTest::Print() {
	for (int i = 0; i < sizeof(buffer) / sizeof(buffer[0]); ++i) {
		printf("%d,", buffer[i]);
	}
	printf("\n");
}

// copy constructor
CTest::CTest(const CTest& copy) {
	printf("copy constructor\n");
}

void f(CTest a = CTest()) { // ����Ʈ �Ķ���Ϳ� �Լ� ��� ����
	a.Print();
}

int main() {
	CTest t;

	t.buffer[0] = 32;
	f(t);
	f();

	return 0;
}

/* ����� �� �Ʒ��� ���� ��� ��.
32,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
*/

/* ���� �����ڸ� �̿��ϰ� �Ǹ� �Ʒ��� ���� ��� ��.
copy constructor
-858993460,-858993460,-858993460,-858993460,-858993460,-858993460,16119524,7411696,16119572,7412298,
0,0,0,0,0,0,0,0,0,0,
*/