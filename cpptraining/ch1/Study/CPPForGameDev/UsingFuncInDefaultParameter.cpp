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

void f(CTest a = CTest()) { // 디폴트 파라미터에 함수 사용 가능
	a.Print();
}

int main() {
	CTest t;

	t.buffer[0] = 32;
	f(t);
	f();

	return 0;
}

/* 사용할 때 아래와 같이 출력 됨.
32,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
*/

/* 복사 생성자를 이용하게 되면 아래와 같이 출력 됨.
copy constructor
-858993460,-858993460,-858993460,-858993460,-858993460,-858993460,16119524,7411696,16119572,7412298,
0,0,0,0,0,0,0,0,0,0,
*/