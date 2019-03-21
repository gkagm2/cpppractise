// use friend function (Prefix, Postfix ++ operator)
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << " circle" << endl; }
	friend void operator++(Circle& op1);
	friend Circle operator++(Circle& op1, int x);
};

//Prefix operator
void operator++(Circle& op1) {
	op1.radius++;
}
//Postfix operator (need int type parameter)
Circle operator++(Circle& op1, int x) {
	Circle temp = op1; // save op1 state before changes
	op1.radius++;
	return temp;
}

int main() {
	Circle a(5), b(4);
	++a;
	b = a++;
	a.show();
	b.show();

	return 0;
}