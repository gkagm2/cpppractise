#include<iostream>
using namespace std;

#include "Calculator.h"
#include "Adder.h"
void Calculator::runn() {
	cout << "input two number : ";
	int a, b;
	cin >> a >> b;
	Adder adder(a, b);
	cout << adder.process();
}
int Adder::process() {
	return op1 + op2;
}