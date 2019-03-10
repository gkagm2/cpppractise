// Make Date class
#include <iostream>
#include <string>
using namespace std;

class Date {
	int year, month, day;
	
public:
	
	Date(int year, int month, int day);
	Date(string date);

	//use inline function
	int getYear() {
		return year;
	}
	int getMonth() {
		return month;
	}
	int getDay() {
		return day;
	}
	void show() {
		cout << year << " year, " << month<<" month, " << day <<" day"<< endl;
	}
};

Date::Date(int year, int month, int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}

Date::Date(string date) {

	int slashCount = 0;
	int startCount = 0;
	int finalCount = 0;
	
	for (finalCount = 0; finalCount < date.length(); finalCount++) {
		if (date[finalCount] == '/') {
			slashCount++;
			switch (slashCount) {
			case 1:
				year = stoi(date.substr(startCount, finalCount - startCount));
			case 2:
				month = stoi(date.substr(startCount, finalCount - startCount));
			}
			startCount = finalCount + 1;
		}
	}
	day = stoi(date.substr(startCount, date.length()));
	cout << endl;





}


int main() {

	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	
	independenceDay.show();
	cout << birth.getYear() << ", " << birth.getMonth() << ", " << birth.getDay() << endl;

	return 0;
}