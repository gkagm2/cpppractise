#pragma once
#include <iostream>
#include "DynamicArrayClass.h"
#include <assert.h>

bool CVector::IsFull()
{
	return mCount >= mArrMaxCount;
}

void CVector::IncreaseCapacity()
{
	mArrMaxCount += mIncreaseCapacity;
	Data* newArr = new int[mArrMaxCount];
	for (int i = 0; i < mCount; ++i)
		newArr[i] = mArr[i];

	if(mArr != nullptr)
		delete[] mArr;
	mArr = newArr;
}

CVector::CVector() :
	mCount(0),
	mArrMaxCount(10)
{
	mArr = new int[mArrMaxCount];
}

CVector::~CVector()
{
	if (mArr != nullptr)
		delete[] mArr;
	mCount = 0;
	mArrMaxCount = mIncreaseCapacity;
}

void CVector::DeleteAll()
{
	if (mArr != nullptr)
		delete[] mArr;
	mCount = 0;
	mArrMaxCount = mIncreaseCapacity;
	mArr = new int[mArrMaxCount];
}

void CVector::DeleteAt(int _idx)
{
	for (int i = _idx; i < mCount - 1; ++i)
		mArr[i] = mArr[i + 1];
	--mCount;
}

void CVector::PushBack(const Data & _data)
{
	if (IsFull())
		IncreaseCapacity();
	mArr[mCount] = _data;
	++mCount;
}

void CVector::PushFront(const Data & _data)
{
	if (IsFull())
		IncreaseCapacity();
	for (int i = mCount; i >= 0; --i)
		mArr[i + 1] = mArr[i];
	mArr[0] = _data;
	++mCount;
}

bool CVector::Search(const Data & _data)
{
	for (int i = 0; i < mCount; ++i) {
		if (mArr[i] == _data)
			return true;
	}
	return false;
}

bool CVector::IsEmpty()
{
	return mCount == 0;
}

const int CVector::Size()
{
	return mCount;
}

void CVector::Print()
{
	for (int i = 0; i < mCount; ++i)
		std::cout << mArr[i] << "->";
}

const Data & CVector::At(int _idx)
{
	if (_idx < 0 || _idx >= mCount)
		throw::std::out_of_range("");
	return mArr[_idx];
}

Data & CVector::operator[](int _idx)
{
	if (_idx < 0 || _idx >= mCount)
		throw::std::out_of_range("");
	return mArr[_idx];
}

CVector::iterator CVector::Erase(iterator & _iter)
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
CVector::iterator::iterator(CVector* _other, int _idx) :
	mOwner(_other),
	mIdx(_idx)
{
}

CVector::iterator::iterator(const iterator & _iter) :
	mOwner(_iter.mOwner),
	mIdx(_iter.mIdx)
{
}

CVector::iterator::~iterator()
{
	mOwner = nullptr;
	mIdx = IterIdxType::END;
}

int & CVector::iterator::operator*()
{
	if (mIdx == IterIdxType::END)
		throw::std::out_of_range("");
	return (*mOwner)[mIdx];
}

CVector::iterator & CVector::iterator::operator++()
{
	if (mIdx == IterIdxType::END)
		throw::std::out_of_range("");

	mIdx = (mIdx + 1) >= mOwner->mCount ? IterIdxType::END : (mIdx + 1);
	return *this;
}

CVector::iterator CVector::iterator::operator++(int)
{
	iterator copyIter(mOwner, mIdx);
	++(*this);
	return copyIter;
}

CVector::iterator & CVector::iterator::operator--()
{
	if (mIdx == IterIdxType::BEGIN)
		throw::std::out_of_range("");

	mIdx = mIdx == IterIdxType::END ? (mOwner->mCount - 1) : (mIdx - 1);
	return *this;
}

CVector::iterator CVector::iterator::operator--(int)
{
	iterator copyIter(mOwner, mIdx);
	--(*this);
	return copyIter;
}

bool CVector::iterator::operator!=(const iterator & _iter)
{
	return mIdx != _iter.mIdx;
}

bool CVector::iterator::operator==(const iterator & _iter)
{
	return mIdx == _iter.mIdx;
}
