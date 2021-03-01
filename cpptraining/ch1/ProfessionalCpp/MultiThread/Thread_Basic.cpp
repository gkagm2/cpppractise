// 2021 03 01
#include <iostream>
#include <thread> // �����带 ����ϱ� ���ؼ� �ʿ�
using namespace std;

void counter(int id, int numIter) {
	for (int i = 0; i < numIter; ++i) {
		cout << "Counter " << id << " has value";
		cout << i << "\n";
	}
}

int main() {
	thread t1(counter, 1, 15);
	thread t2(counter, 2, 20);

	t1.join(); 
	t2.join();

	return 0;
}