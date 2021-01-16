#include <iostream>
using namespace std;

int i = 5, j = 2, k = 0;

void f() throw(int) { // 이 함수는 int형의 예외만 던짐
	cout << "f()\n";
	throw 'A'; // g()를 둘러싼 try가 없다면, GPF가 발생
}

void h() {
	try {
		if (k == 0)
			throw k;
		cout << i / k << "\n";
	}
	catch (int k) {
		cout << "nested catch block\n";
		throw; // 예외를 바깥 catch 블럭으로 전파
	}
}

int main() {
	cout << "begin\n";
	try {
		if (j == 100 || j == 0)
			throw "exception: j is 100 or 0\n";
		//f();
		h();
		cout << i / j << "\n";
		cout << "end of try block\n";
	}
	catch (char e) {
		cout << "char catch\n";
	}
	catch (int e) {
		cout << "int catch\n";
	}
	catch (char* e) {
		cout << e << "\n";
	}
	catch (...) {
		cout << "catch anything\n";
	}
	cout << "end\n";

	return 0;
}