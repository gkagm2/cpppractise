//dynamic allocation
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	void setRadius(int radius);
	double getArea();
	
};
void Circle::setRadius(int radius) {
	this->radius = radius;
}
double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	cout << "count of circle : ";
	int circleCount;
	cin >> circleCount;
	Circle *c = new Circle[circleCount];
	int radius;
	for (int i = 0; i < circleCount; i++) {
		cout << i+1 << " circle radius : ";
		cin >> radius;
		c[i].setRadius(radius);
	}

	int circleMaxCount=0;
	for (int i = 0; i < circleCount; i++) {
		if (c[i].getArea() > 100) {
			circleMaxCount++;
		}
	}
	delete[] c;
	cout << "There are " << circleMaxCount << " circles with an larger than 100" << endl;

	return 0;
}