// print 1 to 100
#include "stdafx.h"
#include<iostream>
using namespace std;

int main() {
	int count = 0;

	for (int i = 1; i < 101; i++) {
		if (count == 10) {
			cout << endl;
			count = 0;
		}
		cout << i<< "\t";
		count++;
	}

	return 0;
}