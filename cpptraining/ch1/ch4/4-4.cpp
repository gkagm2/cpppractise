#include <iostream>
#include <string>
using namespace std;

int main() {
	
	cout << "input one line under the screen. (if you enter exit, program will exited)" << endl;
	string s;
	
	string tempWord;
	char temp;
	while (true) {
		cout << ">>";
		getline(cin, s, '\n');
		if (s == "exit")	
			break;

		for (int i = 0; i < s.length() / 2; i++) {
			temp = s[i];
			s[i] = s[s.length() - 1 - i];
			s[s.length() - 1 - i] = temp;
		}
		cout << s << endl;;
	}
	return 0;
}