#include <iostream>
using namespace std;

class Stack {
	int pos;
	int size;
	int *ary;
public:
	Stack();
	~Stack();
	Stack& operator<<(int value);
	bool operator!();
	void operator>>(int& val);
};
Stack::Stack() {
	size = 5;
	ary = new int[size];
}
// push
Stack& Stack::operator<<(int value) {
	if (pos >= size) {
		int *temp = new int[size + 5];
		for (int i = 0; i < pos; i++) {
			temp[i] = ary[i];
		}
		delete[] ary;
		size += 5;
		ary = temp;
	}
	ary[pos] = value;
	++pos;

	return *this;

}
//pull
void Stack::operator>>(int& val) {
	if (pos >= 1) {
		pos--;
		val = ary[pos];
	}
}
//is empty
bool Stack::operator!() {
	if (pos < 1) {
		return true;
	}
	else
		return false;
}

Stack::~Stack()
{
	delete[] ary;
}
int main() {

	Stack stack;
	stack << 3 << 5 << 10;
	while (true) {
		if (!stack)
			break;
		int x;
		stack >> x;
		cout << x << ' ';
	}

	cout << endl;

	return 0;
}