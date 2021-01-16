#include <iostream>
using namespace std;



// catch 핸들러(Handler)로 전달되었을 때, 스택 되돌리기(stack unwinding) 작업이 일어남.(컴파일러가 이것을 위한 코드를 생성)
// 스택은 지역 변수, 리턴 주소 및 파라미터들을 가지고 있음. 예외가 발생했을 때, 필수적으로 적당한 catch 핸들러에 맞도록 스택의 상태는 복구되야 함.
// (스택에 있는) 영향을 받는 지역 객체는 파괴됨.
//////////////////////////////////////////////////////////////
class CTest {
	int i;
public:
	CTest(int t) {
		i = t;
		cout << "constructor: " << i << "\n";
	}
	virtual ~CTest() {
		cout << "destructorr: " << i << "\n";
	}
};

// 함수 한번에 빠져나오기 테크닉
//////////////////////////////////////////////////////////////
void f() {
	try {
		cout << "f()\n";
		throw "Exit every calls\n";
		cout << "end of f()\n";
	}
	catch (...) {
		throw;
	}
}

void g() {
	try {
		cout << "g()\n";
		f();
		cout << "end g()\n";
	}
	catch (...) {
		throw;
	}
}

void h() {
	try {
		cout << "h()\n";
		g();
		cout << "end h()\n";
	}
	catch (...) {
		throw;
	}
}




int main() {
	
	try {
		CTest i(2), j(3);
		throw "exception";
		cout << "This will be never printed\n";
	}
	catch (...) {
		cout << "catch exception\n";
	}


	// 함수 한번에 빠져나오기
	try {
		h();
		cout << "end of try in main()\n";
	}
	catch (...) {
		cout << "Exited directly from f()\n";
	}


	// 출력
	/*
	h()
	g()
	f()
	Exited directly from f()
	*/

	return 0;
}