// operator function ? -> external function 
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
	friend bool operator!(Book op1);
};
bool operator!(Book op1) {
	if (op1.price == 0)
		return true;
	else
		return false;
}

int main() {

	Book book("º­·è½ÃÀå", 0, 50); //price 0
	if (!book) cout << "free" << endl;

	return 0;
}