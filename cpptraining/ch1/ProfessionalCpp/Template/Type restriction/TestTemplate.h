#pragma once
template<typename T>
class Test {
public:
	T data;
public:
	size_t mWidth;
	size_t mHeight;
public:
	Test(size_t _width, size_t _height);
};

//#include "TestTemplate.cpp" // �ٸ� ���Ͽ� �����θ� �������� �������� ������� ��. ������ Type�� ������ �η��� �ϸ� ������ �ȵȴ�.