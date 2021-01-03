#include <iostream>

/////////// 유클리드 알고리즘 ///////////
// 최대 공약수 구하기 (나머지 기반 알고리즘)
int GCD_modulus_fast(int u, int v) {
	int t;
	while (v) {
		t = u % v;
		u = v;
		v = t;
	}
	return u;
}

// 최대 공약수 구하기 (뺄셈 기반 알고리즘)
int GCD(int u, int v) {
	int t;
	while (u) {
		if (u < v) {
			t = u;
			u = v;
			v = t;
		}
		u = u - v;
	}
	return v;
}

// 최대 공약수 구하기 (재귀를 이용)
int GCD_recursion(int u, int v) {
	if (v == 0)
		return u;
	return GCD_recursion(v, u%v);
}

int main() {

	return 0;
}