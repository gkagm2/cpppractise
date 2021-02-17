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

//#include "TestTemplate.cpp" // 다른 파일에 구현부를 적었으면 마지막에 적어줘야 함. 하지만 Type에 제한을 두려고 하면 적으면 안된다.