#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person();
	string getName() { return name; }
	string getTel() { return tel; }

	void set(string name, string tel);
};
Person::Person() {

}

void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
}

int main() {
	
	cout << "input name and phone number" << endl;

	Person person[3];
	string tel;
	string name;
	for(int i=0;i<3;i++){
		cout << "human " << i + 1 << " >> ";
		cin >> name >> tel;

		person[i].set(name, tel);
		

	}
	cout << "every name are ";
	for (int i = 0; i < 3; i++) {
		cout << person[i].getName() << ' ';
	}
	cout << endl;
	cout << "search phone number. input name : ";
	cin >> name;

	//Search name
	for (int i = 0; i < 3; i++ ) {
		if (name == person[i].getName()) {
			cout << person[i].getTel() << endl;
			break;
		}
	}

	

	return 0;
}
