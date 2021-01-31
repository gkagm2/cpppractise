#pragma once

typedef int Data;
struct Node {
	Data data;
	Node* link;
};

class LinkedList {
private:
	int mCount;

protected:
	Node* pNodeHead;

	Node* CreateNode(const Data& _data);

public:
	LinkedList();
	virtual ~LinkedList();

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