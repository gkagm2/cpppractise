//default parameter practise
#include <iostream>
using namespace std;

class MyVector {
	int *mem;
	int size;
public:
	
	MyVector(int n, int val);
	void show();
	~MyVector() { delete[] mem; }
};
MyVector::MyVector(int n = 100, int val = 0) {
	mem = new int[n];
	size = n;
	for (int i = 0; i < size; i++) mem[i] = val;
}
void MyVector::show() {
	for (int i = 0; i < size; i++) {

		cout << mem[i] << ' ';
	}
	cout << size<<endl;
}
int main() {
	MyVector v;
	MyVector c(200, 3);
	v.show();
	c.show();
	return 0;
}