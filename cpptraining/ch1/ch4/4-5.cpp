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

	int count = 0;
	Circle circle[3];
	int radius;
	for(int i=0;i<3;i++){
		cout << "Circle " << i << "radius :";
		cin >> radius;
		circle[i].setRadius(radius);

		if (circle[i].getArea() > 100)
			count++;
	}
	cout << "There are "<< count << " circles with an area bigger than 100." << endl;


	return 0;
}