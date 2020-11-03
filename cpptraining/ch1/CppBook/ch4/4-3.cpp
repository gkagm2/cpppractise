#include <iostream>
#include <string>
#include <ctime>
#include <random>
using namespace std;

int main() {

	srand((unsigned)time(NULL));

	cout << "enter one line. (if you want to exit, enter \"exit\")" << endl;
	string s;
	while (true) {
		cout << ">>";
		getline(cin, s, '\n');
		if (s == "exit") {
			break;
		}
		int n;
		int indexPos;
		while (true) {
			n = rand() % ('z' - 'a') + 'a';
			indexPos = rand() % s.length();
			if (s[indexPos] != char(n)) // duplicate exception
				break;
		}
		cout << "indexPos : "<<  indexPos << endl;
		cout << "char n : " << char(n)<<endl;
		
		s[indexPos] = char(n);

		cout << s << endl;
		
	}

	return 0;
}