// ��������
#include <iostream>
#include <stdarg.h> // �������ڿ� ���õ� ��ũ�ε��� �������
using namespace std;

void MyPrint(int args, ...) {
	// ap : argument pointer
	va_list ap; // va_list : ���� ���� ���. ���� ������ �޸� �ּҸ� �����ϴ� ������

	va_start(ap, args); // va_start : ���� ���ڸ� ������ �� �ֵ��� �����͸� ����
	for (int i = 0; i < args; ++i) {
		int num = va_arg(ap, int); // ���� ���� �����Ϳ��� Ư�� �ڷ��� ũ�⸸ŭ ���� ������
		cout << num << " ";
		//cout << num << " ";
	}
	va_end(ap); // ���� ���� ó���� ������ �� ������ NULL�� �ʱ�ȭ

	cout << "\n";
}

int main() {
	MyPrint(0);
	MyPrint(1, 20);
	MyPrint(2, 20, 30);
	MyPrint(3, 20, 30, 40);
	MyPrint(4, 20, 30, 40, 50);

	return 0;
}