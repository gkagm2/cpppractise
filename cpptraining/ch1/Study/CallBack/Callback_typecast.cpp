#include <iostream>
using namespace std;

typedef void(*FuncName)(int);

void TestFunc(int i) {
	cout << i << "\n";
}

void TestFunc2(int i) {
	cout << i + i << "\n";
}

int main() {
	FuncName func = TestFunc;
	func(3);

	func = TestFunc2;
	func(7);


	return 0;
}