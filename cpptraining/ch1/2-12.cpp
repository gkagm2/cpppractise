//change C code to C++ code

//   C CODE
/*
#include<stdio.h>
int sum();
int main() {
	int n = 0;
	printf("input adge number of the end >>");
	scanf_s("%d", &n);
	printf("sum of 1 to %d is %d\n", n, sum(1, n));
	return 0;
}

int sum(int a, int b) {
	int k, res = 0;
	for (k = a; k <= b; k++) {
		res += k;
	}
	return res;
}
*/



//   C++ CODE
#include<iostream>
using namespace std;

int sum(int, int); // <- must write parameter in C++
int main() {
	int n = 0;
	cout <<"input adge number of the end >>";
	cin >> n;
	
	cout << "sum of 1 to " << n << " is " << sum(1, n) << endl;

	return 0;
}
int sum(int a, int b) {
	int k, res = 0;
	for (k = a; k <= b; k++) {
		res += k;
	}
	return res;
}