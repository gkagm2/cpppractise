// print x of count number from sentence
#include <iostream>
using namespace std;

int main() {

	cout << "input string (maximum 100) " << endl;
	char str[100];

	cin.getline(str, sizeof(str) ,'\n');
	int count = 0;

	for (int i = 0; i < sizeof(str)/sizeof(char); i++) {
		if (str[i] == 'x')
			count++;
	}

	cout << "the number of 'x' : " << count << endl;
	
	return 0;
}