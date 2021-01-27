#include <iostream>
#include <vector>
using namespace std;

template<typename T, size_t WIDTH, size_t HEIGHT> // ���ø� �����
class Grid {
public:
	Grid();
	virtual ~Grid();

	// �־��� ��ġ�� �׸��� �����Ͽ� ��ġ�Ѵ�.
	void setElementAt(size_t x, size_t y, const T& inElem);
	T& getElementAt(size_t x, size_t y);
	const T& getElementAt(size_t x, size_t y) const;

	size_t getHeight() const { return HEIGHT; }
	size_t getWidth() const { return WIDTH; }
private:
	T mCells[WIDTH][HEIGHT];
};

template<typename T, size_t WIDTH, size_t HEIGHT>
Grid<T, WIDTH, HEIGHT>::Grid() : mCells() //mCells�� 0���� �ʱ�ȭ
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