#include "Add.h"
#include <iostream>
void Add::setValue(int a, int b) {
	this->a = a;
	this->b = b;
}
void Add::calcuate() {
	std::cout << a + b << std::endl;

}