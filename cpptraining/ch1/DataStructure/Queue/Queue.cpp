#include <iostream>
#include "Queue.h"

using namespace std;

int main() {

	CQueue<int> queueInt;

	for (int i = 0; i < 100; ++i) {
		queueInt.push(i + 1);
	}

	// FIFO
	while (!queueInt.is_empty()) {
		cout << queueInt.pop() << endl;
	}

	return 0;
}