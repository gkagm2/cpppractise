// operator function +=, -= -> member function
#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "won " << pages << " page" << endl;
	}
	string getTitle() { return title; }

	Book operator+=(int price);
	Book operator-=(int price);
};
Book Book::operator+=(int price) {
	this->price += price;
	return *this;
}
Book Book::operator-=(int price) {
	this->price -= price;
	return *this;
}

int main() {

	Book a("û��", 20000, 300), b("�̷�", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();


	return 0;
}