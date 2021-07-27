#include <iostream>
using namespace std;

int TestFunc(int i, float f) {
	return i + (int)f;
}

int main() {
	int(&funcName)(int, float) = TestFunc;

	int result = funcName(3, 5.5f);
	cout << result << "\n";

	return 0;
}