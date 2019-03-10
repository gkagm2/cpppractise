// Calculator ex) 2 + 24, 4 / 6,  17 - 3, 54 % 3, 5 * 5
#include<iostream>
using namespace std;

int main() {

	int a, b;
	char oper;

	while(true){
		cout << "? ";
		cin >> a >> oper >> b;

		cout << a << " " << oper << " " << b << endl;

		switch (oper) {
		case '+':
			cout << a << " " << oper << " " << b << " = " << a + b << endl;
			break;
		case '-':
			cout << a << " " << oper << " " << b << " = " << a - b << endl;
			break;
		case '/':
			cout << a << " " << oper << " " << b << " = " << a / b << endl;
			break;
		case '%':
			cout << a << " " << oper << " " << b << " = " << a % b << endl;
			break;
		case '*':
			cout << a << " " << oper << " " << b << " = " << a * b << endl;
			break;
		default:
			cout << "wrong operator";
			break;
		}
	}
	return 0;
}