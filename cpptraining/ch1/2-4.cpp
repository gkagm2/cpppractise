// compare float type number five times and print maximum number
#include<iostream>
using namespace std;

int main() {

	float num[5];
	
	cout << "input number of real type five times >> ";
	for (int i = 0; i < sizeof(num) / sizeof(float); i++) {
		cin >> num[i];
	}

	float max = num[0];
	for (int i = 1; i < sizeof(num) / sizeof(float); i++) {
		if (max < num[i]) {
			max = num[i];
		}
	}
	cout << "maxumum number is  : " << max << endl;
	return 0;
}