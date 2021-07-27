#include <iostream>
using namespace std;

int Add(int a, int b) {
	return a + b;
}

typedef int(*TwoArgFn)(int, int);

class Offset {
private:
	int m_offset;

public:
	int Translate(int x) const { return m_offset + x; }
	int GetOffset() const { return m_offset; }

	static int MagicNumber() { return 7; }

public:
	Offset(int _offset) : m_offset(_offset) {}
	virtual ~Offset() {}
};

typedef int(Offset::*MemFn)(int) const;
typedef int(*ZeroArgFn)();

int main() {

	TwoArgFn pFn = Add; // Same as : TwoArgFn pFn = &Add;

	int a = 6;
	int b = 4;

	int sum = (*pFn)(a, b); // Same as : int sum = (pFn)(a, b);
	cout << sum << "\n";

	MemFn pMemFn = &Offset::Translate; 
	Offset offset(20);

	// ��� �Լ� �����ʹ� �ν��Ͻ� ������ ���ؽ�Ʈ���� ȣ��Ǿ�� �մϴ�.
	int nextA = (offset.*pMemFn)(a); 

	cout << "before a : " << a << " nextA : " << nextA << "\n";

	// ���� ��� �Լ��� ���� ���� �Լ��� �����ϴ�.
	ZeroArgFn pZeroArg = Offset::MagicNumber; // Saame as : ZeroArgFn pZeroArg = &Offset::MagicNumber;

	cout << "ZeroArg : " << pZeroArg() << "\n";
	cout << "ZeroArg : " << (*pZeroArg)() << "\n";


	return 0;
}