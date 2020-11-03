// operator function < -> external function 
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
	//warning!! can't make class member operator function. 
	friend bool operator<(string title, Book op2);
};
bool operator<(string title, Book op2) {
	if (title < op2.title)
		return true;
	else
		return false;
}



int main() {
	Book a("청춘", 20000, 300);
	string b;
	cout << "input the book title>>";
	getline(cin, b); //boo title
	if (b < a) {
		cout << a.getTitle() << "이 " << b << "보다 뒤에 있구나!" << endl;
	}

	return 0;
}