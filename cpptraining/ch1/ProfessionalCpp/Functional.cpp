#include <iostream>
#include <string>
#include <functional>
using namespace std;

typedef function<int(int)> CALLBACK;


int Func(int a) {
	return a + 10;
}

bool Add(float a, float b) {
	if (a > b)
		return true;
	return false;
}

int main() {
	CALLBACK f;
	f = Func;
	cout << f(10) << "\n";

	function<bool(float, float)> callback = Add;
	cout << callback(1.f, 2.f) << "\n";
	return 0;
}
