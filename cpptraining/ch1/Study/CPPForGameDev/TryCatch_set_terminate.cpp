// 594 done  have to -> 604
#include <iostream>
//#include <eh.h>
//#include <process.h>
using namespace std;

// ������ ���ܿ� ���� �ڵ鷯�� ���ٸ�, ���α׷��� �̸� ���巯�� �Լ��� terminate()�� ȣ���ϰ�, terminate()�� ���ο��� abort()�� ȣ���Ͽ� ���α׷��� ���������� ���Ḧ �Ѵ�.
// terminate()�� ȣ���ϴ� �Լ��� �ٲٷ��� ǥ���Լ� set_terminate()�� ����� �� �ִ�.
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