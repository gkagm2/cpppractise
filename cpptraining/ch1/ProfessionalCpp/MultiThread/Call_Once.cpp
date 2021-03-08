// std::call_once
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

/*
std::call_once()를 std:once_flag와 함께 사용하면 복수의 스레드가 사용되는 환경에서 특정 함수를 단 한 번만 구동되도록 보증할 수 있다.
call_once()는 주어진 함수 또는 메서드가 단 한 번만 구동되도록 한다.  이러한 호출을 이펙티브 call_once() 구동이라고 한다. 이펙티브 call_once() 구동이 일어나면 가장 먼저 호출된 call_once()가 리턴하기 전에는 같은 once_flag 인스턴스로 호출된 call_once()들이 리턴하지 못하고 대기한다.
*/

once_flag gOnceFlag;

void initializeSharedResources() {
	// 복수의 스레드에서 사용될 공유 자원 초기화
	cout << "Shared resources intialized.\n";
}

void processingFunction() {

	// 공유 자원이 초기화되었는지 확인
	call_once(gOnceFlag, initializeSharedResources); // call_once이므로 initializeSharedResources 함수는 한번만 실행 됨.
	// 공유 자원을 활용한 작업 수행
	cout << "Processing\n";
}

int main() {
	vector<thread> threads(3);

	for (auto& t : threads) {
		t = thread{ processingFunction };
	}

	for (auto& t : threads) {
		t.join();
	}

	return 0;
}