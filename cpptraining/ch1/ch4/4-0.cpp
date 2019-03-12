// print that the last tring in the dictionary.
#include <iostream>
#include <string>
using namespace std;



int main() {
	
	string name[5];

	for (int i = 0; i < 5; i++) {
		cout << "name : ";
		getline(cin, name[i],'\n');
	}

	string latter = name[0];
	for (int i = 0; i < 5; i++) {
		if (latter < name[i]) {
			latter = name[i];
		}
	}
	cout << "The last string in the dictionary. " << latter << endl;

	return 0;
}