#include <iostream>
#include "Stack.h"

using namespace std;

int main() {

	CStack<int> stackInt;

	for (int i = 0; i < 100; ++i) {
		stackInt.push(i + 1);
	}
	
	stackInt.clear();

	while (!stackInt.is_empty()) {
		cout << stackInt.pop() << endl;
	}
	return 0;
}