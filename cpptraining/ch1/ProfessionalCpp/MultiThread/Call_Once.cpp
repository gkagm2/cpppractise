// std::call_once
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

/*
std::call_once()�� std:once_flag�� �Բ� ����ϸ� ������ �����尡 ���Ǵ� ȯ�濡�� Ư�� �Լ��� �� �� ���� �����ǵ��� ������ �� �ִ�.
call_once()�� �־��� �Լ� �Ǵ� �޼��尡 �� �� ���� �����ǵ��� �Ѵ�.  �̷��� ȣ���� ����Ƽ�� call_once() �����̶�� �Ѵ�. ����Ƽ�� call_once() ������ �Ͼ�� ���� ���� ȣ��� call_once()�� �����ϱ� ������ ���� once_flag �ν��Ͻ��� ȣ��� call_once()���� �������� ���ϰ� ����Ѵ�.
*/

once_flag gOnceFlag;

void initializeSharedResources() {
	// ������ �����忡�� ���� ���� �ڿ� �ʱ�ȭ
	cout << "Shared resources intialized.\n";
}

void processingFunction() {

	// ���� �ڿ��� �ʱ�ȭ�Ǿ����� Ȯ��
	call_once(gOnceFlag, initializeSharedResources); // call_once�̹Ƿ� initializeSharedResources �Լ��� �ѹ��� ���� ��.
	// ���� �ڿ��� Ȱ���� �۾� ����
	cout << "Processing\n";
}

int main() {
	vector<thread> threads(3);

	for (auto& t : threads) {
		t = thread{ processingFunction };
	}

	for (auto& t : threads) {
		t.join();
	}

	return 0;
}