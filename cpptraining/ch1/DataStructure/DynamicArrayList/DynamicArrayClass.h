#pragma once

typedef int Data;
struct Node {
	Data data;
	Node* link;
};

class DynamicArrList {
private:
	const int mIncreaseCapacity = 10;
private:
	Data *mArr;
	int mArrMaxCount;
	int mCount;

protected:
	bool IsFull();
	void IncreaseCapacity();
public:
	DynamicArrList();
	virtual ~DynamicArrList();

	void DeleteAll();
	void DeleteAt(int _idx);
	void PushBack(const Data& _data);
	void PushFront(const Data& _data);
	bool Search(const Data& _data);
	bool IsEmpty();
	const int Size();
	void Print();
	const Data& At(int _idx);
	const Data& operator[] (int _idx);
};