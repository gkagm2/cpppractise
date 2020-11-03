#include "Sub.h"
#include <iostream>

void Sub::setValue(int a, int b) {
	this->a = a;
	this->b = b;
}
void Sub::calcuate() {
	std::cout << a - b << std::endl;
}