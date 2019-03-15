#include<iostream>
using namespace std;

class Accumulator {
	int value;
public:
	Accumulator(int value);
	Accumulator& add(int n);
	int get();
};
Accumulator::Accumulator(int value) {
	this->value = value;
}
Accumulator& Accumulator::add(int n) {
	value += n;
	return *this; // space return
}
int Accumulator::get() {
	return value;
}

int main() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7); //value member of acc : 28
	cout << acc.get(); //print 28

	return 0;
}