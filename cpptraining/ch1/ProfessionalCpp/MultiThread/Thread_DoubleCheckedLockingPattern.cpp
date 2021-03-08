#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <atomic>
using namespace std;

// 이중검사 락킹 패턴
// intialized 변수를 락 시도전에 한 번, 락 점유 후에 한 번, 모두 두 번의 검사가 수행되기 때문에 "이중 검사 락킹 패턴"이라고 한다.
// 첫번ㅉ 검사는 락 점유가 필요없는 경우 락 오버헤드를 피하기 위한 역할이고, 두 번째 검사는 첫 번째 검사와 락 점유 사이에 다른 스레드가 끼어들지 못하도록 하는 역할이다.


void initializeSharedResources() {
	// 복수의 스레드에서 사용될 공유 자원 초기화
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