// Counting Sort
#include <iostream>
#include <cstring>
using namespace std;
int numArr[2000001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	memset(numArr, 0, sizeof(numArr));

	int numCnt;
	cin >> numCnt;

	for (int i = 0; i < numCnt; ++i) {
		int n;
		cin >> n;
		++numArr[n + 1000000];
	}

	for (int i = 0; i < 2000001; ++i) {
		while (numArr[i]--) {
			cout << i - 1000000 << '\n';
		}
	}
	return 0;
}