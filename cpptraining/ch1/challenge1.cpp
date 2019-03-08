

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {

	string a;
	string b;

	cout << "input one of the \"rock\" \"paper\" \"scissors\"" <<endl;
	cout << "A>>";
	cin >> a;

	cout << "B>>";
	cin >> b;

	if (a == "rock" && b == "rock")
		cout << "draw";
	else if (a == "rock" && b == "paper")
		cout << "B win";
	else if (a == "rock" && b == "scissors")
		cout << "A win";

	else if (a == "paper" && b == "rock")
		cout << "A win";
	else if (a == "paper" && b == "paper")
		cout << "draw";
	else if (a == "paper" && b == "scissors")
		cout << "B win";

	else if (a == "scissors" && b == "rock")
		cout << "B win";
	else if (a == "scissors" && b == "paper")
		cout << "A win";
	else if (a == "scissors" && b == "scissors")
		cout << "draw";
	else
		cout << "you was inputed wrong words";

	cout << endl;
	return 0;
}

