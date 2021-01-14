#include <iostream>
using namespace std;

// reinterpret_cast�� �ü���� �����Ϸ��� �������̰ų�, �������� ���� ���� ���� �� ��ȯ�� �Ѵ�.
// �̸��� �ǹ��ϵ�, 2���� ���� �ٸ� ���� ���� ������ ���ο� �����(reinterpretation)�� �õ��Ѵ�.
// ee) void ��

void func(void *v) {
	// cast from pointer type to integral type.
	int i = reinterpret_cast<int>(v);
	cout << i << "\n";
}

//  func�� ����.
void func2(void *v) {
	int i = (int)v;
	cout << i << "\n";
}

int main() {
	//////////////////////////////
	// cast from an integral type to pointer type.
	func(reinterpret_cast<void *>(5));
	func((void*)5); // ���� �ڵ�� ����.

	func2((void*)5);
	//////////////////////////////

	typedef void(*INT_TYPE)(void*); // void(*func)(void*) �� ����
	INT_TYPE pFunc = func;



	pFunc((void*)3);
	pFunc(reinterpret_cast<void*>(10));

	return 0;
}