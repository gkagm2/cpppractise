//Use opeartor member function 
#include <iostream>
using namespace std;

class Matrix {
	int m[4];
public:
	
	Matrix(int a = 0, int b = 0, int c = 0, int d = 0);
	friend void operator>>(Matrix op1, int ary[]);
	friend void operator<<(Matrix& op1, int ary[]);
};
void operator>>(Matrix op1, int ary[]) {

	for (int i = 0; i < 4; i++) {
		ary[i] = op1.m[i];
	}
}
void operator<<(Matrix& op1, int ary[]) {
	for (int i = 0; i < 4; i++) {
		op1.m[i] = ary[i];
	}
}
Matrix::Matrix(int a = 0, int b = 0, int c = 0, int d = 0) {
	this->m[0] = a;
	this->m[1] = b;
	this->m[2] = c;
	this->m[3] = d;
}
int main() {
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,3,4 };
	a >> x; //Copy each element of a to array x.
	b << y; //Set the element value of array y to each element of b

	for (int i = 0; i < 4; i++) { //print x[]
		cout << x[i] << ' ';
	}
	return 0;
}