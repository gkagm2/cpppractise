#include <iostream>
#include <thread>
using namespace std;

int main() {
	int id = 1;
	int numIterations = 5;
	thread t1([id, numIterations] { // Thread�� �͸��Լ��� �߸���.
		for (int i = 0; i < numIterations; ++i) {
			cout << "Counter " << id << " has value ";
			cout << i << "\n";
		}
	});
	t1.join();

	return 0;
}