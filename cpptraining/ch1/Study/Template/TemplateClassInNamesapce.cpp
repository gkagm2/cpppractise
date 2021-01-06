// namespace 안에 있는 템플릿 클래스를 상속받아 사용하는 예제
#pragma warning(disable:4996)
#include <stdio.h>		
namespace std {
	template<typename T>
	class CVector {
		T x;
		T y;
	public:
		CVector();

		void Set(T tx, T ty);
		T GetX() { return x; }
		T GetY() { return y; }
	};
}

template<typename T>
std::CVector<T>::CVector() {
	x = (T)0;
	y = (T)0;
}

template<typename T>
void std::CVector<T>::Set(T tx, T ty) {
	x = tx;
	y = ty;
}

template<typename T>
class CNewVector : public std::CVector<T> {
private:
	T z;
public:
	CNewVector();

	void Set(T tx, T ty, T tz);
	T GetZ() { return z; }
};

template<typename T>
CNewVector<T>::CNewVector()
{
	z = (T)0;
}

template<typename T>
void CNewVector<T>::Set(T tx, T ty, T tz) {
	using namespace::std;
	CVector<T>::Set(tx, ty);
	z = tz;
}

//////////////////////

// 타입이 T가 아닐 경우
class CNewVector1 : public std::CVector<int> {
	int z;
public:
	void Set(int tx, int ty, int tz) {
		std::CVector<int>::Set(tx, ty);
		z = tz;
	}

	int GetZ() { return z; }
};

int main() {
	CNewVector<int> v;
	v.Set(3, 4, 5);
	printf("%d, %d ,%d\n", v.GetX(), v.GetY(), v.GetZ());

	CNewVector1 vec;
	vec.Set(3, 4, 5);
	printf("%d, %d, %d\n", vec.GetX(), vec.GetY(), vec.GetZ());

	return 0;
}