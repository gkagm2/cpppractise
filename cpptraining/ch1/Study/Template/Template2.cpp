#pragma warning(disable:4996)
#include <iostream>
#include <stdlib.h>

using namespace std;

template<class T, class U, int i>
void f1(T x) {
	U buffer[i];
	strcpy(buffer, x);
	cout << buffer << "\n";
}


// 디폴트 변수를 이용할 수 있음 (default 지정자 덕택에 <>만 쓰면 됨. C++은 지원 안한다하네.)
template<class T, class U, int i = 100>
void f(T x) {
	U buffer[i];
	strcpy(buffer, x);
	cout << buffer << "\n";
}

////////////////////////////////////////////

// 템플릿 디폴트 지정
template<class T = int, int size = 10>
class C1 {
public:
	T data[size];
	
	CTest() {}
	void Set(int i, T d) { data[i] = d; }
	T Get(T i) { return data[i]; }
};




int main() {
	// 템플릿의 맨 왼쪽 파라미터가 typename or class가 아니라면 타입에 맞는 이터럴 값으로 넣어줘야 함.
	f1<char*, char, 20>("hello world1");

	f<char*, char>("hello world2");

	// C1 < > c1; // default 지정자 덕택에 <>만 쓰면 됨. C++은 지원 안한다하네.

	return 0;
}