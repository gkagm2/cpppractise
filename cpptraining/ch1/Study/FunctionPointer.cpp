#include <iostream>
#include <functional>
using namespace std;

// �Լ� ������ : �Լ��� �޸� �ּҸ� �����ϱ� ���� ������ ������ ������ �� �ִ�.
// �����Լ��� ��� �Լ����� �� �Լ��� �޸� �ּ��̴�.
// �Լ� ������ ������ : ��ȯŸ�� (*�����ͺ�����)(����Ÿ��); �� ���·� ������ �ȴ�.

class CHanzo {
public:
	CHanzo() {

	}
	~CHanzo() {

	}
public:
	int m_iTest;
public:
	void Output() {
		cout << "Hanzo" << endl;
		cout << "Test : " << m_iTest << endl;
	}
};


int Sum(int a, int b) {
	return a + b;
}

int OutSum(int a, int b) {
	cout << a + b << endl;
	return a + b;
}
void Output() {
	cout << "Output Function" << endl;
}

float TestFunc(float fValue) {
	cout << fValue << endl;
	return fValue;
}


int main() {
	int(*pFunc)(int, int) = Sum;

	cout << pFunc(10, 20) << endl;

	pFunc = OutSum;
	pFunc(10, 20);

	void(*pFunc1)() = Output;

	pFunc1();

	CHanzo hanzo1, hanzo2;
	hanzo1.m_iTest = 100;
	hanzo2.m_iTest = 200;

	// this ������ : Ŭ���� �ȿ��� this�� ����� ��� �ش� ��ü�� �޸� �ּҰ� �ȴ�.
	// �� �ڱ��ڽ��� �������̴�.
	// ����Լ��� ȣ���� ��
	hanzo1.Output();
	hanzo2.Output();
	
	////////////////////////////////////

	// ����Լ������� ����� �����ͺ��� �̸� �տ� Ŭ������ :: �� �ٿ��ش�.
	void (CHanzo::*pFunc2)() = &CHanzo::Output;
	(hanzo1.*pFunc2)();

	// function ����� C++11���� ������ ���ִ� ����̴�. �� ����� �Լ� �����͸� ����, ��� ������ �ʰ� ���� �ּҸ�
	// �����ؼ� ȣ������ �� �ֵ��� ������ִ� ����̴�.
	// ������ : function<��ȯŸ��(����Ÿ��)> ������; �� ���·� �����Ѵ�.

	function<void()> func;
	function<void()> func1;

	// bind()�� �̿��ؼ� �Լ��� �����ش�.
	func = bind(Output);
	func1 = bind(&CHanzo::Output, &hanzo2);

	cout << "============ Functional =========== (functional ������� �ʿ�)" << endl;
	func();
	func1();
	func1 = bind(&CHanzo::Output, &hanzo1);

	function<int(int, int)> func3;
	function<float(float)> func4;

	// �Լ��� ���ڰ� ���� ��� placeholders �� �̿��ؼ� ������ ������ ������ �� �ִ�.
	// �Ʒ�ó�� 2, 1�� �־��ָ� ���ڰ� ���� �ٲ�� �ȴ�.
	func3 = bind(Sum, placeholders::_1, placeholders::_2);

	func3 = bind(Sum, placeholders::_2, placeholders::_1);
	// ������ 2, 1�� �ٲ������Ƿ� 10�� b�� 20�� a�� ���� �ȴ�.
	func3(10, 20);

	func4 = bind(TestFunc, placeholders::_1);

	func4(3.14f);
	 

	
	return 0;
}