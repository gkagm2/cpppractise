#pragma warning(disable:4996)
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

void PrintOnState2(string& s) {
	cout << s << "\n";
	cout << "terminate\n";
}

int main() {
	int state, input = 0;
	string s = "";

	state = 0;
	while (input != 27 && state != 99) { // !(esc) or !(dead state)
		input = getch();
		switch (state) {
		case 0:
			if (input == 'a') {
				s += 'a';
				cout << "start\n";
				state = 1;
			}
			else
				state = 99;
			break;
		case 1:
			if (input == 'b') {
				s += 'b';
			}
			else if (input == 'c') {
				s += 'c';
				state = 2;
			}
			else
				state = 99;
			break;
		case 2:
			PrintOnState2(s);
			if (input == 'd') {
				cout << "restart\n";
				state = 0;
			}
			else
				state = 99;

			break;
		}
	}
	if (state == 2)
		cout << "Input recognized\n";


	return 0;
}
