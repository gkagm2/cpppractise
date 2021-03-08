#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;


/*
������ �������ϰ� ��Ʈ���� ���
���ؽ� ��ü�� �̿��ؼ� �� ���� �� �����常 ��Ʈ�� ��ü�� �а�/���⸦ �� �� �ֵ��� �����ϸ� ��� ����� ��Ű�� ���� �ذ��� �� �ִ�.

Counter Ŭ���������� ��� cout������ ����ȭ�Ѵ�.
static mutex��ü�� Ŭ���� ����� �߰��Ǿ���.


*/


class Counter {
private:
	int mId;
	int mNumIterations;
	static mutex mMutex; // ��� �����忡�� ���� mutex �ν��Ͻ��� �̿��ؾ� �ϱ� ������ static ���.

public:
	Counter(int id, int numIterations) :
		mId(id),
		mNumIterations(numIterations)
	{
	}

	void operator()() const {
		for (int i = 0; i < mNumIterations; ++i) {
			lock_guard<mutex> lock(mMutex); // mutex ���� ���� lock_guard �̿�
			cout << "Counter " << mId << " has value";
			cout << i << "\n";
		}
	}
};
mutex Counter::mMutex;


int main() {

	return 0;
}