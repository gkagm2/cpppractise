#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <atomic>
using namespace std;

// ���߰˻� ��ŷ ����
// intialized ������ �� �õ����� �� ��, �� ���� �Ŀ� �� ��, ��� �� ���� �˻簡 ����Ǳ� ������ "���� �˻� ��ŷ ����"�̶�� �Ѵ�.
// ù��° �˻�� �� ������ �ʿ���� ��� �� ������带 ���ϱ� ���� �����̰�, �� ��° �˻�� ù ��° �˻�� �� ���� ���̿� �ٸ� �����尡 ������� ���ϵ��� �ϴ� �����̴�.

// ���Ž� �ڵ忡�� �ε��� �� �ִ�. ���� �˻� ��ŷ�� ���̽� �����, ĳ�� �ϰ��� � ����ϰ� �Ǽ� ���� �ۼ��ϱⰡ ��ƴ�. ���� ���Ӱ� �ڵ带 �ۼ��� ���� �ִ��� ���ؾ� �ϴ� �����̴�.
// ���� �˻� ��ŷ ���� ��� �ܼ��� ���̳� ����� ����, call_once()���� ���� ����ϴ� ���� ����.

// ���� �˻� ��ŷ ������ � ������ �� �� �� �ʱ�ȭ�Ǵ� ���� ������ �� ����Ѵ�.


void initializeSharedResources() {
	// ������ �����忡�� ���� ���� �ڿ� �ʱ�ȭ
	cout << "Shared resources initialized.\n";
}

atomic<bool> initialized(false);
mutex mut;

void func() {
	if (!initialized) {
		unique_lock<mutex> lock(mut);
		if (!initialized) {
			initializeSharedResources();
			initialized = true;
		}
	}

	cout << "OK\n";
}

int main() {
	vector<thread> threads;
	for (int i = 0; i < 5; i++)
		threads.push_back(thread{ func });

	for (auto& t : threads)
		t.join();

	return 0;
}