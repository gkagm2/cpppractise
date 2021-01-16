// 594 done  have to -> 604
#include <iostream>
//#include <eh.h>
//#include <process.h>
using namespace std;

// 던져진 예외에 대한 핸들러가 없다면, 프로그램은 미리 만드러진 함수인 terminate()를 호출하고, terminate()는 내부에서 abort()를 호출하여 프로그램은 비정상적인 종료를 한다.
// terminate()가 호출하는 함수를 바꾸려면 표준함수 set_terminate()를 사용할 수 있다.
void term_func() {
	cout << "term_func was called by terminate.\n";
	exit(-1);
}

int main() {
	try {
		set_terminate(term_func);
		throw "Out of memory!";
	}
	catch (int) {
		cout << "Integer exception raised.\n";
	}

	return 0;
}