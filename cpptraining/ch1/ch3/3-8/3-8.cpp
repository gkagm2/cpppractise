//make calculatr without overriding and refactoring
#include <iostream>
#include "Add.h"
#include "Div.h"
#include "Mul.h"
#include "Sub.h"
using namespace std;

int main() {

	int num1;
	int num2;
	char op;
	Add a;
	Sub s;
	Mul m;
	Div d;

	while (true) {

		cout << "input two number and operator ex) 3 5 *" << endl;
		cout << ">>";
		cin >> num1 >> num2 >> op;

		switch (op) {
		case '-':
			s.setValue(num1, num2);
			s.calcuate();
			break;
		case '+':
			a.setValue(num1, num2);
			a.calcuate();
			break;
		case '*':
			m.setValue(num1, num2);
			m.calcuate();
			break;
		case '/':
			d.setValue(num1, num2);
			d.calcuate();
			break;
		default:
			cout << "wrong operator" << endl;
		}


	}

	return 0;
}