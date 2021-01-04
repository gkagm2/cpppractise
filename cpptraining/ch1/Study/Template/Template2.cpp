#pragma warning(disable:4996)
#include <iostream>
#include <stdlib.h>

using namespace std;

template<class T, class U, int i>
void f1(T x) {
	U buffer[i];
	strcpy(buffer, x);
	cout << buffer << "\n";
}


// ����Ʈ ������ �̿��� �� ����.
template<class T, class U, int i = 100>
void f(T x) {
	U buffer[i];
	strcpy(buffer, x);
	cout << buffer << "\n";
}

int main() {
	// ���ø��� �� ���� �Ķ���Ͱ� typename or class�� �ƴ϶�� Ÿ�Կ� �´� ���ͷ� ������ �־���� ��.
	f1<char*, char, 20>("hello world1");

	f<char*, char>("hello world2");

	return 0;
}