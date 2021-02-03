#pragma once

typedef int Data;

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
	void DeleteAt(int _idx); // private으로 빼진 않을것임
	void DeleteAll(); // private으로 빼진 않을것임
	void PushBack(const Data& _data);
	void PushFront(const Data& _data);
	bool Search(const Data& _data);
	bool IsEmpty();
	const int Size();
	void Print();
	const Data& At(int _idx);
	Data& operator[] (int _idx);


	// iterator
private:
	enum IterIdxType { END = -1, BEGIN = 0 };
public:
	class iterator {
	public:
		DynamicArrList *mDynamicArr;
		int mIdx;
	public:
		iterator(DynamicArrList* _dArr, int _idx);
		iterator(const iterator& _iter);
		virtual ~iterator();

		int& operator*();
		iterator& operator++(); // 전위
		iterator operator++(int); // 후위
		iterator& operator--();
		iterator operator--(int);
		bool operator!=(const iterator& _iter);
		bool operator==(const iterator& _iter);
	};
	
	iterator begin() { return iterator(this, IterIdxType::BEGIN); }
	iterator end() { return iterator(this, IterIdxType::END); }

public:
	void Erase(iterator& _iter);
};