//separate files, express exponential, value
#include <iostream>

using namespace std;

#include "Exp.h"
int main() {
	Exp a(3, 2);// 3^2
	Exp b(9);//9^1
	Exp c;//1^1

	cout << a.getValue() << ' ' << b.getValue() << ' ' << c.getValue() << endl;
	cout << "base of a " << a.getBase() << ", " << "exponential " << a.getExp() << endl;
	cout << "base of a " << b.getBase() << ", " << "exponential " << b.getExp() << endl;
	cout << "base of a " << a.getBase() << ", " << "exponential " << a.getExp() << endl;

	if (a.equals(b))
		cout << "smae" << endl;
	else
		cout << "not same" << endl;

	return 0;
}