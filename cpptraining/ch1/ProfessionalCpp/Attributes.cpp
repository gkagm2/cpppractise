// Attrubutes
// 벤더 속성

#include <iostream>
using namespace std;


// 함수가 호출된 지점으로 절대 리턴하지 않는다는것을 의미함. (이런 종류의 함수는 보통 프로그램이나 스레드를 종료시켜버리거나 익셉션을 발생시킨다.
[[noreturn]]
void func1() {
	throw 1;
}

// 당장은 사용할 수 있지만 앞으로 사용 중단 안내될 기능임을 표시.
// [[deprecated("안전하지 않은 메소드")]] 
[[deprecated]]
void func2() {
	cout << "ee";
}

int main() {

	try {
		func1();
	}
	catch (int e) {
		cout << e << "\n";
	}

	func2();

	return 0;
}