#pragma once
#include <iostream>
#include "DynamicArrayClass.h"

bool DynamicArrList::IsFull()
{
	return mCount >= mArrMaxCount;
}

void DynamicArrList::IncreaseCapacity()
{
	mArrMaxCount += mIncreaseCapacity;
	Data* newArr = new int[mArrMaxCount];
	for (int i = 0; i < mCount; ++i)
		newArr[i] = mArr[i];

	if(mArr != nullptr)
		delete[] mArr;
	mArr = newArr;
}

DynamicArrList::DynamicArrList() :
	mCount(0),
	mArrMaxCount(10)
{
	mArr = new int[mArrMaxCount];
}

DynamicArrList::~DynamicArrList()
{
	if (mArr != nullptr)
		delete[] mArr;
	mCount = 0;
	mArrMaxCount = mIncreaseCapacity;
}

void DynamicArrList::DeleteAll()
{
	if (mArr != nullptr)
		delete[] mArr;
	mCount = 0;
	mArrMaxCount = mIncreaseCapacity;
	mArr = new int[mArrMaxCount];
}

void DynamicArrList::DeleteAt(int _idx)
{
	for (int i = _idx; i < mCount - 1; ++i)
		mArr[i] = mArr[i + 1];
	--mCount;
}

void DynamicArrList::PushBack(const Data & _data)
{
	if (IsFull())
		IncreaseCapacity();
	mArr[mCount] = _data;
	++mCount;
}

void DynamicArrList::PushFront(const Data & _data)
{
	if (IsFull())
		IncreaseCapacity();
	for (int i = mCount; i >= 0; --i)
		mArr[i + 1] = mArr[i];
	mArr[0] = _data;
	++mCount;
}

bool DynamicArrList::Search(const Data & _data)
{
	for (int i = 0; i < mCount; ++i) {
		if (mArr[i] == _data)
			return true;
	}
	return false;
}

bool DynamicArrList::IsEmpty()
{
	return mCount == 0;
}

const int DynamicArrList::Size()
{
	return mCount;
}

void DynamicArrList::Print()
{
	for (int i = 0; i < mCount; ++i)
		std::cout << mArr[i] << "->";
}

const Data & DynamicArrList::At(int _idx)
{
	if (_idx < 0 || _idx >= mCount)
		throw::std::out_of_range("");
	return mArr[_idx];
}

Data & DynamicArrList::operator[](int _idx)
{
	if (_idx < 0 || _idx >= mCount)
		throw::std::out_of_range("");
	return mArr[_idx];
}

void DynamicArrList::Erase(iterator & _iter)
{
	if (_iter.mIdx < IterIdxType::BEGIN)
		throw::std::out_of_range("");

	DeleteAt(_iter.mIdx);
	if (_iter.mIdx > mCount)
		_iter.mIdx = IterIdxType::END;
}

//////////// Iterator /////////////
DynamicArrList::iterator::iterator(DynamicArrList* _other, int _idx) :
	mDynamicArr(_other),
	mIdx(_idx)
{
}

DynamicArrList::iterator::iterator(const iterator & _iter) :
	mDynamicArr(_iter.mDynamicArr),
	mIdx(_iter.mIdx)
{
}

DynamicArrList::iterator::~iterator()
{
	mDynamicArr = nullptr;
	mIdx = IterIdxType::END;
}

int & DynamicArrList::iterator::operator*()
{
	if (mIdx == IterIdxType::END)
		throw::std::out_of_range("");
	return (*mDynamicArr)[mIdx];
}

DynamicArrList::iterator & DynamicArrList::iterator::operator++()
{
	if (mIdx == IterIdxType::END)
		throw::std::out_of_range("");

	mIdx = (mIdx + 1) >= mDynamicArr->mCount ? IterIdxType::END : (mIdx + 1);
	return *this;
}

DynamicArrList::iterator DynamicArrList::iterator::operator++(int)
{
	iterator copyIter(mDynamicArr, mIdx);
	++(*this);
	return copyIter;
}

DynamicArrList::iterator & DynamicArrList::iterator::operator--()
{
	if (mIdx == IterIdxType::BEGIN)
		throw::std::out_of_range("");

	mIdx = mIdx == IterIdxType::END ? (mDynamicArr->mCount - 1) : (mIdx - 1);
	return *this;
}

DynamicArrList::iterator DynamicArrList::iterator::operator--(int)
{
	iterator copyIter(mDynamicArr, mIdx);
	--(*this);
	return copyIter;
}

bool DynamicArrList::iterator::operator!=(const iterator & _iter)
{
	return mIdx != _iter.mIdx;
}

bool DynamicArrList::iterator::operator==(const iterator & _iter)
{
	return mIdx == _iter.mIdx;
}
