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
// 첫번째 검사는 락 점유가 필요없는 경우 락 오버헤드를 피하기 위한 역할이고, 두 번째 검사는 첫 번째 검사와 락 점유 사이에 다른 스레드가 끼어들지 못하도록 하는 역할이다.

// 레거시 코드에서 부딪힐 수 있다. 이중 검사 락킹은 레이스 컨디션, 캐시 일관성 등에 취약하고 실수 없이 작성하기가 어렵다. 따라서 새롭게 코드를 작성할 때는 최대한 피해야 하는 패턴이다.
// 이중 검사 락킹 패턴 대신 단순한 락이나 아토믹 변수, call_once()같은 것을 사용하는 것이 좋다.

// 이중 검사 락킹 패턴은 어떤 변수가 단 한 번 초기화되는 것을 보증할 때 사용한다.


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