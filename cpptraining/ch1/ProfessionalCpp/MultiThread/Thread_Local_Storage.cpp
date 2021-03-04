// 스레드 로컬 저장소(Thread local storage)
#include <iostream>
#include <thread>
using namespace std;


// 자신만의 고유한 변수 복제본으로 작업. 해당 복제본은 스레드가 살아있는 동안 계속 유지.
// 각 스레드에 대해 한 번씩 수행 됨. (각 스레드마다 각자 고유한 복제본)
thread_local int n; // 스레드 로컬로 사용해야 할 변수를 thread_local로 표시.

int k; // 모든 스레드가 단 하나의 변수를 공유


void DoWork(int id) {
	k = 0;
	n = 0;
	for (; n < 20; ++n) {
		cout << id << "스레드의 고유 번호 n : " << n << "\n";
	}
	for (; k < 20; ++k) {
		cout << id << "스레드의 공유 변수 k : " << k << "\n";
	}
}

int main() {

	thread t1(DoWork, 1);
	thread t2(DoWork, 2);
	t1.join();
	t2.join();

	return 0;
}