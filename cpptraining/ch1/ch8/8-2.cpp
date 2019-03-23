#include <iostream>
#include <string>
using namespace std;
class Circle {
	int radius;
public:
	Circle(int radius = 0) {
		this->radius = radius;
	}
	int getRadius() {
		return radius;
	}
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14* radius* radius; }
};
class NamedCircle : public Circle {
	string name;
public:
	NamedCircle() {};
	NamedCircle(int radius, string name) : Circle(radius) {
		this->name = name;
	}
	string getName() {
		return name;
	}
	void setName(string name) {
		this->name = name;
	}
};
NamedCircle getLargestAreaPizza(NamedCircle pizza[], int size) {
	NamedCircle largestPizza ;
	largestPizza = pizza[0];
	for (int i = 0; i < size; i++) {
		if (largestPizza.getArea() < pizza[i].getArea()) {
			largestPizza = pizza[i];
		}
	}
	return largestPizza;
}
int main() {
	NamedCircle pizza[5];
	
	cout << "Input five circles radius and name." << endl;
	int radius;
	string pizzaName;

	int max = 0;
	for (int i = 0; i < 5; i++) {
		cin >> radius;
		cin.ignore();
		getline(cin, pizzaName);
		pizza[i].setRadius(radius);
		pizza[i].setName(pizzaName);

		if (pizza[i].getRadius() > pizza[max].getRadius()) {
			max = i;
		}
	}
	cout << "pizza of largest area is " << pizza[max].getName()<<" pizza"<<endl;
	return 0;
}