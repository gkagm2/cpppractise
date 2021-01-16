#include <iostream>
using namespace std;



// catch �ڵ鷯(Handler)�� ���޵Ǿ��� ��, ���� �ǵ�����(stack unwinding) �۾��� �Ͼ.(�����Ϸ��� �̰��� ���� �ڵ带 ����)
// ������ ���� ����, ���� �ּ� �� �Ķ���͵��� ������ ����. ���ܰ� �߻����� ��, �ʼ������� ������ catch �ڵ鷯�� �µ��� ������ ���´� �����Ǿ� ��.
// (���ÿ� �ִ�) ������ �޴� ���� ��ü�� �ı���.
//////////////////////////////////////////////////////////////
class CTest {
	int i;
public:
	CTest(int t) {
		i = t;
		cout << "constructor: " << i << "\n";
	}
	virtual ~CTest() {
		cout << "destructorr: " << i << "\n";
	}
};

// �Լ� �ѹ��� ���������� ��ũ��
//////////////////////////////////////////////////////////////
void f() {
	try {
		cout << "f()\n";
		throw "Exit every calls\n";
		cout << "end of f()\n";
	}
	catch (...) {
		throw;
	}
}

void g() {
	try {
		cout << "g()\n";
		f();
		cout << "end g()\n";
	}
	catch (...) {
		throw;
	}
}

void h() {
	try {
		cout << "h()\n";
		g();
		cout << "end h()\n";
	}
	catch (...) {
		throw;
	}
}




int main() {
	
	try {
		CTest i(2), j(3);
		throw "exception";
		cout << "This will be never printed\n";
	}
	catch (...) {
		cout << "catch exception\n";
	}


	// �Լ� �ѹ��� ����������
	try {
		h();
		cout << "end of try in main()\n";
	}
	catch (...) {
		cout << "Exited directly from f()\n";
	}


	// ���
	/*
	h()
	g()
	f()
	Exited directly from f()
	*/

	return 0;
}