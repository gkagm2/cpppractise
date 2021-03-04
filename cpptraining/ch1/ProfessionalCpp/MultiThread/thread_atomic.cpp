#include <iostream>
#include <thread>
#include <atomic> // 필요
#include <vector>
using namespace std;


void func(atomic<int>& counter) {
	for (int i = 0; i < 100; ++i) {
		++counter;
		this_thread::sleep_for(std::chrono::milliseconds(1)); // 지연 시키기
	}
}

int main() {
	atomic<int> counter = 0; // atomic을 이용하여 캐시 일관성 문제, 메모리 접근 순서문제, 컴파일러 최적화 부작용 문제 등을 피할 수 있다.
	// 그냥 int 하게 되면 레이스 컨디션 문제가 발생되어 기대 결과값인 1000이 출력되지 않는다.

	vector<thread> threads;

	for (int i = 0; i < 10; ++i)
		threads.push_back(thread{ func, ref(counter) });

	for (auto& t : threads)
		t.join();

	cout << "Result = " << counter << "\n";

	return 0;
}