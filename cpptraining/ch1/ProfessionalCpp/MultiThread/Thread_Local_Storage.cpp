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

// thread_local 변수가 함수 안에서 선언되면, static으로 선언된 것처럼 동작한다.
// 단 스레드마다 고유하게 복제본을 가진다는 것만 다르다.
// 이 때문에 해당 함수가 몇 번 호출되는 thread_local 변수의 초기화는 각 스레드당 단 한 번만 수행된다.

void DoWork2(int id) {
	thread_local int m;
	k = 0;
	m = 0;
	for (; m < 20; ++m) {
		cout << id << "스레드의 고유 번호 m : " << m << "\n";
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

	thread t3(DoWork, 3);
	thread t4(DoWork, 4);
	t3.join();
	t4.join();

	return 0;
}