#pragma warning(disable:4996)
#include<iostream>
#include<cstdlib>
using namespace std;


class Book {
	char *title;
	int price;
public:
	Book(char *title, int price);
	Book(Book& b);
	~Book();
	void set(char *title, int price);
	void show() {
		cout << title << ' ' << price << "won" << endl;
	}
};
Book::Book(Book& b){
	delete[] this->title;
	this->title = new char[strlen(b.title) + 1];
	strcpy(this->title, b.title);
	price = b.price;

}

Book::Book(char *title, int price) {
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);
	this->price = price;
}
void Book::set(char *title, int price) {
	delete[] this->title;
	cout << strlen(title) + 1 << endl;
	this->title = new char[strlen(title) + 1];

	strcpy(this->title, title); 
	this->price = price;
}
Book::~Book() {
	delete[] title;
}

int main() {
	char a[] = "명품c++";
	char b[] = "명품자바";
	Book cpp(a, 10000);
	Book java = cpp;
	java.set(b, 12000);
	cpp.show();
	java.show();

	return 0;
}