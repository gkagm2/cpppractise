#include "TestTemplate.h"
// 템플릿의 구현부


template<typename T>
inline Test<T>::Test(size_t _width, size_t _height)
	: mWidth(_width)
	, mHeight(_height)
{
}

// 인스턴스화를 허용 하려고 하는 타입을 맨 아래에 적어준다.
template class Test<int>;
template class Test<double>;