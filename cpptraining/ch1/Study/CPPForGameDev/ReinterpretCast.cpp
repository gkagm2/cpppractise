#include <iostream>
using namespace std;

// reinterpret_cast는 운영체제나 컴파일러에 의존적이거나, 안전하지 않은 형에 대해 형 변환을 한다.
// 이름이 의미하듯, 2개의 서로 다른 형에 대해 완전히 새로운 재번역(reinterpretation)을 시도한다.
// ee) void 형

void func(void *v) {
	// cast from pointer type to integral type.
	int i = reinterpret_cast<int>(v);
	cout << i << "\n";
}

//  func와 같다.
void func2(void *v) {
	int i = (int)v;
	cout << i << "\n";
}

int main() {
	//////////////////////////////
	// cast from an integral type to pointer type.
	func(reinterpret_cast<void *>(5));
	func((void*)5); // 위의 코드와 같다.

	func2((void*)5);
	//////////////////////////////

	typedef void(*INT_TYPE)(void*); // void(*func)(void*) 와 같다
	INT_TYPE pFunc = func;



	pFunc((void*)3);
	pFunc(reinterpret_cast<void*>(10));

	return 0;
}