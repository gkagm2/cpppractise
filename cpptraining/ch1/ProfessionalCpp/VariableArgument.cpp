// 가변인자
#include <iostream>
#include <stdarg.h> // 가변인자와 관련된 매크로들이 들어있음
using namespace std;

void MyPrint(int args, ...) {
	// ap : argument pointer
	va_list ap; // va_list : 가변 인자 목록. 가변 인자의 메모리 주소를 저장하는 포인터

	va_start(ap, args); // va_start : 가변 인자를 가져올 수 있도록 포인터를 설정
	for (int i = 0; i < args; ++i) {
		int num = va_arg(ap, int); // 가변 인자 포인터에서 특정 자료형 크기만큼 값을 가져옴
		cout << num << " ";
		//cout << num << " ";
	}
	va_end(ap); // 가변 인자 처리가 끝났을 때 포인터 NULL로 초기화

	cout << "\n";
}

int main() {
	MyPrint(0);
	MyPrint(1, 20);
	MyPrint(2, 20, 30);
	MyPrint(3, 20, 30, 40);
	MyPrint(4, 20, 30, 40, 50);

	return 0;
}