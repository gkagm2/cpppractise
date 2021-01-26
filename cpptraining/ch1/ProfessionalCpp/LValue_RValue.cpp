#include <iostream>
using namespace std;

// 좌측 값
void incr(int& value) {
	cout << "lvalue\n";
	++value;
}

// 우측 값
void incr(int&& value) {
	cout << "rvalue\n";
	++value;
}

void Case1() {
	int a = 10, b = 20;
	
	// 좌측 값 참조
	incr(a);

	// 우측 값 참조
	incr(1 + 3);

	// 우측 값 참조
	incr(a + b);

	// std::move() => 우측 값 참조형 함수를 호출하게 한다.  (rvalue로 static_cast함)
	incr(std::move(a + b));
}

void Case2() {
	/* 안됨
	int& i = 2; // 허용되지 않음. 상수값에 대한 참조
	int a = 2, b = 3;
	int&j = a + b; // 허용되지 않음. 임시 객체에 대한 참조
	*/

	// 우측값 참조를 이용하면 가능함.
	int&& i = 2;
	int a = 2, b = 3;
	int&&j = a + b;
}

int main() {

	Case1();
	Case2();

	return 0;
}