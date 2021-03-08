#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
using namespace std;

/*
Ÿ�Ӿƿ� ���� Ȱ��
Ÿ�Ӿƿ� ���ؽ��� Ȱ��
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
			// 200ms �ȿ� ���� �������� ���ϸ� �� �õ��� �����ϰ� �����ڿ��� �����Ѵ�.
			// lock�� bool ��ȯ �����ڸ� �����ε��ϰ� �ֱ� ������ loc ������  if ������ �˻��Ͽ� �� ������ �����ߴ��� �� �� �ִ�.
			// Timeout��  ũ�γ� ���̺귯�� �̿�

			unique_lock<timed_mutex> lock(mTimedMutex, 200ms); // unique_lock�� �����ڿ��� 200�и����� ��� �ð��� ���ڷ� �־���. (c++14 ǥ���� ����� ���� ���ͷ��� �������� �ʴ´ٸ� 200ms ��� 200  ���
			if (lock) {
				cout << "Counter " << mId << " has value";
				cout << i << "\n";
			}
			else {
				// 200ms�ȿ� ���� ȹ������ ����.
			}

		}
	}
};
timed_mutex Counter::mTimedMutex;


int main() {

	return 0;
}