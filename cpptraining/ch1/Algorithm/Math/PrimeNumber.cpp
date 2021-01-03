#include <iostream>
#include <cstring>
#include <math.h>
// �Ҽ� ���ϱ�

// �Ҽ����� �Ǻ��ϴ� �Լ� O(n^0.5)
int IsPrime_fast(int n) {
	for (int i = 2; i < sqrt(n); ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

// �Ҽ����� �Ǻ��ϴ� �Լ� O(n)
int IsPrime_slow(int n) {
	int i;
	for (int i = 2; i < n; ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

// �����佺�׳׽��� ü (Sieve of Eratosthenes)
// �־��� ���� n���� ���� ��� �Ҽ��� ���Ѵ�.
int IsPrime_Eratosthenes(int n) {
	// ���� �迭 ����
	int *pArr = new int[n + 1](); // 0�̸� �Ҽ� 1�̸� �Ҽ� �ƴ�
	memset(pArr, 0, sizeof(pArr));// �޸� �ʱ�ȭ

	// �����佺�׳׽��� ü�� �̿��Ͽ� �� �ε������� �Ҽ����� ����
	int j = 0;
	for (int i = 2; i <= n; ++i) {
		if (pArr[i] == 1) // �̹� ������ ��(�Ҽ�)�� �ƴϸ� �Ѿ
			continue;
		j = i; // �Ҽ����� j�� �־���.
		while((j+=i) <= n) {
			pArr[j] = 1;
		}
	}

	// �Ҽ��� ���
	for (int i = 2; i <= n; ++i) {
		if (pArr[i] == 0)
			std::cout << i << " ";
	}

	bool isPrime  = pArr[n] == 0 ? true : false;
	delete[] pArr;
	return isPrime;
}

int main() {
	return 0;
}