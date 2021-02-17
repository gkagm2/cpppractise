#include <iostream>
#include "TestTemplate.h"
using namespace std;

int main() {
	Test<int> t(3, 5); // 정상작동
	t.data = 3;

	cout << t.data << "\n";

	Test<double> d(3, 5); // 정상작동
	d.data = 53.3;
	cout << d.data << "\n"; 

	/*
	Test<float> d(3, 5); // 재정의 기본 형식이 다르다고 에러남
	d.data = 3.3f;
	cout << d.data;
	*/
	return 0;
}