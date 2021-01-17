#include <iostream>
#include <stdarg.h>
#include <stdio.h>
using namespace std;

//CSort
template<typename T>
class SortFunctor;

template<typename T, typename FUNCTOR = SortFunctor<T>>
class CSort {
public:
	FUNCTOR ft;
	T m_data[10];
	int m_size;

	CSort();
	virtual ~CSort();
	void SetData(int size, ...);
	void Print();
	void Sort();
};

template<typename T, typename FUNCTOR>
CSort<T, FUNCTOR>::CSort() {
	m_size = 0;
}

template<typename T, typename FUNCTOR>
CSort<T, FUNCTOR>::~CSort() {
}

template<typename T, typename FUNCTOR>
void CSort<T, FUNCTOR>::SetData(int size, ...) {
	m_size = size;
	va_list va;
	va_start(va, size);
	for (int i = 0; i < size; ++i) {
		m_data[i] = va_arg(va, T);
	}
	va_end(va);
}

template<typename T, typename FUNCTOR>
void CSort<T, FUNCTOR>::Print()
{
	for (int i = 0; i < m_size; ++i) {
		ft.Print(m_data[i]); // 펑터의 Print()를 호출
	}
}

template<typename T, typename FUNCTOR>
void CSort<T, FUNCTOR>::Sort()
{
	// double sort
	for (int i = m_size - 1; i >= 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (ft.Compare(m_data[j], m_data[j + 1]) > 0)
				ft.Swap(m_data[j], m_data[j + 1]);
		}
	}
}

template<typename T>
class SortFunctor {
public:
	void Print(T& i) {
		cout << i << ", ";
	}
	int Compare(T& a, T& b) {
		return a > b;
	}
	void Swap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}
};

/*
// char* 형
template<>
class SortFunctor<char*> {
public:
	void Print(char* i) {
		cout << i << ", ";
	}
	int Compare(char* a, char* b) {
		return a > b;
	}
	void Swap(char*a, char* b) {
		char* temp = a;
		a = b;
		b = temp;
	}
};
*/

////////////////////////
template<typename T>
void Test(T i, SortFunctor<T> ft) {
	ft.Print(i);
}

int main() {
	CSort<double> sort;
	sort.SetData(7, -1.2, 4.4, 6, 2.0, 4.1, 8.5, 3.7);
	sort.Print();

	cout << "\n";

	sort.Sort();
	sort.Print();


	CSort<int> sort1;
	sort1.SetData(7, -1, 4, 6, 2, 4, 8, 3);
	sort1.Print();

	cout << "\n";

	sort1.Sort();
	sort1.Print();

	cout << "\n";
	Test(99, SortFunctor<int>());


	// CSort<char*> sort2;

	return 0;
}