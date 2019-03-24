#include <iostream>
using namespace std;

class BaseArray {
private:
	int capacity;
	int *mem;
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() {
		delete[] mem;
	}
	void put(int index, int val) {
		mem[index] = val;
	}
	int get(int index) {
		return mem[index];
	}
	int getCapacity() {
		return capacity;
	}
};

class MyStack : public BaseArray {
	int pos;
public :
	MyStack(int size) : BaseArray(size){}
	void push(int num);
	int pop();
	int length();
	int capacity();
};
void MyStack::push(int num) {
	if (pos < getCapacity()) {
		put(pos, num);
		++pos;
	}
}
int MyStack::pop() {
	if (pos > 0)
		return get(--pos);
	else
		cout << "empty" << endl;;
		return NULL;
}
int MyStack::length() {
	return pos;
}
int MyStack::capacity() {
	return getCapacity();
}

int main() {
	MyStack mStack(100);
	int n;
	cout << "Input five numbers to put on the stack. >> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n);
	}
	cout << "stack capacity : " << mStack.capacity() << ", stack length : " << mStack.length() << endl;
	cout << "pop and print all elementary of stack" << endl;
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' ';
	}
	cout << endl << "current stack legnth : " << mStack.length() << endl;

	return 0;
}