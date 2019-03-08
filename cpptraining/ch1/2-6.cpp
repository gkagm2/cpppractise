// use string class
#include <iostream>
#include <string>
using namespace std;

int main() {

	cout << "input new password >>";
	string password[2];
	getline(cin, password[0]);

	cout << "input new password again >>";
	getline(cin, password[1]);

	if (password[0] == password[1])
		cout << "Same password" << endl;
	else
		cout << "Differnet password" << endl;
	



	return 0;
}