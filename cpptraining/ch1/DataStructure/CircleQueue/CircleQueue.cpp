#include <iostream>
#include "CircleQueue.h"

using namespace std;

int main() {
	// Circle Queue
	CCircleQueue<int, 10> circleQueue;

	for (int i = 0; i < 10; ++i) {
		circleQueue.push(i + 1);
	}

	for (int i = 0; i < 3; ++i) {
		cout << circleQueue.pop() << endl;
	}

	for (int i = 0; i < 4; ++i) {
		circleQueue.push(i + 10);
	}

	cout << " all of pop" << endl;
	while (!circleQueue.is_empty()) {
		cout << circleQueue.pop() << endl;
	}

	return 0;
}

