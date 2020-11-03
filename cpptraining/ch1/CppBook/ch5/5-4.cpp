#include <iostream>
using namespace std;

char& find(char a[], char c, bool& success) {
	for (int i = 0; i < sizeof(a) / sizeof(char); i++) {
		if (a[i] == c) {
			success = true;
			return a[i];
		}
	}
	success = false;
}

int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "can't find M" << endl;
		for (int i = 0; i < sizeof(s) / sizeof(char); i++) {
		}
		return 0;
	}
	loc = 'm';
	cout << s << endl;
	
	return 0;
}