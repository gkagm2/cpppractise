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
	delete[] mArr;
	mCount = 0;
	mArrMaxCount = mIncreaseCapacity;
}

void DynamicArrList::DeleteAll()
{
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
		throw;
	return mArr[_idx];
}

const Data & DynamicArrList::operator[](int _idx)
{
	if (_idx < 0 || _idx >= mCount)
		throw;
	return mArr[_idx];
}
