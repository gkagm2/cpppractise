// Attrubutes
// ���� �Ӽ�

#include <iostream>
using namespace std;


// �Լ��� ȣ��� �������� ���� �������� �ʴ´ٴ°��� �ǹ���. (�̷� ������ �Լ��� ���� ���α׷��̳� �����带 ������ѹ����ų� �ͼ����� �߻���Ų��.
[[noreturn]]
void func1() {
	throw 1;
}

// ������ ����� �� ������ ������ ��� �ߴ� �ȳ��� ������� ǥ��.
// [[deprecated("�������� ���� �޼ҵ�")]] 
[[deprecated]]
void func2() {
	cout << "ee";
}

int main() {

	try {
		func1();
	}
	catch (int e) {
		cout << e << "\n";
	}

	func2();

	return 0;
}