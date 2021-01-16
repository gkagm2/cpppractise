#include <iostream>
using namespace std;

int i = 5, j = 2, k = 0;

void f() throw(int) { // �� �Լ��� int���� ���ܸ� ����
	cout << "f()\n";
	throw 'A'; // g()�� �ѷ��� try�� ���ٸ�, GPF�� �߻�
}

void h() {
	try {
		if (k == 0)
			throw k;
		cout << i / k << "\n";
	}
	catch (int k) {
		cout << "nested catch block\n";
		throw; // ���ܸ� �ٱ� catch ������ ����
	}
}

int main() {
	cout << "begin\n";
	try {
		if (j == 100 || j == 0)
			throw "exception: j is 100 or 0\n";
		//f();
		h();
		cout << i / j << "\n";
		cout << "end of try block\n";
	}
	catch (char e) {
		cout << "char catch\n";
	}
	catch (int e) {
		cout << "int catch\n";
	}
	catch (char* e) {
		cout << e << "\n";
	}
	catch (...) {
		cout << "catch anything\n";
	}
	cout << "end\n";

	return 0;
}