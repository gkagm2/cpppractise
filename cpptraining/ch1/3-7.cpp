#include <iostream>
using namespace std;

class Oval {
	int height, width;
public:
	Oval();
	Oval(int w, int h);
	void set(int w, int h);
	~Oval();
	int getWidth();
	int getHeight();
	void show();
};
Oval::Oval() {
	width = height = 1;
}
Oval::Oval(int w, int h) {
	width = w;
	height = h;

}
void Oval::set(int w, int h) {
	width = w;
	height = h;
}
Oval::~Oval() {
	cout << "Oval destructor.  width : " << width << " , height : " << height << endl;
}
int Oval::getWidth() {
	return width;
}
int Oval::getHeight() {
	return height;
}
void Oval::show() {
	cout << "width : " << width << ", height : " << height << endl;
}





int main() {

	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << ", " << b.getHeight() << endl ;

	return 0;
}