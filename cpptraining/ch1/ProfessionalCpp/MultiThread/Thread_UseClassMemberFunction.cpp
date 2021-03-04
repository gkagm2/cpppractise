// 클래스의 멤버 함수를 이용한 스레드
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
	클래스의 멤버 함수(객체 메서드)가 스레드에서 수행되도록 지장할 수 있다.
	새로운 스레드를 생성하고 기동하면서 Request 클래스 인스턴스 req의 멤버 함수 process()를 호출

	이 방법을 이용하면 특정 객체의 메서드를 별도의 스레드로 실행 할 수 있다.
	다른 스레드에서 같은 객체에 접근한다면 레이스 컨디션이 발생하지 않도록 클래스를 스레드 세이프하게 구현해야 함.
	*/

	Request req(100);
	thread t{ &Request::process, &req };
	t.join();

	return 0;
}