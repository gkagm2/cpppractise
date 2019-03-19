// operator function == -> use external funciton 
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

	friend bool operator==(Book& op1, int price); // price
	friend bool operator==(Book& op1, string title); // title
	friend bool operator==(Book& op1, Book op2); // book


};
bool operator==(Book& op1, int price) {
	
	return op1.price == price ? true : false;
}
bool operator==(Book& op1, string title) {
	return op1.title == title ? true : false;
}
bool operator==(Book& op1, Book op2) {
	if (op1.price == op2.price && op1.title == op2.title && op1.pages == op2.pages) //compare book, title, pages 
		return true;
	else
		return false;
}

int main() {

	Book a("��ǰ C++", 30000, 500), b("��ǰ C++", 30000, 500);
	if (a == 30000)
		cout << "���� 30000��" << endl; //compare price
	if (a == "��ǰ C++")
		cout << "��ǰ C++ �Դϴ�." << endl; // compare book title
	if (a == b)
		cout << "�� å�� ���� å�Դϴ�." << endl; // compare title, price, pages


	return 0;
}