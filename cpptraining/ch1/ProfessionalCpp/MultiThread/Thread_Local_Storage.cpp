// ������ ���� �����(Thread local storage)
#include <iostream>
#include <thread>
using namespace std;


// �ڽŸ��� ������ ���� ���������� �۾�. �ش� �������� �����尡 ����ִ� ���� ��� ����.
// �� �����忡 ���� �� ���� ���� ��. (�� �����帶�� ���� ������ ������)
thread_local int n; // ������ ���÷� ����ؾ� �� ������ thread_local�� ǥ��.

int k; // ��� �����尡 �� �ϳ��� ������ ����


void DoWork(int id) {
	k = 0;
	n = 0;
	for (; n < 20; ++n) {
		cout << id << "�������� ���� ��ȣ n : " << n << "\n";
	}
	for (; k < 20; ++k) {
		cout << id << "�������� ���� ���� k : " << k << "\n";
	}
}

int main() {

	thread t1(DoWork, 1);
	thread t2(DoWork, 2);
	t1.join();
	t2.join();

	return 0;
}