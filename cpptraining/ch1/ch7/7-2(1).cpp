// operator function == -> use member function
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
		cout << title << ' ' << price << "circle " << pages << " page" << endl;
	}
	string getTitle() { return title; }

	bool operator==(int price); // price
	bool operator==(string title); // title
	bool operator==(Book op2); // book
	
};
bool Book::operator==(int price) {
	return this->price == price ? true : false;
}
bool Book::operator==(string title) {
	return this->title == title ? true : false;
}
bool Book::operator==(Book op2) {
	if (price == op2.price && title == op2.title && pages == op2.pages) //compare book, title, pages 
		return true;
	else
		return false;
}

int main() {

	Book a("��ǰ C++", 30000, 500), b("��ǰ C++", 30000, 500);
	if (a == 30000)
		cout << "���� 30000��" << endl; //compare price
	if(a == "��ǰ C++")
		cout << "��ǰ C++ �Դϴ�." << endl; // compare book title
	if (a == b)
		cout << "�� å�� ���� å�Դϴ�." << endl; // compare title, price, pages


	return 0;
}