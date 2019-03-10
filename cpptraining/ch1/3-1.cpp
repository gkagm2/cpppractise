// Make Tower class
#include <iostream>
using namespace std;


class Tower {
	int height;
public:
	Tower();
	Tower(int meter);

	int getHeight();
};

Tower::Tower() {
	height = 1;
}

Tower::Tower(int meter) {
	height = meter;
}
int Tower::getHeight() {
	return height;
}

int main() {
	Tower myTower;
	Tower seoulTower(100);
	cout << "height : " << myTower.getHeight() << "meter" << endl;
	cout << "height : " << seoulTower.getHeight() << "meter" << endl;
	return 0;
}