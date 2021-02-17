// (C2995 error)계속 이미 정의되어있다고 뜸 뭐가문제냐;

#include "TestTemplateHeader.h"
// 구현부
template<typename T>
inline CTempTest<T>::CTempTest(size_t _width, size_t _height)
	: mWidth(_width)
	, mHeight(_height)
{
} 

template<typename T>
inline T CTempTest<T>::GetData()
{
	return data;
}