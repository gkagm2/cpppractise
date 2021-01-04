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


// 디폴트 변수를 이용할 수 있음.
template<class T, class U, int i = 100>
void f(T x) {
	U buffer[i];
	strcpy(buffer, x);
	cout << buffer << "\n";
}

int main() {
	// 템플릿의 맨 왼쪽 파라미터가 typename or class가 아니라면 타입에 맞는 이터럴 값으로 넣어줘야 함.
	f1<char*, char, 20>("hello world1");

	f<char*, char>("hello world2");

	return 0;
}