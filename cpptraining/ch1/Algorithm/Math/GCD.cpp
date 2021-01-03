#include <iostream>

/////////// ��Ŭ���� �˰��� ///////////
// �ִ� ����� ���ϱ� (������ ��� �˰���)
int GCD_modulus_fast(int u, int v) {
	int t;
	while (v) {
		t = u % v;
		u = v;
		v = t;
	}
	return u;
}

// �ִ� ����� ���ϱ� (���� ��� �˰���)
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

// �ִ� ����� ���ϱ� (��͸� �̿�)
int GCD_recursion(int u, int v) {
	if (v == 0)
		return u;
	return GCD_recursion(v, u%v);
}

int main() {

	return 0;
}