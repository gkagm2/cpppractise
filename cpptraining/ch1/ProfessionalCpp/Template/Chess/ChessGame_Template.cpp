#include <iostream>
#include <vector>
using namespace std;

template<typename T> // 템플릿 선언부
class Grid {
public:
	explicit Grid(size_t inWidth = kDefaultWidth, size_t inHeight = kDefaultHeight);
	virtual ~Grid();

	// 주어진 위치에 항목을 복제하여 배치한다.
	void setElementAt(size_t x, size_t y, const T& inElem);
	T& getElementAt(size_t x, size_t y);
	const T& getElementAt(size_t x, size_t y) const;

	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }
	static const size_t kDefaultWidth = 0;
	static const size_t kDefaultHeight = 0;
private:
	void initializeCellsContainer();
	std::vector<std::vector<T>> mCells;
	size_t mWidth, mHeight;
};

template<typename T>
Grid<T>::Grid(size_t inWidth, size_t inHeight)
{
}

template<typename T>
Grid<T>::~Grid()
{
}

template<typename T>
void Grid<T>::setElementAt(size_t x, size_t y, const T & inElem)
{
}

template<typename T>
T & Grid<T>::getElementAt(size_t x, size_t y)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
}

template<typename T>
const T & Grid<T>::getElementAt(size_t x, size_t y) const
{
	// TODO: 여기에 반환 구문을 삽입합니다.
}

template<typename T>
void Grid<T>::initializeCellsContainer()
{
}

int main() {
	

	return 0;
}