#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big) {
	if (a > b)
		big = a;
	else if (a < b)
		big = b;
	else { //same - true
		big = a;
		return true;
	}
	//not same - false
	return false;
}

int main() {
	int a, b;
	int big;
	cout << "input number :";
	cin >> a;
	cout << "input number :";
	cin >> b;

	cout << endl;
	if (bigger(a, b, big)) {
		cout << big << " is same" << endl;
	}
	else {
		cout << big << " is bigger" << endl;
	}
	
	

	return 0;
}