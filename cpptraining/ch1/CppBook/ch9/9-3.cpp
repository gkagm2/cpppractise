#include <iostream>
#include <string>
using namespace std;

class LoopAdder { //abstract class 
	string name; //loop's name
	int x, y, sum; //sum of x to y
	void read(); // input x, y 
	void write(); // output sum
protected:
	LoopAdder(string name = "") { // input loop's name.  initialized value : ""
		this->name = name;
	}
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;
public:
	void run();
};

void LoopAdder::read() { // input x, y
	cout << name << " : " << endl;
	cout << "Add first number to second number. input two numbers >> ";
	cin >> x >> y;
}
void LoopAdder::write() {
	cout << "The sum of " << x << " to " << y << " is " << sum << endl;
}
void LoopAdder::run() {
	read(); //read x, y
	sum = calculate(); // calculate
	write(); // write sum
}

class ForLoopAdder : public LoopAdder {
public:
	ForLoopAdder(string name) : LoopAdder(name) {}
	int calculate(); //overriding method
};
int ForLoopAdder::calculate() {
	int sum = 0;
	int x = getX();
	int y = getY();
	for (x; x <= y; x++) {
		sum += x;
	}
	return sum;
}

int main() {
	ForLoopAdder forLoop("For Loop");
	forLoop.run();
	return 0;
}