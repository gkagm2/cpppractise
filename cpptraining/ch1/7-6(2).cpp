#include <iostream>
using namespace std;

class Matrix {
	Matrix(int a = 0, int b = 0, int c = 0, int d = 0);
};
Matrix::Matrix(int a = 0, int b = 0, int c = 0, int d = 0) {

}

int main() {
	Matrix a(4, 3, 2, 1)b;
	int x[4], y[4] = { 1,2,3,4 };
	a >> x;
	b << y;
	return 0;
}