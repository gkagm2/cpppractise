// 20210201
// 템플릿으로 만든 가변배열

#include <iostream>
using namespace std;

template<typename T>
class Array{
private:
	static constexpr size_t kAllocSize = 4;
	void resize(size_t newSize);
	void initializeElements();
	T* mElems;
	size_t mSize;
public:
	Array();
	virtual ~Array();

	// 값에 의한 대입을 금지
	Array<T>& operator=(const Array<T>& rhs) = delete;
	Array(const Array<T>& src) = delete;

	T getElementAt(size_t idx) const; 
	void setElementAt(size_t idx, const T& val);

	T& operator[](size_t idx);
	const T& operator[](size_t id) const;
};

template<typename T>
void Array<T>::resize(size_t newSize)
{
	T* oldElems = mElems;
	size_t oldSize = mSize;
	// 더 큰 배열 생성
	mSize = newSize;
	mElems = new T[newSize];
	initializeElements();
	for (size_t i = 0; i < oldSize; ++i)
		mElems[i] = oldElems[i];
	delete[] oldElems;
}

template<typename T>
void Array<T>::initializeElements()
{
	for (size_t i = 0; i < mSize; ++i)
		mElems[i] = T(); // <- 0으로 초기화
}

template<typename T>
Array<T>::Array()
{
	mSize = kAllocSize;
	mElems = new T[mSize];
	initializeElements();
}

template<typename T>
Array<T>::~Array() {
	if (mElems) delete[] mElems;
	mElems = nullptr;
}

template<typename T>
T Array<T>::getElementAt(size_t idx) const {
	if (idx >= mSize)
		throw::std::out_of_range("");
	return mElems[idx];
}

template<typename T>
void Array<T>::setElementAt(size_t idx, const T& val) {
	if (idx >= mSize)
		resize(idx + kAllocSize);
	mElems[idx] = val;
}

template<typename T>
T& Array<T>::operator[](size_t idx)
{
	if (idx >= mSize)
		resize(idx + kAllocSize);
	return mElems[idx];
}

// read-only
template<typename T>
const T& Array<T>::operator[](size_t idx) const {
	if (idx >= mSize)
		throw::std::out_of_range("");
	return mElems[idx];
}

void PrintArray(const Array<int>& arr, size_t size);

int main() {
	Array<int> arr;
	for (size_t i = 0; i < 10; ++i)
		arr.setElementAt(i, 100);

	for (size_t i = 0; i < 10; ++i)
		cout << arr.getElementAt(i) << " ";

	for (size_t i = 0; i < 10; ++i)
		arr[i] = 101;

	PrintArray(arr, 10);

	return 0;
}

void PrintArray(const Array<int>& arr, size_t size) {
	for (size_t i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

