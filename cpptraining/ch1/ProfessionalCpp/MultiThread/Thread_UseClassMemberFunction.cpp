// Ŭ������ ��� �Լ��� �̿��� ������
#include <iostream>
#include<thread>
using namespace std;

class Request {
private:
	int mId;
public:
	Request(int id) :mId(id) {}
	void process() {
		cout << "Processing request " << mId << "\n";
	}
};

int main() {

	/*
	Ŭ������ ��� �Լ�(��ü �޼���)�� �����忡�� ����ǵ��� ������ �� �ִ�.
	���ο� �����带 �����ϰ� �⵿�ϸ鼭 Request Ŭ���� �ν��Ͻ� req�� ��� �Լ� process()�� ȣ��

	�� ����� �̿��ϸ� Ư�� ��ü�� �޼��带 ������ ������� ���� �� �� �ִ�.
	�ٸ� �����忡�� ���� ��ü�� �����Ѵٸ� ���̽� ������� �߻����� �ʵ��� Ŭ������ ������ �������ϰ� �����ؾ� ��.
	*/

	Request req(100);
	thread t{ &Request::process, &req };
	t.join();

	return 0;
}