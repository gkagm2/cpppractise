#include <iostream>
using namespace std;

// #�����ڳ� ## �����ڴ� ��ũ�ο��� ���ȴ�.

// # �����ڴ� ��Ʈ��ȭ �������̴�.
// #�� ��ũ�� �Լ��� ���Ǿ� ��ũ�� �Լ��� �Ķ���͸� ��Ʈ������ ����� ������ �Ѵ�.
#define STRING(s) #s

// ## ��ū(token) ���� �������̴�.
// ##�� ��ũ�� �Լ��� ���Ǿ� ��ũ�� �Լ��� �Ķ���͵��� �����Ͽ� �ϳ��� ��ū���� ����� ������ �ϴ� �����ڴ�.
#define token(i,j) i##j
#define string(i) lpsz##i

int main() {

	// # ����
	cout << STRING(hello world) << "\n"; // "hello world"�� �ٲ�.

	// ## ����
	int i = 1, j = 2, ij = 3;

	char lpszStr1[] = "hello";
	char string(Str2)[] = "world"; //

	cout << i << " " << j << " " << token(i, j) << "\n"; // token(i, j)�� ij�� �ٲ�
	cout << lpszStr1 << "\n";
	cout << string(Str1) << "\n"; // string(Str1)�� lpszStr1�� �ٲ�
	cout << string(Str2) << "\n"; // string(Str2)�� lpszStr2�� �ٲ� 

	return 0;
}
