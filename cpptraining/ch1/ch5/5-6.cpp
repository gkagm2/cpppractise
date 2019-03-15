#include <iostream>
using namespace std;

class MyIntStack {
	int *p;
	int size;
	int tos;
public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(MyIntStack& s);
	~MyIntStack();
	bool push(int n);
	bool pop(int &n);
};

MyIntStack::MyIntStack() {
	tos = 0;
}
MyIntStack::MyIntStack(int size) {
	p = new int[size];
	this->size = size;
}
MyIntStack::MyIntStack(MyIntStack& s) { //copy
	tos = s.tos;
	size = s.size;
	p = new int[size];

	for (int i = 0; i < tos; i++) {
		p[i] = s.p[i];
	}
}
MyIntStack::~MyIntStack() {
	delete[] p;
}
bool MyIntStack::push(int n) {
	if (tos < size) {
		p[tos] = n;
		tos++;
		return true;
	}
	return false;
}
bool MyIntStack::pop(int &n) {
	if (tos > 0) {
		tos--;
		n = p[tos];
		return true;
	}
	return false;
}

int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a; // copy class

	b.push(30);
	
	int n;
	a.pop(n);
	cout << "Popped value from a stack.: " << n << endl;
	b.pop(n);
	cout << "Popped value from b stack.: " << n << endl;

	return 0;
}