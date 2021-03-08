#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
using namespace std;

/*
타임아웃 락의 활용
타임아웃 뮤텍스의 활용
*/

class Counter {
private:
	int mId;
	int mNumIterations;
	static timed_mutex mTimedMutex;

public:
	Counter(int id, int numIterations) :
		mId(id),
		mNumIterations(numIterations)
	{
	}

	void operator()() const {
		for (int i = 0; i < mNumIterations; ++i) {
			// 200ms 안에 락을 점유하지 못하면 락 시도를 포기하고 생성자에서 리턴한다.
			// lock은 bool 변환 연산자를 오버로딩하고 있기 때문에 loc 변수를  if 문으로 검사하여 락 점유에 성공했는지 알 수 있다.
			// Timeout은  크로노 라이브러리 이용

			unique_lock<timed_mutex> lock(mTimedMutex, 200ms); // unique_lock의 생성자에는 200밀리초의 상대 시간이 인자로 주어짐. (c++14 표준의 사용자 정의 리터럴을 지원하지 않는다면 200ms 대신 200  사용
			if (lock) {
				cout << "Counter " << mId << " has value";
				cout << i << "\n";
			}
			else {
				// 200ms안에 락을 획득하지 못함.
			}

		}
	}
};
timed_mutex Counter::mTimedMutex;


int main() {

	return 0;
}