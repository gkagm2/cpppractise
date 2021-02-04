#pragma once

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
	void DeleteAt(int _idx); // private���� ���� ��������
	void DeleteAll(); // private���� ���� ��������
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
		iterator& operator++(); // ����
		iterator operator++(int); // ����
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