//use istream& get(char& ch) function and find out how many spacing there are.
#include <iostream>
using namespace std;

int main() {
	
	char ch;
	int spaceCount = 0;
	while (true) {
		cin.get(ch);
		if (ch == ' ')
			++spaceCount;
		if (cin.eof()) // ctrl-z -> end program
			break;
		cout.put(ch); //print 
		if (ch == '\n')
			break;
	}
	cout << "space count : " << spaceCount << endl;

	return 0;
}