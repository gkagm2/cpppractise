// (C2995 error)��� �̹� ���ǵǾ��ִٰ� �� ����������;

#include "TestTemplateHeader.h"
// ������
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