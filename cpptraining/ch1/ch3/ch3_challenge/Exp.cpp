#include "Exp.h"


Exp::Exp() {
	base = exp = 1;
}
Exp::Exp(int base) {
	this->base = base;
	exp = 1;
}
Exp::Exp(int base, int exp) {
	this->base = base;
	this->exp = exp;
}
int Exp::getValue() {
	int value = 1;
	for (int i = 0; i < exp; i++) {
		value *= base;
	}
	return value;
}
bool Exp::equals(Exp value) {
	return  this->getValue() == value.getValue() ? true : false;
}
int Exp::getExp() {
	return exp;
}
int Exp::getBase() {
	return base;
}