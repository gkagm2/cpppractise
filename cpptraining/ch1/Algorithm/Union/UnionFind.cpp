#include <iostream>
using namespace std;

int arrLink[100];
int arrSize[100];

int Find(int x) {
	while (x != arrLink[x])
		x = arrLink[x];
	return x;
}

bool Same(int a, int b) {
	return Find(a) == Find(b);
}

void Unite(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (arrSize[a] < arrSize[b])
		swap(a, b);
	arrSize[a] += arrSize[b];
	arrLink[b] = a;
}

int main() {

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) arrLink[i] = i;
	for (int i = 1; i <= n; ++i) arrSize[i] = 1;

	return 0;
}