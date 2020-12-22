// ��������
#include <iostream>
#include <stdarg.h> // �������ڿ� ���õ� ��ũ�ε��� �������
using namespace std;

// �������� ���� ���� �Լ�
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

// �ڷ����� �ٸ� ���� ���� �Լ� �����
/*
����(int) : 'i'
�Ǽ�(double) : 'd'
�Ǽ�(float) : 'f'
����(char) : 'c'
���ڿ�(char *) : 's'
*/
void MyPrint2(char *types, ...) {
	va_list ap;
	int i = 0;

	va_start(ap, types);
	while (types[i] != '\0') {
		switch (types[i]) {
		case 'i':
			cout << va_arg(ap, int) << " ";
			break;
		case 'd':
			cout << va_arg(ap, double) << " ";
			break;
		case 'c':
			cout << va_arg(ap, char) << " ";
			break;
		case 's':
			cout << va_arg(ap, char *) << " "; 
			break;
		default:
			break;
		}
		++i;
	}
	va_end(ap);
	cout << "\n";
}


int main() {
	MyPrint(0);
	MyPrint(1, 20);
	MyPrint(2, 20, 30);
	MyPrint(3, 20, 30, 40);
	MyPrint(4, 20, 30, 40, 50);

	// �ڷ����� �ٸ� ���� ���� �Լ�
	MyPrint2("i", 10);
	MyPrint2("ci", 'a', 10);
	MyPrint2("dci", 3.46, 'a', 10);
	MyPrint2("sdci", "Hello world", 3.46, 'a', 10); // "Hello world"�� ���ͷ��̱� ������ ���ڿ� �״�� ���°� �ƴ϶� ���ڿ��� �ּҰ� ����.

	return 0;
}