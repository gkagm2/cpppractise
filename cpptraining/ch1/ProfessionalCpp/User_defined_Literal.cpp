#include <iostream>
#include <complex>
#include <typeinfo>
using namespace std;

//C++11���� ���α׷��Ӱ� �ڽŸ��� ���ͷ��� ������ �� �ְ� ���ش�.'

// ������� ���� ���ͷ��� ���ٷ� �����ϰ� ���ͷ� �����ڸ� ���������ν� ����� �� �ִ�.

// ���ͷ� ���۷����ʹ� �̰��� ���(raw node)�� ���� ���(cooked mode)�� �ִ�.

// �̰��� ��忡���� ���ͷ� �����ڰ� �Ϸ��� ���ڸ� �ް� �ǰ� ���� ��忡���� �ؼ��� Ư�� Ÿ���� ���� �ް� �ȴ�.

// ���� ��� C++ ���ͷ� 123�� �ִٰ� �ϸ� �̰��� ��忡���� ���ͷ� �����ڰ� ���ڿ� '1','2','3'�� �ް�, ���� ��忡���� int Ÿ�� �� 123�� �ް� �ȴ�.
// �� �ٸ� ���� C++ ���ͷ� 0x23�� �̰��� ��忡���� '0','x','2','3'��, ���� ��忡���� int Ÿ�� �� 35�� �޴´�.
// �� C++ ���ͷ� 3.14�� �̰��� ���Լ��� '3','.','1','4'��, ���� ��忡���� �ε��Ҽ����� 3.14�� �޴´�.

// ���� ��� ���ͷ� �����ڴ� ���� ������ ���߾�� �Ѵ�.
/*
 ���ڰ��� ó���Ϸ��� unsigned long long, long double, char, wchar_t, char16_t, char32_t �� �ϳ��� �Ķ���� Ÿ������ �̿��Ѵ�.

// �Ǵ� ���� �迭�� �� �迭�� ũ�⸦ �Ķ���ͷ� �����Ͽ� ���ڿ��� ó���ؾ� �Ѵ�. ���� ��� 'const char* str, size_t len'�� ���� �Ķ���͸� �����Ѵ�.
*/

// ǥ�� ����� ���� ���ͷ�
// C++14������ �Ʒ��� ���� ǥ�� ����� ���� ���ͷ��� �����ϰ� �ִ�.
// 's' ÷�ڴ� std::stringŸ�� ���ͷ��� �ǹ��Ѵ�. ���� ��� �Ʒ��� auto ������ std::string���� ��޵ȴ�.
// auto myString = "Hello world"s;

// 'h', 'min', 'ms', 'us', 'ns'�� ��¥ ������ Ÿ�� std::chrono::duration�� �ð� ������ �ǹ��Ѵ�.
// ���� ��� auto myDuration =42min;

// 'i', 'il', 'if'�� ���� ���Ҽ� ������ Ÿ�� complex<double>, complex<long double>, complex<float>�� �ǹ��Ѵ�. 
// ���� ��� auto myComplexNumber = 1.3i;  (double type)



// str::string ������ Ÿ������ ���� (���� ��� ���ͷ� ������ ����)
std::string operator""_s(const char* str, size_t len) {
	return std::string(str, len);
}

// _i ���ͷ��� �̿��ؼ� ���Ҽ��� ����
std::complex<double> operator"" _i(long double d) {
	return std::complex<double>(0, d);
}

int main() {
	std::string str1 = "Hello world"_s; // �� ���ͷ��� str2�� std::string Ÿ���� ������.
	// _s ���ͷ��� ������� ������ auto Ÿ���� ��ȯ �꿡 ���� const char*�� �ؼ��ȴ�.
	auto str3 = "Hello world2"; // str3�� const char* Ÿ���� ����.
	auto str4 = "Hello world3"_s; // _s�� ����Ͽ� string Ÿ������ ������ ��.

	cout << typeid(str1).name() << "\n"; // class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >

	cout << typeid(str3).name() << "\n"; // char const *

	cout << typeid(str4).name() << "\n"; // class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >

	/////////
	std::complex<double> c1 = 9.634_i;
	auto c2 = 1.23_i; // std::complex<double> Ÿ���� ����

	cout << typeid(c1).name() << "\n"; // class std::complex<double>
	cout << typeid(c2).name() << "\n"; // class std::complex<double>


	return 0;
}