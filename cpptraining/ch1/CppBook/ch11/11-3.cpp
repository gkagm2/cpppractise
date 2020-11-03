#include <iostream>
using namespace std;

int main() {


	char ch;
	while ((ch = cin.get()) != EOF) {

		cout.put(ch);

		if (ch == '\n') {
			break;
		}

	}
	return 0;
}