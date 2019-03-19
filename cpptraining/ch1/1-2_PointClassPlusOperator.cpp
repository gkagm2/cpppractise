#include<iostream>
using namespace std;;

class Point {
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) { }
	void Print() const { cout << x << ',' << y << endl; }
	void operator+(Point arg) {
		cout << "operator+() 함수 호출" << endl;
	}
};
int main() {
	Point p1(2, 3), p2(5, 5);

	p1 + p2 ;// p1.operator+(p2);와 같다.
	cout << p1 * p2 << endl;// p1.operator*(p2);와 같다.
	cout << p1 = p2 << endl;// p1.operator=(p2);와 같다.
	cout << p1 == p2 << endl;// p1.operator==(p2);와 같다.
	cout << p1 += p2 << endl;// p1.operator++(p2);와 같다.
	

	return 0;
}