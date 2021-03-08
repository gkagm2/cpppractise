// 한 번에 여러 개의 락을 동시에 획득하기
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

mutex mut1;
mutex mut2;

void process() {
	// 2개의 락을 각 뮤텍스에 생성한다.

	unique_lock<mutex> lock1(mut1, defer_lock_t()); //derfer_lock_t의 인스턴스를 인자로 넘겨줌으로써 생성과 동시에 락을 시도하지 않도록 한다. 데드락 방지
	unique_lock<mutex> lock2(mut2, defer_lock_t());
	lock(lock1, lock2);
	// 락을 획득함.
}

int main() {
	process();

	return 0;
}