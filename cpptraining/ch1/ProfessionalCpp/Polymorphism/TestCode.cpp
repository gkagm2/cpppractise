#include <iostream>
#include <vector>
using namespace std;

// Abstract class
class Car {
public:
	virtual void Logo() = 0; // pure virtual method
};

class Truck : public Car{
public:
	virtual void Logo() override {
		cout << "Truck\n";
	}
};

class SportsCar : public Car{
public:
	virtual void Logo() override{
		cout << "SportsCar\n";
	}
};


int main() {
	// 포인터나 참조로 업캐스팅 가능
	Car *pt1 = new Truck();
	Car *pt2 = new Truck();
	Car *pt3 = new SportsCar();
	Car *pt4 = new SportsCar();

	vector<Car*> carv;
	carv.push_back(pt1);
	carv.push_back(pt2);
	carv.push_back(pt3);
	carv.push_back(pt4);
	for (auto x : carv) {
		x->Logo();
	}
	
	vector<unique_ptr<Car*>> carvec;
	carvec.push_back(make_unique<Car*>(pt1));
	carvec.push_back(make_unique<Car*>(pt2));
	carvec.push_back(make_unique<Car*>(pt3));
	carvec.push_back(make_unique<Car*>(pt4));
	for (auto x : carv) {
		x->Logo();
	}

	vector<unique_ptr<Car>> carArray;
	carArray.push_back(make_unique<SportsCar>());
	carArray.push_back(make_unique<Truck>());
	carArray.push_back(make_unique<SportsCar>());

	for (int i = 0; i < carArray.size(); ++i) {
		carArray[i]->Logo();
	}
	return 0;
}

