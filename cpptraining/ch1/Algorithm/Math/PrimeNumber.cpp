#include <iostream>
#include <cstring>
#include <math.h>
// 소수 구하기

// 소수인지 판별하는 함수 O(n^0.5)
int IsPrime_fast(int n) {
	for (int i = 2; i < sqrt(n); ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

// 소수인지 판별하는 함수 O(n)
int IsPrime_slow(int n) {
	int i;
	for (int i = 2; i < n; ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

// 에라토스테네스의 체 (Sieve of Eratosthenes)
// 주어진 정수 n보다 작은 모든 소수를 구한다.
int IsPrime_Eratosthenes(int n) {
	// 동적 배열 생성
	int *pArr = new int[n + 1](); // 0이면 소수 1이면 소수 아님
	memset(pArr, 0, sizeof(pArr));// 메모리 초기화

	// 에라토스테네스의 체를 이용하여 각 인덱스값이 소수인지 세팅
	int j = 0;
	for (int i = 2; i <= n; ++i) {
		if (pArr[i] == 1) // 이미 지워진 수(소수)가 아니면 넘어감
			continue;
		j = i; // 소수값을 j에 넣어줌.
		while((j+=i) <= n) {
			pArr[j] = 1;
		}
	}

	// 소수들 출력
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