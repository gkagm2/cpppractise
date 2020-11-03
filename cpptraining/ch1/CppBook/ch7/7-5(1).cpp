// Create a Matrix class that abstracts a two-dimensional matrix.create operator member functions 
#include <iostream>
using namespace std;

class Matrix {
	int m[4];
public:
	Matrix();
	Matrix(int a, int b, int c, int d);
	void show();

	Matrix operator+(Matrix op2);
	Matrix operator+=(Matrix op2);
	bool operator==(Matrix op2);
};
Matrix::Matrix() {
	for (int i = 0; i < 4; i++) {
		m[i] = 0;
	}
}
Matrix::Matrix(int a, int b, int c, int d) {
	m[0] = a;
	m[1] = b;
	m[2] = c;
	m[3] = d;
}
void Matrix::show() {
	cout << "Matrix = { ";
	for (int i = 0; i < 4; i++) {
		cout << m[i] << ' ';
	}
	cout << '}' << endl;
}

//operator function
Matrix Matrix::operator+=(Matrix op2) {
	for (int i = 0; i < 4; i++) {
		m[i] += op2.m[i];
	}
	return *this;
}
Matrix Matrix::operator+(Matrix op2) {
	Matrix temp;
	for (int i = 0; i < 4; i++) {
		temp.m[i] = this->m[i] + op2.m[i];
	}
	return temp;
}
bool Matrix::operator==(Matrix op2) {
	for (int i = 0; i < 4; i++) {
		if (op2.m[i] != m[i])
			return false;
	}
	return true;
}

int main() {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show();
	b.show();
	c.show();
	if (a == c)
		cout << "a and c are the same" << endl;
	return 0;
}