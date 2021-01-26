#include <iostream>
using namespace std;

// ���� ��
void incr(int& value) {
	cout << "lvalue\n";
	++value;
}

// ���� ��
void incr(int&& value) {
	cout << "rvalue\n";
	++value;
}

void Case1() {
	int a = 10, b = 20;
	
	// ���� �� ����
	incr(a);

	// ���� �� ����
	incr(1 + 3);

	// ���� �� ����
	incr(a + b);

	// std::move() => ���� �� ������ �Լ��� ȣ���ϰ� �Ѵ�.  (rvalue�� static_cast��)
	incr(std::move(a + b));
}

void Case2() {
	/* �ȵ�
	int& i = 2; // ������ ����. ������� ���� ����
	int a = 2, b = 3;
	int&j = a + b; // ������ ����. �ӽ� ��ü�� ���� ����
	*/

	// ������ ������ �̿��ϸ� ������.
	int&& i = 2;
	int a = 2, b = 3;
	int&&j = a + b;
}

int main() {

	Case1();
	Case2();

	return 0;
}