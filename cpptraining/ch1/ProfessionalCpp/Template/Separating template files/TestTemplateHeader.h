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

#include"TestTemplateDefinitions.hpp" // 마지막에 정의된 파일을 포함시켜줘야 함