#include "Mul.h"
#include <iostream>

void Mul::setValue(int a, int b) {
	this->a = a;
	this->b = b;
}
void Mul::calcuate() {
	std::cout << a * b << std::endl;
}