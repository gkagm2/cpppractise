#include <iostream>
using namespace std;

class Box {
	int width, height;
	char fill;
public:
	Box(int w, int h) { setSize(w, h); fill = '*'; }
	void setFill(char f) { fill = f; }
	void setSize(int w, int h);
	void draw(); //draw box
};
void Box::setSize(int w, int h) {
	width = w;
	height = h;
}
void Box::draw() {
	for (int n = 0; n < height; n++) {
		for (int m = 0; m < width; m++)
			cout << fill;
		cout << endl;
	}
}

int main() {

	Box b(10, 2);
	b.draw();
	cout << endl;
	b.setSize(7, 4);
	b.setFill('~');
	b.draw();

	return 0;
}