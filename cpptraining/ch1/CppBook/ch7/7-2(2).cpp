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

	Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
	if (a == 30000)
		cout << "정가 30000원" << endl; //compare price
	if (a == "명품 C++")
		cout << "명품 C++ 입니다." << endl; // compare book title
	if (a == b)
		cout << "두 책이 같은 책입니다." << endl; // compare title, price, pages


	return 0;
}