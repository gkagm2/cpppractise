#include "TestTemplate.h"
// ���ø��� ������


template<typename T>
inline Test<T>::Test(size_t _width, size_t _height)
	: mWidth(_width)
	, mHeight(_height)
{
}

// �ν��Ͻ�ȭ�� ��� �Ϸ��� �ϴ� Ÿ���� �� �Ʒ��� �����ش�.
template class Test<int>;
template class Test<double>;