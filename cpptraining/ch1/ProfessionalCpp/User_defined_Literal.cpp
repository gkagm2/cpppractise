#include <iostream>
#include <complex>
#include <typeinfo>
using namespace std;

//C++11부터 프로그래머가 자신만의 리터럴을 정의할 수 있게 해준다.'

// 사용자의 정의 리터럴은 밑줄로 시작하고 리터럴 연산자를 구현함으로써 사용할 수 있다.

// 리터럴 오퍼레이터는 미가공 모드(raw node)와 가공 모드(cooked mode)가 있다.

// 미가공 모드에서는 리터럴 연산자가 일련의 문자를 받게 되고 가공 모드에서는 해석된 특정 타입의 값을 받게 된다.

// 예를 들어 C++ 리터럴 123이 있다고 하면 미가공 모드에서는 리터럴 연산자가 문자열 '1','2','3'을 받고, 가공 모드에서는 int 타입 값 123을 받게 된다.
// 또 다른 예는 C++ 리터럴 0x23은 미가공 모드에서는 '0','x','2','3'을, 가공 모드에서는 int 타입 값 35를 받는다.
// 또 C++ 리터럴 3.14는 미가공 모드게서는 '3','.','1','4'를, 가공 모드에서는 부동소수점값 3.14를 받는다.

// 가공 모드 리터럴 연산자는 다음 조건을 갖추어야 한다.
/*
 숫자값을 처리하려면 unsigned long long, long double, char, wchar_t, char16_t, char32_t 중 하나를 파라미터 타입으로 이용한다.

// 또는 문자 배열과 그 배열의 크기를 파라미터로 선언하여 문자열을 처리해야 한다. 예를 들어 'const char* str, size_t len'과 같이 파라미터를 선언한다.
*/

// 표준 사용자 정의 리터럴
// C++14에서는 아래와 같은 표준 사용자 정의 리터럴을 지원하고 있다.
// 's' 첨자는 std::string타입 리터럴을 의미한다. 예를 들면 아래의 auto 변수는 std::string으로 취급된다.
// auto myString = "Hello world"s;

// 'h', 'min', 'ms', 'us', 'ns'는 날짜 데이터 타입 std::chrono::duration의 시간 간격을 의미한다.
// 예를 들면 auto myDuration =42min;

// 'i', 'il', 'if'는 각각 복소수 데이터 타입 complex<double>, complex<long double>, complex<float>를 의미한다. 
// 예를 들면 auto myComplexNumber = 1.3i;  (double type)



// str::string 데이터 타입으로 정의 (가공 모드 리터럴 연산자 구현)
std::string operator""_s(const char* str, size_t len) {
	return std::string(str, len);
}

// _i 리터럴을 이용해서 복소수를 정의
std::complex<double> operator"" _i(long double d) {
	return std::complex<double>(0, d);
}

int main() {
	std::string str1 = "Hello world"_s; // 이 리터럴은 str2는 std::string 타입을 가진다.
	// _s 리터럴을 사용하지 않으면 auto 타입의 변환 룰에 의해 const char*로 해석된다.
	auto str3 = "Hello world2"; // str3은 const char* 타입을 가짐.
	auto str4 = "Hello world3"_s; // _s를 사용하여 string 타입으로 가지게 함.

	cout << typeid(str1).name() << "\n"; // class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >

	cout << typeid(str3).name() << "\n"; // char const *

	cout << typeid(str4).name() << "\n"; // class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >

	/////////
	std::complex<double> c1 = 9.634_i;
	auto c2 = 1.23_i; // std::complex<double> 타입을 가짐

	cout << typeid(c1).name() << "\n"; // class std::complex<double>
	cout << typeid(c2).name() << "\n"; // class std::complex<double>


	return 0;
}