// change c code to c++ code.
//   C CODE
/*  
#include<stdio.h>
int main() {
	int k, n = 0;
	int sum = 0;
	printf("input adge number of the end ");
	scanf_s("%d", &n);
	for (k = 1; k <= n; k++) {
		sum += k;
	}
	printf("sum of 1 to %d is %d\n", n, sum);
	return 0;
}
*/

//   C++ CODE
#include <iostream>
using namespace std;

int main() {

	int k, n = 0;
	int sum = 0;
	cout << "input adge number of the end";
	cin >> n;
	for (k = 1; k <= n; k++) {
		sum += k;
	}
	cout << "sum of 1 to " << n << " is " << sum << endl;
	return 0;
}
