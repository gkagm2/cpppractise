// when input 'yes' or 'Yes' than exit the program
#include<iostream>
#include<cstdio>
using namespace std;


int main() {


	char str[100];

	while (true) {
		cout << "if you want to exit the program, input \"yes\" >>";
		cin.getline(str, sizeof(str) / sizeof(char));
		cout << str;
		if (!strcmp("yes",str) || !(strcmp("Yes",str))) {
			break;
		}

	}
	

	return 0;
}