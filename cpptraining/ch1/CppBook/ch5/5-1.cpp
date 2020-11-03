#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();
	Circle(int radius);
	void setRadius(int radius);
	int getRadius();
};
Circle::Circle() {
	radius = 1;
}
Circle::Circle(int radius) {
	this->radius = radius;
}
void Circle::setRadius(int radius) {
	this->radius = radius;
}
int Circle::getRadius() {
	return radius;
}

void swap(Circle &c1, Circle &c2) {
	int temp;
	temp = c1.getRadius();
	c1.setRadius(c2.getRadius());
	c2.setRadius(temp);
}

int main() {
	Circle c1, c2(6);
	c1.setRadius(2);

	cout << c1.getRadius() << endl;
	cout << c2.getRadius() << endl;

	swap(c1, c2);

	cout << c1.getRadius() << endl;
	cout << c2.getRadius() << endl;

	return 0;
}