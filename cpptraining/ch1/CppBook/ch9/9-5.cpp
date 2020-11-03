//use in cin.get() function and print how many of the 'a' spell in the words
#include <iostream>
using namespace std;

class AbstractGate { // abstract class
protected:
	bool x, y;
public:
	void set(bool x, bool y) { this->x = x; this->y = y; }
	virtual bool operation() = 0;
};

//TODO : Make ANDGate, ORGate, XORGate class 
class ANDGate {
public:

};
class ORGate {
public:
};
class XORGate {
public:
};

int main() {
	ANDGate and;
	ORGate or;
	XORGate xor;

	and.set(true, false);
	or .set(true, false);
	xor.set(true, false);
	cout.setf(ios::boolalpha); // print boolean vaule with string 
	cout << and.operation() << endl; // AND result : false
	cout << or.operation() << endl; // OR result : true
	cout << xor.operation() << endl; // XOR result : true
	return 0;
}