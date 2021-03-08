// �� ���� ���� ���� ���� ���ÿ� ȹ���ϱ�
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

mutex mut1;
mutex mut2;

void process() {
	// 2���� ���� �� ���ؽ��� �����Ѵ�.

	unique_lock<mutex> lock1(mut1, defer_lock_t()); //derfer_lock_t�� �ν��Ͻ��� ���ڷ� �Ѱ������ν� ������ ���ÿ� ���� �õ����� �ʵ��� �Ѵ�. ����� ����
	unique_lock<mutex> lock2(mut2, defer_lock_t());
	lock(lock1, lock2);
	// ���� ȹ����.
}

int main() {
	process();

	return 0;
}