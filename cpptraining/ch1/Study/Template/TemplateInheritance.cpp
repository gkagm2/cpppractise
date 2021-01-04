#include <iostream>
using namespace std;

template<typename T>
class Super {
private:
	T m_data[100];
public:
	Super() {}
	void SetData(int index, T data);
	T GetData(int index) { return m_data[index]; }
};

template<typename T>
void Super<T>::SetData(int index, T data) {
	m_data[index] = data;
}

template<typename T, typename U>
class Sub : public Super<T> {
private:
	U m_myData;
public:
	using Super<T>::SetData;
	void SetData(int index, T data, U data2);
};

template<typename T, typename U>
void Sub<T, U>::SetData(int index, T data, U data2)
{
	m_myData = data2;
	Super<T>::SetData(index, data);
}

int main() {
	Sub<int, float> sub; 
	sub.SetData(0, 7); // 이것도 가능함
	sub.SetData(1, 8, 1.0f);

	cout << sub.GetData(0) << " " << sub.GetData(1);
	return 0;
}
