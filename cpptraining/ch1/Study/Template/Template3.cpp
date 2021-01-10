// 문법적 에러남 뭐가 문제냐..

// 미리 정의된 파라미터를 가지는 템플릿 클래스
#pragma warning(disable:4996)
#include <stdio.h>
#include <iostream>
#include <memory.h>

// template class CTest
template<typename T>
class CTest {
private:
	T m_data[100];
public:
	CTest();
	void SetData(int index, T data);
	T GetData(int index);
};

template<typename T>
CTest<T>::CTest() {}

template<typename T>
void CTest<T>::SetData(int index, T data) {
	m_data[index] = data;
}

template<typename T>
T CTest<T>::GetData(int index) {
	return m_data[index];
}


struct SData {
	int data[10];
};

//////////////////////////////////////////////////
// template class CTest<SData>
template<> // <- 이 클래스가 기존의 템플릿 클래스임을 나타낸다. 위에 이미 클래스가 정의되어있음.
class CTest<SData> { // <- CTest 뒤에 지정된 <SData>는 템플릿 파라미터를 의미한다.
private:
	T m_data[100];

public:
	CTest<SData>::CTest();
	void SetData(int index, T data);
	T GetData(int index);
};

template<>
CTest<SData>::CTest(){}

template<>
void CTest<SData>::SetData(int index, SData data) {
	memcpy(&m_data[index], &data, sizeof(T));
}

template<>
SData CTest<SData>::GetData(int index) {
	return m_data[index];
}

int main() {
	CTest<int> t;
	t.SetData(0, 7);

	int i;

	i = t.GetData(0);
	printf("%d\n", i);
	CTest<SData> t2;
	SData d;
	SData r;

	memset(&d.data, 0, sizeof(d));
	d.data[1] = 8;
	t2.SetData(0, d);
	r = t2.GetData(0);
	printf("%d\n", r.data[1]);

	return 0;
}