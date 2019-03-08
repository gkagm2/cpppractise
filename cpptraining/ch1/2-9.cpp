// input name, address, age and print all 
#include <iostream>
#include <string>
using namespace std;

int main() {

	cout << "name : ";
	string name;
	getline(cin, name);
	
	cout << "address : ";
	string address;
	getline(cin, address);

	cout << "age : ";
	string age;
	getline(cin, age);

	cout << name << ", " << address << ", " << age << "old" << endl;


	return 0;
}