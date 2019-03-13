
#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
	string name;
public:
	void setCircle(string name, int radius);
	double getArea();
	string getName();
};

void Circle::setCircle(string name, int radius) {
	this->name = name;
	this->radius = radius;
}
double Circle::getArea() {
	return 3.14 * radius * radius;
}
string Circle::getName() {
	return name;
}


//////////////////
class CircleManager {
	Circle *p;
	int size;
public:
	CircleManager(int size);
	~CircleManager();
	void searchByName(string name);
	void searchByArea(double area);
	void setCircle(string name, int radius, int num);
};
CircleManager::CircleManager(int size) {
	this->size = size;
	p = new Circle[size];
}
void CircleManager::searchByArea(double area) {
	for (int i = 0; i < size; i++) {
		if (p[i].getArea() > area) {
			cout << p[i].getName() << "'s area : " << p[i].getArea() << '\t';
		}
	}
}
void CircleManager::searchByName(string name) {
	for (int i = 0; i < size; i++) {
		if (p[i].getName() == name) {
			cout << p[i].getName() <<"'s area : " << p[i].getArea();
			break;
		}

	}
}
void CircleManager::setCircle(string name, int radius, int num) {
	p[num].setCircle(name, radius);
}

CircleManager::~CircleManager() {
	delete[] p;
}


int main() {
	int circleCount;
	cout << "Circle count : ";
	cin >> circleCount;
	CircleManager *circleManager = new CircleManager(circleCount);
	string name;
	int size;
	for (int i = 0; i < circleCount; i++) {
		cout << i + 1 << " circle's name and radius : ";
		cin >> name >> size;
		circleManager->setCircle(name, size, i);
	}
	cout << endl;

	cout << "search circle's name : ";
	cin >> name;
	circleManager->searchByName(name);
	cout << endl;
	int area;
	cout << "input minimum area with integer : ";
	cin >> area;
	circleManager->searchByArea(area);

	delete circleManager;
	return 0;
}