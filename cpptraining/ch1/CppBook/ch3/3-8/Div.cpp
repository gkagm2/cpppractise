#include "Div.h"
#include <iostream>

void Div::setValue(int a, int b) {
	this->a = a;
	this->b = b;
}
void Div::calcuate() {
	std::cout << a / b << std::endl;
}