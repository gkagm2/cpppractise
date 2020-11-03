#pragma once
class Exp {
private:
	int base;
	int exp;

public:

	Exp();
	Exp(int base);
	Exp(int base, int exp);

	int getValue();
	int getExp();
	int getBase();
	bool equals(Exp value);
};