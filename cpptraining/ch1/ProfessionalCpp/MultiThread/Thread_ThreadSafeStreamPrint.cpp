#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;


/*
스레드 세이프하게 스트림에 출력
뮤텍스 객체를 이용해서 한 번에 한 스레드만 스트림 객체에 읽고/쓰기를 할 수 있도록 강제하면 출력 결과가 엉키는 것을 해결할 수 있다.

Counter 클래스에서의 모든 cout접근을 동기화한다.
static mutex객체가 클래스 멤버로 추가되었다.


*/


class Counter {
private:
	int mId;
	int mNumIterations;
	static mutex mMutex; // 모든 스레드에서 같은 mutex 인스턴스를 이용해야 하기 때문에 static 멤버.

public:
	Counter(int id, int numIterations) :
		mId(id),
		mNumIterations(numIterations)
	{
	}

	void operator()() const {
		for (int i = 0; i < mNumIterations; ++i) {
			lock_guard<mutex> lock(mMutex); // mutex 락을 위해 lock_guard 이용
			cout << "Counter " << mId << " has value";
			cout << i << "\n";
		}
	}
};
mutex Counter::mMutex;


int main() {

	return 0;
}