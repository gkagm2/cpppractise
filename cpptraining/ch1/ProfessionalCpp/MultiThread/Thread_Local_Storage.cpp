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

// thread_local ������ �Լ� �ȿ��� ����Ǹ�, static���� ����� ��ó�� �����Ѵ�.
// �� �����帶�� �����ϰ� �������� �����ٴ� �͸� �ٸ���.
// �� ������ �ش� �Լ��� �� �� ȣ��Ǵ� thread_local ������ �ʱ�ȭ�� �� ������� �� �� ���� ����ȴ�.

void DoWork2(int id) {
	thread_local int m;
	k = 0;
	m = 0;
	for (; m < 20; ++m) {
		cout << id << "�������� ���� ��ȣ m : " << m << "\n";
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

	thread t3(DoWork, 3);
	thread t4(DoWork, 4);
	t3.join();
	t4.join();

	return 0;
}