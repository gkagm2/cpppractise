#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
public:
	Person(){}
	Person(string name) { this->name = name; }
	string getName() { return name; }
	void setName(string name) { this->name = name; };
};

class Family {
	string familyName;
	Person *p;
	int size;
public:
	Family(string name, int size);
	void show();
	~Family();
	void setName(int num, string name);
};

Family::Family(string name, int size) {
	familyName = name;
	this->size = size;
	p = new Person[size];
	
}
void Family::show() {
	cout << "There are " << size << " "<< familyName << "'s family members" << endl;
	for (int i = 0; i < size; i++) {
		cout << p[i].getName() << '\t';
	}
	cout << endl;

}
void Family::setName(int num, string name) {
	p[num].setName(name);
}

Family::~Family() {
	delete[] p;
}

int main() {

	Family *simpson = new Family("Simpson", 3);
	simpson->setName(0, "Mr. Simpson");
	simpson->setName(1, "Mrs. Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->show();
	delete simpson;
	return 0;
}