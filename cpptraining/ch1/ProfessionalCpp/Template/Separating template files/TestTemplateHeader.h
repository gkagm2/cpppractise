#pragma once
template<typename T>
class CTempTest {
public:
	T data;
	size_t mWidth;
	size_t mHeight;

	CTempTest(size_t _width, size_t _height);
	T GetData();
};

#include"TestTemplateDefinitions.hpp" // �������� ���ǵ� ������ ���Խ������ ��