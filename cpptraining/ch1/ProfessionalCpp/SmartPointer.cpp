#include <iostream>
#include <memory> // 스마트 포인터를 이용하려면 이 헤더파일이 필요한다.
using namespace std;

struct Student {
	char name[10];
	int age;
};

int main() {
	// 스마트 포인터의 종류는 3개가지가 있다.

	// 1. uniqye_ptr
	std::unique_ptr<Student> uniq; // 포인팅하고 있는 객체에 대해 단독으로 오너쉽을 가진다.  예외상황이 발생했을 때 메모리 해제를 단순하게 할 수 있다.

	/* 다른 방법의 선언 방법 */
	Student *pStudent = new Student();
	auto u = make_unique<Student>(); // C++14 버전부터 지원
	std::unique_ptr<Student> student(new Student);

	// 2. shared_ptr
	std::shared_ptr<int> shar; // 데이터에 대한 오너십이 여기 저기 분산될 수 있게 해준다. shar 변수가 다른 변수에 대입될 때마다 레퍼런스 카운터가 증가되어 데이터의 오너가 하나 더 늘었다는 것을 표시한다.
	// 모든 스코프를 벗어날 때는 레퍼런스 카운터가 0이되므로 이는 오너가 더 이상 없다는 뜻이므로 포인터에 의해 참조되고 있는 객체의 메모리가 해제된다. 배열지원X

	// 3. weak_ptr
	std::weak_ptr<int> weak; // shared_ptr에 대입된 객체를 참조하되 레퍼런스 카운터에 영향을 주고 싶지 않을 때 사용한다.

	return 0;
}