#include <iostream>
#include <vector>
using namespace std;

template<typename T, size_t WIDTH, size_t HEIGHT> // 템플릿 선언부
class Grid {
public:
	Grid();
	virtual ~Grid();

	// 주어진 위치에 항목을 복제하여 배치한다.
	void setElementAt(size_t x, size_t y, const T& inElem);
	T& getElementAt(size_t x, size_t y);
	const T& getElementAt(size_t x, size_t y) const;

	size_t getHeight() const { return HEIGHT; }
	size_t getWidth() const { return WIDTH; }
private:
	T mCells[WIDTH][HEIGHT];
};

template<typename T, size_t WIDTH, size_t HEIGHT>
Grid<T, WIDTH, HEIGHT>::Grid() : mCells() //mCells는 0으로 초기화
{
}	

template<typename T, size_t WIDTH, size_t HEIGHT>
Grid<T, WIDTH, HEIGHT>::~Grid()
{
}

template<typename T, size_t WIDTH, size_t HEIGHT>
void Grid<T, WIDTH, HEIGHT>::setElementAt(size_t x, size_t y, const T & inElem)
{
	mCells[x][y] = inElem;
}

template<typename T, size_t WIDTH, size_t HEIGHT>
T & Grid<T, WIDTH, HEIGHT>::getElementAt(size_t x, size_t y)
{
	return mCells[x][y];
}

template<typename T, size_t WIDTH, size_t HEIGHT>
const T & Grid<T, WIDTH, HEIGHT>::getElementAt(size_t x, size_t y) const
{
	return mCells[x][y];
}

int main() {


	return 0;
}