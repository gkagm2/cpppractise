#pragma warning(disable:4996)
#include <stdio.h>
#include <memory.h>

class CTest {
public:
	int buffer[10];
public:
	CTest() { memset(buffer, 0, sizeof(buffer)); }
	void Print();
};

void CTest::Print() {
	for (int i = 0; i < sizeof(buffer) / sizeof(buffer[0]); ++i) {
		printf("%d,", buffer[i]);
	}
	printf("\n");
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
