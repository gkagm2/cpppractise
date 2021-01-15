#include <iostream>
using namespace std;

// #연산자나 ## 연산자는 매크로에서 사용된다.

// # 연산자는 스트링화 연산자이다.
// #은 매크로 함수에 사용되어 매크로 함수의 파라미터를 스트링으로 만드는 역할을 한다.
#define STRING(s) #s

// ## 토큰(token) 연결 연산자이다.
// ##은 매크로 함수에 사용되어 매크로 함수의 파라미터들을 결합하여 하나의 토큰으로 만드는 역할을 하는 연산자다.
#define token(i,j) i##j
#define string(i) lpsz##i

int main() {

	// # 예제
	cout << STRING(hello world) << "\n"; // "hello world"로 바뀜.

	// ## 예제
	int i = 1, j = 2, ij = 3;

	char lpszStr1[] = "hello";
	char string(Str2)[] = "world"; //

	cout << i << " " << j << " " << token(i, j) << "\n"; // token(i, j)는 ij로 바뀜
	cout << lpszStr1 << "\n";
	cout << string(Str1) << "\n"; // string(Str1)은 lpszStr1로 바뀜
	cout << string(Str2) << "\n"; // string(Str2)은 lpszStr2로 바뀜 

	return 0;
}
