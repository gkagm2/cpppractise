#include <iostream>
#include "TestTemplate.h"
using namespace std;

int main() {
	Test<int> t(3, 5); // �����۵�
	t.data = 3;

	cout << t.data << "\n";

	Test<double> d(3, 5); // �����۵�
	d.data = 53.3;
	cout << d.data << "\n"; 

	/*
	Test<float> d(3, 5); // ������ �⺻ ������ �ٸ��ٰ� ������
	d.data = 3.3f;
	cout << d.data;
	*/
	return 0;
}