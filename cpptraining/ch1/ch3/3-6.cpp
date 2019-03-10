#include <iostream>
#include <string>
using namespace std;

class Integer {
	int number;
public:
	Integer(int num);
	Integer(string num);
	void set(int num);
	int get();
	bool isEven();
	
};

Integer::Integer(int num) {
	number = num;
}
Integer::Integer(string num) {
	number = stoi(num);  //change string to integer
}
void Integer::set(int num) {
	number = num;
}

int Integer::get() {
	return number;
}
bool Integer::isEven() {
	return number % 2 == 0 ? true : false;
}


int main() {
	Integer n(30);
	cout << n.get() << ' ';
	n.set(50);
	cout << n.get() << ' ';

	Integer m("300");
	cout << m.get() << ' ';
	cout << m.isEven();
	return 0;
}