#pragma once
#include <assert.h>
template<typename T>
class CVector {
private:
	const int mIncreaseCapacity = 10;
private:
	T *mArr;
	int mArrMaxCount;
	int mCount;

protected:
	bool IsFull();
	void IncreaseCapacity();

public:
	CVector();
	virtual ~CVector();
	void DeleteAt(int _idx); // private으로 빼진 않을것임
	void DeleteAll(); // private으로 빼진 않을것임
	void PushBack(const T& _data);
	void PushFront(const T& _data);
	bool Search(const T& _data);
	bool IsEmpty();
	const int Size();
	void Print();
	const T& At(int _idx);
	T& operator[] (int _idx);


	// iterator
private:
	enum IterIdxType { END = -2, BEGIN = 0 };
public:
	class iterator {
	private:
		CVector *mOwner;
		int mIdx;
	public:
		iterator(CVector* _dArr, int _idx);
		iterator(const iterator& _iter);
		virtual ~iterator();

		int& operator*();
		iterator& operator++(); // 전위
		iterator operator++(int); // 후위
		iterator& operator--();
		iterator operator--(int);
		bool operator!=(const iterator& _iter);
		bool operator==(const iterator& _iter);

		friend class CVector;
	};
	
	iterator begin() { return iterator(this, IterIdxType::BEGIN); }
	iterator end() { return iterator(this, IterIdxType::END); }
	iterator Erase(iterator& _iter);
};


template<typename T>
bool CVector<T>::IsFull()
{
	return mCount >= mArrMaxCount;
}

template<typename T>
void CVector<T>::IncreaseCapacity()
{
	mArrMaxCount += mIncreaseCapacity;
	T* newArr = new int[mArrMaxCount];
	for (int i = 0; i < mCount; ++i)
		newArr[i] = mArr[i];

	if (mArr != nullptr)
		delete[] mArr;
	mArr = newArr;
}

template<typename T>
CVector<T>::CVector() :
	mCount(0),
	mArrMaxCount(10)
{
	mArr = new int[mArrMaxCount];
}

template<typename T>
CVector<T>::~CVector()
{
	if (mArr != nullptr)
		delete[] mArr;
	mCount = 0;
	mArrMaxCount = mIncreaseCapacity;
}

template<typename T>
void CVector<T>::DeleteAll()
{
	if (mArr != nullptr)
		delete[] mArr;
	mCount = 0;
	mArrMaxCount = mIncreaseCapacity;
	mArr = new int[mArrMaxCount];
}

template<typename T>
void CVector<T>::DeleteAt(int _idx)
{
	for (int i = _idx; i < mCount - 1; ++i)
		mArr[i] = mArr[i + 1];
	--mCount;
}

template<typename T>
void CVector<T>::PushBack(const T & _data)
{
	if (IsFull())
		IncreaseCapacity();
	mArr[mCount] = _data;
	++mCount;
}

template<typename T>
void CVector<T>::PushFront(const T & _data)
{
	if (IsFull())
		IncreaseCapacity();
	for (int i = mCount; i >= 0; --i)
		mArr[i + 1] = mArr[i];
	mArr[0] = _data;
	++mCount;
}

template<typename T>
bool CVector<T>::Search(const T & _data)
{
	for (int i = 0; i < mCount; ++i) {
		if (mArr[i] == _data)
			return true;
	}
	return false;
}

template<typename T>
bool CVector<T>::IsEmpty()
{
	return mCount == 0;
}

template<typename T>
const int CVector<T>::Size()
{
	return mCount;
}

template<typename T>
void CVector<T>::Print()
{
	for (int i = 0; i < mCount; ++i)
		std::cout << mArr[i] << "->";
}

template<typename T>
const T & CVector<T>::At(int _idx)
{
	if (_idx < 0 || _idx >= mCount)
		throw::std::out_of_range("");
	return mArr[_idx];
}

template<typename T>
T & CVector<T>::operator[](int _idx)
{
	if (_idx < 0 || _idx >= mCount)
		throw::std::out_of_range("");
	return mArr[_idx];
}

//// Using Iterator ////
template<typename T>
typename CVector<T>::iterator CVector<T>::Erase(iterator & _iter)
{
	assert(_iter.mOwner == this);

	if (_iter.mIdx < IterIdxType::BEGIN)
		throw::std::out_of_range("");

	iterator copyIter(_iter.mOwner, _iter.mIdx - 1);
	DeleteAt(_iter.mIdx);
	if (_iter.mIdx > mCount)
		_iter.mIdx = IterIdxType::END;
	return copyIter;
}


//////////// Iterator /////////////

template<typename T>
inline CVector<T>::iterator::iterator(CVector* _other, int _idx) :
	mOwner(_other),
	mIdx(_idx)
{
}

template<typename T>
inline CVector<T>::iterator::iterator(const iterator & _iter) :
	mOwner(_iter.mOwner),
	mIdx(_iter.mIdx)
{
}

template<typename T>
inline CVector<T>::iterator::~iterator()
{
	mOwner = nullptr;
	mIdx = IterIdxType::END;
}

template<typename T>
typename int & CVector<T>::iterator::operator*()
{
	if (mIdx == IterIdxType::END)
		throw::std::out_of_range("");
	return (*mOwner)[mIdx];
}

template<typename T>
typename CVector<T>::iterator & CVector<T>::iterator::operator++()
{
	if (mIdx == IterIdxType::END)
		throw::std::out_of_range("");

	mIdx = (mIdx + 1) >= mOwner->mCount ? IterIdxType::END : (mIdx + 1);
	return *this;
}

template<typename T>
typename CVector<T>::iterator CVector<T>::iterator::operator++(int)
{
	iterator copyIter(mOwner, mIdx);
	++(*this);
	return copyIter;
}

template<typename T>
typename CVector<T>::iterator & CVector<T>::iterator::operator--()
{
	if (mIdx == IterIdxType::BEGIN)
		throw::std::out_of_range("");

	mIdx = mIdx == IterIdxType::END ? (mOwner->mCount - 1) : (mIdx - 1);
	return *this;
}

template<typename T>
typename CVector<T>::iterator CVector<T>::iterator::operator--(int)
{
	iterator copyIter(mOwner, mIdx);
	--(*this);
	return copyIter;
}

template<typename T>
typename bool CVector<T>::iterator::operator!=(const iterator & _iter)
{
	return mIdx != _iter.mIdx;
}

template<typename T>
typename bool CVector<T>::iterator::operator==(const iterator & _iter)
{
	return mIdx == _iter.mIdx;
}