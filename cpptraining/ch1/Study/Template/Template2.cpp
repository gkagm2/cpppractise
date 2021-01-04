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


// ����Ʈ ������ �̿��� �� ���� (default ������ ���ÿ� <>�� ���� ��. C++�� ���� ���Ѵ��ϳ�.)
template<class T, class U, int i = 100>
void f(T x) {
	U buffer[i];
	strcpy(buffer, x);
	cout << buffer << "\n";
}

////////////////////////////////////////////

// ���ø� ����Ʈ ����
template<class T = int, int size = 10>
class C1 {
public:
	T data[size];
	
	CTest() {}
	void Set(int i, T d) { data[i] = d; }
	T Get(T i) { return data[i]; }
};




int main() {
	// ���ø��� �� ���� �Ķ���Ͱ� typename or class�� �ƴ϶�� Ÿ�Կ� �´� ���ͷ� ������ �־���� ��.
	f1<char*, char, 20>("hello world1");

	f<char*, char>("hello world2");

	// C1 < > c1; // default ������ ���ÿ� <>�� ���� ��. C++�� ���� ���Ѵ��ϳ�.

	return 0;
}