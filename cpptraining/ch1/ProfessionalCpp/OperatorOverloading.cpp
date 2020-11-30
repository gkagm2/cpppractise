#include <iostream>
using namespace std;
static int a = 0;
class MyClass {
private:
	int myCode;
	int mValue = 0;
public:
	MyClass() {
		myCode = a++;
	}
	explicit MyClass(int n) : mValue(n) {};

	MyClass operator+(const MyClass& op) const {
		MyClass newClass;
		newClass.mValue = op.mValue + mValue;
		return newClass;
	}

	MyClass operator+(const int n) {
		MyClass newClass;
		newClass.mValue = n + mValue;
		return newClass;
	}

	MyClass& operator=(const int n) {
		mValue += n;
		return *this;
	}

	MyClass& operator+=(const MyClass& rhs);



	void setValue(int n) {
		mValue = n;
	}
	int getValue() const {
		return mValue;
	}

	

	int getCode() const {
		return myCode;
	}
	friend MyClass operator+(const MyClass& lhs, const MyClass& rhs);
	friend MyClass operator+(const int n, const MyClass& rhs);
};

// 덧셈을 할 때 인자의 좌 우 위치 관계없이 + 연산자가 동작되게 하려면 전역으로 만들고 friend를 이용해야 한다.
MyClass operator+(const MyClass& lhs, const MyClass& rhs) {
	MyClass newClass;
	newClass.setValue(lhs.getValue() + rhs.getValue());
	return newClass;
}

// 정수 + class
MyClass operator+(const int n, const MyClass& rhs) {
	MyClass newClass;
	newClass.setValue(n + rhs.getValue());
	return newClass;
}

// 축양형 산술 연산자 오버로딩
MyClass& MyClass::operator+=(const MyClass& rhs) {
	setValue(mValue + rhs.mValue);
	return *this;
}

int main() {

	MyClass m;
	m.setValue(6);
	m = m + 4;
	m = 5 + m;

	MyClass n;

	n = 1 + 31;

	cout << m.getValue();
	cout << "\n";

	cout << n.getValue();
	cout << "\n";

	n += m;
	cout << n.getValue();
	cout << "\n";

	return 0;
}