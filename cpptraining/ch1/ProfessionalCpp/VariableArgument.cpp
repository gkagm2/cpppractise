// 가변인자
#include <iostream>
#include <stdarg.h> // 가변인자와 관련된 매크로들이 들어있음
using namespace std;

// 정수형의 가변 인자 함수
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

// 자료형이 다른 가변 인자 함수 만들기
/*
정수(int) : 'i'
실수(double) : 'd'
실수(float) : 'f'
문자(char) : 'c'
문자열(char *) : 's'
*/
void MyPrint2(char *types, ...) {
	va_list ap;
	int i = 0;

	va_start(ap, types);
	while (types[i] != '\0') {
		switch (types[i]) {
		case 'i':
			cout << va_arg(ap, int) << " ";
			break;
		case 'd':
			cout << va_arg(ap, double) << " ";
			break;
		case 'c':
			cout << va_arg(ap, char) << " ";
			break;
		case 's':
			cout << va_arg(ap, char *) << " "; 
			break;
		default:
			break;
		}
		++i;
	}
	va_end(ap);
	cout << "\n";
}


int main() {
	MyPrint(0);
	MyPrint(1, 20);
	MyPrint(2, 20, 30);
	MyPrint(3, 20, 30, 40);
	MyPrint(4, 20, 30, 40, 50);

	// 자료형이 다른 가변 인자 함수
	MyPrint2("i", 10);
	MyPrint2("ci", 'a', 10);
	MyPrint2("dci", 3.46, 'a', 10);
	MyPrint2("sdci", "Hello world", 3.46, 'a', 10); // "Hello world"는 리터럴이기 때문에 문자열 그대로 들어가는게 아니라 문자열의 주소가 들어간다.

	return 0;
}