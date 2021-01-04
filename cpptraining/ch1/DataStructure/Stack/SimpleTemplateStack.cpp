#include <iostream>
using namespace std;

template<class T, int size =20>
class CStack {
public:
	enum Error {
		ERROR_FULL,
		ERROR_EMPTY
	};
private:
	T arr[size];
	int curTop;
public:
	CStack() : curTop(-1) { }
	void CStack<T, size>::Push(T data); // CStack:: 없어도 될꺼임
	void CStack<T, size>::Pop();
	T CStack<T, size>::Top();
	int Size();
};

template<class T, int size>
void CStack<T, size>::Push(T data) {
	if (curTop == size)
		throw ERROR_FULL;
	arr[++curTop] = data;
}

template<class T, int size>
void CStack<T, size>::Pop()
{
	if (curTop == -1)
		throw ERROR_EMPTY;
	--curTop;
}

template<class T, int size>
T CStack<T, size>::Top()
{
	if (curTop < 0)
		throw ERROR_EMPTY;
	return arr[curTop];
}

template<class T, int size>
int CStack<T, size>::Size() {
	return curTop + 1;
}

int main() {
	CStack<int> stk;

	stk.Push(0);
	stk.Push(1);
	stk.Push(2);

	cout << "stack size : " << stk.Size() << "\n";

	int size = stk.Size();
	for (int i = 0; i < size; ++i) {
		cout << stk.Top() << "\n";
		stk.Pop();
	}

	cout << "stack size : " << stk.Size() << "\n";
	return 0;
}