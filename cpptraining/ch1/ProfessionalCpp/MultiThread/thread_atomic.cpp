#include <iostream>
#include <thread>
#include <atomic> // �ʿ�
#include <vector>
using namespace std;


void func(atomic<int>& counter) {
	for (int i = 0; i < 100; ++i) {
		++counter;
		this_thread::sleep_for(std::chrono::milliseconds(1)); // ���� ��Ű��
	}
}

int main() {
	atomic<int> counter = 0; // atomic�� �̿��Ͽ� ĳ�� �ϰ��� ����, �޸� ���� ��������, �����Ϸ� ����ȭ ���ۿ� ���� ���� ���� �� �ִ�.
	// �׳� int �ϰ� �Ǹ� ���̽� ����� ������ �߻��Ǿ� ��� ������� 1000�� ��µ��� �ʴ´�.

	vector<thread> threads;

	for (int i = 0; i < 10; ++i)
		threads.push_back(thread{ func, ref(counter) });

	for (auto& t : threads)
		t.join();

	cout << "Result = " << counter << "\n";

	return 0;
}